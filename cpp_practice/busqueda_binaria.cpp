#include <iostream> 
// Librería estándar para entrada/salida (cout, endl)

using namespace std; 
// Evita escribir std::cout cada vez


// ==================================================
// FUNCIÓN: Búsqueda binaria (usa índices)
// ==================================================

int busqueda(int* arr, int size, int target) {
    // arr → dirección base del arreglo
    // size → número de elementos
    // target → valor a buscar

    int left = 0;              
    int right = size - 1;      
    // right = último índice válido

    while (left <= right) {
        // Mientras exista un rango válido de búsqueda

        int mid = (left + right) / 2;  
        // mid es un ÍNDICE, no un puntero
        // Acceso equivalente:
        // arr[mid]  <=>  *(arr + mid)

        if (*(arr + mid) == target) {
            // Si el valor en la posición mid coincide
            return 1;  
        }
        else if (*(arr + mid) < target) {
            // Si el valor medio es menor, descarta la mitad izquierda
            left = mid + 1;
        }
        else {
            // Si es mayor, descarta la mitad derecha
            right = mid - 1;
        }
    }

    return 0;  
    // No encontrado
}



// ==================================================
// FUNCIÓN 1: Imprimir usando índice (forma clásica)
// ==================================================

// Esta versión está comentada para comparar con la otra
/*
void imprimir(int* arr, int size) {
    // Aquí SÍ usamos un índice i
    // i NO es una dirección, es un contador

    for (int i = 0; i < size; i++) {
        // arr[i] significa:
        // *(arr + i) → desplazamiento desde la dirección base

        cout << *(arr + i) << endl;
    }
}
*/


// ==================================================
// FUNCIÓN 2: Imprimir usando puntero que avanza
// ==================================================

void imprimir(int* arr, int size) {

    int* ptr = arr;
    // ptr apunta al inicio del arreglo
    // ptr y arr contienen la MISMA dirección al inicio
    // pero ptr SÍ lo vamos a mover

    for (int i = 0; i < size; i++) {
        // i solo controla cuántas veces iteramos
        // NO se usa para acceder al arreglo

        cout << *ptr << endl;
        // *ptr → valor en la dirección actual

        ptr++;  
        // ptr avanza al siguiente entero en memoria
        // equivalente a arr[i+1]
    }
}



// ==================================================
// FUNCIÓN 3: Imprimir sin índice (puntero puro)
// ==================================================

void imprimir2(int* arr, int size) {

    int* ptr = arr;
    // ptr inicia en la dirección base

    while (ptr < arr + size) {
        // arr + size = dirección justo DESPUÉS del último elemento
        // condición 100% basada en direcciones, no en índices

        cout << *ptr << endl;
        // imprime el valor apuntado

        ptr++;  
        // avanza al siguiente entero en memoria
    }
}



// ==================================================
// FUNCIÓN PRINCIPAL
// ==================================================

int main() {

    int arr[] = {10,20,30,40,50};
    // Arreglo en memoria contigua

    int size = 5;
    // C++ NO sabe el tamaño automáticamente al pasarlo a funciones

    cout << "Impresion del arreglo:" << endl; 
    imprimir(arr, size);
    // Usa puntero que avanza + for

    cout << endl;

    cout << "Impresion del arreglo2:" << endl; 
    imprimir2(arr, size);
    // Usa puntero que avanza + while

    cout << endl;

    int resultado1 = busqueda(arr, size, 4);
    // Busca 4 → NO está en el arreglo

    int resultado2 = busqueda(arr, size, 10);
    // Busca 10 → SÍ está (posición 0)

    cout << "Buscar 4: " << resultado1 << endl;
    cout << "Buscar 10: " << resultado2 << endl;

    return 0;
}
