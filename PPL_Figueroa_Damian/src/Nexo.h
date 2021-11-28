//Author: Figueroa Damian

#ifndef NEXUS_H_
#define NEXUS_H_

#include "FuncionesFigueroa.h"
#include "Clientes.h"
#include "Localidad.h"
#include "OrdenesRecoleccion.h"



#endif /* NEXUS_H_ */

int mostrarClientesOrdenesPendientes (eCliente* clientList, eOrden* ordersList,eLocalidades* localitiesList, int clientsLen, int lenOrders, int localitiesLen); // 6
int ordenPendienteClienteInfo (eCliente* clientList, eOrden* ordersList, int lenClients, int lenOrders); // 7
int mostrarOrdenCompletaPeso (eCliente* clientList, eOrden* ordersList, ePlasticos* plasticList, int clientsLen, int ordersLen); // 8
int ordenPendienteLocalidad (eLocalidades* localitiesList, eCliente* clientList, eOrden* ordersList, int lenClients, int lenOrders, int* uniqueLocalityID); // 9
int promedioPPporCliente (eCliente* clientList, eOrden* ordersList,ePlasticos* plasticList, int clientsLen, int ordersLen); // 10
int clienteMasOrdenes (eCliente* clientList, eLocalidades* localitiesList,eOrden* ordersList, int clientsLen, int ordersLen, int status); // 11 12 13
int imprimirPlasticoRecicladoLocalidad(eCliente* clientList, eLocalidades* localitiesList,eOrden* ordersList, ePlasticos* plasticList, int clientsLen, int ordersLen, char locality[], int id);
int plasticoRecicladoLocalidad(eCliente* clientList, eLocalidades* localitiesList,eOrden* ordersList, ePlasticos* plasticList, int clientsLen, int ordersLen, int* uniqueLocalityID);
int imprimeClientePorLocalidad(eCliente clientList, eLocalidades* localitiesList, int clientsLen, int localitiesLen);
int imprimirListaClientesLocalidades(eCliente* clientList, eLocalidades* localitiesList, int clientsLen, int localitiesLen);


eCliente obtenerClientes(eCliente* clientList,int lenClients, int id);
int deliverOrders (eOrden* ordersList,int ordersLen, int id);
eOrden traerOrdenes(eOrden* ordersList, int ordersLen, int id);
ePlasticos traerPlasticos (ePlasticos* plasticList, int plasticLen, int id);
int ppAcumulador (ePlasticos* plasticList,int lenPlastic, int id); // 10
int cuentaClientesPorOrden (eOrden* ordersList, ePlasticos* plasticsList,int ordersLen, int id);
int buscaMayoriaOrdenes (eOrden* ordersList, int ordersLen, int id, int status);

