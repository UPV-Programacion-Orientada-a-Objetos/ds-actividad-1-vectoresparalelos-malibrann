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


void buscarAt( std::string nombreAt[], std::string paises[], std::string disciplina[],std::string genero[],const int medallas[], const int ind ){
    std::string busqueda;
    std::cout << "INgrese el nombre del atrleta: ";
    //esto se usa para limpiar el bufer y ademas que se lea el nombre completo del artista y no solo la primer palabra
    std::cin.ignore();
    std::getline(std::cin, busqueda);
    for (int i = 0; i < registros; i++)
    {
      if(nombreAt[i] == busqueda){
         std::cout << "Nombre: " << nombreAt[i] << std::endl;
         std::cout << "Pais: " << paises[i]<< std::endl;
         std::cout << "Disciplina: " << disciplina[i] << std::endl;
         std::cout << "Genero: " << genero[i] << std::endl;
         std::cout << "Medallas: " << medallas[i] << std::endl;

         return;
    }
    
    
}{std::cout << "no estaba";}  }

void encontrarMax( std::string nombreAt[],const int medallas[], const int ind){
    int maxMed = medallas [0];
    int max;
    for ( int i = 0; i < registros; i++)
    {if (medallas[i]>maxMed)
       {maxMed=medallas[i];
        max = i;}}
    
    std::cout<<"El atleta con mas medallas es "<< nombreAt[max] <<" con un total de "<<maxMed<<std::endl;
}

void medPais(std::string pais[], const int medallas[]) {
    std::string pUnico[ind];
    int medTot[ind]; 
    int cont = 0; 
    for (int i = 0; i < registros; i++) {
        bool encontrado = false;
        // Buscar si el país ya está en pUnico
        for (int j = 0; j < cont; j++) {
            if (pais[i] == pUnico[j]) {
                medTot[j] += medallas[i]; 
                encontrado = true;
                break;
            }
        }
        // Si no se encontró, agregarlo como nuevo
        if (!encontrado) {
            pUnico[cont] = pais[i];
            medTot[cont] = medallas[i];
            cont++;
        }
    }
    // Mostrar resultados
    std::cout << "\nMedallas por país:\n";
    for (int i = 0; i < cont; i++) {
        std::cout << "País: " << pUnico[i] 
                  << " - Medallas: " << medTot[i] << std::endl;
    }
}

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
    std::getline(archivo, entrada); // lee y descarta la línea de encabezado

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

    int opcion = 0;
    do {
        std::cout << "\n Olimpiadas\n";
        std::cout << "1. Salir\n";
        std::cout << "2. Buscar atleta\n";
        std::cout << "3. Atleta con mas medallas\n";
        std::cout << "4. Medallas totales por pais\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

    switch(opcion) {
        case 1: break;
        case 2: buscarAt(nombreAt, paises, disciplina, genero, medallas, registros); break;
        case 3: encontrarMax(nombreAt, medallas, registros); break;
        case 4: medPais(paises, medallas); break;
        default: std::cout << "Opcion invalida\n";
    }
} while(opcion != 1);

    return 0;
}