//
// Created by Rui Pinto on 28/12/2020.
//

#ifndef TESTEAS_ESTRUTURAS_H
#define TESTEAS_ESTRUTURAS_H


typedef struct data{
    int segundos;
    int minutos;
    int horas;
    int dia;
    int mes;
    int ano;
}DATA;
typedef struct regra {
    int idRegra;
    char * descricao;
    double descontoInflacao;
}REGRA;
typedef struct listaRegras {
    int numeroRegras;
    REGRA * primeiraRegra;
}LISTAREGRAS;
typedef struct evento {
    int idEvento;
    int idCliente;
    int idEstudio;
    int idPredio;
    int idAgencia;

    DATA * inicio;
    DATA * fim;
    DATA * dataDeRegisto;

    double precoAPagar;

    REGRA ** arrayDeRegrasParaPagamento;
    int numeroDeRegrasNoArray;
    int numeroMaximoDeRegrasNoArray;

    struct evento * proximoEvento; // so para caso de impressao
    char * descricao;
    double valorAInflacionarDescontarNoPreco;
}EVENTO;
typedef struct listaEvento {
    DATA * data;
    int numeroEventos;
    EVENTO * primeiroEvento;
}LISTAEVENTO;
typedef struct cliente {
    int idCliente;
    char * email;
    char * nome;
    struct cliente * proximoCliente;
    LISTAEVENTO * primeiroEvento;
}CLIENTE;
typedef struct listaClientes {
    int numeroClientes;
    CLIENTE * primeiroCliente;
}LISTACLIENTE;
typedef struct promocao {
    int idPromocao;
    int idEstudio; // promotion to studio
    int  idPredio; // promotion to building
    DATA * inicio;  //promotion to booking on interval of date
    DATA * fim; //promotion to booking on interval of date
    struct promocao * proximaPromocao; // promotion list
    int minimoDeDias; //promotion to minimal days to booking
    int percentagemDescontoInflacao;
}PROMOCAO;//
typedef struct listaPromocao {
    int numeroPromocao;
    int autoIncrimentId;
    PROMOCAO * primeiraPromocao;
}LISTAPROMOCAO;
typedef struct agencia {
    int idAgencia;
    char * nome;
    struct agencia * proximaAgencia;
    LISTAEVENTO * primeiroEvento ;
    LISTAPROMOCAO * primeiroPromocao ;
}AGENCIA;
typedef struct listaAgencia {
    int numeroAgencias;
    AGENCIA * primeiraAgencia;
}LISTAAGENCIA;
typedef struct estudio {
    int idEstudio;
    int idPredio;
    int numeroQuartos;
    int duplex;
    char * descricao;
    double precoBase;
    double  metrosQuadrados;

    EVENTO ** arrayEventos;
    LISTAAGENCIA * listaagencia;
    int numeroEventosRegistados;
    int numeroMaximoEventosArray;

    struct estudio * proximoEstudio; // pointer to linked list on portoflat
}ESTUDIO;
typedef struct listaEstudio {
    int numeroDeEstudios;
    ESTUDIO * primeiroEstudio;
}LISTAESTUDIO;
typedef struct predio {
    int idPredio;
    int numeroEstudios;
    double longitude;
    double latitude;
    char * rua;
    char * cidade;
    int numeroMaximoDoEstudiosArray;
    ESTUDIO ** arrayDeEstudios;
    struct predio * proximoPredio; // list to portoflat
}PREDIO;
typedef struct listaPredio{
    int numeroDePredios;
    PREDIO * primeiroPredios;
}LISTAPREDIO;

typedef struct portoFlat{
    LISTAAGENCIA * listaAgencia;
    LISTAESTUDIO * listaEstudio;
    LISTAPREDIO * listaPredio;
    LISTACLIENTE * listaCliente;
    LISTAEVENTO * listaEvento;
    double faturacao;
    int autoIncrementIdAgencia;
    int autoIncrementIdEstudio;
    int autoIncrementIdCliente;
    int autoIncrementIdPredio;
    int autoIncrementIdEvento;
}PORTOFLAT;// C
#endif //TESTEAS_ESTRUTURAS_H
