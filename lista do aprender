#include <stdio.h>  
#include <stdlib.h> 

/* * ESTRUTURA DO NÓ 
 * Aqui nós criamos o "molde" de como cada pedaço da nossa lista será.
 */
typedef struct No {
    int id;          // A "carga" do vagão: guarda o número que você quer armazenar.
    struct No* prox; // O "engate" do vagão: guarda o endereço do PRÓXIMO vagão da fila.
} No;

/* * FUNÇÃO PARA CRIAR A CABEÇA 
 * Esta função é chamada apenas UMA vez no início do programa.
 */
No* criarCabeca() {
    // 1. Pedimos um espaço na memória do tamanho exato de um "No" (um vagão).
    No* cabeca = (No*) malloc(sizeof(No));
    
    // 2. Colocamos o valor -1 na carga. Como é o nó fantasma, nós vamos sempre ignorar esse -1.
    cabeca->id = -1; 
    
    // 3. Como a lista nasce vazia, não tem ninguém atrás dessa cabeça, então o próximo é o NADA (NULL).
    cabeca->prox = NULL;
    
    // 4. Devolvemos o "endereço" dessa caixa inteira para quem chamou a função.
    return cabeca; 
}

/*
 * FUNÇÃO DE REMOVER UM ELEMENTO
 * O desafio aqui é: para remover um vagão, precisamos conectar o vagão de trás com o vagão da frente.
 */
void remover(No* cabeca, int id){
    // 'atual' começa apontando para o PRIMEIRO VAGÃO COM CARGA REAL (pulando o -1)
    No* atual = cabeca->prox; 
    // 'anterior' começa apontando para a CABEÇA (o nó fantasma)
    No* anterior = cabeca;

    // Enquanto o nosso dedo 'atual' estiver apontando para um vagão que existe (não for NULL)...
    while(atual != NULL){
        
        // Verificamos: "A carga desse vagão atual é a que eu quero apagar?"
        if(atual->id == id){
            
            // A MÁGICA DA REMOÇÃO ACONTECE AQUI:
            // O vagão de trás ('anterior') solta o vagão 'atual' e engata direto no vagão da frente ('atual->prox').
            // O vagão 'atual' acabou de ser isolado da lista!
            anterior->prox = atual->prox;
            
            // Agora que o vagão está solto, destruímos ele para devolver a memória ao computador.
            free(atual);
            
            // Achamos e apagamos o que queríamos, então saímos da função. Missão cumprida!
            return; 
        }
        
        // Se a carga não era a certa, precisamos andar para frente.
        // O dedo 'anterior' pula para onde o 'atual' está...
        anterior = atual; 
        // ...e o dedo 'atual' dá um passo para o próximo vagão.
        atual = atual->prox;
    }
}

/*
 * FUNÇÃO DE INSERIR NO FINAL
 * Aqui nós criamos um vagão novo e passeamos pela lista até achar o último cara para pendurar o novo vagão nele.
 */
void inserir(No* cabeca, int l){
    // 1. Fabricando o vagão novo
    No* novo = (No*)malloc(sizeof(No)); // Pede espaço na memória
    novo->prox = NULL;                  // Ele será o último da fila, então não aponta para ninguém
    novo->id = l;                       // Guarda o número que o usuário digitou

    // 2. Criamos o nosso dedo apontador chamado 'atual'. 
    // Ele recebe o endereço da CAIXA INTEIRA do nó cabeça (que contém o id -1 e o seu respectivo prox).
    No* atual = cabeca;

    // 3. O motorzinho de busca: "Enquanto o vagão onde estou apontar para alguém que existe..."
    while(atual->prox != NULL){
        // ...eu tiro o dedo deste vagão e pulo para o vagão da frente.
        atual = atual->prox;
    }
    // Quando o while terminar, significa que o 'atual->prox' é NULL. 
    // Achamos o último vagão da fila!

    // 4. Pegamos o "engate" do último vagão da fila e conectamos ao nosso 'novo' vagão.
    atual->prox = novo;
}

/*
 * FUNÇÃO DE COMPARAR TEXTOS (Strings)
 * Uma string em C é uma fila de caracteres que sempre termina com o caractere especial '\0' (vazio).
 */
