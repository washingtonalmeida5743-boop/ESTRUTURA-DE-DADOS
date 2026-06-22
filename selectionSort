#include <stdio.h>
//meu
void selectionSort1(int *v, int n){
    int menor, troca;
    for(int i = 0 ; i < n -1; i++ ){
        menor = i;
        for(int j = i+1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}
//professora
void selectionSort2(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }            
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

