#include "locacaoFuncoes.h"
#include "locacao.h"
#include "clienteFuncoes.h"
#include "cliente.h"
#include "acervoFuncoes.h"
#include "acervo.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

extern list<Cliente> listClientes;
extern list<Acervo> listAcervos;
extern list<Locacao> listLocacoes;

double faturamento = 0;

int setIdLocacao()
{
  if(listLocacoes.size() != 0) {
	  list<Locacao>::iterator it;
	  int novoId = 1;
	  for (it = listLocacoes.begin(); it != listLocacoes.end(); it++)
	  {
	    if(it->id >= novoId)
		{
			novoId = it->id;
		}
	  }
	  return novoId+1;
  }
  return 1;
}

void adicionarLocacao(){
	cout << "Adicionar nova LOCACAO\n\n";
	// Realizar operação de cadastrar locar mais de um item
	// Validar se o item já não está como locado

	int clienteId;
	int acervoId;
	
	Locacao locacao;
	locacao.id = setIdLocacao();

	cout << "ID do cliente: ";
	cin >> clienteId;
	
	locacao.cliente = buscarClientePorId(clienteId);
	
	//while - pede cliente, enquantro nao eoncntra, pede o cliente
	//altera variavel de controle do whileai para o whiel
	
	if (!locacao.cliente == 0x0) {
	    cout << "Usuario " + locacao.cliente->nomeCliente + " selecionado.\n";

        cout << "ID do Acervo: ";
        cin >> acervoId;

        Acervo *item;
        item = buscarItemPorId(acervoId);
        cout << "Item " + item->titulo + " selecionado.\n";

        item->locado = 1;
        locacao.valor = item->valor;
        locacao.item = item;

        listLocacoes.push_back(locacao);
	} else {
		cout << "Cliente nao encontrado\n";
	}
}

void alterarLocacao(){
	cout << "alterarItem\n\n";
}

void excluirLocacao(){
	cout << "excluirCliente\n\n";
}

void visualizarItensNaoLocados()
{
	list<Acervo>::iterator it;
	cout << "Itens nao locados: \n";
	for (it = listAcervos.begin(); it != listAcervos.end(); it++)
	{
		if(!it->locado)
		{
			cout << it->titulo << endl;
		}
	}
}

void visualizarItensLocados()
{
	list<Locacao>::iterator it;
	for (it = listLocacoes.begin(); it != listLocacoes.end(); it++)
		cout << "ID: " << it->id
		<< "\nValor locacao: " << it->valor
		<< "\nCliente: " << it->cliente->nomeCliente << endl;
}

void realizarDevolucao()
{
	int locacaoId;

	cout << "ID da Locação: ";
	cin >> locacaoId;

	list<Locacao>::iterator it;
	for(it = listLocacoes.begin(); it != listLocacoes.end(); it++)
	{
		if(it->id == locacaoId) {
			faturamento += it->item->valor;
			it->item->locado = 0;
			listLocacoes.erase(it);
			break;
		}
	}

	cout << "Faturamento: "<< faturamento;
	
}

void mostrarFaturamento(){
	cout << "\n" << "Faturamento da locadora: R$" << faturamento << "\n";
}

void menuLocacao(){
	int run = 1;
	char opcao = 'x';
	while(run){	    
		cout << "Menu de LOCACOES" << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar uma nova locacao" << endl;
		cout << "2 - Visualizar locacoes" << endl;
		cout << "3 - Visualizar itens nao locados (disponiveis)" << endl;
		cout << "4 - Realizar devolucao" << endl;
		cout << "5 - Mostrar faturamento" << endl;
		cin >> opcao;
		
		int iopcao = opcao - '0';
		
		switch(iopcao) {
			case 0:
				run = 0;
				break;
			case 1:
				adicionarLocacao();
				break;
			case 2:
			    visualizarItensLocados();
				break;
			case 3:
				visualizarItensNaoLocados();
				break;
			case 4:
				realizarDevolucao();
				break;	
			case 5:
				mostrarFaturamento();
				break;	
			default: 
				cout << "Opcao inexistente";
				break;
		}
	}
}
