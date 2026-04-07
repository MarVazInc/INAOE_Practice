#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main() {
    stack<string> s;  
    
    // Simulamos operaciones
    s.push("A");
    s.push("B");
    s.push("1");
    s.push("2");
    s.push("C");

    // Abrimos archivo para escribir
    ofstream outfile("stack.txt");

    // Guardamos los elementos de la pila en el archivo de arriba a abajo
    while (!s.empty()) {
        outfile << s.top() << " "; // Escribe el elemento superior de la pila en el archivo
        s.pop(); // Elimina el elemento superior de la pila
    }
    
    outfile.close();

    // Imprimir los números en orden inverso
    cout << "Stack guardado en archivo stack.txt" << endl;

    return 0;
}