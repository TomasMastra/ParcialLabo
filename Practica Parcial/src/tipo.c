/*
 * tipo.c
 *
 *  Created on: 14 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef TIPO_C_
#define TIPO_C_
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "tipo.h"

int harcodearTipo(eTipo tipo[], int tamTipo)
{
	int ret;

	int i;
	char descripcion[][31] = {"SEDAN 3PTAS", "SEDAN 5PTAS","CAMIONETA"};
	int id[] = {1, 2, 3};


		for(i=0;i<tamTipo;i++)
		{
			tipo[i].idTipo = id[i];
			strcpy(tipo[i].descripcion, descripcion[i]);

			tipo[i].isEmpty = 1;
			ret=1;


		}


	return ret;

}


void ListarTipo(eTipo tipo)
{
	printf("%-20d  %-20s\n", tipo.idTipo, tipo.descripcion);


}
void ListarTipos(eTipo tipo[], int tamTipo)
{
	int i;

	printf("\nLista de tipos...\n\n"
							   "%-20s %-20s\n", "ID", "Descripcion");
	for(i=0;i<tamTipo;i++)
	{
		if(tipo[i].isEmpty == 1)
		{
			ListarTipo(tipo[i]);
		}
	}


}


#endif /* TIPO_C_ */
