#include <stdio.h>
#include <string.h>
#include "Entidade.h"
#include "CRUD.h"
#include "Validacoes.h"
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0
#define Max_Detento 200;


void cadastroDetento(Detentos denVec[]){
    Detentos den;


    time_t agora;
    char dataEntrada[50];
    agora = time(NULL);
    strftime( dataEntrada, sizeof(dataEntrada), "%d/%m/%Y", localtime( &agora ) );

    printf("Digite o nome do Detento \n");
    fflush(stdin);
    gets(den.Nome);

    den.ID = retornaProximoId(6, denVec);

    strcpy(den.dataNascimento, dataEntrada);

    den.ativo = true;



    if(validaString(den.Nome)){

        den.preenchido = true;

        if(!verificaDetentoExiste(den.Nome, denVec)){
                if(cadastroDetentoCRUD(den, 6)){
                    printf("Cadastro Realizado com Sucesso! \n");
                    strcpy(denVec[den.ID].Nome, den.Nome);
                    denVec[den.ID].ID = den.ID;
                    strcpy(denVec[den.ID].dataNascimento, den.dataNascimento);
                    denVec[den.ID].preenchido = true;
                    denVec[den.ID].ativo = true;
                }else{
                    printf("Cadastro não realizado! \n");
                }

         }else {

             printf("Detento %s já cadastrado \n", den.Nome);

         }

    }else{
        printf("Favor digitar Nome \n");
    }
}

void listaDetentos(Detentos denVec[]){

    listaDetentoCRUD(denVec);
}

void alteraDetento(Detentos denVec[]){

    system("cls");
    char nome[50];
    Detentos den, denBusca;
    printf("******Altera Detento******* \n");

    printf("Digite o nome do cntato a ser alterado  \n");
    fflush(stdin);
    gets(nome);

    if(verificaDetentoExiste(nome, denVec)){


        printf("Digite o novo nome do Detento \n");
        fflush(stdin);
        gets(den.Nome);
        denBusca = retornaDetentoPorNome(nome, denVec);

        if(denBusca.ativo == false){
            printf("Detento nao existe \n");
        }else{
            strcpy(den.dataNascimento, denBusca.dataNascimento);
            den.ID = denBusca.ID;
            den.ativo = true;
            den.preenchido = true;

            if(alteraDetentoCRUD(den, denBusca.ID)){
                printf("Detento %s Alteado! \n", den.Nome);

            }else{
                printf("Erro na alteracao! \n");
            }

        }



    }else{
        printf("Detento nao existe \n");
    }

}

void excluiDetento(Detentos denVect[]){

    system("cls");
    char nome[50];
    Detentos den;

    printf("****Exclui Detento**** \n");

    listaDetentos(denVect);

    printf("Digite O Nome do detento a ser excluido \n");
    fflush(stdin);
    gets(nome);

    system("cls");
    printf("****Exclui Detento**** \n");

    if(validaString(nome)){
        if(verificaDetentoExiste(nome, denVect)){
                den = retornaDetentoPorNome(nome, denVect);
                printf("Detento %s , ID %d \n", den.Nome, den.ID);
                den.ativo = false;

                if(alteraDetentoCRUD(den,den.ID)){
                    denVect[den.ID].ativo = false;
                    printf("O Detento %s Foi excluido do Sistema! \n", nome);
                }else{
                    printf("Erro! Não foi possivel excluir detento! \n");
                }

        }else{
            printf("Este detento não existe no nosso registro! \n");

        }
    }else{
        printf("Erro! Nome não digitado! \n");
    }
}
