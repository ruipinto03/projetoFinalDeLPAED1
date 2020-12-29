//
// Created by Rui Pinto on 28/12/2020.
//

#include "funcoes.h"

PORTOFLAT portoflat = {NULL, NULL, NULL, NULL, NULL, 0.0, 0, 0, 0, 0, 0};
/*AUXILIARES*/
char *newString(int size) {
    return (char *) malloc(sizeof(char *) * size + 1);
}

char *toUpper(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (*(string + i) >= 'a' && *(string + i) <= 'z') {
            *(string + i) -= 32;
        }
    }
    return string;
}

DATA *stringToDate(char *string) {
    char *token;
    int day = 0, month = 0, year = 0;
    token = strtok(string, "/");
    while (token != NULL) {
        day = atoi(token);
        token = strtok(NULL, "/");
        month = atoi(token);
        token = strtok(NULL, "/");
        year = atoi(token);
        token = strtok(NULL, "/");
        //   printf("%d %d %d", day,month,year);
    }
    DATA *new = novoData(day, month, year);
    return new;
}

DATA *stringToTimeStamp(char *string) {
    char *token, *data, *horas, *token1, *token2;
    int year, day, month, hours, seconds, minutes;
    token = strtok(string, " ");
    while (token != NULL) {
        data = newString(strlen(token));
        strcpy(data, token);
        //      printf("%s",data);
        token = strtok(NULL, " ");
        horas = newString(strlen(token));
        strcpy(horas, token);
        //      printf(" %s",horas);
        token = strtok(NULL, " ");
    }
    token1 = strtok(data, "/");
    while (token1 != NULL) {
        day = atoi(token1);
        token1 = strtok(NULL, "/");
        month = atoi(token1);
        token1 = strtok(NULL, "/");
        year = atoi(token1);
        token1 = strtok(NULL, "/");
    }
    token2 = strtok(horas, ":");
    while (token2 != NULL) {
        hours = atoi(token2);
        token2 = strtok(NULL, ":");
        minutes = atoi(token2);
        token2 = strtok(NULL, ":");
        seconds = atoi(token2);
        token2 = strtok(NULL, ":");
    }

    DATA *new = novoData(day, month, year);
    new->minutos = minutes;
    new->horas = hours;
    new->segundos = seconds;
    printf("date -> %d/%d/%d ", new->dia, new->mes, new->ano);
    printf(" %d:%d:%d\n", new->horas, new->minutos, new->segundos);

    return new;
}

int existeAgencia(int id){
    if (portoflat.listaAgencia->numeroAgencias == 0) {
//printf("List empty!\n");
        return 1;
    }
    AGENCIA *temp =portoflat.listaAgencia->primeiraAgencia;
    while (temp != NULL) {
        if (temp->idAgencia == id) {
            return 0;
        }
        temp = temp->proximaAgencia;
    }
    return 1;
}
int existeCliente(int id){
    if (portoflat.listaCliente->numeroClientes == 0) {
//printf("List empty!\n");
        return 1;
    }
    CLIENTE *temp =portoflat.listaCliente->primeiroCliente;
    while (temp != NULL) {
        if (temp->idCliente == id) {
            return 0;
        }
        temp = temp->proximoCliente;
    }
    return 1;
}
int existePredio(int id){
    if (portoflat.listaPredio->numeroDePredios == 0) {
//printf("List empty!\n");
        return 1;
    }
    PREDIO *temp =portoflat.listaPredio->primeiroPredios;
    while (temp != NULL) {
        if (temp->idPredio == id) {
            return 0;
        }
        temp = temp->proximoPredio;
    }
    return 1;
}
int existeEstudio(int id){
    if (portoflat.listaEstudio->numeroDeEstudios == 0) {
//printf("List empty!\n");
        return 1;
    }
    ESTUDIO *temp =portoflat.listaEstudio->primeiroEstudio;
    while (temp != NULL) {
        if (temp->idEstudio == id) {
            return 0;
        }
        temp = temp->proximoEstudio;
    }
    return 1;
}
int existeEvento(int id){
    if (portoflat.listaEvento->numeroEventos == 0) {
//printf("List empty!\n");
        return 1;
    }
    EVENTO *temp =portoflat.listaEvento->primeiroEvento;
    while (temp != NULL) {
        if (temp->idEvento == id) {
            return 0;
        }
        temp = temp->proximoEvento;
    }
    return 1;
}

