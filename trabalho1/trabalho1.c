// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Cauã Amaro Manoel
//  email:
//  Matrícula: 20252160004
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <ctype.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int ConversorInteiro(char s[]) {
 
    int resultado = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        resultado = resultado * 10 + (s[i] - '0');
    }
    return resultado;
}

int ehBissexto(int ano) {
    return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0) );
}

int q1(char data[])
{
  int datavalida = 1;
  char sDia[3], sMes[3], sAno[5];
  int dia, mes, ano;
  int i, j = 0, parte = 0;

  for(i = 0; data[i] != '\0'; i++) {
    if (data[i] == '/')
    {
        if (parte == 0)
            sDia[j] = '\0';
        else if (parte == 1)
             sMes[j] = '\0';
        else datavalida = 0;
    parte++;
    j = 0;
    }

    else if (data[i] < '0' || data[i] > '9')
        datavalida = 0;
    else if (parte == 0 && j < 2)
        sDia[j++] = data[i];
    else if(parte == 1 && j < 2)
        sMes[j++] = data[i];
    else if (parte == 2 && j < 4)
        sAno[j++] = data[i];
    else 
        datavalida = 0;
  }

    if (parte == 2)
        sAno[j] = '\0';
    else datavalida = 0;
    if (j != 2 && j != 4)
        datavalida = 0;


  if (datavalida)
{
  dia = ConversorInteiro(sDia);
  mes = ConversorInteiro(sMes);
  ano = ConversorInteiro(sAno);
  if (j == 2) ano += 2000;

 if (mes < 1 || mes > 12)
    datavalida = 0;
  else
  {
    int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int maximo = diasMes[mes - 1];
    if (mes == 2 && ehBissexto(ano)) maximo = 29;
    if (dia < 1 || dia > maximo) datavalida = 0;
  }
}
  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

int diasNoMes(int mes, int ano) {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ehBissexto(ano)) {
        return 29;
    }
    return diasMes[mes - 1];
}


DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }

    DataQuebrada ini = quebraData(datainicial);
    DataQuebrada fim = quebraData(datafinal);

    if (ini.iAno > fim.iAno || 
       (ini.iAno == fim.iAno && ini.iMes > fim.iMes) || 
       (ini.iAno == fim.iAno && ini.iMes == fim.iMes && ini.iDia > fim.iDia)) 
    {
        dma.retorno = 4;
        return dma;
    }

    if (ini.iDia == 29 && ini.iMes == 2 && fim.iDia == 28 && fim.iMes == 2 && !ehBissexto(fim.iAno)) {
        fim.iDia = 29;
    }

    int anos = fim.iAno - ini.iAno;
    int meses = fim.iMes - ini.iMes;
    int dias = fim.iDia - ini.iDia;

    if (dias < 0) {
        meses--; 
        int mesAnterior = fim.iMes - 1;
        int anoAnterior = fim.iAno;
        
        if (mesAnterior == 0) {
            mesAnterior = 12;
            anoAnterior--;
        }
        
        dias += diasNoMes(mesAnterior, anoAnterior);
    }

    if (meses < 0) {
        anos--; 
        meses += 12;
    }

    dma.qtdAnos = anos;
    dma.qtdMeses = meses;
    dma.qtdDias = dias;
    dma.retorno = 1;

    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

for(int i = 0; texto[i] != '\0'; i++) {
    if (isCaseSensitive == 1) {
        if (texto[i] == c)
            qtdOcorrencias++;
        } else {
        if (toupper(texto[i]) == toupper(c))
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{

    int qtdOcorrencias = 0;
    int idxPos = 0;
    int i = 0, j = 0;

    int tamTexto = 0, tamBusca = 0;
    while (strTexto[tamTexto] != '\0') tamTexto++;
    while (strBusca[tamBusca] != '\0') tamBusca++;

    if (tamBusca == 0) return 0;

    for (i = 0; i <= tamTexto - tamBusca; i++) {
        int match = 1;
        
        for (j = 0; j < tamBusca; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                match = 0;
                break;
            }
        }

        if (match == 1) {
            posicoes[idxPos] = i + 1;            
            posicoes[idxPos + 1] = i + tamBusca; 
            idxPos += 2;                          
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int invertido = 0;
    int digito;

    while ( num != 0) {
    
        digito = num % 10;
        resultado = resultado * 10 + digito;
        num = num / 10;

    }

    return resultado;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int divisor = 10;             
    int copia = numerobusca;      

    while (copia >= 10)
    {
        divisor = divisor * 10;
        copia = copia / 10;
    }

 
    while (numerobase > 0)
    {
        if (numerobase % divisor == numerobusca)
        {
            qtdOcorrencias++;                      
            numerobase = numerobase / divisor;  
        }
        else
        {
            numerobase = numerobase / 10;       
        }
    }

    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
{
    int linhas = 8;
    int colunas = 10;
    
    int tamPalavra = 0;
    while (palavra[tamPalavra] != '\0') tamPalavra++;

    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1}; 
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1}; 

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            
            if (matriz[i][j] == palavra[0]) {
                
                for (int dir = 0; dir < 8; dir++) {
                    int k;
                    int novaLinha = i;
                    int novaColuna = j;
                    
                    for (k = 1; k < tamPalavra; k++) {
                        novaLinha += dx[dir];
                        novaColuna += dy[dir];
                        
                        if (novaLinha < 0 || novaLinha >= linhas || novaColuna < 0 || novaColuna >= colunas) {
                            break;
                        }
                        
                        if (matriz[novaLinha][novaColuna] != palavra[k]) {
                            break;
                        }
                    }
                    
                    if (k == tamPalavra) {
                        return 1;
                    }
                }
            }
        }
    }
    
    return 0; 
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
