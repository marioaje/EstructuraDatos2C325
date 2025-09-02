#include <iostream>
using namespace std;


//Clase rerpresentacion de un arbol B(Balanceado)

//Ocupa el tamaño + la hoja(leaf)
class BTreeNode { //Arbol - N : nada->Arbol - N(Constructora)
	public:
		int* keys; //arreglo de claves.

		//altura : Arbol - N->entero(Analizadora)
		int t;//tamaño minimo ( defiene la cantidad de claves que puede tener)

		//Hijos : Arbol - N->Lista(Analizadora)
		BTreeNode** arregloAuxiliarC;  //Arreglo de los hijos ( la definicion de los punteros hijos)

		int n; //Numero de actual de las int* keys; //arreglo de claves.

		bool leaf;  //Indica el final de la rama por medio de una hoja

		BTreeNode* seach(int datoBusqueda);

		//t1 tamaño
		//leaf2 hoja
		BTreeNode(int t1, bool leaf2);


		//split o divisisor
		void splitChild(int i, BTreeNode* y);
		void insertarDatosNotNulls(int datoIngreso);
		
		//Los metodos de insertardatosnulls
		//los transversales
		void traverse();
		//Metodo de busqueda.

		/*2. Operaciones:
			raíz : Arbol - N->entero(Analizadora)
			HijoPos : Arbol - N, entero->entero(Analizadora)
			esVacio : Arbol - N -> bool(Analizadora)
			peso : Arbol - N->entero(Analizadora)			
			preorden : Arbol - N->nada(Salida pantalla)
			inorden : Arbol - N->nada(Salida pantalla)
			postorden : Arbol - N->nada(Salida pantalla)*/

};

//t2 tamaño
//leaf1 hoja 1
//Construir nuestro nodo similar a la raiz
//Constructor del nodo
BTreeNode::BTreeNode(int t1, bool leaf1) {
	t = t1;
	leaf = leaf1;
	//La LONGITUD: distancia entre el fin y el principio
	//del camino. (número de elementos – 1 )	
	keys = new int[2 * t - 1];
	//arreglo de claves.
	arregloAuxiliarC = new BTreeNode * [2 * t];

	n = 0;

}


//los transversales, recorre el arbol
void BTreeNode::traverse() {
	//C es para hoja
	int i;
	for (i = 0; i < n; i++) {
		//Estas cerrada rama???
		if (!leaf) {
			arregloAuxiliarC[i]->traverse();
		}
		cout << " --- " << keys[i];
	}

	if (!leaf) {
		arregloAuxiliarC[i]->traverse();
	}
}



//Verifica si tiene datos o  esta lleno y lo divide.
//int i la posicion
void BTreeNode::splitChild(int i, BTreeNode* y) {
	//agregamos los datos de la estructura
	//C es para hoja
	BTreeNode* z = new BTreeNode(y->t, y - leaf);

	//(número de elementos – 1)
	z->n = t - 1;

	//Primero recorremos la iz
	for (int j = 0; j < t; j++)
	{
		//(número de elementos + 1)
		z->keys[j] = y->keys[j + t];
	}

	//segundo de
	if (!y->leaf) {
		for (int j = 0; j < t; j++)
		{
			//(número de elementos + 1)
			z->arregloAuxiliarC[j] = y->arregloAuxiliarC[j + t];
		}
	}

	//(número de elementos – 1)
	y->n = t - 1;


	//Primero recorremos //C es para hoja la iz
	for (int j = 0; j < t; j++)
	{
		//(número de elementos + 1)
		arregloAuxiliarC[j + 1] = arregloAuxiliarC[j];
	}

	//(número de elementos – 1)
	//int i la posicion
	arregloAuxiliarC[i + 1] = z;



	//Primero recorremos //C es para hoja la de
	for (int j = 0; j < t; j++)
	{
		//(número de elementos + 1)
		keys[j + 1] = keys[j];
	}


	//(número de elementos – 1)
	keys[i] = y->keys[t - 1];

	n++; //Numero de actual de las int* keys; //arreglo de claves.

}



void BTreeNode::insertarDatosNotNulls(int datoIngreso) {
	//(número de elementos – 1)
	int i = n - 1;

	if (leaf) {
		//int* keys; //arreglo de claves.
		while (i >= 0 && keys[i] > datoIngreso) {
			keys[i + 1] = keys[i];
			i--;
		}


		keys[i + 1] = datoIngreso;

		//int n; //Numero de actual de las int* keys; //arreglo de claves.
		n++;
	}
	else {
		//int* keys; //arreglo de claves.
		while (i >= 0 && keys[i] > datoIngreso) {
			//keys[i + 1] = keys[i];
			i--;

			//Lo agrego en el arreglo auxiloiar letra C
			//	keys = new int[2 * t - 1];
			if (arregloAuxiliarC[i + 1]->n == 2 * t - 1) {
				splitChild(i + 1, arregloAuxiliarC[i + 1]);

				if (keys[i + 1] < datoIngreso) {
					i++;
				}
			}
			//Inserta en el arreglo auxiliar.
			arregloAuxiliarC[i + 1]->insertarDatosNotNulls(datoIngreso);

		}

	}




}



BTreeNode *BTreeNode::seach(int datoBusqueda) {
	int i = 0;
	while (i < n && keys[i]) {
		i++;
	}

	if (keys[i] == datoBusqueda) {
		return this;
	}

	if (leaf) {
		return nullptr;
	}

	return arregloAuxiliarC[i]->seach(datoBusqueda);
}
//Metodo de busqueda.




//Los metodos de insertardatosnulls
//split o divisisor
//los transversales
//Metodo de busqueda.



class BTree {
	BTreeNode *root;
	int t;//Tamano



public:
	BTree(int t1) {
		root = nullptr;
		t = t1;
	}

	//los transversales
	void traverse() {
		if (root != nullptr) {
			root->traverse();
		}
	}

	//BTreeNode *searc----

	void insertar(int datoingresado);

};



void BTree::insertar(int datoingresado) {
	if (root == nullptr) {
		root = new BTreeNode(t, true);
		root->keys[0] = datoingresado;
		root->n = 1; int n; //Numero de actual de las int* keys; //arreglo de claves.
	}
	else {
		if (root->n == 2 * t - 1) {
			BTreeNode* estructuraTemporal = new BTreeNode(t, false);
			estructuraTemporal->arregloAuxiliarC[0] = root;

			estructuraTemporal->splitChild(0, root);

			int i = 0;

			if (estructuraTemporal->keys[0] < datoingresado)
			{
				i++;
			}

			estructuraTemporal->arregloAuxiliarC[i]->insertarDatosNotNulls(datoingresado);


			root = estructuraTemporal;


		}
		else {
			root->insertarDatosNotNulls(datoingresado);
		}



	}
}



int main() {

	BTree t(3);//el minimo de tamano que tiene

	t.insertar(10);
	t.insertar(20);
	t.insertar(5);
	t.insertar(6);
	t.insertar(12);
	t.insertar(30);
	t.insertar(7);
	t.insertar(17);
	t.insertar(18);

	
	
	cout << "Recorrido de datos del arbol B:";
	t.traverse();


	return 0;


}










//
////split o divisisor
//void splitChild(int i, BTreeNode* y);
//void insertarDatosNotNulls(int datoIngreso);
////Los metodos de insertardatosnulls
////los transversales

//void traverse();