//Author: Figueroa Damian

#ifndef ORDENESRECOLECCION_H_
#define ORDENESRECOLECCION_H_

#define FULL 0
#define EMPTY 1
#define COMPLETED 0
#define PENDING 1
#define ALL 2


#include "FuncionesFigueroa.h"
#include "Clientes.h"
#include "Plasticos.h"

struct
{
	// IDs
	int idOrden;
	int idCliente;
	int pesoOrden;

	// Data status
	int estado;
	int isEmpty;

}typedef eOrden;


//brief Inicia el vector de ordenes en vacio en todas las posiciones.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int iniciarOrden (eOrden* ordersList, int len);

//brief Busca un espacio libre en el vector para la creación de una nueva orden.

//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int espacioLibreOrden (eOrden* ordersList, int len);

//brief Pide todos los datos para crear una nueva orden.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int nuevaOrden (eCliente* clientList, eOrden* ordersList, eLocalidades* localitiesList, int len, int* uniqueOrderID);

//brief Da de alta una nueva orden relacionandola a un cliente existente.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int agregarOrden (eOrden* ordersList, int len, int clientId , int orderWeight, int orderId, int status);

//brief Muestra 1 orden.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int mostrarOrden (eOrden ordersList);

//brief Muestra la lista completa de ordenes.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int mostarListaOrdenes (eOrden* ordersList, int len);
int arrayChargeOrders (eOrden* ordersList, eCliente* clientList, int len, int* uniqueOrderID);

//brief Pide un id de una la lista de pedidos pendientes para procesarla.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int procesaOrden (eCliente* clientList, eOrden* ordersList, ePlasticos* plasticsList, int clientsLen, int ordersLen);
int pedirId(eOrden* ordersList, int len);
int idOrdenPedido(eCliente* clientList, eOrden* ordersList, int clientsLen, int ordersLen);
int validaOrden (eOrden* ordersList, int len, int enteredId);


#endif /* ORDENESRECOLECCION_H_ */
