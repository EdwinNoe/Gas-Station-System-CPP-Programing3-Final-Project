#ifndef COMBUSTIBLE_H
#define COMBUSTIBLE_H

#include <iostream>
#include <fstream>
using namespace std;

class Combustible {
    private:
        string nombreCombustible;
        double cantidadDisponible;
        double precio;
        int totalVentasGasolinaUnitaria = 0;
        static int totalVentasGasolinaGeneral;

    public:
        // Constructor
        Combustible(string constNombreCombustible, double constCantidadDisponible, double constPrecio);

        // Getters
        string getNombreCombustible();
        double getCantidadDisponible();
        int getTotalVentasGasolinaUnitaria();
        int getTotalVentasGasolinaGeneral();
        double getPrecio();

        // Setters
        void setNombreCombustible(string nombre);
        void setCantidadDisponible(double cantidad);
        void setTotalVentasGasolinaUnitaria(int ventas);
        void setTotalVentasGasolinaGeneral(int ventas);
        void setPrecio(double nuevoPrecio);

        // Métodos personalizados
        void SumarVentaGasolinaGeneral();
        void SumarVentaGasolinaUnitaria();
        void imprimirInfoCombustibe();
        void ActualizarinstanciaEnArchivo(string  nombreAct);
};

#endif