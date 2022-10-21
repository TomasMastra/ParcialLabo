/*
 * Vehiculo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_

typedef struct
{
	int idVehiculo;
	char descripcion[31];
	int modelo;
	char color[11];
	int tipoId;

	int isEmpty;
}eVehiculo;


void inicializarVehiculo(eVehiculo vehiculo[], int tamVehiculo);
int buscarLibre(eVehiculo vehiculo[], int tamVehiculo);
void cargarVehiculo(eVehiculo vehiculo[], int tamVehiculo);
int buscarVehiculoPorId(eVehiculo vehiculo[], int tamVehiculo, int id);
//int modificarVehiculo(eVehiculo vehiculo[], int tamVehiculo);
int eliminarVehiculo(eVehiculo vehiculo[], int tamVehiculo);



#endif /* VEHICULO_H_ */
