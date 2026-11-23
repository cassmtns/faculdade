#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define TAM 50

typedef struct {
    int id;
    char nome[50];
    char curso[50];
    float n1;
    float n2;
} Aluno;

int cadastrar_aluno(Aluno alunos[TAM], int qtd);
void listar_alunos(Aluno alunos[TAM], int qtd);
float calcular_media(Aluno aluno);
int buscar_aluno(Aluno alunos[TAM], int qtd, int matricula);
void pesquisar_aluno(Aluno alunos[TAM], int qtd);
void alterar_aluno(Aluno alunos[TAM], int qtd);
int excluir_aluno(Aluno alunos[TAM], int qtd);
void exibir_situacao(Aluno alunos[TAM], int qtd);
void estatisticas_turma(Aluno alunos[TAM], int qtd);

#endif