AGENCIA * retornaAgencia(int id){
    if (portoflat.listaAgencia->numeroAgencias == 0) {
//printf("List empty!\n");
        return NULL;
    }
    AGENCIA *temp =portoflat.listaAgencia->primeiraAgencia;
    while (temp != NULL) {
        if (temp->idAgencia == id) {
            return temp;
        }
        temp = temp->proximaAgencia;
    }
    return NULL;
}
CLIENTE * retornaCliente(int id){
    if (portoflat.listaCliente->numeroClientes == 0) {
//printf("List empty!\n");
        return NULL;
    }
    CLIENTE *temp =portoflat.listaCliente->primeiroCliente;
    while (temp != NULL) {
        if (temp->idCliente == id) {
            return temp;
        }
        temp = temp->proximoCliente;
    }
    return NULL;
}
PREDIO * retornaPredio(int id){
    if (portoflat.listaPredio->numeroDePredios == 0) {
//printf("List empty!\n");
        return NULL;
    }
    PREDIO *temp =portoflat.listaPredio->primeiroPredios;
    while (temp != NULL) {
        if (temp->idPredio == id) {
            return temp;
        }
        temp = temp->proximoPredio;
    }
    return NULL;
}
ESTUDIO * retornaEstudio(int id){
    if (portoflat.listaEstudio->numeroDeEstudios == 0) {
//printf("List empty!\n");
        return NULL;
    }
    ESTUDIO *temp =portoflat.listaEstudio->primeiroEstudio;
    while (temp != NULL) {
        if (temp->idEstudio == id) {
            return temp;
        }
        temp = temp->proximoEstudio;
    }
    return NULL;
}
EVENTO * retornaEvento(int id){
    if (portoflat.listaEvento->numeroEventos == 0) {
//printf("List empty!\n");
        return NULL;
    }
    EVENTO *temp =portoflat.listaEvento->primeiroEvento;
    while (temp != NULL) {
        if (temp->idEvento == id) {
            return temp;
        }
        temp = temp->proximoEvento;
    }
    return NULL;
}

/*ALOCACAO*/
EVENTO ** novoArrayEvento(int tamanho){
    EVENTO **eventoArray = (EVENTO **) malloc(sizeof(EVENTO *) * tamanho);
    return eventoArray;
}
LISTAEVENTO ** novoArrayDeListaEventos(int tamanho){
    LISTAEVENTO **listaEventoArray = (LISTAEVENTO **) malloc(sizeof(LISTAEVENTO *) * tamanho);
    return listaEventoArray;
}
ESTUDIO **novoEstudioArray(int tamanho){
    ESTUDIO **eventoEstudio = (ESTUDIO **) malloc(sizeof(ESTUDIO *) * tamanho);
    return eventoEstudio;
}
REGRA **novoRegrasArray(int tamanho){
    REGRA **eventoArray = (REGRA **) malloc(sizeof(REGRA *) * tamanho);
    return eventoArray;
}

