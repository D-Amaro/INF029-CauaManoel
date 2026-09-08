#include <stdlib.h>
#include <stdio.h>
#define TAM_ALUNO 3

#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3


// === Estruturas === // 
typedef struct alu {
    int matricula;
    char sexo;
    char nome[50];
    char cpf[15];
    Data Datanasc;
    int ativo;
} Aluno;

typedef struct prof {
    int matricula;
    char sexo;
    char nome[50];
    char cpf[15];
    Data Datanasc;
} Professor;


typedef struct disc {
    char nomeDisciplina[50];
    int codigoDisciplina;
    int semestre;
    int matriculaProfessor;
} Disciplina;

// protótipos
int menuGeral();
int menuAluno();
int CadastrarAluno(Aluno listaAluno[], int qtd_aluno);
void listarAluno(Aluno listaAluno[], int qtd_aluno);
int atualizarAluno(Aluno listaAluno[], int qtd_aluno);


int main(void) {

    Aluno listaAluno[TAM_ALUNO];
    int opcao;
    int qtd_aluno = 0;
    int matricula = 0;
    int sair = 0; // falso

    while (!sair) {

        opcao = menuGeral();

        switch (opcao) {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                printf("Módulo do Aluno\n");
                int SairAluno = 0;
                int opcaoAluno;
                while (!SairAluno) {

                    opcaoAluno = menuAluno();

                    switch (opcaoAluno) {
                        case 0: {
                            SairAluno = 1;
                            break;
                        }
                        case 1: {

                            int retorno = CadastrarAluno(listaAluno, qtd_aluno);

                            if (retorno == LISTA_CHEIA)
                                printf("Lista de aluno cheia \n");
                            else if (retorno == MATRICULA_INVALIDA)
                                printf("Mátricula Inválida \n");
                            else {
                                printf("Cadastrado com Sucesso \n");
                                qtd_aluno++;
                            }

                            break;
                        }
                        case 2: {

                            listarAluno(listaAluno, qtd_aluno);

                            break;
                        }

                        case 3: {
                           


                            break;
                        }
                        case 4: {
                            printf("Excluir Aluno \n");
                            printf("Digite a mátricula: \n");
                            scanf("%d", &matricula);
                            int achou = 0;

                            if (matricula < 0) {
                                printf("Mátricula Inválida \n");
                            } else {
                                for (int i = 0; i < qtd_aluno; i++)
                                {
                                    if (matricula == listaAluno[i].matricula) {
                                        // exclusão lógica
                                        listaAluno[i].ativo = -1;
                                        for (int j = i; j < qtd_aluno - 1; j++) { // shift: move alunos da frente para uma casa anterior
                                            listaAluno[j].matricula = listaAluno[j + 1].matricula; // posição J recebe
                                            listaAluno[j].sexo = listaAluno[j + 1].sexo;
                                            listaAluno[j].ativo = listaAluno[j + 1].ativo;
                                        }

                                        qtd_aluno--; // decrementa a quantidade de alunos
                                        achou = 1;
                                        break;
                                    }
                                }
                                if (achou)
                                    printf("Aluno excluido com sucesso \n");
                                else
                                    printf("Mátricula inexistente \n");
                            }
                            break;
                        }
                        default: {
                            printf("Opção Inválida \n");
                        }
                    }
                }
                break;
            }
            case 2: {
                printf("Módulo do Professor\n");
                break;
            }
            case 3: {
                printf("Módulo da Disciplina\n");
                break;
            }
            default: {
                printf("Opção Inválida\n");
            }
        }
    }

    return 0;
}

// Funções

int menuGeral() {

    int opcao;

    printf("====================\n");
    printf("Projeto Escola\n");
    printf("====================\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");

    scanf("%d", &opcao);

    return opcao;
}

int menuAluno() {

    int opcaoAluno;

    printf("0 - Voltar \n");
    printf("1 - Cadastrar Aluno \n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno \n");
    printf("4 - Excluir Aluno \n");

    scanf("%d", &opcaoAluno);

    return opcaoAluno;
}

int CadastrarAluno(Aluno listaAluno[], int qtd_aluno) {
    // Liberando acesso a lista e qtd

    printf("Cadastrar Aluno \n");
    if (qtd_aluno == TAM_ALUNO) {
        return LISTA_CHEIA;
    } else {
        printf("Digite a mátricula \n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        listaAluno[qtd_aluno].matricula = matricula; // Lista de alunos recebe o cadastro da mátricula em um vetor de tamanho qtd_aluno começando em 0
        listaAluno[qtd_aluno].ativo = 1;

        return CAD_ALUNO_SUCESSO;
    }
}

void listarAluno(Aluno listaAluno[], int qtd_aluno) {
    // void, pois está função não imprime

    printf("Listar Aluno \n");
    if (qtd_aluno == 0) {
        printf("Lista De Alunos Vazia\n");
    } else {
        for (int i = 0; i < qtd_aluno; i++)
        {
            if (listaAluno[i].ativo == 1)
                printf("Mátricula: %d\n", listaAluno[i].matricula);
        }
    }
}

int atualizarAluno(Aluno listaAluno[], int qtd_aluno){

    printf("Atualizar Aluno \n");
    printf("Digite a mátricula: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    int novamatricula;

    if (matricula < 0) {
        printf("Mátricula Inválida \n");
    } else {
        for (int i = 0; i < qtd_aluno; i++)
        {
            if (matricula == listaAluno[i].matricula && listaAluno[i].ativo) {
                // atualizacao
                printf("Digite a nova mátricula: \n");
                scanf("%d", &novamatricula);
                // resolver questão de mátricula negativa

                listaAluno[i].matricula = novamatricula;

                achou = 1;
                break;
            }
        }
        if (achou)
            printf("Aluno excluido com sucesso \n");
        else
            printf("Mátricula inexistente \n");
    }

}