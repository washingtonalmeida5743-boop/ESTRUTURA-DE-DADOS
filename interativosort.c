#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define N         40
#define ALTURA    20
#define DELAY_US  55000
//cores
#define RST        "\033[0m"
#define BOLD       "\033[1m"
#define BAR_NRM    "\033[48;5;240m"
#define BAR_CMP    "\033[48;5;33m"
#define BAR_SWP    "\033[48;5;202m"
#define BAR_PIV    "\033[48;5;220m"
#define BAR_ORD    "\033[48;5;35m"
#define BAR_CUR    "\033[48;5;135m"
#define FG_BLU     "\033[1;34m"
#define FG_ORG     "\033[1;33m"
#define FG_GRN     "\033[1;32m"
#define FG_PRP     "\033[1;35m"
#define FG_GRY     "\033[0;37m"
#define FG_WHT     "\033[1;37m"
#define FG_YLW     "\033[33m"

#define GOTO(r,c)  printf("\033[%d;%dH",(r),(c))
#define CLEAR()    printf("\033[H\033[J")

typedef enum { NORMAL, COMPARANDO, TROCANDO, PIVOT, ORDENADO, ATUAL } Cor;

int  arr[N];
Cor  cor[N];
long comparacoes = 0;
long trocas      = 0;
char msg_log[256];
//desenho
void desenhar(void) {
    int maximo = 1;
    for (int i = 0; i < N; i++)
        if (arr[i] > maximo) maximo = arr[i];

    GOTO(1,1);

    printf(FG_WHT BOLD
        "+------------------------------------------------------------------------------+\n"
        "|         VISUALIZADOR DE ORDENACAO  --  TERMINAL ASCII                       |\n"
        "+------------------------------------------------------------------------------+"
        RST "\n");

    printf("  "
        BAR_CMP "  " RST FG_BLU " comparando  " RST
        BAR_SWP "  " RST FG_ORG " trocando    " RST
        BAR_CUR "  " RST FG_PRP " atual       " RST
        BAR_PIV "  " RST FG_YLW " pivo        " RST
        BAR_ORD "  " RST FG_GRN " ordenado    " RST
        BAR_NRM "  " RST FG_GRY " normal\n"    RST);

    for (int linha = ALTURA; linha >= 1; linha--) {
        printf("  ");
        for (int i = 0; i < N; i++) {
            int h = (arr[i] * ALTURA) / maximo;
            if (linha <= h) {
                const char *c;
                switch (cor[i]) {
                    case COMPARANDO: c = BAR_CMP; break;
                    case TROCANDO:   c = BAR_SWP; break;
                    case PIVOT:      c = BAR_PIV; break;
                    case ORDENADO:   c = BAR_ORD; break;
                    case ATUAL:      c = BAR_CUR; break;
                    default:         c = BAR_NRM; break;
                }
                printf("%s  " RST, c);
            } else {
                printf("  ");
            }
            printf(" ");
        }
        printf("\n");
    }

    printf("  ");
    for (int i = 0; i < N; i++) {
        const char *c;
        switch (cor[i]) {
            case COMPARANDO: c = FG_BLU; break;
            case TROCANDO:   c = FG_ORG; break;
            case PIVOT:      c = FG_YLW; break;
            case ORDENADO:   c = FG_GRN; break;
            case ATUAL:      c = FG_PRP; break;
            default:         c = FG_GRY; break;
        }
        printf("%s%2d" RST " ", c, arr[i] % 100);
    }
    printf("\n");

    printf(FG_WHT
        "+------------------------------------------------------------------------------+\n"
        RST);


    printf("  "
        FG_WHT "Comparacoes: " RST FG_BLU "%6ld" RST "   "
        FG_WHT "Trocas: "      RST FG_ORG "%6ld" RST "   "
        FG_WHT "Elementos: "   RST "%d\n",
        comparacoes, trocas, N);

//log
    printf("  " FG_GRY ">> " RST "%-74s\n", msg_log);

    printf(FG_WHT
        "+------------------------------------------------------------------------------+"
        RST "\n");

    fflush(stdout);
    usleep(DELAY_US);
}

void resetCores(void) {
    for (int i = 0; i < N; i++) cor[i] = NORMAL;
}

void trocar(int i, int j) {
    int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
    trocas++;
}

void passo(int a, int b, Cor ca, Cor cb, const char *log) {
    resetCores();
    if (a >= 0) cor[a] = ca;
    if (b >= 0) cor[b] = cb;
    snprintf(msg_log, sizeof(msg_log), "%s", log);
    desenhar();
}

