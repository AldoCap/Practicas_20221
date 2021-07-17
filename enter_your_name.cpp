#include <iostream>             // Libreria de entradas y salidas
using namespace std;            // crea espacio de nombres con su libreria estandar

int main()                      // Funcion principal del programa
{
    string name;                // Declaracion de variable sin inicializacion.

    cout << "Enter your name: ";  // Funcion para salir a consola con instruccion estractor.

    cin >> name;                    // Funcion entrada e datos por consola con intruccion insertor.

    cout << "Hello " << name << endl;  // intruccion endl Salto de linea en consola

    //cin.ignore();                      // Funcion para aa
   //cin.get();

    return 0;
}
