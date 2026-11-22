#include <stdio.h>
#include <stdlib.h>

#include "trabalho2.h"


int menu();
void opcaoInserir();
void opcaoListarTodas();
void opcaoListarOrdenadasPorEstrutura();
void opcaoListarTodosOrdenados();
void opcaoExcluir();
void opcaoAumentar();
int contarTotalElementos();

int menu()
{
    int op;
    printf("\n===== MENU =====\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados de cada estrutura\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}


int contarTotalElementos()
{
    int i, qtd, total = 0;
    for (i = 1; i <= 10; i++)
    {
        qtd = getQuantidadeElementosEstruturaAuxiliar(i);
        if (qtd > 0)
            total += qtd;
    }
    return total;
}

void opcaoInserir()
{
    int posicao, valor, tamanho, ret;

    printf("Posicao (1..10): ");
    scanf("%d", &posicao);
    printf("Numero a inserir: ");
    scanf("%d", &valor);

    ret = inserirNumeroEmEstrutura(posicao, valor);


    if (ret == SEM_ESTRUTURA_AUXILIAR)
    {
        printf("Ainda nao existe estrutura auxiliar nessa posicao.\n");
        printf("Tamanho total da estrutura auxiliar: ");
        scanf("%d", &tamanho);

        ret = criarEstruturaAuxiliar(posicao, tamanho);
        if (ret == SUCESSO)
        {
            ret = inserirNumeroEmEstrutura(posicao, valor);
        }
        else if (ret == TAMANHO_INVALIDO)
        {
            printf("Tamanho invalido (deve ser >= 1).\n");
            return;
        }
        else if (ret == SEM_ESPACO_DE_MEMORIA)
        {
            printf("Sem espaco de memoria.\n");
            return;
        }
    }

    if (ret == SUCESSO)
        printf("Inserido com sucesso.\n");
    else if (ret == SEM_ESPACO)
        printf("Sem espaco para inserir mais numeros nessa estrutura.\n");
    else if (ret == POSICAO_INVALIDA)
        printf("Posicao invalida.\n");
}

void opcaoListarTodas()
{
    int i, j, tam, qtd;

    for (i = 1; i <= 10; i++)
    {
        tam = getTamanhoEstruturaAuxiliar(i);
        if (tam == SEM_ESTRUTURA_AUXILIAR)
        {
            printf("Posicao %d: sem estrutura auxiliar\n", i);
            continue; // pula para a próxima posição
        }

        qtd = getQuantidadeElementosEstruturaAuxiliar(i);
        printf("Posicao %d (tamanho %d): ", i, tam);

        if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
        {
            printf("vazia\n");
        }
        else
        {
        
            int vetorAux[qtd];
            getDadosEstruturaAuxiliar(i, vetorAux);
            for (j = 0; j < qtd; j++)
                printf("%d ", vetorAux[j]);
            printf("\n");
        }
    }
}

void opcaoListarOrdenadasPorEstrutura()
{
    int i, j, tam, qtd;

    for (i = 1; i <= 10; i++)
    {
        tam = getTamanhoEstruturaAuxiliar(i);
        if (tam == SEM_ESTRUTURA_AUXILIAR)
        {
            printf("Posicao %d: sem estrutura auxiliar\n", i);
            continue;
        }

        qtd = getQuantidadeElementosEstruturaAuxiliar(i);
        printf("Posicao %d (tamanho %d): ", i, tam);

        if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
        {
            printf("vazia\n");
        }
        else
        {
            int vetorAux[qtd];
            getDadosOrdenadosEstruturaAuxiliar(i, vetorAux);
            for (j = 0; j < qtd; j++)
                printf("%d ", vetorAux[j]);
            printf("\n");
        }
    }
}

void opcaoListarTodosOrdenados()
{
    int i, total = contarTotalElementos();

    if (total == 0)
    {
        printf("Todas as estruturas auxiliares estao vazias.\n");
        return;
    }

    int vetorAux[total];
    if (getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux) == SUCESSO)
    {
        for (i = 0; i < total; i++)
            printf("%d ", vetorAux[i]);
        printf("\n");
    }
}

void opcaoExcluir()
{
    int posicao, valor, ret;

    printf("Posicao (1..10): ");
    scanf("%d", &posicao);
    printf("Numero a excluir: ");
    scanf("%d", &valor);

    ret = excluirNumeroEspecificoDeEstrutura(posicao, valor);

    if (ret == SUCESSO)
        printf("Numero excluido com sucesso.\n");
    else if (ret == POSICAO_INVALIDA)
        printf("Posicao invalida.\n");
    else if (ret == SEM_ESTRUTURA_AUXILIAR)
        printf("Nao existe estrutura auxiliar nessa posicao.\n");
    else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
        printf("A estrutura auxiliar esta vazia.\n");
    else if (ret == NUMERO_INEXISTENTE)
        printf("Numero nao encontrado nessa estrutura.\n");
}

void opcaoAumentar()
{
    int posicao, extra, ret;

    printf("Posicao (1..10): ");
    scanf("%d", &posicao);
    printf("Quantas posicoes extras? ");
    scanf("%d", &extra);

    ret = modificarTamanhoEstruturaAuxiliar(posicao, extra);

    if (ret == SUCESSO)
        printf("Tamanho alterado. Novo tamanho: %d\n", getTamanhoEstruturaAuxiliar(posicao));
    else if (ret == POSICAO_INVALIDA)
        printf("Posicao invalida.\n");
    else if (ret == SEM_ESTRUTURA_AUXILIAR)
        printf("Nao existe estrutura auxiliar nessa posicao.\n");
    else if (ret == NOVO_TAMANHO_INVALIDO)
        printf("Novo tamanho invalido (o resultado deve ser >= 1).\n");
    else if (ret == SEM_ESPACO_DE_MEMORIA)
        printf("Sem espaco de memoria.\n");
}

int main()
{
    int op;
    int sair = 0;

    inicializar();

    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 1:
            opcaoInserir();
            break;
        case 2:
            opcaoListarTodas();
            break;
        case 3:
            opcaoListarOrdenadasPorEstrutura();
            break;
        case 4:
            opcaoListarTodosOrdenados();
            break;
        case 5:
            opcaoExcluir();
            break;
        case 6:
            opcaoAumentar();
            break;
        case 7:
            sair = 1;
            finalizar(); // libera toda a memória alocada com malloc/realloc
            break;
        default:
            printf("Opcao invalida\n");
        }
    }

    return 0;
}