LISTAAGENCIA * novaListaAgencia(){
    LISTAAGENCIA * nova = (LISTAAGENCIA*)malloc(sizeof(LISTAAGENCIA));
    nova->primeiraAgencia=NULL;
    nova->numeroAgencias = 0 ;
    return nova;
}
LISTAESTUDIO * novaListaEstudio(){
    LISTAESTUDIO *nova = (LISTAESTUDIO *) malloc(sizeof(LISTAESTUDIO));
    nova->numeroDeEstudios = 0;
    nova->primeiroEstudio = NULL;
    return nova;
}
LISTAPREDIO * novaListaPredio(){
    LISTAPREDIO *nova = (LISTAPREDIO *) malloc(sizeof(LISTAPREDIO));
    nova->numeroDePredios = 0;
    nova->primeiroPredios = NULL;
    return nova;
}
LISTACLIENTE * novaListaCliente(){
    LISTACLIENTE *nova = (LISTACLIENTE *) malloc(sizeof(LISTACLIENTE));
    nova->numeroClientes = 0;
    nova->primeiroCliente = NULL;
    return nova;
}
LISTAEVENTO * novaListaEvento(){
    LISTAEVENTO *nova = (LISTAEVENTO *) malloc(sizeof(LISTAEVENTO));
    nova->numeroEventos = 0;
    nova->primeiroEvento = NULL;
    nova->data = NULL;
    return nova;
}
LISTAPROMOCAO * novaListaPromocao(){
    LISTAPROMOCAO *nova = (LISTAPROMOCAO *) malloc(sizeof(LISTAPROMOCAO));
    nova->numeroPromocao = 0;
    nova->autoIncrimentId = 0;
    nova->primeiraPromocao = NULL;
    return nova;
}

DATA * novoData(int dia,int mes,int ano){

    DATA *novo = (DATA *) malloc(sizeof(DATA));

    if (mes < 1 || mes > 12 || dia > daysMonth(mes, ano) || dia < 1) {
        printf("Data invalida");
        return NULL;
    }

    novo->segundos = 0;
    novo->minutos = 0;
    novo->horas = 0;
    novo->dia = dia;
    novo->mes = mes;
    novo->ano = ano;
    return novo;
}
DATA * novoTimeStamp(){
    DATA *novo = (DATA *) malloc(sizeof(DATA));

    time_t time1;
    time(&time1);
    struct tm *t = localtime(&time1);
    novo->segundos = t->tm_sec;
    novo->minutos = t->tm_min;
    novo->horas = t->tm_hour;
    novo->dia = t->tm_mday;
    novo->mes = t->tm_mon + 1;
    novo->ano = t->tm_year + 1900;

    return novo;
}


AGENCIA * novoAgencia(int idAgencia , char * nome){
    AGENCIA *agencia = (AGENCIA *) malloc(sizeof(AGENCIA));
    agencia->nome = newString((int) strlen(nome));
    strcpy(agencia->nome, nome);
    if (idAgencia == 0) {
        agencia->idAgencia = portoflat.autoIncrementIdAgencia + 1;
        portoflat.autoIncrementIdAgencia += 1;
    } else {
        if (existeAgencia(idAgencia) == 0) {
            printf("Error id exist!");
            return NULL;
        } else {
            if ( portoflat.autoIncrementIdAgencia < idAgencia) {
                portoflat.autoIncrementIdAgencia = idAgencia;
            }
            agencia->idAgencia = portoflat.autoIncrementIdAgencia;
        }
    }
    agencia->proximaAgencia = NULL;
    agencia->primeiroEvento = novaListaEvento();
    agencia->primeiroPromocao = novaListaPromocao();
    return agencia;
}

REGRA * novoRegra(int idRegra, char *descricao, double descontoOuInflacao){
    REGRA *novo = (REGRA *) malloc(sizeof(REGRA));
    novo->descricao = newString((int) strlen(descricao));
    strcpy(novo->descricao, descricao);
    novo->idRegra = idRegra;
    novo->descontoInflacao = descontoOuInflacao;
    return novo;
}

