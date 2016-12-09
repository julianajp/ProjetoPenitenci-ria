#include <stdio.h>
#include <string.h>
#include "Entidade.h"
#include <stdlib.h>
#define true 1
#define false 0
#include <time.h>
#define MAX_Detentos 200



int validaString(char String[]){
    int a = 0;
    if(strcmp(String, "") != 0){
        a = 1;
    }
    return a;
}

int validaIntPositivo(int numero){
    int a = 0;

    if(numero > 0){
        a = 1;
    }
    return a;
}

void limpaVetor(char string[]){
    strcpy(string, "");
}

int retornarIDaleatorio(){

srand(time(NULL));

int rando = rand()%200;

return rando;

}

int verificaDetentoExiste(char stringN[], Detentos denVec[]){

    int index, result = 0;

        for(index = 0; index <= MAX_Detentos; index++){
           if(strcmp(denVec[index].Nome, stringN) == 0){
                result = 1;
                break;
            }
        }

        return result;
}



