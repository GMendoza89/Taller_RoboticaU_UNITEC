#include<iostream>

int main(){
    int contador;
    int A, B;

    contador = 1;

    A =-1;
    B= 2;
    bool C;
    C = true;
    while(C){

        switch (A)
    {
    case 1:
        std::cout<<"Ël valor de A es 1"<<std::endl;
        ++A;
        break;
    case 2:
        std::cout<<"Ël valor de A es 2"<<std::endl;
        ++A;
        break;
    case 3:
        std::cout<<"Ël valor de A es 3"<<std::endl;
        ++A;
        C = false;
        break;    
    default: 
        std::cout<<"Valor no valido"<<std::endl;
        ++A;
        break;
    }

        //A+=B;
        //std::cout<<"Suma igual a: "<<A<<std::endl;

        // if(A>20){
        //     std::cout<<"Suma paso el valor de 20 A iagual a: "<<A<<std::endl;
        //     if(A>30)
        //         C=false;
        // }

    }

    

    

    // do{

    //     std::cout<<"contador igual a: "<<contador<<std::endl;
    //     ++contador;

    // }while(contador<10);
    // std::cout<<"contador igual a: "<<contador<<std::endl;

    // for(int i=5;i > 0;i-=2){
    //     std::cout<<"contador igual a: "<<i<<std::endl;

    // }

    return 0;
}