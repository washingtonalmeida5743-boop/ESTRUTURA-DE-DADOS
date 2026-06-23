#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LARGURA_TELA 80

// =========================================================================
// FUNÇÕES DE INTERFACE E TELA
// =========================================================================
void limparTela() {
    // Comando para limpar o terminal (funciona na maioria dos SOs)
    printf("\033[H\033[J");
}

int contartama(char *str) {
    int c = 0;
    while(str[c] != '\0') c++;
    return c;
}

void imprimiresp(int n) {
    for(int i = 0; i < n; i++) printf(" ");
}

void centralizado(char *str) {
    int len = contartama(str);
    int esp = (LARGURA_TELA - len) / 2;
    imprimiresp(esp);
    printf("%s", str);
}

// Transformei o seu "sairdojogo" em um menu reutilizável!
int menuInterativo(char *titulo, char *opcoes[], int tot) {
    int sel = 1;
    char comando;
    char tamanhoooo[] = "-------------------------------------";
    int tu = contartama(tamanhoooo); 
    int margem_menuuu = (LARGURA_TELA - tu) / 2;

    while(1) { 
        limparTela();
        printf("\033[1;32m"); // Cor verde
        printf("\n");
        imprimiresp(margem_menuuu); printf("%s\n", tamanhoooo);
        
        // Imprime o título centralizado na caixa
        imprimiresp(margem_menuuu); 
        int espacos_titulo = (37 - contartama(titulo)) / 2;
        for(int i=0; i<espacos_titulo; i++) printf(" ");
        printf("%s\n", titulo);

        imprimiresp(margem_menuuu); printf("%s\n", tamanhoooo);
        imprimiresp(margem_menuuu); printf("                                     \n");

        for(int i = 0; i < tot; i++) {
            imprimiresp(margem_menuuu);
            if(sel == i + 1) {
                printf("              -> %-10s <-       \n", opcoes[i]);
            } else {
                printf("                 %-10s          \n", opcoes[i]);
            }
        }

        imprimiresp(margem_menuuu); printf("                                     \n");
        imprimiresp(margem_menuuu); printf("%s\n\n", tamanhoooo);
        centralizado("COMANDOS: 'w' (sobe), 's' (desce), 'f' (confirma)\n");
        centralizado("Sua escolha: ");
        
        scanf(" %c", &comando); 
        
        if (comando == 'w' || comando == 'W') {
            sel--;
            if (sel < 1) sel = tot;
        }
        else if (comando == 's' || comando == 'S') {
            sel++;
            if (sel > tot) sel = 1;
        }
        else if (comando == 'f' || comando == 'F') {
            printf("\033[0m"); // Reseta a cor
            return sel; // Retorna a opção escolhida
        }
    }
}

void imprimeVetor(int v[], int n) {
    printf("\nVetor: [ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n\n");
}


// =========================================================================
// 1. MERGE SORT
// =========================================================================
// MEU
void merge(int v[], int inicio, int meio, int fim){
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
    }
    // Correção: Copiando o resto e movido para fora do while
    while(i <= meio) vaxi[k++] = v[i++];
    while(j <= fim) vaxi[k++] = v[j++];
    for(i = inicio, k = 0; i <= fim; i++, k++){
        v[i] = vaxi[k];
    }
}
void mergeSort(int v[], int inicio, int fim){
    int meio = floor(fim + inicio)/2;
    if(inicio < fim){
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim); // Correção: meio + 1
        merge(v, inicio, meio, fim);
    }
}

// PROFESSORA
void merge1(int v[], int inicio, int meio, int fim){
    int tamanho = fim + 1;
    int vAux[tamanho];
    int i = inicio, j = meio + 1, k = 0;
    while(i <= meio && j <= fim){
        if(v[i] <= v[j]) vAux[k++] = v[i++];
        else vAux[k++] = v[j++];
    }
    while(i <= meio) vAux[k++] = v[i++];
    while(j <= fim) vAux[k++] = v[j++];
    for(i = inicio, k = 0; i <= fim; i++, k++){
        v[i] = vAux[k];
    }
}
void mergeSort1(int v[], int inicio, int fim){
    int meio = floor((fim + inicio)/2);
    if(inicio < fim){
        mergeSort1(v, inicio, meio);
        mergeSort1(v, meio + 1, fim);
        merge1(v, inicio, meio, fim);
    }
}

