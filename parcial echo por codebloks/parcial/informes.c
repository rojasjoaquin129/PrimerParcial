#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
#include "informes.h"



int contarPedidoPorId(aPedido *list, int length,int id) {
	int i;
	int contador=0;
	int retorno = -1;
	if(list!=NULL && length>0){
    for (i = 0; i < length; i++) {
        if (list[i].isEmpty == STATUS_NOT_EMPTY && list[i].prendiente==1) {
            if(list[i].idCliente==id){
                contador++;
            }
			}
          }
          retorno=contador;
		}
    return retorno;
}

int printCantidadDePedidos (aPedido* list,int length,aCliente*listCliente,int len){
    int retorno=-1;
    int i;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        printf("ID    NOMBRE    CUIT   DIRECCION    LOCALIDAD    PEDIDOS");
        for(i=0;i<len;i++){
            if(listCliente[i].isEmpty==STATUS_NOT_EMPTY){
                printf("\n%d-----%s----%s------%s------%s-----%d\n",listCliente[i].id,
                    listCliente[i].nombre,listCliente[i].cuit,
                    listCliente[i].localidad,listCliente[i].direccion,contarPedidoPorId(list,length,listCliente[i].id));
                }
        }
        retorno=0;
    }
	return retorno;
}


int printPedidosporclientes (aPedido* list,int length,aCliente*listCliente,int len,int estado){
    int retorno=-1;
    int i;
    int posicion;
    if(list!=NULL && length>0 && listCliente!=NULL && len>0){
        printf("ID    CUIT   DIRECCION    LOCALIDAD  RECOLECTAR(kilos)");
        for(i=0;i<len;i++){
            if(list[i].isEmpty==STATUS_NOT_EMPTY && list[i].prendiente==estado){
                posicion=buscarclientesPorPedidos(listCliente,len,list[i].idCliente);
                if(posicion!=-1){
                printf("\n%d-----%s----%s------%s------%d\n",list[i].id,
                    listCliente[posicion].cuit,
                    listCliente[posicion].direccion,listCliente[posicion].localidad,list[i].kilos);
                }
            }
        }
        retorno=0;
    }
	return retorno;
}

int buscarclientesPorPedidos(aCliente *list, int len,int id) {
	int i;
	int retorno = -1;
	if(list!=NULL && len>0){
    for (i = 0; i < len; i++) {
        if (list[i].isEmpty == STATUS_NOT_EMPTY ) {
            if(list[i].id==id){
            retorno=i;
            }
        }
          }
		}
    return retorno;
}