PROMOCAO *novoPromocao(int agencia,int idPromocao, int idEstudio,int idPredio, DATA *inicio, DATA *fim ,int numeroMinimoDias,int desconto){
    PROMOCAO *promocao = (PROMOCAO *) malloc(sizeof(PROMOCAO));
    if (existeAgencia(agencia) != 0) {
        return NULL;
    }
    AGENCIA *temp = retornaAgencia(agencia);
    if (idPromocao == 0) {
        promocao->idPromocao = temp->primeiroPromocao->autoIncrimentId + 1;
        temp->primeiroPromocao->autoIncrimentId += 1;
    } else {

        if (temp->primeiroPromocao->autoIncrimentId < idPromocao) {
            temp->primeiroPromocao->autoIncrimentId = idPromocao;
        }
        promocao->idPromocao = temp->primeiroPromocao->autoIncrimentId;
    }
    if (inicio == NULL || fim == NULL) {
        promocao->fim = NULL;
        promocao->inicio = NULL;
    } else if (beforeDate(inicio, fim) != 0) {
        promocao->fim = fim;
        promocao->inicio = inicio;
    } else {
        promocao->fim = NULL;
        promocao->inicio = NULL;
    }
    promocao->idPredio = idPredio;
    promocao->percentagemDescontoInflacao = desconto;
    promocao->minimoDeDias = numeroMinimoDias;
    promocao->idEstudio = idEstudio;
    promocao->proximaPromocao = NULL;

    return promocao;
}

CLIENTE * novoCliente(int idCliente, char *nome, char *email) {
    CLIENTE *cliente = (CLIENTE *) malloc(sizeof(CLIENTE));

    cliente->nome = newString((int) strlen(nome));
    cliente->email = newString((int) strlen(email));
    strcpy(cliente->nome, nome);
    strcpy(cliente->email, email);

    if (idCliente == 0) {
        cliente->idCliente = portoflat.autoIncrementIdCliente + 1;
        portoflat.autoIncrementIdCliente += 1;
    } else {
        if (existeCliente(idCliente) == 0) {
            printf("Error id exist!");
            return NULL;
        } else {
            if (portoflat.autoIncrementIdCliente < idCliente) {
                portoflat.autoIncrementIdCliente = idCliente;
            }
            cliente->idCliente = portoflat.autoIncrementIdCliente;
        }
    }
    cliente->proximoCliente = NULL;
    cliente->primeiroEvento = novaListaEvento();

    return cliente;
}

PREDIO * novoPredio(int idPredio, char *rua, char *cidade, double longitude, double latitude){
    PREDIO *predio = (PREDIO *) malloc(sizeof(PREDIO));
    predio->rua = newString((int) strlen(rua));
    predio->cidade = newString((int) strlen(cidade));
    strcpy(predio->rua, rua);
    strcpy(predio->cidade, cidade);

    predio->latitude = latitude;
    predio->longitude = longitude;

    predio->numeroMaximoDoEstudiosArray = INITIALSIZE;
    if (idPredio == 0) {
        predio->idPredio = portoflat.autoIncrementIdPredio + 1;
        portoflat.autoIncrementIdPredio += 1;
    } else {
        if (existePredio(idPredio) == 0) {
            printf("Error id exist!");
            return NULL;
        } else {
            if (portoflat.autoIncrementIdPredio < idPredio) {
                portoflat.autoIncrementIdPredio = idPredio;
            }
            predio->idPredio = portoflat.autoIncrementIdPredio;
        }
    }
    predio->numeroEstudios = 0;

    predio->proximoPredio = NULL;
    predio->arrayDeEstudios = novoEstudioArray(INITIALSIZE);

    return predio;
}

