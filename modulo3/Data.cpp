#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <cstddef>
#include <time.h>
#include "Data.h"
#include "ExecaoCustomizada.h"

using namespace std;

//Metodos Privados:

void Data::ticksToDate()
{
    long aux;
    int bissexto= 0;        //Variavel para identificar se o ano atualmente considerado eh bissexto, sendo 1 sim e 0 nao

    aux= ticks;     //Copia o valor conhecido de ticks para uma variavel auxiliar
    //Inicializa a data como o menor valor possivel para ser entao incrementado
    ano= 1970;
    mes= 1;
    dia= 1;
    hora= 0;
    minuto= 0;
    segundo= 0;
    //Determina o numero de anos passados desde 1970:
    while (aux>(60*60*24*365))      //Verifica se o valor restante de ticks supera os segundos de um ano normal
    {
        if ((ano%400==0)||((ano%4==0)&&(ano%100!=0)))       //Verifica se o ano atualmente considerado eh bissexto
        {
            bissexto= 1;
            if (aux>(60*60*24*366))     //Verifica se o valor restante de ticks supera os segundos de um ano bissexto
            {
                ano++;
                aux= aux-(60*60*24*366);
            }
            else
                break;
        }
        else
            bissexto= 0;
    }
    //Determina o numero de meses e dias passados no ano final:
    while (aux>(60*60*24))
    {
        dia++;
        aux= aux-(60*60*24);
        if ((dia>31)&&((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)))     //Verifica se o numero de dias supera 31 nos meses correspondentes
        {
            mes++;
            dia= 1;
        }
        else if ((dia>30)&&((mes==4)||(mes==6)||(mes==9)||(mes==11)))        //Verifica se o numero de dias supera 30 nos meses correspondentes
        {
            mes++;
            dia= 1;
        }
        else if (dia>(28+bissexto))     //Verifica se o numero de dias supera 28 ou 29 em fevereiro levando em conta se o ano eh bissexto
        {
            mes++;
            dia= 1;
        }
    }
    //Determina o numero de horas no dia final:
    while (aux>(60*60))
    {
        hora++;
        aux= aux-(60*60);
    }
    //Determina o numero de minutos na hora final:
    while (aux>60)
    {
        minuto++;
        aux= aux-60;
    }
    //Determina o numero de segundos no minuto final:
    segundo= int(aux);
}

void Data::dateToTicks()
{
    long aux= 0;        //Foi #include "ExecaoCustomizada.h"utilizada uma variavel auxiliar para nao ser necessario inicializar ticks como 0 por default
    int anosBissextos= 0;       //Variavel para armazenar o numero de anos bissextos passados desde 1970
    int anosNormais= 0;     //Variavel para armazenar o numero de anos nao bissextos passados desde 1970

    anosBissextos= ((ano-1973)/4)+1;        //1972 eh um ano bissexto, e somente a partir dele ciclos perfeitos de 4
                                            //anos ocorreram desde 1970 para a contagem de anos bissextos passados
    anosNormais= ano-1970-anosBissextos;
    aux+= long(anosBissextos*(60*60*24*366));
    aux+= long(anosNormais*(60*60*24*365));
    if (mes>=2)
        aux+= long((31*60*60*24));
    if (mes>=3)
    {
        aux+= long((28*60*60*24));
        if ((ano%400==0)||((ano%4==0)&&(ano%100!=0)))
            aux+= long((60*60*24));
    }
    if (mes>=4)
        aux+= long((31*60*60*24));
    if (mes>=5)
        aux+= long((30*60*60*24));
    if (mes>=6)
        aux+= long((31*60*60*24));
    if (mes>=7)
        aux+= long((30*60*60*24));
    if (mes>=8)
        aux+= long((31*60*60*24));
    if (mes>=9)
        aux+= long((31*60*60*24));
    if (mes>=10)
        aux+= long((30*60*60*24));
    if (mes>=11)
        aux+= long((31*60*60*24));
    if (mes==12)
        aux+= long((30*60*60*24));
    aux+= long(dia*(60*60*24));
    aux+= long(hora*(60*60));
    aux+= long(minuto*60);
    aux+= long(segundo);
    ticks= aux;
}

//Construtores:

Data::Data()
{
    ano= 1970;
    mes= 1;
    dia= 1;
    hora= 0;
    minuto= 0;
    segundo= 0;
    dateToTicks();
    validaData();
}

Data::Data(Formato valFormato)
{
    ano= 1970;
    mes= 1;
    dia= 1;
    hora= 0;
    minuto= 0;
    segundo= 0;
    formatoData= valFormato;
    dateToTicks();
    validaData();
}

Data::Data(int valAno, int valMes, int valDia, int valHora, int valMin, int valSeg)
{
    ano= valAno;
    mes= valMes;
    dia= valDia;
    hora= valHora;
    minuto= valMin;
    segundo= valSeg;
    dateToTicks();
    validaData();
}

Data::Data(long valTicks)
{
    ticks= valTicks;
    ticksToDate();
    validaData();
}

//Destrutor:
Data::~Data(){}

//Operadores:

bool Data::operator==(Data &d2)
{
	return ((ano == d2.ano)&&(mes == d2.mes)&&(dia == d2.dia)&&(hora == d2.hora)&&
           (minuto == d2.minuto)&&(segundo == d2.segundo)||(ticks == d2.ticks));
}

