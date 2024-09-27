//Alumno
//Edwin Noe Argueta Flores 
// 32111584

//Clases
#include "../TercerAvanceProyecto/include/ClienteCorporativo.h"
#include "../TercerAvanceProyecto/include/ClienteRegular.h"
#include "../TercerAvanceProyecto/include/Combustible.h"
#include "../TercerAvanceProyecto/include/Facturacion.h"

// instancias Clientes
ClienteCorporativo clienteCorp;
ClienteRegular clienteReg;

//instancias Combustible (iniciaizadas por defecto)
Combustible super("Super", 1000.00, 100); //<-- Nombre , Cantidad , Precio 
Combustible regular("Regular", 1000.00, 90);//<-- Nombre , Cantidad , Precio 
Combustible diesel("Diesel", 1000.00, 80);//<-- Nombre , Cantidad , Precio 

// instancia Facturacion 
Facturacion factura;

//Funciones 
// Gestiona cliente Coorporativo y regular .
void GestionarCliente (int tipoCliente){
    //identificador de tipo Cliente 
    string stringTipoCliente;
    tipoCliente==1?stringTipoCliente="COORPORATIVO":stringTipoCliente="REGULAR";
    
    //Variables Generales 
    int idClienteModificar;
    int idClienteEliminar;
    int opcion;
    bool continuar = true;

    //Varables para instancia
    //cliente
    int id;
    string nombre;
    int edad=0;
    //corporativo
    string nombreEmpresa;
    double creditoDisponible;
    //Regular
    double puntosDisponible;

    while (continuar) {
        cout << endl;
        cout << "=============================================" << endl;
        cout << " MENU CLIENTE " << stringTipoCliente << endl;
        cout << "=============================================" << endl;
        cout << "1) Agregar Cliente" << endl;            //C
        cout << "2) Mostrar Todos los Clientes" << endl; //R
        cout << "3) Actualizar Cliente" << endl;         //U
        cout << "4) Eliminar Cliente" << endl;           //D
        cout << "5) Volver al Menu Principal" << endl;
        cout << "===============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: //C
             cout << endl;
                cout << "=============================================" << endl;
                cout << " Ingreso de CLiente " << stringTipoCliente << endl;
                cout << "=============================================" << endl;
                cout << "ingrese Id: ";           
                cin >> id;
                cout << "Ingrese Nombre: ";           
                cin >> nombre;
                cout << "Ingrese Edad: " ;           
                cin >> edad;
                if (tipoCliente==1){
                    cout << "Ingrese Nombre De Empresa: " ;           
                    cin >> nombreEmpresa;
                    cout << "Ingrese Credito Disponible: ";           
                    cin >> creditoDisponible;
                    //ingresar Datos A instancia Corporativa
                    clienteCorp.setId(id);
                    clienteCorp.actualizarCliente(nombre, edad, nombreEmpresa,creditoDisponible);
                    clienteCorp.Create();
                }else{
                    cout << "Ingrese Puntos Disponiibles: " ;           
                    cin >> puntosDisponible;
                    //ingresar Datos A instancia Cliente Regular
                    clienteReg.setId(id);
                    clienteReg.actualizarCliente(nombre, edad, puntosDisponible);
                    clienteReg.Create();
                }
            break;
            case 2://R
                cout << endl;
                cout << "=============================================" << endl;
                cout << " Lectura de Todos los Registro de CLiente " << stringTipoCliente << endl;
                cout << "=============================================" << endl;
                if(tipoCliente==1){
                    clienteCorp.Read();
                }else {
                     clienteReg.Read();
                }
            break;
            case 3: //U
                cout << endl;
                cout << "=============================================" << endl;
                cout << " Actualizar Registro de CLiente " << stringTipoCliente << endl;
                cout << "=============================================" << endl;
                if(tipoCliente==1){
                    clienteCorp.Read();
                    cout <<endl;
                    cout<< "ingrese ID del cliente que le gustaria modificar: " ;
                    cin >> idClienteModificar; 
                    clienteCorp.Update(idClienteModificar);
                }else {
                    clienteReg.Read();
                    cout <<endl;
                    cout<< "ingrese ID del cliente que le gustaria modificar: " ;
                    cin >> idClienteModificar; 
                    clienteReg.Update(idClienteModificar);
                }
            break;
            case 4://D
                cout << endl;
                cout << "=============================================" << endl;
                cout << " Eliminar Registro de CLiente " << stringTipoCliente << endl;
                cout << "=============================================" << endl;
                if(tipoCliente==1){
                    clienteCorp.Read();
                    cout <<endl;
                    cout<< "ingrese ID del cliente que le gustaria Eliminar: " ;
                    cin >> idClienteEliminar; 
                    clienteCorp.Delete(idClienteEliminar);
                }else {
                    clienteReg.Read();
                    cout <<endl;
                    cout<< "ingrese ID del cliente que le gustaria Eliminar: " ;
                    cin >> idClienteEliminar; 
                    clienteReg.Delete(idClienteEliminar);
                }
            break;
            case 5:
                // Volver al menú principal
                continuar=false;
            break;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
            break;
        }
    }
}
// Gestiona gasolina.
void EscribirArchiivoGasolina(){
    ofstream EscribirArchivo;
    EscribirArchivo.open("Combustible.txt", ios::out);
    EscribirArchivo<<super.getNombreCombustible() << " " << super.getCantidadDisponible()<<  " " << super.getPrecio() << endl;
    EscribirArchivo<<regular.getNombreCombustible() << " " << regular.getCantidadDisponible()<<  " " << regular.getPrecio() << endl;
    EscribirArchivo<<diesel.getNombreCombustible() << " " << diesel.getCantidadDisponible()<<  " " << diesel.getPrecio() << endl;
    EscribirArchivo.close();
}

