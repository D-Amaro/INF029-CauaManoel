#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"
#include "utils.h"

// ================ PROTÓTIPOS ==============//
int menuGeral();
int menuAluno();
int menuProfessor();

int CadastrarAluno(Aluno listaAluno[], int qtd_aluno);
void listarAluno(Aluno listaAluno[], int qtd_aluno);
int atualizarAluno(Aluno listaAluno[], int qtd_aluno);
int excluirAluno(Aluno listaAluno[], int qtd_aluno);

int CadastrarProfessor(Professor listaProfessor[], int qtd_professor);
void ListarProfessor(Professor listaProfessor[], int qtd_professor);
int AtualizarProfessor(Professor listaProfessor[],int qtd_professor);
int ExcluirProfessor(Professor listaProfessor[], int qtd_professor);

int cadastrarDisciplina(Disciplina listaDisciplina[], int qtd_disciplina);


int main(void) {

    Professor listaProfessor[TAM_PROFESSOR];
    Aluno listaAluno[TAM_ALUNO];
    Disciplina listaDisciplina[TAM_DISCIPLINA];
    int opcao;
    int qtd_professor = 0;
    int qtd_disciplina = 0;
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
                while(!SairAluno){

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

                            int retorno = atualizarAluno(listaAluno, qtd_aluno);
                            if (retorno == MATRICULA_INVALIDA) 
                                printf("Matrícula inválida\n");
                            else if (retorno == ATUALIZACAO_ALUNO_SUCESSO) {
                                printf("Aluno atualizado com sucesso \n");
                            } else { (retorno == MATRICULA_INEXISTENTE);
                                printf("Matrícula inexistente\n");   
                            }
                            break;

                        }
                        case 4: {
                            
                            int retorno = excluirAluno(listaAluno, qtd_aluno);

                            if (retorno == MATRICULA_INVALIDA) 
                                printf("Matrícula inválida\n");
                            else if (retorno == EXCLUSAO_SUCESSO) {
                                printf("Mátricula Excluída com sucesso \n");
                                qtd_aluno--; // decrementa a quantidade de alunos
                            } else { (retorno == MATRICULA_INEXISTENTE);
                                printf("Matrícula inexistente\n");
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
                printf("\n=======================\n");
                printf("Módulo do Professor\n");
                printf("\n=======================\n");

                int SairProfessor = 0;
                int opcaoProfessor;

                while(!SairProfessor) {

                    opcaoProfessor = menuProfessor();
                
                    switch(opcaoProfessor) {
                        case 0: {
                            SairProfessor = 1;
                            break;
                        }
                        case 1: {

                            int retorno = CadastrarProfessor(listaProfessor, qtd_professor);

                            if (retorno == LISTA_CHEIA) 
                                printf("Limite máximo de professores cadastrados \n");
                            else if (retorno == MATRICULA_INVALIDA) { 
                                printf("Mátricula inválida \n");
                            } else { 
                                printf("Professor matrículo com sucesso \n");
                                qtd_professor++;
                            }
                            break;
                        }
                        case 2: {

                            ListarProfessor(listaProfessor, qtd_professor);
                            
                            break;

                        }
                        case 3: {

                            int retorno = AtualizarProfessor(listaProfessor, qtd_professor);

                            if (retorno == MATRICULA_INVALIDA) 
                                printf("Matrícula de professor inválida \n");
                            else if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO) {
                                printf("Atualizada com sucesso \n ");
                            } else { (retorno == MATRICULA_INEXISTENTE);
                                printf("Matrícula Inexistente \n");
                            }
                            break;

                        }
                        case 4: {

                            int retorno = ExcluirProfessor(listaProfessor, qtd_professor);

                            if (retorno == MATRICULA_INVALIDA) {
                                printf("Mátricula Invalida \n");
                            } else if (retorno == EXCLUSAO_SUCESSO) {
                                printf("Professor Excluido com sucesso \n");
                                qtd_professor--;
                            } else { (retorno == MATRICULA_INEXISTENTE);
                                printf("Mátricula Inexistente \n");
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

int menuProfessor() {

    int opcaoProfessor;

    printf("0 - Voltar \n");
    printf("1 - Cadastrar \n");
    printf("2 - Listar \n");
    printf("3 - Atualizar \n");
    printf("4 - Excluir \n");

    scanf("%d", &opcaoProfessor);

    return opcaoProfessor;
}

int ExcluirProfessor(Professor listaProfessor[], int qtd_professor) {

    int matricula;
    int achou = 0;

    printf("Excluir Professor \n");
    printf("Informe a matrícula para ser excluida: \n");
    scanf("%d", &matricula);

    if (matricula < 0 ) {
        return MATRICULA_INVALIDA;
    } else {
        for (int i = 0; i < qtd_professor; i++) 
        {
            if (matricula == listaProfessor[i].matricula) {

            listaProfessor[i].ativo = -1; // desativação lógica

                for (int j = i; j < qtd_professor - 1; j++) { // shift para ajustar o vetor
                    listaProfessor[j].matricula = listaProfessor[j+1].matricula;
                    listaProfessor[j].sexo = listaProfessor[j+1].matricula;
                    listaProfessor[j].ativo = listaProfessor[j+1].ativo;
                }
                achou = 1;
                break;
            }
        }    
            if(achou)
                return EXCLUSAO_SUCESSO;
            else 
                return MATRICULA_INEXISTENTE;
    }
}


int AtualizarProfessor (Professor listaProfessor[], int qtd_professor) {

    int achou = 0;
    int novamatricula;

    printf("Atualizar Professor \n");

    printf("Informe a mátricula atual: \n");
    int matricula;
    scanf("%d", &matricula);
    if ( matricula < 0) {
        return MATRICULA_INVALIDA;
    } else {
        for (int i = 0; i < qtd_professor; i++) 
            {
            if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo) {
                printf("Digite a nova matrícula: \n ");
                int novamatricula;
                scanf("%d", &novamatricula);

                if ( matricula < 0) {
                    return MATRICULA_INVALIDA;
                }

                listaProfessor[i].matricula = novamatricula;

                achou = 1;
                break;
            }
        }
            if (achou)
                    return ATUALIZACAO_PROFESSOR_SUCESSO;
            else 
                    return MATRICULA_INEXISTENTE;
    } 
}

void ListarProfessor(Professor listaProfessor[], int qtd_professor) {

    printf("Listar Professores \n");
    if (qtd_professor == 0) {
        printf("Lista de profesores vazia \n");
    } else { 
        for ( int i = 0; i < qtd_professor; i++)
        { 
            if ( listaProfessor[i].ativo == 1)
                printf("Mátricula: %d \n", &ListaProfessor[i].matricula);
        }
    }
}

int CadastrarProfessor(Professor listaProfessor[], int qtd_professor) {

    printf("\n==========================\n");
    printf("    Cadastrar Professor\n");
    printf("\n==========================\n");
    if (qtd_professor == TAM_PROFESSOR) {
        return LISTA_CHEIA;
    } else {
        printf("Digite a mátricula \n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        listaProfessor[qtd_professor].matricula = matricula; 
        listaProfessor[qtd_professor].ativo = 1;

            return CAD_PROFESSOR_SUCESSO;
    }   
}
int CadastrarAluno(Aluno listaAluno[], int qtd_aluno) {
    // Liberando acesso a lista e qtd
    printf("\n==========================\n");
    printf("      Cadastrar Aluno \n");
     printf("\n==========================\n");

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
        return MATRICULA_INVALIDA;
    } else {
        for (int i = 0; i < qtd_aluno; i++)
        {
            if (matricula == listaAluno[i].matricula && listaAluno[i].ativo) {
                // atualizacao
                printf("Digite a nova mátricula: \n");
                scanf("%d", &novamatricula);
               
                if (matricula < 0) {
                    return MATRICULA_INVALIDA;
                }
                // resolver questão de mátricula negativa

                listaAluno[i].matricula = novamatricula;

                achou = 1;
                break;
            }
        }
        if (achou)
            return ATUALIZACAO_ALUNO_SUCESSO;
        else
            return MATRICULA_INEXISTENTE;
    }

}

int excluirAluno(Aluno listaAluno[], int qtd_aluno) {

    printf("Excluir Aluno \n");
    printf("Digite a mátricula: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;

    if (matricula < 0) {
        return MATRICULA_INVALIDA;
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

                achou = 1;
                break;
            }
        }
        if (achou)
            return EXCLUSAO_SUCESSO;
        else
            return MATRICULA_INEXISTENTE;
    }

}