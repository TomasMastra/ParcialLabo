/*
 * HojaServicio.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Tomas Mastra
 */

#include "HojaServicio.h"
#include "Funciones.h"

void inicializar(eHojaServicio hojaServicio[], int tamHojaServicio)
{
	for(int i=0;i<tamHojaServicio;i++)
	{
		hojaServicio[i].isEmpty = -1;
	}
}


int buscarLibreHojaServicio(eHojaServicio hojaServicio[], int tamHojaServicio)
{
	int i;
	int ret=-1;

	for(i=0;i<tamHojaServicio;i++)
	{
		if(hojaServicio[i].isEmpty==-1)
		{
			ret=i;
			break;
		}
	}



	return ret;

}


void pedirFecha(eHojaServicio hojaServicio[], int index)
{


		int anio;
		int mes;
		int dia;

		getInt(&anio, "Ingrese el anio: ", "ERROR, Ingrese el anio: ", 2022, 2040);
		getInt(&mes, "Ingrese el mes: ", "ERROR, Ingrese el mes: ", 1, 12);
		getInt(&dia, "Ingrese el dia: ", "ERROR, Ingrese el dia: ", 1, 31);


		while(isValidFecha(dia,  mes,  anio)==-1)
		{
			printf("\nERROR, ingrese una fecha correcta!!!!!\n");
			getInt(&anio, "Ingrese el anio: ", "ERROR, Ingrese el anio: ", 2022, 2040);
			getInt(&mes, "Ingrese el mes: ", "ERROR, Ingrese el mes: ", 1, 12);
			getInt(&dia, "Ingrese el dia: ", "ERROR, Ingrese el dia: ", 1, 31);

		}

		hojaServicio[index].fecha.dia = dia;
		hojaServicio[index].fecha.mes = mes;
		hojaServicio[index].fecha.anio = anio;



}
