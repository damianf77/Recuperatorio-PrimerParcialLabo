//Author: Figueroa Damian

#ifndef NEXUS_H_
#define NEXUS_H_

#include "FuncionesFigueroa.h"
#include "Clientes.h"
#include "Localidad.h"
#include "OrdenesRecoleccion.h"



#endif /* NEXUS_H_ */

int showClientsWithPendingOrders (eCliente* clientList, sOrders* ordersList,eLocalidades* localitiesList, int clientsLen, int lenOrders, int localitiesLen); // 6
int showPedingOrdersWithClientsInfo (eCliente* clientList, sOrders* ordersList, int lenClients, int lenOrders); // 7
int showCompleteOrdersWithWeight (eCliente* clientList, sOrders* ordersList, sPlastics* plasticList, int clientsLen, int ordersLen); // 8
int showPendingOrdersByLocality (eLocalidades* localitiesList, eCliente* clientList, sOrders* ordersList, int lenClients, int lenOrders, int* uniqueLocalityID); // 9
int averagePPRecicledByClient (eCliente* clientList, sOrders* ordersList,sPlastics* plasticList, int clientsLen, int ordersLen); // 10
int clientWithMostOrders (eCliente* clientList, eLocalidades* localitiesList,sOrders* ordersList, int clientsLen, int ordersLen, int status); // 11 12 13
int printplasticRecicledByLocality(eCliente* clientList, eLocalidades* localitiesList,sOrders* ordersList, sPlastics* plasticList, int clientsLen, int ordersLen, char locality[], int id);
int plasticRecicledByLocality(eCliente* clientList, eLocalidades* localitiesList,sOrders* ordersList, sPlastics* plasticList, int clientsLen, int ordersLen, int* uniqueLocalityID);
int CLI_printOneClientWithLocality(eCliente clientList, eLocalidades* localitiesList, int clientsLen, int localitiesLen);
int CLI_printClientsListWithLocalities(eCliente* clientList, eLocalidades* localitiesList, int clientsLen, int localitiesLen);


eCliente bringClients(eCliente* clientList,int lenClients, int id);
int deliverOrders (sOrders* ordersList,int ordersLen, int id);
sOrders bringOrders(sOrders* ordersList, int ordersLen, int id);
sPlastics bringPlasticTypes (sPlastics* plasticList, int plasticLen, int id);
int ppAcumulator (sPlastics* plasticList,int lenPlastic, int id); // 10
int countClientsByOrder (sOrders* ordersList, sPlastics* plasticsList,int ordersLen, int id);
int mostOrdersFinder (sOrders* ordersList, int ordersLen, int id, int status);

