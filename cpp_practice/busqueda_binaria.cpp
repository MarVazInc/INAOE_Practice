#include <iostream> 
// Librería estándar para entrada/salida (imprimir en consola con cout)

using namespace std; 
// Permite usar cout, endl, etc. sin escribir std::cout por ejemplo

// --------------------------------------------------
// FUNCIÓN: Búsqueda binaria
// --------------------------------------------------

int busqueda(int* arr, int size, int target) {
    // arr → puntero (dirección del primer elemento del arreglo)
    // size → tamaño del arreglo (se pasa manualmente)
    // target → valor que queremos buscar

    int left = 0;              
    int right = size - 1;      
    // size - 1 porque los índices empiezan en 0

    while (left <= right) {
        // Mientras haya espacio de búsqueda

        int mid = (left + right) / 2;  
        // Punto medio del arreglo

        //if (arr[mid] == target) {
        if (*(arr + mid) == target) {
            return 1;  
            // 1 = encontrado (true)
        }
        else if (*(arr + mid) < target) {
            left = mid + 1;
            // Buscar en la mitad derecha
        }
        else {
            right = mid - 1;
            // Buscar en la mitad izquierda
        }
    }

    return 0;  
    // 0 = no encontrado (false)
}


// --------------------------------------------------
// FUNCIÓN 2: Imprimir arreglo con punteros
// --------------------------------------------------

//void imprimir(int* arr, int size) {
//    for (int i = 0; i < size; i++) {    // i =o inicializa en dirección base? i++ suma 1?
//        cout << *(arr +i) << endl;
//    }
//}


// --------------------------------------------------
// FUNCIÓN: Imprimir SIN usar índice (nivel bajo real)
// --------------------------------------------------


void imprimir(int* arr, int size) {

    int* ptr = arr;
        // ptr es otro puntero que apunta al inicio del arreglo
        // es como una "copia" de la dirección base  {
    
    for (int i = 0; i < size; i++) {
        // seguimos usando i SOLO para controlar cuántas veces iteramos
        // PERO NO para acceder al arreglo

        cout << *ptr << endl;
        // *ptr → accede al valor en la dirección actual

        ptr++;  
        // avanza el puntero a la siguiente posición de memoria
        // esto es equivalente a moverte al siguiente elemento del arregl
    }
}



// --------------------------------------------------
// FUNCIÓN PRINCIPAL (main)
// --------------------------------------------------

/*uso de memoria real (int arr[])
paso por puntero (int* arr)
control manual de tamaño
implementación de algoritmo clásico en C++ */

int main() {
    // Punto de entrada del programa

    int arr[] = {10,20,30,40,50};
    // Arreglo de enteros (memoria contigua)

    int size = 5;
    // Tamaño del arreglo (C++ no lo sabe automáticamente)

    cout << "Impresion del arreglo:" << endl; 
    imprimir(arr, size);
    
    cout << endl;

    int resultado1 = busqueda(arr, size, 4);
    // Llamada a la función → busca 4

    int resultado2 = busqueda(arr, size, 10);
    // Llamada a la función → busca 10

    cout << "Buscar 4: " << resultado1 << endl;
    // cout → imprime en consola
    // << → operador de inserción (envía datos a la salida)
    // endl → salto de línea

    cout << "Buscar 10: " << resultado2 << endl;
    return 0;
    // Indica que el programa terminó correctamente
}