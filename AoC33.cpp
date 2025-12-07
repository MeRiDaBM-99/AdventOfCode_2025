#include <bits/stdc++.h>
using namespace std;

long long doce(string linea){
    long long definitivo = 0;

    for(int i = 0; i < linea.size() - 11; i++){
        // pivote
        long long pivote = (linea[i]-'0') * 100000000000LL;

        // num1
        int mejor1 = -1, pos1 = -1;
        for(int j = i+1; j < linea.size()-10; j++){
            if((linea[j]-'0') > mejor1){
                mejor1 = (linea[j]-'0');
                pos1 = j;
            }
        }
        long long num1 = mejor1*10000000000LL + pivote;

        // num2
        int mejor2 = -1, pos2 = -1;
        for(int j = pos1+1; j < linea.size()-9; j++){
            if((linea[j]-'0') > mejor2){
                mejor2 = (linea[j]-'0');
                pos2 = j;
            }
        }
        long long num2 = mejor2*1000000000LL + num1;

        // num3
        int mejor3 = -1, pos3 = -1;
        for(int j = pos2+1; j < linea.size()-8; j++){
            if((linea[j]-'0') > mejor3){
                mejor3 = (linea[j]-'0');
                pos3 = j;
            }
        }
        long long num3 = mejor3*100000000LL + num2;

        // num4
        int mejor4 = -1, pos4 = -1;
        for(int j = pos3+1; j < linea.size()-7; j++){
            if((linea[j]-'0') > mejor4){
                mejor4 = (linea[j]-'0');
                pos4 = j;
            }
        }
        long long num4 = mejor4*10000000LL + num3;

        // num5
        int mejor5 = -1, pos5 = -1;
        for(int j = pos4+1; j < linea.size()-6; j++){
            if((linea[j]-'0') > mejor5){
                mejor5 = (linea[j]-'0');
                pos5 = j;
            }
        }
        long long num5 = mejor5*1000000LL + num4;

        // num6
        int mejor6 = -1, pos6 = -1;
        for(int j = pos5+1; j < linea.size()-5; j++){
            if((linea[j]-'0') > mejor6){
                mejor6 = (linea[j]-'0');
                pos6 = j;
            }
        }
        long long num6 = mejor6*100000LL + num5;

        // num7
        int mejor7 = -1, pos7 = -1;
        for(int j = pos6+1; j < linea.size()-4; j++){
            if((linea[j]-'0') > mejor7){
                mejor7 = (linea[j]-'0');
                pos7 = j;
            }
        }
        long long num7 = mejor7*10000LL + num6;

        // num8
        int mejor8 = -1, pos8 = -1;
        for(int j = pos7+1; j < linea.size()-3; j++){
            if((linea[j]-'0') > mejor8){
                mejor8 = (linea[j]-'0');
                pos8 = j;
            }
        }
        long long num8 = mejor8*1000LL + num7;

        // num9
        int mejor9 = -1, pos9 = -1;
        for(int j = pos8+1; j < linea.size()-2; j++){
            if((linea[j]-'0') > mejor9){
                mejor9 = (linea[j]-'0');
                pos9 = j;
            }
        }
        long long num9 = mejor9*100LL + num8;

        // num10
        int mejor10 = -1, pos10 = -1;
        for(int j = pos9+1; j < linea.size()-1; j++){
            if((linea[j]-'0') > mejor10){
                mejor10 = (linea[j]-'0');
                pos10 = j;
            }
        }
        long long num10 = mejor10*10LL + num9;

        // num11
        int mejor11 = -1, pos11 = -1;
        for(int j = pos10+1; j < linea.size(); j++){
            if((linea[j]-'0') > mejor11){
                mejor11 = (linea[j]-'0');
                pos11 = j;
            }
        }
        long long num11 = mejor11 + num10;

        definitivo += num11;
    }
    return definitivo;
}

int main(){
    ifstream archivo("baterias.txt");
    if(!archivo.is_open()){
        cout << "Archivo no encontrado" << endl;
        return 0;
    }

    long long suma = 0;
    string linea;
    while(getline(archivo, linea)){
        suma += doce(linea);
    }
    cout << suma << endl;
    return 0;
}
