/*********************************
 * Autor: Juan Carreño
 * Materia: Estructuras de datos
 * Fecha: 24 de julio de 2024
*********************************/
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int sumaRecursiva(int n){
	if(n <= 1) {
		return n;
	}
	else{
		return n + sumaRecursiva(n-1);
	}
}

int cuadradosPares(int n){
	if(n == 0){
		return n;
	}
	else if(n % 2 == 0) {
		return n*n + cuadradosPares(n-1);
	} else {
		return cuadradosPares(n - 1);
	}
}

int cuadradosPares2(int n){
	if(n == 0){
		return n;
	} else {
		return pow(n+n,2) + cuadradosPares2(n - 1);
	}
}

int fibNumero(int n){
 	if(n <= 1){
		return n;
	} else {
		return fibNumero(n-1) + fibNumero(n-2);
	}
}


bool lineal(string s, char c, int l){
	if(l < 0){
		return false;
	} else if (s[l] == c){
		return true;		
	} else {
		return lineal(s, c, l-1);
	}
}


int main(){
	int sumaNumeros = sumaRecursiva(9);
	int cuadradosPares(33);
	int cuadradosPares2(33);
	int numFib = fibNumero(9);
	string palabra = "Palabra";
	char substring = 'g';
	bool caracter = lineal(palabra, substring, palabra.length()-1);
    	int opcion = -1;
    
    do {
        cout<<"Escoja la operacion que desea realizar: "<<endl;
        cout<<"1. Suma de dos numeros"<<endl;
        cout<<"2. Cuadrados pares - Metodo 1"<<endl;
        cout<<"3. Cuadrados pares - Metodo 2"<<endl;
        cout<<"4. Sucesion de fibonacci"<<endl;
        cout<<"5. Lineal"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;
        
        switch(opcion){
	        case 1:{
	            cout << "Suma: " << sumaNumeros << endl;
	            break;
	        }
	        case 2:{
	            cout << "Cuadrados pares: " << cuadradosPares << endl;
	            break;
	        }
	        case 3:{
	            cout << "Cuadrados pares: " << cuadradosPares2 << endl;
	            break;
	        }
	        case 4:{
	            cout << "Fibonacci: " << numFib << endl;
	            break;
	        }
	        case 5:{
	            cout << "Caracter encontrado: " << caracter << endl;
	            break;
	        }
	        case 0:{
	            return 0;
	        }
	        
	        default:{
	            cout<<"Opcion invalida"<<endl;
	            break;
	        }
    	}
    }while(opcion !=0);
    
    return 0;
}