void GestionarGasolina(){
    //Variables generales
    int opcion;
    bool continuar = true;
    int opcionAgregarGasolina;
    double agregarGasolina ,  eliminarGasolina;

    //variables Crud
    string nombre;
    double cantidad;
    double precio;

    while (continuar) {
        cout << endl;
        cout << "=============================================" << endl;
        cout << " MENU COMBUSTIBLE " << endl;
        cout << "=============================================" << endl;
        cout << "1) Agregar Combustible" << endl;            //C <- Agregar Combustible
        cout << "2) Mostrar Combustible en inventario" << endl; //R <--toda la informacion 
        cout << "3) Actualizar Combustible en inventario" << endl; //U <--toda la informacion 
        cout << "4) Eliminar Combustible" << endl; //U <- Eliminar Combustible
        cout << "5) Volver al Menu Principal" << endl;
        cout << "===============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1 : 
                cout << endl;
                cout << "=============================================" << endl;
                cout << "Agregar Combustible " << endl;
                cout << "=============================================" << endl;
                cout << "1) " << super.getNombreCombustible() << endl;
                cout << "2) " << regular.getNombreCombustible() << endl;
                cout << "3) " << diesel.getNombreCombustible() << endl;
                cout << "ingrese la opcion para agregar mas gasolina: ";
                cin >> opcionAgregarGasolina;

                switch (opcionAgregarGasolina){
                    case 1:
                        cout << "Ingrese la Cantidad a Agregar :";
                        cin >> agregarGasolina;
                        super.setCantidadDisponible(super.getCantidadDisponible()+agregarGasolina);
                        EscribirArchiivoGasolina();
                        cout << "Cantidad Agregada , nueva cantidad de " << super.getNombreCombustible()<< " es " << super.getCantidadDisponible();
                    break;
                    case 2:
                        cout << "Ingrese la Cantidad a Agregar :";
                        cin >> agregarGasolina;
                        regular.setCantidadDisponible(regular.getCantidadDisponible()+agregarGasolina);
                        EscribirArchiivoGasolina();
                        cout << "Cantidad Agregada , nueva cantidad de " << regular.getNombreCombustible()<< " es " << regular.getCantidadDisponible();
                    break;     
                    case 3:
                        cout << "Ingrese la Cantidad a Agregar :";
                        cin >> agregarGasolina;
                        diesel.setCantidadDisponible(diesel.getCantidadDisponible()+agregarGasolina);
                        EscribirArchiivoGasolina();
                        cout << "Cantidad Agregada , nueva cantidad de " << diesel.getNombreCombustible()<< " es " << diesel.getCantidadDisponible();
                    break;                     

                    default:
                        cout << " Opcion invalida " << endl;
                    break;
                }

            break;

            case 4 : 
                cout << endl;
                cout << "=============================================" << endl;
                cout << "Eliminar Combustible " << endl;
                cout << "=============================================" << endl;
                cout << "1) " << super.getNombreCombustible() << endl;
                cout << "2) " << regular.getNombreCombustible() << endl;
                cout << "3) " << diesel.getNombreCombustible() << endl;
                cout << "ingrese la opcion para disminuir gasolina: ";
                cin >> opcionAgregarGasolina;

                switch (opcionAgregarGasolina){
                    case 1:
                        cout << "Ingrese la Cantidad a Eliminar :";
                        cin >> eliminarGasolina;
                        super.setCantidadDisponible(super.getCantidadDisponible()-eliminarGasolina);
                        EscribirArchiivoGasolina();
                        cout << "Cantidad Eliminar , nueva cantidad de " << super.getNombreCombustible()<< " es " << super.getCantidadDisponible();
                    break;
                    case 2:
                        cout << "Ingrese la Cantidad a Eliminar :";
                        cin >> eliminarGasolina;
                        regular.setCantidadDisponible(regular.getCantidadDisponible()-eliminarGasolina);
                        EscribirArchiivoGasolina();
                        cout << "Cantidad Eliminar , nueva cantidad de " << regular.getNombreCombustible()<< " es " << regular.getCantidadDisponible();
                    break;     
                    case 3:
                        cout << "Ingrese la Cantidad a Eliminar :";
                        cin >> eliminarGasolina;
                        diesel.setCantidadDisponible(diesel.getCantidadDisponible()-eliminarGasolina);
                        EscribirArchiivoGasolina();
                        cout << "Cantidad Eliminar , nueva cantidad de " << diesel.getNombreCombustible()<< " es " << diesel.getCantidadDisponible();
                    break;                     

                    default:
                        cout << " Opcion invalida " << endl;
                    break;
                }

            break;

            case 5: 
                continuar=false;
            break;

            case 3: 
                cout << endl;
                cout << "=============================================" << endl;
                cout << "Actualizar Combustible en inventario" << endl;
                cout << "=============================================" << endl;
                cout << "1) " << super.getNombreCombustible() << endl;
                cout << "2) " << regular.getNombreCombustible() << endl;
                cout << "3) " << diesel.getNombreCombustible() << endl;
                cout << "ingrese la opcion a actualizar: ";
                cin >> opcionAgregarGasolina;

                if (opcionAgregarGasolina >= 1 && opcionAgregarGasolina <= 3){
                    cout << "Ingrese el nuevo nombre de la gasolina : ";
                    cin >> nombre;
                    cout << "Ingrese el nueva cantidad de la gasolina : ";
                    cin >> cantidad;
                    cout << "Ingrese el nuevo precio de la gasolina : ";
                    cin >> precio;

                    switch (opcionAgregarGasolina){
                        case 1:
                            super.setNombreCombustible(nombre);
                            super.setCantidadDisponible(cantidad);
                            super.setPrecio(precio);
                            EscribirArchiivoGasolina();
                            cout << "Gasolina Actualizada " << endl;
                        break;
                        case 2:
                            regular.setNombreCombustible(nombre);
                            regular.setCantidadDisponible(cantidad);
                            regular.setPrecio(precio);
                            EscribirArchiivoGasolina();
                            cout << "Gasolina Actualizada " << endl;
                        break;
                        case 3:
                            regular.setNombreCombustible(nombre);
                            regular.setCantidadDisponible(cantidad);
                            regular.setPrecio(precio);
                            EscribirArchiivoGasolina();
                            cout << "Gasolina Actualizada " << endl;
                        break;
                    }
                }else{
                    cout << "Opción inválida" << endl;
                }
            break;


            case 2:
                cout << endl;
                cout << "=============================================" << endl;
                cout << "Mostrar Combustible en inventario " << endl;
                cout << "=============================================" << endl;
                cout << "Nombre - Cantidad -Precio " << endl;
                ifstream leerArchivoCombustible;
                leerArchivoCombustible.open("Combustible.txt" , ios::in);
                if (leerArchivoCombustible.is_open()) {
                    string linea;
                    while (getline(leerArchivoCombustible, linea)) {
                        cout << linea << endl;  
                    }
                    leerArchivoCombustible.close(); 
                } else {
                   cout << "No se pudo abrir el archivo" << endl;
                }
                leerArchivoCombustible.close();
            break;

        }
    }
}

