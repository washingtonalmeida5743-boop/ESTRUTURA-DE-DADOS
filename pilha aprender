#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da pilha (guarda a url e o gancho pro próximo)
typedef struct no {
    char url[100];
    struct no* prox;
} no;

// Cria a cabeça sentinela (porta de entrada fixa)
no* criarno() {
    int i = 0;
    char a[] = "FANTASMA";
    no* cabeca = (no*) malloc(sizeof(no)); // Aloca memória
    
    // Copia FANTASMA letra por letra
    while (a[i] != '\0') {
        cabeca->url[i] = a[i];
        i++;
    }
    cabeca->url[i] = '\0'; // Fecha a palavra
    cabeca->prox = NULL;   // Começa vazia
    
    return cabeca;
}

// Compara duas strings (1 se igual, 0 se diferente)
int comparar(char a[], char in[]) {
    int i = 0;

    // Avança enquanto as letras forem iguais
    while(a[i] == in[i] && a[i] != '\0') {
        i++;
    }
    
    // Se parou no mesmo lugar, é match
    if(a[i] == in[i]) {
        return 1;
    } else {
        return 0; 
    }
}

// Empilha um site novo no topo (logo após a cabeça)
void acessar(no* cabeca, char ur[]) {
    no* novo = (no*) malloc(sizeof(no));
    int i = 0;
    
    // Copia a URL digitada pro nó
    while(ur[i] != '\0') {
        novo->url[i] = ur[i];
        i++;
    }
    novo->url[i] = '\0';

    // Amarra o novo nó na pilha
    novo->prox = cabeca->prox;
    cabeca->prox = novo;
}

// Mostra o topo sem remover
void atual(no* cabeca) {
    if(cabeca->prox != NULL) {
        printf("%s\n", cabeca->prox->url);
    } else {
        printf("Nenhuma pagina\n");
    }
}

// Remove o nó do topo (desempilha)
void voltar(no* cabeca) {
    if(cabeca->prox == NULL) {
        printf("Historico vazio\n"); // Já estava vazio
        return; 
    }

    no* remover = cabeca->prox; // Pega o topo
    cabeca->prox = remover->prox; // A cabeça pula o topo
    free(remover); // Apaga o topo da memória

    // Checa como a pilha ficou após remover
    if(cabeca->prox == NULL) {
        printf("Historico vazio\n");
    } else {
        printf("Voltando para: %s\n", cabeca->prox->url);
    }
}

int main() {
    no* cabeca = criarno();
    char in[] = "ACESSAR";
    char r[] = "ATUAL";
    char im[]= "VOLTAR";

    while(1) {
        char a[100];

        // Lê o comando; se acabar a entrada (EOF), encerra
        if (scanf("%s", a) == EOF) {
            break; 
        }
       
        if(comparar(a, in)) { // "ACESSAR"
            char site[100];
            scanf("%s", site); // Lê a url associada
            acessar(cabeca, site);
        }
        else if(comparar(a, r)) { // "ATUAL"
            atual(cabeca);
        }
        else if(comparar(a, im)) { // "VOLTAR"
            voltar(cabeca);
        }
    }

    return 0;
}
