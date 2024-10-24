// -----------------TALLER GRAFOS-----------------
// Estructuras de datos
// 23 de Octubre de 2024
// Santiago Hernandez, Isaias Acosta, Julian Diaz, Juan Carreño

#ifndef ARISTA_H
#define ARISTA_H

#include "vertice.h"

// Clase Arista que representa una conexión entre dos vértices
template <typename T, typename W>
class Arista {
public:
    Vertice<T>* origen;  // Vértice de origen de la arista
    Vertice<T>* destino; // Vértice de destino de la arista
    W peso;              // Peso de la arista

    // Constructor que inicializa una arista con su origen, destino y peso
    Arista(Vertice<T>* orig, Vertice<T>* dest, W p);
};

// Implementación del constructor de la clase Arista
template <typename T, typename W>
Arista<T, W>::Arista(Vertice<T>* orig, Vertice<T>* dest, W p) : origen(orig), destino(dest), peso(p) {}

#endif // ARISTA_H
