#include <stdio.h>
#include "functions.h"

float calcular_media(Aluno aluno) {
    return (aluno.n1 + aluno.n2) / 2.0;
}

int buscar_aluno(Aluno alunos[TAM], int qtd, int matricula) {
    for (int j = 0; j < qtd; j++) {
        if (alunos[j].id == matricula) {
            return j;
        }
    }
    return -1;
}

int cadastrar_aluno(Aluno alunos[TAM], int qtd) {
    if (qtd >= TAM) {
        printf("Limite de %d alunos atingido. Nao e possivel cadastrar.\n", TAM);
        return qtd;
    }

    int matricula;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    while (matricula <= 0 || buscar_aluno(alunos, qtd, matricula) != -1) {
        if (matricula <= 0)
            printf("Matricula invalida. Digite novamente: ");
        else
            printf("Matricula ja cadastrada. Digite novamente: ");
        scanf("%d", &matricula);
    }
    alunos[qtd].id = matricula;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", alunos[qtd].nome);

    printf("Digite o curso do aluno: ");
    scanf(" %[^\n]", alunos[qtd].curso);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &alunos[qtd].n1);
    while (alunos[qtd].n1 < 0 || alunos[qtd].n1 > 10) {
        printf("Nota invalida. Digite novamente: ");
        scanf("%f", &alunos[qtd].n1);
    }

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &alunos[qtd].n2);
    while (alunos[qtd].n2 < 0 || alunos[qtd].n2 > 10) {
        printf("Nota invalida. Digite novamente: ");
        scanf("%f", &alunos[qtd].n2);
    }

    printf("Aluno cadastrado com sucesso.\n");
    return qtd + 1;
}

void listar_alunos(Aluno alunos[TAM], int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %6s  %s\n", "Matricula", "Nome", "Curso", "Media", "Situacao");
    printf("--------------------------------------------------------------------------\n");
    for (int j = 0; j < qtd; j++) {
        float media = calcular_media(alunos[j]);
        printf("%-10d %-25s %-20s %6.2f  %s\n",
               alunos[j].id, alunos[j].nome, alunos[j].curso, media,
               (media >= 6.0) ? "APROVADO" : "REPROVADO");
    }
}

void pesquisar_aluno(Aluno alunos[TAM], int qtd) {
    int matricula;
    printf("Digite a matricula do aluno que deseja pesquisar: ");
    scanf("%d", &matricula);

    int pos = buscar_aluno(alunos, qtd, matricula);
    if (pos == -1) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    float media = calcular_media(alunos[pos]);
    printf("\nAluno encontrado:\n");
    printf("Matricula: %d\n", alunos[pos].id);
    printf("Nome: %s\n", alunos[pos].nome);
    printf("Curso: %s\n", alunos[pos].curso);
    printf("Nota 1: %.2f\n", alunos[pos].n1);
    printf("Nota 2: %.2f\n", alunos[pos].n2);
    printf("Media: %.2f\n", media);
    printf("Situacao: %s\n", (media >= 6.0) ? "APROVADO" : "REPROVADO");
}

void alterar_aluno(Aluno alunos[TAM], int qtd) {
    int matricula, opcao;
    printf("Digite a matricula do aluno que deseja alterar: ");
    scanf("%d", &matricula);

    int pos = buscar_aluno(alunos, qtd, matricula);
    if (pos == -1) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    do {
        printf("\nAlterando: %s (matricula %d)\n", alunos[pos].nome, alunos[pos].id);
        printf("1. Nome\n");
        printf("2. Curso\n");
        printf("3. Nota 1\n");
        printf("4. Nota 2\n");
        printf("0. Concluir\n");
        printf("Escolha o campo: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Novo nome: ");
                scanf(" %[^\n]", alunos[pos].nome);
                break;
            case 2:
                printf("Novo curso: ");
                scanf(" %[^\n]", alunos[pos].curso);
                break;
            case 3:
                printf("Nova nota 1: ");
                scanf("%f", &alunos[pos].n1);
                while (alunos[pos].n1 < 0 || alunos[pos].n1 > 10) {
                    printf("Nota invalida. Digite novamente: ");
                    scanf("%f", &alunos[pos].n1);
                }
                break;
            case 4:
                printf("Nova nota 2: ");
                scanf("%f", &alunos[pos].n2);
                while (alunos[pos].n2 < 0 || alunos[pos].n2 > 10) {
                    printf("Nota invalida. Digite novamente: ");
                    scanf("%f", &alunos[pos].n2);
                }
                break;
            case 0:
                printf("Alteracoes concluidas.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

int excluir_aluno(Aluno alunos[TAM], int qtd) {
    int matricula;
    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    int pos = buscar_aluno(alunos, qtd, matricula);
    if (pos == -1) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return qtd;
    }

    for (int j = pos; j < qtd - 1; j++) {
        alunos[j] = alunos[j + 1];
    }
    printf("Aluno excluido com sucesso.\n");
    return qtd - 1;
}

void exibir_situacao(Aluno alunos[TAM], int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n%-25s %6s  %s\n", "Nome", "Media", "Situacao");
    printf("-------------------------------------------\n");
    for (int j = 0; j < qtd; j++) {
        float media = calcular_media(alunos[j]);
        printf("%-25s %6.2f  %s\n", alunos[j].nome, media,
               (media >= 6.0) ? "APROVADO" : "REPROVADO");
    }
}

void estatisticas_turma(Aluno alunos[TAM], int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int aprovados = 0, reprovados = 0;
    int maior = 0, menor = 0;
    float soma = 0;

    for (int j = 0; j < qtd; j++) {
        float media = calcular_media(alunos[j]);
        soma += media;
        if (media >= 6.0) aprovados++;
        else reprovados++;
        if (media > calcular_media(alunos[maior])) maior = j;
        if (media < calcular_media(alunos[menor])) menor = j;
    }

    printf("\n===== ESTATISTICAS DA TURMA =====\n");
    printf("Alunos cadastrados: %d\n", qtd);
    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);
    printf("Media geral da turma: %.2f\n", soma / qtd);
    printf("Maior media: %s (%.2f)\n", alunos[maior].nome, calcular_media(alunos[maior]));
    printf("Menor media: %s (%.2f)\n", alunos[menor].nome, calcular_media(alunos[menor]));
}