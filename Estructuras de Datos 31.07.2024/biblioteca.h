/*********************************
 * Autor: Juan Carreño
 * Materia: Estructuras de datos
 * Fecha: 24 de julio de 2024
*********************************/
#include <iostream>
#include <string>
#include <math.h>
#include <stack>
#include <vector>

using namespace std;

int sumaRecursiva(int n);

int cuadradosPares(int n);

int cuadradosPares2(int n);

int fibNumero(int n);

bool lineal(string s, char c, int l);

// Prototipo añadido para la nueva función
void ejemploCharacterStack();

class Character {
public:
    Character(std::string Name) : Name(Name) {
        std::cout << "Constructing " << Name << "\n";
    }
    
    Character(const Character& Source) : Name(Source.Name) {
        std::cout << "Copying " << Source.Name << "\n";
    }
    
    Character(Character&& Source) : Name(Source.Name) {
        std::cout << "Moving " << Source.Name << "\n";
    }
    
    std::string Name;
};
