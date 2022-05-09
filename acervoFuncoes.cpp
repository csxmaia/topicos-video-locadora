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
	cin.ignore();
	getline(cin, acervo.titulo);

	cout << "Genero: ";
	getline(cin, acervo.genero);

	cout << "Valor: ";
	cin >> acervo.valor;

	acervo.locado = 0;
	
	listAcervos.push_back(acervo);
}

void alterarItem(list<Acervo>& listAcervos){
	int id;
	char opcao;
	bool run = 1;
	list<Acervo>::iterator it;
	
	cout << "Informe o ID do item que deseja alterar: ";
	cin >> id;
	cout << endl;
	
	for(it = listAcervos.begin(); it != listAcervos.end(); it++){
		if(it -> id == id){
			cout << "O item que voce est� alterando �: ";
			cout << it-> titulo;
			
			
			while(run){
				cout<<"\n\nMenu de altera��es de itens" << endl;
				cout<<"0 - Finalizar altera��o e voltar"<< endl;
				cout<<"1 - Alterar titulo do Acervo"<< endl;
				cout<<"2 - Alterar genero do Acervo"<< endl;
				cout<<"3 - Alterar valor do Acervo"<< endl;
				cin >> opcao;
				
				if (opcao == '1') {
					cout << "Informe o novo TITULO: ";
					cin.ignore();
					getline(cin, it->titulo);

				} else if (opcao == '2') {
					cout << "Informe o novo GENERO: ";
					cin.ignore();
					getline(cin, it->genero);

				} else if (opcao == '3') {
					cout << "Informe o novo VALOR: ";
					cin >> it -> valor;
				} else if (opcao == '0') {
					run = 0;
				}
			}
			
			break;
		}
	}
}

void excluirItem(list<Acervo>& listAcervos){
	int id;
	cout << "Informe o id do item que deseja remover" << endl;
	cin >> id;
	
	list<Acervo>::iterator it;
	for(it = listAcervos.begin(); it != listAcervos.end(); it++)
	{
		if(it->id == id) {
			listAcervos.erase(it);
			break;
		}
	}
	
	cout << "Item removido com sucesso!";
}

void listarItens(list<Acervo>& listAcervos){
	list<Acervo>::iterator it;
	for(it = listAcervos.begin(); it != listAcervos.end(); it++)
	{
		cout << "id: " << it->id << "\n"
	    << "titulo: " << it->titulo << "\n"
	    << "genero: "<< it->genero << "\n"
	    << "valor: R$"<< it->valor << "\n"
	    << "locado: "<< it->locado << "\n"
	    << endl;
	}

}

Acervo* buscarItemPorId(int& id, list<Acervo>& listAcervos)
{
	Acervo *item;
	list<Acervo>::iterator it;
	for(it = listAcervos.begin(); it != listAcervos.end(); it++)
	{
		if(it -> id == id)
		{
			item = &(*it);
			break;
		}
		
	}
	return item;
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
				alterarItem(listAcervos);
				break;
			case 3:
				excluirItem(listAcervos);
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

