#include "SistemaFicheiros.h"
#include "Entradas.h"
#include <ctime>

Entrada::Entrada(string nome, string caminho, time_t data,SistemaFicheiros *sistema)
{
	NOME = nome;
	CAMINHO = caminho;
	DATA = data;
	Sistema = sistema;
}

Entrada::~Entrada()
{
	
}

string Entrada::getNome()
{
	return NOME;
}

string Entrada::getCaminho()
{
	return CAMINHO;
}

time_t Entrada::getData()
{
	return DATA;
}

SistemaFicheiros *Entrada::getSistema()
{
	return Sistema;
}

void Entrada::setNome(string novoNome)
{
	NOME = novoNome;
}

void Entrada::setCaminho(string novoCaminho)
{
	CAMINHO = novoCaminho;
}

string Entrada::getDataFormatada()
{
	tm *t = localtime(&DATA); //converte para uma estrutura de tempo mais detalhada do tipo tm que contém campos como o dia, mês, ano
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", t); // formata as data que está no ponteiro t para uma string que contem o dia, mês e ano
    return string(buffer);
}