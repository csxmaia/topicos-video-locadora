#include "acervoFuncoes.h"
#include "acervo.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int setId(list<Acervo>& listAcervos)
{
  if(listAcervos.size() != 0) {
	  list<Acervo>::iterator it;
	  int novoId = 1;
	  for(it = listAcervos.begin(); it != listAcervos.end(); it++)
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

void adicionarItem(list<Acervo>& listAcervos){
	cout << "Adicionar item no acervo\n\n";
	
	Acervo acervo;
	acervo.id = setId(listAcervos);
	cout << "Titulo: ";
	cin >> acervo.titulo;
	cout << "Genero: ";
	cin >> acervo.genero;
	cout << "Valor: ";
	cin >> acervo.genero;
	acervo.locado = 0;
	
	listAcervos.push_back(acervo);
}

void alterarItem(){
	cout << "alterarItem\n\n";
}

void excluirItem(){
	cout << "excluirCliente\n\n";
}

void listarItens(list<Acervo>& listAcervos){
	list<Acervo>::iterator it;
	for(it = listAcervos.begin(); it != listAcervos.end(); it++)
	    cout << "id: " << it->id << "\n"
	    << "titulo: " << it->titulo << "\n"
	    << "genero: "<< it->genero << "\n"
	    << "valor: R$"<< it->valor << "\n"
	    << "locado: "<< it->locado << "\n"
	    << endl;

}

void menuAcervo(list<Acervo>& listAcervos){
	int run = 1;
	char opcao = 'x';
	while(run){	    
		cout << "Menu de Acervo" << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar um novo item" << endl;
		cout << "2 - Alterar dados de um item" << endl;
		cout << "3 - Remover um item" << endl;
		cout << "4 - Listar TODOS os itens" << endl;
		cin >> opcao;
		
		int iopcao = opcao - '0';
		
		switch(iopcao) {
			case 0:
				run = 0;
				break;
			case 1:
				adicionarItem(listAcervos);
				break;
			case 2:
				alterarItem();
				break;
			case 3:
				excluirItem();
				break;
			case 4:
				listarItens(listAcervos);
				break;	
			default: 
				cout << "Opcao inexistente";
				break;
		}
	}
}

