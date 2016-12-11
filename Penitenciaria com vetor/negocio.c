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

    system("cls");
    printf("******* Cadastro Detento ******* \n");
    printf("Os Campos com * devem ser preenchido obrigatóriamente \n");

    printf("Digite o nome do Detento *\n");
    fflush(stdin);
    gets(den.Nome);

    den.ID = retornaProximoId(6, denVec);

    printf("Digite a Data de Nascimento ex: dd/mm/aa \n");
    fflush(stdin);
    gets(den.dataNascimento);

    strcpy(den.dataEntrada, dataEntrada);

    printf("Digite a Data de Saida ex: dd/mm/aa *\n");
    fflush(stdin);
    gets(den.dataSaida);

    printf("Digite o nome da mãe *\n");
    fflush(stdin);
    gets(den.nomeMae);

    printf("Digite sua escolaridade \n");
    fflush(stdin);
    gets(den.escolaridade);

    printf("Digite o número da Ala *\n");
    scanf("%d", &den.numeroAla);

    printf("Digite o número de Telefone \n");
    scanf("%d", &den.telefone);

    printf("Digite a Pena *\n");
    scanf("%d", &den.pena);

    den.ativo = true;

    printf("Digite a profissão \n");
    fflush(stdin);
    gets(den.Profissao);

    printf("Digite o número do quarto *\n");
    scanf("%d", &den.numeroQuarto);

    printf("Digite o número do CPF *\n");
    scanf("%ld", &den.loginCPF);

    if(validaString(den.Nome) && validaIntPositivo(den.loginCPF)){

        den.preenchido = true;

        if(!verificaDetentoExiste(den.Nome, denVec) && (!verificaDetentoExisteCPFcdt(den.loginCPF, denVec))){
                if(cadastroDetentoCRUD(den, 6)){
                    printf("Cadastro Realizado com Sucesso! \n");
                    copiaDetentoParaVetor(den, denVec);
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

    listaDetentos(denVec);

    printf("\n\nDigite o nome do cntato a ser alterado  \n");
    fflush(stdin);
    gets(nome);

    if(verificaDetentoExiste(nome, denVec)){

            printf("Digite o novo nome do Detento \n");
            fflush(stdin);
            gets(den.Nome);
            if(!verificaDetentoExiste(den.Nome, denVec)){
                denBusca = retornaDetentoPorNome(nome, denVec);

                if(denBusca.ativo == false){
                    printf("Detento nao existe \n");
                }else{

                    den.ID = denBusca.ID;
                    printf("Digite a Data de Nascimento ex: dd/mm/aa \n");
                    fflush(stdin);
                    gets(den.dataNascimento);

                    printf("Digite a Data de entrada \n");
                    fflush(stdin);
                    gets(den.dataEntrada);


                    printf("Digite a Data de Saida ex: dd/mm/aa *\n");
                    fflush(stdin);
                    gets(den.dataSaida);

                    printf("Digite o nome da mãe *\n");
                    fflush(stdin);
                    gets(den.nomeMae);

                    printf("Digite sua escolaridade \n");
                    fflush(stdin);
                    gets(den.escolaridade);

                    printf("Digite o número da Ala *\n");
                    scanf("%d", &den.numeroAla);

                    printf("Digite o número de Telefone \n");
                    scanf("%d", &den.telefone);

                    printf("Digite a Pena *\n");
                    scanf("%d", &den.pena);

                    den.ativo = true;

                    printf("Digite a profissão \n");
                    fflush(stdin);
                    gets(den.Profissao);

                    printf("Digite o número do quarto *\n");
                    scanf("%d", &den.numeroQuarto);

                    printf("Digite o número do CPF *\n");
                    scanf("%ld", &den.loginCPF);

                    den.ativo = true;
                    den.preenchido = true;

                    if(validaIntPositivo(den.loginCPF) && validaString(den.Nome)){
                            if(!verificaDetentoExisteCPF(den.loginCPF, denVec, den.ID)){
                               if(alteraDetentoCRUD(den, denBusca.ID)){
                                printf("Detento %s Alteado! \n", den.Nome);
                                copiaDetentoParaVetor(den, denVec);

                                }else{
                                    printf("Erro na alteracao! \n");
                                }
                            }else{
                                printf("Erro! CPF pertence a outro Detento \n");
                            }

                    }else{
                        printf("Dados não foram preenchidos corretamente! \n");
                    }
                }

            }else{
                printf("Erro! O Detento %s já cadastrado no Sistema, tentar novamente com outro Nome\n", den.Nome);
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


void cadastroPena(Penas penvec[]){

    Penas pen;
    system("cls");
    printf("**** Cadastro de Penas***** \n");

    printf("Digite a descrição da Pena \n");
    fflush(stdin);
    gets(pen.descricao);

    printf("Digite o Regime da Pena \n");
    fflush(stdin);
    gets(pen.Regiume);

    printf("Digite o grau da Pena \n");
    fflush(stdin);
    scanf("%d", &pen.grau);

    pen.ID = retornaProximoIdPenas(penvec);

    if(validaString(pen.descricao) && validaString(pen.Regiume) && validaIntPositivo(pen.grau)){
            pen.preenchido = true;
            if(!verificaDecsPenaExiste(pen.descricao, penvec)){
                if(cadastraPenasCRUD(pen, 8)){
                        printf("Pena Cadastrada! \n");
                        copiaPenaParaVetor(pen, penvec);
                }else{
                    printf("Erro! Pena Não cadastrada \n");
                }
            }else{
                printf("Erro! Não é possível cadastrar essa pena, pois ela já foi cadastrada \n");
            }

    }else{
        printf("Favor, preencher todos os dados corretamente \n");
    }
}

void listaPenas(Penas penVec[]){
    listaPenasCRUD(penVec);
}


void alteraPena(Penas penVec[]){

    system("cls");

    char descricao[50];
    int ID;
    Penas pen, penBusca;

    printf("****** Alteração de Pena *******");

    listaPenas(penVec);

    printf("Digite o ID do Contato a ser Alterado \n");
    scanf("%d", &ID);

    if(verificaPenaExiste(ID, penVec)){

            printf("Digite o Novo nome para descrição \n");
            fflush(stdin);
            gets(pen.descricao);

            if(!verificaDecsPenaExiste(pen.descricao, penVec)){
                  penBusca = retornaPenaDetento(ID, penVec);

                  printf("Digite o Grau \n");
                  scanf("%d", &pen.grau);
                  pen.ID = penBusca.ID;
                  printf("%d %d", penBusca.ID, penBusca.preenchido);

                  if(validaString(pen.descricao), validaIntPositivo(pen.grau)){
                        pen.preenchido = penBusca.preenchido;
                        if(alteraPenasCRUD(pen, penBusca.ID)){
                            printf("A Pena %s Foi Alterada com Sucesso!",  pen.descricao);
                            copiaPenaParaVetor(pen, penVec);
                        }else{
                            printf("Erro! Pena não Alterada!");
                        }
                  }else{
                      printf("Erro! Digite os campos corretamente! \n");
                  }

            }else{
                printf("Erro! Nome já cadastrado, tente como outro! \n");
            }

    }else{
        printf("Erro! Esta Pena Não existe \n");
    }
}

void cadastroFunc(Funcionario funcVec[]){
    Funcionario func;



    printf("Digite o nome do funcionario \n");
    fflush(stdin);
    gets(func.nome);

    printf("Digite o cargo do funcionario 1. Adm 2. \n");
    fflush(stdin);
    gets(func.cargo);

    printf("Digite o CPF do funcionario");
    fflush(stdin);
    gets(func.loginCPF);

    printf("Digite a data de nascimento do funcionario");
    fflush(stdin);
    gets(func.datadenascimento);

    printf("Digite a idade do funcionario");
    fflush(stdin);
    gets(func.idade);

    printf("Mãe");
    fflush(stdin);
    gets(func.nomedamae);

    printf("Digite o Rg do funcionario");
    fflush(stdin);
    gets(func.Rg);

    switch(cargo){
        case 1:
            printf("Digite a senha do funcionario");
            fflush(stdin);
            gets(func.senha);
            break;

        default:
            break;

    }



    func.ID = retornaProximoId(1, funcVec);



    func.ativo = true;



    if(validaString(func.nome)){

        func.preenchido = true;

        if(!verificaFuncExiste(func.nome, funcVec)){
                if(cadastroFuncCRUD(func, 1)){
                    printf("Cadastro Realizado com Sucesso! \n");
                    strcpy(funcVec[func.ID].nome, func.nome);
                    funcVec[func.ID].ID = func.ID;
                    strcpy(funcVec[func.ID].loginCPF, func.loginCPF);
                    strcpy(funcVec[func.ID].Rg, func.Rg);
                    strcpy(funcVec[func.ID].datadenascimento, func.datadenascimento);
                    strcpy(funcVec[func.ID].Senha, func.Senha);
                    strcpy(funcVec[func.ID].nomedamae, func.nomedamae);
                    funcVec[func.ID].preenchido = true;
                    funcVec[func.ID].ativo = true;
                }else{
                    printf("Cadastro não realizado! \n");
                }

         }else {

             printf("Funcionario %s já cadastrado \n", func.nome);

         }

    }else{
        printf("Favor digitar Nome \n");
    }
}
void Login(){

    Funcionario func1;
    int i = 0;
    long int senhaconf;
    int matconf;

do{



        printf("Login");
        scanf("%d", &matconf);
        printf("Senha");
        scanf("%ld", &senha);

        if(fread(&func1.cargo, sizeof(int), 1, pf) == 1){

            if(&func1.cargo == 1){

                fread(&func1.loginCPF,sizeof(int), 1, pf);
                fread(&func1.&func.Senha,sizeof(long),1, pf);

                if(&func1.loginCPF == matconf && &func.Senha == senhaconf){

                        printf("Bem Vindo");
                        i == 1;
                    }else{
                        printf("Digite seus dados novamente");
                    }

                else{
                    printf("Funcionário não autorizado");

                }
                }

            }
        }while(i == 1)
    }





void agendaVisita(){

Visitantes vis1;
Visitas vis;
char nome[80],nome1[100];
int opc = 1;



do{
printf("Digite nome");
gets(nome);

if(fread(&vis1, sizeof(struct Visitantes), 1, pf)== 1){

    if(strcmp(vis1.Nome, nome) == 0){
        print("Insira nome do detento");
        gets(nome1);

        if(verificaDetentoExiste(nome1, denVec) == 1){

        print("Insira data");
        scanf("%d", dataVisita);
        abrirArquivo(5, vis);

        fwrite(&vis.nomeVis, &vis.nomeDen, &vis.dataVisita, sizeof(Visitas), 1, pf);


        printf("Visita agendada com sucesso! %c %d ", nomeVis, dataVisita );


        break;}

}   else{
    printf("Usuário Inválido");
}
printf("1.Cadastrar novamente 2.Sair ");
scanf("%d", opc);
}
}while(opc = 1)
system('pause');
}
