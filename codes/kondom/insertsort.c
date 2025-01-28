#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COUNT 1000
void insertsort(int data[], int size);
void prin(int data[],int size);
int main(void){
    int data[COUNT];
    srand((unsigned int)time(NULL));
    for(int i=0; i<COUNT; i++){
        data[i]=rand();
    }
    //ソート前データ
    //prin(data,COUNT);
    //ソート
    clock_t start,end;
    start=clock();
    insertsort(data, COUNT);
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
void insertsort(int data[], int size){
    for (int i=1; i<size; i++){
        int key=data[i];
        int j=i-1;

        while(j>=0 && data[j]>key) {
            data[j+1]=data[j];
            j--;
        }
        data[j+1] = key;
    }
}