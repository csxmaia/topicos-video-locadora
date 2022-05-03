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

double faturamento = 0;

int setId(list<Locacao>& listLocacoes)
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

void adicionarLocacao(list<Locacao>& listLocacoes, list<Cliente>& listClientes, list<Acervo>& listAcervos){
	cout << "Adicionar item no acervo\n\n";
	// Realizar operação de cadastrar locar mais de um item
	// Validar se o item já não está como locado

	int clienteId;
	int acervoId;
	
	Locacao locacao;
	locacao.id = setId(listLocacoes);

	cout << "ID do cliente: ";
	cin >> clienteId;
	
	locacao.cliente = buscarClientePorId(clienteId, listClientes);
	cout << "Usuario " + locacao.cliente->nomeCliente + " selecionado.\n";

	cout << "ID do Acervo: ";
	cin >> acervoId;
	
	Acervo *item;
	item = buscarItemPorId(acervoId, listAcervos);
	cout << "Item " + item->titulo + " selecionado.\n";
	
	item->locado = 1;
	locacao.valor = item->valor;
	locacao.item = item;
	
	listLocacoes.push_back(locacao);
}

void alterarLocacao(){
	cout << "alterarItem\n\n";
}

void excluirLocacao(){
	cout << "excluirCliente\n\n";
}

void visualizarItensNaoLocados(list<Acervo>& listAcervos)
{
	list<Acervo>::iterator it;
	cout << "Itens não locados: \n";
	for (it = listAcervos.begin(); it != listAcervos.end(); it++)
	{
		if(!it->locado)
		{
			cout << it->titulo << endl;
		}
	}
}

void visualizarItensLocados(list<Locacao>& listLocacoes)
{
	list<Locacao>::iterator it;
	for (it = listLocacoes.begin(); it != listLocacoes.end(); it++)
		cout << "ID: " << it->id << endl;
		cout << "Valor locacao: " << it->valor << endl;
		cout << "Cliente: " << it->cliente->nomeCliente << endl;
}

void realizarDevolucao(list<Locacao>& listLocacoes)
{
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
	
	

}

void menuLocacao(list<Locacao>& listLocacoes, list<Cliente>& listClientes, list<Acervo>& listAcervos){
	int run = 1;
	char opcao = 'x';
	while(run){	    
		cout << "Menu de Locacoes" << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar uma nova locacao" << endl;
		cout << "2 - Alterar dados de uma locacao" << endl;
		cout << "3 - Remover uma locacao" << endl;
		cout << "4 - Visualizar locacoes" << endl;
		cout << "5 - Visualizar itens nao locados" << endl;
		cout << "6 - Realizar devoluçao" << endl;
		cin >> opcao;
		
		int iopcao = opcao - '0';
		
		switch(iopcao) {
			case 0:
				run = 0;
				break;
			case 1:
				adicionarLocacao(listLocacoes, listClientes, listAcervos);
				break;
			case 2:
				alterarLocacao();
				break;
			case 3:
				excluirLocacao();
				break;
			case 4:
				visualizarItensLocados(listLocacoes);
				break;	
			case 5:
				visualizarItensNaoLocados(listAcervos);
				break;	
			case 6:
				realizarDevolucao(listLocacoes);
				break;
			default: 
				cout << "Opcao inexistente";
				break;
		}
	}
}