ESTUDIO * novoEstudio(int idEstudio, int idPredio, int numeroQuartos, int duplex, char *descricao, double precoBase, double metrosQuadrados){
    if (existePredio(idPredio) != 0) {
        printf("Building not exist!");
        return NULL;
    }
    ESTUDIO *novo = (ESTUDIO *) malloc(sizeof(ESTUDIO));
    novo->idPredio = idPredio;

    if (idEstudio == 0) {
        novo->idEstudio = portoflat.autoIncrementIdEstudio + 1;
        portoflat.autoIncrementIdEstudio += 1;
    } else {
        if (existeEstudio(idEstudio) == 0) {
            printf("Error id exist!");
            return NULL;
        } else {
            if ( portoflat.autoIncrementIdEstudio < idEstudio) {
                portoflat.autoIncrementIdEstudio = idEstudio;
            }
            novo->idEstudio =  portoflat.autoIncrementIdEstudio;
        }
    }

    novo->numeroQuartos = numeroQuartos;
    novo->duplex = duplex;
    novo->descricao = descricao;
    novo->precoBase = precoBase;
    novo->metrosQuadrados = metrosQuadrados;
    novo->listaagencia = novaListaAgencia();
    novo->arrayEventos = novoArrayEvento(INITIALSIZE);
    novo->numeroEventosRegistados =0;
    novo->numeroMaximoEventosArray =INITIALSIZE;
    novo->proximoEstudio = NULL;
    return novo;
}

EVENTO * novoEvento(int idEvento, int idCliente, int idEstudio, int idPredio, int idAgencia, DATA *inicio, DATA *fim, double precoDaResreva,char *descricao){
    EVENTO *novo = (EVENTO *) malloc(sizeof(EVENTO));

    if (idEvento == 0) {
        novo->idEvento = portoflat.autoIncrementIdEvento + 1;
        portoflat.autoIncrementIdEvento += 1;
    } else {
        if (existeEvento(idEvento) == 0) {
            printf("Error id exist!");
            return NULL;
        } else {
            if ( portoflat.autoIncrementIdEvento < idEvento) {
                portoflat.autoIncrementIdEvento = idEvento;
            }
            novo->idEvento =  portoflat.autoIncrementIdEvento;
        }
    }
    ESTUDIO *temp = retornaEstudio(idEstudio);
    if (temp == NULL) {
        free(novo);
        printf("Error Id building invalid!");
        return NULL;
    }
    novo->idCliente = idCliente;
    novo->idEstudio = idEstudio;
    novo->idPredio = idPredio;
    novo->idAgencia = idAgencia;
    novo->inicio = inicio;
    novo->fim = fim;
    novo->dataDeRegisto = novoTimeStamp();
    novo->precoAPagar = precoDaResreva;
    novo->descricao = newString((int)strlen(descricao));
    strcpy(novo->descricao , descricao);
    novo->arrayDeRegrasParaPagamento = novoRegrasArray(INITIALSIZE);
    novo->numeroDeRegrasNoArray = 0;
    novo->valorAInflacionarDescontarNoPreco = 1;
    novo->numeroMaximoDeRegrasNoArray = INITIALSIZE;
    novo->proximoEvento = NULL; // so para caso de impressao
    return novo;
}

EVENTO * novoEventoCompleto(int idEvento, int idCliente, int idEstudio, int idPredio, int idAgencia, DATA *inicio, DATA *fim,
                            DATA *dataDaReserva, double precoDaReserva, REGRA **arrayDeRegras, int numeroRegras,
                            char *descricao){
    EVENTO *novo = (EVENTO *) malloc(sizeof(EVENTO));
    novo->idEvento = idEvento;
    novo->idCliente = idCliente;
    novo->idEstudio = idEstudio;
    novo->idPredio = idPredio;
    novo->idAgencia = idAgencia;
    novo->inicio = inicio;
    novo->fim = fim;
    novo->dataDeRegisto = dataDaReserva;
    novo->precoAPagar = precoDaReserva;
    novo->descricao = newString((int)strlen(descricao));
    strcpy(novo->descricao , descricao);
    novo->arrayDeRegrasParaPagamento = arrayDeRegras;
    novo->numeroDeRegrasNoArray = numeroRegras;
    novo->numeroMaximoDeRegrasNoArray = INITIALSIZE;
    novo->proximoEvento = NULL; // so para caso de impressao
    return novo;
}
void insereNaListaAgencia(LISTAAGENCIA * listaagencia , AGENCIA * agencia){
    if (listaagencia->numeroAgencias == 0) {
        listaagencia->primeiraAgencia = agencia;
        listaagencia->numeroAgencias += 1;
        return;
    }
    AGENCIA *pcurrent = listaagencia->primeiraAgencia, *pointer = NULL;
    while (pcurrent != NULL && strcmp(agencia->nome, pcurrent->nome) > 0) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximaAgencia;
    }
