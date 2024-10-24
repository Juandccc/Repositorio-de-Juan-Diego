// -----------------TALLER GRAFOS-----------------
// Estructuras de datos
// 23 de Octubre de 2024
// Santiago Hernandez, Isaias Acosta, Julian Diaz, Juan Carreño

// Arista.hxx

#include "arista.h"
// Constructor de la clase arista
template <typename T, typename W>
Arista<T, W>::Arista(Vertice<T>* orig, Vertice<T>* dest, W p) : origen(orig), destino(dest), peso(p) {}


