#include <stdio.h>
#include <string.h>
#include <estruturas.h>

int compararData(DataNascimento data1, DataNascimento data2) {

    if (data1.ano != data2.ano)
        return data1.ano > data2.ano;

    if (data1.mes != data2.mes)
        return data1.mes > data2.mes;

    return data1.dia > data2.dia;
}

int cpfvalido(char cpf[]) {
    int len = strlen(cpf);
    if (len != 11 ) 
        return 0;
    for (int i = 0; i < len; i++) {
        if (cpf[i] < '0' || cpf[i] > '9' )
        return 0;
    }
    return 1;

}

int valida_data_numeros(int dia, int mes, int ano) {
    
    if (ano < 1900 || mes < 1 || mes > 12 || dia < 1) {
        return 0;
    }

    int dias_no_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        dias_no_mes[1] = 29; // Atualiza fevereiro
    }

    if (dia > dias_no_mes[mes - 1]) {
        return 0; // Inválido (ex: 31 no mês 4)
    }

    return 1; 
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerQuebraLinha(char s[]) {
    size_t ln = strlen(s);
    if (ln > 0 && s[ln - 1] == '\n')
        s[ln - 1] = '\0';
}
