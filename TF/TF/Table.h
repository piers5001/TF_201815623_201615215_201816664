#pragma once

#include "Column.h"
#include "ArbolAVL.h"
#include <fstream>
#include<stdlib.h>

class Table
{
private:

	vector<Column*>* columns;
	map<string, Column*> columnsMap;

	int key;

public:
	function<string(Column*)>k1 = [&](Column* col) {
		return col->getString(key);
	};
	AVLBST<Column*, string, nullptr>* arbol = new AVLBST<Column*, string, nullptr>(k1); //objeto arbol con template


	Table() :key(0) {
		//ArbolAVLString = new AVLBST<string, string, NULL>();
		columns = new vector<Column*>();
		columnsMap = map<string, Column*>();//no se si esta bien inicializado
	}
	~Table() {}

	map<string, Column*> getColumnsMap() {
		return columnsMap;
	}

	vector<Column*>* getColumns() {
		return columns;
	}



	void createTable(int* tipoDato, int  cantCol) {



	}


	void indexar(string nombreColumna) {

		for (int i = 0; i < columns->size(); i++) {
			if (nombreColumna == columns->at(i)->get_name()) {
				key = i; break;//optiene posic
			}

		}
		//opcional
		auto k1 = [&](Column col) {
			return col.getString(key);//string del vector q esta en columna
		};

		for (int i = 0; i < columns->size(); i++)
		{
			arbol->add(columns->at(i));
		}

	}

	//el nombre del arbolIndexadoseGuarda

	//void Ordenar() {
	//	for (int i = 0; i < columns->size(); i++)
	//	{
	//		if (columns->at(i)->get_estaIndexado()) {
	//
	//		}
	//			arbol->inOrder(columns->at(i));
	//
	//	}
	//}


	//	void indexar(string nombreColumna  elem) {
	//
	//		arboles[nombreColumna] = new ArbolAVLInt<string>();
	//		for(int i=0; i < columnas[nombreColumna]->datos.size();i++){
	//			arboles[nombreColumna]->add(columnas)[nombreColumna]->datos[i];
	//
	//			columnas[nombreColumna]->setIndex(true);
	//		}
			//if(columns->at(0).getTipo==""//auto k1 = [](vector<Column>* columns) { return columns->at(0).getInt(0); };auto sd = elem=ee12;//ArbolAVLIntVLBST<Cumn><Colum>2	//ArbolAVLInt->add(elem);//)


			//if (columns[nombreColumna]->getTipo() == "int") { // yes, columnas es un map.
			//	auto k = [=](Fila* fila) { return fila->getInt(nombreColumna); };
			//	//arboles[nombreColumna] = new ArbolInt(k);
			//}


			//else if (columns[nombreColumna]->getTipo() == "string") {
			//	auto k = [=](Fila* fila) { return fila->getString(nombreColumna); };
			//	//arboles[nombreColumna] = new ArbolString(k);




			//} // Así para todos los demás tipos
			//for (auto fila : *filas) {
			//	//arboles[nombreColumna]->add(fila);
			//}

		//}


	//void buscarElementoXColumna(string nombreCol) {
	//	int elemin = 0;
	//	string elemstr = " ";
	//	float elemflt = 0.0;
	//	
	//	for (int i = 0; i < columns->size(); i++) {//cant de columnas
	//		if (nombreCol == columns->at(i).get_name()) {//si el nombre coincide
	//			cout << "Esta columna contiene valores " << columns->at(i).getTipo() << endl;
	//			cout << "Ingrese el valor que desea buscar" << endl;
	//			if (if (columns->at(i).getTipo() == "int")) {
	//				cin >> elemin;
	//			}if (columns->at(i).getTipo() == "string") {
	//				cin >> elemstr;
	//			}if (columns->at(i).getTipo() == "float") {
	//				cin >> elemflt;
	//			}
	//			for (int j = 0; j < columns->at(i).cant(); ++j) {//cant elementos de la columna
	//				if (elemin == columns->at(i).getInt(j)) {
	//					cout << columns->at(i).getInt(j);
	//				}
	//				if (elemstr == columns->at(i).getString(j)) {
	//					cout << columns->at(i).getString(j);
	//				}
	//				if (elemflt == columns->at(i).getFloat(j)) {
	//					cout << columns->at(i).getFloat(j);
	//				}
	//			}
	//		}
	//	}
	//}



