#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int ind = 99;

std::string nombreAt[ind];
std::string paises[ind];
std::string disciplina[ind];
std::string genero[ind];
int medallas[ind];

int registros = 0;






int main(int argc, char* argv[]) {
    std::string nombCSV;
    if (argc > 1){
        nombCSV = argv[1];
    }else{
        std::cout << "ingresa el nombre de tu csv: ";
        std::cin >>nombCSV;
    }

    std::ifstream archivo(nombCSV);
    if (!archivo.is_open()){
        std::cout << "no se pudo abnrir el archivo";
        return 1;
    }

    std::string entrada;
    while(std::getline(archivo, entrada) && registros < ind){
        std::stringstream ss(entrada);
        std::string campo;

        std::getline(ss, campo, ',');
        nombreAt[registros] = campo;

        std::getline(ss, campo, ',');
        paises[registros] = campo;

        std::getline(ss, campo, ',');
        disciplina[registros] = campo;

        std::getline(ss, campo, ',');
        genero[registros] = campo;

        std::getline(ss, campo, ',');
        medallas[registros] = std::stoi(campo);

        registros ++;} archivo.close();
        

    return 0;
}