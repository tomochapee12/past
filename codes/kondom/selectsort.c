#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COUNT 1000
void selectsort(int data[],int size);
void prin(int data[],int size);

int main(void) {
    int data[COUNT];
    srand((unsigned int)time(NULL));
    for(int i=0; i<COUNT; i++){
        data[i]=rand();
    }
    //ソート前データ
    prin(data,COUNT);
    //ソート
    clock_t start,end;
    start=clock();
    selectsort(data,COUNT);
    end=clock();
    //ソート後データ
    prin(data,COUNT);
    
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", elapsed_time);
    return 0;
}

void prin(int data[], int size){
    for(int i=0; i<size; i++){
        printf("%d",data[i]);
        printf(" ");
    }
    printf("\n");
}
void selectsort(int data[],int size){
    for(int i=0; i<size-1; i++){
        int min_index=i;
        for (int j=i+1; j<size; j++){
            if(data[j]<data[min_index]){
                min_index=j;
            }
        }
        if(min_index != i){
            int tmp=data[i];
            data[i]=data[min_index];
            data[min_index]=tmp;
        }
    }
}
