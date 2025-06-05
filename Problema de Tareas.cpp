
// Codigo de Jose Miguel Mateo Valdivia Castillo

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool comparador(std::pair<int, int>& a, std::pair<int, int>& b) {
    return a.first > b.first;
}

int main() {

    int Size_A = 0;

    std::cout << "Ingrese la cantidad de tareas: ";
    std::cin >> Size_A;

    std::vector<std::pair<int, int>> Beneficio(Size_A);
    std::vector<std::pair<int, int>> Plazo(Size_A);

    std::vector<std::pair<int, int>> Solución(Size_A);

    for (int i = 0; i < Size_A; i++) {
        int bene = 0;
        int pla = 0;

        std::cout << "Ingrese la tarea (" << i+1 << "): ";
        std::cin >> bene; std::cout << "\n";

        Beneficio[i].first = bene;
        Beneficio[i].second = i;

        std::cout << "Ingrese el plazo (" << i+1 << "): ";
        std::cin >> pla; std::cout << "\n";

        Plazo[i].first = pla;
        Plazo[i].second = i;
    }


    std::sort(Beneficio.begin(), Beneficio.end(), comparador);

    for (auto p : Beneficio) { std::cout << p.first << " \t"; }
    std::cout << "\n";
    for (auto p : Beneficio) { std::cout << p.second << " \t"; }
    std::cout << "\n";

    std::vector<bool> ocupado(1001, false);
    std::vector<int> tareas_elegidas;
    int beneficio_total = 0;

    for (auto& tarea : Beneficio) {
        int i = tarea.second;
        int plazo = Plazo[i].first;

        
        for (int t = plazo; t >= 1; --t) {
            if (!ocupado[t]) {
                ocupado[t] = true;
                beneficio_total += tarea.first;
                tareas_elegidas.push_back(i + 1);
                break;
            }
        }
    }

    std::cout << "El Beneficio total es: " << beneficio_total << "\n";
    for (int i = 0; i < tareas_elegidas.size(); ++i) {
        std::cout << tareas_elegidas[i];
        if (i != tareas_elegidas.size() - 1)
            std::cout << " ";
    }
    std::cout << "\n";
}









