// -----------------TALLER GRAFOS-----------------
// Estructuras de datos
// 23 de Octubre de 2024
// Santiago Hernandez, Isaias Acosta, Julian Diaz, Juan Carreño

#ifndef VERTICE_H
#define VERTICE_H

// Clase Vertice que representa un nodo del grafo
template <typename T>
class Vertice {
public:
    T dato;  // El valor o dato que almacena el vértice
    explicit Vertice(T valor);  // Constructor que inicializa el vértice con un valor
};

// Implementación del constructor de la clase Vertice
template <typename T>
Vertice<T>::Vertice(T valor) : dato(valor) {}

#endif // VERTICE_H
