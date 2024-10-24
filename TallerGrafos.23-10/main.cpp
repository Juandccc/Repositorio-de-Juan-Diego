// -----------------TALLER GRAFOS-----------------
// Estructuras de datos
// 23 de Octubre de 2024
// Santiago Hernandez, Isaias Acosta, Julian Diaz, Juan Carreño

#include "grafo.h"
#include <iostream>

int main() {
    // Crear un grafo de strings con pesos enteros
    Grafo<std::string, int> miGrafo;

    // Agregar vértices al grafo
    miGrafo.agregarVertice("A");
    miGrafo.agregarVertice("B");
    miGrafo.agregarVertice("C");

    // Agregar aristas entre los vértices
    miGrafo.agregarArista("A", "B", 5);
    miGrafo.agregarArista("A", "C", 10);

    // Imprimir el grafo
    miGrafo.imprimirGrafo();

    // Buscar un vértice
    if (miGrafo.buscarVertice("B")) {
        std::cout << "Vértice B encontrado.\n";
    } else {
        std::cout << "Vértice B no existe.\n";
    }

    // Buscar una arista entre dos vértices
    if (miGrafo.buscarArista("A", "B")) {
        std::cout << "Arista entre A y B encontrada.\n";
    } else {
        std::cout << "Arista entre A y B no existe.\n";
    }

    return 0;
}
