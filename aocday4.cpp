#include <bits/stdc++.h>
using namespace std;

/*
  Problema: Contar cuántos rollos de papel '@' son accesibles.
  Regla: Un '@' es accesible si en sus 8 vecinos hay menos de 4 '@'.

*/

int main() {
    
    vector<string> grid; //para guardar la cuadricula completa, cada fila es un string
    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back(); // por si hay CRLF
        if (!line.empty()) grid.push_back(line);
    }

    int R = (int)grid.size(); //ROWS
    int C = (int)grid[0].size(); //COLUMNAS, es decir, longitud de la primera fila

    /*Validación: todas las filas deben tener el mismo tamaño
    for (const auto& row : grid) {
        if ((int)row.size() != C) {
            cerr << "Error: filas de longitud desigual.\n";
            return 1;
        }
    }
    */

    // desplazamientos de los 8 vecinos (N, NE, E, SE, S, SW, W, NW)
    const int dr[8] = {-1, -1,  0,  1, 1,  1,  0, -1};
    const int dc[8] = { 0,  1,  1,  1, 0, -1, -1, -1};


    int accessible = 0;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] != '@') continue; //no hay rollo, no me interesa

            int neighbors = 0;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k]; //fila vecino
                int nc = c + dc[k]; //columna vecino
                if (r >= 0 && r < R && c < C && c>= 0 && grid[nr][nc] == '@') {
                    neighbors++;
                }
            }

            // Regla: menos de 4 vecinos '@' => accesible
            if (neighbors < 4) {
                accessible++;
            }
        }
    }

    cout << accessible << "\n";
    return 0;
}