// Gestonar Ventas 
void GestionVentas(int tipoCliente){
    // Variables generales
    string stringTipoCliente;
    tipoCliente == 1 ? stringTipoCliente = "COORPORATIVO" : stringTipoCliente = "REGULAR";
    
    //varianles buscar 
    bool continuar = true;
    int idBuscar;
    bool found = false;
    int opcion;

    // Variables para clientes
    int idLeer;
    string nombreLeer;
    int edadLeer;
    string empresaLeer;
    double creditoLeer;
    double puntosLeer;

    //variables Cliente Encontrado case 2

    double CompraCantidad;
    int comprarPuntos;
    double canjearPuntos=0;
    int ComprarNombre;

    double cantARecargarCor;
    // double creditoTotal;

    //variiables de corp 
    // int pagarCredito;



    cout << endl;
    cout << "=============================================" << endl;
    cout << " Login " << stringTipoCliente << endl;
    cout << "=============================================" << endl;
    cout << "Por favor ingrese su ID (Ingrese -1 para volver al menu anterior): ";
    cin >> idBuscar;
    cout << endl;

    if (idBuscar == -1) {
        cout << "Volviendo al menu anterior..." << endl;
        return; // Vuelve al menu principal o anterior
    }

    // Funcion para buscar el cliente en los archivos correspondientes y asignar a instancias 
    if (stringTipoCliente == "COORPORATIVO") {
        ifstream leerAchivocorp("C_Coorporativos.txt");

        while (leerAchivocorp >> idLeer >> nombreLeer >> edadLeer >> empresaLeer >> creditoLeer) {
            if (idLeer == idBuscar) {
                found = true;
                cout << "Bienvenido " << nombreLeer << endl;
                // Actualizar instancia para trabajar con ella 
                clienteCorp.setId(idLeer);
                clienteCorp.setNombreCliente(nombreLeer);
                clienteCorp.setEdad(edadLeer);
                clienteCorp.setNombreEmpresa(empresaLeer);
                clienteCorp.setCreditoDisponible(creditoLeer);
                break;
            }
        }
        leerAchivocorp.close();

        if (!found) {
            cout << "Cliente no encontrado." << endl;
        }

    } else if (stringTipoCliente == "REGULAR") {
        ifstream leerAchivoreg("C_Regular.txt");

        while (leerAchivoreg >> idLeer >> nombreLeer >> edadLeer >> puntosLeer) {
            if (idLeer == idBuscar) {
                found = true;
                cout << "Bienvenido " << nombreLeer << endl;
                // Actualizar instancia para trabajar con ella 
                clienteReg.setId(idLeer);
                clienteReg.setNombreCliente(nombreLeer);
                clienteReg.setEdad(edadLeer);
                clienteReg.setPuntos(puntosLeer);
                break;
            }
        }
        leerAchivoreg.close();

        if (!found) {
            cout << "Cliente no encontrado." << endl;
        }

    } else {
        cout << "Opcion invalida." << endl;
        return;
    }
//------------------------------------------------------------------------------------------------------------------------------------------------------>
    // Cliente Encontrado
    if (found) {
        while (continuar) {
            cout << "=============================================" << endl;
            cout << " MENU VENTA CLIENTE " << stringTipoCliente << endl;
            cout << "=============================================" << endl;
            cout << "1) Ver informacion personal" << endl;
            cout << "2) Realizar compra" << endl;
            cout << "3) Salir" << endl;

            cout << "Ingrese la opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 1:
                    if (stringTipoCliente == "COORPORATIVO") {
                        cout<< endl;
                        cout << "=============================================" << endl;
                        cout << " Informacion Personal  " << endl;
                        cout << "=============================================" << endl;

                        cout << "Numero de ID: " << clienteCorp.getId() << endl;
                        cout << "Nombre: " << clienteCorp.getNombreCliente() << endl;
                        cout << "Edad: " << clienteCorp.getEdad() << endl;
                        cout << "Empresa: " << clienteCorp.getNombreEmpresa() << endl;
                        cout << "Credito Disponible: " << clienteCorp.getCreditoDisponible() << endl;

                    } else if (stringTipoCliente == "REGULAR") {
                        cout << "=============================================" << endl;
                        cout << " Informacion Personal  " << endl;
                        cout << "=============================================" << endl;
                        cout << "Numero de ID: " << clienteReg.getId() << endl;
                        cout << "Nombre: " << clienteReg.getNombreCliente() << endl;
                        cout << "Edad: " << clienteReg.getEdad() << endl;
                        cout << "Puntos: " << clienteReg.getPuntos() << endl;
                    }
                    cout << "Presione cualquier tecla para continuar... ";
                    system("pause");  // Esperar hasta que el usuario presione cualquier tecla
                    cout << endl;
                    break;
                case 2:    
                    if(stringTipoCliente == "COORPORATIVO"){
                        cout << "=============================================" << endl;
                        cout << " Menu Compra  " << endl;
                        cout << "=============================================" << endl;
                        cout << "1) Comprar Gasolina" << endl;
                        cout << "2) Comprar Credito" << endl;
                        cout << "ingrese la opcion de gasolina a comprar : ";
                        cin >> ComprarNombre ;
                        switch (ComprarNombre)
                        {
                            case 1:
                                cout << "=============================================" << endl;
                                cout << " MENU DE COMBUSTIBLE " << endl;
                                cout << "=============================================" << endl;
                                cout << "1) ";
                                cout << "   Nombre: " << super.getNombreCombustible() << endl;
                                cout << "   Cantidad disponible: " << super.getCantidadDisponible() << endl;
                                cout << "   Precio: " << super.getPrecio() << endl;
                                cout << endl;

                                cout << "2) "; 
                                cout << "   Nombre: " << regular.getNombreCombustible() << endl;
                                cout << "   Cantidad disponible: " << regular.getCantidadDisponible() << endl;
                                cout << "   Precio: " << regular.getPrecio() << endl;
                                cout << endl;

                                cout << "3) ";
                                cout << "   Nombre: " << diesel.getNombreCombustible() << endl;
                                cout << "   Cantidad disponible: " << diesel.getCantidadDisponible() << endl;
                                cout << "   Precio: " << diesel.getPrecio() << endl;
                                cout << "=============================================" << endl;
                                
                                cout << "ingrese la opcion de gasolina a comprar : ";
                                cin >> ComprarNombre;

                                switch (ComprarNombre)
                                {
                                case 1:
                                    cout << "Ingrese la cantidad de gasolina a comprar (litros): ";
                                    cin >> CompraCantidad;
                                     if (CompraCantidad > super.getCantidadDisponible()) {
                                        cout << "No contamos con la cantidad de combustible disponible actualmente." << endl;
                                    }else  {
                                         cout <<"---------------------------------------------------------------------" <<  endl;
                                        cout << endl;
                                        if(clienteCorp.getCreditoDisponible() > 0){
                                            cout << "Desea pagar con Credito? 1: si, 2: no : " ;
                                            cin >> comprarPuntos;
                                             if (comprarPuntos == 1) {
                                                cout << "¿Cuanto Credito desea canjear? (usted posee " << clienteCorp.getCreditoDisponible() << " Crediito) : ";
                                                cin >> canjearPuntos;
                                                clienteCorp.aplicarCredito(canjearPuntos);
                                            }
                                        }
                                        // Verificar si tiene descuento por tercera edad
                                        double descuentoTerceraEdad = clienteCorp.calcularDescuentoTerceraEdad(CompraCantidad);
                                        if (clienteCorp.getEdad() >= 65) {
                                            cout << "Descuento aplicado por tercera edad de un total de : " << descuentoTerceraEdad*100<< endl;
                                        }

                                        double descuentoPuntos = canjearPuntos;  // Aquí los crediitos se convierten en descuento en dinero
                                        if (comprarPuntos == 1) {
                                            cout << "Credito aplicados: " << descuentoPuntos << " LPS" << endl;
                                        }
                                        
                                        // Calcular el total del descuento en dinero
                                        double totalDescuento = descuentoTerceraEdad * super.getPrecio() + descuentoPuntos;
                                        
                                        // Actualizar la cantidad disponible de combustible
                                        super.setCantidadDisponible(super.getCantidadDisponible() - CompraCantidad);
                                         // Imprimir factura
                                        cout <<endl;
                                        factura.imprimirFactura(clienteCorp.getNombreCliente(), stringTipoCliente, super.getNombreCombustible(), CompraCantidad, totalDescuento, super.getPrecio());

                                        canjearPuntos = 0;  // Restablecer los puntos canjeados
                                    }
                                    clienteCorp.ActualizarinstanciaEnArchivo(clienteCorp.getId());
                                    super.ActualizarinstanciaEnArchivo(super.getNombreCombustible());
                                break;
                                case 2:
                                    cout << "Ingrese la cantidad de gasolina a comprar (litros): ";
                                    cin >> CompraCantidad;
                                     if (CompraCantidad > regular.getCantidadDisponible()) {
                                        cout << "No contamos con la cantidad de combustible disponible actualmente." << endl;
                                    }else  {
                                         cout <<"---------------------------------------------------------------------" <<  endl;
                                        cout << endl;
                                        if(clienteCorp.getCreditoDisponible() > 0){
                                            cout << "Desea pagar con Credito? 1: si, 2: no : " ;
                                            cin >> comprarPuntos;
                                             if (comprarPuntos == 1) {
                                                cout << "¿Cuanto Credito desea canjear? (usted posee " << clienteCorp.getCreditoDisponible() << " Crediito) : ";
                                                cin >> canjearPuntos;
                                                clienteCorp.aplicarCredito(canjearPuntos);
                                            }
                                        }
                                        // Verificar si tiene descuento por tercera edad
                                        double descuentoTerceraEdad = clienteCorp.calcularDescuentoTerceraEdad(CompraCantidad);
                                        if (clienteCorp.getEdad() >= 65) {
                                            cout << "Descuento aplicado por tercera edad de un total de : " << descuentoTerceraEdad*100<< endl;
                                        }

                                        double descuentoPuntos = canjearPuntos;  // Aquí los crediitos se convierten en descuento en dinero
                                        if (comprarPuntos == 1) {
                                            cout << "Credito aplicados: " << descuentoPuntos << " LPS" << endl;
                                        }
                                        
                                        // Calcular el total del descuento en dinero
                                        double totalDescuento = descuentoTerceraEdad * regular.getPrecio() + descuentoPuntos;
                                        
                                        // Actualizar la cantidad disponible de combustible
                                        regular.setCantidadDisponible(regular.getCantidadDisponible() - CompraCantidad);
                                         // Imprimir factura
                                        cout <<endl;
                                        factura.imprimirFactura(clienteCorp.getNombreCliente(), stringTipoCliente, regular.getNombreCombustible(), CompraCantidad, totalDescuento, regular.getPrecio());

                                        canjearPuntos = 0;  // Restablecer los puntos canjeados
                                    }
                                    clienteCorp.ActualizarinstanciaEnArchivo(clienteCorp.getId());
                                    regular.ActualizarinstanciaEnArchivo(regular.getNombreCombustible());
                                break;
                                case 3:
                                    cout << "Ingrese la cantidad de gasolina a comprar (litros): ";
                                    cin >> CompraCantidad;
                                     if (CompraCantidad > diesel.getCantidadDisponible()) {
                                        cout << "No contamos con la cantidad de combustible disponible actualmente." << endl;
                                    }else  {
                                         cout <<"---------------------------------------------------------------------" <<  endl;
                                        cout << endl;
                                        if(clienteCorp.getCreditoDisponible() > 0){
                                            cout << "Desea pagar con Credito? 1: si, 2: no : " ;
                                            cin >> comprarPuntos;
                                             if (comprarPuntos == 1) {
                                                cout << "¿Cuanto Credito desea canjear? (usted posee " << clienteCorp.getCreditoDisponible() << " Crediito) : ";
                                                cin >> canjearPuntos;
                                                clienteCorp.aplicarCredito(canjearPuntos);
                                            }
                                        }
                                        // Verificar si tiene descuento por tercera edad
                                        double descuentoTerceraEdad = clienteCorp.calcularDescuentoTerceraEdad(CompraCantidad);
                                        if (clienteCorp.getEdad() >= 65) {
                                            cout << "Descuento aplicado por tercera edad de un total de : " << descuentoTerceraEdad*100<< endl;
                                        }

                                        double descuentoPuntos = canjearPuntos;  // Aquí los crediitos se convierten en descuento en dinero
                                        if (comprarPuntos == 1) {
                                            cout << "Credito aplicados: " << descuentoPuntos << " LPS" << endl;
                                        }
                                        
                                        // Calcular el total del descuento en dinero
                                        double totalDescuento = descuentoTerceraEdad * diesel.getPrecio() + descuentoPuntos;
                                        
                                        // Actualizar la cantidad disponible de combustible
                                        diesel.setCantidadDisponible(diesel.getCantidadDisponible() - CompraCantidad);
                                         // Imprimir factura
                                        cout <<endl;
                                        factura.imprimirFactura(clienteCorp.getNombreCliente(), stringTipoCliente, diesel.getNombreCombustible(), CompraCantidad, totalDescuento, regular.getPrecio());

                                        canjearPuntos = 0;  // Restablecer los puntos canjeados
                                    }
                                    clienteCorp.ActualizarinstanciaEnArchivo(clienteCorp.getId());
                                    diesel.ActualizarinstanciaEnArchivo(diesel.getNombreCombustible());
                                break;

                                default:
                                break;
                                }

                            break;

                            case 2:
                                cout << "ingrese la cantidad a recargar ";
                                cin >> cantARecargarCor ;

                                clienteCorp.RecargarCredito(cantARecargarCor);
                                cout << clienteCorp.getCreditoDisponible() << endl;
                                cout  << clienteCorp.getId();

                                clienteCorp.ActualizarinstanciaEnArchivo(clienteCorp.getId());
                            break;
                            
                            default:
                            break;
                        }


                    }  else if (stringTipoCliente == "REGULAR") {
                        cout << "=============================================" << endl;
                        cout << " MENU DE COMBUSTIBLE " << endl;
                        cout << "=============================================" << endl;
                        cout << "1) ";
                        cout << "   Nombre: " << super.getNombreCombustible() << endl;
                        cout << "   Cantidad disponible: " << super.getCantidadDisponible() << endl;
                        cout << "   Precio: " << super.getPrecio() << endl;
                        cout << endl;

                        cout << "2) ";
                        cout << "   Nombre: " << regular.getNombreCombustible() << endl;
                        cout << "   Cantidad disponible: " << regular.getCantidadDisponible() << endl;
                        cout << "   Precio: " << regular.getPrecio() << endl;
                        cout << endl;

                        cout << "3) ";
                        cout << "   Nombre: " << diesel.getNombreCombustible() << endl;
                        cout << "   Cantidad disponible: " << diesel.getCantidadDisponible() << endl;
                        cout << "   Precio: " << diesel.getPrecio() << endl;
                        cout << "=============================================" << endl;
                        
                        cout << "ingrese la opcion de gasolina a comprar : ";
                        cin >> ComprarNombre;
                        
                        switch (ComprarNombre)
                        {
                            case 1:
                                    cout << "Ingrese la cantidad de gasolina a comprar (litros): ";
                                    cin >> CompraCantidad;

                                    if (CompraCantidad > super.getCantidadDisponible()) {
                                        cout << "No contamos con la cantidad de combustible disponible actualmente." << endl;
                                    } else {
                                        cout <<"---------------------------------------------------------------------" <<  endl;
                                        cout << endl;
                                        if (clienteReg.getPuntos() >= 100) {
                                            cout << "Desea canjear puntos? 1: si, 2: no : " ;
                                            cin >> comprarPuntos;
                                            if (comprarPuntos == 1) {
                                                cout << "¿Cuantos puntos desea canjear? (usted posee " << clienteReg.getPuntos() << " puntos) : ";
                                                cin >> canjearPuntos;
                                                clienteReg.canjearPuntos(canjearPuntos);
                                            }
                                        }

                                        // Verificar si tiene descuento por tercera edad
                                        double descuentoTerceraEdad = clienteReg.calcularDescuentoTerceraEdad(CompraCantidad);
                                        if (clienteReg.getEdad() >= 65) {
                                            cout << "Descuento aplicado por tercera edad de un total de : " << descuentoTerceraEdad*100<< endl;
                                        }

                                        double descuentoPuntos = canjearPuntos;  // Aquí los puntos se convierten en descuento en dinero
                                        if (comprarPuntos == 1) {
                                            cout << "Puntos aplicados: " << descuentoPuntos << " LPS" << endl;
                                        }

                                        // Calcular el total del descuento en dinero
                                        double totalDescuento = descuentoTerceraEdad * super.getPrecio() + descuentoPuntos;

                                        // Actualizar la cantidad disponible de combustible
                                        super.setCantidadDisponible(super.getCantidadDisponible() - CompraCantidad);

                                        // Imprimir factura
                                        cout <<endl;
                                        clienteReg.acumularPuntos(CompraCantidad*super.getPrecio());;
                                        factura.imprimirFactura(clienteReg.getNombreCliente(), stringTipoCliente, super.getNombreCombustible(), CompraCantidad, totalDescuento, super.getPrecio());

                                        canjearPuntos = 0;  // Restablecer los puntos canjeados
                                    }

                                clienteReg.ActualizarinstanciaEnArchivo(clienteReg.getId());
                                super.ActualizarinstanciaEnArchivo(super.getNombreCombustible());
                            break; 

                            case 2:
                                
                                cout << "Ingrese la cantidad de gasolina a comprar (litros): ";
                                cin >> CompraCantidad;

                                if (CompraCantidad > regular.getCantidadDisponible()) {
                                    cout << "No contamos con la cantidad de combustible disponible actualmente." << endl;
                                } else {
                                    cout <<"---------------------------------------------------------------------" <<  endl;
                                    cout << endl;
                                    if (clienteReg.getPuntos() >= 100) {
                                        cout << "Desea canjear puntos? 1: si, 2: no : " ;
                                        cin >> comprarPuntos;
                                        if (comprarPuntos == 1) {
                                            cout << "Cuantos puntos desea canjear? (usted posee " << clienteReg.getPuntos() << " puntos) : ";
                                            cin >> canjearPuntos;
                                            clienteReg.canjearPuntos(canjearPuntos);
                                        }
                                    }

                                    // Verificar si tiene descuento por tercera edad
                                    double descuentoTerceraEdad = clienteReg.calcularDescuentoTerceraEdad(CompraCantidad);
                                    if (clienteReg.getEdad() >= 65) {
                                        cout << "Descuento aplicado por tercera edad de un total de : " << descuentoTerceraEdad*100<< endl;
                                    }

                                    double descuentoPuntos = canjearPuntos;  // Aquí los puntos se convierten en descuento en dinero
                                    if (comprarPuntos == 1) {
                                        cout << "Puntos aplicados: " << descuentoPuntos << " LPS" << endl;
                                    }

                                    // Calcular el total del descuento en dinero
                                    double totalDescuento = descuentoTerceraEdad * regular.getPrecio() + descuentoPuntos;

                                    // Actualizar la cantidad disponible de combustible
                                    regular.setCantidadDisponible(regular.getCantidadDisponible() - CompraCantidad);

                                    // Imprimir factura
                                    cout <<endl;
                                    clienteReg.acumularPuntos(CompraCantidad*super.getPrecio());
                                    factura.imprimirFactura(clienteReg.getNombreCliente(), stringTipoCliente, super.getNombreCombustible(), CompraCantidad, totalDescuento, super.getPrecio());

                                    canjearPuntos = 0;  // Restablecer los puntos canjeados
                                }
                                    clienteReg.ActualizarinstanciaEnArchivo(clienteReg.getId());
                                    regular.ActualizarinstanciaEnArchivo(regular.getNombreCombustible());
                            break;

                            case 3 :

                                cout << "Ingrese la cantidad de gasolina a comprar (litros): ";
                                cin >> CompraCantidad;

                                if (CompraCantidad > regular.getCantidadDisponible()) {
                                    cout << "No contamos con la cantidad de combustible disponible actualmente." << endl;
                                } else {
                                    cout <<"---------------------------------------------------------------------" <<  endl;
                                    cout << endl;
                                    if (clienteReg.getPuntos() >= 100) {
                                        cout << "Desea canjear puntos? 1: si, 2: no : " ;
                                        cin >> comprarPuntos;
                                        if (comprarPuntos == 1) {
                                            cout << "Cuantos puntos desea canjear? (usted posee " << clienteReg.getPuntos() << " puntos) : ";
                                            cin >> canjearPuntos;
                                            clienteReg.canjearPuntos(canjearPuntos);
                                        }
                                    }

                                    // Verificar si tiene descuento por tercera edad
                                    double descuentoTerceraEdad = clienteReg.calcularDescuentoTerceraEdad(CompraCantidad);
                                    if (clienteReg.getEdad() >= 65) {
                                        cout << "Descuento aplicado por tercera edad de un total de : " << descuentoTerceraEdad*100<< endl;
                                    }

                                    double descuentoPuntos = canjearPuntos;  // Aquí los puntos se convierten en descuento en dinero
                                    if (comprarPuntos == 1) {
                                        cout << "Puntos aplicados: " << descuentoPuntos << " LPS" << endl;
                                    }

                                    // Calcular el total del descuento en dinero
                                    double totalDescuento = descuentoTerceraEdad * regular.getPrecio() + descuentoPuntos;

                                    // Actualizar la cantidad disponible de combustible
                                    regular.setCantidadDisponible(regular.getCantidadDisponible() - CompraCantidad);

                                    // Imprimir factura
                                    cout <<endl;
                                    clienteReg.acumularPuntos(CompraCantidad*super.getPrecio());
                                    factura.imprimirFactura(clienteReg.getNombreCliente(), stringTipoCliente, super.getNombreCombustible(), CompraCantidad, totalDescuento, super.getPrecio());

                                    canjearPuntos = 0;  // Restablecer los puntos canjeados
                                }
                            clienteReg.ActualizarinstanciaEnArchivo(clienteReg.getId());
                            regular.ActualizarinstanciaEnArchivo(regular.getNombreCombustible());

                            break;
                            default:
                                cout << "opcion  invalida "<< endl;

                            break;
                        }
                    }
                    cout << "-----------------------------------------------------------" << endl;
                    cout << endl;
                break;
                
                case 3:
                    continuar = false;
                    cout << "Saliendo del menu..." << endl;
                    break;
                default:
                    cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
                break;
            }
        }
    }
}


