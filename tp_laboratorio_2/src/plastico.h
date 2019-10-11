/*
 * plastico.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PLASTICO_H_
#define PLASTICO_H_


#define QTY_PLASTICOS 1000
#define QTY_CARACTERES 51

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct {
	int id;
	int idPedido;
	int HDPE;
	int LDPE;
	int PP;
	int isEmpty;

}typedef aPlastico;


int initLugarLibrePlastico(aPlastico *aArray, int cantidad);
int buscarLugarLibrePlastico(aPlastico *aArray, int cantidad);
int buscarPlasticoPorId(aPlastico *aArray, int cantidad,int id);
int altaPlasticoPorId(aPlastico *aArray, int cantidad,aPlastico item);
#endif /* PLASTICO_H_ */
