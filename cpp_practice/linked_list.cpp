#include <iostream>
using namespace std;

// --------------------------------------------------
// ESTRUCTURA: Nodo de lista enlazada
// --------------------------------------------------
struct Node {
    int data;   // Valor almacenado en el nodo.
                // Este es el DATO real que guarda la estructura.
                // Puede ser cualquier tipo (int, float, struct, etc.)
                // En una lista enlazada, cada nodo guarda un valor.

    Node* next; // Puntero al siguiente nodo de la lista.
                // IMPORTANTE:
                // - No es un nodo, es una DIRECCIÓN en memoria.
                // - next apunta al siguiente elemento de la lista.
                // - Si next == NULL → este nodo es el ÚLTIMO.
                //
                // Esto permite que los nodos NO estén juntos en memoria.
                // Cada nodo sabe dónde está el siguiente gracias al puntero.
};


// --------------------------------------------------
// BUSCAR EN ESTRUCTURA: Busqueda
// --------------------------------------------------

int buscar(Node* head, int target) {
    // Esta función RECORRE una lista enlazada desde el nodo 'head'
    // y busca si existe un nodo cuyo 'data' sea igual a 'target'.
    // Si lo encuentra → regresa 1
    // Si no lo encuentra → regresa 0
    // Complejidad: O(n)

    Node* current = head;   
    // 'current' es un puntero que empieza en el primer nodo de la lista.
    // IMPORTANTE:
    // No estamos copiando la lista, solo copiamos la DIRECCIÓN del primer nodo.
    // 'current' sirve para recorrer sin perder 'head'.

    while (current != NULL) {
        // Recorremos la lista mientras no lleguemos al final.
        // NULL indica el final de la estructura.
        // Si current == NULL → ya no hay más nodos.

        if (current->data == target) {
            // Comparamos el valor del nodo actual con el valor buscado.
            // current->data se usa porque 'current' es un puntero.
            return 1;  
            // Si encontramos el valor, regresamos 1 inmediatamente.
            // No seguimos recorriendo.
        }

        current = current->next;
        // Avanzamos al siguiente nodo.
        // Si olvidas esta línea → loop infinito.
        // Esto es equivalente a i++ en un arreglo, pero en listas enlazadas.
    }

    return 0;
    // Si salimos del while significa que recorrimos toda la lista
    // y nunca encontramos el valor → regresamos 0.
}


// --------------------------------------------------
// ELIMINAR NODE EN ESTRUCTURA: Eliminar
// --------------------------------------------------

int eliminar(Node*& head, int target) { 
    // Node*& head → referencia a puntero
    // Esto permite MODIFICAR el puntero head original.
    // Si no fuera referencia (&), no podrías cambiar head desde aquí.
    // Necesario para eliminar el PRIMER nodo de la lista.

    // Inicializamos los punteros de recorrido
    Node* current = head;  
    Node* prev = NULL;

    // current → nodo que estoy revisando en este momento
    // prev → nodo anterior (sirve para reconectar la lista al eliminar)

    // Recorremos la lista nodo por nodo
    while (current != NULL) {

        // Si encontramos el valor buscado
        if (current->data == target) {

            // CASO 1: El nodo a eliminar es el PRIMERO (head)
            if (prev == NULL) { 
                head = current->next; 
                // Explicación:
                // - prev == NULL significa que current ES head.
                // - Para eliminarlo, simplemente movemos head al siguiente nodo.
                // - El nodo original queda "desconectado".
                //
                // Antes:
                // head → [current] → next
                //
                // Después:
                // head → next
            }

            // CASO 2: El nodo está en medio o al final
            else {
                prev->next = current->next;
                // Explicación:
                // - Saltamos el nodo actual.
                // - Reconectamos prev directamente con current->next.
                //
                // Antes:
                // prev → current → next
                //
                // Después:
                // prev → next
            }
            
            delete current;     
            // MUY IMPORTANTE:
            // - Libera la memoria del nodo eliminado.
            // - Si no haces esto → MEMORY LEAK.
            // - En listas enlazadas SIEMPRE debes liberar memoria manualmente.

            return 1;   
            // Terminamos la función porque ya eliminamos el nodo.
            // Solo se elimina la primera coincidencia.
        }
        
        // Avanzamos los punteros para seguir recorriendo
        prev = current;          // prev se mueve al nodo actual
        current = current->next; // current avanza al siguiente nodo
    }

    return 0;
    // Si salimos del while:
    // - Recorrimos toda la lista
    // - Nunca encontramos el valor
    // → Regresamos 0 para indicar "no encontrado"
}

