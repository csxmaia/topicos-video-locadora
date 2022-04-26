#include "clienteFuncoes.h"
#include <iostream>
#include <list>

using namespace std;


void adicionarCliente(list<Cliente>& listCliente){
	cout << "adicionarCliente\n\n";
	Cliente cliente;
	cout << "Nome do Cliente: ";
	cin >> cli.nomeCliente;
	cout << "Idade do Cliente: ";
	cin >> cli.idade;
	
	listCliente.push_back(cliente);
}

void alterarCliente(){
	cout << "alterarCliente\n\n";
}

void excluirCliente(){
	cout << "excluirCliente\n\n";
}

void visualizarClientes(){
	cout << "visualizarClientes\n\n";
}

void menuCliente(list<int>& listCliente){
	int run = 1;
	char opcao = 'x';
	while(run){	
		listCliente.push_back( 10 );
	  	listCliente.push_back( 11 );
		cout << "Menu de Clientes" << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar um novo cliente" << endl;
		cout << "2 - Alterar dados de um cliente" << endl;
		cout << "3 - Remover um cliente" << endl;
		cout << "4 - Listar TODOS clientes" << endl;
		cin >> opcao;
		
		int iopcao = opcao - '0';
		
		switch(iopcao) {
			case 0:
				run = 0;
				break;
			case 1:
				adicionarCliente();
				break;
			case 2:
				alterarCliente();
				break;
			case 3:
				excluirCliente();
				break;
			case 4:
				visualizarClientes();
				break;	
			default: 
				cout << "Opcao inexistente";
				break;
		}
	}
}

