#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 100

typedef struct SqList{
    int data[Maxsize];
    int length;
} SqList;

//A[] = {1, 3, 7, 11, 21, 25};
//B[] = {2, 4, 8, 10, 16, 32, 458, 818, 919};
int L[] = {2, 4, 8, 10, 16, 32, 458, 818, 919, 1, 3, 7, 11, 21, 25};

SqList* creat_list(int array[], int arr_length){
    SqList *p;
    p = (SqList*)malloc(sizeof(SqList));
    for(int i=0; i<arr_length; i++){
        p->data[i] = array[i];
    }
    p->length = arr_length;
    return p;
}

void reverse(SqList *L, int k){
    int temp;
    int i;
    for(i=0; i<L->length-1-i; i++){
        temp = L->data[i];
        L->data[i] = L->data[L->length-1-i];
        L->data[L->length-1-i] = temp;
    }
    for(i=0; i<L->length-k-i; i++){
        temp = L->data[i];
        L->data[i] = L->data[L->length-1-i-k];
        L->data[L->length-1-i-k] = temp;
    }
    for(i=L->length-k; i<2*L->length-i-k; i++){
        temp = L->data[i];
        L->data[i] = L->data[2*L->length-1-i-k];
        L->data[2*L->length-1-i-k] = temp;
    }
}

void  main(){
    int array_length;
    int divi_pos = 6;
    array_length = sizeof(L) / sizeof(int);
    SqList* List = creat_list(L, array_length);
    reverse(List, divi_pos);
    for(int i=0; i<List->length; i++)
       printf("%d\n", List->data[i]);
}
    