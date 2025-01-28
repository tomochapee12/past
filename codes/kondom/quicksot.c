#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COUNT 1000
void quicksort(int data[],int left,int right);
void prin(int data[], int size);

int main(void){
    int data[COUNT];
    srand((unsigned int)time(NULL));
    for (int i=0; i<COUNT; i++){
        data[i]=rand();
    }
    //ソート前データ
    prin(data,COUNT);
    //クイックソート
    clock_t start,end;
    start=clock();
    quicksort(data,0,COUNT-1);
    end=clock();
    //ソート後データ
    prin(data,COUNT);
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
void quicksort(int data[],int left,int right){
    if (left>=right){return;}
    int pivot=data[(left+right)/2];
    int i=left, j=right;
    while(i<=j){
        while(data[i]<pivot){i++;}
        while(data[j]>pivot){j--;}
        if(i<=j){
            int tmp=data[i];
            data[i]=data[j];
            data[j]=tmp;
            i++;
            j--;
        }
    }
    quicksort(data,left,j);
    quicksort(data,i,right);
}
