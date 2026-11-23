#include <iostream>
#include <string>
#include <stdlib.h>
#include "SistemaFicheiros.h"

using namespace std;

void menuPesquisas(SistemaFicheiros &sistemaFicheiros);
void menuOperacoes(SistemaFicheiros &sistemaFicheiros);
void menuEstatisticas(SistemaFicheiros &sistemaFicheiros);

int main()
{
    system("cls");
    SistemaFicheiros sistemaFicheiros;
    int opcao;
    string path;

    do 
	{
        cout << "========================================" << endl;
        cout << "            MENU PRINCIPAL" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "1 - Carregar sistema de ficheiros" << endl;
        cout << "2 - Mostrar Tree do Sistema de Ficheiros" << endl;
        cout << "3 - Pesquisas" << endl;
        cout << "4 - Estatisticas" << endl;
        cout << "5 - Outras Operacoes" << endl;
        cout << "0 - Sair" << endl;
        cout << endl;
        cout << "Opcao pretendida: ";
        cin >> opcao;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// limpa o enter pendente para ser lido o caminho corretamente

        switch(opcao)
        {
            case 1:
            	system("cls");
                cout << "Introduza o caminho da diretoria raiz a carregar: ";
                getline(cin, path);
                if (sistemaFicheiros.Load(path))
                {
                    cout << "Sistema de Ficheiros carregado com sucesso!" << endl;	
				}
                break;
                
            case 2:
            	{
            		system("cls");
                    int opcaoTree;
                    string nomeF;

                    cout << "Como pretende ver a Tree?" << endl;
                    cout << "1 - No ecra" << endl;
                    cout << "2 - Gravar para ficheiro" << endl;
                    cout << "Opcao: ";
                    cin >> opcaoTree;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (opcaoTree == 1)
                    {
                        sistemaFicheiros.Tree();
                    }
                    else if (opcaoTree == 2)
                    {
                        cout << "Nome do ficheiro para gravar: ";
                        getline(cin, nomeF);
                        sistemaFicheiros.Tree(&nomeF);
                        cout << "Tree gravada em " << nomeF << endl;
                    }
                    else
                    {
                        cout << "Opcao invalida!" << endl;
                    }
                    break;
				}

            case 3:
            	system("cls");
                menuPesquisas(sistemaFicheiros);
                break;

            case 4:
            	system("cls");
                menuEstatisticas(sistemaFicheiros);
                break;

            case 5:
            	system("cls");
                menuOperacoes(sistemaFicheiros);
                break;

            case 0:
                cout << "A sair do programa..." << endl;
                break;

            default:
            	system("cls");
                cout << "Opcao invalida. Tente novamente!" << endl;
        }

    } while(opcao != 0);
    
	return 0;
}


void menuPesquisas(SistemaFicheiros &sistemaFicheiros)
{
	system("cls");
    int opcao;
    string nome;

    do 
	{
        cout << "\n----------------- MENU PESQUISAS -----------------" << endl;
        cout << endl;
        cout << "1 - Procurar um determinado ficheiro" << endl;
        cout << "2 - Procurar uma determinada directoria" << endl;
        cout << "3 - Listar todos os ficheiros com nome fornecido" << endl;
        cout << "4 - Listar todas as directorias com nome fornecido" << endl;
        cout << "0 - Voltar" << endl;
        cout << endl;
        cout << "Opcao pretendida: ";
        cin >> opcao;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcao)
        {
            case 1:
            	system("cls");
                cout << "Nome do ficheiro: ";
                getline(cin, nome);
                if (auto pesquisa = sistemaFicheiros.Search(nome, 0))
                {
                	cout << "Ficheiro encontrado: " << *pesquisa << endl;
				}
                else
                {
                	cout << "Nenhum ficheiro encontrado" << endl;
				}
                break;

            case 2:
            	system("cls");
                cout << "Nome da directoria: ";
                getline(cin, nome);
                if (auto pesquisa = sistemaFicheiros.Search(nome, 1))
                {
                	cout << "Directoria encontrada: " << *pesquisa << endl;
				}
                else
                {
                	cout << "Nenhuma directoria encontrada" << endl;
				}
                break;

            case 3: 
			{ //usa-se chavetas porque se declaram variaveis dentro do case
				system("cls");
                list<string> lista;
                cout << "Nome do ficheiro: ";
                getline(cin, nome);
                sistemaFicheiros.PesquisarAllFicheiros(lista, nome);
                for (auto &ficheiro : lista) 
				{
					cout << ficheiro << endl;
				}
                if (lista.empty())
				{
					cout << "Nenhum ficheiro com esse nome encontrado" << endl;
				}
                break;
            }

            case 4: 
			{
				system("cls");
                list<string> lista;
                cout << "Nome da directoria: ";
                getline(cin, nome);
                sistemaFicheiros.PesquisarAllDirectorias(lista, nome);
                for (auto &directoria : lista)
                {
                	cout << directoria << endl;
				}
                if (lista.empty()) 
				{
					cout << "Nenhuma directoria com esse nome encontrada" << endl;
				}
                break;
            }
        }

    } while(opcao != 0);
}


