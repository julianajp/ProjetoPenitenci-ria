#ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED

void abrirArquivo(int arquivo, char tipo[]);
int cadastroDetentoCRUD(Detentos den, int enty);
void carregaDetentosVetor(int enty, Detentos den[]);
void listaDetentoCRUD(Detentos den[]);
int retornaProximoId(int enty, Detentos den[]);
Detentos retornaDetentoPorNome(char nome[], Detentos denVec[]);
int alteraDetentoCRUD(Detentos den, int id);
#endif // CRUD_H_INCLUDED
