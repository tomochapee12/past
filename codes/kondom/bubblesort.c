#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COUNT 1000
void bubblesort(int data[], int size);
void prin(int data[],int size);
int main(void) {
    int data[COUNT];
    srand((unsigned int)time(NULL));
    for(int i=0; i<COUNT; i++){
        data[i]=rand();
    }
	//ソート前データ
    //prin(data,COUNT);
	//ソート処理
    clock_t start,end;
    start=clock();
    bubblesort(data, COUNT);
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
void bubblesort(int data[], int size){
    for(int i = 0; i < size - 1; i++){
        int flag = 0;
        for(int j=0; j<size-i-1; j++){
            if (data[j]>data[j+1]){
                int tmp=data[j];
                data[j]=data[j+1];
                data[j+1]=tmp;
                flag=1;
            }
        }
        if(!flag){break;}
    }
}