/*
 ============================================================================
 Name        : Practica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Vehiculo.h"
#include "Funciones.h"
#include "tipo.h"
#include "HojaServicio.h"
#include "Nexo.h"





int main(void) {

	setbuf(stdout,NULL);
	int opcion;

	int banderaAltaVehiculo = 1;
	int banderaAltaHojaServicio = 1;

	eVehiculo vehiculo[300];
		int tamVehiculo=300;

		eTipo tipo[3];
		int tamTipo = 3;

		eHojaServicio hojaServicio[300];
		int tamHojaServicio = 300;

		inicializarVehiculo(vehiculo,  tamVehiculo);
		harcodearTipo(tipo,  tamTipo);
		 inicializar(hojaServicio,  tamHojaServicio);




	 do
		 	    {

		 	    	getInt(&opcion, "-------------------------------------\n"
		 	    								 "1. ALTA VEHICULO\n"
		 	    								 "2. MODIFICAR VEHICULO\n"
		 	    								 "3. BAJA VEHICULO\n"
		 	    								 "4. LISTAR EVHICULO\n"
		 	    								 "5. LISTAR TIPOS\n"
		 	    								 "6. ALTA HOJAS\n"
		 	    								 "7. LISTAR HOJA\n"
		 	    								 "8. SUB MENU\n"
		 	    								 "-------------------------------------\n",
		 	    								 "Enter the option: "
		 	    								 "-------------------------------------\n"
												 "1. ALTA VEHCIULO\n"
												 "2. MODIFICAR VEHICULO\n"
												 "3. BAJA VEHICULO\n"
												 "4. LISTAR VEHICULO\n"
												 "5. LISTAR TIPOS\n"
												 "6. ALTA HOJA\n"
												 "7. LISTAR HOJA\n"
												 "8. SUB MENU\n"
		 	    								 "-------------------------------------\n"
		 	    								 "Invalid option, Enter the correct option: ", 1, 10);


		 	        switch(opcion)
		 	        {
		 	            case 1:

		 	           	 banderaAltaVehiculo = 0;

		 	            	cargarVehiculo(vehiculo,  tamVehiculo);



		 	            break;
		 	            case 2:

		 	            	if(	 banderaAltaVehiculo == 0)
		 	            	{


		 	            	 modificarVehiculo(vehiculo,  tamVehiculo,  hojaServicio,  tamHojaServicio);
		 	            	}





		 	            break;
		 	            case 3:
		 	            	if(	 banderaAltaVehiculo == 0)
		 	            	{
			 	             eliminarVehiculo(vehiculo,  tamVehiculo);
		 	            	}


		 	            	break;

		 	            case 4:
		 	            	if(	 banderaAltaVehiculo == 0)
		 	            	{
		 	             listarVehiculosConTipo(vehiculo,  tamVehiculo,  tipo,  tamTipo);
		 	            	}


		 	             break;
		 	            case 5:
		 	            	 ListarTipos(tipo,  tamTipo);



		 	            	break;
		 	            case 6:
		 	           	 banderaAltaHojaServicio = 0;
		 	           	cargarHojaServicio(hojaServicio,  tamHojaServicio,  vehiculo,  tamVehiculo,  tipo,  tamTipo);


		 	            	break;

		 	            case 7:
		 	            	if(	 banderaAltaHojaServicio == 0)
		 	            	{
		 	             listarHojasConVehiculo(hojaServicio,  tamHojaServicio,  vehiculo,  tamVehiculo);
		 	            	}


		 	            	break;

		 	            case 8:
		 	            	if(	 banderaAltaVehiculo == 0 && banderaAltaHojaServicio == 0)
		 	            	{
		 	            		 mostrarSubemenu( hojaServicio,  tamHojaServicio,  vehiculo,  tamVehiculo,  tipo,  tamTipo);

		 	            	}

		 	            	break;




		 	        }
		 	    }while(opcion!=10);


	return EXIT_SUCCESS;
}
