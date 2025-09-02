//Nodo
//hijoiz hijoder
#include <iostream>
using namespace std;

//Definimos una clase, clase que represente el arbol

//Nodo de la raiz, del arbol binario.
struct Nodo //Nos ayuda a crear en memoria una estructura
{
	int dato;

	Nodo* izquierdo;
	Nodo* derecho;

	Nodo(int valor) {
		dato = valor;
		izquierdo = derecho = nullptr;//Creacion de un puntero nulo

	}

};


//Generamos la clase del arbol binario.
class ArbolBinario
{
	//Traemos nuestro 
	private:
		Nodo* raiz;


		//Existen funciones auxiliares
		//Insertar los datos
		Nodo* insertar(Nodo* nodo, int valor) {

			if (nodo == nullptr) {
				return new Nodo(valor);
			}

			if (valor < nodo->dato) {
				nodo->izquierdo = insertar(nodo->izquierdo, valor);
			}

			else if (valor > nodo->dato) {
				nodo->derecho = insertar(nodo->derecho, valor);
			}

			return nodo;

		}


		//Un recorrido del arbol binario, pasando por el nodo, y su izquierda y derecha
		void inorden(Nodo* nodo) {
			if (nodo != nullptr) {
				inorden(nodo->izquierdo);

				cout << nodo->dato << "---" << endl;

				inorden(nodo->derecho);

			}
		}


		public: ArbolBinario() {
			raiz = nullptr;
		}

		void insertar(int valor) {
			raiz = insertar(raiz, valor);
		}


		void mostrarInorden() {
			cout << "Recorrdo del arbol Binario ";

			inorden(raiz);

			cout << endl;

		}

};

int main() {

	ArbolBinario arbol;


	arbol.insertar(50);
	arbol.insertar(30);
	arbol.insertar(70);
	arbol.insertar(20);
	arbol.insertar(40);
	arbol.insertar(60);
	arbol.insertar(80);


	//Mostrar los datos de las funcion en orden.

	arbol.mostrarInorden();


	return 0;

}

