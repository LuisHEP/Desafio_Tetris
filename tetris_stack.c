#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

typedef struct {
    char nome;
    int id;
} Peca;

typedef struct {
    Peca pecas[TAMANHO_FILA];
    int frente;
    int tras;
    int tamanho;
} FilaPecas;

int proximoId = 0;

Peca gerarPeca() {
    Peca novaPeca;
    char tipos[] = {'I', 'O', 'T', 'L'};
    novaPeca.nome = tipos[rand() % 4];
    novaPeca.id = proximoId++;
    return novaPeca;
}

void inicializarFila(FilaPecas* fila) {
    fila->frente = 0;
    fila->tras = 0;
    fila->tamanho = 0;
}

int filaVazia(FilaPecas* fila) {
    return fila->tamanho == 0;
}

int filaCheia(FilaPecas* fila) {
    return fila->tamanho == TAMANHO_FILA;
}

int enqueue(FilaPecas* fila, Peca peca) {
    if (filaCheia(fila)) {
        return 0;
    }
    
    fila->pecas[fila->tras] = peca;
    fila->tras = (fila->tras + 1) % TAMANHO_FILA;
    fila->tamanho++;
    return 1;
}

int dequeue(FilaPecas* fila, Peca* peca) {
    if (filaVazia(fila)) {
        return 0;
    }
    
    *peca = fila->pecas[fila->frente];
    fila->frente = (fila->frente + 1) % TAMANHO_FILA;
    fila->tamanho--;
    return 1;
}

void exibirFila(FilaPecas* fila) {
    printf("\nFila de pecas\n");
    
    if (filaVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    
    int i = fila->frente;
    for (int count = 0; count < fila->tamanho; count++) {
        printf("[%c %d] ", fila->pecas[i].nome, fila->pecas[i].id);
        i = (i + 1) % TAMANHO_FILA;
    }
    printf("\n");
}

void exibirMenu() {
    printf("\nOpcoes de acao:\n");
    printf("1 - Jogar peca (dequeue)\n");
    printf("2 - Inserir nova peca (enqueue)\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    srand(time(NULL));
    
    FilaPecas fila;
    inicializarFila(&fila);
    
    for (int i = 0; i < TAMANHO_FILA; i++) {
        Peca peca = gerarPeca();
        enqueue(&fila, peca);
    }
    
    int opcao;
    Peca pecaRemovida;
    
    do {
        exibirFila(&fila);
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (dequeue(&fila, &pecaRemovida)) {
                    printf("Peca jogada: [%c %d]\n", pecaRemovida.nome, pecaRemovida.id);
                } else {
                    printf("Fila vazia! Nao e possivel jogar uma peca.\n");
                }
                break;
                
            case 2:
                if (!filaCheia(&fila)) {
                    Peca novaPeca = gerarPeca();
                    enqueue(&fila, novaPeca);
                    printf("Nova peca inserida: [%c %d]\n", novaPeca.nome, novaPeca.id);
                } else {
                    printf("Fila cheia! Nao e possivel inserir nova peca.\n");
                }
                break;
                
            case 0:
                printf("Saindo do jogo...\n");
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        
    } while (opcao != 0);
    
    return 0;
}