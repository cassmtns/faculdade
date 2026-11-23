#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define TAM 50
#define ARQUIVO "alunos.bin"

typedef struct {
    int id;
    char nome[50];
    char curso[50];
    float n1;
    float n2;
} Aluno;

/* Etapa I */
void cadastrar_aluno(Aluno *alunos, int *qtd);
void listar_alunos(Aluno *alunos, int qtd);
float calcular_media(Aluno *aluno);
char *obter_situacao(Aluno *aluno);
void exibir_situacao(Aluno *alunos, int qtd);
void estatisticas_turma(Aluno *alunos, int qtd);

/* Etapa II (ponteiros para estruturas) */
Aluno *buscar_aluno(Aluno *alunos, int qtd, int matricula);
void pesquisar_aluno(Aluno *alunos, int qtd);
void alterar_aluno(Aluno *alunos, int qtd);
void excluir_aluno(Aluno *alunos, int *qtd);

/* Etapa III (arquivos) */
void salvar_alunos(Aluno *alunos, int qtd);
int carregar_alunos(Aluno *alunos);

#endif