void bubbleSort(void) {
    snprintf(msg_log, sizeof(msg_log), "Bubble Sort -- iniciando...");
    desenhar();

    for (int j = N - 1; j > 0; j--) {
        int houve = 0;
        for (int i = 0; i < j; i++) {
            comparacoes++;
            char buf[200];
            snprintf(buf, sizeof(buf),
                "Passagem %d/%d | arr[%d]=%d vs arr[%d]=%d",
                N - j, N - 1, i, arr[i], i+1, arr[i+1]);
            passo(i, i+1, COMPARANDO, COMPARANDO, buf);

            if (arr[i] > arr[i+1]) {
                snprintf(buf, sizeof(buf),
                    "Troca! %d > %d -> posicoes %d <-> %d",
                    arr[i], arr[i+1], i, i+1);
                passo(i, i+1, TROCANDO, TROCANDO, buf);
                trocar(i, i+1);
                houve = 1;
            }
        }
        resetCores();
        for (int k = j; k < N; k++) cor[k] = ORDENADO;
        snprintf(msg_log, sizeof(msg_log),
            "Posicao %d no lugar. %d elementos ordenados.", j, N - j);
        desenhar();
        if (!houve) break;
    }
    resetCores();
    for (int i = 0; i < N; i++) cor[i] = ORDENADO;
    snprintf(msg_log, sizeof(msg_log),
        "CONCLUIDO! Comparacoes: %ld  Trocas: %ld", comparacoes, trocas);
    desenhar();
}

void selectionSort(void) {
    snprintf(msg_log, sizeof(msg_log), "Selection Sort -- iniciando...FG_BLU");
    desenhar();

    for (int i = 0; i < N - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < N; j++) {
            comparacoes++;
            char buf[200];
            snprintf(buf, sizeof(buf),
                "Busca minimo >= pos %d | minimo atual=%d(pos %d), testando %d(pos %d)",
                i, arr[menor], menor, arr[j], j);

            resetCores();
            for (int k = 0; k < i; k++) cor[k] = ORDENADO;
            cor[menor] = PIVOT;
            cor[j]     = COMPARANDO;
            snprintf(msg_log, sizeof(msg_log), "%s", buf);
            desenhar();

            if (arr[j] < arr[menor]) menor = j;
        }
        if (menor != i) {
            char buf[200];
            snprintf(buf, sizeof(buf),
                "Minimo=%d (pos %d) vai para posicao %d", arr[menor], menor, i);
            resetCores();
            for (int k = 0; k < i; k++) cor[k] = ORDENADO;
            cor[i] = TROCANDO; cor[menor] = TROCANDO;
            snprintf(msg_log, sizeof(msg_log), "%s", buf);
            desenhar();
            trocar(i, menor);
        }
        resetCores();
        for (int k = 0; k <= i; k++) cor[k] = ORDENADO;
        snprintf(msg_log, sizeof(msg_log),
            "Posicao %d preenchida com %d.", i, arr[i]);
        desenhar();
    }
    resetCores();
    for (int i = 0; i < N; i++) cor[i] = ORDENADO;
    snprintf(msg_log, sizeof(msg_log),
        "CONCLUIDO! Comparacoes: %ld  Trocas: %ld", comparacoes, trocas);
    desenhar();
}

void insertionSort(void) {
    snprintf(msg_log, sizeof(msg_log), "Insertion Sort -- iniciando...");
    cor[0] = ORDENADO;
    desenhar();

    for (int i = 1; i < N; i++) {
        int chave = arr[i];
        int j = i - 1;

        resetCores();
        for (int k = 0; k < i; k++) cor[k] = ORDENADO;
        cor[i] = ATUAL;
        snprintf(msg_log, sizeof(msg_log),
            "Inserindo arr[%d]=%d na posicao correta dentro de [0..%d]",
            i, chave, i - 1);
        desenhar();

        while (j >= 0 && arr[j] > chave) {
            comparacoes++;
            char buf[200];
            snprintf(buf, sizeof(buf),
                "arr[%d]=%d > chave=%d -> desloca para direita", j, arr[j], chave);

            resetCores();
            for (int k = 0; k <= i; k++) cor[k] = ORDENADO;
            cor[j]   = COMPARANDO;
            cor[j+1] = TROCANDO;
            snprintf(msg_log, sizeof(msg_log), "%s", buf);
            desenhar();

            arr[j+1] = arr[j];
            trocas++;
            j--;
        }
        arr[j+1] = chave;

        resetCores();
        for (int k = 0; k <= i; k++) cor[k] = ORDENADO;
        snprintf(msg_log, sizeof(msg_log),
            "%d inserido na posicao %d.", chave, j+1);
        desenhar();
    }
    resetCores();
    for (int i = 0; i < N; i++) cor[i] = ORDENADO;
    snprintf(msg_log, sizeof(msg_log),
        "CONCLUIDO! Comparacoes: %ld  Trocas: %ld", comparacoes, trocas);
    desenhar();
}

