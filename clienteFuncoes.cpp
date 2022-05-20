#include "clienteFuncoes.h"
#include "cliente.h"
#include "util.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

extern list<Cliente> listClientes;

int setIdCliente()
{

  if(listClientes.size() != 0) {
	  list<Cliente>::iterator it;
	  int novoId = 1;
	  for(it = listClientes.begin(); it != listClientes.end(); it++)
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

void adicionarCliente(){
	limparTela();
	
	cout << "---------------------" << endl;
	cout << "Menu de Clientes" << endl;
	cout << "---------------------" << endl;
	
	cout << "\nOpcao 1: Adicionar NOVO cliente\n\n";
	
	Cliente cliente;
	cliente.id = setIdCliente();
	cout << "Nome do Cliente: ";
	cin.ignore();
	getline(cin, cliente.nomeCliente);

	cout << "Idade do Cliente: ";
	cin >> cliente.idade;
	
	listClientes.push_back(cliente);
	
	limparTela();
	
	cout << "\nCliente " + cliente.nomeCliente + " adicionado.\n\n";
}

void alterarCliente(){
	int id;
	char opcao;
	bool run = 1;
	list<Cliente>::iterator it;
	
	limparTela();
	
	cout << "---------------------" << endl;
	cout << "Menu de Clientes" << endl;
	cout << "---------------------" << endl;
	
	cout << "\nOpcao 2: Alterar dados do cliente\n";
	
	cout << "\nInforme o ID do cliente que deseja alterar: ";
	cin >> id;
	cout << endl;
	
	Cliente* cliente = buscarClientePorId(id);
	
	if (!cliente == 0x0) {
		for(it = listClientes.begin(); it != listClientes.end(); it++){
			if(it -> id == id){
				limparTela();
				
				cout << "\nVoce esta alterando os dados do cliente: ";
				cout << it->nomeCliente;
				
				while(run){
					
					cout << "\n\n-------------------------------------" << endl;
					cout << "Menu de Alteracao de Dados de Cliente" << endl;
					cout << "-------------------------------------" << endl;

					cout<<"1 - Alterar nome do Cliente"<< endl;
					cout<<"2 - Alterar idade do Cliente"<< endl;
					cout<<"3 - Finalizar alteracoes e voltar"<< endl;
					
					cin >> opcao;
					
					if (opcao == '1') {
						cout << "Informe o novo NOME: ";
						cin.ignore();
						getline(cin, it -> nomeCliente);
						
						limparTela();
					} else if (opcao == '2') {
						cout << "Informe a nova IDADE: ";
						cin >> it -> idade;
						
						limparTela();
					} else if (opcao == '3') {
						limparTela();
						run = 0;
					}
				}
				
				break;	
			}
		}
	} else {
		limparTela();
		
		cout << "Cliente nao encontrado!\n\n";
	}
}

void excluirCliente(){
		
	int id;
	
	limparTela();
	
	cout << "---------------------" << endl;
	cout << "Menu de Clientes" << endl;
	cout << "---------------------" << endl;
	
	cout << "\nOpcao 3: Remover cliente\n";
	
	cout << "\nInforme o ID do cliente que deseja remover" << endl;
	cin >> id;
	
	Cliente* cliente = buscarClientePorId(id);
	
	if (!cliente == 0x0) {
		list<Cliente>::iterator it;
	for(it = listClientes.begin(); it != listClientes.end(); it++)
	{
		if(it->id == id) {
			listClientes.erase(it);
			break;
		}
	}
	
	limparTela();
	
	cout << "\nCliente removido com sucesso!\n";
	} else {
		limparTela();
		
		cout << "Cliente nao encontrado!\n\n";
	}	
}

void listarClientes(){
	
	list<Cliente>::iterator it;
	
	if (!listClientes.empty()) {
		limparTela();
		
		cout << "Listando os clientes cadastrados...\n";
		
		for(it = listClientes.begin(); it != listClientes.end(); it++) {
			cout << "\n--------------------------\n";
			cout << "id: " << it->id << "\n"
	    	<< "nome: " << it->nomeCliente << "\n"
	    	<< "idade: "<< it->idade
	    	<< endl;
	    	cout << "--------------------------\n";
		}
	} else {
		limparTela();
		cout << "\nNao existem clientes cadastrados!\n";
	}
}

Cliente* buscarClientePorId(int& id)
{
	Cliente *cliente = 0x0;
	
	list<Cliente>::iterator it;
	for(it = listClientes.begin(); it != listClientes.end(); it++)
	{
		if(it -> id == id)
		{
			cliente = &(*it);
			break;
		}
		
	}
	return cliente;
}




void menuCliente(){
	int run = 1;
	char opcao = 'x';
	while(run){	    
		cout << "---------------------" << endl;
		cout << "Menu de Clientes" << endl;
		cout << "---------------------" << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar um novo cliente" << endl;
		cout << "2 - Alterar dados de um cliente" << endl;
		cout << "3 - Remover um cliente" << endl;
		cout << "4 - Listar TODOS clientes\n" << endl;
		cin >> opcao;
		
		int iopcao = opcao - '0';
		
		switch(iopcao) {
			case 0:
				limparTela();
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
				listarClientes();
				break;	
			case 5:
				limparTela();
				break;	
			default: 
				cout << "Opcao inexistente";
				break;
		}
	}
}


