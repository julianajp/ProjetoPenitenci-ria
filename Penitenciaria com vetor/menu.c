#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"
#include "Validacoes.h"
#include "Negocio.h"
#include "CRUD.h"
#include <locale.h>
#include <time.h>


void menuCadastros(Detentos denVec[], Penas penVec[]){

    int controle = 0;

    do{
    printf("\n***** Menu de Cadastros ****** \n");
    printf("Digite \n1 - Cadastro Detento \n2 - Cadastro Pena \n3 - Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

    switch(controle){
        case 1:
            menuCadastroDetento(denVec);
            break;
        case 2:
            menuCadastroPena(penVec);
            break;
        default:
            printf("Digite uma opção válida \n");
            break;
    }

    }while(controle != 3);
}

void menuCadastroDetento(Detentos denVec[]){

    int controle = 0;

    while(controle != 5){
    printf("\n***** Menu de Cadastros Detento ****** \n");
    printf("Digite 1 - Cadastra Detento \n2 - Lista Detento \n3 - Altera Detento \n4 - Exclui Detento \n5 - Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastroDetento(denVec);
                break;
            case 2:
                listaDetentos(denVec);
                break;
            case 3:
                alteraDetento(denVec);
                carregaDetentosVetor(6, denVec);
                break;
            case 4:
                excluiDetento(denVec);
                break;
            case 5:
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}


void menuCadastroPena(Penas penVec[]){

    int controle = 0;

    while(controle != 4){
    printf("\n***** Menu de Cadastros Penas ****** \n");
    printf("Digite 1 - Cadastra Pena \n2 - Lista Pena \n3 - Altera Pena \n4 - Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastroPena(penVec);
                break;
            case 2:
                listaPenas(penVec);
                break;
            case 3:
                alteraPena(penVec);
                carregaPenasVetor(8, penVec);
                break;
            case 4:
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}