	//void filtradoXColumna() {
	//	//Devolver los datos que se repiten por columna y luego ordenarlo en las demás columnas
	//
	//}
	//
	//void ordenamientoXColumna() {
	//	//auto k1 = [](vector<Column>* columns) { return columns->at(0).getInt(0); };
	//	//ArbolAVLInt = new AVLBST<Column, int>(k1);
	//		//ArbolAVLInt->add(sd);
	//
	//	//for(int)
	//}

	//falta terminar
	void addColumn(Column* col) {
		columns->push_back(col);
	}




	void DrawTotalElements() {
		cout << "-----------------------------------" << endl;

		for (int i = 0; i < columns->at(0)->get_cant(); ++i) {
			for (int j = 0; j < columns->size(); ++j) {
				if (columns->at(j)->getTipo() == "string") {
					cout << "| " << columns->at(j)->getString(i) << " ";
				}
				if (columns->at(j)->getTipo() == "int") {
					cout << "| " << columns->at(j)->getInt(i) << " ";
				}
				if (columns->at(j)->getTipo() == "float") {
					cout << "| " << columns->at(j)->getFloat(i) << " ";
				}
			}
			cout << endl;
		}

	}

	void DrawTable() {

		cout << "-----------------------------------" << endl;
		for (int i = 0; i < columns->size(); ++i) {
			cout << "|  " << columns->at(i)->get_name();
		}
		cout << "   |" << endl;
		DrawTotalElements();

	}


	void addRow() {
		string word = ""; float numRac = 0.0; int enter = 0;
		for (int i = 0; i < columns->size(); i++) {
			if (columns->at(i)->getTipo() == "string") {
				cout << "Ingrese un elemeto de " << columns->at(i)->get_name() << endl;
				cin >> word;
				columns->at(i)->addStr(word);
			}
			if (columns->at(i)->getTipo() == "float") {
				cout << "Ingrese un elemeto de " << columns->at(i)->get_name() << endl;
				cin >> numRac;
				columns->at(i)->addFloat(numRac);
			}
			if (columns->at(i)->getTipo() == "int") {
				cout << "Ingrese un elemeto de " << columns->at(i)->get_name() << endl;
				cin >> enter;
				columns->at(i)->addInt(enter);
			}
		}
		columns->at(0)->changeCant();
		DrawTable();
	}

	void DrawTotalElementsTXT() {
		ofstream archivo;
		archivo.open("Prueba.txt", ios::app);
		archivo << "-----------------------------------" << endl;

		for (int i = 0; i < columns->at(0)->get_cant(); ++i) {
			for (int j = 0; j < columns->size(); ++j) {
				if (columns->at(j)->getTipo() == "string") {
					archivo << "| " << columns->at(j)->getString(i) << " ";
				}
				if (columns->at(j)->getTipo() == "int") {
					archivo << "| " << columns->at(j)->getInt(i) << " ";
				}
				if (columns->at(j)->getTipo() == "float") {
					archivo << "| " << columns->at(j)->getFloat(i) << " ";
				}
			}
			archivo << endl;
		}
	}

	void DrawTableTXT() {
		ofstream archivo;
		archivo.open("Prueba.txt", ios::app);
		archivo << "-----------------------------------" << endl;
		for (int i = 0; i < columns->size(); ++i) {
			archivo << "|  " << columns->at(i)->get_name();
		}
		archivo << "   |" << endl;
		DrawTotalElementsTXT();
		archivo.close();
	}

};


//string getStringTable(int numFila, string nombreColumna, string tipoDato) {//creo q falta inicializarlo con new
//	columns[nombreColumna] = new Column(nombreColumna, tipoDato);
//	return columns[nombreColumna]->getString(numFila);
//}










///void add_Colums(string name, vector<T>elementos) {
///	columns = new vector<Column<T>>;
///	rows = new vector<Row<T>>;
///	int can;//cantidad elementos
///	string cName;//column name
///	T vari ;//variable que dará el valor a cada elemento de la columna
///	cout << "Cuantos columnas desea ingresar: " << endl;
///	cin >> can;
///	for (int i = 0; i < can; i++) {
///		Column<T> aux;
///		cout << "Para la columna " << i + 1 << " cual sera su nombre?" << endl;
///		cin >> cName;
///		
///		aux.set_Name(cName);
///			while (true)
///			{
///				cout << "Ingrese un elemento a su columna-si ya no desea ingresar más elementos ingrese un punto ." << endl;
///				cin >> vari;
///				if (vari == ".") {
///					break;
///				}
///				aux.addElem(vari);
///			}
///	}
///	aux->addElem(elem)
///	columns.push_back(aux)
///	cout<<columns.at(0);//muestra lo q hay en el primer vector
///	
///}