void menuEstatisticas(SistemaFicheiros &sistemaFicheiros)
{
	system("cls");
    int opcao;
    do 
	{
        cout << "\n-------------- MENU ESTATISTICAS --------------" << endl;
        cout << endl;
        cout << "1 - Contar o numero de ficheiros" << endl;
        cout << "2 - Contar o numero de diretorias" << endl;
        cout << "3 - Memoria total ocupada" << endl;
        cout << "4 - Directoria com mais elementos" << endl;
        cout << "5 - Directoria com menos elementos" << endl;
        cout << "6 - Ficheiro maior (o que ocupa mais espaco)" << endl;
        cout << "7 - Directoria com mais espaco (que ocupa mais)" << endl;
        cout << "0 - Voltar" << endl;
        cout << endl;
        cout << "Opcao pretendida: ";
        cin >> opcao;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcao)
        {
            case 1:
            	system("cls");
                cout << "Numero total de ficheiros: " << sistemaFicheiros.ContarFicheiros() << endl;
                break;

            case 2:
            	system("cls");
                cout << "Numero total de directorias: " << sistemaFicheiros.ContarDirectorias() << endl;
                break;

            case 3:
            	system("cls");
                cout << "Memoria total ocupada: " << sistemaFicheiros.Memoria() << " bytes" << endl;
                break;

            case 4:
            	system("cls");
                if (auto directoria = sistemaFicheiros.DirectoriaMaisElementos())
                {
                	cout << "Directoria com mais elementos: " << *directoria << endl;
				}
                else
				{
					cout << "Nenhuma directoria encontrada" << endl;
				} 
                break;

            case 5:
            	system("cls");
                if (auto directoria = sistemaFicheiros.DirectoriaMenosElementos())
                {
                	cout << "Directoria com menos elementos: " << *directoria << endl;
				}
                else
				{
					cout << "Nenhuma directoria encontrada" << endl;
				} 
                break;

            case 6:
            	system("cls");
                if (auto ficheiro = sistemaFicheiros.FicheiroMaior())
                {
                	cout << "Ficheiro maior (que ocupa mais espaco): " << *ficheiro << endl;
				}
                else
				{ 
					cout << "Nenhum ficheiro encontrado" << endl;
				}
                break;

            case 7:
            	system("cls");
                if (auto directoria = sistemaFicheiros.DirectoriaMaisEspaco())
                {
                	cout << "Directoria maior (que ocupa mais espaco): " << *directoria << endl;
				}
                else
				{
					cout << "Nenhuma directoria encontrada" << endl;
				}
                break;
        }

    } while(opcao != 0);
}


