#include "../TercerAvanceProyecto/include/Cliente.h"

int Cliente::Contador = 0; 

// Constructor
Cliente::Cliente(int constId, string constNombreCliente, int constEdad) {
    id = constId;
    nombreCliente = constNombreCliente;
    edad = constEdad;
    Contador = Contador + 1;
}

// Getters
int Cliente::getTotalClientes() {
    return Contador;
}

int Cliente::getId() {
    return id;
}

string Cliente::getNombreCliente() {
    return nombreCliente;
}

int Cliente::getEdad() {
    return edad;
}

// Setters
void Cliente::setId(int nuevoId) {
    id = nuevoId;
}

void Cliente::setNombreCliente(string nombre) {
    nombreCliente = nombre;
}

void Cliente::setEdad(int nuevaEdad) {
    edad = nuevaEdad;
}

// Métodos personalizados
double Cliente::calcularDescuentoTerceraEdad(double cantidadGasolina) {
    return (edad >= 65) ?  (cantidadGasolina * descuento) : 0;
}




// Polimorfismo
void Cliente::actualizarCliente() {}

//CRUD
void Cliente::Create(){}

void Cliente::Read(){}

void Cliente::Delete(int ){}

void Cliente::Update(int ){}

    // Implementación específica en clases derivadas
