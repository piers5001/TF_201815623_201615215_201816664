#include"Table.h"
#include <fstream>
#include<stdlib.h>
#include <string.h>
//#include "ArbolAVL.h"





void menu(int* option) {
	do {
		system("Cls");
		Console::ForegroundColor = ConsoleColor::Cyan;
		cout << "\t\t\t\t\t\t\t TABLA" << endl << endl << endl;
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "1.- \tCreacion de Tabla" << endl;
		cout << "2.- \tDibujar tabla" << endl;
		cout << "3.- \tInsercion de Registros" << endl;
		cout << "4.- \tSeleccion de datos por columna" << endl; //arbol
		cout << "5.- \tIndexado de datos por columna" << endl;  //arbol
		cout << "6.- \tFiltrado de datos por columna" << endl; //arbol
		cout << "7.- \tOrdenamiento de datos por columna" << endl; //arbol
		cout << "8.- \tExportacion de datos  a archivos planos " << endl; //arbol
		cout << "0.- \tSalir" << endl << endl;
		Console::ForegroundColor = ConsoleColor::DarkYellow;
		cout << "Ingrese su opcion: ";
		Console::ForegroundColor = ConsoleColor::DarkRed;
		cin >> *option;
	} while ((*option < 0 || *option > 9));
}



//void setIntRow(Table* tabla, string nombreColumna, int dato) {
//	tabla->getColumnsMap()[nombreColumna]->addInt(dato);
//}
//
//void setStringRow(Table* tabla, string nombreColumna, string dato) {
//	tabla->getColumnsMap()[nombreColumna]->addStr(dato);
//}
//
//void setFloatRow(Table* tabla, string nombreColumna, float dato) {
//	tabla->getColumnsMap()[nombreColumna]->addFloat(dato);
//}



int main() {

	//ejemplo int my_vector1[10];
	//AVLBST<Column*, int, NULL>* ArbolAVLString = new AVLBST<Column*, int, NULL>();
	//AVLBST<Column*, string, nullptr>* ArbolAVLString = new AVLBST<Column*, string, nullptr>();
	Column* col;/* vector<Column>* Vcol;*/ Table* tabla = new Table();
	int NumTipoDato = 0; string TipoDato = "";  int tipo = 0;
	int elem_int = 0; string elem_str = ""; float elem_float = 0.0;
	int cantCol = 0; int cant_elem = 0; string nombreIndex = "";
	string nameCol = "";
	int contadorFila = 1;
	int* op = new int();
	int repetidor = 0;
	ifstream archivo;
	ifstream archivocopia;
	ofstream archivoguardar;
	const string narchivo = "Prueba.txt";
	const string narchivoguardar = "PruebaCopia.txt";
	string texto;
	string textocopia;
	char letra;
	FILE* borrar;

	do {
		menu(op);
		switch (*op)
		{
		case 1:
			system("Cls");
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "Ingrese el numero de columnas para su tabla: ";
			Console::ForegroundColor = ConsoleColor::DarkRed;
			cin >> cantCol; cout << endl;
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "Ingrese los tipos de datos que se registraran en sus columnas: "; cout << endl;
			for (int i = 0; i < cantCol; ++i) {
				system("Cls");
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << "El tipo de dato de la Columna numero " << i + 1 << " es: " << endl;
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << "(1) Texto" << endl;
				cout << "(2) Numero entero" << endl;
				cout << "(3) Numero decimal" << endl;
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << "Ingrese el Numero correspondiente al tipo de dato que desee: ";
				Console::ForegroundColor = ConsoleColor::DarkRed;
				cin >> NumTipoDato; cout << endl;
				if (NumTipoDato == 1) TipoDato = "string";
				if (NumTipoDato == 2) TipoDato = "int";
				if (NumTipoDato == 3) TipoDato = "float";
				system("Cls");
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << "Ingrese el Nombre de la Columna " << i + 1 << " : ";
				Console::ForegroundColor = ConsoleColor::DarkRed;
				cin >> nameCol; cout << endl;
				if (i == 0) {
					system("Cls");
					Console::ForegroundColor = ConsoleColor::Cyan;
					cout << "Ingrese la cantidad de elementos de la Columna: "; //definir numero de elementos que van a tener todas las columnas
					Console::ForegroundColor = ConsoleColor::DarkRed;
					cin >> cant_elem; cout << endl;
				}
				col = new Column(nameCol, TipoDato, cant_elem);

				if (TipoDato == "string") {
					system("Cls");
					Console::ForegroundColor = ConsoleColor::Cyan;
					cout << "Ingrese los datos de su columna " << nameCol << " :" << endl;
					for (int j = 0; j < cant_elem; ++j) {
						Console::ForegroundColor = ConsoleColor::Yellow;
						cout << "Elemento " << j + 1 << ": ";
						Console::ForegroundColor = ConsoleColor::DarkRed;
						cin >> elem_str;
						col->addStr(elem_str);

					}
				}
				if (TipoDato == "int") {
					system("Cls");
					Console::ForegroundColor = ConsoleColor::Cyan;
					cout << "Ingrese los datos de su columna " << nameCol << " :" << endl;
					for (int j = 0; j < cant_elem; ++j) {
						Console::ForegroundColor = ConsoleColor::Yellow;
						cout << "Elemento " << j + 1 << ":" << endl;
						Console::ForegroundColor = ConsoleColor::DarkRed;
						cin >> elem_int;
						col->addInt(elem_int);

					}
				}
				if (TipoDato == "float") {
					system("Cls");
					Console::ForegroundColor = ConsoleColor::Cyan;
					cout << "Ingrese los datos de su columna " << nameCol << " :" << endl;
					for (int j = 0; j < cant_elem; ++j) {
						Console::ForegroundColor = ConsoleColor::Yellow;
						cout << "Elemento " << j + 1 << ":" << endl;
						Console::ForegroundColor = ConsoleColor::DarkRed;
						cin >> elem_float;
						col->addFloat(elem_float);

					}

				}
				tabla->addColumn(col);
			}
			break;
		case 2:
			tabla->DrawTable();
			system("pause");
			break;
		case 3: tabla->addRow();
			system("pause");
			break;
		case 4://cout << "Ingrese el nombre de la columna: "; string nombc; cin >> nombc; cout << endl;


			//tabla->buscarElementoXColumna(nombc);
			break;
		case 5:
			cout << "Ingrese el nombre de la columna que desea indexar: ";
			cin >> nombreIndex;
			tabla->indexar(nombreIndex);
			//tabla->indexar(nombreIndex,tabla->getColumns()->at(0));
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			borrar = fopen("Prueba.txt", "w");
			fclose(borrar);
			remove("Prueba.txt");
			tabla->DrawTableTXT();
			archivo.open("Prueba.txt", ios::in);
			archivocopia.open("PruebaCopia.txt", ios::in);
			while (!archivocopia.eof())
			{
				getline(archivocopia, textocopia);
				cout << textocopia << endl;
			}
			while (!archivo.eof())
			{
				getline(archivo, texto);
				cout << texto << endl;
			}
			archivo.close();
			archivocopia.close();
			system("pause");
			break;
		case 0: repetidor = 1;
			break;
		}



	} while (repetidor != 1);



	cin.get();
	return 0;
}