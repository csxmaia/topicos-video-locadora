#include <iostream>
#include "clienteFuncoes.h"

using namespace std;

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
			case 1:
				cout << "Cliente";
				menuCliente();
				break;
			case 2:
				cout << "Acervo";
				break;
			case 3:
				cout << "Locacao";
				break;
			default: 
				cout << "Op��o inexistente";
		}
	}
	return 0;
}