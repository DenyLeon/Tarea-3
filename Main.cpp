#include "Alumno.cpp"
#include <iostream>
#include <stdlib.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
 
	struct Estudiante;	
	string nombre,apellido,direccion;
	int codigo, telefono;
	 	
void crear();
void leer();
void actualizar();
void borrar();
void final();

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	char direccion[100];
	int telefono;
};
void crear();
void leer();
void modificar();
void eliminar();
int main(){
	int menu;
	do{
		
		cout<<"\n 1. Nuevo";
		cout<<"\n 2. Leer";
		cout<<"\n 3. Actualizar";
		cout<<"\n 4. Borrar";
		cout<<"\n 5. Salir ";
		cout<<"\n Operacion a ejecutar: ";
		
		cin>>menu;
		system("cls");	
		
		switch(menu){
			case 1 : crear(); break;
			case 2 : leer(); break;
			case 3: modificar(); break;
			case 4: eliminar(); break;

		}
		
	}while(menu<=4);
	return 0;
	
}

void crear(){
	
	FILE* archivo = fopen(nombre_archivo, "ab");
	Estudiante estudiante;
	char continuar;
	string nombres, apellidos, direccion;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres: ";
		getline(cin,nombres);
		strcpy(estudiante.nombres, nombres.c_str());
		
			cout<<"Ingrese Apellidos: ";
		getline(cin,apellidos);
		strcpy(estudiante.apellidos, apellidos.c_str());
		
			cout<<"Ingrese Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		
		
		cout<<"Ingrese Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite(&estudiante, sizeof(Estudiante),1,archivo);
		
		cout<<"Desea ingresar otro Estudiante (s/n): ";
		cin>>continuar;
	} while((continuar=='s') || (continuar=='S'));	
	
	fclose(archivo);
	system("Pause");
}
	
void leer(){
	FILE* archivo=fopen(nombre_archivo, "rb");
	if(!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante, sizeof(Estudiante),1, archivo);
	cout<<"_________________________________________________________________________________"<<endl;
	cout<<"ID" << "|" <<"CODIGO"<< "|" <<"NOMBRES"<< "|" <<"APELLIDOS"<< "|" <<"DIRECCION"<< "|" <<"TELEFONO"<<endl;
	do{
		cout<<"_______________________________________________________________________________"<<endl;
		cout<<id<<" | "<<estudiante.codigo<<" | "<<estudiante.nombres<<" | "<<estudiante.apellidos<<" | "<<estudiante.direccion<<" | "<<estudiante.telefono<<endl;
	fread(&estudiante, sizeof(Estudiante),1,archivo);
	id+=1;
	}while(feof(archivo)==0);
}
void modificar(){
	FILE* archivo=fopen(nombre_archivo, "r+b");
	int id;
	string nombres,apellidos,direccion;
	Estudiante estudiante;
	
	cout<<"Ingrese el ID que desea Modificar: ";
	cin>> id;
	fseek(archivo, id*sizeof(Estudiante),SEEK_SET);
	
	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres: ";
		getline(cin,nombres);
		strcpy(estudiante.nombres, nombres.c_str());
		
			cout<<"Ingrese Apellidos: ";
		getline(cin,apellidos);
		strcpy(estudiante.apellidos, apellidos.c_str());
		
			cout<<"Ingrese Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		
		
		cout<<"Ingrese Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite( &estudiante, sizeof(Estudiante),1,archivo);
	fclose(archivo);
}
void eliminar(){
	FILE* archivo=fopen(nombre_archivo, "r+b");
	int id;
	Estudiante estudiante;
	string nombres,apellidos,direccion;
	cout<<"Ingrese el Id que desea Eliminar: ";
	cin>>id;
	fseek(archivo, id*sizeof(Estudiante),SEEK_SET);
	id =0;
	
	cout<<"ESTUDIANTE ELIMINADO"<<endl;
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
}