// Huffman Coding in C
// https://www.programiz.com/dsa/huffman-coding

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HEIGHT 50

typedef struct MinHNode {
    char item;
    unsigned freq;
    struct MinHNode *left, *right;
} MinHNode;

typedef struct {
    unsigned size;
    unsigned capacity;
    MinHNode **array;
} MinHeap;

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

MinHNode *newNode(char item, unsigned freq) {
    MinHNode *temp = (MinHNode*)malloc(sizeof(MinHNode));

    temp->left = temp->right = NULL;
    temp->item = item;
    temp->freq = freq;

    return temp;
}

MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    
    minHeap->size = 0;
    minHeap->capacity = capacity;

    minHeap->array = (MinHNode**)malloc(minHeap->capacity * sizeof(MinHNode*));
    
    return minHeap;
}

void swapMinHNode(MinHNode **a, MinHNode **b) {
    MinHNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int checkSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

MinHNode *extractMin(MinHeap *minHeap) {
    MinHNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(MinHeap *minHeap, MinHNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}


int isLeaf(MinHNode *root) {
    return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(char item[], int freq[], int size) {
    MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(item[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

MinHNode *buildHuffmanTree(char item[], int freq[], int size) {
    MinHNode *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(item, freq, size);

    while (!checkSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printHCodes(MinHNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("  %c   | ", root->item);
        printArray(arr, top);
    }
}

void HuffmanCodes(char item[], int freq[], int size) {
    MinHNode *root = buildHuffmanTree(item, freq, size);

    int arr[MAX_TREE_HEIGHT], top = 0;

    printHCodes(root, arr, top);
}


int main() {
    char arr[] = {'a', 'd', 'g', 'j', 'm', 'o', 's', 'v', 'x', 'z'};
    int freq[] = {3, 15, 20, 8, 3, 11, 7, 12, 18, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf(" Char | Huffman code ");
    printf("\n--------------------\n");

    HuffmanCodes(arr, freq, size);
}

/*
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        char ch;
        int freq;
        struct node *left;
        struct node *right;
}node;

node * heap[100];
int heapSize=0;

void Insert(node * element)
{
        heapSize++;
        heap[heapSize] = element;
        int now = heapSize;
        while(heap[now/2] -> freq > element -> freq)
        {
                heap[now] = heap[now/2];
                now /= 2;
        }
        heap[now] = element;
}
node * DeleteMin()
{
        node * minElement,*lastElement;
        int child,now;
        minElement = heap[1];
        lastElement = heap[heapSize--];
        for(now = 1; now*2 <= heapSize ;now = child)
        {
             child = now*2;
                 if(child != heapSize && heap[child+1]->freq < heap[child] -> freq )
                {
                        child++;
                }
                if(lastElement -> freq > heap[child] -> freq)
                {
                        heap[now] = heap[child];
                }
                else
                {
                        break;
                }
        }
        heap[now] = lastElement;
        return minElement;
}
void print(node *temp,char *code)
{
        if(temp->left==NULL && temp->right==NULL)
        {
                printf("char %c code %s\n",temp->ch,code);
                return;
        }
        int length = strlen(code);
        char leftcode[10],rightcode[10];
        strcpy(leftcode,code);
        strcpy(rightcode,code);
        leftcode[length] = '0';
        leftcode[length+1] = '\0';
        rightcode[length] = '1';
        rightcode[length+1] = '\0';
        print(temp->left,leftcode);
        print(temp->right,rightcode);
}
int main()
{

       heap[0] = (node *)malloc(sizeof(node));
        heap[0]->freq = 0;
        int n ;
        printf("Enter the no of characters: ");
        scanf("%d",&n);
        printf("Enter the characters and their frequencies: ");
        char ch;
        int freq,i;

        for(i=0;i<n;i++)
        {
                scanf(" %c",&ch);
                scanf("%d",&freq);
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = ch;
                temp -> freq = freq;
                temp -> left = temp -> right = NULL;
                Insert(temp);
        }
        if(n==1)
        {
                printf("char %c code 0\n",ch);
                return 0;
        }
        for(i=0;i<n-1 ;i++)
        {
                node * left = DeleteMin();
                node * right = DeleteMin();
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = 0;
                temp -> left = left;
                temp -> right = right;
                temp -> freq = left->freq + right -> freq;
                Insert(temp);
        }
        node *tree = DeleteMin();
        char code[10];
        code[0] = '\0';
        print(tree,code);



}
*/