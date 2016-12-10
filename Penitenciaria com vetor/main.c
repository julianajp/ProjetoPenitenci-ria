#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"
#include "Validacoes.h"
#include "Negocio.h"
#include "CRUD.h"
#include <locale.h>
#include <time.h>


int main()
{
    setlocale(LC_ALL, "Portuguese");

    int a = 0;

    Detentos *den;

    den = malloc(sizeof(Detentos)*250);

    carregaDetentosVetor(6, den);

    while (a = 4){

        printf("\n*****Menu***** \n \n");
        printf("1 - Cadastrar \n2 - Listar  \n3 - Alterar \n4 - Excluir \n");
        scanf("%d", &a);
        switch(a){

        case 1:
            cadastroDetento(den);
            break;
        case 2:
            listaDetentos(den);
            break;
        case 3:
            alteraDetento(den);
            carregaDetentosVetor(6, den);
            break;
        case 4:
            excluiDetento(den);
            break;

        }
    }
    system("pause");


    return 0;
}

