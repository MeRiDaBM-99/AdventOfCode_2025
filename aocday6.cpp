#include <bits/stdc++.h>
using namespace std;

/*
  Extrae todas las secuencias de dígitos dentro de un substring
  y las devuelve como enteros largos (long long).
  Ejemplo: "  123  45 " -> {123, 45}
*/
vector<long long> extractNumbers(const string& sub) {
    vector<long long> nums;
    int i = 0;
    int n = (int)sub.size();
    while (i < n) {
        //avanza i saltando los caracteres que no son digitos, como los guiones
        while (i < n && !isdigit(static_cast<unsigned char>(sub[i]))){
            i++;
        }
        if (i >= n) { //si llega al final, sale
            break;
        }
        // leee una secuencia de digitos
        long long val = 0;
        int start = i;
        while (i < n && isdigit(static_cast<unsigned char>(sub[i]))) {
            val = val * 10 + (sub[i] - '0');
            i++;
        }
        // guarda el numero leido
        nums.push_back(val);
    }
    return nums;
}

/*
  Detecta si una columna (col) es separadora: todos los caracteres son ' '.
*/
bool isSeparatorColumn(const vector<string>& grid, int col) {
    for (const auto& row : grid) {
        if (row[col] != ' ') return false;
    }
    return true;
}

int main() {
    vector<string> lines;
    string line;
    // Leer todas las líneas de la entrada 
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    if (lines.empty()) {
        cout << 0 << "\n";
        return 0;
    }

   
    size_t W = 0;
    int rows = (int)lines.size();
    int cols = (int)W;

    // encontrar bloques de columnas (problemas) entre columnas separadoras.
    vector<pair<int,int>> blocks; 
    int c = 0;
    while (c < cols) {
        // saltar columnas separadoras
        while (c < cols && isSeparatorColumn(lines, c)){
            c++;
        } 
        if (c >= cols) {
            break;
        }
        int L = c;
        // avanzar hasta la siguiente separadora
        while (c < cols && !isSeparatorColumn(lines, c)) {
            c++;
        }
        int R = c - 1;
        blocks.push_back({L, R});
    }

    long long grandTotal = 0;

    //esta condicion del for es lo unico que no entiendo pero no he
    // conseguido entender ninguna otra forma que me daba copilot
    for (auto [L, R] : blocks) {
        vector<long long> numbers;

        // se extraen los numeros de todas las filas menos la ultima
        for (int r = 0; r < rows - 1; r++) {
            string sub = lines[r].substr(L, R - L + 1);
            nums = extractNumbers(sub);
            numbers.push_back(v);
        }

        // leer operador ultima fila
        string last = lines[rows - 1].substr(L, R - L + 1);
        char op = 0;
        for (char ch : last) {
            if (ch == '+' || ch == '*') {
                op = ch;
                break;
            }
        }

                
        long long result = 0;
        if (op == '+') {
            for (auto v : numbers) result += v;
        } else { 
            for (auto v : numbers) result *= v;
        }

        grandTotal += result;
    }
   
    cout << grandTotal << "\n";
    return 0;
}
