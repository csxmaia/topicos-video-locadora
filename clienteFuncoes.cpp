#include <iostream>


void menuCliente (char *opcao){
	while(opcao != '0' &&
			opcao != '1' &&
			opcao != '2' &&
			opcao != '3' &&
			opcao != '4' &&
			opcao != '5' &&){
			cout << "Menu de Clientes" << endl;
			cout << "1 - Adicionar um novo cliente" << endl;
			cout << "2 - Alterar dados de um cliente" << endl;
			cout << "3 - Remover um cliente" << endl;
			cout << "4 - Listar TODOS clientes" << endl;
			cin >> *opcao;		
}


void adicionarCliente{
}

void excluirCliente{
}

void alterarCliente{
}

void visualizarClientes{
}
