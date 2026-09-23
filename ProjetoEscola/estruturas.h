#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include "defines.h"

// == Estruturas == //

typedef struct data {

    char dataCompleta[11];
    int dia;
    int mes;
    int ano;

} DataNascimento;

typedef struct alu {
    int matricula;
    char sexo;
    char nome[50];
    DataNascimento DataNascimento;
    char cpf[15];
    int ativo;
} Aluno;

typedef struct prof {
    int matricula;
    char sexo;
    char nome[50];
    DataNascimento DataNascimento;
    char cpf[15];
    int ativo;
} Professor;


typedef struct disc {
    char nome[50];
    int codigoDisciplina;
    int semestre;
    int matriculaProfessor;
    int ativo;
    int matriculaAlunos[TAM_MAX_ALUNOS];
    int qtd_alunos_disciplina;
} Disciplina;


#endif