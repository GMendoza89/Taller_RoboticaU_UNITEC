#include<iostream>

int main(int argc, char** argv){

 int number;

bool impar;

 std::cout<<"Favor de ingresar un número: ";
 std::cin>>number;
 std::cout<<std::endl;
 impar = number%2;

 if(impar)
    std::cout<< "ël numero ingresado es impar"<<std::endl;
else
    std::cout<< "ël numero ingresado es par"<<std::endl;

    return 0;

}