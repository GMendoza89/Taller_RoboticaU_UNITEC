#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char** argv){
//declaracion de variables
unsigned int numero_elementos, ext;
long unsigned int *serie_fibonacci;
char nombre[20];
std::ofstream fichero;
std::string nombre_fichero;
std::string extencion[2];
extencion[0]=".txt";
extencion[1]=".csv";
ext = 0;
//lectura de argumentos o solicitud de datos
if(argc!=4){
    std::cout<<"Favor de ingresar un número: ";
    std::cin>>numero_elementos;
    std::cout<<std::endl;
    std::cout<<"Ingresar nombre de fichero de salida: ";
    std::cin>>nombre;
    std::cout<<"Ingresar la extencion 0 - txt (por defecto) 1 - csv: ";
    std::cin>>ext;
    nombre_fichero = std::string(nombre)+extencion[0];
 }
else{
    numero_elementos = atoi(argv[1]);
    nombre_fichero = std::string(argv[2])+extencion[atoi(argv[3])];}
std::cout<<std::endl;

serie_fibonacci = new long unsigned int(numero_elementos);
fichero.open(nombre_fichero.c_str());

serie_fibonacci[0] = 0;
serie_fibonacci[1] = 1;

std::cout<<"Serie de Fibonanncy: "<<serie_fibonacci[0];
fichero<<"Serie de fibonacci\n";
fichero<<serie_fibonacci[0];

for(int i0 = 1; i0<numero_elementos-1;++i0){
    serie_fibonacci[i0+1] = serie_fibonacci[i0]+serie_fibonacci[i0-1];
    std::cout<<", "<<serie_fibonacci[i0];
    fichero<<", "<<serie_fibonacci[i0];
}
std::cout<<", "<<serie_fibonacci[numero_elementos-1];
fichero<<", "<<serie_fibonacci[numero_elementos-1];
std::cout<<std::endl;
fichero.close();
delete serie_fibonacci;
return 0;

}

