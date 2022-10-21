/*
 * HojaServicio.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;
typedef struct
{
	int idHoja;
	int vehiculoId;
	char descripcion[31];
	float precioServicio;
	eFecha fecha;
	int isEmpty;

}eHojaServicio;

int buscarLibreHojaServicio(eHojaServicio hojaServicio[], int tamHojaServicio);
void pedirFecha(eHojaServicio hojaServicio[], int index);
void inicializar(eHojaServicio hojaServicio[], int tamHojaServicio);

#endif /* HOJASERVICIO_H_ */
