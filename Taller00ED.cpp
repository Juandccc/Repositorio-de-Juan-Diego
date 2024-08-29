#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stack>
using namespace std;
struct cliente{
    string nombre;
    string nombre_producto;
    int cedula;
    int costo_producto;
    int cantidad;
};
void rellenarArreglo(int arreglo[]) {
    for (int i=0; i<10; i++) {
        arreglo[i] = rand()%25;
    }
}

void mostrarArreglo(int arreglo[], int* puntero) {
    for (int i=0; i<10; i++) {
        cout<<"posicion "<< i+1<<" :"<<*(puntero+i) <<endl;
    }

    for (int i=0; i<10; i++) {
        cout<<puntero+i <<endl;
    }
}


int main() {
    srand(time(NULL));
    int arreglo[10];


    int* puntero =arreglo;
    rellenarArreglo(arreglo);
    mostrarArreglo(arreglo,puntero);


    bool repetir = true;
    int numeroRepetir;
    vector <cliente> clientes;
    cout<<"Bienvenido a la empresa."<<endl;
    while(repetir==true) {
        cliente nuevoCliente;
        cout<<"por favor ingrese el nombre del cliente: ";
        cin>>nuevoCliente.nombre;
        cout<<"por favor ingrese el nombre del producto: ";
        cin>>nuevoCliente.nombre_producto;
        cout<<"por favor ingrese la cedula del cliente: ";
        cin>>nuevoCliente.cedula;
        cout<<"por favor ingrese el precio del producto: ";
        cin>>nuevoCliente.costo_producto;
        cout<<"Por favor ingrese la cantidad de productos: ";
        cin>>nuevoCliente.cantidad;
        clientes.push_back(nuevoCliente);
        cout<<"desea ingresar otro cliente?"<<endl;
        cout<<"ingrese 1 para si, 2 para no: ";
        cin>>numeroRepetir;
        if(numeroRepetir==1) {
            repetir = true;
        }else {
            repetir=false;
        }
    }
    int valortotal;
    for (int i=0; i<clientes.size(); i++) {
        cout<<"nombre:" <<clientes[i].nombre<<" "<<endl;
        cout<<"Nombre producto: "<<clientes[i].nombre_producto<<" "<<endl;
        cout<<"Cedula: "<<clientes[i].cedula<<" ";
        cout<<"valor producto: "<<clientes[i].costo_producto<<" "<<endl;
        cout<<"cantidad producto: " <<clientes[i].cantidad<<endl;
        valortotal=clientes[i].cantidad* clientes[i].costo_producto;
        cout<<"Valor total: "<<valortotal;

        cout<<endl;
    }
    ofstream archivo("clientes.txt");  // Abre el archivo para escritura

    if (archivo.is_open()) {
        for (int i=0; i<clientes.size(); i++) {
            archivo<<"nombre:" <<clientes[i].nombre<<" "<<endl;
            archivo<<"Nombre producto: "<<clientes[i].nombre_producto<<" "<<endl;
            archivo<<"Cedula: "<<clientes[i].cedula<<" ";
            archivo<<"valor producto: "<<clientes[i].costo_producto<<" "<<endl;
            archivo<<"cantidad producto: " <<clientes[i].cantidad<<endl;
            archivo<<"Valor total: "<<valortotal;

        }
        archivo.close();
    }
}