#include "clienteFuncoes.h"
#include "cliente.h"
#include "acervoFuncoes.h"
#include "acervo.h"
#include "locacaoFuncoes.h"
#include "locacao.h"
#include "util.h"
#include <iostream>
#include <list>

using namespace std;

list<Cliente> listClientes;
list<Acervo> listAcervos;
list<Locacao> listLocacoes;

int main()
{
	int run = 1;
	char opcao = 'x';
	cout << "Bem vindo ao software de gerencia de video locadoras\n\n";
	
	while(run) {
		cout << "Selecione uma opcao:\n";
		cout << "0 - Sair\n";
		cout << "1 - Realizar operacoes com cliente\n";
		cout << "2 - Realizar operacoes com o acervo\n";
		cout << "3 - Realizar operacoes de locacao\n";
		cout << "\n";
		cin >> opcao;
		
		int iopcao = opcao - '0';
		switch(iopcao) {
			case 0:
				run = 0;
			case 1:
				limparTela();
				menuCliente(listClientes);
				break;
			case 2:
				menuAcervo(listAcervos);
				cout << "Acervo";
				break;
			case 3:
				menuLocacao(listLocacoes, listClientes, listAcervos);
				cout << "Locacao";
				break;
			default: 
				cout << "Opcao inexistente";
		}
	}
	return 0;
}
