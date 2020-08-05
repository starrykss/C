void print_queue(char msg[]) {
    int i, maxi = rear;
    if (front >= rear) maxi += MAX_QUEUE_SIZE;
    printf("%s[%2d]= ", msg, size());
    for (i = front + 1; i <= maxi; i++) {
        printf("%2d ", data[i % MAX_QUEUE_SIZE]);
    }
    printf("\n");
}