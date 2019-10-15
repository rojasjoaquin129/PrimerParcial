#ifndef INFORMES_H_
#define INFORMES_H_
#define QTY_PEDIDOS 1000
#define QTY_CARACTERES 51

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

int printPedidosporclientes (aPedido* list,int length,aCliente*listCliente,int len,int estado);
int buscarclientesPorPedidos(aCliente *list, int len,int id);
int contarPedidoPorId(aPedido *list, int length,int id);
int printCantidadDePedidos (aPedido* list,int length,aCliente*listCliente,int len);

#endif /* IMFORMES_H_ */
