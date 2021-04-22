#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 100

int B[] = {2, 4, 8, 2, 16, 32, 2, 2, 2};

int find_main(int A[], int len){
    int temp=A[0], count=1;
    for(int i=1; i<len; i++){
        if(temp == A[i]){
            count++;
        }
        else{
            if(count > 0){
                count--;
            }
            else{
                temp = A[i];
                count = 1;
            }
        }
    }
    if(count > 0){
        count = 0;
        for(int j=0; j<len; j++){
            if(temp ==A[j]){
                count++;
            }
        }
    }
    if(count > len/2){
        return temp;
    }
    else{
        return -1;
    }
}


void main(){
    int B_len = sizeof(B) / sizeof(int);
    int main_elem = find_main(B, B_len);
    printf("%d", main_elem);
}