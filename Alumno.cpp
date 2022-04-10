#include "Persona.cpp"
#include <iostream>
using namespace std;

class Alumno : Persona {
	
	private: int codigo, telefono;
	
	public: 
	Alumno  (){
	}
	
	Alumno (string nom, string ape, string cur, int cod, int t) : Persona (nom, ape, cur)
	{
		codigo = cod;
		telefono = t;
		
	}

};