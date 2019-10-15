#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
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

		printf("id       id del Cliente       Kilos a recolectar        Estado\n");
		for (i = 0; i < length; i++) {
            if (list[i].isEmpty == STATUS_NOT_EMPTY) {
                if(list[i].prendiente==0){
                    printf("%d ------------ %d ------------------- %d ------------------- Completado \n", list[i].id,
						list[i].idCliente, list[i].kilos);
                    } else {
                    printf("%d ------------ %d ------------------- %d ------------------- pendiente \n", list[i].id,
						list[i].idCliente, list[i].kilos);
                        }
			}

		}
	}
	return retorno;
}

int ordenarPedidoPorCliente(aPedido*aArray,int cantidad){
    int i;
	int retorno = -1;
	aPedido buffer;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(aArray[i].idCliente<aArray[i+1].idCliente)
				{
					fSwap = 1;
					buffer = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=buffer;
				}
				else if(aArray[i].idCliente==aArray[i+1].idCliente)
				{
					if(aArray[i].kilos>aArray[i+1].kilos)
					{
						fSwap = 1;
						buffer = aArray[i];
						aArray[i]=aArray[i+1];
						aArray[i+1]=buffer;
					}
				}
			}
		}while(fSwap);
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





int modificarPedidoporId(aPedido *list, int len, aPedido item) {
	int retorno = -1;
	int index;
	if (list != NULL && len > 0) {
		index = buscarPedidoPorId(list, len, item.id);
		if (index != -1) {
			list[index] = item;
			list[index].prendiente=0;
			list[index].isEmpty = STATUS_NOT_EMPTY;
			retorno = 0;
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
