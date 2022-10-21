/*
 * Veniculo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Tomas Mastra
 */

#include <stdio.h>
#include <stdlib.h>
#include "vehiculo.h"
#include "Funciones.h"


void inicializarVehiculo(eVehiculo vehiculo[], int tamVehiculo)
{

	int i;

	for(i=0;i<tamVehiculo;i++)
	{
		vehiculo[i].isEmpty=-1;
		vehiculo[i].idVehiculo=0;

	}
}


int buscarLibre(eVehiculo vehiculo[], int tamVehiculo)
{
	int i;
	int ret=-1;

	for(i=0;i<tamVehiculo;i++)
	{
		if(vehiculo[i].isEmpty==-1)
		{
			ret=i;
			break;
		}
	}



	return ret;

}

/////////

void cargarVehiculo(eVehiculo vehiculo[], int tamVehiculo)
{

	int i;
	int guardar;
	i = buscarLibre(vehiculo, tamVehiculo);

	{
		if(i != -1)
		{
			vehiculo[i].idVehiculo=i+1000;

			getName(vehiculo[i].descripcion, "Ingrese la descripcion: ", "ERROR, Ingrese la descripcion: ", 31);
			getInt(&vehiculo[i].modelo, "Ingrese el modelo (anio de fabricacion): ", "ERROR, Ingrese el modelo (anio de fabricacion): ", 1990, 2022);
			getName(vehiculo[i].color, "Ingrese el color: ", "ERROR, Ingrese elcolor: ", 11);
			getInt(&vehiculo[i].tipoId, "Ingrese el Tipo: (1-SEDAN 3PTAS, 2-SEDAN 5PTAS, 3-CAMIONETA): ", "ERROR, Ingrese el Tipo: (1-SEDAN 3PTAS, 2-SEDAN 5PTAS, 3-CAMIONETA): ", 1, 3);





			getInt(&guardar, "Ingrese 1 para guardar o 2 para no guardarlo: ", "ERROR, Ingrese 1 para guardar: ", 1, 2);


			if(guardar==1)
			{
				vehiculo[i].isEmpty=1;
			}


		}else
		{
			printf("No hay espacio\n");
		}
	}
}

int buscarVehiculoPorId(eVehiculo vehiculo[], int tamVehiculo, int id)
{
	int index=-1;
	for(int i=0;i<tamVehiculo; i++)
	{
		if(vehiculo[i].idVehiculo == id && vehiculo[i].isEmpty!=-1)
		{
			index = i;
			break;
		}
	}



	return index;
}



int eliminarVehiculo(eVehiculo vehiculo[], int tamVehiculo)
{
	int id;
	int confirmar;
	int index;

	getInt(&id,"Ingrese ID para eliminar: ","ERROR, Ingrese ID para eliminar: ",1000,5000);
	index = buscarVehiculoPorId(vehiculo,  tamVehiculo,  id);

	if(index!= -1)
	{
		getInt(&confirmar, "Ingrese 1 para eliminar o 2 para cancelar: ", "ERROR, Ingrese 1 para eliminar: ", 1, 2);
		if(confirmar == 1)
		{
			vehiculo[index].isEmpty=-1;
			printf("vehiculo eliminado con exito\n");
		}

	}else
	{
		printf("ERROR, No se encontro ese vehiculo\n");
	}



	return index;
}
