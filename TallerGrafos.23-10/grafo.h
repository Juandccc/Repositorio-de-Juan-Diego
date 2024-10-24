// -----------------TALLER GRAFOS-----------------
// Estructuras de datos
// 23 de Octubre de 2024
// Santiago Hernandez, Isaias Acosta, Julian Diaz, Juan Carreño

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "vertice.h"
#include "arista.h"
#include <iostream>

// Clase Grafo que gestiona vértices y aristas
template <typename T, typename W>
class Grafo {
private:
    std::vector<Vertice<T>*> vertices;  // Lista de vértices
    std::vector<Arista<T, W>*> aristas; // Lista de aristas

public:
    // Métodos para agregar vértices, aristas y otros
    void agregarVertice(T valor);
    void agregarArista(T valorOrigen, T valorDestino, W peso);
    void imprimirGrafo() const; // Imprimir la representación del grafo
    int cantidarVertices();     // Contar el número de vértices
    int cantidadAristas();      // Contar el número de aristas

    // Nuevas funciones
    Vertice<T>* buscarVertice(T valor);  // Buscar un vértice por su valor
    Arista<T, W>* buscarArista(T valorOrigen, T valorDestino); // Buscar una arista entre dos vértices
};

// Implementación de los métodos del Grafo

// Método para agregar un vértice al grafo
template <typename T, typename W>
void Grafo<T, W>::agregarVertice(T valor) {
    Vertice<T>* nuevoVertice = new Vertice<T>(valor);
    vertices.push_back(nuevoVertice);
}

// Método para contar la cantidad de aristas del grafo
template <typename T, typename W>
int Grafo<T, W>::cantidadAristas() {
    return aristas.size();  // Retorna el tamaño del vector de aristas
}

// Método para contar la cantidad de vértices del grafo
template <typename T, typename W>
int Grafo<T, W>::cantidarVertices() {
    return vertices.size();  // Retorna el tamaño del vector de vértices
}

// Método para agregar una arista al grafo
template <typename T, typename W>
void Grafo<T, W>::agregarArista(T valorOrigen, T valorDestino, W peso) {
    // Buscar los vértices origen y destino
    Vertice<T>* origen = buscarVertice(valorOrigen);
    Vertice<T>* destino = buscarVertice(valorDestino);

    // Si ambos vértices existen, crea una nueva arista
    if (origen && destino) {
        Arista<T, W>* nuevaArista = new Arista<T, W>(origen, destino, peso);
        aristas.push_back(nuevaArista);
    } else {
        std::cout << "Uno o ambos vértices no existen.\n";
    }
}

// Método para imprimir las aristas del grafo
template <typename T, typename W>
void Grafo<T, W>::imprimirGrafo() const {
    for (const auto& arista : aristas) {
        std::cout << arista->origen->dato << " --(" << arista->peso << ")--> " << arista->destino->dato << std::endl;
    }
}

// Método para buscar un vértice en el grafo
template <typename T, typename W>
Vertice<T>* Grafo<T, W>::buscarVertice(T valor) {
    // Recorre la lista de vértices y devuelve el que tenga el valor buscado
    for (auto v : vertices) {
        if (v->dato == valor) {
            return v;
        }
    }
    return nullptr;  // Si no se encuentra el vértice, retorna nullptr
}

// Método para buscar una arista entre dos vértices
template <typename T, typename W>
Arista<T, W>* Grafo<T, W>::buscarArista(T valorOrigen, T valorDestino) {
    // Recorre la lista de aristas buscando la que conecta los dos vértices indicados
    for (auto a : aristas) {
        if (a->origen->dato == valorOrigen && a->destino->dato == valorDestino) {
            return a;
        }
    }
    return nullptr;  // Si no se encuentra la arista, retorna nullptr
}

#endif // GRAFO_H