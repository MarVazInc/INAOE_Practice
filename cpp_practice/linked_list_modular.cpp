#include <iostream>
using namespace std;

// --------------------------------------------------
// ESTRUCTURA: Nodo
// --------------------------------------------------
struct Node {
    int data;      // valor almacenado
    Node* next;    // dirección del siguiente nodo
};


// --------------------------------------------------
// CREAR NODO
// --------------------------------------------------
Node* crear(int valor)  {
    
    Node* x = new Node();  
    // 🔥 Reservas memoria en el HEAP
    // x guarda la DIRECCIÓN de ese bloque

    x->data = valor;       
    // Guardas el valor dentro del nodo

    x->next = NULL;        
    // Inicialmente no apunta a nadie (fin de lista)

    return x;              
    // Regresas la dirección del nodo creado
}


// --------------------------------------------------
// INSERTAR AL INICIO
// --------------------------------------------------
void insertar_inicio(Node*& head, int valor)    {

    Node* x = crear(valor);  
    // Crear nuevo nodo

    x->next = head;         
    // 🔥 Conectas nuevo nodo al inicio actual
    // x → antiguo head

    head = x;               
    // 🔥 Mueves el inicio de la lista
    // ahora head apunta a x

}


// --------------------------------------------------
// INSERTAR AL FINAL
// --------------------------------------------------
void insertar_final(Node*& head, int valor) {

    Node* x = crear(valor); 
    // Crear nuevo nodo

    if (head == NULL)   {
        head = x;
        return;
        // 🔥 Caso especial:
        // lista vacía → el nuevo nodo es toda la lista
    }
    
    Node* y = head;  
    // Puntero auxiliar para recorrer

    while (y->next != NULL) {   
        y = y->next;
        // 🔥 Avanza hasta el último nodo
    }

    y->next = x;
    // 🔥 Conecta el último nodo con el nuevo
}


// --------------------------------------------------
// BUSCAR
// --------------------------------------------------
int buscar(Node* head, int target)      {
    
    Node* current = head;
    // Empiezas desde el inicio

    while (current != NULL) {
        // Mientras haya nodos

        if (current->data == target) {
            return 1;
            // 🔥 Encontrado
        }

        current = current->next;
        // 🔥 Avanzar al siguiente nodo
    }

    return 0;
    // 🔥 No encontrado
}


// --------------------------------------------------
// ELIMINAR
// --------------------------------------------------
int eliminar(Node*& head, int target)   {
    
    Node* current = head;
    Node* prev = NULL;
    // current → nodo actual
    // prev → nodo anterior (para reconectar)

    while (current != NULL) {

        if (current->data == target) {

            if (prev == NULL) {
                head = current->next;
                // 🔥 Estás eliminando el PRIMER nodo
                // head salta al siguiente
            }
            else {
                prev->next = current->next;
                // 🔥 Saltas el nodo actual
                // prev → next
            }

            delete current;
            // 🔥 Libera memoria (muy importante)

            return 1;
        }

        prev = current;
        // 🔥 Guardas el nodo actual como anterior

        current = current->next;
        // 🔥 Avanzas
    }

    return 0;
}


// --------------------------------------------------
// IMPRIMIR
// --------------------------------------------------
void imprimir(Node* head)   {

    Node* current = head;

    while (current != NULL) {
        cout << current->data << endl;
        // Imprime el valor del nodo

        current = current->next;        
        // Avanza
    }

    cout << "---" << endl;
}


// --------------------------------------------------
// MAIN
// --------------------------------------------------
int main()  {

    Node* head = NULL;
    // Lista vacía

    insertar_inicio(head, 10);
    insertar_inicio(head, 5);
    insertar_final(head, 99);

    imprimir(head);

    eliminar(head, 10);

    imprimir(head);

    return 0;
}