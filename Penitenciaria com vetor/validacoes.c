#include <stdio.h>
#include <string.h>
#include "Entidade.h"
#include <stdlib.h>
#define true 1
#define false 0
#include <time.h>
#define MAX_Detentos 200
#define Max_Penas 100



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

int verificaDetentoExisteCPF(long int CPF, Detentos denVec[], int atual){

    int index, result = 0;

        for(index = 0; index <= MAX_Detentos; index++){
           if(CPF == denVec[index].loginCPF){
                if(index == atual){
                    result = 0;
                }else{
                    result = 1;
                }

                break;
            }
        }

        return result;
}

int verificaDetentoExisteCPFcdt(long int CPF, Detentos denVec[]){

    int index, result = 0;

        for(index = 0; index <= MAX_Detentos; index++){
           if(CPF == denVec[index].loginCPF){
                result = 1;
                break;
            }
        }

        return result;
}


void copiaDetentoParaVetor(Detentos den, Detentos denVec[]){

    int ID = den.ID;

    strcpy(denVec[ID].Nome, den.Nome);
    denVec[ID].ID = den.ID;
    strcpy(denVec[ID].dataNascimento, den.dataNascimento);
    strcpy(denVec[ID].dataSaida, den.dataSaida);
    strcpy(denVec[ID].dataEntrada, den.dataEntrada);
    strcpy(denVec[ID].nomeMae, den.nomeMae);
    strcpy(denVec[ID].escolaridade, den.escolaridade);
    denVec[ID].numeroAla = den.numeroAla;
    denVec[ID].telefone = den.telefone;
    denVec[ID].pena = den.pena;
    denVec[ID].ativo = den.ativo;
    denVec[ID].preenchido = den.preenchido;
    strcpy(denVec[ID].Profissao, den.Profissao);
    denVec[ID].numeroQuarto = den.numeroQuarto;
    denVec[ID].loginCPF = den.loginCPF;

}

int verificaPenaExiste(int IDpena, Penas penVec[]){

    int index, result = 0;

        for(index = 0; index <= Max_Penas; index++){
           if(penVec[index].ID ==  IDpena){
                result = 1;
                break;
            }
        }

        return result;
}

int verificaDecsPenaExiste(char stringP[], Penas penVec[]){

    int index, result = 0;

        for(index = 0; index <= Max_Penas; index++){
           if(strcmp(penVec[index].descricao, stringP) == 0){
                result = 1;
                break;
            }
        }

        return result;
}

void copiaPenaParaVetor(Penas pen, Penas penVec[]){

    int ID = pen.ID;

    strcpy(penVec[ID].descricao, pen.descricao);
    penVec[ID].ID = pen.ID;
    strcpy(penVec[ID].Regiume, pen.Regiume);
    penVec[ID].grau = pen.grau;
    penVec[ID].preenchido = pen.preenchido;

}
int verificaFuncExiste(char stringN[], Funcionario funcVec[]){

    int index, result = 0;

        for(index = 0; index <= MAX_Func; index++){
           if(strcmp(funcVec[index].nome, stringN) == 0){
                result = 1;
                break;
            }
        }

        return result;
}

