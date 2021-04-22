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

int find_x(SqList *L, int k){
    int left=0, right=L->length-1, mid;
    while(left<=right){
        mid = (left+right) / 2;
        if(L->data[mid] == k){
            return mid;
        }
        else if(L->data[mid] < k){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return L->length;
}

void exchange(SqList *L, int pos){
    int temp;
    if(pos < L->length-1){
        temp = L->data[pos];
        L->data[pos] = L->data[pos+1];
        L->data[pos+1] = temp;
    }
}

void insert(SqList *L, int k){
    for(int i =L->length-1; i>=0; i--){
        if(k > L->data[i]){
            L->data[i+1] = k;
        }
        else{
            L->data[i+1] = L->data[i];
        }
    }
    L->length = L->length+1;
}

void  main(){
    int array_length;
    int X = 4;
    array_length = sizeof(L) / sizeof(int);
    SqList* List = creat_list(L, array_length);
    int pos = find_x(List, X);
    if(pos < List->length){
        exchange(List, pos);
    }
    else{
        insert(List, X);
    }
    for(int i=0; i<List->length; i++)
       printf("%d\n", List->data[i]);
}
   