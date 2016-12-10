#ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED

void abrirArquivo(int arquivo, char tipo[], FILE **pf);
int cadastroDetentoCRUD(Detentos den, int enty);
void carregaDetentosVetor(int enty, Detentos den[]);
void listaDetentoCRUD(Detentos den[]);
int retornaProximoId(int enty, Detentos den[]);
Detentos retornaDetentoPorNome(char nome[], Detentos denVec[]);
int alteraDetentoCRUD(Detentos den, int id);

void carregaPenasVetor(int enty, Penas pen[]);
int retornaProximoIdPenas(Penas pen[]);
Penas retornaPenaDetento(int ID, Penas penVec[]);
int cadastraPenasCRUD(Penas pen, int enty);
void listaPenasCRUD(Penas pen[]);
int  alteraPenasCRUD(Penas pen, int id);
#endif // CRUD_H_INCLUDED
