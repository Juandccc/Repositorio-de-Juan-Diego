#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Album {
	string nombre;
	int aC1o;
};

struct Cancion {
	string nombre;
	string autor;
	string genero;
	Album album;
};


void imprimirCanciones(const list<Cancion>& canciones) {
	for (const auto& cancion : canciones) {
		cout << "CanciC3n: " << cancion.nombre << endl;
		cout << "Autor: " << cancion.autor << endl;
		cout << "GC)nero: " << cancion.genero << endl;
		cout << "Clbum: " << cancion.album.nombre << endl;
		cout << "AC1o: " << cancion.album.aC1o << endl;
		cout << "-----------------------------" << endl;
	}
}

int main() {
	list<Cancion> canciones;
	bool repetir = true;

	while (repetir) {
		cout << "Bienvenido a javemusic, estas son sus canciones: " << endl;


		ifstream archivo("archivo.txt");
		if (archivo.is_open()) {
			string linea;
			while (getline(archivo, linea)) {
				istringstream ss(linea);
				Cancion cancion;
				string campo;

				try {

					getline(ss, cancion.nombre, '|');
					getline(ss, cancion.autor, '|');
					getline(ss, cancion.genero, '|');
					getline(ss, campo, '|');
					cancion.album.nombre = campo;
					getline(ss, campo, '|');
					if (!campo.empty()) {
						cancion.album.aC1o = stoi(campo);
					} else {
						throw invalid_argument("El campo del aC1o estC! vacC-o");
					}

					canciones.push_back(cancion);
				} catch (const invalid_argument& e) {
					cout << "Error al convertir el campo del aC1o a entero: " << e.what() << endl;
				}
			}
			archivo.close();
		} else {
			cout << "Unable to open file" << endl;
		}

		int seleccion;
		cout << endl;
		cout << "1. Listar todos los autores." << endl;
		cout << "2. Listar las canciones de un artista ordenado alfabC)ticamente." << endl;
		cout << "3. Listar todos los C!lbumes, ordenados cronolC3gicamente." << endl;
		cout << "4. Listar todas las canciones de un C!lbum, ordenadas alfabC)ticamente." << endl;
		cout << "5. Listar todas las canciones y su C!lbum, ordenados alfabC)ticamente por el C!lbum y despuC)s por la canciC3n." << endl;
		cout << "Ingrese una opciC3n: ";
		cin >> seleccion;


		switch (seleccion) {
		case 1: {

			list<string> autores;
			for (const auto& cancion : canciones) {
				autores.push_back(cancion.autor);
			}
			autores.sort();
			autores.unique();
			cout << "Autores:" << endl;
			for (const auto& autor : autores) {
				cout << autor << endl;
			}
			break;
		}
		case 2: {

			string artista;
			cout << "Ingrese el nombre del artista: ";
			cin>> artista;

			list<Cancion> cancionesArtista;
			for (const auto& cancion : canciones) {
				if (cancion.autor == artista) {
					cancionesArtista.push_back(cancion);
				}
			}

			cancionesArtista.sort([](const Cancion& a, const Cancion& b) {
				return a.nombre < b.nombre;
			});

			cout << "Canciones de " << artista << ":" << endl;
			imprimirCanciones(cancionesArtista);
			break;
		}
		case 3: {

			vector<Album> albumes;
			for (const auto& cancion : canciones) {
				albumes.push_back(cancion.album);
			}


			sort(albumes.begin(), albumes.end(), [](const Album& a, const Album& b) {
				return a.aC1o < b.aC1o;
			});
			albumes.erase(unique(albumes.begin(), albumes.end(), [](const Album& a, const Album& b) {
				return a.nombre == b.nombre && a.aC1o == b.aC1o;
			}), albumes.end());

			cout << "Clbumes por aC1o:" << endl;
			for (const auto& album : albumes) {
				cout << "Clbum: " << album.nombre << ", AC1o: " << album.aC1o << endl;
			}
			break;
		}
		case 4: {

			string albumNombre;
			cout << "Ingrese el nombre del C!lbum: ";
			getline(cin, albumNombre);

			list<Cancion> cancionesAlbum;
			for (const auto& cancion : canciones) {
				if (cancion.album.nombre == albumNombre) {
					cancionesAlbum.push_back(cancion);
				}
			}

			cancionesAlbum.sort([](const Cancion& a, const Cancion& b) {
				return a.nombre < b.nombre;
			});

			cout << "Canciones en el C!lbum " << albumNombre << ":" << endl;
			imprimirCanciones(cancionesAlbum);
			break;
		}
		case 5: {

			list<Cancion> cancionesOrdenadas = canciones;

			cancionesOrdenadas.sort([](const Cancion& a, const Cancion& b) {
				if (a.album.nombre == b.album.nombre) {
					return a.nombre < b.nombre;
				}
				return a.album.nombre < b.album.nombre;
			});

			cout << "Canciones y C!lbumes:" << endl;
			imprimirCanciones(cancionesOrdenadas);
			break;
		}
		default:
			cout << "OpciC3n no vC!lida." << endl;
			break;
		}

		cout << "B?Desea volver al menC: principal? (1 para sC-, 0 para no): ";
		cin >> repetir;
	}

	return 0;
}
