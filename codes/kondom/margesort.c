#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COUNT 100
void mergesort(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);
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
    mergesort(data,0,COUNT-1);
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
void mergesort(int data[], int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        // 左半分ソート
        mergesort(data,left,mid);
        // 右半分ソート
        mergesort(data,mid+1,right);
        // 左右マージ
        merge(data,left,mid,right);
    }
}
void merge(int data[], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    // 一時配列を作成
    int leftdata[n1], rightdata[n2];
    // 左側を一時配列にコピー
    for (int i=0; i<n1; i++) {
        leftdata[i]=data[left+i];
    }
    // 右側を一時配列にコピー
    for (int j=0; j<n2; j++){
        rightdata[j]=data[mid+1+j];
    }
    int i=0, j=0, k=left;
    // 左右の一時配列をマージしてソート
    while (i<n1 && j<n2){
        if(leftdata[i]<=rightdata[j]){
            data[k++]=leftdata[i++];
        }else{
            data[k++]=rightdata[j++];
        }
    }
    // 残りの要素をコピー
    while(i<n1){
        data[k++]=leftdata[i++];
    }
    while(j<n2){
        data[k++]=rightdata[j++];
    }
}
