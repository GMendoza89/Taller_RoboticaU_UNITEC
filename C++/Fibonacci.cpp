#include<iostream>
//#include<fstream>

int main(int argc, char** argv){

unsigned int numero_elementos, numero_presente, numero_pasado, numero_futuro,contador;
if(argc!=2){
    std::cout<<"Favor de ingresar un número: ";
 std::cin>>numero_elementos;}
else{
    numero_elementos = atoi(argv[1]);}
std::cout<<std::endl;
int fibonacci[100];

fibonacci[0] = 0;
fibonacci[1] = 1;
numero_pasado = 0;
numero_presente = 1;
contador = 1;
std::cout<<"Serie de Fibonanncy: "<<numero_pasado<<", ";
//Iniciamos ciclo de impresion
// while(contador<numero_elementos){
// std::cout<<numero_presente<<", ";               // mostramos número presente
// numero_futuro = numero_presente+numero_pasado;  // calculamos el el proximo numero futuro
// numero_pasado = numero_presente;                // guardamos el numero pasado 
// numero_presente = numero_futuro;                // guardamos nuevo número presente
// contador++;                                     // incrementamos contador
// }
std::cout<<"Serie de Fibonanncy: "<<fibonacci[0]<<", ";
while (contador<numero_elementos)
{
    std::cout<<fibonacci[contador]<<", ";
    fibonacci[contador+1] = fibonacci[contador]+fibonacci[contador-1];
    ++contador;
}

std::cout<<std::endl;
//generar con arreglo dinámico
    return 0;

}

