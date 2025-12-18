#include <bits/stdc++.h> 

// Usamos el espacio de nombres estándar para simplificar.
using namespace std;

int main() {
    // Vamos a leer líneas de la entrada estándar con el formato "x,y".
    // Guardaremos las coordenadas como pares (x, y) en un vector.
    vector<pair<long long, long long>> reds; // Usamos long long por seguridad ante coordenadas grandes.

    // Preparamos variables para leer cada línea.
    string line; // Almacena cada línea completa "x,y".

    // Leemos todas las líneas hasta EOF (fin de archivo).
    while (getline(cin, line)) {
        // Si la línea está vacía (posibles líneas en blanco), la ignoramos.
        if (line.empty()) continue;

        // Buscamos la coma que separa x e y.
        size_t coma = line.find(',');
        // Si no hay coma, el formato es inválido; lo ignoramos de forma segura.
        if (coma == string::npos) continue;

        // Extraemos las subcadenas para x e y.
        string xs = line.substr(0, coma);           // Parte antes de la coma: x
        string ys = line.substr(coma + 1);          // Parte después de la coma: y

        /* Quitamos espacios en los extremos por si los hubiera.
        auto trim = [](string &s) {
            // Elimina espacios en blanco al inicio y al final de la cadena.
            while (!s.empty() && isspace(static_cast<unsigned char>(s.back()))) s.pop_back();
            size_t i = 0;
            while (i < s.size() && isspace(static_cast<unsigned char>(s[i]))) ++i;
            s.erase(0, i);
        };
        
        trim(xs);
        trim(ys);
        */

        // Convertimos x e y a enteros (long long).
        // Usamos stoll que convierte string a long long y lanza excepción si no es válido.
        try {
            long long x = stoll(xs);
            long long y = stoll(ys);
            // Añadimos la coordenada válida al vector.
            reds.emplace_back(x, y);
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

    // Recorremos todas las parejas de puntos rojos para calcular el área del rectángulo
    // con esquinas opuestas en esos dos puntos. El área se cuenta de forma inclusiva:
    // ancho = |x2 - x1| + 1, alto = |y2 - y1| + 1, área = ancho * alto.
    long long best = 0; // Almacena el máximo área encontrado.

    // Doble bucle para todas las parejas (i, j) con i < j.
    for (size_t i = 0; i < reds.size(); i++) {
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
