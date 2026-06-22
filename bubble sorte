#include <stdio.h>
//meu
void bubbleSort1(int lista[], int n) {
 
    for(int j = n - 1; j > 0; j--){
        for(int i = 0; i < n-1; i++){
            if(lista[i] > lista[i + 1]){
                int axi = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = axi;
            }
        }
    }    
}
//professora
void bubbleSort2(int *v, int n){
    int i, continua, aux, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v [i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while (continua != 0);    
}
