#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "estruturas.h"
#include "defines.h"

// ================ PROTÓTIPOS ============== //
int menuGeral();
int menuAluno();
int menuProfessor();
int menuDisciplina();
int MenuListagem();
int menuRelatorios();

void limparBuffer(void);
void removerQuebraLinha(char s[]);
int cpfvalido(char cpf[]);
int valida_data_numeros(int dia, int mes, int ano);
int compararData(DataNascimento data1, DataNascimento data2);

int CadastrarAluno(Aluno listaAluno[], int qtd_aluno);
void listarAluno(Aluno listaAluno[], int qtd_aluno);
void listarAlunoSexo(Aluno listaAluno[], int qtd_aluno);
void listarAlunoAlfabetica (Aluno listaAluno[], int qtd_aluno);
void listarAlunoData(Aluno listaAluno[], int qtd_aluno);

int atualizarAluno(Aluno listaAluno[], int qtd_aluno);
int excluirAluno(Aluno listaAluno[], int qtd_aluno);

int CadastrarProfessor(Professor listaProfessor[], int qtd_professor);
void ListarProfessor(Professor listaProfessor[], int qtd_professor);
int AtualizarProfessor(Professor listaProfessor[],int qtd_professor);
int ExcluirProfessor(Professor listaProfessor[], int qtd_professor);

int cadastrarDisciplina(Disciplina listaDisciplina[], int qtd_disciplina);
void listarDisciplina(Disciplina listaDisciplina[], int qtd_disciplina);
void atualizarDisciplina(Disciplina listaDisciplina[], int qtd_disciplina);
void excluirDisciplina(Disciplina listaDisciplina[], int qtd_disciplina);


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
                printf("===================\n");
                printf("  Menu do Aluno\n");
                printf("===================\n");

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
                                printf("Limite máximo de alunos cadastrados. \n");
                            else if (retorno == MATRICULA_INVALIDA)
                                printf("Mátricula Inválida. \n");
                            else if (retorno == SEXO_INVALIDO) 
                                printf("O sexo informado é inválido. \n");
                            else {
                                printf("Aluno cadastrado com sucesso!\n"); 
                                qtd_aluno++;
                            }

                            break;
                        }
                        case 2: {
                            
                            int sairLista = 0;
                            int opcaoLista;

                            while(!sairLista) {
                                 opcaoLista = MenuListagem();

                                 switch(opcaoLista) {
                                    case 0: {
                                        sairLista = 1;
                                        break;
                                    }
                                    case 1: {

                                        listarAluno(listaAluno, qtd_aluno);
                                        break;
                                    }
                                    case 2: {

                                        listarAlunoSexo(listaAluno, qtd_aluno);
                                        break;
                                    }
                                    case 3: {

                                        listarAlunoAlfabetica(listaAluno, qtd_aluno);
                                        break;
                                    }
                                    case 4: {

                                        listarAlunoData(listaAluno, qtd_aluno);
                                        break;
                                    }
                        default: {
                            printf("Opção Inválida. \n");
                        }
                    }
                }
                break;
            }
                        case 3: {

                            int retorno = atualizarAluno(listaAluno, qtd_aluno);

                            if (retorno == MATRICULA_INVALIDA) 
                                printf("Matrícula inválida.\n");
                            else if (retorno == ATUALIZACAO_ALUNO_SUCESSO) {
                                printf("Nome atualizado com sucesso! \n");
                            } else { 
                                printf("Matrícula inexistente.\n");   
                            }
                            break;

                        }
                        case 4: {
                            
                            int retorno = excluirAluno(listaAluno, qtd_aluno);

                            if (retorno == MATRICULA_INVALIDA) 
                                printf("Matrícula inválida.\n");
                            else if (retorno == EXCLUSAO_SUCESSO) {
                                printf("Aluno excluído com sucesso! \n");
                                qtd_aluno--; // decrementa a quantidade de alunos
                            } else { 
                                printf("Matrícula inexistente.\n");
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
                printf("   Menu do Professor\n");
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
                            else if (retorno == MATRICULA_INVALIDA)
                                printf("Mátricula inválida \n");
                            else if (retorno == SEXO_INVALIDO) 
                                printf("O sexo informado é inválido. \n");
                            else { 
                                printf("Professor cadastrado com sucesso! \n");
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
                                printf("Matrícula de professor inválida. \n");
                            else if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO) {
                                printf("Nome atualizado com sucesso! \n ");
                            } else { 
                                printf("Matrícula Inexistente \n");
                            }
                            break;

                        }
                        case 4: {

                            int retorno = ExcluirProfessor(listaProfessor, qtd_professor);

                            if (retorno == MATRICULA_INVALIDA) {
                                printf("Mátricula Invalida \n");
                            } else if (retorno == EXCLUSAO_SUCESSO) {
                                printf("Professor Excluido com sucesso! \n");
                                qtd_professor--;
                            } else {
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
                printf("\n=======================\n");
                printf("Menu de Disciplina\n");
                printf("\n=======================\n");

                int opcaoDisciplina;
                int SairDisciplina = 0;

                while(!SairDisciplina) {
                    
                    opcaoDisciplina = menuDisciplina();

                switch(opcaoDisciplina) {

                    case 0: {
                    SairDisciplina = 1;
                    break;
                    }
                    case 1: {


                    }




                }
                }
                    

                break;
            }

            case 4: {

                printf("\n=======================\n");
                printf("    Menu de Relatórios \n");
                printf("\n=======================\n");

                int opcaoRelatorio;
                int SairRelatorio = 0;

                while(!SairRelatorio){

                    opcaoRelatorio = menuRelatorios();

                    switch(opcaoRelatorio){
                        case 0: {
                            SairRelatorio = 1;
                            break;
                        }
                        case 1: {

                        }
                        case 2: {

                        }
                        case 3: {

                        }
                        case 4: {

                        }
                        default: {
                            printf("Opção Inválida \n");
                        }
                    }
                }
                break;
            }

            default: {
                printf("Opção Inválida\n");
            }
        }
    }

    return 0;
}

