#include <list>
#include "cliente.h"
#ifndef cliente_funcoes_h
#define cliente_funcoes_h

void menuCliente(std::list<Cliente>& listClientes); 
Cliente* buscarClientePorId(int& id, std::list<Cliente>& listClientes);

#endif
