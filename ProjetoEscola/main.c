#include <stdlib.h>
#include <stdio.h>
#define TAM_ALUNO 3

typedef struct alu {
    int matricula;
    char sexo;
    int ativo;
} Aluno;

int main(void) {

    Aluno listaAluno[TAM_ALUNO];
    int opcao;
    int qtd_aluno = 0;
    int matricula = 0;
    int sair = 0; //falso

    while(!sair) {
        printf("====================\n");
        printf("Projeto Escola\n");
        printf("====================\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                printf("Módulo do Aluno\n");
                int SairAluno = 0;
                int opcaoAluno;
                while(!sair){

                printf("0 - Voltar \n");
                printf("1 - Cadastrar Aluno \n");
                printf("2 - Listar Aluno\n");
                printf("3 - Atualizar Aluno \n");
                printf("4 - Excluir Aluno \n");

                scanf("%d", &opcaoAluno);

                switch(opcaoAluno){
                    case 0: {
                        SairAluno = 1;
                        break;
                    }
                    case 1: {
                        printf("Cadastrar Aluno \n");
                        if (qtd_aluno == TAM_ALUNO) {
                            printf("Lista de alunos cheia \n");
                        } else {
                            
                            printf("Digite a mátricula \n");
                            scanf("%d", &matricula);
                        if (matricula < 0) {
                            printf("Mátricula Inválida\n");                         
                        }
                            listaAluno[qtd_aluno].matricula = matricula;//Lista de alunos recebe o cadastro da mátricula em um vetor de tamanho qtd_aluno começando em 0
                            listaAluno[qtd_aluno].ativo = 1;
                            qtd_aluno++;
                            printf("Mátriculado com sucesso\n");
                            }
                        }
                        break;

                    case 2: {
                        printf("Listar Aluno \n");
                        if (qtd_aluno == 0) {
                            printf("Lista De Alunos Vazia\n");
                        } else {    
                        for(int i=0; i<qtd_aluno; i++)
                        {
                            if (listaAluno[i].ativo)
                            printf("Mátricula: %d\n", listaAluno[i].matricula);
                             }
                        }
                        break;
                    }
                    
                    case 3: {
                        printf("Atualizar Aluno \n");
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
                                for(int i=0; i < qtd_aluno; i++) 
                                { 
                                    if (matricula == listaAluno[i].matricula) {
                                    // exclusão lógica
                                    listaAluno[i].ativo = -1;
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
                        break;
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
            } default: {
                printf("Opção Inválida\n");
                }
            }
        }

        return 0;
    }