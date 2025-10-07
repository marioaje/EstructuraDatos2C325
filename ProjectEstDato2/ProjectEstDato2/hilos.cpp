#include <iostream>
#include <thread>    //Libreria de hilos
#include <semaphore> //Semaforo y  sincronizacion

counting_semaphore<1> semaforo(1); // Semaforo de control

// acceso a los recurso compartidos
int recursosCompartidos = 0;

// Tareas de ejecucion de acceso
void tarea(const string &nombre)
{

    for (int i = 0; i < 3; i++)
    {
        semaforo.acquire(); // Esperar turno, recursos, hacer fila;

        recursosCompartidos++; // Contador de recursos
        cout << nombre << "acceso al recurso: " << recursosCompartidos << endl;
        semaforo.release(); // liberar los recursos
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main()
{

    // o recorrerlo dinamicamente y generarlo con un foreach
    thread hilo1(tarea, "Nombre del Hilo 1 ");
    thread hilo2(tarea, "Nombre del Hilo 2 ");
    thread hilo3(tarea, "Nombre del Hilo 3 ");

    hilo1.join();
    hilo2.join();
    hilo3.join();

    cout << " Fin del recurso " << recursosCompartidos << endl;

    return 0;
}