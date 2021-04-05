//Declaración de encabezados
#include<iostream>
#include<string>
//Prototipos de funcion
int suma(int A, int B);
void sumac(int A, int B);
using namespace std;

//Variables globales

struct Punto
{
	int x;
	int y;
	float radio;
	char nombre[20];
};




//Funcion principal
int main(){
	Punto A;
	
	A.x = 0;
	A.y = 2;
	A.radio = 3.82;
	//A.nombre = "abeja";
;

	std::cout<<"el punto ingresado tiene coordenadas e x "<<A.x<<", y en y ="<<A.y<<std::endl;
	int *P;
	P = &A.x;
	std::cout<<"la coordenada x esta guardada en la direccion  "<<P<<std::endl;
	
	return 0;
}


//Funciónes
int suma(int A, int B){

	return A+B;

}
void sumac(int A, int B){
	std::cout<< A+B<<std::endl;
}
