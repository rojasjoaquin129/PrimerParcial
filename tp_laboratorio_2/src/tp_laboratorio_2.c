/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedido.h"
#include "plastico.h"
#include "ArrayClientes.h"

int main(void) {
	aCliente list[QTY_CLIENTES];
	aPedido  pedidos[QTY_PEDIDOS];
	aPedido bPedidos;
	aPlastico plastico[QTY_PLASTICOS];
	aPlastico bPlastico;
	int posicion;
	int auxPlastico;
	int out = 1;
	int id = 0;
	int assistantAdd = -1;
	int opcion = 0;
	initCliente(list, QTY_CLIENTES);
	do {
		printf("\n"
				"1. Alta de cliente\n"
				"2. Modificacion datos del cliente\n"
				"3. Baja del cliente\n"
				"4. Lista de Empleados\n"
				"5. Salir\n");

		getInt(&opcion, "\nIngrese la opcion\n", "\n Error\n", 1, 5, 3);
		switch (opcion) {
		case 1:
			if (addUI(list, QTY_CLIENTES, id) == 0) {
				assistantAdd = 0;
				break;
			}
			break;
		case 2:
			if (assistantAdd == 0) {
				modifyUI(list, QTY_CLIENTES);
			} else {
				printf("No existe ningun CLIENTE para modificar\n");
			}
			break;
		case 3:
			if (assistantAdd == 0) {
				removeUI(list, QTY_CLIENTES);
			} else {
				printf("No existe ningun empleado para eliminar\n");
			}
			break;
		case 4:

			printf("Alta de pedido\n");
			if (buscarLugarLibrePedido(pedidos, QTY_PEDIDOS) == -1) {
				printf("Error no hay mas lugar para pedidos\n");
				break;
			}
			printCliente(list,QTY_CLIENTES);
			if (getInt(&bPedidos.idCliente, "Ingrese el id del cliente\n", "Error",
							1, 1000000, 2) == -1) {
				printf("Error en el id\n");
				break;
			}
			if(findClienteById(list,QTY_CLIENTES, bPedidos.idCliente)== -1){
				printf("Error id del cliente inexistente");
				break;
			}
			if (getInt(&bPedidos.kilos, "Ingrese la cantidad de kilos\n", "Error",
								1, 10000000, 2) == -1) {
				printf("Error en la cantidad de kilos\n");
				break;
			}
			if (altaPedidoPorId(pedidos, QTY_PEDIDOS	, bPedidos) == 0) {
							printf("pedido de recoleccion exitoso\n");
				} else {
					printf("Error al hacer el pedido\n");

			      }
			break;
		case 5:
			if (buscarLugarLibrePlastico(plastico, QTY_PLASTICOS) == -1) {
				printf("Error no hay mas lugar para pedidos\n");
				break;
				}
			printPedidos(pedidos,QTY_PEDIDOS);
			if (getInt(&bPlastico.idPedido, "Ingrese el id del pedido\n", "Error",
							1, 1000000, 2) == -1) {
				printf("Error en el id\n");
				break;
			}
			posicion=buscarPedidoPorId(pedidos,QTY_PEDIDOS, bPlastico.idPedido);
			if(posicion== -1){
					printf("Error id del pedido inexistente");
					break;
			}
			if (getInt(&bPlastico.HDPE, "Ingrese la cantidad de polietileno de alta densidad\n", "Error",
										1, 1000000, 2) == -1) {
				printf("Error en la cantidad de HDPE\n");
				break;
			}
			if (getInt(&bPlastico.LDPE, "Ingrese la cantidad de polietileno de Baja densidad\n", "Error",
													1, 1000000, 2) == -1) {
				printf("Error en la cantidad de LDPE\n");
				break;
			}
			if (getInt(&bPlastico.PP, "Ingrese la cantidad de polietileno \n", "Error\n",
													1, 1000000, 2) == -1) {
				printf("Error en la cantidad de PP\n");
				break;
			}
			auxPlastico=bPlastico.PP+bPlastico.HDPE+bPlastico.PP;
			if(auxPlastico>pedidos[posicion].kilos){
				printf("Error en la cantidad de plastico");
				break;
			}

			if (altaPlasticoPorId(plastico, QTY_PLASTICOS, bPlastico) == 0) {
				printf("PROCESO exitoso\n");
				pedidos[posicion].prendiente=0;
				} else {
				printf("Error al hacer el PROCESO\n");

			      }
			break;
		case 6:

			break;

		case 10:
			out = 0;
			printf("Que tenga un buen dia\n");
			break;
		default:
			printf("ERROR, la opcion es invalida\n");
			break;
		}
	} while (out);
	return EXIT_SUCCESS;
}
