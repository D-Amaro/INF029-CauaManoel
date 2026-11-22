#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

typedef struct
{
    int *dados;
    int tamanho;
    int qtd;
} EstruturaAux;

EstruturaAux vetorPrincipal[TAM];

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

void ordenar(int v[], int n)
{
    int i, j, chave;
    for (i = 1; i < n; i++)
    {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;

    

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].dados != NULL)
    {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }
    else if (tamanho < 1)
    {
        retorno = TAMANHO_INVALIDO;
    }
    else
    {
        int *novo = (int *)malloc(tamanho * sizeof(int));
        if (novo == NULL)
        {
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
        else
        {
            vetorPrincipal[posicao - 1].dados = novo;
            vetorPrincipal[posicao - 1].tamanho = tamanho;
            vetorPrincipal[posicao - 1].qtd = 0;
            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        EstruturaAux *aux = &vetorPrincipal[posicao - 1];
        if (aux->dados != NULL)
        {
            if (aux->qtd < aux->tamanho)
            {
                aux->dados[aux->qtd] = valor;
                aux->qtd++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if (vetorPrincipal[posicao - 1].qtd == 0)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    else
    {
        
        vetorPrincipal[posicao - 1].qtd--;
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if (vetorPrincipal[posicao - 1].qtd == 0)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    else
    {
        EstruturaAux *aux = &vetorPrincipal[posicao - 1];
        int i, achou = -1;

        for (i = 0; i < aux->qtd && achou == -1; i++)
        {
            if (aux->dados[i] == valor)
                achou = i;
        }

        if (achou == -1)
        {
            retorno = NUMERO_INEXISTENTE;
        }
        else
        {
            
            for (i = achou; i < aux->qtd - 1; i++)
            {
                aux->dados[i] = aux->dados[i + 1];
            }
            aux->qtd--;
            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        int i;
        for (i = 0; i < vetorPrincipal[posicao - 1].qtd; i++)
        {
            vetorAux[i] = vetorPrincipal[posicao - 1].dados[i];
        }
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

    if (retorno == SUCESSO)
    {
        ordenar(vetorAux, vetorPrincipal[posicao - 1].qtd);
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int i, j, k = 0;

    
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < vetorPrincipal[i].qtd; j++)
        {
            vetorAux[k] = vetorPrincipal[i].dados[j];
            k++;
        }
    }

    if (k == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if (retorno == SUCESSO)
    {
        int i, total = 0;
        for (i = 0; i < TAM; i++)
            total += vetorPrincipal[i].qtd;

        ordenar(vetorAux, total);
    }

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        EstruturaAux *aux = &vetorPrincipal[posicao - 1];

        
        int resultante = aux->tamanho + novoTamanho;

        if (resultante < 1)
        {
            retorno = NOVO_TAMANHO_INVALIDO;
        }
        else
        {
            
            int *temp = (int *)realloc(aux->dados, resultante * sizeof(int));
            if (temp == NULL)
            {
                retorno = SEM_ESPACO_DE_MEMORIA;
            }
            else
            {
                aux->dados = temp;
                aux->tamanho = resultante;
                if (aux->qtd > aux->tamanho)
                    aux->qtd = aux->tamanho;
                retorno = SUCESSO;
            }
        }
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if (vetorPrincipal[posicao - 1].qtd == 0)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    else
    {
        retorno = vetorPrincipal[posicao - 1].qtd;
    }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    int i, j, total = 0;
    No *inicio = NULL;
    No *ultimo = NULL;

    for (i = 0; i < TAM; i++)
        total += vetorPrincipal[i].qtd;
    if (total == 0)
        return NULL;

    
    inicio = (No *)malloc(sizeof(No));
    if (inicio == NULL)
        return NULL;
    inicio->prox = NULL;
    ultimo = inicio;

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < vetorPrincipal[i].qtd; j++)
        {
            No *novo = (No *)malloc(sizeof(No));
            if (novo == NULL)
            {
                destruirListaEncadeadaComCabecote(&inicio);
                return NULL;
            }
            novo->conteudo = vetorPrincipal[i].dados[j];
            novo->prox = NULL;
            ultimo->prox = novo;
            ultimo = novo;
        }
    }

    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int k = 0;
    No *atual;

    if (inicio == NULL)
        return;

    for (atual = inicio->prox; atual != NULL; atual = atual->prox)
    {
        vetorAux[k] = atual->conteudo;
        k++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    
    No *atual = *inicio;
    No *proximo;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}

int getTamanhoEstruturaAuxiliar(int posicao)
{
    int retorno = 0;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        retorno = vetorPrincipal[posicao - 1].tamanho;
    }

    return retorno;
}

void dobrar(int *x)
{
    *x = (*x) * 2;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    int i;
    
    for (i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].dados = NULL;
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].qtd = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].dados != NULL)
        {
            free(vetorPrincipal[i].dados);
            vetorPrincipal[i].dados = NULL;
            vetorPrincipal[i].tamanho = 0;
            vetorPrincipal[i].qtd = 0;
        }
    }
}
