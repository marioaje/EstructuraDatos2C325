#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// se crea el valor del orden

const int ORDEN = 3; // el abrol B de orden de 3, si cambiamos cambia el valor

// Clase del NodoB
class NodoB
{
public:
    vector<int> claves;    /// Las claves del nodo, los valores
    vector<NodoB *> hijos; // Punteros hijo
    bool hoja;             // las hojas( es o no es hoja)

    NodoB(bool esHoja)
    {
        hoja = esHoja;
    }
};

// Clase del Arbol B
class ArbolB
{
private:
    NodoB *raiz;

public:
    ArbolB()
    {
        raiz = new NodoB(true); // Nueva hojao donde empieza la raiz.
    }

    // Nuestras funciones CRUD
    void insertar(int k)
    {
        if (raiz->claves.size() == ORDEN - 1) // esto es una validacion que si la raiz esta llena o no
        {
            NodoB *nuevaRaiz = new NodoB(false); // este es el padre
            nuevaRaiz->hijos.push_back(raiz);
            // deveriamos dividirlos
            // void  dividiHijo(NodoB* padre, int i, NodoB* hijo){
            dividiHijo(nuevaRaiz, 0, raiz);
            raiz = nuevaRaiz;
        }
        // inserta datos que no esten llenos
        //    void insertarNoLleno(NodoB* nodo, int k){
        insertarNoLleno(raiz, k);
    }

    void mostrar()
    {
        // Funcion de muestra de datos de la raiz
        mostrarNodo(raiz, 0);
    }

    // deveriamos dividirlos los hijos si estan llenos
    void dividiHijo(NodoB *padre, int i, NodoB *hijo)
    {
        int mid = (ORDEN - 1) / 2;
        NodoB *nuevo = new NodoB(hijo->hoja);

        // Lo que se hace es moverlo hacia la mitad, de las claves ( los valores)
        nuevo->claves.assign(hijo->claves.begin() + mid + 1, hijo->claves.end());
        int claveMedio = hijo->claves[mid];
        hijo->claves.resize(mid); // se redimensiona a si mismo
        // una pregunta en la cual indique que si es el hijo o lo movera
        // Es hoja o no es hoja
        if (!hijo->hoja)
        {
            // similar a claves.assign(hijo->claves.begin() + mid + 1, hijo->claves.end());
            nuevo->hijos.assign(hijo->hijos.begin() + mid + 1, hijo->hijos.end());
            hijo->hijos.resize(mid + 1); // se redimensiona a si mismo
        }

        // nuestra seccion de insercio de datos claves para el padre int i
        padre->claves.insert(padre->claves.begin() + i, claveMedio);
        padre->hijos.insert(padre->hijos.begin() + i + 1, nuevo); // trae   NodoB *nuevo = new NodoB(hijo->hoja);
    }

    // inserta datos que no esten llenos
    void insertarNoLleno(NodoB *nodo, int k)
    {

        if (nodo->hoja)
        {
            nodo->claves.insert(upper_bound(nodo->claves.begin(), nodo->claves.end(), k), k); // Seccion de busqueda upper_bound
        }
        else
        {
            int i = upper_bound(nodo->claves.begin(), nodo->claves.end(), k) - nodo->claves.begin(); // Seccion de busqueda upper_bound

            if (nodo->hijos[i]->claves.size() == ORDEN - 1)
            {
                dividiHijo(nodo, i, nodo->hijos[i]);
                if (k > nodo->claves[i])
                {
                    i++;
                }
            }
            insertarNoLleno(nodo->hijos[i], k);
        }
    }

    // mostrarNodo(raiz, 0);
    void mostrarNodo(NodoB *nodo, int nivel)
    {
        // recursividad de lectura.

        cout << string(nivel * 4, ' ');
        cout << "[";
        for (int clave : nodo->claves)
        {
            cout << clave << ", ";
        }
        cout << "]" << endl;

        if (!nodo->hoja)
        {
            for (NodoB *hijo : nodo->hijos)
            {

                // Los niveles le suma un nivel
                mostrarNodo(hijo, nivel + 1);
            }
        }
    }
};

// Setup
int main()
{
    ArbolB arbol;

    // Ingreso de datos
    vector<int> datos = {10, 20, 5, 8, 12, 25, 30};

    for (int x : datos)
    {
        arbol.insertar(x);
    }

    cout << "Arbol tipo B ordenado 3" << endl;

    arbol.mostrar();

    return 0;
}
