#include <iostream>
#include <cstdlib> // Las malloc, free calloc

#define INITIAL_SIZE 4; // Inicio de la tabla

// Similar a json valor, llaves

// Definicio de la estructura base
typedef struct
{
    int key;   // Seria como la variable a buscar
    int value; // La ruta
} Entry;

typedef struct
{
    Entry *table;
    int size;
    int count;
} HashTable;

unsigned int hash(int key, int size)
{

    // 🔹 ¿Cómo se hace?
    // 1. Se define una función hash para mapear claves a posiciones.
    // Ejemplo: h(k) = k % tamaño_tabla.
    return key % size;
}

HashTable *createTable(int size)
{
    HashTable *hashTablaDinamica = (HashTable *)malloc(sizeof(HashTable));
    hashTablaDinamica->size = size;
    hashTablaDinamica->count = 0;

    // generacio de la tabla
    /*     Entry *table;
        int size;
        int count;  */
    hashTablaDinamica->table = (Entry *)calloc(size, sizeof(Entry));

    return hashTablaDinamica;
}

void resize(HashTable *hashTablaDinamica);

void insert(HashTable *hashTablaDinamica, int key, int value)
{

    // Cuando la carga de la tabla es demasiado alta (por ejemplo, > 0.75), se hace rehashing
    if ((float)hashTablaDinamica->count / hashTablaDinamica->size > 0.7)
    {
        resize(hashTablaDinamica);
    }

    int idx = hash(key, hashTablaDinamica->size); // indice de la tabla de cuantos datos vienen

    while (hashTablaDinamica->table[idx].key != 0)
    {
        /* code */
        idx = (idx + 1) % hashTablaDinamica->size;
    }
    hashTablaDinamica->table[idx].key = key;
    hashTablaDinamica->table[idx].value = value;
    hashTablaDinamica->count++;
}

// de busqueda

int search(HashTable *hashTablaDinamica, int key)
{
    int idx = hash(key, hashTablaDinamica->size);
    int start = idx;

    while (hashTablaDinamica->table[idx].key != 0)
    {
        if (hashTablaDinamica->table[idx].key == key)
        {
            return hashTablaDinamica->table[idx].value;
            // hashTablaDinamica->table[idx].value);
        }
        idx = (idx + 1) % hashTablaDinamica->size;
        if (idx == start)
            break;
    }
    return -1;
}
// resize
void resize(HashTable *hashTablaDinamica)
{
    int oldSize = hashTablaDinamica->size;

    Entry *oldTable = hashTablaDinamica->table;
    // x2
    hashTablaDinamica->size *= 2;
    hashTablaDinamica->count = 0;
    hashTablaDinamica->table = (Entry *)calloc(hashTablaDinamica->size, sizeof(Entry));

    for (int i = 0; i < oldSize; i++)
    {
        if (oldTable[i].key != 0)
        {
            insert(hashTablaDinamica, oldTable[i].key, oldTable[i].value);
        }
    }
    free(oldTable);
}
int main()
{
    // #define INITIAL_SIZE 4; // Inicio de la tabla
    HashTable *hashTablaDinamica = createTable(4);

    // nuestros metodos de almacenamiento
    insert(hashTablaDinamica, 1, 10);
    insert(hashTablaDinamica, 2, 20);
    insert(hashTablaDinamica, 3, 30);
    insert(hashTablaDinamica, 4, 40);
    insert(hashTablaDinamica, 5, 50);

    std::cout << "Valor para la llave3: " << search(hashTablaDinamica, 3) << std::endl;
    std::cout << "Valor para la llave3: " << search(hashTablaDinamica, 300) << std::endl;

    free(hashTablaDinamica->table);
    free(hashTablaDinamica);

    return 0;
}