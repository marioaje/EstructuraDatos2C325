#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Sirve para clases o entidades
class Grafo
{

private:
    int numVertice;
    // vecino y peso vector
    vector<vector<pair<int, int>>> listaAdyancecia;

public:
    // Grafo
    Grafo(int vertice)
    {
        numVertice = vertice;
        listaAdyancecia.resize(vertice); // reajustece con la cantidad de vertices
    }

    // Inseertar, Mostrar

    void agregarArista(int origen, int destino, int peso)
    {
        listaAdyancecia[origen].push_back({destino, peso});
        listaAdyancecia[destino].push_back({destino, peso}); // no dirigdo
    }

    void mostrarGrafo()
    {
        cout << "Lista de adyancencia del Grafo: \n";

        for (int i = 0; i < numVertice; i++)
        {
            /* code */
            cout << "Nodo: <- " << i << " ->";

            for (auto vecino : listaAdyancecia[i])
            {
                cout << "(-- Origen: " << vecino.first << ", peso:" << vecino.second << "--)";
            }

            cout << endl;
        }
    }
};

int main()
{
    Grafo g(5);
    g.agregarArista(3, 4, 8);
    g.agregarArista(0, 1, 4);
    g.agregarArista(0, 4, 1);
    g.agregarArista(1, 2, 3);
    g.agregarArista(1, 3, 2);
    g.agregarArista(1, 4, 7);
    g.agregarArista(2, 3, 5);
    g.agregarArista(3, 4, 8);

    g.mostrarGrafo();
}