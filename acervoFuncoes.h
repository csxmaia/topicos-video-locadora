#include <list>
#include "acervo.h"
#ifndef acervo_funcoes_h
#define acervo_funcoes_h

void menuAcervo(std::list<Acervo>& listAcervos); 
Acervo* buscarItemPorId(int& id, std::list<Acervo>& listAcervos);

#endif