//HEAD
    if (pcurrent == listaagencia->primeiraAgencia) {
        agencia->proximaAgencia = pcurrent;
        listaagencia->primeiraAgencia = agencia;
        listaagencia->numeroAgencias += 1;
        return;
    }

//TAIL
    if (pcurrent == NULL) {
        pointer->proximaAgencia = agencia;
        listaagencia->numeroAgencias += 1;
        return;
    }
//MIDDLE
    pointer->proximaAgencia = agencia;
    agencia->proximaAgencia = pcurrent;
    listaagencia->numeroAgencias += 1;
}
void insereNaListaCliente(LISTACLIENTE * listacliente , CLIENTE * cliente){
    if (listacliente->numeroClientes == 0) {
        listacliente->primeiroCliente = cliente;
        listacliente->numeroClientes += 1;
        return;
    }
    CLIENTE *pcurrent = listacliente->primeiroCliente, *pointer = NULL;
    while (pcurrent != NULL && strcmp(cliente->nome, pcurrent->nome) > 0) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximoCliente;
    }
//HEAD
    if (pcurrent == listacliente->primeiroCliente) {
        cliente->proximoCliente = pcurrent;
        listacliente->primeiroCliente = cliente;
        listacliente->numeroClientes += 1;
        return;
    }

//TAIL
    if (pcurrent == NULL) {
        pointer->proximoCliente = cliente;
        listacliente->numeroClientes += 1;
        return;
    }
//MIDDLE
    pointer->proximoCliente = cliente;
    cliente->proximoCliente = pcurrent;
    listacliente->numeroClientes += 1;
}
void insereNaListaPredio(LISTAPREDIO * listapredio , PREDIO * predio){
    if (listapredio->numeroDePredios == 0) {
        listapredio->primeiroPredios = predio;
        listapredio->numeroDePredios += 1;
        return;
    }
    PREDIO *pcurrent = listapredio->primeiroPredios, *pointer = NULL;
    while (pcurrent != NULL && strcmp(predio->cidade, pcurrent->cidade) > 0) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximoPredio;
    }
//HEAD
    if (pcurrent == listapredio->primeiroPredios) {
        predio->proximoPredio = pcurrent;
        listapredio->primeiroPredios = predio;
        listapredio->numeroDePredios += 1;
        return;
    }

//TAIL
    if (pcurrent == NULL) {
        pointer->proximoPredio = predio;
        listapredio->numeroDePredios += 1;
        return;
    }
//MIDDLE
    pointer->proximoPredio = predio;
    predio->proximoPredio = pcurrent;
    listapredio->numeroDePredios += 1;
}
void insereNaListaEstudio(LISTAESTUDIO * listaestudio , ESTUDIO * estudio){
    if (listaestudio->numeroDeEstudios == 0) {
        listaestudio->primeiroEstudio = estudio;
        listaestudio->numeroDeEstudios += 1;
        return;
    }
    ESTUDIO *pcurrent = listaestudio->primeiroEstudio, *pointer = NULL;
    while (pcurrent != NULL && estudio->numeroQuartos>= pcurrent->numeroMaximoEventosArray) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximoEstudio;
    }
//HEAD
    if (pcurrent == listaestudio->primeiroEstudio) {
        estudio->proximoEstudio = pcurrent;
        listaestudio->primeiroEstudio = estudio;
        listaestudio->numeroDeEstudios += 1;
        return;
    }

