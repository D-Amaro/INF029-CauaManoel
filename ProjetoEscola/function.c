#include <stdio.h>

int valida_data_numeros(int dia, int mes, int ano) {
    
    if (ano <= 0 || mes < 1 || mes > 12 || dia < 1) {
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

int validar_data(char data[]) {
    int dia, mes, ano;
    
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        return 0; 
    
    return valida_data_numeros(dia, mes, ano);
    }
}