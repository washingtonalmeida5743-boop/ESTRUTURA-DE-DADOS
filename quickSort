#include <stdio.h>

//meu 
void quickSort(int v[], int inicio, int final){
    int pivo = v[inicio];
    int l = inicio;
    int r=final;

    while(l <= r){

        while(v[l] < pivo) l++;
        while(v[r] > pivo) r--;


        if( l <= r){
            int temp = v[l];
            v[l] = v[r];
            v[r] = temp;

            l++;
            r--;
        }
    }
    if(inicio < r) quickSort(v, inicio, r);
    if(l < final) quickSort(v, l, final);
}
//professora
int quick(int *v, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = v[inicio];
    while(esq < dir){
        while(esq <= final && v[esq] <= pivo){
            esq++;
        }
        while(dir >= 0 && v[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;    
}

void quickSort2(int *v, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = quick(v, inicio, fim);
        quickSort2(v, inicio, pivo - 1);
        quickSort2(v, pivo + 1, fim);
    }
}
