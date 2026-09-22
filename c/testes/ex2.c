#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ra;
    char nome[50];
    float nota;
} Aluno;

int main() {
    int n;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida de alunos.\n");
        return 1;
    }

    Aluno alunos[n];

    float soma_notas = 0.0;
    int indice_maior_nota = 0;

    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("RA: ");
        scanf("%d", &alunos[i].ra);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);

        soma_notas += alunos[i].nota;

        if (alunos[i].nota > alunos[indice_maior_nota].nota) {
            indice_maior_nota = i;
        }
    }

    float media = soma_notas / n;

    printf("\n================ RESULTADOS ================\n");
    printf("Media das notas da turma: %.2f\n", media);
    printf("RA do aluno com a maior nota (%.2f): %d (%s)\n", 
           alunos[indice_maior_nota].nota, 
           alunos[indice_maior_nota].ra,
           alunos[indice_maior_nota].nome);

    return 0;
}