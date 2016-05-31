#include <stdio.h>

int T[10]; //nPr을 이루는 각각의 경우를 저장
int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void process(int q){
    for(int i = q-1; i>= 0; i--){
            printf("%d ", T[i]);
    }
    printf("\n");
}

void Comb(int n, int r, int q){
    if(r == 0){
        process(q);
        return;
    }else if(n<r){
        return;
    }
    else {  //loop이 아님
        T[r-1] = data[n-1];
        Comb(n-1, r-1, q);  //n-1Cr-1
        Comb(n-1, r, q);    //n-1Cr
    }
}

int main(void){
    Comb(4, 3, 3);
    return 0;
}


