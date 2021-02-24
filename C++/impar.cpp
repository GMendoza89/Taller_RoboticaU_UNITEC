#include<iostream>

int main(int argc, char** argv){

 int number;

bool par;

if(argc!=2){
    std::cout<<"Error no existe argumento  de entrada ejemplo: "<<argv[0]<<" [Número] "<<std::endl;
    return -1;}
else{
    number = atoi(argv[1]);}
 
 par = number%2;

std::cout<<std::endl;

if(!par)
    std::cout<< "el número ingresado es par"<<std::endl;
else
    std::cout<< "el número ingresado es impar"<<std::endl;

    return 0;

}