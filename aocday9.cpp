#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    // Guardaremos las coordenadas como pares (x, y) en un vector.
    vector<pair<long long, long long>> reds; //long long por seguridad ante coordenadas grandes.

    string line; // Almacena cada línea completa "x,y".

    while (getline(cin, line)) { // Leemos todas las líneas hasta fin de archivo
        
        if (line.empty()) continue; // Para gestionar posibles líneas vacías

        size_t coma = line.find(','); // Busca la coma que separa x e y
        if (coma == string::npos) continue; // En caso de no haber coma, el formato sería inválido y por tanto, lo ignoramos

        // Extraemos las subcadenas para x e y = (x, y)
        string xs = line.substr(0, coma); // x se encuentra antes de la coma
        string ys = line.substr(coma + 1); // y se encuentra después de la coma

        try {
            long long x = stoll(xs); //convierto x e y a enteros, long long
            long long y = stoll(ys);
            
            reds.emplace_back(x, y); // Añadimos la coordenada válida al vector.
        } catch (...) {
            // Si la conversión falla, ignoramos esta línea.
            continue;
        }
    }

    // Si hay menos de 2 baldosas rojas, no se puede formar ningún rectángulo.
    if (reds.size() < 2) {
        cout << 0 << "\n"; // Área máxima es 0 en este caso.
        return 0;          // Terminamos el programa.
    }

    /* Recorremos todas las parejas de puntos rojos para calcular el área del rectángulo con esquinas opuestas en esos dos puntos. 
    El área se cuenta de forma inclusiva:
    ancho = |x2 - x1| + 1, alto = |y2 - y1| + 1, área = ancho * alto.
    */

    long long best = 0; //Almacena el máximo área encontrado.

    // Doble bucle para todas las parejas (i, j) con i < j.
    for(size_t i = 0; i < reds.size(); i++) {
        for (size_t j = i + 1; j < reds.size(); j++) {
            // Obtenemos las coordenadas de la pareja actual.
            long long x1 = reds[i].first;
            long long y1 = reds[i].second;
            long long x2 = reds[j].first;
            long long y2 = reds[j].second;

            // Calculamos el ancho inclusivo: diferencia absoluta en x más 1.
            long long width = llabs(x2 - x1) + 1;
            // Calculamos el alto inclusivo: diferencia absoluta en y más 1.
            long long height = llabs(y2 - y1) + 1;

            // Calculamos el área del rectángulo con estas dos esquinas opuestas.
            long long area = width * height;

            // Actualizamos el máximo si encontramos un área mayor.
            if (area > best) best = area;
        }
    }

    // Imprimimos el área máxima encontrada.
    cout << best << "\n";

    // Terminamos correctamente.
    return 0;
}

