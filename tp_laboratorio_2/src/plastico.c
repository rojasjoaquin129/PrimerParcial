/*
 * plastico.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "plastico.h"

static int generarId(void){
	static int id = 0;
	id++;
	return id;
}

int initLugarLibrePlastico(aPlastico *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			aArray[i].isEmpty = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarLugarLibrePlastico(aPlastico *aArray, int cantidad){
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].isEmpty == STATUS_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



int buscarPlasticoPorId(aPlastico *aArray, int cantidad,int id){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad > 0 ){
		for(i=0;i<cantidad;i++){
			if(aArray[i].id == id && aArray[i].isEmpty == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaPlasticoPorId(aPlastico *aArray, int cantidad,aPlastico item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0)
	{

		index = buscarLugarLibrePlastico(aArray, cantidad);
		if(index>=0){
			aArray[index] = item;
			aArray[index].isEmpty = STATUS_NOT_EMPTY;
			aArray[index].id = generarId();
			retorno = 0;
		}
	}
	return retorno;
}
