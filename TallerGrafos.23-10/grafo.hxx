// -----------------TALLER GRAFOS-----------------
// Estructuras de datos
// 23 de Octubre de 2024
// Santiago Hernandez, Isaias Acosta, Julian Diaz, Juan Carreño

// Grafo.hxx

#include "grafo.h"
#include <iostream>

// Metodo para agregar un vertice al grafo
template <typename T, typename W>
void Grafo<T, W>::agregarVertice(T valor) {
    Vertice<T>* nuevoVertice = new Vertice<T>(valor);
    vertices.push_back(nuevoVertice);
}

// Método para contar la cantidad de aristas de un grafo
template <typename T, typename W>
int Grafo<T, W>::cantidadAristas() {
    return aristas.size();
}

// Método para contar la cantidad de vertices de un grafo
template <typename T, typename W>
int Grafo<T, W>::cantidarVertices() {
    return vertices.size();
}

// Método para agregar una arista al grafo
template <typename T, typename W>
void Grafo<T, W>::agregarArista(T valorOrigen, T valorDestino, W peso) {
    Vertice<T>* origen = buscarVertice(valorOrigen);
    Vertice<T>* destino = buscarVertice(valorDestino);

    if (origen && destino) {
        Arista<T, W>* nuevaArista = new Arista<T, W>(origen, destino, peso);
        aristas.push_back(nuevaArista);
    } else {
        std::cout << "Uno o ambos vertices no existen.\n";
    }
}

// Método para imprimir el grafo
template <typename T, typename W>
void Grafo<T, W>::imprimirGrafo() const {
    for (const auto& arista : aristas) {
        std::cout << arista->origen->dato << " --(" << arista->peso << ")--> " << arista->destino->dato << std::endl;
    }
}

// Nueva función para buscar un vértice
template <typename T
