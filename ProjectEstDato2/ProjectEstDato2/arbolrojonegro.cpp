#include <iostream>

// Declaracion de valores colores
enum Color
{
    ROJO,
    NEGRO
};

/// Clase Nodo
struct Nodo
{
    int dato;
    Color color;
    Nodo *izq, *der, *padre;

    Nodo(int valor)
    {
        // Cuando es nuevo inicia ROJO
        dato = valor;
        color = ROJO;
        izq = der = padre = nullptr;
    }

    /* data */
};
// CLASE Rojo Negro

class ArobolRN
{

private:
    Nodo *raiz;

    //
    // y es la izq
    void rotarizquierda(Nodo *x)
    {
        Nodo *y = x->der; // paso derecha
        x->der = y->izq;  // paso izquierda
        if (y->izq != nullptr)
            y->izq->padre = x;
        y->padre = x->padre;
        if (x->padre == nullptr)
            raiz = y;
        else if (x == x->padre->izq)
            x->padre->izq = y;
        else
            x->padre->der = y;
        y->izq = x;
        x->padre = y;
    }

    // x es la izq
    void rotarderecha(Nodo *y)
    {
        Nodo *x = y->izq; // paso derecha
        y->izq = x->der;  // paso izquierda
        if (x->der != nullptr)
            x->der->padre = y;
        x->padre = y->padre;
        if (y->padre == nullptr)
            raiz = x;
        else if (y == y->padre->izq)
            y->padre->izq = x;
        else
            y->padre->der = x;
        x->der = y;
        y->padre = x;
    }

    /// despues de reparar las propiedades
    void arreglarinsercion(Nodo *z)
    {
        while (z->padre != nullptr && z->padre->color == ROJO)
        {
            if (z->padre == z->padre->padre->izq)
            {
                Nodo *y = z->padre->padre->der;
                if (y != nullptr && y->color == ROJO)
                {
                    /// caso de que es rojo
                    z->padre->color = NEGRO;
                    y->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    z = z->padre->padre;
                }
                else
                {
                    if (z == z->padre->der)
                    {
                        // caso 2 dribling o zig zag o replace, de los datos
                        z = z->padre;
                        rotarizquierda(z);
                    }

                    z->padre->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    rotarderecha(z->padre->padre);
                }
            }
            else
            {
                Nodo *y = z->padre->padre->izq;
                if (y != nullptr && y->color == ROJO)
                {
                    z->padre->color = NEGRO;
                    y->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    z = z->padre->padre;
                }
                else
                {
                    if (z == z->padre->izq)
                    {
                        z = z->padre;
                        rotarderecha(z);
                    }
                    z->padre->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    rotarizquierda(z->padre->padre);
                }
            }
        }

        raiz->color = NEGRO; // La raiz o la base es negra.
    }

public:
    ArobolRN() { raiz = nullptr; }
    /// Insertar un nodo en el arbol
    // void
    void insertar(int valor)
    {
        Nodo *nuevo = new Nodo(valor);
        Nodo *y = nullptr;
        Nodo *x = raiz;

        // Insercion de datos
        while (x != nullptr)
        {
            y = x;
            if (nuevo->dato < x->dato)
                x = x->izq;
            else
                x = x->der;
        }

        nuevo->padre = y;
        if (y == nullptr)
            raiz = nuevo;
        else if (nuevo->dato < y->dato)
            y->izq = nuevo;
        else
            y->der = nuevo;

        ///
        arreglarinsercion(nuevo); // va hacer la base para los
    }

    // Crear el metodo de busqueda basado en orden binariol
    void enOrden(Nodo *nodo)
    {
        // con el enum, seleccionan ROJO o NEGRO
    }

    // Mostrar los datos del recorrdido en orden.

    /// imprimen el Color del dato...
    // aca llaman la funcion enOrden
};

int main()
{
    ArobolRN arbol;

    // Push de datos o insercion

    int datos[] = {10, 20, 30, 15, 25, 5};

    for (int x : datos)
    {
        arbol.insertar(x);
        // arbol.mostrarlos datoss
    }

    return 0;
}