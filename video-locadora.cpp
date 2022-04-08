#include <iostream>

using namespace std;

int main()
{
	int run = 1;
	char opcao = "x";
	cout << "Bem vindo ao software de gerencia de video locadoras";
	
	while(run) {
		cout << "Selecione uma opcao:";
		cout << "0 - Sair";
		cout << "1 - Realizar operacoes com cliente";
		cout << "2 - Realizar operacoes com o acervo";
		cout << "3 - Realizar operacoes de locacao";
		cin >> opcao;
	}
	return 0;
}
