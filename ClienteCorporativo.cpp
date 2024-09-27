#include "../TercerAvanceProyecto/include/ClienteCorporativo.h"

// Inicialización de miembro estático
int ClienteCorporativo::contadorClinteCorp = 0;

// Constructor
ClienteCorporativo::ClienteCorporativo(string contsNombreEmpresa, double cosntCreditoDisponible) {
    nombreEmpresa = contsNombreEmpresa;
    creditoDisponible = cosntCreditoDisponible;
    contadorClinteCorp = contadorClinteCorp + 1;
}

// Getters
string ClienteCorporativo::getNombreEmpresa() {
    return nombreEmpresa;
}

double ClienteCorporativo::getCreditoDisponible() {
    return creditoDisponible;
}

int ClienteCorporativo::getContadorClinteCorp() {
    return contadorClinteCorp;
}

// Setters
void ClienteCorporativo::setNombreEmpresa(string nuevoNombreEmpresa) {
    nombreEmpresa = nuevoNombreEmpresa;
}

void ClienteCorporativo::setCreditoDisponible(double nuevoCreditoDisponible) {
    creditoDisponible = nuevoCreditoDisponible;
}

// Métodos personalizados
void ClienteCorporativo::aplicarCredito(double montoAplicar) {
    creditoDisponible = creditoDisponible - montoAplicar;
    cout << "Se aplico un credito de : " << montoAplicar;
    cout << " Crédito disponible después de credito: " << creditoDisponible << endl;
}

double ClienteCorporativo::RecargarCredito(double montoComprar) {
    double totalRecarga;

    if (montoComprar < 1000) {
        totalRecarga = montoComprar * 1.10; // 10% adicional
        cout << "Recarga realizada: " << montoComprar << " Lps. Se ha agregado un 10% adicional al credito." << endl;
    } else {
        totalRecarga = montoComprar * 1.25; // 25% adicional
        cout << "Recarga realizada: " << montoComprar << " Lps. Se ha agregado un 25% adicional al credito." << endl;
    }

    creditoDisponible += totalRecarga; // Actualiza el crédito disponible
    cout << "Crédito disponible después de la recarga: " << creditoDisponible << " Lps." << endl;
    
    return totalRecarga; // Retorna el total de la recarga
}

void ClienteCorporativo::ActualizarinstanciaEnArchivo(int idUpdate) {
    ifstream leerArchivo("C_Coorporativos.txt");
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

    while (leerArchivo >> idModificar >> nombreModificar >> edadModificar >> empresaModificar >> creditoModificar) {
        if (idModificar == idUpdate) {
            // Modificar los datos del cliente con la información actual
            idModificar = getId();
            nombreModificar = getNombreCliente();
            edadModificar = getEdad();
            empresaModificar = getNombreEmpresa();
            creditoModificar = getCreditoDisponible();
            found = true;
        }
        // Guardar los datos en el archivo temporal, ya sea modificados o no
        tempArchivo << idModificar << " " << nombreModificar << " " << edadModificar << " " << empresaModificar << " " << creditoModificar << "\n";
    }

    leerArchivo.close();
    tempArchivo.close();

    // Reemplazar el archivo original con el archivo temporal
    remove("C_Coorporativos.txt");
    rename("temp.txt", "C_Coorporativos.txt");

    if (found) {
        cout << "Cliente modificado exitosamente." << endl;
    } else {
        cout << "Cliente con ID " << idUpdate << " no encontrado." << endl;
    }
}



//polimofismo
void ClienteCorporativo::actualizarCliente(string actNombre, int actedad, string actNombreEmpresa, double actCreditoDisponible) {
    setNombreCliente(actNombre);
    setEdad(actedad);
    setNombreEmpresa(actNombreEmpresa);
    setCreditoDisponible(actCreditoDisponible);
    cout << "Proceso realizado con exito" << endl;
}

//CRUD
void ClienteCorporativo::Create(){
    ofstream escribirArchivo;
    escribirArchivo.open("C_Coorporativos.txt", ios::app);

    escribirArchivo << getId()<< " " << getNombreCliente() << " " << getEdad() << " "
                   << getNombreEmpresa() << " " << getCreditoDisponible() << "\n";

    escribirArchivo.close();
}

void ClienteCorporativo::Read(){
    ifstream leerArchivo;
    leerArchivo.open("C_Coorporativos.txt", ios::in);

    int idLeer;
    string nombreLeer;
    int edadLeer;
    string empresaLeer;
    double creditoLeer;

    while (leerArchivo >> idLeer >> nombreLeer >> edadLeer >> empresaLeer >> creditoLeer) {
        cout << "ID: " << idLeer << "\n"
             << "Nombre: " << nombreLeer << "\n"
             << "Edad: " << edadLeer << "\n"
             << "Empresa: " << empresaLeer << "\n"
             << "Credito Disponible: " << creditoLeer << "\n"
             << "-----------------------------" << endl;
    }

    leerArchivo.close();
}

void ClienteCorporativo::Delete(int idDelete) {
    ifstream leerArchivo("C_Coorporativos.txt");
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

    while (leerArchivo >> idBorrar >> nombreBorrar >> edadBorrar >> empresaBorrar >> creditoBorrar) {
        if (idBorrar != idDelete) {
            // Si el ID no coincide, copiar los datos al archivo temporal
            tempArchivo << idBorrar << " " << nombreBorrar << " " << edadBorrar << " " << empresaBorrar << " " << creditoBorrar << "\n";
        } else {
            found = true;
        }
    }

    leerArchivo.close();
    tempArchivo.close();

    // Eliminar el archivo original y renombrar el temporal
    remove("C_Coorporativos.txt");
    rename("temp.txt", "C_Coorporativos.txt");

    if (found) {
        cout << "Cliente eliminado exitosamente." << endl;
    } else {
        cout << "Cliente con ID  no encontrado." << endl;
    }
}

void ClienteCorporativo::Update(int idUpdate) {
    ifstream leerArchivo("C_Coorporativos.txt");
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

    while (leerArchivo >> idModificar >> nombreModificar >> edadModificar >> empresaModificar >> creditoModificar) {
        if (idModificar == idUpdate) {
            // Modificar los datos del cliente
            cout << "Ingrese el nueva Id: ";
            cin >> idModificar;
            cout << "Ingrese el nuevo nombre: ";
            cin >> nombreModificar;
            cout << "Ingrese la nueva edad: ";
            cin >> edadModificar;
            cout << "Ingrese la nueva empresa: ";
            cin >> empresaModificar;
            cout << "Ingrese el nuevo crédito disponible: ";
            cin >> creditoModificar;
            found = true;
        }
        // Guardar los datos en el archivo temporal, ya sea modificados o no
        tempArchivo << idModificar << " " << nombreModificar << " " << edadModificar << " " << empresaModificar << " " << creditoModificar << "\n";
    }

    leerArchivo.close();
    tempArchivo.close();


    remove("C_Coorporativos.txt");
    rename("temp.txt", "C_Coorporativos.txt");

    if (found) {
        cout << "Cliente modificado exitosamente." << endl;
    } else {
        cout << "Cliente con ID  no encontrado." << endl;
    }
}

//Podria actualizar cada uno tambien. 