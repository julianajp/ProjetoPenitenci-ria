#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"
#include "Validacoes.h"
#include "Negocio.h"
#include "CRUD.h"
#include "Menu.h"
#include <locale.h>
#include <time.h>


int main()
{
    setlocale(LC_ALL, "Portuguese");

    int a = 0;

    Detentos *den;
    Penas *pen;

    den = malloc(sizeof(Detentos)*250);
    pen = malloc(sizeof(Penas)*100);

    carregaDetentosVetor(6, den);
    carregaPenasVetor(8, pen);

    while (a != 2){

        printf("\n***** Penitenciária ***** \n \n");
        printf("1 - Menu Inicial \n2 - Sair  \n");
        fflush(stdin);
        scanf("%d", &a);
        switch(a){

        case 1:
            menuCadastros(den, pen);
            break;
        case 2:
            printf("Sistema off \n");
            break;
        default:
            printf("Digite um número correto \n");

        }
    }
    system("pause");


    return 0;
}

