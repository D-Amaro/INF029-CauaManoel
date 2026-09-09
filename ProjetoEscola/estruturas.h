// == Estruturas == //

typedef struct alu {
    int matricula;
    char sexo;
    char nome[50];
    char cpf[15];
    int ativo;
} Aluno;

typedef struct prof {
    int matricula;
    char sexo;
    char nome[50];
    char cpf[15];
} Professor;


typedef struct disc {
    char nomeDisciplina[50];
    int codigoDisciplina;
    int semestre;
    int matriculaProfessor;
} Disciplina;
