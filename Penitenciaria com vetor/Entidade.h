#ifndef ENTIDADE_H_INCLUDED
#define ENTIDADE_H_INCLUDED



typedef struct funcionario{

int ID;
char nome[80];
int idade;
char datadenascimento[30];
char nomedamae[80];
int cargo;
int Senha;
long int loginCPF;
int telefone;
char Rg[15];
char CPF[19];
int Preenchido;
int Ativo;

} Funcionario;

typedef struct atividade{

char descricao[40];
int ID;
int avaliacao;
float remuneracao;
int preenchido;
int ativo;

} Atividade;



typedef struct funcAtividade{

int IDdetenti;
int IDatividade;
char dataAtividade[20];

} FuncAtividade;

typedef struct visitantes{

int ID;
char Nome[80];
char CPF[20];
char dataNascimento[20];
char profissao[20];
char escolaridade[25];
int preenchido;
int ativo;

} Visitantes;

typedef struct visitas{

int IDdetento;
int IDpreso;
char dataVisita[20];
int salaVisista;


} Visitas;


typedef struct detentos{

int ID;
char Nome[80];
char dataNascimento[20];
char dataEntrada[20];
char dataSaida[20];
char nomeMae[80];
char escolaridade[50];
int numeroAla;
int telefone;
float avaliacao;
char pena[20];
int preenchido;
int ativo;
char Profissao[30];
int numeroQuarto;


} Detentos;

typedef struct entradaSaida{

int tipoSaida; /* 1 detento e 2 visita*/
char dataSaida[20];
char dataVolta[20];
int entrada; /*Para verificar se está dentro na penetenciária*/
int IDdetento;
int IDvisitante;


} EntradaSaida;
#endif // ENTIDADE_H_INCLUDED
