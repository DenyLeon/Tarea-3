#include <iostream>
using namespace std;
class Persona{
	
	protected : string nombre, apellido, direccion;
				
				
	protected :
		Persona(){
		}
		Persona (string nom, string ape, string dir){
			nombre = nom;
			apellido = ape;
			direccion = dir;
		
		}	
		
		
		void mostrar(); 		
};