//============ Funções ============//

int menuGeral() {

    int opcao;

    printf("====================\n");
    printf("  Projeto Escola\n");
    printf("====================\n");
    printf("0 - Sair\n");
    printf("1 - Menu de Aluno\n");
    printf("2 - Menu de Professor\n");
    printf("3 - Menu de Disciplina\n");
    printf("4 - Menu de Relatórios\n");

    scanf("%d", &opcao);
    limparBuffer();

    return opcao;
}

int MenuListagem() {

    int opcaoLista;

    printf("====================\n");
    printf("Opções de Listagem \n");
    printf("====================\n");

    printf("0 - Voltar \n");
    printf("1 - Listagem convencional \n");
    printf("2 - Listar por Sexo \n");
    printf("3 - Listar em ordem alfabética \n");
    printf("4 - Listar por data de nascimento \n");

    scanf("%d", &opcaoLista);
    limparBuffer();

    return opcaoLista;
}

int menuRelatorios() {

    int opcaoRelatorio;

    printf("====================\n");
    printf(" Menu de Relatórios \n");
    printf("====================\n");

    printf("0 - Voltar \n");
    printf("1 - Aniversariantes do mês \n");
    printf("2 - Busca por nome \n");
    printf("3 - Alunos irregulares \n");
    printf("4 - Disciplinas com mais de 40 vagas \n");

    scanf("%d", &opcaoRelatorio);
    limparBuffer();

    return opcaoRelatorio;
}

int menuDisciplina() {

    int opcaoDisciplina;

    printf("====================\n");
    printf("Projeto Escola\n");
    printf("====================\n");

    printf("0 - Voltar \n");
    printf("1 - Cadastrar Disciplina \n");
    printf("2 - Listar Disciplina\n");
    printf("3 - Atualizar Disciplina \n");
    printf("4 - Excluir Disciplina \n");

    scanf("%d", &opcaoDisciplina);
    limparBuffer();

    return opcaoDisciplina;

}

int menuAluno() {

    int opcaoAluno;

    printf("0 - Voltar \n");
    printf("1 - Cadastrar Aluno \n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno \n");
    printf("4 - Excluir Aluno \n");

    scanf("%d", &opcaoAluno);
    limparBuffer();

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
    limparBuffer();

    return opcaoProfessor;
}