void quickSort(int lo, int hi) {
    if (lo >= hi) {
        if (lo >= 0 && lo < N && lo == hi) cor[lo] = ORDENADO;
        return;
    }
    int pivo = arr[lo], l = lo, r = hi;

    resetCores();
    cor[lo] = PIVOT;
    snprintf(msg_log, sizeof(msg_log),
        "Quick Sort | Pivo=%d (pos %d) | Particao [%d..%d]",
        pivo, lo, lo, hi);
    desenhar();

    while (l <= r) {
        while (arr[l] < pivo) {
            comparacoes++;
            resetCores();
            cor[lo] = PIVOT; cor[l] = COMPARANDO;
            snprintf(msg_log, sizeof(msg_log),
                "arr[%d]=%d < pivo=%d -> avanca esquerda", l, arr[l], pivo);
            desenhar();
            l++;
        }
        while (arr[r] > pivo) {
            comparacoes++;
            resetCores();
            cor[lo] = PIVOT; cor[r] = COMPARANDO;
            snprintf(msg_log, sizeof(msg_log),
                "arr[%d]=%d > pivo=%d -> recua direita", r, arr[r], pivo);
            desenhar();
            r--;
        }
        if (l <= r) {
            resetCores();
            cor[l] = TROCANDO; cor[r] = TROCANDO;
            snprintf(msg_log, sizeof(msg_log),
                "Troca arr[%d]=%d <-> arr[%d]=%d", l, arr[l], r, arr[r]);
            desenhar();
            trocar(l, r);
            l++; r--;
        }
    }
    cor[r+1] = ORDENADO;
    snprintf(msg_log, sizeof(msg_log),
        "Pivo %d fixado. Recursao: [%d..%d] e [%d..%d]",
        pivo, lo, r, l, hi);
    desenhar();

    quickSort(lo, r);
    quickSort(l, hi);
}

void mergeFn(int lo, int mid, int hi) {
    int tam = hi - lo + 1;
    int *tmp = malloc(tam * sizeof(int));
    int i = lo, j = mid+1, k = 0;

    while (i <= mid && j <= hi) {
        comparacoes++;
        resetCores();
        cor[i] = COMPARANDO; cor[j] = COMPARANDO;
        snprintf(msg_log, sizeof(msg_log),
            "Merge [%d..%d..%d] | arr[%d]=%d vs arr[%d]=%d",
            lo, mid, hi, i, arr[i], j, arr[j]);
        desenhar();

        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else                   tmp[k++] = arr[j++];
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= hi)  tmp[k++] = arr[j++];

    for (i = lo, k = 0; i <= hi; i++, k++) {
        arr[i] = tmp[k];
        trocas++;
    }
    free(tmp);

    resetCores();
    for (int x = lo; x <= hi; x++) cor[x] = ORDENADO;
    snprintf(msg_log, sizeof(msg_log),
        "Segmento [%d..%d] mesclado e ordenado.", lo, hi);
    desenhar();
}

void mergeSort(int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;

    snprintf(msg_log, sizeof(msg_log),
        "Merge Sort | Dividindo [%d..%d] -> [%d..%d] e [%d..%d]",
        lo, hi, lo, mid, mid+1, hi);
    desenhar();

    mergeSort(lo, mid);
    mergeSort(mid+1, hi);
    mergeFn(lo, mid, hi);
}

int menu(void) {
    CLEAR();
    printf(FG_WHT BOLD
        "\n"
        "  +========================================+\n"
        "  |    VISUALIZADOR DE ORDENACAO ASCII    |\n"
        "  +========================================+\n\n" RST);
    printf("  Escolha o algoritmo:\n\n");
    printf("  " FG_BLU "[1]" RST " Bubble Sort\n");
    printf("  " FG_ORG "[2]" RST " Selection Sort\n");
    printf("  " FG_PRP "[3]" RST " Insertion Sort\n");
    printf("  " FG_YLW "[4]" RST " Quick Sort\n");
    printf("  " FG_GRN "[5]" RST " Merge Sort\n");
    printf("  " FG_GRY "[0]" RST " Sair\n\n");
    printf("  Opcao: ");
    int op;
    scanf("%d", &op);
    return op;
}

int main(void) {
    printf("\033[?25l");

    while (1) {
        int op = menu();
        if (op == 0) break;
        if (op < 1 || op > 5) continue;

        srand((unsigned)time(NULL));
        for (int i = 0; i < N; i++) arr[i] = rand() % 99 + 1;
        resetCores();
        comparacoes = 0;
        trocas      = 0;

        CLEAR();

        switch (op) {
            case 1: bubbleSort();       break;
            case 2: selectionSort();    break;
            case 3: insertionSort();    break;
            case 4: quickSort(0, N-1);  break;
            case 5: mergeSort(0, N-1);  break;
        }

        printf("\n  Pressione ENTER para voltar ao menu...");
        getchar(); getchar();
    }

    printf("\033[?25h");  /* restaura cursor */
    CLEAR();
    printf("Ate logo!\n");
    return 0;
}