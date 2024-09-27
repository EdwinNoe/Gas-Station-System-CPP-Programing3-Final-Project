#include "../TercerAvanceProyecto/include/ClienteRegular.h"

// Inicialización de miembro estático
int ClienteRegular::contadorClinteReg = 0;

// Constructor
ClienteRegular::ClienteRegular(double constPuntos) {
    puntos = constPuntos;
    contadorClinteReg = contadorClinteReg + 1;
}

// Getters
double ClienteRegular::getPuntos() {
    return puntos;
}

int ClienteRegular::getContadorClinteReg() {
    return contadorClinteReg;
}

// Setters
void ClienteRegular::setPuntos(double nuevoPuntos) {
    puntos = nuevoPuntos;
}

// Métodos personalizados
void ClienteRegular::canjearPuntos(double puntosAplicar) {
    if (puntosAplicar > puntos) {
        cout << "Usted no posee la cantidad necesaria de puntos. ";
        if (puntosAplicar < 100) {
            cout << "Error, tiene que canjear mínimo 100 puntos." << endl;
        }
    } else {
        puntos = puntos - puntosAplicar;
    }
    cout << "Puntos Canjeados Exitosamente " << endl;
    cout << "Puntos actuales: " << puntos << " Puntos" << endl;
}

void ClienteRegular::acumularPuntos(double montoCompra) {
    puntos = puntos + montoCompra * 0.10;
    cout << "Se acumularon " << montoCompra * 0.10 << " puntos" << endl;
}


void ClienteRegular::ActualizarinstanciaEnArchivo(int idUpdate) {
    ifstream leerArchivo("C_Regular.txt");
    ofstream tempArchivo("temp.txt");

    if (!leerArchivo || !tempArchivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    int idModificar;
    string nombreModificar;
    int edadModificar;
    string empresaModificar;
    double creditoModificar;

    bool found = false;

    while (leerArchivo >> idModificar >> nombreModificar >> edadModificar >> creditoModificar) {
        if (idModificar == idUpdate) {
            // Modificar los datos del cliente
            idModificar=getId();
            nombreModificar=getNombreCliente();
            edadModificar=getEdad();
            creditoModificar=getPuntos();
            found = true;
        }
        // Guardar los datos en el archivo temporal, ya sea modificados o no
        tempArchivo << idModificar << " " << nombreModificar << " " << edadModificar << " " << creditoModificar << "\n";
    }

    leerArchivo.close();
    tempArchivo.close();


    remove("C_Regular.txt");
    rename("temp.txt", "C_Regular.txt");

    if (found) {
        cout << "Cliente modificado exitosamente." << endl;
    } else {
        cout << "Cliente con ID  no encontrado." << endl;
    }
}


//polimofismo
void ClienteRegular::actualizarCliente(string actNombre, int actedad, double actPuntos) {
    setNombreCliente(actNombre);
    setEdad(actedad);
    setPuntos(actPuntos);
    cout << "Proceso realizado con exito" << endl;
    cout << endl;
}

//CRUD
void ClienteRegular::Create(){
    ofstream escribirArchivo;
    escribirArchivo.open("C_Regular.txt", ios::app);

    escribirArchivo << getId()<< " " << getNombreCliente() << " " << getEdad() << " "
                   << getPuntos() <<"\n";

    escribirArchivo.close();
}

void ClienteRegular::Read(){
    ifstream leerArchivo;
    leerArchivo.open("C_Regular.txt", ios::in);

    int idLeer;
    string nombreLeer;
    int edadLeer;
    double puntosLeer;

    while (leerArchivo >> idLeer >> nombreLeer >> edadLeer >> puntosLeer) {
        cout << "ID: " << idLeer << "\n"
             << "Nombre: " << nombreLeer << "\n"
             << "Edad: " << edadLeer << "\n"
             << "Puntos Disponible: " << puntosLeer << "\n"
             << "-----------------------------" << endl;
    }

    leerArchivo.close();
}

void ClienteRegular::Update(int idUpdate) {
    ifstream leerArchivo("C_Regular.txt");
    ofstream tempArchivo("temp.txt");

    if (!leerArchivo || !tempArchivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    int idModificar;
    string nombreModificar;
    int edadModificar;
    string empresaModificar;
    double creditoModificar;

    bool found = false;

    while (leerArchivo >> idModificar >> nombreModificar >> edadModificar >> creditoModificar) {
        if (idModificar == idUpdate) {
            // Modificar los datos del cliente
            cout << "Ingrese el nueva Id: ";
            cin >> idModificar;
            cout << "Ingrese el nuevo nombre: ";
            cin >> nombreModificar;
            cout << "Ingrese la nueva edad: ";
            cin >> edadModificar;
            cout << "Ingrese los nuevos puntos disponible: ";
            cin >> creditoModificar;
            found = true;
        }
        // Guardar los datos en el archivo temporal, ya sea modificados o no
        tempArchivo << idModificar << " " << nombreModificar << " " << edadModificar << " " << creditoModificar << "\n";
    }

    leerArchivo.close();
    tempArchivo.close();


    remove("C_Regular.txt");
    rename("temp.txt", "C_Regular.txt");

    if (found) {
        cout << "Cliente modificado exitosamente." << endl;
    } else {
        cout << "Cliente con ID  no encontrado." << endl;
    }
}

void ClienteRegular::Delete(int idDelete) {
    ifstream leerArchivo("C_Regular.txt");
    ofstream tempArchivo("temp.txt");

    if (!leerArchivo || !tempArchivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    int idBorrar;
    string nombreBorrar;
    int edadBorrar;
    string empresaBorrar;
    double creditoBorrar;

    bool found = false;

    while (leerArchivo >> idBorrar >> nombreBorrar >> edadBorrar >> creditoBorrar) {
        if (idBorrar != idDelete) {
            // Si el ID no coincide, copiar los datos al archivo temporal
            tempArchivo << idBorrar << " " << nombreBorrar << " " << edadBorrar << " " << creditoBorrar << "\n";
        } else {
            found = true;
        }
    }

    leerArchivo.close();
    tempArchivo.close();

    // Eliminar el archivo original y renombrar el temporal
    remove("C_Regular.txt");
    rename("temp.txt", "C_Regular.txt");

    if (found) {
        cout << "Cliente eliminado exitosamente." << endl;
    } else {
        cout << "Cliente con ID  no encontrado." << endl;
    }
}