bool Data::operator<(Data &d2)
{
	return ((ano<d2.ano)||(ano==d2.ano && mes<d2.mes)||(ano==d2.ano && mes==d2.mes && dia<d2.dia)||
           (ano==d2.ano && mes==d2.mes && dia==d2.dia && hora<d2.hora)||(ano==d2.ano && mes==d2.mes&&
           dia==d2.dia && hora==d2.hora && minuto<d2.minuto)||(ano==d2.ano && mes==d2.mes && dia==d2.dia &&
           hora==d2.hora && minuto==d2.minuto && segundo<d2.segundo));
}

bool Data::operator>(Data &d2)
{
    return !((ano<d2.ano)||(ano==d2.ano && mes<d2.mes)||(ano==d2.ano && mes==d2.mes && dia<d2.dia)||
	       (ano==d2.ano && mes==d2.mes && dia==d2.dia && hora<d2.hora)||(ano==d2.ano && mes==d2.mes&&
           dia==d2.dia && hora==d2.hora && minuto<d2.minuto)||(ano==d2.ano && mes==d2.mes && dia==d2.dia &&
           hora==d2.hora && minuto==d2.minuto && segundo<d2.segundo));
}

Data Data::operator-(Data &d2)
{
    Data aux(ticks-d2.getTicks());
    if (ticks<d2.getTicks())        //Tratamento de excecao se for tentada uma subtracao impossivel
        throw ExecaoCustomizada("Erro: Resultado eh data negativa, inverta parametros");
    else
        return aux;
}

//Metodos get:

int Data::getAno()
{
    return ano;
}

int Data::getMes()
{
    return mes;
}

int Data::getDia()
{
    return dia;
}

int Data::getHora()
{
    return hora;
}

int Data::getMin()
{
    return minuto;
}

int Data::getSeg()
{
    return segundo;
}

long Data::getTicks()
{
    return ticks;
}

string Data::getFormato()
{
    return formatoData.getNome();
}

//Metodos set:

void Data::setAno(int valAno)
{
    ano= valAno;
    dateToTicks();
    validaData();
}

void Data::setMes(int valMes)
{
    mes= valMes;
    dateToTicks();
    validaData();
}

void Data::setDia(int valDia)
{
    dia= valDia;
    dateToTicks();
    validaData();
}

void Data::setHora(int valHora)
{
    hora= valHora;
    dateToTicks();
    validaData();
}

void Data::setMin(int valMin)
{
    minuto= valMin;
    dateToTicks();
    validaData();
}

void Data::setSeg(int valSeg)
{
    segundo= valSeg;
    dateToTicks();
    validaData();
}

void Data::setTicks(long valTicks)
{
    ticks= valTicks;
    ticksToDate();
    validaData();
}

void Data::setFormato(Formato valFormato)
{
    formatoData= valFormato;
}

//Outros metodos:

bool Data::validaData()
{
    int condicao= 1;
    if ((segundo<0)||(minuto<0)||(hora<0)||(dia<0)||(mes<0)||(ano<1970))
        condicao= 0;
    else if ((segundo>59)||(minuto>59)||(hora>23)||(mes>12))
        condicao= 0;
    else if ((dia>31)&&((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)))
        condicao= 0;
    else if ((dia>30)&&((mes==4)||(mes==6)||(mes==9)||(mes==11)))
        condicao= 0;
    if ((ano%400==0)||((ano%4==0)&&(ano%100!=0)))
    {
        if ((mes==2)&&(dia>29))
            condicao= 0;
    }
    else
    {
        if ((mes==2)&&(dia>28))
            condicao= 0;
    }
    return (condicao==1);
}

Data Data::dateNow()
{
    time_t tempo= time(NULL);
    double a= double(tempo);
    Data aux(a);
    return aux;
}

void Data::printData()
{
    if (strcmp(formatoData.getNome().c_str(),"PT-BR")==0)
    {
        cout << dia << formatoData.getSeparadorData() << mes << formatoData.getSeparadorData() << ano << "  ";
        cout << hora << formatoData.getSeparadorHorario() << minuto << formatoData.getSeparadorHorario() << segundo << endl;
    }
    else if (strcmp(formatoData.getNome().c_str(),"EN-US")==0)
    {
        cout << ano << formatoData.getSeparadorData() << mes << formatoData.getSeparadorData() << dia << "  ";
        cout << hora << formatoData.getSeparadorHorario() << minuto << formatoData.getSeparadorHorario() << segundo << endl;
    }
    else        //Tratamento de excecao de formato invalido
        throw ExecaoCustomizada("Erro: Esperado argumento PT-BR ou EN-US");
}

string Data::getData() {
  string data = "";
   if (strcmp(formatoData.getNome().c_str(),"PT-BR")==0)
    {
      data = std::to_string(dia) + formatoData.getSeparadorData() + std::to_string(mes) + formatoData.getSeparadorData() + to_string(ano) + " " + to_string(hora)  + formatoData.getSeparadorHorario() + to_string(minuto) + formatoData.getSeparadorHorario() + to_string(segundo);

    }
   else if (strcmp(formatoData.getNome().c_str(),"EN-US")==0)
    {
       data = std::to_string(ano) + formatoData.getSeparadorData() + std::to_string(mes) + formatoData.getSeparadorData() + to_string(dia) + " " + to_string(hora)  + formatoData.getSeparadorHorario() + to_string(minuto) + formatoData.getSeparadorHorario() + to_string(segundo);
    }
    else        //Tratamento de excecao de formato invalido
        throw ExecaoCustomizada("Erro: Esperado argumento PT-BR ou EN-US");
  return data;
}

int Data::diffData(Data d2) {
  int diff = ticks - d2.getTicks();
  return diff / 60 / 60 / 24;
}
