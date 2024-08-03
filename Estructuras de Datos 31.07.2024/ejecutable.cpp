/*********************************
 * Autor: Juan Carreño
 * Materia: Estructuras de datos
 * Fecha: 24 de julio de 2024
*********************************/
#include <iostream>
#include <string>
#include <math.h>
#include "biblioteca.h"

using namespace std;

int main(){
    int n = 9;
    int sumaNumeros = sumaRecursiva(n);
    int cuadradosParesRes = cuadradosPares(n);
    int cuadradosPares2Res = cuadradosPares2(n);
    int numFib = fibNumero(n);
    string palabra = "Palabra";
    char substring = 'g';
    bool caracter = lineal(palabra, substring, palabra.length()-1);
    int opcion = -1;
    
    do {
        cout << "Escoja la operacion que desea realizar: " << endl;
        cout << "1. Suma de dos numeros" << endl;
        cout << "2. Cuadrados pares - Metodo 1" << endl;
        cout << "3. Cuadrados pares - Metodo 2" << endl;
        cout << "4. Sucesion de fibonacci" << endl;
        cout << "5. Lineal" << endl;
        cout << "6. Ejemplo de Character y stack" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        
        switch(opcion){
            case 1:{
                cout << "Suma: " << sumaNumeros << endl;
                break;
            }
            case 2:{
                cout << "Cuadrados pares: " << cuadradosParesRes << endl;
                break;
            }
            case 3:{
                cout << "Cuadrados pares: " << cuadradosPares2Res << endl;
                break;
            }
            case 4:{
                cout << "Fibonacci: " << numFib << endl;
                break;
            }
            case 5:{
                cout << "Caracter encontrado: " << (lineal(palabra, substring, palabra.length()-1) ? "Sí" : "No") << endl;
                break;
            }
            case 6:{
                ejemploCharacterStack();
                break;
            }
            case 0:{
                return 0;
            }
            default:{
                cout << "Opcion invalida" << endl;
                break;
            }
        }
    } while(opcion != 0);
    
    return 0;
}
