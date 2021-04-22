#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 100

typedef struct SqList{
    int data[Maxsize];
    int length;
} SqList;

int A[] = {1, 3, 7, 11, 21, 25};
int B[] = {2, 4, 8, 10, 16, 32, 458, 818, 919};

SqList* creat_list(int array[], int arr_length){
    SqList *p;
    p = (SqList*)malloc(sizeof(SqList));
    for(int i=0; i<arr_length; i++){
        p->data[i] = array[i];
    }
    p->length = arr_length;
    return p;
}

SqList* merge(SqList *A, SqList *B){
    SqList *C;
    C = (SqList *)malloc(sizeof(SqList));
    int i=0, j=0, k=0;
    while(i<A->length && j<B->length){
        if(A->data[i] < B->data[j]){
            C->data[k] = A->data[i];
            i++;
        }
        else{
            C->data[k] = B->data[j];
            j++;
        }
        k++;
    }
    if(A->length == i){
        for(; j<B->length; j++){
            C->data[k] = B->data[j];
            k++;
        } 
    }
    else{
        for(; i<A->length; i++){
            C->data[k] = A->data[i];
            k++;
        }
    }
    C->length = k+1;
    return C;

}

void  main() {
    int array_length;
    array_length = sizeof(A) / sizeof(int);
    SqList* La = creat_list(A, array_length);
    array_length = sizeof(B) / sizeof(int);
    SqList* Lb = creat_list(B, array_length);
    SqList* Lc = merge(La, Lb);
    for(int i=0; i<Lc->length-1; i++)
       printf("%d\n", Lc->data[i]);
}