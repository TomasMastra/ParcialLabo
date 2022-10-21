/*
 * nexo.c
 *
 *  Created on: 14 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef NEXO_C_
#define NEXO_C_

#include "Vehiculo.h"
#include "Funciones.h"
#include "HojaServicio.h"
#include "tipo.h"
#include "Nexo.h"

void cargarHojaServicio(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo)
{

	int i;
	int guardar;
	i = buscarLibre(vehiculo, tamVehiculo);

	{
		if(i != -1)
		{
			hojaServicio[i].idHoja=i+20000;

			getName(hojaServicio[i].descripcion, "Ingrese la descripcion: ", "ERROR, Ingrese la descripcion: ", 31);
			getFloat(&hojaServicio[i].precioServicio, "Ingrese el precio: ", "ERROR, Ingrese el precio: ", 1990, 2022);
			 pedirFecha(hojaServicio,  i);
			  pedirVehiculo(hojaServicio,  vehiculo,  tamVehiculo,  tipo,  tamTipo,  i);





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

int pedirVehiculo(eHojaServicio hojaServicio[], eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo, int index)
{
	int ret;
	int id;

	 listarVehiculosConTipo(vehiculo,  tamVehiculo,  tipo,  tamTipo);
	 getInt(&id, "Elija la ID del vehiculo que le corresponde: ", "Ingrese el ID del vehiculo que le corresponde: ", 0, 100000);
	 ret = 1;

	  while(buscarVehiculoPorId(vehiculo,  tamVehiculo,  id)==-1)
	  {
			getInt(&id, "Elija la ID del vehiculo que le corresponde: ", "Ingrese el ID del vehiculo que le corresponde: ", 0, 100000);

	  }


	  hojaServicio[index].vehiculoId = id;



	return ret;
}

void listarVehiculoConTipo(eVehiculo vehiculo, eTipo tipo)
{
	printf("%-20d %-20s  %-20d %-20s %20s\n", vehiculo.idVehiculo, vehiculo.descripcion, vehiculo.modelo, vehiculo.color, tipo.descripcion);


}
void listarVehiculosConTipo(eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo)
{
	int i;
	int j;

	printf("\nLista de vouchers...\n\n"
							   "%-20s %-20s %-20s %-20s %20s\n", "ID", "DESCRIPCION", "PRECIO", "MODELO", "TIPO");
	for(i=0;i<tamVehiculo;i++)
	{
		j = compararVehiculo_Tipo(tipo,  tamTipo,  vehiculo[i]);

		if(j!=-1)
		{
		listarVehiculoConTipo(vehiculo[i], tipo[j]);
		}

	}


}


int modificarVehiculo(eVehiculo vehiculo[], int tamVehiculo, eHojaServicio hojaServicio[], int tamHojaServicio)
{
	int index;
	int id;
	int opcion;
	int auxInt;
	char auxString[51];
	int validar=-1;
	int j;

	getInt(&id,"Ingrese ID del vehiculo para modificar: ","ERROR, Ingrese ID del vehiculo para modificar: ",0,5000);
	index = buscarVehiculoPorId(vehiculo,  tamVehiculo,  id);


	if(index!= -1)
	{

		getInt(&opcion,"Que quiere modificar? (1.descripcion, 2.precioServicio): ","ERROR, Que quiere modificar? (1.descripcion, 2.precioServicio): ",1,2);
		switch(opcion)
		{

		case 1:
		getName(auxString,"Ingrese la descripcion: ","ERROR, Ingrese la descripcion: ",51);

		printf("Ingrese 1 para modificar la descripcion: \n");
		scanf("%d", &validar);
		if(validar==1)
		{
			strcpy(vehiculo[index].descripcion, auxString);
		}

		break;

		case 2:

		getInt(&auxInt,"Ingrese el precio: ","ERROR, Ingrese el precio: ",50, 1000);
		printf("Ingrese 1 para modificar el precio: \n");
		scanf("%d", &validar);

		if(validar==1)
		{
			j =  compararHojaServicio_Vehiculo(hojaServicio,  tamHojaServicio, vehiculo[index]);

			hojaServicio[j].precioServicio = auxInt;
		}

		break;

		}

	}else
	{
		printf("No existe ese vehiculo!!!\n");
	}

	return index;
}


int compararVehiculo_Tipo(eTipo tipo[], int tamTipo, eVehiculo vehiculo)
{
	int ret=-1;

	for(int i=0;i<tamTipo;i++)
	{
		if(vehiculo.tipoId == tipo[i].idTipo  && vehiculo.isEmpty!=-1)
		{
			ret = i;
			break;
		}
	}


	return ret;
}

int compararHojaServicio_Vehiculo(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo)
{
	int ret=-1;

	for(int i=0;i<tamHojaServicio;i++)
	{
		if(vehiculo.idVehiculo == hojaServicio[i].vehiculoId  && vehiculo.isEmpty!=-1)
		{
			ret = i;
			break;
		}
	}


	return ret;
}

int compararVehiculo_HojaServicio(eVehiculo vehiculo[], int tamVehiculo, eHojaServicio hojaServicio)
{
	int ret=-1;

	for(int i=0;i<tamVehiculo;i++)
	{
		if(vehiculo[i].idVehiculo == hojaServicio.vehiculoId  && vehiculo[i].isEmpty!=-1)
		{
			ret = i;
			break;
		}
	}


	return ret;
}


void listarHojaConVehiculo(eHojaServicio hojaServicio, eVehiculo vehiculo)
{
	printf("%-20s  %-20f %-20s %d/%d/%d\n", hojaServicio.descripcion, hojaServicio.precioServicio, vehiculo.descripcion, hojaServicio.fecha.dia, hojaServicio.fecha.mes, hojaServicio.fecha.anio);


}
void listarHojasConVehiculo(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo)
{
	int i;
	int j;

	printf("\nLista de vouchers...\n\n"
							   "%-20s %-20s %-20s %-20s\n", "PRECIO", "DESCRIPCION", "DESTINO", "FECHA");
	for(i=0;i<tamVehiculo;i++)
	{
		j = compararVehiculo_HojaServicio(vehiculo,  tamVehiculo,  hojaServicio[i]);
		printf("%d\n",j);

		if(j!=-1)
		{
		listarHojaConVehiculo(hojaServicio[i], vehiculo[j]);
		}

	}


}


void mostrarVehiculoTipoSeleccionado(eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo)
{
	int idTipo;
		int j;
		getInt(&tipo, "Ingrese el Tipo: (1-SEDAN 3PTAS, 2-SEDAN 5PTAS, 3-CAMIONETA): ", "Ingrese el Tipo: (1-SEDAN 3PTAS, 2-SEDAN 5PTAS, 3-CAMIONETA): ", 2022, 2040);



		for(int i=0;i<tamVehiculo;i++)
		{
			if(vehiculo[i].tipoId == idTipo )
			{
				j= compararVehiculo_Tipo( tipo,  tamTipo,  vehiculo[i]);

				listarVehiculoConTipo( vehiculo[i],  tipo[j]);

			}
		}



}
void mostrarHojasFechaseleccionada(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo)
{
	int dia;
	int mes;
	int anio;
	int j;
	getInt(&anio, "Ingrese el anio: ", "Ingrese el anio: ", 2022, 2040);
	getInt(&mes, "Ingrese el mes: ", "Ingrese el mes: ", 1, 12);
	getInt(&dia, "Ingrese el dia: ", "Ingrese el dia: ", 1, 31);


	for(int i=0;i<tamHojaServicio;i++)
	{
		if(hojaServicio[i].fecha.anio == anio && hojaServicio[i].fecha.mes == mes && hojaServicio[i].fecha.dia == dia)
		{
			 compararVehiculo_HojaServicio( vehiculo,  tamVehiculo,  hojaServicio[i]);

			listarHojasConVehiculo( hojaServicio,  tamHojaServicio,  vehiculo,  tamVehiculo);

		}
	}


}

void mostrarSubemenu(eHojaServicio hojaServicio[], int tamHojaServicio, eVehiculo vehiculo[], int tamVehiculo, eTipo tipo[], int tamTipo)
{

	int opcion;
	 do
			 	    {

			 	    	getInt(&opcion, "-------------------------------------\n"
			 	    			"1- Mostrar vehículos de un tipo seleccionado"
			 	    			"2- Mostrar todas las hojas de servicio efectuadas en una fecha seleccionada"
			 	    			"3- Informar importe total de las hojas de servicio realizadas en un vehículo seleccionado"
			 	    			"4- Informar importe total"
			 	    								 "-------------------------------------\n",
			 	    								 "Enter the option: "
			 	    								 "-------------------------------------\n"
													 "1- Mostrar vehículos de un tipo seleccionado"
													 "2- Mostrar todas las hojas de servicio efectuadas en una fecha seleccionadaç"
													 "3- Informar importe total de las hojas de servicio realizadas en un vehículo seleccionado"
													 "4- Informar importe total"
			 	    								 "-------------------------------------\n"
			 	    								 "Invalid option, Enter the correct option: ", 1, 10);


			 	        switch(opcion)
			 	        {
			 	            case 1:

			 	            	 mostrarVehiculoTipoSeleccionado( vehiculo,  tamVehiculo,  tipo,  tamTipo);




			 	            break;
			 	            case 2:


			 	            	 mostrarHojasFechaseleccionada( hojaServicio,  tamHojaServicio,  vehiculo,  tamVehiculo);




			 	            break;
			 	            case 3:


			 	            	break;

			 	            case 4:


			 	             break;




			 	        }
			 	    }while(opcion!=10);

}

#endif /* NEXO_C_ */
