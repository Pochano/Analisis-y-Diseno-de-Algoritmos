#include <iostream>

int Contenedores_Max(int* Pesos, int size, int Capacidad) {
    int suma = 0;
    int cont = 0;

    for (int i = 0; i < size; i++) {
        if (suma + *(Pesos + i) <= Capacidad) {
            suma += *(Pesos + i);
            cont++;
        }
        else {
            break;
        }
    }

    return cont;
}

// b) Maximiza la cantidad de toneladas cargadas (arreglo ordenado de mayor a menor)
int Toneladas_Max(int* Pesos, int size, int Capacidad) {
    int suma = 0;

    for (int i = 0; i < size; i++) {
        if (suma + *(Pesos + i) <= Capacidad) {
            suma += *(Pesos + i);
        }
    }

    return suma;
}

int main() {

    int capacidad = 20;

    int Pesos_1[5] = { 3, 5, 7, 8, 10 };
    int Pesos_2[5] = { 10, 8, 7, 5, 3 };

    int Cantidad_Maxima = Contenedores_Max(Pesos_1, 5 , capacidad);
    int Toneladas_Cargadas = Toneladas_Max(Pesos_2, 5, capacidad);

    std::cout << "a) Maximo numero de contenedores cargados: " << Cantidad_Maxima << "\n";
    std::cout << "b) Maximo numero de toneladas cargadas: " << Toneladas_Cargadas << "\n";

}