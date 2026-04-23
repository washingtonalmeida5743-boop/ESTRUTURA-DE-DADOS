🚀 Estudo de Estruturas de Dados em C

Este repositório é destinado ao registro do meu aprendizado em Estruturas de Dados, focando em como o hardware lida com a memória e como podemos manipular isso usando a linguagem C.
🧠 Conceitos Fundamentais
1. Alocação Dinâmica de Memória

Diferente da alocação estática, aqui eu decido quando e quanta memória o programa vai usar durante a execução.

    malloc(): É o comando que eu uso para pedir memória para o Sistema Operacional. Ele reserva um bloco no Heap e me devolve o endereço de memória.

    sizeof(): Eu utilizo este operador para medir o tamanho exato de um tipo ou de uma struct. Como o tamanho dos tipos muda de sistema para sistema (32-bit vs 64-bit), o sizeof garante que meu código seja portátil.

    free(): Memória alocada não é infinita. Sempre que eu termino de usar um bloco alocado com malloc, eu uso o free para evitar o temido Memory Leak (vazamento de memória).

2. Ponteiros e Structs

Ponteiros são o coração das Estruturas de Dados. Eles não guardam valores, mas sim endereços.

    Acesso a Campos:

        Quando eu tenho uma struct comum, eu uso o ponto (p.codigo).

        Quando eu tenho um ponteiro para struct, eu uso a seta (p->codigo), que é um atalho para dizer: "Vá até o endereço de p e acesse o campo codigo".

🛠️ Exemplo de Estudo: Alocação de Structs

Um erro comum que eu estudei foi o sobrescrito de ponteiro. Veja o que acontece se eu não tomar cuidado com a ordem dos mallocs:
C

// JEITO PROBLEMÁTICO:
Profissao* p;
p = malloc(sizeof(Profissao)); // Aloco a estrutura
p = malloc(tamanho_nome);     // ERRO: Aqui eu apaguei o endereço da estrutura!

O que aprendi: Para manter a integridade da memória, eu preciso alocar a estrutura principal primeiro e, em seguida, alocar os campos internos separadamente, sem perder a referência da base.
📂 Organização do Repositório
Pasta	Descrição
/ponteiros	Exercícios básicos de manipulação de endereços e aritmética.
/alocacao_dinamica	Desafios de malloc, realloc e gestão de memória.
/structs	Criação de tipos abstratos de dados (TADs).
/projetos	Projetos maiores (ex: renderizador 3D em ASCII, jogos em C).
💻 Ambiente de Desenvolvimento

    OS: Debian Linux (Trixie/Testing)

    Editor: Neovim / VS Code

    Compilador: GCC

    Hardware: ThinkPad L14 Gen 2

📚 Referências

    C: Como Programar (Deitel)

    Documentação da stdlib.h

    Material de Algoritmos e Programação de Computadores (APC) - UnB

"Programar em C é como ter uma faca afiada sem cabo: você tem controle total, mas se não souber onde pegar, vai se cortar (ou dar Segfault)."🏆 Programação Competitiva & Algoritmos
Este repositório é onde organizo meus estudos de Estruturas de Dados, Algoritmos e resoluções de problemas de Programação Competitiva. O objetivo principal é melhorar minha lógica, entender análise de complexidade (Big O) e manter um histórico da minha evolução.

📌 Sobre o Repositório
Aqui você encontrará minhas soluções para problemas de diversos Online Judges, além de implementações próprias de algoritmos clássicos. O foco é escrever códigos limpos e com a melhor eficiência de tempo e espaço possível.

📂 Como está organizado
Os códigos estão divididos de duas formas principais: por plataforma de exercícios e por tópicos de estudo da Ciência da Computação.

/Plataformas:

Codeforces/: Problemas resolvidos em rounds ou no problemset.

LeetCode/: Foco em problemas clássicos de entrevistas técnicas.

CSES/: Soluções para a clássica lista do CSES Problem Set.

/Algoritmos_e_Estruturas:

Matematica/: Teoria dos Números, Crivo, Exponenciação Rápida.

Grafos/: BFS, DFS, Dijkstra, Árvores.

Programacao_Dinamica/: Problemas de otimização, Knapsack.

Busca_Ordenacao/: Busca Binária, Two Pointers.

🛠️ Tecnologias e Compilação
A linguagem principal utilizada nestes estudos é o C++, aproveitando a velocidade da linguagem e as estruturas prontas da STL (Standard Template Library).

Para compilar e rodar qualquer arquivo localmente via terminal, utilizo o GCC. Exemplo:

Bash
# Compilando com flags de otimização e avisos
g++ -O2 -Wall arquivo.cpp -o executavel

# Executando o código
./executavel
🚀 Meu Template Base
Para ganhar tempo durante competições, utilizo um boilerplate (template) padrão no início de cada código que otimiza a leitura e escrita de dados no terminal (Fast I/O). Ele fica salvo no arquivo template.cpp na raiz deste repositório.
