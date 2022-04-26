#ifndef acervo_classe_h
#define acervo_classe_h

#include <iostream>
#include <string>


	typedef struct acervo 
	{
		int id;
		std::string titulo;
		std::string genero;
		double valor;
		bool locado;
	}	Acervo;

#endif
