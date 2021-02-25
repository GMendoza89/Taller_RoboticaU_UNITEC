#include<iostream>
#include<math.h>

class Punto{

private:
    double x,y,z;

public:
    Punto();
    Punto(double X, double Y);
    Punto(double X, double Y, double Z);
    ~Punto();

    void set_X(double X);
    void set_Y(double Y);
    void set_Z(double Z);

    double get_X();
    double get_Y();
    double get_Z();

    double distancia(Punto A);

    Punto operator = (const Punto &A);
    Punto operator + (const Punto &A);



};
int main(){
    
    Punto A(4.17,6);
    Punto B(2.4,5.8,92.4);
    Punto C;
    C = A+B;



    std::cout<<"Las coordenadas del punto A son "<<C.get_X() <<","<<C.get_Y()<<","<<C.get_Z()<<std::endl;
    std::cout<<"La distancia entre los puntos A y B es de  "<<A.distancia(B)<<std::endl;


 return 0;
}



Punto::Punto(){
    x = 0;
    y = 0;
    z = 0;
}
Punto::Punto(double X, double Y){
    x = X;
    y = Y;
    z = 0;
}
Punto::Punto(double X, double Y, double Z){
    x = X;
    y = Y;
    z = Z;
}
Punto::~Punto(){

}


void Punto::set_X(double X){x = X;}
void Punto::set_Y(double Y){y = Y;}
void Punto::set_Z(double Z){z = Z;}

double Punto::get_X(){return x;}
double Punto::get_Y(){return y;}
double Punto::get_Z(){return z;}

Punto Punto::operator =(const Punto &A){
    this->x=A.x;
    this->y=A.y;
    this->z=A.z;
    return(*this);
}
Punto Punto::operator + (const Punto &A){
    
    Punto P;
    P.x = x + A.x;
    P.y = y + A.y;
    P.z = z + A.z;
    return(P);
}

double Punto::distancia(Punto A){return sqrt((A.x-x)*(A.x-x)+(A.y-y)*(A.y-y)+(A.z-z)*(A.z-z));}