//TAIL
    if (pcurrent == NULL) {
        pointer->proximoEstudio = estudio;
        listaestudio->numeroDeEstudios += 1;
        return;
    }
//MIDDLE
    pointer->proximoEstudio = estudio;
    estudio->proximoEstudio = pcurrent;
    listaestudio->numeroDeEstudios += 1;
}
void insereNaListaEvento(LISTAEVENTO * listaevento, EVENTO * evento){
    if (listaevento->numeroEventos == 0) {
        listaevento->primeiroEvento = evento;
        listaevento->numeroEventos += 1;
        return;
    }
    EVENTO *pcurrent = listaevento->primeiroEvento, *pointer = NULL;
    while (pcurrent != NULL && beforeDate(evento->inicio, pcurrent->inicio)) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximoEvento;
    }
//HEAD
    if (pcurrent == listaevento->primeiroEvento) {
        evento->proximoEvento = pcurrent;
        listaevento->primeiroEvento = evento;
        listaevento->numeroEventos += 1;
        return;
    }

//TAIL
    if (pcurrent == NULL) {
        pointer->proximoEvento = evento;
        listaevento->numeroEventos += 1;
        return;
    }
//MIDDLE
    pointer->proximoEvento = evento;
    evento->proximoEvento = pcurrent;
    listaevento->numeroEventos += 1;
}

void insereNoArrayEstudios( ESTUDIO * estudio){
    PREDIO *temp = portoflat.listaPredio->primeiroPredios;
    for (int i = 0; i < portoflat.listaPredio->numeroDePredios; i++) {
        if (temp->idPredio == estudio->idPredio) {
            if (temp->numeroMaximoDoEstudiosArray / 2 == temp->numeroEstudios + 1) {
                temp->arrayDeEstudios = (ESTUDIO **) realloc(temp->arrayDeEstudios,
                                                        sizeof(ESTUDIO *) * temp->numeroMaximoDoEstudiosArray * 2);
                temp->numeroMaximoDoEstudiosArray *= 2;
            }
            temp->arrayDeEstudios[temp->numeroEstudios] = estudio;
            temp->numeroEstudios += 1;
            return;
        }
        temp = temp->proximoPredio;
    }
}
void inserePromocaoAgencia(int idAgencia, PROMOCAO * promocao){
    AGENCIA * temp = retornaAgencia(idAgencia);
    if (temp->primeiroPromocao->numeroPromocao == 0) {
        temp->primeiroPromocao->primeiraPromocao = promocao;
        temp->primeiroPromocao->numeroPromocao += 1;
        return;
    }
    PROMOCAO *pcurrent = temp->primeiroPromocao->primeiraPromocao, *pointer = NULL;
    while (pcurrent != NULL) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximaPromocao;
    }
//HEAD
    if (pcurrent == temp->primeiroPromocao->primeiraPromocao) {
        promocao->proximaPromocao = pcurrent;
        temp->primeiroPromocao->primeiraPromocao = promocao;
        temp->primeiroPromocao->numeroPromocao += 1;
        return;
    }

//TAIL
    if (pcurrent == NULL) {
        pointer->proximaPromocao = promocao;
        temp->primeiroPromocao->numeroPromocao += 1;
        return;
    }
//MIDDLE
    pointer->proximaPromocao = promocao;
    promocao->proximaPromocao = pcurrent;
    temp->primeiroPromocao->numeroPromocao += 1;
}

