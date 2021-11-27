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
	int orderId;
	int clientId;
	int orderWeight;

	// Data status
	int status;
	int isEmpty;

}typedef sOrders;

/// @fn int initOrders(sOrders*, int)
/// @brief Inicia el vector de ordenes en vacio en todas las posiciones.
///
/// @param ordersList
/// @param len
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int initOrders (sOrders* ordersList, int len);

/// @fn int freeOrderSpot(sOrders*, int)
/// @brief Busca un espacio libre en el vector para la creación de una nueva orden.
///
/// @param ordersList
/// @param len
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int freeOrderSpot (sOrders* ordersList, int len);

/// @fn int newOrder(eClients*, sOrders*, sLocality*, int, int*)
/// @brief Pide todos los datos para crear una nueva orden.
///
/// @param clientList
/// @param ordersList
/// @param localitiesList
/// @param len
/// @param uniqueOrderID
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int newOrder (eCliente* clientList, sOrders* ordersList, eLocalidades* localitiesList, int len, int* uniqueOrderID);

/// @fn int addOrder(sOrders*, int, int, int, int, int)
/// @brief Da de alta una nueva orden relacionandola a un cliente existente.
///
/// @param ordersList
/// @param len
/// @param clientId
/// @param orderWeight
/// @param orderId
/// @param status
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int addOrder (sOrders* ordersList, int len, int clientId , int orderWeight, int orderId, int status);

/// @fn int showOneOrder(sOrders)
/// @brief Muestra 1 orden.
///
/// @param ordersList
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int showOneOrder (sOrders ordersList);

/// @fn int showListOfOrders(sOrders*, int)
/// @brief Muestra la lista completa de ordenes.
///
/// @param ordersList
/// @param len
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int showListOfOrders (sOrders* ordersList, int len);
int arrayChargeOrders (sOrders* ordersList, eCliente* clientList, int len, int* uniqueOrderID);

/// @fn int processingOrder(eClients*, sOrders*, sPlastics*, int, int)
/// @brief Pide un id de una la lista de pedidos pendientes para procesarla.
///
/// @param clientList
/// @param ordersList
/// @param plasticsList
/// @param clientsLen
/// @param ordersLen
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int processingOrder (eCliente* clientList, sOrders* ordersList, sPlastics* plasticsList, int clientsLen, int ordersLen);
int idOrderAsk(sOrders* ordersList, int len);
int idOrderAskForProcess(eCliente* clientList, sOrders* ordersList, int clientsLen, int ordersLen);
int orderIdValidation (sOrders* ordersList, int len, int enteredId);


#endif /* ORDENESRECOLECCION_H_ */