// =========================================================================
// 2. BUBBLE SORT
// =========================================================================
// MEU
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
// PROFESSORA
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

// =========================================================================
// 3. INSERTION SORT
// =========================================================================
// MEU
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
// PROFESSORA
void insertionSort1(int *v, int n){
    int i, j, atual;
    for(i = 1; i < n; i++){
        atual = v[i];
        for(j = i; (j > 0) && (atual < v[j-1]); j--){
            v[j] = v[j - 1];
        }
        v[j] = atual;
    }
}

// =========================================================================
// 4. QUICK SORT
// =========================================================================
// MEU
void quickSort(int v[], int inicio, int final){
    int pivo = v[inicio], l = inicio, r = final;
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

// PROFESSORA
int quick(int *v, int inicio, int final){
    int esq = inicio, dir = final, pivo = v[inicio], aux;
    while(esq < dir){
        while(esq <= final && v[esq] <= pivo) esq++;
        while(dir >= 0 && v[dir] > pivo) dir--;
        if(esq < dir){
            aux = v[esq]; v[esq] = v[dir]; v[dir] = aux;
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

// =========================================================================
// 5. SELECTION SORT
// =========================================================================
// MEU
void selectionSort1(int *v, int n){
    int menor, troca;
    for(int i = 0 ; i < n -1; i++ ){
        menor = i;
        for(int j = i+1; j < n; j++){
            if(v[j] < v[menor]) menor = j;
        }
        if(i != menor){
            troca = v[i]; v[i] = v[menor]; v[menor] = troca;
        }
    }
}

// PROFESSORA
void selectionSort2(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]) menor = j;
        }
        if(i != menor){
            troca = v[i]; v[i] = v[menor]; v[menor] = troca;
        }
    }
}

// =========================================================================
// MAIN - ONDE A MÁGICA ACONTECE
// =========================================================================
int main() {
    char *opcoesAlgoritmos[] = {"Merge", "Bubble", "Insertion", "Quick", "Selection", "Sair"};
    char *opcoesAutor[] = {"Meu", "Professora"};
    
    while(1) {
        // 1. Menu para escolher o Algoritmo
        int escolhaAlg = menuInterativo("ESCOLHA O ALGORITMO", opcoesAlgoritmos, 6);
        
        if (escolhaAlg == 6) { // Escolheu Sair
            limparTela();
            printf("Saindo do programa... Ate logo!\n");
            break;
        }

        // 2. Menu para escolher a Versão do código
        int escolhaAutor = menuInterativo("QUAL VERSAO USAR?", opcoesAutor, 2);

        // Gera um vetor de teste desordenado para toda execução
        int vetor[] = {45, 12, 78, 4, 99, 23, 8, 15, 67, 2};
        int n = sizeof(vetor) / sizeof(vetor[0]);

        limparTela();
        printf("\n=========================================\n");
        printf("Executando: %s Sort -> Versao: %s\n", opcoesAlgoritmos[escolhaAlg-1], opcoesAutor[escolhaAutor-1]);
        printf("=========================================\n");
        
        printf("Vetor ANTES da ordenacao:");
        imprimeVetor(vetor, n);

        // 3. Executa o algoritmo escolhido baseado nas escolhas
        switch(escolhaAlg) {
            case 1: // Merge
                if(escolhaAutor == 1) mergeSort(vetor, 0, n - 1);
                else mergeSort1(vetor, 0, n - 1);
                break;
            case 2: // Bubble
                if(escolhaAutor == 1) bubbleSort1(vetor, n);
                else bubbleSort2(vetor, n);
                break;
            case 3: // Insertion
                if(escolhaAutor == 1) insertionSort(vetor, n);
                else insertionSort1(vetor, n);
                break;
            case 4: // Quick
                if(escolhaAutor == 1) quickSort(vetor, 0, n - 1);
                else quickSort2(vetor, 0, n - 1);
                break;
            case 5: // Selection
                if(escolhaAutor == 1) selectionSort1(vetor, n);
                else selectionSort2(vetor, n);
                break;
        }

        printf("Vetor DEPOIS da ordenacao:");
        imprimeVetor(vetor, n);

        // Pausa antes de voltar ao menu inicial
        printf("Pressione 'f' e dê ENTER para voltar ao menu...");
        char lixo;
        scanf(" %c", &lixo);
    }

    return 0;
}
