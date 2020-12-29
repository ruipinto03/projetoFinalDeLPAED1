//
// Created by Rui Pinto on 28/12/2020.
//

#ifndef TESTEAS_FUNCOES_H
#define TESTEAS_FUNCOES_H
#define INITIALSIZE 10
#define MAXBUFF 4096
#define DELIMETER ";"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>
#include "estruturas.h"

int main_teste(int argc, char **argv);

char *newString(int size);

char *toUpper(char *string);

DATA *stringToDate(char *string);

DATA *stringToTimeStamp(char *string);

/*Verificacao*/

int existeAgencia(int id);
int existeCliente(int id);
int existePredio(int id);
int existeEstudio(int id);
int existeEvento(int id);

AGENCIA * retornaAgencia(int id);
CLIENTE * retornaCliente(int id);
PREDIO * retornaPredio(int id);
ESTUDIO * retornaEstudio(int id);
EVENTO * retornaEvento(int id);

/*ALOCACAO DE MEMORIA*/
AGENCIA * novoAgencia(int idAgencia , char * nome);
CLIENTE * novoCliente(int idCliente, char *nome, char *email);
PREDIO * novoPredio(int idPredio, char *rua, char *cidade, double longitude, double latitude);
ESTUDIO * novoEstudio(int idEstudio, int idPredio, int numeroQuartos, int duplex, char *descricao, double precoBase, double metrosQuadrados);
EVENTO * novoEvento(int idEvento, int idCliente, int idEstudio, int idPredio, int idAgencia, DATA *inicio, DATA *fim, double precoDaResreva,
                    char *descricao);
EVENTO * novoEventoCompleto(int idEvento, int idCliente, int idEstudio, int idPredio, int idAgencia, DATA *inicio, DATA *fim,
                            DATA *dataDaReserva, double precoDaReserva, REGRA **arrayDeRegras, int numeroRegras,
                            char *descricao);
PROMOCAO *novoPromocao(int agencia,int idPromocao, int idEstudio,int idPredio, DATA *inicio, DATA *fim ,int numeroMinimoDias,int desconto);
REGRA * novoRegra(int idRegra, char *descricao, double descontoOuInflacao);

DATA * novoData(int dia,int mes,int ano);
DATA * novoTimeStamp();

EVENTO ** novoArrayEvento(int tamanho);
LISTAEVENTO ** novoArrayDeListaEventos(int tamanho);
ESTUDIO **novoEstudioArray(int tamanho);
REGRA **novoRegrasArray(int tamanho);

LISTAAGENCIA * novaListaAgencia();
LISTAESTUDIO * novaListaEstudio();
LISTAPREDIO * novaListaPredio();
LISTACLIENTE * novaListaCliente();
LISTAEVENTO * novaListaEvento();
LISTAPROMOCAO * novaListaPromocao();

/*INSERE*/
void insereNaListaAgencia(LISTAAGENCIA * listaagencia , AGENCIA * agencia);
void insereNaListaCliente(LISTACLIENTE * listacliente , CLIENTE * cliente);
void insereNaListaPredio(LISTAPREDIO * listapredio , PREDIO * predio);
void insereNaListaEstudio(LISTAESTUDIO * listaestudio , ESTUDIO * estudio);
void insereNaListaEvento(LISTAEVENTO * listaevento, EVENTO * evento);

void insereNoArrayEstudios(ESTUDIO * estudio);
void inserePromocaoAgencia(int idAgencia, PROMOCAO * promocao);

/*REMOVE*/
void removeAgencia(int id);
void removeCliente(int id);
void removePredio(int id);
void removeEstudio(int id);
void removeEstudioArrayEstudios(int idPredio, int idEstudio);
void removeEvento(int id);

/*IMPRIME*/
void imprimeAgencia(AGENCIA* agencia);
void imprimeCliente(CLIENTE* cliente);
void imprimePredio(PREDIO* predio);
void imprimeEstudio(ESTUDIO* estudio);
void imprimeEvento(EVENTO* evento);

void imprimeListaAgencia(LISTAAGENCIA* listaagencia);
void imprimeListaCliente(LISTACLIENTE* listacliente);
void imprimeListaPredio(LISTAPREDIO* listapredio);
void imprimeListaEstudio(LISTAESTUDIO* listaestudio);
void imprimeListaEvento(LISTAEVENTO* listaevento);

void imprimeEstudiosDosPredios(LISTAPREDIO * listapredio);
void imprimePromocaoAgencias(AGENCIA* agencia);
void imprimeListaPromocao(LISTAPROMOCAO * agencia);
void imprimeData(DATA* data);

/*EDITAR*/


/*CARREGAR FICHEIROS*/

void carregaDadosAgencia();
void carregaDadosCliente();
void carregaDadosPredio();
void carregaDadosEstudio();
void carregaDadosEvento();
void carregaDadosPromocao();
void carregaTodosDados();

/*GRAVAR DADOS NOS FICHEIROS*/
void gravaDadosAgencia();
void gravaDadosCliente();
void gravaDadosPredio();
void gravaDadosEstudio();
void gravaDadosEvento();

/*MANIPULACAO DE DATAS*/
int compareDates(DATA *inicio, DATA *fim);

int afterDate(DATA *data, DATA *data2);

int differenceYears(DATA *inicio, DATA *fim);

int isLeapYearValidation(int ano);

int isLeapYear(int ano);

int daysMonth(int month, int ano);

int differenceBetweenDays(DATA *inicio, DATA *fim);

void incrementDate(DATA *inicio);

int dayofweek(DATA *inicio);

DATA *nextDay(DATA *inicio);

DATA *beforeDay(DATA *inicio);

int beforeDate(DATA *inicio, DATA *fim);

/*PRECOS*/
double configuracaoEstudio(ESTUDIO *estudio);

double reservaNumeroDeDias(DATA *inicio, DATA *fim);

double epocaDaReserva(DATA *inicio, DATA *fim);

double verificacaoPromocaoAgencia(AGENCIA *agencia, EVENTO *evento);

double antecedencia(DATA *inicio);

void calcularPrecoEmRelacaoAsRegras(EVENTO * evento);
#endif //TESTEAS_FUNCOES_H
