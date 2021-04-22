#include <stdio.h>
#include <stdlib.h>

int [] = {1, 3, 7, 11, 21, 25};
int D[] = {2, 4, 8, 10, 16, 32, 458, 818, 919};

int find_mid(int A[], int A_len, int B, int B_len){
    int A_left=0, A_right=A_len-1, A_mid, B_left=0, B_right=B_len-1, B_mid;
    while(A_left!=A_right || B_left!=B_right){
        A_mid = (A_left+A_right) / 2;
        B_mid = (B_left+B_right) / 2;
        if(A_mid == B_mid){
            return A[A_mid];
        }
        if(A_mid < B_mid){
            if((A_left+A_right)%2 == 0){
                A_left = A_mid;
                B_right = B_mid;
            }
            else{
                A_left = A_mid + 1;
                B_right = B_mid;
            }
        }
        else{
            if((B_left+B_right)%2 ==0){
                A_right = A_mid;
                B_left = B_mid;
            }
            else{
                A_right = A_mid;
                B_left = B_mid + 1;
            }
        }
    }
    if(A[A_left]<B[B_left]){
        return A[A_left];}
    else{
        return B[B_left];}
    
}


void main(){
    int C_Len = sizeof(C) / sizeof(int);
    int D_Len = sizeof(D) / sizeof(int);
    int mid  = find_mid(C, C_Len, D, D_Len);
    printf("%d", mid);
}