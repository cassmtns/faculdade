#include <stdio.h>
#include "functions.h"

int main() {
    Aluno alunos[TAM];
    int qtd = 0;
    int opc;

    qtd = carregar_alunos(alunos);

    do {
        printf("\n==================================\n");
        printf("SISTEMA DE GERENCIAMENTODE ALUNOS\n");
        printf("==================================\n\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Pesquisar aluno\n");
        printf("4 - Alterar dados de um aluno\n");
        printf("5 - Excluir aluno\n");
        printf("6 - Exibir situacao dos alunos\n");
        printf("7 - Estatisticas da turma\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cadastrar_aluno(alunos, &qtd);
                salvar_alunos(alunos, qtd);
                break;
            case 2:
                listar_alunos(alunos, qtd);
                break;
            case 3:
                pesquisar_aluno(alunos, qtd);
                break;
            case 4:
                alterar_aluno(alunos, qtd);
                salvar_alunos(alunos, qtd);
                break;
            case 5:
                excluir_aluno(alunos, &qtd);
                salvar_alunos(alunos, qtd);
                break;
            case 6:
                exibir_situacao(alunos, qtd);
                break;
            case 7:
                estatisticas_turma(alunos, qtd);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opc != 0);

    return 0;
}