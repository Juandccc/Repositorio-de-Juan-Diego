/************************
Autor: Juan Diego Carreño
Materia: Estructuras de datos
Fecha: 24 de julio de 2024
*************************/

#include <iostream>
using namespace std;

/*Tipo de Dato Abstracto para las Cafeteras*/
class Cafetera {
public:
    virtual void Capuchino() = 0;
    virtual void Tinto() = 0;
};

/*Implementación del TAD para OSTER*/
class Oster : public Cafetera {
public:
    void Capuchino() override {
        cout << "Oster haciendo capuchino!!!" << endl;
    }
    void Tinto() override {
        cout << "Oster haciendo tinto!!!" << endl;
    }
};

/*Implementación del TAD para HACEB*/
class Haceb : public Cafetera {
public:
    void Capuchino() override {
        cout << "Haceb haciendo capuchino!!!" << endl;
    }
    void Tinto() override {
        cout << "Haceb haciendo tinto!!!" << endl;
    }
};

void mostrarMenu() {
    cout << "Seleccione el tipo de cafetera:" << endl;
    cout << "1. Oster" << endl;
    cout << "2. Haceb" << endl;
    cout << "Seleccione la receta deseada:" << endl;
    cout << "1. Capuchino" << endl;
    cout << "2. Tinto" << endl;
}

int main(){
    int tipoCafetera, receta;
    Cafetera* cafetera = nullptr;

    mostrarMenu();

    cout << "Ingrese el número correspondiente al tipo de cafetera: ";
    cin >> tipoCafetera;
    cout << "Ingrese el número correspondiente a la receta deseada: ";
    cin >> receta;

    if (tipoCafetera == 1) {
        cafetera = new Oster();
    } else if (tipoCafetera == 2) {
        cafetera = new Haceb();
    } else {
        cout << "Tipo de cafetera no válido." << endl;
        return 1;
    }

    if (receta == 1) {
        cafetera->Capuchino();
    } else if (receta == 2) {
        cafetera->Tinto();
    } else {
        cout << "Receta no válida." << endl;
        delete cafetera;
        return 1;
    }

    delete cafetera;
    return 0;
}
