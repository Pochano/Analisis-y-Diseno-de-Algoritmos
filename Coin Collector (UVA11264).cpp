
#include <iostream>

int Coin_Collector(int* Monedas, int size) {

    int suma = 0;
    int contador = 1; //Iniciamos con 1 ya que se siempre se incluye la ultima moneda, por ello tambien el for va hasta size - 1

    for (int i = 0; i < size - 1; i++) {
        
        if (suma + *(Monedas + i) < *(Monedas + i + 1)) {
            suma += *(Monedas + i);
            contador++;
            std::cout << "Moneda: " << * (Monedas + i) << "\t";
        }

        else {
            std::cout << "Moneda No usada: " << *(Monedas + i) << "\t";
        }
    }

    return contador;
}


int main()
{

    int Monedas_1[6]{ 1, 2, 4, 8, 16, 32 };
    int Monedas_2[4]{ 1, 3, 6, 8 };

std::cout << "\n Total de Monedas: " << Coin_Collector(Monedas_1, 6) << "\n";
std::cout << "\n Total de Monedas: " << Coin_Collector(Monedas_2, 4) << "\n";


}
