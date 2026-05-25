#include <stdio.h>
#include <stdlib.h>

struct elementolista{
    int valor;
    struct elementolista* prox;
};

typedef struct elementolista item;

void inserefim(item* cabeca, int valor){
//criar ponteiro para novo item e alocar dinamicamente
//declaro um ponteiro pro novo item (* novo)
//chamo a funcao malloc que vai alocar um espaco para o novo item (malloc(sizeof(item))
//eu converto esse ponteiro para ponteiro tipo item(item*)
    item* novo = (item*)malloc(sizeof(item));

    novo->prox = NULL;        //ultimo da lista
    novo->valor = valor;        //conteudo do item

    printf("%3d no endereco 0x%000000X\n", novo->valor, novo);
//varre a lista do comeco pra chegar na ultima posicao

//declarei ponteiro atual que guarda a cabeca
//enquanto prox nao for o ultimo eu continuo
    item* atual = cabeca;
    while(atual->prox != NULL){
    atual = atual->prox;
}

//chego na ultima posicao
//e o pontero do prox pega o ponteiro do novo(NULL)
    atual->prox = novo;

}
void imprime(item* cabeca){
//proximo elemento da lista 
item* atual = cabeca->prox;

int i=0;
while(atual != NULL){
    printf("valor do item %3d endereco do proximo 0x%000000X\n", atual->valor, atual->prox);
    i++;
    atual = atual->prox;
}

printf("total de itens %d\n",i);
}

void liberar(item* cabeca){
//ponteiro para inicio da lista
    item* atual = cabeca->prox;

//ponteiro para item ser liberado
    item* liberado;

//parte do inicio da lista,eliminando todos os itens
while(atual != NULL){
//o liberando recebe o item a ser liberado
    liberado = atual;
//o atual recebe o endereco do proximo
    atual = atual->prox;
    printf("liberando o item de valor %3d na posicao 0x%000000X\n", liberado->valor, liberado);//libera atual

    free(liberado);

}

}

int main(){

item cabeca;

cabeca.prox = NULL;

printf("inserindo itens novos no final da lista\n");
//chama funcao imprimir no fim
    inserefim(&cabeca, 17);
    inserefim(&cabeca, 367);
    inserefim(&cabeca, 15);
    inserefim(&cabeca, 983);
    inserefim(&cabeca, 78);
    inserefim(&cabeca, 57);
//espera dar enter
system("PAUSE");

    imprime(&cabeca);

system("PAUSE");

    liberar(&cabeca);

system("PAUSE");

return 0; 
}
