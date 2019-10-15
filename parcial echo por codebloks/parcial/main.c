#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
#include "informes.h"
void CargaForzadaCliente(aCliente *list, int len);
void CargaForzadaPedidos(aPedido *list, int len);
int main(void) {
	aCliente list[QTY_CLIENTES];
	aPedido  pedidos[QTY_PEDIDOS];
	int out = 1;
	int id = 0;
	int assistantAdd = -1;
	int opcion = 0;
	initCliente(list, QTY_CLIENTES);
	initLugarLibrePedido(pedidos,QTY_PEDIDOS);
	CargaForzadaCliente(list,QTY_CLIENTES);
	CargaForzadaPedidos(pedidos,QTY_PEDIDOS);
	do {
		printf("\n"
				"1. Alta de cliente\n"
				"2. Modificacion datos del cliente\n"
				"3. Baja del cliente\n"
				"4. crear pedido de recoleccion\n"
				"5. procesar resuidos\n"
				"6. imprimir Clientes\n"
				"7. Imprimir pedidos Pendientes\n"
				"8. Imprimir Pedidos Procesados\n"
				"9. Salir\n");

		getInt(&opcion, "\nIngrese la opcion\n", "\n Error\n", 1, 9, 3);
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
			altaPedidoUI(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
		case 5:
			modificacionPedidoUI(pedidos,QTY_PEDIDOS);
		case 6:
            printCantidadDePedidos(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES);
            break;
        case 7:
            printPedidosporclientes(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES,1);
            break;
        case 8:
            printPedidosporclientes(pedidos,QTY_PEDIDOS,list,QTY_CLIENTES,0);
            break;
		case 9:
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

/*
 * \brief Carga forzada de datos para la entidad Pedido
 * \param list Pedido*
 * \param len int
 */
void CargaForzadaPedidos(aPedido *list, int len)
{
	int kilos[]={1000,100,150,10,1000,400,390,1000,390,2000,200};
	int aIdCliente[]={1,4,2,4,1,5,3,3,1,3,5};
	aPedido bPedido;
	int i;
	for(i=0;i<11;i++){
		bPedido.kilos= kilos[i];
		bPedido.idCliente = aIdCliente[i];
		altaPedidoPorId(list, len, bPedido);
	}

}


/*
 * \brief Carga forzada de datos para la entidad Cliente
 * \param list Cliente*
 * \param len int
 */
void CargaForzadaCliente(aCliente *list, int len)
{
	char aNombre[][QTY_CARACTERES]={"Ana","Brian","Micaela","Julian","Mabel","Matias"};
	char aCuit[][QTY_CARACTERES]={"36-83253654-5","18-95375743-5","17-23178762-3","20-23298383-5","23-21898839-4","20-34558439-8"};
	char aDireccion[][QTY_CARACTERES]={"Euskadi 2965 ","Zumaya 152","Jorge 2568","Madrid 168","Santa catalina 156","Juan XXIII 744"};
	char aLocalidad[][QTY_CARACTERES]={"Lanus","avellaneda","Lomas de Zamora","Bamfiel","chacarita",""};
	aCliente bCliente;
	int i;
	for(i=0;i<6;i++){
		strncpy(bCliente.nombre,aNombre[i],QTY_CARACTERES);
		strncpy(bCliente.cuit,aCuit[i],QTY_CARACTERES);
		strncpy(bCliente.direccion,aDireccion[i],QTY_CARACTERES);
		strncpy(bCliente.localidad,aLocalidad[i],QTY_CARACTERES);

		addCliente(list, len, bCliente);
	}

}