//Main
int main()
{
    EscribirArchiivoGasolina();
    int opcion;
    bool continuar = true;
    while (continuar) {
        cout << "===============================" << endl;
        cout << "          MENU PRINCIPAL        " << endl;
        cout << "===============================" << endl;
        cout << "1) Gestionar Clientes" << endl; //CRUD
        cout << "2) Gestionar Gasolina" <<  endl; //CRUD <--- unicamente para 3 , tiene limite 
        cout << "3) Gestionar Venta (Interfaz de Usuario)" <<  endl; //CR <--- No se hara UD
        cout << "4> Salir" << endl;
        cout << "===============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "" << endl;
        switch (opcion) {
            case 1:
                int tipoClienteGestion;
                cout << "Seleccione el tipo de cliente: " << endl;
                cout << "1) Cliente Corporativo" << endl;
                cout << "2) Cliente Regular" << endl;
                cout << "Seleccione una opcion: ";
                cin >> tipoClienteGestion;
                GestionarCliente(tipoClienteGestion);
                cout << endl;
            break;

            break;
            case 2:
                GestionarGasolina();
            break;
            case 3:
                int tipoClienteVenta;
                cout << "Seleccione el tipo de cliente: " << endl;
                cout << "1) Cliente Corporativo" << endl;
                cout << "2) Cliente Regular" << endl;
                cout << "Seleccione una opcion: ";
                cin >> tipoClienteVenta;
                GestionVentas(tipoClienteVenta);
                cout << endl;
            break;
            case 4:
                continuar = false;
            break;

            default:
                cout << "Opción no valida, intente nuevamente." << endl;
            break;
        }
    }
    return 0;
}
