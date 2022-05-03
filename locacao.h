#ifndef locacao_classe_h
#define locacao_classe_h

#include "cliente.h"
#include "acervo.h"

#include <iostream>
#include <string>


	typedef struct Locacao 
	{
		int id;
		Cliente *cliente;
		std::list<Acervo*> itens;
		double valor;
	} Locacao;

#endif
