/*
 * pedido.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedido.h"
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

static int generarId(void){
	static int id = 0;
	id++;
	return id;
}


int initLugarLibrePedido(aPedido *aArray, int cantidad){
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

int buscarLugarLibrePedido(aPedido *aArray, int cantidad){
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

int printPedidos(aPedido *list, int length) {
	int i;
	int retorno = -1;
	if (list != NULL && length > 0) {
		retorno = 0;
		printf("id       id del Cliente       Kilos a recolectar        pendiente\n");
		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == STATUS_NOT_EMPTY) {
				printf("%d -- %d -- %d -- %d \n", list[i].id,
						list[i].idCliente, list[i].kilos, list[i].prendiente);
			}

		}
	}
	return retorno;
}


int buscarPedidoPorId(aPedido *aArray, int cantidad,int id){
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

int altaPedidoPorId(aPedido *aArray, int cantidad,aPedido item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarLugarLibrePedido(aArray, cantidad);
		if(index>=0){
			aArray[index] = item;
			aArray[index].prendiente=1;
			aArray[index].isEmpty = STATUS_NOT_EMPTY;
			aArray[index].id = generarId();
			retorno = 0;
		}
	}
	return retorno;
}






