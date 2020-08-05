#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random(n) (rand()%n)

////////////////////////////////////////////////////////////////
void BucketSort(int ary[], int size) {
    int max;
    
    // 배열에서 최댓값 찾기
    max = ary[0];
    for (int i = 0; i < size; i++) {
        if (ary[i] >= max) {
            max = ary[i];
        }
    }

    int *aux = (int*)malloc(sizeof(int) * (max + 1));

    // initializing the auxiliary array elements to 0
    for (int i = 0; i <= max; i++) {
        aux[i] = 0;
    }

    // filling the auxiliary array with elements of unsorted array
    for (int i = 0; i < size; i++) {
        aux[ary[i]]++;
    }

    // emptying the auxiliary array
    for (int i = 0, j = 0; i <= max; i++) {
        for(; aux[i] > 0; (aux[i])--) {
            ary[j] = i;
            j++;
        }
    }

    free(aux);
}

////////////////////////////////////////////////////

void ScreenOut(int *pList, int count) { 
    int i; 
    for(i=0;i<count;i++) 
        printf("%d ",pList[i]); 

    puts(""); 
} 


int main() {
    int i,input; 
    int *list; 

    srand((unsigned int)time(NULL)); 

    printf("Input Data Count : "); 
    scanf("%d",&input); 

    list=(int *)malloc(sizeof(int)*input); 

    for(i=0;i<input;i++)     
        list[i]=random(100); 

    printf("Insert Data : "); 
    ScreenOut(list,input); 

    // SORT ////////////////////
    BucketSort(list,input); 
    ////////////////////////////
     
    printf("Sorting Data : "); 
    ScreenOut(list,input); 

    free(list); 

    return 0; 
}