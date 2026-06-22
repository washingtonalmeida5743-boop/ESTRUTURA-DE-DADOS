#include <stdio.h> 
//meu
void insertionSort(int *v, int n){
    int i, j, axi;
    for(i = 1; i < n; i++){
        axi = v[i];
        j = i - 1;
    
        while ((j >= 0) && (axi < v[j])){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = axi;
    }
}
//professora
void insertionSort(int *v, int n){
    int i, j, atual;
    for(i = 1; i < n; i++){
        atual = v[i];
        for(j = i; (j > 0) && (atual < v[j-1]); j--){
            v[j] = v[j - 1];
        }
        v[j] = atual;
    }
}