int cadastrarDisciplina(Disciplina listaDisciplina[], int qtd_disciplina) {

    printf("\n==========================\n");
    printf("    Cadastrar Disciplina\n");
    printf("\n==========================\n");
    if (qtd_disciplina == TAM_DISCIPLINA) {
        return LISTA_CHEIA;
    } else {
        printf("Digite o código da discplina: \n");
        int codigoDisciplina;
        scanf("%d", &codigoDisciplina);

        if (codigoDisciplina < 0) {
            return MATRICULA_INVALIDA;
        }

        listaDisciplina[qtd_disciplina].codigoDisciplina = codigoDisciplina;
        listaDisciplina[qtd_disciplina].ativo = 1;

        return COD_DISCIPLINA_SUCESSO;

    }
}

void listarDisciplina(Disciplina listaDisciplina[], int qtd_disciplina){

}
void atualizarDisciplina(Disciplina listaDisciplina[], int qtd_disciplina) {

}
void excluirDisciplina(Disciplina listaDisciplina[], int qtd_disciplina){
    
}



int ExcluirProfessor(Professor listaProfessor[], int qtd_professor) {

    int matricula;
    int achou = 0;

    printf("========================\n");
    printf("    Excluir Professor \n");
    printf("========================\n");
    printf("Informe a matrícula para ser excluida: \n");
    scanf("%d", &matricula);
    limparBuffer();

    if (matricula < 0 ) {
        return MATRICULA_INVALIDA;
    } else {
        for (int i = 0; i < qtd_professor; i++) 
        {
            if (matricula == listaProfessor[i].matricula) {

            listaProfessor[i].ativo = -1; // desativação lógica

                for (int j = i; j < qtd_professor - 1; j++) { // shift para ajustar o vetor
                    listaProfessor[j].matricula = listaProfessor[j+1].matricula;
                    strcpy(listaProfessor[j].nome,listaProfessor[j+1].nome);
                    strcpy(listaProfessor[j].cpf, listaProfessor[j+1].cpf);
                    listaProfessor[j].sexo = listaProfessor[j+1].sexo;
                    listaProfessor[j].DataNascimento = listaProfessor[j+1].DataNascimento;
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

    printf("===========================\n");
    printf("    Atualizar Professor \n");
    printf("===========================\n");

    printf("Informe a mátricula do usuario (ATT NOME): \n");
    int matricula;
    scanf("%d", &matricula);
    limparBuffer();

    if ( matricula < 0) {
        return MATRICULA_INVALIDA;
    } else {
        for (int i = 0; i < qtd_professor; i++) 
            {
            if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo) {

                printf("Informe o novo nome: \n ");
                fgets(listaProfessor[i].nome,50,stdin);
                removerQuebraLinha(listaProfessor[i].nome);
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
            if ( listaProfessor[i].ativo == 1) {
                printf("Mátricula: %d \n", listaProfessor[i].matricula);
                printf("Nome: %s\n", listaProfessor[i].nome);
                printf("Sexo: %c\n", listaProfessor[i].sexo);
                printf("Data de nascimento %d / %d / %d\n",
            listaProfessor[i].DataNascimento.dia,
            listaProfessor[i].DataNascimento.mes,
            listaProfessor[i].DataNascimento.ano);
                printf("CPF: %s", listaProfessor[i].cpf);
                printf("--------------------------------------\n");
            }
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
        scanf("%d", &listaProfessor[qtd_professor].matricula);
        limparBuffer();

        if (listaProfessor[qtd_professor].matricula < 0) {
            return MATRICULA_INVALIDA;
        }

        printf("Digite o nome do professor: \n");
        fgets(listaProfessor[qtd_professor].nome,50,stdin);
        removerQuebraLinha(listaProfessor[qtd_professor].nome);

        printf("Digite o sexo: \n");
        scanf(" %c", &listaProfessor[qtd_professor].sexo);
        limparBuffer();
    
        listaProfessor[qtd_professor].sexo = toupper(listaProfessor[qtd_professor].sexo);
        if (listaProfessor[qtd_professor].sexo != 'M' && listaProfessor[qtd_professor].sexo != 'F')
        {
            return SEXO_INVALIDO;
        }

        int datavalida;

        do {
        printf("Digite o dia de nascimento: \n");
        scanf("%d", &listaProfessor[qtd_professor].DataNascimento.dia);
        limparBuffer();

        printf("Digite o mês de nascimento: \n");
        scanf("%d", &listaProfessor[qtd_professor].DataNascimento.mes);
        limparBuffer();

        printf("Digite o ano de nascimento: \n");
        scanf("%d", &listaProfessor[qtd_professor].DataNascimento.ano);
        limparBuffer();

        datavalida = valida_data_numeros(
            listaProfessor[qtd_professor].DataNascimento.dia,
            listaProfessor[qtd_professor].DataNascimento.mes,
            listaProfessor[qtd_professor].DataNascimento.ano
        );
        if (!datavalida)
            printf("Data Inválida! Por favor, digite novamente. \n");
    } while (!datavalida);

    int validarcpf;

    do {
        printf("Digite o CPF: \n");
        fgets(listaProfessor[qtd_professor].cpf, 13, stdin);
        removerQuebraLinha(listaProfessor[qtd_professor].cpf);

        validarcpf  = cpfvalido(listaProfessor[qtd_professor].cpf);

        if (!validarcpf)
           printf("CPF Inválido. Digite apenas os 11 números. \n");
    } while (!validarcpf);

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
        scanf("%d", &listaAluno[qtd_aluno].matricula);
        limparBuffer();

        if (listaAluno[qtd_aluno].matricula < 0) {
            return MATRICULA_INVALIDA;
        }

        printf("Digite o nome do aluno: \n");
        fgets(listaAluno[qtd_aluno].nome, 50, stdin);
        removerQuebraLinha(listaAluno[qtd_aluno].nome);

        printf("Digite o sexo: \n");
        scanf(" %c", &listaAluno[qtd_aluno].sexo);
        limparBuffer();

        listaAluno[qtd_aluno].sexo = toupper(listaAluno[qtd_aluno].sexo);
        if (listaAluno[qtd_aluno].sexo != 'M' && listaAluno[qtd_aluno].sexo != 'F')
        {
            return SEXO_INVALIDO;
        }

        int datavalida;

        do {
        printf("Digite o dia de nascimento: \n");
        scanf("%d", &listaAluno[qtd_aluno].DataNascimento.dia);
        limparBuffer();

        printf("Digite o mês de nascimento: \n");
        scanf("%d", &listaAluno[qtd_aluno].DataNascimento.mes);
        limparBuffer();

        printf("Digite o ano de nascimento: \n");
        scanf("%d", &listaAluno[qtd_aluno].DataNascimento.ano);
        limparBuffer();

        datavalida = valida_data_numeros (
            listaAluno[qtd_aluno].DataNascimento.dia,
            listaAluno[qtd_aluno].DataNascimento.mes,
            listaAluno[qtd_aluno].DataNascimento.ano
        );

        if(!datavalida)
            printf("Data Inválida! Por favor, digite novamente. \n");
    } while (!datavalida);

    int validarcpf;

    do {
        printf("Digite o CPF: \n");
        fgets(listaAluno[qtd_aluno].cpf, 13, stdin);
        removerQuebraLinha(listaAluno[qtd_aluno].cpf);

        validarcpf = cpfvalido(listaAluno[qtd_aluno].cpf);

        if (!validarcpf)
            printf("CPF Inválido. Digite apenas os 11 números. \n");
    } while (!validarcpf);

        listaAluno[qtd_aluno].ativo = 1;

        return CAD_ALUNO_SUCESSO;
    }
}

void listarAluno(Aluno listaAluno[], int qtd_aluno) {
    // void, pois está função não imprime

    printf("=========================\n");
    printf("  Listagem Convencional \n");
    printf("=========================\n");
    if (qtd_aluno == 0) {
        printf("Lista de alunos vazia.\n");
    } else {
        for (int i = 0; i < qtd_aluno; i++)
        {
            if (listaAluno[i].ativo == 1) {
                printf("Mátricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("Data de nascimento %d / %d / %d\n",
            listaAluno[i].DataNascimento.dia,
            listaAluno[i].DataNascimento.mes,
            listaAluno[i].DataNascimento.ano);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("--------------------------------------\n");
            }
        }
    }
}

void listarAlunoSexo(Aluno listaAluno[], int qtd_aluno) {

    printf("=========================\n");
    printf("  Listagem por Sexo \n");
    printf("=========================\n");
    if (qtd_aluno == 0) {
        printf("Lista de alunos vazia.\n");
        return;
    }

        char sexovalido;
        do {
            printf("Informe o sexo a ser listado ( M / F ): \n");
            scanf(" %c",&sexovalido);
            limparBuffer();

        sexovalido = toupper(sexovalido);
        if (sexovalido != 'M' && sexovalido != 'F')
            printf("Sexo inválido! Digite M ou F \n");

        } while(sexovalido != 'M' && sexovalido != 'F');

        for (int i = 0; i < qtd_aluno; i++) {
            if (listaAluno[i].ativo == 1 && listaAluno[i].sexo == sexovalido) {
                printf("Mátricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("Data de nascimento %d / %d / %d\n",
            listaAluno[i].DataNascimento.dia,
            listaAluno[i].DataNascimento.mes,
            listaAluno[i].DataNascimento.ano);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("--------------------------------------\n");

        }
    }
}

void listarAlunoAlfabetica (Aluno listaAluno[], int qtd_aluno) {

    printf("====================================\n");
    printf("  Listagem por ordem alfabética \n");
    printf("====================================\n");
    if (qtd_aluno == 0) {
        printf("Lista de alunos vazia.\n");
        return;
    }

    for (int i = 0; i < qtd_aluno - 1; i++){
        for (int j = 0; j < qtd_aluno - 1 - i; j++) {
            if (strcmp(listaAluno[j].nome, listaAluno[j+1].nome) > 0) {
                Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j+1];
                listaAluno[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < qtd_aluno; i++) {
        if (listaAluno[i].ativo == 1) {
                printf("Mátricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("Data de nascimento %d / %d / %d\n",
                listaAluno[i].DataNascimento.dia,
                listaAluno[i].DataNascimento.mes,
                listaAluno[i].DataNascimento.ano);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("--------------------------------------\n");
            }
        }
    }

void listarAlunoData(Aluno listaAluno[], int qtd_aluno) {

    printf("====================================\n");
    printf("  Listagem por data de nascimento \n");
    printf("====================================\n");
    if (qtd_aluno == 0) {
        printf("Lista de alunos vazia.\n");
    return;
    }

    for(int i = 0; i < qtd_aluno - 1; i++){
        for(int j = 0; j < qtd_aluno - 1 - i; j++) {
            if(compararData(listaAluno[j].DataNascimento, listaAluno[j+1].DataNascimento)) {
            Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j+1];
                listaAluno[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < qtd_aluno; i++) {
        if (listaAluno[i].ativo == 1) {
                printf("Mátricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("Data de nascimento %d / %d / %d\n",
                listaAluno[i].DataNascimento.dia,
                listaAluno[i].DataNascimento.mes,
                listaAluno[i].DataNascimento.ano);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("--------------------------------------\n");
            }
        }
}

int atualizarAluno(Aluno listaAluno[], int qtd_aluno){

    printf("Atualizar Aluno \n");
    printf("Digite a mátricula: \n");
    int matricula;
    scanf("%d", &matricula);
    limparBuffer();

    int achou = 0;
    int novamatricula;

    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    } else {
        for (int i = 0; i < qtd_aluno; i++)
        {
            if (matricula == listaAluno[i].matricula && listaAluno[i].ativo) {

                printf("Informe o novo nome: \n ");
                fgets(listaAluno[i].nome,50,stdin);
                removerQuebraLinha(listaAluno[i].nome);
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
    limparBuffer();

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
                    listaAluno[j].matricula = listaAluno[j+1].matricula;
                    strcpy(listaAluno[j].nome,listaAluno[j+1].nome);
                    strcpy(listaAluno[j].cpf, listaAluno[j+1].cpf);
                    listaAluno[j].sexo = listaAluno[j+1].sexo;
                    listaAluno[j].DataNascimento = listaAluno[j+1].DataNascimento;
                    listaAluno[j].ativo = listaAluno[j+1].ativo;
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