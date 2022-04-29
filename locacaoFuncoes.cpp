#include "locacaoFuncoes.h"
#include "locacao.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

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

void adicionarItem(list<Locacao>& listLocacoes){
	cout << "Adicionar item no acervo\n\n";
	
	Locacao locacao;
	locacao.id = setId(listLocacoes);

	cout << "ID do cliente: ";
	cin >> locacao.clienteId;

	cout << "ID do Acervo: ";
	cin >> locacao.acervoId;
	
	listLocacoes.push_back(locacao);
}

void alterarItem(){
	cout << "alterarItem\n\n";
}

void excluirItem(){
	cout << "excluirCliente\n\n";
}

void listarItens(list<Locacao>& listLocacoes){
	list<Locacao>::iterator it;
	for (it = listLocacoes.begin(); it != listLocacoes.end(); it++)
		cout << "ID: " << it->id << "\n"
	    << "ID do Cliente: " << it->clienteId << "\n"
	    << "ID do Acervo: "<< it->acervoId << "\n"
	    << endl;

}

void menuAcervo(list<Locacao>& listLocacoes){
	int run = 1;
	char opcao = 'x';
	while(run){	    
		cout << "Menu de Locacoes" << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar uma nova locacao" << endl;
		cout << "2 - Alterar dados de uma locacao" << endl;
		cout << "3 - Remover uma locacao" << endl;
		cout << "4 - Listar TODAS as locacoes" << endl;
		cin >> opcao;
		
		int iopcao = opcao - '0';
		
		switch(iopcao) {
			case 0:
				run = 0;
				break;
			case 1:
				adicionarItem(listLocacoes);
				break;
			case 2:
				alterarItem();
				break;
			case 3:
				excluirItem();
				break;
			case 4:
				listarItens(listLocacoes);
				break;	
			default: 
				cout << "Opcao inexistente";
				break;
		}
	}
}

