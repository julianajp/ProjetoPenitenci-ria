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
 Funcionario func[200];

    carregaFuncVetor(1, func);

    Visitas vis[200];

    while (a = 3){

        printf("\n*****Menu***** \n \n");
        printf("1 - Cadastrar \n2 - Listar  \n3 - Alterar \n4 - Excluir \n");
        scanf("%d", &a);
        switch(a){

        case 1:
            cadastroFunc(func);
            break;
        case 2:
            listaFunc(func);
            break;
        case 3:
            alteraFunc(func);
            carregaFuncVetor(1, func);
            break;
        case 4:
            excluiFunc(func);
            break;

        }
