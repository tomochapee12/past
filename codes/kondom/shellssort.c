#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COUNT 1000
void shellsort(int data[], int size);
void prin(int data[],int size);
int main(void) {
    int data[COUNT];
    srand((unsigned int)time(NULL));
    for (int i=0; i<COUNT; i++){
        data[i]=rand();
    }
    //ソート前データ
    //prin(data,COUNT);
    //ソート
    clock_t start,end;
    start=clock();
    shellsort(data, COUNT);
    end=clock();
    //ソート後データ
    //prin(data,COUNT);
    
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", elapsed_time);
    return 0;
}
void prin(int data[], int size){
    for(int i=0; i<COUNT; i++){
        printf("%d",data[i]);
        printf(" ");
    }
    printf("\n");
}
void shellsort(int data[], int size){
    for (int gap=size/2; gap>0; gap/=2){
        for (int i=gap; i<size;i++) {
            int tmp=data[i];
            int j;
            for (j=i; j>=gap && data[j-gap]>tmp; j-=gap){
                data[j]=data[j-gap];
            }
            data[j]=tmp;
        }
    }
}