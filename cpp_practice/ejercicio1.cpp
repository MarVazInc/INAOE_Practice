#include <iostream>
#include <vector>

// Esta función usa "Paso por Referencia" (&)
// Es eficiente porque NO copia el arreglo, solo accede a el.
void elevar_al_cuadrado_modular(int& n, int q) {
    n = (n * n) % q;
}

int main() {
    int q = 8380417; //El módulo de Dilithium
    int x = 1000;

    std::cout << "Valor original de x: " << x << std::endl;

    // Llamamos a la función que modifica x por referencia.
    // Como usamos '&', 'x' cambiará permanentemente.
    elevar_al_cuadrado_modular(x, q);

    std::cout << "Valor modificado de x - elevado al cuadrado: " << x << std::endl;

    return 0;
}