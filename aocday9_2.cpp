#include <iostream>
#include <vector>
#include <string>
#include <fstream>   // Para leer el archivo
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// --- ESTRUCTURAS ---

struct Point {
    long long x, y; //long long para evitar desbordamientos en cálculos de área
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Mantenemos tu MyHashSet para consultas rápidas de vértices si fuera necesario,
// aunque para la geometría nos basaremos en vectores para iterar segmentos.
class MyHashSet {
private:
    struct Entry {
        long long key; // Guardamos una llave combinada
        bool occupied = false;
    };
    vector<Entry> table;
    int capacity;

    size_t hash(long long k) const {
        return (k * 2654435761) % capacity; 
    }

public:
    MyHashSet(int cap = 10007) : capacity(cap) {
        table.resize(capacity);
    }

    void insert(long long x, long long y) {
        // Empaquetar x,y en un solo long long (asumiendo coords < 100,000)
        long long k = (x << 32) | y; 
        size_t idx = hash(k);
        while (table[idx].occupied) {
            if (table[idx].key == k) return;
            idx = (idx + 1) % capacity;
        }
        table[idx].key = k;
        table[idx].occupied = true;
    }

    bool contains(long long x, long long y) const {
        long long k = (x << 32) | y;
        size_t idx = hash(k);
        size_t start = idx;
        while (table[idx].occupied) {
            if (table[idx].key == k) return true;
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
        return false;
    }
};

// --- LECTURA DE ARCHIVO ---

vector<Point> read_input(const string& filename) {
    vector<Point> tiles;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        // Reemplazar la coma por espacio para usar cin fácilmente
        for (char &c : line) {
            if (c == ',') c = ' ';
        }
        
        stringstream ss(line);
        long long x, y;
        if (ss >> x >> y) {
            tiles.push_back({x, y});
        }
    }
    return tiles;
}

// --- LÓGICA GEOMÉTRICA ---

// Verifica si un valor 'v' está estrictamente entre 'a' y 'b'
bool is_between(long long v, long long a, long long b) {
    return v > min(a, b) && v < max(a, b);
}

// Verifica si un rectángulo candidato es válido
// rx1, ry1, rx2, ry2: Esquinas del rectángulo candidato
// polygon: Lista de vértices del polígono (borde rojo)
bool is_valid_rectangle(long long rx1, long long ry1, long long rx2, long long ry2, const vector<Point>& polygon) {
    long long r_min_x = min(rx1, rx2);
    long long r_max_x = max(rx1, rx2);
    long long r_min_y = min(ry1, ry2);
    long long r_max_y = max(ry1, ry2);

    int n = polygon.size();

    // 1. VERIFICAR INTERSECCIONES CON EL BORDE
    // Si alguna línea del polígono atraviesa el interior del rectángulo, es inválido.
    // (Tocar los bordes está permitido porque son verdes).
    
    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        // Segmento del polígono es Vertical
        if (p1.x == p2.x) {
            long long seg_x = p1.x;
            long long seg_y_min = min(p1.y, p2.y);
            long long seg_y_max = max(p1.y, p2.y);

            // ¿Este segmento vertical corta horizontalmente al rectángulo?
            // Para cortar, su X debe estar estrictamente dentro del rango X del rectángulo
            // Y sus rangos Y deben solaparse estrictamente.
            if (seg_x > r_min_x && seg_x < r_max_x) {
                // Verificar solapamiento en Y
                if (max(seg_y_min, r_min_y) < min(seg_y_max, r_max_y)) {
                    return false; // Corta por la mitad
                }
            }
        } 
        // Segmento del polígono es Horizontal
        else { 
            long long seg_y = p1.y;
            long long seg_x_min = min(p1.x, p2.x);
            long long seg_x_max = max(p1.x, p2.x);

            // ¿Corta verticalmente?
            if (seg_y > r_min_y && seg_y < r_max_y) {
                // Verificar solapamiento en X
                if (max(seg_x_min, r_min_x) < min(seg_x_max, r_max_x)) {
                    return false; // Corta por la mitad
                }
            }
        }
    }

    // 2. VERIFICAR SI ESTÁ DENTRO (RAY CASTING)
    // Tomamos el punto central del rectángulo. Si el centro está dentro del polígono,
    // y no hubo intersecciones (paso 1), entonces todo el rectángulo está dentro.
    double mid_x = (r_min_x + r_max_x) / 2.0;
    double mid_y = (r_min_y + r_max_y) / 2.0;

    int crossings = 0;
    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        // Ray Casting hacia la derecha desde (mid_x, mid_y)
        // Solo nos importan los segmentos que no sean horizontales y que crucen nuestra Y
        if ((p1.y > mid_y) != (p2.y > mid_y)) {
            double intersect_x = (p2.x - p1.x) * (mid_y - p1.y) / (double)(p2.y - p1.y) + p1.x;
            if (mid_x < intersect_x) {
                crossings++;
            }
        }
    }

    // Si cruzamos un número IMPAR de líneas, estamos DENTRO.
    return (crossings % 2 != 0);
}

int main() {
    // 1. Leer el archivo real
    cout << "Leyendo archivo..." << endl;
    vector<Point> red_tiles = read_input("input_day9_2.txt");
    cout << "Puntos leidos: " << red_tiles.size() << endl;

    long long max_area = 0;
    int n = red_tiles.size();

    // 2. Iterar sobre todos los pares de vértices Rojos
    // Con ~280 puntos, son ~40,000 pares. La validación toma ~280 pasos.
    // Total operaciones ~10^7, muy rápido (menos de 1 segundo).
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Point p1 = red_tiles[i];
            Point p2 = red_tiles[j];

            // Cálculo del Área Candidata
            long long w = abs(p1.x - p2.x) + 1;
            long long h = abs(p1.y - p2.y) + 1;
            long long current_area = w * h;

            // Optimización: Si el área es menor que la máxima encontrada, ni chequear
            if (current_area <= max_area) continue;

            // Validación Geométrica
            if (is_valid_rectangle(p1.x, p1.y, p2.x, p2.y, red_tiles)) {
                max_area = current_area;
                cout << "Nuevo maximo encontrado: " << max_area << endl;
            }
        }
    }

    cout << "-------------------------" << endl;
    cout << "AREA MAXIMA FINAL: " << max_area << endl;
    cout << "-------------------------" << endl;

    return 0;
}