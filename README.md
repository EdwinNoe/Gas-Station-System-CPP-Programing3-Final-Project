# Sistema de Gestión de Gasolinera

## Proyecto Universitario
Este proyecto es parte del curso de Programación 3 como proyecto final.

## Presentación 
[Ver Presentación](https://youtu.be/9Px7wYd-tXM)

## Descripción del Caso a Desarrollar
Gasolinera que ofrece diferentes tipos de combustible. El proyecto consiste en desarrollar un programa para una gasolinera que ofrecer diferentes tipos de combustible. Este programa permitirá realizar gestiones CRUD para realizar los registros de la venta y compra de combustible, los cuales serán guardados en un archivo TXT.

## Descripción de Problemas a Resolver
Además del CRUD debe resolver los siguientes problemas:

- **Inventario**: El programa no permitirá realizar la venta de combustible si la gasolinera no cuenta con la cantidad suficiente en inventario.

- **Descuentos**:
  - **Descuento para Personas de la Tercera Edad**: Basado en la edad del cliente o si el cliente tiene descuento aplicado, se otorgará un 25% de descuento automáticamente a los clientes que tengan la edad mayor o igual a 65 años.
  
  - **Clientes Regulares**: Los clientes Regulares podrán acumular puntos; por cada compra acumularán el 10% en puntos, los cuales solo se pueden canjear si los puntos son mayores a 100. Cada punto de compra equivale a 1 lempira.

  - **Clientes Corporativos**: Los clientes corporativos no acumularán puntos, sin embargo, podrán tener la posibilidad de comprar crédito y pagar con crédito. Por cada recarga de crédito que sea mayor a 1000 lempiras, se le aplicará el 25% más al crédito. Ejemplo: si el cliente corporativo compra 1000 lempiras en crédito, se le aplicará 1225 en crédito. En caso de que la compra sea menor a 1000 lempiras, únicamente se le aplicará 10%.

## Características
- Gestión del inventario de combustible con operaciones CRUD.
- Descuentos automáticos para clientes elegibles.
- Sistema de acumulación de puntos para clientes regulares.
- Opciones de compra de crédito para clientes corporativos.
- Registros de ventas y compras guardados en un archivo TXT.

----------------------------------------------------------------------------------------------

# Gas Station Management System

## University Project
This project is part of the Programming 3 course as a final project.

## Presentation 
[View Presentation](https://youtu.be/9Px7wYd-tXM)

## Description of the Case to Develop
A gas station that offers different types of fuel. The project involves developing a program for a gas station that provides various types of fuel. This program will allow CRUD operations to register the sale and purchase of fuel, and these records will be saved in a TXT file.

## Description of Problems to Solve
In addition to the CRUD operations, the program must address the following issues:

- **Inventory**: The program will not allow fuel sales if the gas station does not have sufficient stock.

- **Discounts**:
  - **Senior Citizen Discount**: Based on the customer's age or if the customer has a discount applied, a 25% discount will be automatically granted to customers aged 65 or older.
  
  - **Regular Customers**: Regular customers will be able to accumulate points; for each purchase, they will earn 10% in points, which can only be redeemed if the points are greater than 100. Each point earned equals 1 lempira.

  - **Corporate Customers**: Corporate customers will not accumulate points; however, they will have the option to purchase credit and pay with credit. For each credit recharge greater than 1000 lempiras, an additional 25% will be applied to the credit. For example, if a corporate customer buys 1000 lempiras in credit, they will receive 1225 in credit. If the purchase is less than 1000 lempiras, only a 10% increase will be applied.

## Features
- Management of fuel inventory with CRUD operations.
- Automatic discounts for eligible customers.
- Point accumulation system for regular customers.
- Credit purchase options for corporate customers.
- Records of sales and purchases saved in a TXT file.