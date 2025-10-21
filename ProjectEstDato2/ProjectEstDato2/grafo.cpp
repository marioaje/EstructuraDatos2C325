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

    // Busqueda DFS
    void DFS(int inicio)
    {
        vector<bool> visitado(numVertice, false);
        cout << "\nRecorrido DFS desde que nodo inicio " << inicio << ": ";
        DFSUtil(inicio, visitado);
        cout << endl;
    }

    void DFSUtil(int v, vector<bool> &visitado)
    {
        visitado[v] = true;
        cout << v << " ";
        for (auto vecino : listaAdyancecia[v])
        {
            if (!visitado[vecino.first])
            {
                DFSUtil(vecino.first, visitado);
            }
        }
    }

    // Parecido al DFS el de anchura (BFS)

    void BFS(int inicio)
    {
        vector<bool> visitado(numVertice, false);
        queue<int> cola;

        visitado[inicio] = true;
        cola.push(inicio);

        cout << "\nRecorrido BFS desde que nodo inicio " << inicio << ": ";

        while (!cola.empty())
        {
            int nodo = cola.front();
            cola.pop();
            cout << nodo << " ";

            for (auto vecino : listaAdyancecia[nodo])
            {
                if (!visitado[vecino.first])
                {
                    visitado[vecino.first] = true;
                    cola.push(vecino.first);
                }
            }
        }

        cout << endl;
    }

    // Verificar si un nodo esta conectado en el grafo
    bool estaContacto()
    {
        vector<bool> visitado(numVertice, false);
        // los nodos revisar si estan comunicados.
        // Busqueda con DFS
        DFSUtil(0, visitado);
        // Aristas
        for (bool v : visitado)
        {
            if (!v)
                return false; // Si hay un nodo que no visitamos, o que no esta conectado
        }

        return true;
    }
};

int main()
{
    Grafo g(6);
    // g.agregarArista(3, 4, 8);
    g.agregarArista(0, 1, 4);
    g.agregarArista(0, 4, 1);
    g.agregarArista(1, 2, 3);
    g.agregarArista(1, 3, 2);
    g.agregarArista(1, 4, 7);
    g.agregarArista(2, 3, 5);
    g.agregarArista(3, 4, 8);
    //    g.agregarArista(5, 6, 1);

    g.mostrarGrafo();

    g.DFS(0);
    g.BFS(0);

    if (g.estaContacto())
    {
        cout << "\n   ✅El grafo esta conectado.\n";
    }
    else
    {
        cout << "\n 🔥El grafo NO esta conectado.\n";
    }
}