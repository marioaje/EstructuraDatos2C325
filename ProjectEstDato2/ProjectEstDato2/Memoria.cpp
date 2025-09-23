#include <iostream>
#include <cstdlib> //malloc es para la memoria dinamica
using namespace std;

int main()
{
    int N; // el tamano el arreglo
    cout << "Ingrese sus datos" << endl;
    cin >> N; // utilizando lo que se llma la artimtia del puntero

    // reservamos de #include <cstdlib>//malloc es para la memoria dinamica
    int *arr1 = (int *)malloc(N * sizeof(int));

    // como verificar la memoria si tiene datos???
    if (arr1 == NULL)
    {
        cout << "Sin datos en la memoria malloc" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        arr1[i] = i + 6;
    }

    // Liberando la memoria
    free(arr1);

    system("pause");
    return 0;
}