void menuOperacoes(SistemaFicheiros &sistemaFicheiros)
{
	system("cls");
    int opcao;
    string string1, string2;

    do 
	{
        cout << "\n-------------- MENU OUTRAS OPERACOES  --------------" << endl;
        cout << endl;
        cout << "1 - Remover todos os ficheiros" << endl;
        cout << "2 - Remover todas as diretorias" << endl;
        cout << "3 - Mover ficheiro para directoria desejada" << endl;
        cout << "4 - Mover diretoria para outra desejada" << endl;
        cout << "5 - Renomear ficheiro" << endl;
        cout << "6 - Verificar ficheiros duplicados (mesmo nome)" << endl;
        cout << "7 - Gravar Sistema de Ficheiros em XML" << endl;
        cout << "8 - Ler o Sistema de Ficheiro atraves do ficheiro XML" << endl;
        cout << "9 - Data de criacao um ficheiro" << endl;
        cout << "10 - Copy batch" << endl;
        cout << "0 - Voltar" << endl;
        cout << endl;
        cout << "Opcao pretendida: ";
        cin >> opcao;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcao)
        {
            case 1:
            	system("cls");
                sistemaFicheiros.RemoverAll("", "FILE");
                cout << "Todos os ficheiros foram removidos com sucesso!" << endl;
                break;

            case 2:
            	system("cls");
                sistemaFicheiros.RemoverAll("", "DIR");
                cout << "Todas as directorias foram removidas com sucesso!" << endl;
                break;

            case 3:
            	system("cls");
                cout << "Nome do ficheiro que pretende mover: ";
                getline(cin, string1);
                cout << "Directoria de destino desse ficheiro: ";
                getline(cin, string2);
                if (sistemaFicheiros.MoveFicheiro(string1, string2))
                {
                   cout << "Ficheiro movido com sucesso!" << endl;
                }
                else
                {
                   cout << "Nao foi possivel mover o ficheiro" << endl;
                }
                break;

            case 4:
            	system("cls");
                cout << "Nome da directoria que pretende mover: ";
                getline(cin, string1);
                cout << "Directoria de destino: ";
                getline(cin, string2);
                if (sistemaFicheiros.MoverDirectoria(string1, string2))
                {
                	cout << "Directoria movida com sucesso!" << endl;
				}
				else
				{
					cout << "Nao foi possivel mover a directoria" << endl;
				}
                break;

            case 5:
            	system("cls");
                cout << "Nome do ficheiro que quer renomear: ";
                getline(cin, string1);
                cout << "Novo nome: ";
                getline(cin, string2);
                sistemaFicheiros.RenomearFicheiros(string1, string2);
                cout << "Ficheiro renomeado com sucesso!" << endl;
                break;

            case 6:
            	system("cls");
                if(sistemaFicheiros.FicheiroDuplicados())
                {
                	cout << "Existem ficheiros duplicados neste Sistema de Ficheiros" << endl;
				}
				else
				{
					cout << "Nao existem ficheiros duplicados neste Sistema de Ficheiros" << endl;
				}
                break;
            
			case 7:
                system("cls");
                cout << "Nome do ficheiro XML para gravar: ";
                getline(cin, string1);
                sistemaFicheiros.Escrever_XML(string1);
                break;

            case 8:
                system("cls");
                cout << "Nome do ficheiro XML para ler: ";
                getline(cin, string1);
                if (sistemaFicheiros.Ler_XML(string1))
                {
                	cout << "Sistema carregado corretamente pelo XML!" << endl;
			    }
                else
                {
                	cout << "Falha ao carregar sistema do XML." << endl;
				}
                break;

            case 9:
            	{
                system("cls");
                cout << "Nome do ficheiro que pretende saber a data: ";
                getline(cin, string1);
                string data = sistemaFicheiros.DataFicheiro(string1);
                if (data != "NULL")
                {
                	cout << "Data do ficheiro: " << data << endl;
				}
                else
                {
                	cout << "Ficheiro nao encontrado." << endl;
				}
				}
                break;
                
            case 10:
            	{
                    system("cls");
                    string padrao, DirOrigem, DirDestino;
                    cout << "Introduza o padrao para copiar (ex: parte do nome do ficheiro): ";
                    getline(cin, padrao);
                    cout << "Directoria de origem: ";
                    getline(cin, DirOrigem);
                    cout << "Directoria de destino: ";
                    getline(cin, DirDestino);
                    if (sistemaFicheiros.CopyBatch(padrao, DirOrigem, DirDestino))
                    {
                        cout << "Ficheiros copiados com sucesso!" << endl;
                    }
                    else
                    {
                        cout << "Falha ao copiar ficheiros" << endl;
                    }
                }
                break;
        }

    } while(opcao != 0);
}