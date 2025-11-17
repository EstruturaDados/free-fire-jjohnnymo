#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Estrutura que representa um item da mochila
typedef struct {
    char nome[30];    // Nome do item (ex: "Rifle", "Bandagem")
    char tipo[20];    // Tipo do item (ex: "Arma", "Munição", "Cura", "Ferramenta")
    int quantidade;   // Quantidade do item
} Item;

// Função para inserir um item na mochila
void inserirItem(Item mochila[], int *numItens) {
    if (*numItens >= MAX_ITENS) {
        printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novoItem;
    printf("\n--- Cadastro de Item ---\n");
    printf("Digite o nome do item: ");
    scanf("%29s", novoItem.nome);

    printf("Digite o tipo do item (Arma, Munição, Cura, Ferramenta): ");
    scanf("%19s", novoItem.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);

    mochila[*numItens] = novoItem;
    (*numItens)++;

    printf("\nItem adicionado com sucesso!\n");
}

// Função para remover um item da mochila pelo nome
void removerItem(Item mochila[], int *numItens) {
    if (*numItens == 0) {
        printf("\nA mochila está vazia, nada para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%29s", nomeRemover);

    int encontrado = 0;
    for (int i = 0; i < *numItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = 1;
            // Desloca os itens seguintes para preencher o espaço
            for (int j = i; j < *numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*numItens)--;
            printf("\nItem '%s' removido com sucesso!\n", nomeRemover);
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem não encontrado na mochila.\n");
    }
}

// Função para listar todos os itens da mochila
void listarItens(Item mochila[], int numItens) {
    printf("\n===== Itens na Mochila =====\n");
    if (numItens == 0) {
        printf("A mochila está vazia.\n");
    } else {
        for (int i = 0; i < numItens; i++) {
            printf("Item %d:\n", i + 1);
            printf("  Nome: %s\n", mochila[i].nome);
            printf("  Tipo: %s\n", mochila[i].tipo);
            printf("  Quantidade: %d\n", mochila[i].quantidade);
        }
    }
}

// Função para buscar um item pelo nome (busca sequencial)
void buscarItem(Item mochila[], int numItens) {
    if (numItens == 0) {
        printf("\nA mochila está vazia, nada para buscar.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%29s", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            printf("\nItem encontrado!\n");
            printf("  Nome: %s\n", mochila[i].nome);
            printf("  Tipo: %s\n", mochila[i].tipo);
            printf("  Quantidade: %d\n", mochila[i].quantidade);
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem '%s' não encontrado na mochila.\n", nomeBusca);
    }
}

int main() {
    Item mochila[MAX_ITENS]; // Vetor que representa a mochila
    int numItens = 0;        // Quantidade atual de itens na mochila
    int opcao;

    do {
        printf("\n===== Sistema de Inventário =====\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &numItens);
                listarItens(mochila, numItens);
                break;
            case 2:
                removerItem(mochila, &numItens);
                listarItens(mochila, numItens);
                break;
            case 3:
                listarItens(mochila, numItens);
                break;
            case 4:
                buscarItem(mochila, numItens);
                break;
            case 5:
                printf("\nSaindo do sistema. Boa sorte no jogo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}