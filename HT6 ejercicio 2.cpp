/*EJERCICIO#2 
Realice un programa que, 
	*dado el peso, 
	*la altura, 
	*la edad y 
	*el género (M/F) 
	*de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso,
altura y edad de esta población.  
Los datos deben guardarse de forma ordenada por edad en un archivo de datos.  
Así mismo el programa debe ser capaz leer los datos del archivo y generar
un reporte con la media del peso, altura y la edad. 
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 
using namespace std;

void menu();
void poblacion();
void reporte();

void menu(){
	int p;
	do {
	
		system("CLS");
		cout<<" ----------SELECCIONAR OPCIÓN----------"<<"\n";
		cout<<" 1 - Ingresar Datos "<<"\n";
		cout<<" 2 - Reporte de Datos "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cin>> p;
		if (p==1){		
			system("CLS");
			poblacion();			
		}
		else if (p==2){		
			system("CLS");
			reporte();
		}			
		else if (p==3)
			exit (1);
		else
			break;
		
	} while(p>3);
		//cout<< "opcion incorrecta vuela a elegir una opcion valida" << endl;
		system("PAUSE");
		menu();		
}
void poblacion(){
	//Declaracion de variables
	float peso;
	float altura; 
	int edad;
	string genero;
	ofstream archivo;
	 	
	system("CLS");
	//Ingreso de datos
	cout<<"*** Ingreso de Datos de poblacion ***\n\n";
	
	
	cout<<"ingreser peso: "<<endl;
	cin>>peso;
	cin.ignore();
	
	cout<<"ingresar altura:"<<endl;
	cin>>altura;
	fflush(stdin);
	cin.ignore();
	
	cout<<"ingresar edad:"<<endl;
	cin>>edad;
	fflush(stdin);
	cin.ignore();
	
	cout<<"ingresar Genero F/M:"<<endl;
	cin>>genero;
	fflush(stdin);
	cin.ignore();
	
	//insertar datos a archivo
	try{
		archivo.open("estadistica.txt",ios::app);
		archivo<<peso<<"\t"<<altura<<"\t"<<edad<<"\t"<<genero<<endl;   //"|"
		archivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
}

void reporte(){
	//declaracion de variables
	int i,edad;
	string genero;
	float peso,altura;	
	string linea;
	float suma= 0;
	
	ifstream archivo;	
	try{
		archivo.open("estadistica.txt",ios::in);	
		cout<<"Datos del archivo:"<<endl;
		cout<<"peso"<<" altura    |"<<"edad|"<<"genero"<<endl;		
		while (archivo>>peso>>altura>>edad>>genero){
			cout<<setw(5)<<peso<<"|"<<setw(5)<<altura<<setw(5)<<edad<<"|"<<setw(5)<<genero<<"|"<<endl;
			i++;					
			suma+=peso;
		}	
		archivo.close();	
		
		cout<<"\nPromedio Global: "<<suma/i<<endl;
		//cout<<"ID de Nota Mas Alta: "<<setw(3)<<mayorid<<" - Nota Mas alta: "<<setw(3)<<mayornota<<endl;
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	

}
int main(){
	menu ();
	
}
