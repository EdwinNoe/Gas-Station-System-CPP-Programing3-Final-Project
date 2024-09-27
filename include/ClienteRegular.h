#ifndef CLIENTE_REGULAR_H
#define CLIENTE_REGULAR_H

#include <iostream>
#include <string>
#include <fstream>

#include "./Cliente.h" // Incluye la clase base Cliente

using namespace std;

class ClienteRegular : public Cliente {
    private:
        double puntos;
        static int contadorClinteReg;
    public:
        // Constructor
        ClienteRegular(double constPuntos = 0);

        // Getters
        double getPuntos();
        int getContadorClinteReg();

        // Setters
        void setPuntos(double nuevoPuntos);

        // Métodos personalizados
        void canjearPuntos(double puntosAplicar);
        void acumularPuntos(double montoCompra);
        void actualizarCliente(string actNombre, int actedad, double actPuntos);
        void ActualizarinstanciaEnArchivo (int id);

        
        //CRUD
        void Create();
        
        void Read();

        void Delete(int idDelete);

        void Update(int idModificar);
};

#endif // CLIENTE_REGULAR_H
