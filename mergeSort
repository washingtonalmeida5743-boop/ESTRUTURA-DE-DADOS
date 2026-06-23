#include <stdio.h>
//meu
void merge(int v[],int inicio,int meio,int fim){
int tamanho = fim + 1;
int vaxi[tamanho];
int i = inicio, j = meio + 1;
int k = 0;

    while(i <= meio && j <= fim ){
        if(v[i] <= v[j]){
            vaxi[k++] = v[i++];
        }else {
            vaxi[k++] = v[j++];
        }
        for(i = inicio, k = 0; i <= fim; i++, k++){
            v[i] = vaxi[k];
        }
    }
}

void mergeSort(int v[], int inicio, int fim){
	int meio = floor(fim + inicio)/2;
    //floor arredonda o numero pra baixo
	if(inicio < fim){
		mergeSort(v, inicio, meio);
		mergeSort(v, meio, fim);

		merge(v, inicio, meio, fim);

	}
}
//professora
void merge(int v[], int inicio, int meio, int fim){
    int tamanho = fim + 1;
    int vAux[tamanho];
    int i = inicio;             //início da primeira metade
    int j = meio + 1;           //início da segunda metade
    int k = 0;
    //intercala
    while(i <= meio && j <= fim){
        if(v[i] <= v[j]){
            vAux[k++] = v[i++];         //igual a vAux[k] = v[i]; k++; i++;
        }else{
            vAux[k++] = v[j++];
        }
    }
    //copia o resto do subvetor
    while(i <= meio){
        vAux[k++] = v[i++];
    }
    while(j <= fim){
        vAux[k++] = v[j++];
    }
    //copia de volta para v
    for(i = inicio, k = 0; i <= fim; i++, k++){
        v[i] = vAux[k];
    }
}

void mergeSort(int v[], int inicio, int fim){
    int meio = floor((fim + inicio)/2);
    if(inicio < fim){
        //divisão
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        //conquista
        merge(v, inicio, meio, fim);
    }
}
