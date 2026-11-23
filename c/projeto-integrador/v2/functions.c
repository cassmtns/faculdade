#include <stdio.h>
#include "functions.h"



float calcular_media(Aluno *aluno) {
    return (aluno->n1 + aluno->n2) / 2.0f;
}

char *obter_situacao(Aluno *aluno) {
    return (calcular_media(aluno) >= 6.0f) ? "APROVADO" : "REPROVADO";
}

void cadastrar_aluno(Aluno *alunos, int *qtd) {
    if (*qtd >= TAM) {
        printf("Limite de %d alunos atingido. Nao e possivel cadastrar.\n", TAM);
        return;
    }

    Aluno *novo = &alunos[*qtd];
    int matricula;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    while (matricula <= 0 || buscar_aluno(alunos, *qtd, matricula) != NULL) {
        if (matricula <= 0)
            printf("Matricula invalida. Digite novamente: ");
        else
            printf("Matricula ja cadastrada. Digite novamente: ");
        scanf("%d", &matricula);
    }
    novo->id = matricula;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", novo->nome);

    printf("Digite o curso do aluno: ");
    scanf(" %[^\n]", novo->curso);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &novo->n1);
    while (novo->n1 < 0 || novo->n1 > 10) {
        printf("Nota invalida. Digite novamente: ");
        scanf("%f", &novo->n1);
    }

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &novo->n2);
    while (novo->n2 < 0 || novo->n2 > 10) {
        printf("Nota invalida. Digite novamente: ");
        scanf("%f", &novo->n2);
    }

    (*qtd)++;
    printf("Aluno cadastrado com sucesso.\n");
}

void listar_alunos(Aluno *alunos, int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %6s  %s\n", "Matricula", "Nome", "Curso", "Media", "Situacao");
    printf("--------------------------------------------------------------------------\n");
    for (Aluno *p = alunos; p < alunos + qtd; p++) {
        printf("%-10d %-25s %-20s %6.2f  %s\n",
               p->id, p->nome, p->curso, calcular_media(p), obter_situacao(p));
    }
}

void exibir_situacao(Aluno *alunos, int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n%-25s %6s  %s\n", "Nome", "Media", "Situacao");
    printf("-------------------------------------------\n");
    for (Aluno *p = alunos; p < alunos + qtd; p++) {
        printf("%-25s %6.2f  %s\n", p->nome, calcular_media(p), obter_situacao(p));
    }
}

void estatisticas_turma(Aluno *alunos, int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int aprovados = 0, reprovados = 0;
    float soma = 0;
    Aluno *maior = alunos;
    Aluno *menor = alunos;

    for (Aluno *p = alunos; p < alunos + qtd; p++) {
        float media = calcular_media(p);
        soma += media;
        if (media >= 6.0f) aprovados++;
        else reprovados++;
        if (media > calcular_media(maior)) maior = p;
        if (media < calcular_media(menor)) menor = p;
    }

    printf("\n===== ESTATISTICAS DA TURMA =====\n");
    printf("Alunos cadastrados: %d\n", qtd);
    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);
    printf("Media geral da turma: %.2f\n", soma / qtd);
    printf("Maior media: %s (%.2f)\n", maior->nome, calcular_media(maior));
    printf("Menor media: %s (%.2f)\n", menor->nome, calcular_media(menor));
}

Aluno *buscar_aluno(Aluno *alunos, int qtd, int matricula) {
    for (Aluno *p = alunos; p < alunos + qtd; p++) {
        if (p->id == matricula) {
            return p;
        }
    }
    return NULL;
}

void pesquisar_aluno(Aluno *alunos, int qtd) {
    int matricula;
    printf("Digite a matricula do aluno que deseja pesquisar: ");
    scanf("%d", &matricula);

    Aluno *aluno = buscar_aluno(alunos, qtd, matricula);
    if (aluno == NULL) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    printf("\nAluno encontrado:\n");
    printf("Matricula: %d\n", aluno->id);
    printf("Nome: %s\n", aluno->nome);
    printf("Curso: %s\n", aluno->curso);
    printf("Nota 1: %.2f\n", aluno->n1);
    printf("Nota 2: %.2f\n", aluno->n2);
    printf("Media: %.2f\n", calcular_media(aluno));
    printf("Situacao: %s\n", obter_situacao(aluno));
}

void alterar_aluno(Aluno *alunos, int qtd) {
    int matricula, opcao;
    printf("Digite a matricula do aluno que deseja alterar: ");
    scanf("%d", &matricula);

    Aluno *aluno = buscar_aluno(alunos, qtd, matricula);
    if (aluno == NULL) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    do {
        printf("\nAlterando: %s (matricula %d)\n", aluno->nome, aluno->id);
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
                scanf(" %[^\n]", aluno->nome);
                break;
            case 2:
                printf("Novo curso: ");
                scanf(" %[^\n]", aluno->curso);
                break;
            case 3:
                printf("Nova nota 1: ");
                scanf("%f", &aluno->n1);
                while (aluno->n1 < 0 || aluno->n1 > 10) {
                    printf("Nota invalida. Digite novamente: ");
                    scanf("%f", &aluno->n1);
                }
                break;
            case 4:
                printf("Nova nota 2: ");
                scanf("%f", &aluno->n2);
                while (aluno->n2 < 0 || aluno->n2 > 10) {
                    printf("Nota invalida. Digite novamente: ");
                    scanf("%f", &aluno->n2);
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

void excluir_aluno(Aluno *alunos, int *qtd) {
    int matricula;
    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    Aluno *aluno = buscar_aluno(alunos, *qtd, matricula);
    if (aluno == NULL) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    Aluno *fim = alunos + *qtd;
    for (Aluno *p = aluno; p < fim - 1; p++) {
        *p = *(p + 1);
    }
    (*qtd)--;
    printf("Aluno excluido com sucesso.\n");
}