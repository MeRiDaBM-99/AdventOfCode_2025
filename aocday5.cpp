#include <bits/stdc++.h>
using namespace std;

/*
  Estructura simple para manejar rangos [l, r] inclusivos.
*/
struct Range {
    long long l, r;
};

/*
  Fusiona una lista de rangos (posiblemente solapados) en una lista mínima
  de rangos disjuntos y ordenados. Esto permite búsquedas más eficientes.
*/
vector<Range> mergeRanges(vector<Range> ranges) {
    // Si no hay rangos, devolvemos vacío.
    if (ranges.empty()) return {};

    // Ordenamos por inicio; si empatan, por fin.
    sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        if (a.l != b.l) return a.l < b.l;
        return a.r < b.r;
    });

    vector<Range> merged;
    merged.reserve(ranges.size());

    // Empezamos con el primer rango como base.
    Range current = ranges[0];

    // Recorremos el resto para fusionar solapamientos o adyacencias.
    for (size_t i = 1; i < ranges.size(); ++i) {
        const Range& nxt = ranges[i];
        // Si el siguiente empieza antes o justo donde termina el actual + 1,
        // hay solape o continuidad; extendemos el rango actual.
        if (nxt.l <= current.r + 1) {
            current.r = max(current.r, nxt.r);
        } else {
            // No solapa: fijamos el actual y empezamos uno nuevo.
            merged.push_back(current);
            current = nxt;
        }
    }
    // Añadimos el último rango activo.
    merged.push_back(current);
    return merged;
}

/*
  Comprueba si un ID está dentro de alguno de los rangos fusionados.
  Aprovechamos que los rangos están ordenados y disjuntos para hacer
  una búsqueda binaria por rangos.
*/
bool isFresh(const vector<Range>& merged, long long id) {
    // Búsqueda binaria sobre los rangos.
    int lo = 0, hi = (int)merged.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        const Range& rg = merged[mid];
        if (id < rg.l) {
            hi = mid - 1;
        } else if (id > rg.r) {
            lo = mid + 1;
        } else {
            // id dentro de [rg.l, rg.r]
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Range> ranges;
    vector<long long> ids;

    string line;
    bool readingRanges = true;

    /*
      Leemos toda la entrada línea a línea.
      - Antes de la línea en blanco: rangos "a-b".
      - Después de la línea en blanco: IDs (un número por línea).
    */
    while (getline(cin, line)) {
        // Eliminamos espacios laterales si hubiera.
        // (Opcional: si el formato es limpio, no es necesario.)
        auto trim = [](string& s) {
            size_t start = s.find_first_not_of(" \t\r");
            size_t end   = s.find_last_not_of(" \t\r");
            if (start == string::npos) { s.clear(); return; }
            s = s.substr(start, end - start + 1);
        };
        trim(line);

    }
}