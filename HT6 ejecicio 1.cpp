/*
EJERCICIO # 1
En una librería se venden 4 modelos diferentes de cuadernos, con los siguientes precios:
 ? Modelo#1 – Q10.00 
 ? Modelo#2 – Q15.00 
 ? Modelo#3 – Q18.50 
 ? Modelo#4 – Q25.00  
Por otra parte, se tiene información sobre las ventas realizadas durante los últimos 30 días,
estos movimientos se deben de guardar en un archivo de la siguiente forma:
 DIA1,MOD,CANT 
 DIA2,MOD,CANT 
 . 
 . 
 . 
 DIA30,MODELO,CANTIDAD  
DIAi = Variable que representa el día que se efectuó la venta i (1 - 30) 
MOD= Variable que representa código de Modelo que se vendió. (1 – 4) 
CANT= Variable que representa la cantidad de unidades vendidas.  
El programa debe ser capaz de: 
? Modificar el número de unidades vendidas, solicitando al usuario el día y código de articulo (modificación del archivo) 
? Eliminación de un día especifico de venta (modificación del archivo) 
? Calcular el total recaudado por modelo en los 30 días. 
? Calcular cuál fue el modelo que se vendió mas en los 30 días 
*/


#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;
void cuadernos();
void mp();
void reporte();
void eliminar();
void modificar();


int main(){	
	mp();
	
}
void mp(){
	int resp;
	
	do {
		system("CLS");
		cout<<"-------------------------------------"<<"\n";
		cout<<"---------Menu Principal------------"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar compra "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Eliminar compra"<<"\n";
		cout<<" 4 - Modificar compra"<<"\n";
		cout<<" 5 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			cuadernos();			
		}
		else if (resp==2){		
			system("CLS");
			reporte();
		}
		else if (resp==3){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==4){
			system("CLS");
			modificar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}

void cuadernos(){
	//declaracion de variables
	int aux,aux2,cant,total;
	int dia;
	float tipo;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"*** Ingreso de Compras ***\n\n";
	cout<<"Indique dia del mes de compra: "<<endl;
	cin>>dia;
	fflush(stdin);
	cout<<"Indique cantidad de cuadernos :         "<<endl;
	cin>>cant;
	fflush(stdin);	
	cout<<"Indique el tipo de cuaderno 1-4:         "<<endl;
	cin>>aux2;
	
	if(aux2==1){
		tipo= cant*10;
	}
	else if(aux2==2){
		tipo= cant*15;
	}
	else if(aux2==3){
		tipo=cant*18.50;
	}
	else if(aux2==4){
		tipo=cant * 20;
	}
	
	
	//Insercion de datos a un archivo
	try {
		db.open("libreria.txt",ios::app);
		cout<<"Datos del archivo:"<<endl;
		cout<<" Dia|"<<" cant |"<<" total|"<<"tipo cuaderno |"<<endl;
		db<<dia<<"\t"<<cant<<"\t"<<tipo<<endl;   //"|"
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
}
void reporte(){
	//declaracion de variables
	float tipo;
	int i,dia,cant;
	float suma= 0.00;
	
	ifstream db;	
	try{
		db.open("libreria.txt",ios::in);	
		cout<<"Datos del archivo:"<<endl;
		cout<<" Dia|"<<" cant |"<<" total|"<<endl;		
		while (db>>dia>>cant>>tipo){
			cout<<setw(3)<<dia<<"|"<<setw(5)<<cant<<"|"<<setw(4)<<tipo<<"|"<<endl;
			i++;					
			suma+=tipo;
			}
		db.close();	
		cout<<"\n El total vendido durante el periodo es de:  "<<suma<<endl;
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}

void eliminar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	float tipo;
	int dia, cant,flag,aux;
	remove("Temporal.txt");
	
	db_a.open("libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"ingrese el dia que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>dia>>cant>>tipo){
		if(aux==dia){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=dia)
			db_n<<dia<<"\t"<<cant<<"\t"<<tipo<<endl;
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("libreria.txt");
		rename("Temporal.txt","libreria.txt");
	}	
	system("Pause");
}

void modificar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,dia,cant,cant2,flag;
	float tipo;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"ingrese el dia que desea modificar: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese modificacion: "<<endl;
		cin>>cant2;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>dia>>cant>>tipo){
		if(aux==dia){
			db_n<<dia<<"\t"<<cant2<<"\t"<<tipo<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=dia)
			db_n<<dia<<"\t"<<cant<<"\t"<<tipo<<endl;
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("libreria.txt");
		rename("Temporal.txt","libreria.txt");
	}	
	system("Pause");
}
