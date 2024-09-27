#ifndef CLIENTE_CORPORATIVO_H
#define CLIENTE_CORPORATIVO_H

#include <iostream>
#include <string>
#include <fstream>

#include "./Cliente.h" // Incluye la clase base Cliente

using namespace std;

class ClienteCorporativo : public Cliente {
    private:
        static int contadorClinteCorp;
        string nombreEmpresa;
        double creditoDisponible;
    public:
        // Constructor
        ClienteCorporativo(string contsNombreEmpresa = "Nombre Empresa no Ingresada", double cosntCreditoDisponible = 0);

        // Getters
        string getNombreEmpresa();
        double getCreditoDisponible();
        int getContadorClinteCorp();

        // Setters
        void setNombreEmpresa(string nuevoNombreEmpresa);
        void setCreditoDisponible(double nuevoCreditoDisponible);

        // Métodos personalizados
        void aplicarCredito(double montoAplicar);
        double RecargarCredito(double montoComprar);
        void actualizarCliente(string actNombre, int actedad, string actNombreEmpresa, double actCreditoDisponible);
        void ActualizarinstanciaEnArchivo (int id);
        //CRUD
        void Create() override;
        
        void Read() override;

        void Delete(int idDelete) override;

        void Update(int idModificar) override;

};

#endif // CLIENTE_CORPORATIVO_H
