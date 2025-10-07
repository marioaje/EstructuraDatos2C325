#include <iostream>
#include <thread>    //Libreria de hilos
#include <semaphore> //Semaforo y  sincronizacion

std::counting_semaphore<1> semaforo(1); // Semaforo de control

// acceso a los recurso compartidos
int recursosCompartidos = 0;

// Tareas de ejecucion de acceso
void tarea(const std::string &nombre)
{

    for (int i = 0; i < 4; i++)
    {
        semaforo.acquire(); // Esperar turno, recursos, hacer fila;

        recursosCompartidos++; // Contador de recursos
        std::cout << nombre << "acceso al recurso: " << recursosCompartidos << std::endl;
        semaforo.release(); // liberar los recursos
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main()
{

    // o recorrerlo dinamicamente y generarlo con un foreach
    std::thread hilo1(tarea, "Nombre del Hilo 1 ");
    std::thread hilo2(tarea, "Nombre del Hilo 2 ");
    std::thread hilo3(tarea, "Nombre del Hilo 3 ");

    hilo1.join();
    hilo2.join();
    hilo3.join();

    std::cout << " Fin del recurso " << recursosCompartidos << std::endl;

    return 0;
}