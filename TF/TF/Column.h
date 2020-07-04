#pragma once

#include<map>
#include<vector>
#include<iostream>
#include<string>

using namespace System;
using namespace std;

class Column {
private:

	string nombre;
	string tipo;
	vector<int> intData; //1
	vector<string> strData; //2
	vector<float> floatData; //3
	int cant;
	bool estaIndexado;

public:
	Column() {

		intData = vector<int>();
		strData = vector<string>();
		floatData = vector<float>();
		estaIndexado = false;

	}
	Column(string nombre, string tipo, int cant) {

		this->nombre = nombre;
		this->tipo = tipo;
		this->cant = cant;
		//no se estan recibiendo los datos
	}

	//falta terminar destrcutor
	~Column() {}

	int get_cant() {
		return cant;
	}

	bool get_estaIndexado() {
		return estaIndexado;
	}

	void changeCant() {
		cant++;
	}
	void setName(string _name) {
		nombre = _name;
	}
	void addInt(int dato) {
		intData.push_back(dato); //1
	}

	void addFloat(float dato) {
		floatData.push_back(dato); //3
	}

	void addStr(string dato) {
		strData.push_back(dato); //2
	}

	string getTipo() {
		return tipo;
	}

	string get_name() {
		return nombre;
	}

	string getString(int i) {
		return strData[i];
	}

	int getInt(int i) {
		return intData[i];
	}
	float getFloat(int i) {
		return floatData[i];
	}

};



/*

Esto para indexar en tabla

MAP<STRING,COLUMN*> COLUMNS;

data (en este ejemplo será un vector de string)

columns["nombre"]=new Column("nombre","string");//se le da la  seccion  de  "nombre" a columns, en este caso "nombre" que es de tipo string, psdt: se pueden dar más secciones

columns["nombre"]->data.push_back("Juan");aca almacena a "Juan" en la seccion de nombres de la variable columns de tipo MAP, que es heredada por el vector data

for(auto dato: columns["nombre"]->data){//recorre el vector data el cual solo mapea la seccion de nombre que ha sido almacenado en columns, por ello mostrará el unico valor q se ha asignado que es "JUAN"
	cout<< dato <<" ";
}
cout<<endl;

*/

