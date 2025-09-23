#include <iostream>
using namespace std;

int main()
{
    const int N = 6; // el tamano el arreglo
    int arr[N];      // declarar el tipo
    int *p = arr;    // Crear nuestro puntero que apunta al inicio de nuestra variable{ el arreglo}

    // Leer datos???
    cout << "Ingrese sus datos" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> *(p + i); // utilizando lo que se llma la artimtia del puntero
    }

    // podemos imprimir los datos
    for (int i = 0; i < N; i++)
    {
        cout << *(p + i); // accedemos al puntero o recoremos el puntero
    }

    system("pause");
    return 0;
}