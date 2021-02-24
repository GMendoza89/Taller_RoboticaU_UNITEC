#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char** argv){
//declaracion de variables
unsigned int numero_elementos, ext;
long unsigned int *serie_fibonacci;
std::ofstream fichero;
std::string nombre_fichero;
std::string extencion[2];
extencion[0]=".txt";
extencion[1]=".csv";
ext = 0;

//lectura de argumentos o solicitud de datos
if(argc == 2){
    numero_elementos = atoi(argv[1]);
}else if(argc == 3){
    numero_elementos = atoi(argv[1]);
    nombre_fichero = std::string(argv[2])+extencion[0];
}else if (argc == 4){
    numero_elementos = atoi(argv[1]);
    nombre_fichero = std::string(argv[2])+extencion[atoi(argv[3])];
}else
{
    std::cout<<"Favor de ingresar un número: ";
    std::cin>>numero_elementos;
    std::cout<<std::endl;
    nombre_fichero = "fibonacci"+extencion[0];
}


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