// Nota general:
// Aquí NO mueves datos.
// Mueves DIRECCIONES (punteros).
// Esa es la esencia de las listas enlazadas.



// --------------------------------------------------
// FUNCIÓN PRINCIPAL
// --------------------------------------------------
int main() {

    // --------------------------------------------------
    // CREACIÓN DE NODOS EN MEMORIA (HEAP)
    // --------------------------------------------------
    Node* n1 = new Node();  
    // new Node() → solicita memoria dinámica (heap)
    // Devuelve una DIRECCIÓN → por eso usamos punteros

    Node* n2 = new Node();  
    Node* n3 = new Node();  
    // Estos tres nodos formarán la lista base

    Node* nuevo = new Node();       
    // Nodo que insertaremos al INICIO de la lista

    Node* nuevo_final = new Node(); 
    // Nodo que insertaremos al FINAL de la lista


    // --------------------------------------------------
    // ASIGNACIÓN DE VALORES A LOS NODOS
    // --------------------------------------------------
    nuevo->data = 5;   // Nodo que irá al inicio

    n1->data = 10;  
    // "->" accede a atributos de un objeto vía puntero
    // Equivalente a: (*n1).data

    n2->data = 20;
    n3->data = 30;

    nuevo_final->data = 99;  // Nodo que irá al final


    // --------------------------------------------------
    // CONEXIÓN DE NODOS (CREACIÓN DE LA LISTA)
    // --------------------------------------------------
    n1->next = n2;  
    // Aunque no están contiguos en memoria,
    // quedan conectados mediante punteros

    n2->next = n3;
    n3->next = NULL;  
    // NULL marca el FINAL de la lista
    // Sin NULL → loop infinito o acceso inválido

    nuevo_final->next = NULL;  
    // El nodo final siempre debe apuntar a NULL


    // --------------------------------------------------
    // HEAD (PUNTO DE ENTRADA A LA LISTA)
    // --------------------------------------------------
    Node* head = n1;  
    // head NO es la lista
    // head es la DIRECCIÓN del primer nodo
    // Si pierdes head → pierdes TODA la lista


    // --------------------------------------------------
    // INSERCIÓN AL INICIO
    // --------------------------------------------------
    nuevo->next = head;  
    // Paso 1: conectar el nuevo nodo al inicio actual

    head = nuevo;        
    // Paso 2: mover head al nuevo nodo
    //
    // ORDEN IMPORTANTE:
    // Si haces head = nuevo primero → pierdes la lista original


    // --------------------------------------------------
    // INSERCIÓN AL FINAL
    // --------------------------------------------------
    Node* temp = head;  
    // Puntero auxiliar para recorrer la lista
    // Nunca recorrer con head directamente

    while (temp->next != NULL) {  
        // Buscamos el nodo cuyo next es NULL (último nodo)
        temp = temp->next;  
        // Avanzamos nodo por nodo
    }

    temp->next = nuevo_final;  
    // Conectamos el nuevo nodo al final
    // Esta operación SIEMPRE debe hacerse FUERA del while


    // --------------------------------------------------
    // ELIMINAR UN ELEMENTO
    // --------------------------------------------------
    cout << "Eliminar 20: " << eliminar(head,20) << endl;
    // Llamamos a eliminar ANTES del recorrido
    // porque eliminar modifica enlaces internos


    // --------------------------------------------------
    // RECORRIDO DE LA LISTA
    // --------------------------------------------------
    Node* current = head;  
    // Puntero para recorrer sin modificar head

    while (current != NULL) {  
        // Mientras existan nodos por recorrer

        cout << current->data << endl;  
        // Imprime el valor del nodo actual

        current = current->next;  
        // Avanza al siguiente nodo
        //
        // Si hay un error en los enlaces → loop infinito
    }


    // --------------------------------------------------
    // BÚSQUEDA EN LA LISTA
    // --------------------------------------------------
    cout << "Buscar 30: " << buscar(head,30) <<  endl;
    // Si 20 fue eliminado → debe imprimir 0

    cout << "Buscar 100: " << buscar(head,100) << endl;
    // 100 no existe → imprime 0


    // --------------------------------------------------
    // FIN DEL PROGRAMA
    // --------------------------------------------------
    return 0;  
    // Indica ejecución exitosa
}