void removeAgencia(int id){
  if (portoflat.listaAgencia->numeroAgencias == 0) {
        //printf("List empty!\n");
        return ;
    }
    AGENCIA *pointer = NULL, *pcurrent = portoflat.listaAgencia->primeiraAgencia;
    while (pcurrent != NULL && pcurrent->idAgencia != id) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximaAgencia;
    }
    if (pcurrent == NULL) {
        return ;
    }
    if (pointer == NULL) {
        portoflat.listaAgencia->primeiraAgencia = pcurrent->proximaAgencia;
        free(pcurrent);
        portoflat.listaAgencia->numeroAgencias -= 1;
        return ;
    }
    pointer->proximaAgencia = pcurrent->proximaAgencia;
    free(pcurrent);
    portoflat.listaAgencia->numeroAgencias -= 1;
}

void removeCliente(int id){
    if (portoflat.listaCliente->numeroClientes == 0) {
        //printf("List empty!\n");
        return ;
    }
    CLIENTE *pointer = NULL, *pcurrent = portoflat.listaCliente->primeiroCliente;
    while (pcurrent != NULL && pcurrent->idCliente != id) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximoCliente;
    }
    if (pcurrent == NULL) {
        return ;
    }
    if (pointer == NULL) {
        portoflat.listaCliente->primeiroCliente = pcurrent->proximoCliente;
        free(pcurrent);
        portoflat.listaCliente->numeroClientes -= 1;
        return ;
    }
    pointer->proximoCliente = pcurrent->proximoCliente;
    free(pcurrent);
    portoflat.listaCliente->numeroClientes -= 1;
}
void removePredio(int id){
    if (portoflat.listaPredio->numeroDePredios == 0) {
        //printf("List empty!\n");
        return ;
    }
    PREDIO *pointer = NULL, *pcurrent = portoflat.listaPredio->primeiroPredios;
    while (pcurrent != NULL && pcurrent->idPredio != id) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximoPredio;
    }
    if (pcurrent == NULL) {
        return ;
    }
    if (pointer == NULL) {
        portoflat.listaPredio->primeiroPredios = pcurrent->proximoPredio;
        free(pcurrent);
        portoflat.listaPredio->numeroDePredios -= 1;
        return ;
    }
    pointer->proximoPredio = pcurrent->proximoPredio;
    free(pcurrent);
    portoflat.listaPredio->numeroDePredios -= 1;
}

void removeEstudio(int id){
    if (portoflat.listaEstudio->numeroDeEstudios == 0) {
        //printf("List empty!\n");
        return ;
    }
    ESTUDIO *pointer = NULL, *pcurrent =portoflat.listaEstudio->primeiroEstudio;
    while (pcurrent != NULL && pcurrent->idEstudio != id) {
        pointer = pcurrent;
        pcurrent = pcurrent->proximoEstudio;
    }
    if (pcurrent == NULL) {
        return ;
    }
    if (pointer == NULL) {
        portoflat.listaEstudio->primeiroEstudio = pcurrent->proximoEstudio;
        free(pcurrent);
        portoflat.listaEstudio->numeroDeEstudios -= 1;
        return ;
    }
    pointer->proximoEstudio = pcurrent->proximoEstudio;
    free(pcurrent);
    portoflat.listaEstudio->numeroDeEstudios -= 1;
}

void removeEstudioArrayEstudios(int idPredio, int idEstudio){
   PREDIO * predio = retornaPredio(idPredio);
   for(int i = 0 ; i<predio->numeroEstudios; i++){
       if(predio->arrayDeEstudios[i]->idEstudio == idEstudio){
           for (int j = i; j <predio->numeroEstudios ; ++j) {
               predio->arrayDeEstudios[i] = predio->arrayDeEstudios[j+1];
           }
           predio->numeroEstudios-=1;
           if( predio->numeroEstudios <= predio->numeroMaximoDoEstudiosArray /4){
               predio->arrayDeEstudios = (ESTUDIO **) realloc(predio->arrayDeEstudios,
                                                            sizeof(ESTUDIO *) * predio->numeroMaximoDoEstudiosArray / 2);
               predio->numeroMaximoDoEstudiosArray = predio->numeroMaximoDoEstudiosArray / 2;
           }
           return;
       }
   }
}

void removeEvento(int id){

}