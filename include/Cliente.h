#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <fstream>
using namespace std;

class Cliente {
    private:
        static int Contador; // Contador para asignar el índice y saber cuántos clientes hay en total
        int id;
        string nombreCliente;
        int edad;
        const double descuento = 0.25;

    public:
        // Constructor
        Cliente(int constId = Contador, string constNombreCliente = "Nombre Indefinido", int constEdad = -1);

        // Getters
        int getTotalClientes();
        int getId();
        string getNombreCliente();
        int getEdad();

        // Setters
        void setId(int nuevoId);
        void setNombreCliente(string nombre);
        void setEdad(int nuevaEdad);

        // Métodos personalizados
        
        virtual double calcularDescuentoTerceraEdad(double cantidadGasolina);


        // Polimorfismo
        virtual void actualizarCliente(); // Método para ser sobreescrito en clases derivadas

        virtual void Create();
        
        virtual  void Read();

        virtual  void Delete(int idUpdate);

        virtual void Update(int idUpdate);

};


#endif // CLIENTE_H