#include <iostream> // Incluimos la biblioteca para entrada y salida
#include <fstream> // Incluimos la biblioteca para manejo de archivos
using namespace std; // Usamos el espacio de nombres estándar para evitar escribir std:: antes de cada uso

int main() {
    // Abrimos el archivo para leer
    ofstream file("ops.txt");

    file << "push A\n"; // Escribimos la operación push A en el archivo
    file << "push B\n"; // Escribimos la operación push B en el archivo
    file << "push C\n"; // Escribimos la operación push C en el archivo
    file << "pop\n";    // Escribimos la operación pop en el archivo
    file << "push D\n"; // Escribimos la operación push D en el archivo

    file.close(); // Cerramos el archivo después de escribir

    cout << "Operaciones guardadas en ops.txt" << endl;
    return 0;
}