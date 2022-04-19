#ifndef cliente_classe_h
#define cliente_classe_h

#include <iostream>
#include <string>


	typedef struct Cliente 
	{
		int id;
		std::string nomecliente;
		int idade;
	}	Cliente;


	void MenuCliente(char *opcao);


#endif
