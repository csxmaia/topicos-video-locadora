#include <iostream>

using namespace std;


void adicionarCliente(){
	cout << "adicionarCliente\n\n";
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

void menuCliente (){
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
				cout << "voltar aqui";
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
		}
	}
}

int main() {
	menuCliente();
	return 0;
}

