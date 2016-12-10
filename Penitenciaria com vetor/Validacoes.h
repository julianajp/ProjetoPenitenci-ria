#ifndef VALIDACOES_H_INCLUDED
#define VALIDACOES_H_INCLUDED



int validaString(char String[]);
int validaIntPositivo(int numero);
void limpaVetor(char String[]);
int retornarIDaleatorio();
int verificaDetentoExiste(char stringN[], Detentos denVec[]);
void copiaDetentoParaVetor(Detentos den, Detentos denVec[]);
int verificaDetentoExisteCPF(long int CPF, Detentos denVec[], int atual);
int verificaDetentoExisteCPFcdt(long int CPF, Detentos denVec[]);


#endif // VALIDACOES_H_INCLUDED
