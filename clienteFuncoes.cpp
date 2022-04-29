#include "clienteFuncoes.h"
#include "cliente.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int setId(list<Cliente>& listCliente)
{
  if(listCliente.size() != 0) {
	  list<Cliente>::iterator it;
	  int novoId = 1;
	  for(it = listCliente.begin(); it != listCliente.end(); it++)
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

void adicionarCliente(list<Cliente>& listClientes){
	cout << "adicionarCliente\n\n";
	
	Cliente cliente;
	cliente.id = setId(listClientes);
	cout << "Nome do Cliente: ";
	cin >> cliente.nomeCliente;
	cout << "Idade do Cliente: ";
	cin >> cliente.idade;
	
	listClientes.push_back(cliente);
}

void alterarCliente(list<Cliente>& listClientes){
	cout << "alterarCliente\n\n";
	
	int id;
	char opcao;
	bool run = 1;
	list<Cliente>::iterator it;
	
	cout << "Informe o ID do cliente que deseja alterar: ";
	cin >> id;
	cout << endl;
	
	for(it = listClientes.begin(); it != listClientes.end(); it++){
		if(it -> id == id){
			cout << "O cliente que voce está alterando é: ";
			cout << it->nomeCliente;
			
			
			while(run){
				cout<<"\n\nMenu de alterações de clientes" << endl;
				cout<<"0 - Finalizar alteração"<< endl;
				cout<<"1 - Alterar nome do Cliente"<< endl;
				cout<<"2 - Alterar idade do Cliente"<< endl;
				cin >> opcao;
				
				if(opcao == '1'){
					cout << "Informe o novo NOME: ";
					cin >> it -> nomeCliente;
				}else if (opcao == '2'){
					cout << "Informe a nova IDADE: ";
					cin >> it -> idade;

				}else if (opcao == '0'){
					run = 0;
				}
			}
			
			break;
		}
	}
	
}

void excluirCliente(){
	cout << "excluirCliente\n\n";
}

void listarClientes(list<Cliente>& listClientes){
	list<Cliente>::iterator it;
	for(it = listClientes.begin(); it != listClientes.end(); it++)
	    cout << "id: " << it->id << "\n"
	    << "nome: " << it->nomeCliente << "\n"
	    << "idade: "<< it->idade
	    << endl;

}

void menuCliente(list<Cliente>& listClientes){
	int run = 1;
	char opcao = 'x';
	while(run){	    
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
				adicionarCliente(listClientes);
				break;
			case 2:
				alterarCliente(listClientes);
				break;
			case 3:
				excluirCliente();
				break;
			case 4:
				listarClientes(listClientes);
				break;	
			default: 
				cout << "Opcao inexistente";
				break;
		}
	}
}

