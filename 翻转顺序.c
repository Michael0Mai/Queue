#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 100

typedef struct SqList{
    int data[Maxsize];
    int length;
} SqList;

int L[] = {2, 4, 8, 10, 16, 32, 458, 818, 919};

SqList* creat_list(int array[], int arr_length){
    SqList *p;
    p = (SqList*)malloc(sizeof(SqList));
    for(int i=0; i<arr_length; i++){
        p->data[i] = array[i];
    }
    p->length = arr_length;
    return p;
}

void reverse(SqList *L, int pos){
    int i, temp;
    for(i=0; i<L->length-1-i; i++){
        temp = L->data[i];
        L->data[i] = L->data[L->length-1-i];
        L->data[L->length-1-i] = temp;
    }
    for(i=0; i<L->length-pos-i; i++){
        temp = L->data[i];
        L->data[i] = L->data[L->length-pos-i-1];
        L->data[L->length-pos-i-1] = temp;
    }
    for(i=L->length-pos; i<2*L->length-pos-i; i++){
        temp = L->data[i];
        L->data[i] = L->data[2*L->length-pos-1-i];
        L->data[2*L->length-pos-1-i] = temp;
    }
}

void  main(){
    int array_length;
    int pos = 6;
    array_length = sizeof(L) / sizeof(int);
    SqList* List = creat_list(L, array_length);
    reverse(List, pos);
    for(int i=0; i<List->length; i++)
        printf("%d\n", List->data[i]);
}
   