int comparar(char a[],char in[]){
    int i = 0; // Começamos a olhar para a primeira letra (posição 0)

    // Enquanto as letras forem iguais nas duas palavras E não tivermos chegado no final da palavra digitada...
    while(a[i] == in[i] && a[i] != '\0'){
        i++; // ...andamos para a próxima letra.
    }
    
    // Se o laço parou e as letras nas posições onde parou são idênticas (geralmente o '\0' de ambas),
    // significa que as palavras são idênticas.
    if(a[i] == in[i]){
        return 1; // 1 significa "Verdadeiro, são iguais!"
    }else {
        return 0; // 0 significa "Falso, são diferentes!"
    }
}

/*
 * FUNÇÃO DE IMPRIMIR A LISTA
 */
void imprimir(No* cabeca){
    // Colocamos o dedo 'atual' no primeiro vagão com dados reais (pulamos a cabeça fantasma)
    No* atual = cabeca->prox;

    // Enquanto não chegarmos ao final do trem...
    while(atual != NULL){
        // Imprime a carga do vagão atual na tela
        printf("%d ", atual->id);
        
        // Pula para o próximo vagão
        atual = atual->prox;
    }
    // Pula uma linha no terminal para ficar bonito depois de imprimir todos
    printf("\n");
}

/*
 * FUNÇÃO PARA LIBERAR A MEMÓRIA
 * É regra de ouro: tudo que você cria com 'malloc' precisa ser destruído com 'free'.
 */
void liberar(No* cabeca) {
    // Começamos desde a cabeça fantasma, pois ELA TAMBÉM foi criada com malloc e precisa ser destruída!
    No* atual = cabeca;
    
    // Criamos uma variável de apoio para não perdermos o endereço do resto do trem.
    No* temporario;
    
    // Enquanto tiver vagão na pista...
    while(atual != NULL) {
        // 1. Salvo o endereço do vagão da frente (se eu não fizer isso, na linha de baixo eu perco o trem inteiro!)
        temporario = atual->prox;
        
        // 2. Destruo o vagão onde estou pisando agora
        free(atual);
        
        // 3. Dou um passo para frente, usando aquele endereço que deixei salvo a salvo
        atual = temporario;
    }
}

/*
 * FUNÇÃO PRINCIPAL (Onde o programa começa a rodar)
 */
int main(){

    // Nasce a nossa lista. A variável 'cabeca' agora guarda o endereço da locomotiva fantasma.
    No* cabeca = criarCabeca();
    
    // Definimos as palavras-chave que o programa vai entender.
    char in[] = "INSERIR";
    char r[] = "REMOVER";
    char im[]= "IMPRIMIR";

    // Criamos um "loop infinito". O 1 significa 'verdadeiro'. O programa vai rodar até mandarmos ele parar (return 0).
    while(1){
        char a[50]; // Espaço para guardar a palavra que o usuário vai digitar
        int n;      // Espaço para guardar o número que o usuário vai digitar
        
        // Fica esperando o usuário digitar uma palavra e aperta Enter. Guarda a palavra na variável 'a'.
        scanf("%s", a);

        // Se a palavra digitada ('a') for igual a "INSERIR"...
        if(comparar(a, in)){
            // ...pede para o usuário digitar um número.
            scanf("%d", &n);
            // Chama a função de inserir passando o endereço do nosso trem e o número novo.
            inserir(cabeca, n);
        }
        // Mas se a palavra for igual a "REMOVER"...
        else if(comparar(a, r)){
            // ...pede o número que ele quer remover.
            scanf("%d", &n);
            // Chama a função de apagar.
            remover(cabeca, n);
        }
        // Mas se a palavra for igual a "IMPRIMIR"...
        else if(comparar(a, im)){
            // Imprime tudo o que tem no trem...
            imprimir(cabeca);
            // ...limpa a sujeira que fizemos na memória para não travar o PC...
            liberar(cabeca); 
            // ...e encerra o programa de vez (mata o while).
            return 0;
        }
    }
    
    // Esse return 0 no final é o padrão da linguagem C para dizer ao sistema operacional: "Tudo terminou bem".
    return 0;
}
