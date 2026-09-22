#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para a semente do rand()

#define TAM 10

typedef struct {
    int Dia;
    int Mes;
    int Ano;
} Data;

typedef struct {
    char nome[50];
    float altura;
    Data nascimento;
} Pessoa;

void CriaData(Data *D) {
    D->Mes = 1 + (rand() % 12);
    D->Ano = 1950 + (rand() % 49);
    D->Dia = 1 + (rand() % 30);
}
void inserir_pessoa(Pessoa pessoas[], int *qtd) {
    if (*qtd >= TAM) {
        printf("\n[ERRO] Limite maximo de pessoas (%d) atingido!\n", TAM);
        return;
    }

    printf("\n--- Inserir Pessoa %d ---\n", *qtd + 1);
    
    printf("Digite o nome: ");
    scanf(" %[^\n]", pessoas[*qtd].nome);

    printf("Digite a altura (em metros, ex: 1.75): ");
    scanf("%f", &pessoas[*qtd].altura);

    CriaData(&pessoas[*qtd].nascimento);

    printf("Pessoa inserida com sucesso! Data gerada: %02d/%02d/%d\n", 
           pessoas[*qtd].nascimento.Dia, 
           pessoas[*qtd].nascimento.Mes, 
           pessoas[*qtd].nascimento.Ano);

    (*qtd)++;
}
void listar_todos(Pessoa pessoas[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhuma pessoa cadastrada ainda.\n");
        return;
    }

    printf("\n=== LISTA DE PESSOAS CADASTRADAS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("\n[Pessoa %d]\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Altura: %.2f m\n", pessoas[i].altura);
        printf("Data de Nascimento: %02d/%02d/%d\n", 
               pessoas[i].nascimento.Dia, 
               pessoas[i].nascimento.Mes, 
               pessoas[i].nascimento.Ano);
    }
}

int nasceu_antes(Data a, Data b) {
    if (a.Ano < b.Ano) return 1;
    if (a.Ano > b.Ano) return 0;
    
    if (a.Mes < b.Mes) return 1;
    if (a.Mes > b.Mes) return 0;
    
    if (a.Dia < b.Dia) return 1;
    return 0;
}

void listar_antes(Pessoa pessoas[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhuma pessoa cadastrada ainda.\n");
        return;
    }

    Data limite;
    printf("\n--- Listar Nascidos Antes de Uma Data ---\n");
    printf("Digite a data limite (Dia Mes Ano separando por espaco): ");
    scanf("%d %d %d", &limite.Dia, &limite.Mes, &limite.Ano);

    int encontrados = 0;
    printf("\nPessoas nascidas antes de %02d/%02d/%d:\n", limite.Dia, limite.Mes, limite.Ano);

    for (int i = 0; i < qtd; i++) {
        if (nasceu_antes(pessoas[i].nascimento, limite)) {
            printf("- %s (Nascido em: %02d/%02d/%d)\n", 
                   pessoas[i].nome, 
                   pessoas[i].nascimento.Dia, 
                   pessoas[i].nascimento.Mes, 
                   pessoas[i].nascimento.Ano);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhuma pessoa encontrada com data anterior à informada.\n");
    }
}

int main() {
    // Inicializa a semente aleatória com o tempo atual do sistema
    srand(time(NULL));

    Pessoa pessoas[TAM];
    int qtd = 0;
    int opcao;

    do {
        printf("\n================ MENU ================\n");
        printf("1. Inserir pessoa\n");
        printf("2. Listar todas as pessoas e alturas\n");
        printf("3. Listar pessoas nascidas antes de uma data\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_pessoa(pessoas, &qtd);
                break;
            case 2:
                listar_todos(pessoas, qtd);
                break;
            case 3:
                listar_antes(pessoas, qtd);
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}