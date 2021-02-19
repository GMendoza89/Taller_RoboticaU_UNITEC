//Declaración de encabezados
#include<iostream>

//Prototipos de funcion
int suma(int A, int B);
void sumac(int A, int B);

//Variables globales

//Funcion principal
int main(){
	int A,B,E;
	float F;
	A = 100;
	B = 10;
	B /=2;
	E = (A)+(B++);
	F = E%2;	
	std::cout<<"Biemvenidos al taller de robotica "<<A<<" , "<<B<<" , "<< E << " , "<<F<<std::endl;

	if(!F!=0)
		std::cout<<"El número es impar"<<std::endl;
	else
		std::cout<<"El número es par"<<std::endl;

	return 0;
}


//Funciónes
int suma(int A, int B){

	return A+B;

}
void sumac(int A, int B){
	std::cout<< A+B<<std::endl;
}
