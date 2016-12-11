#include <stdio.h>
#include <string.h>
#include "Entidade.h"
#include "Validacoes.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define true 1
#define false 0
#define Max_Detento 200
#define Max_Penas 100

const char FUNCIONARIO[17] = "funcionario.bin";
const char ATIVIDADE[15] = "atividade.bin";
const char FUNCATIVIDADE[19] = "funcAtividade.bin";
const char VISITANTES[15] = "visitantes.bin";
const char VISITAS[15] = "visitas.bin";
const char DETENTOS[15] = "detentos.bin";
const char ENTRADASAIDA[15] = "entradaSaida.bin";
const char PENAS[15] = "penas.bin";




void abrirArquivo(int arquivo, char tipo[], FILE **pf){

     char string[20] = "";

     switch(arquivo){
        case 1:
            strcpy(string, FUNCIONARIO);
            break;
        case 2:
            strcpy(string, ATIVIDADE);
            break;
        case 3:
            strcpy(string, FUNCATIVIDADE);
            break;
        case 4:
            strcpy(string, VISITANTES);
            break;
        case 5:
            strcpy(string, VISITAS);
            break;
        case 6:
            strcpy(string, DETENTOS);
            break;
        case 7:
            strcpy(string, ENTRADASAIDA);
            break;
        case 8:
            strcpy(string, PENAS);
            break;

     }
    if(!(*pf = fopen(string, tipo))){
            printf("Erro!");
            exit(1);
    }else {
        printf("Banco aberto  \n");


}

}

/* CRUD Detento */

int cadastroDetentoCRUD(Detentos den, int enty){

    FILE *pf;
    int a = 0;
    abrirArquivo(enty, "a+b", &pf);

    fseek(pf, 0, SEEK_END);

    if(fwrite(&den, sizeof(Detentos), 1, pf) != 1){
        a = 0;
    }else {
        a = 1;
    }
    fclose(pf);

    return a;

}

void carregaDetentosVetor(int enty, Detentos den[]){

    FILE *pf;
    int indix = 0;
    abrirArquivo(enty, "a+b", &pf);
    fseek(pf, 0, SEEK_SET);
    memset(den, 0, sizeof(Detentos));

    do{
            if(fread(&den[indix], sizeof(Detentos), 1, pf) == 1){
                indix++;
            }


    }while(!feof(pf));

    fclose(pf);

}

void listaDetentoCRUD(Detentos den[]){

    system("cls");
    int result = 0, cont = 0;


    printf("***Lista de Detentos*** \n");


    for(result = 0; result <= 200; result++){
        if(den[result].ativo == true && den[result].preenchido == true){
            printf("ID %d \nNome %s \nData de Nascimento %s \n", den[result].ID, den[result].Nome, den[result].dataNascimento);
            cont++;
        }
    }


    printf("******** A busca retornou %d Detentos ********* \n", cont);

}

int retornaProximoId(int enty, Detentos den[]){

    int result = 0, index;

    for(index = 0; index < Max_Detento; index++){
        if(den[index].preenchido == true){
            result++;
        }else{
            break;
        }
    }

    return result;

}



Detentos retornaDetentoPorNome(char nome[], Detentos denVec[]){


    int index = 0;
    Detentos den;

    for(index = 0; index < 200; index++){
        if(strcmp(denVec[index].Nome, nome) == 0){
                strcpy(den.Nome, denVec[index].Nome);
                strcpy(den.Nome, denVec[index].Nome);
                den.ID = denVec[index].ID;
                strcpy(den.dataNascimento, denVec[index].dataNascimento);
                den.preenchido = true;
                den.ativo = true;
                break;
        }
    }

    return den;

}

int  alteraDetentoCRUD(Detentos den, int id){

    FILE *pf;
    int retorno = 0;
    abrirArquivo(6, "r+b", &pf);


    rewind(pf);



    fseek(pf, (id)*sizeof(Detentos), SEEK_SET);

    if(fwrite(&den, sizeof(Detentos), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;

}

/* CRUD Penas */

void carregaPenasVetor(int enty, Penas pen[]){

    FILE *pf;
    int indix = 0;
    abrirArquivo(enty, "a+b", &pf);
    fseek(pf, 0, SEEK_SET);
    memset(pen, 0, sizeof(Detentos));

    do{
            if(fread(&pen[indix], sizeof(Penas), 1, pf) == 1){
                indix++;
            }


    }while(!feof(pf));

    fclose(pf);

}

int retornaProximoIdPenas(Penas pen[]){

    int result = 0, index;

    for(index = 0; index < Max_Penas; index++){
        if(pen[result].preenchido == true){
            result++;
        }else{
            break;
        }
    }

    return result;

}

Penas retornaPenaDetento(int ID, Penas penVec[]){
    int index = 0;
    Penas pen;

    for(index; index <= Max_Penas; index++){
        if(penVec[index].ID == ID){
            strcpy(pen.descricao, penVec[index].descricao);
            strcpy(pen.Regiume, penVec[index].Regiume);
            pen.grau = penVec[index].grau;
            pen.ID = penVec[index].ID;
        }
    }

    return pen;
}

int cadastraPenasCRUD(Penas pen, int enty){
    FILE *pf;
    int retorno = 0;
    abrirArquivo(enty, "a+b", &pf);

    fseek(pf, 0, SEEK_END);

    if(fwrite(&pen, sizeof(Penas), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;
}

void listaPenasCRUD(Penas pen[]){

    system("cls");
    int result = 0, cont = 0;


    printf("***Lista de Penas*** \n");


    for(result = 0; result <= 200; result++){
        if(pen[result].preenchido == true){
            printf("ID da Pena: %d \nDescrição: %s \nRegime: %s \nGrau: %d \n", pen[result].ID, pen[result].descricao, pen[result].Regiume, pen[result].grau);
            cont++;
        }
    }


    printf("******** A busca retornou %d Detentos ********* \n", cont);

}


int  alteraPenasCRUD(Penas pen, int id){

    FILE *pf;
    int retorno = 0;
    abrirArquivo(8, "r+b", &pf);


    rewind(pf);



    fseek(pf, (id)*sizeof(Penas), SEEK_SET);

    if(fwrite(&pen, sizeof(Penas), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;

}
int cadastroFuncCRUD(Funcionario func, int enty){

    int a = 0;
    abrirArquivo(enty, "a+b");

    fseek(pf, 0, SEEK_END);

    if(fwrite(&func, sizeof(Funcionario), 1, pf) != 1){
        a = 0;
    }else {
        a = 1;
    }
    fclose(pf);

    return a;

}

void carregaFuncVetor(int enty, Funcionario func[]){

    int indix = 0;
    abrirArquivo(enty, "a+b");
    fseek(pf, 0, SEEK_SET);
    memset(func, 0, sizeof(Funcionario));

    do{
            if(fread(&func[indix], sizeof(Funcionario), 1, pf) == 1){
                indix++;
            }


    }while(!feof(pf));

    fclose(pf);

}

