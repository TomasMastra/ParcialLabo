/*
 * tipo.h
 *
 *  Created on: 14 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{

	int idTipo;
	char descripcion[21];

	int isEmpty;

}eTipo;

int harcodearTipo(eTipo tipo[], int tamTipo);
void ListarTipo(eTipo tipo);
void ListarTipos(eTipo tipo[], int tamTipo);


#endif /* TIPO_H_ */
