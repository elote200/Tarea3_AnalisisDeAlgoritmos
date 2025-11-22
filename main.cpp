#include <iostream>
#include <vector>
#include <chrono>  // Para medir el tiempo
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <string>
#include "sorts.hpp" // Tus algoritmos

using namespace std;
using namespace std::chrono;

vector<int> generarDatos(int n)
{
    vector<int> datos;
    datos.reserve(n); // Optimización para reservar memoria de golpe
    for (int i = 0; i < n; i++)
    {
        datos.push_back(rand() % 1000000); // Números entre 0 y 999,999
    }
    return datos;
}

void ejecutarPrueba(string nombreSort, void (*funcionSort)(vector<int> &), int tamano)
{
    cout << "Generando " << tamano << " numeros aleatorios... ";
    vector<int> data = generarDatos(tamano);
    cout << "Listo.\n";

    cout << "Ejecutando " << nombreSort << " con " << tamano << " elementos... " << flush;

    // Medir tiempo
    auto inicio = high_resolution_clock::now();
    funcionSort(data);
    auto fin = high_resolution_clock::now();

    duration<double, std::milli> tiempo = fin - inicio;

    cout << "TERMINADO.\n";
    cout << ">>> Tiempo: " << tiempo.count() << " ms (" << (tiempo.count() / 1000.0) << " segundos)\n";
    cout << "---------------------------------------------------\n";
}

int main()
{
    srand(time(0));

    int opcion;

    // Definimos los tamaños
    const int SMALL = 100000;
    const int MEDIUM = 500000;
    const int LARGE = 1000000;

    cout << "\n=== BENCHMARK DE ALGORITMOS DE ORDENAMIENTO ===\n";
    cout << "Se probaran 3 arreglos: " << SMALL << ", " << MEDIUM << " y " << LARGE << " elementos.\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Heap Sort\n";
    cout << "6. Quick Sort\n";
    cout << "0. Salir\n";
    cout << "Algoritmo a probar: ";
    cin >> opcion;

    // Puntero a función para guardar qué algoritmo usar
    void (*algoritmoElegido)(vector<int> &) = nullptr;
    string nombreAlgoritmo = "";

    switch (opcion)
    {
    case 1:
        algoritmoElegido = insertionSort;
        nombreAlgoritmo = "Insertion Sort";
        break;
    case 2:
        algoritmoElegido = selectionSort;
        nombreAlgoritmo = "Selection Sort";
        break;
    case 3:
        algoritmoElegido = bubbleSort;
        nombreAlgoritmo = "Bubble Sort";
        break;
    case 4:
        algoritmoElegido = mergeSort;
        nombreAlgoritmo = "Merge Sort";
        break;
    case 5:
        algoritmoElegido = heapSort;
        nombreAlgoritmo = "Heap Sort";
        break;
    case 6:
        algoritmoElegido = quickSort;
        nombreAlgoritmo = "Quick Sort";
        break;
    default:
        cout << "Opcion invalida.\n";
        return 0;
    }

    cout << "\nIniciando pruebas para: " << nombreAlgoritmo << "\n";
    cout << "===================================================\n";

    // 1. Prueba Pequeña
    ejecutarPrueba(nombreAlgoritmo, algoritmoElegido, SMALL);

    // 2. Prueba Mediana
    ejecutarPrueba(nombreAlgoritmo, algoritmoElegido, MEDIUM);

    // 3. Prueba Grande
    ejecutarPrueba(nombreAlgoritmo, algoritmoElegido, LARGE);

    return 0;
}
