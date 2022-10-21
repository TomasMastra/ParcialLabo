/*
 * nexo.h
 *
 *  Created on: 14 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef NEXO_H_
#define NEXO_H_

void cargarHojaServicio(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo);
int pedirVehiculo(eHojaServicio hojaServicio[], eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo, int index);
void listarVehiculoConTipo(eVehiculo vehiculo, eTipo tipo);
void listarVehiculosConTipo(eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo);
int modificarVehiculo(eVehiculo vehiculo[], int tamVehiculo, eHojaServicio hojaServicio[], int tamHojaServicio);
int compararVehiculo_Tipo(eTipo tipo[], int tamTipo, eVehiculo vehiculo);
int compararHojaServicio_Vehiculo(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo);
int compararVehiculo_HojaServicio(eVehiculo vehiculo[], int tamVehiculo, eHojaServicio hojaServicio);

void listarHojasConVehiculo(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo);
void listarHojaConVehiculo(eHojaServicio hojaServicio, eVehiculo vehiculo);


void mostrarVehiculoTipoSeleccionado(eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo);
void mostrarHojasFechaseleccionada(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo);


void mostrarSubemenu(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo);






#endif /* NEXO_H_ */
