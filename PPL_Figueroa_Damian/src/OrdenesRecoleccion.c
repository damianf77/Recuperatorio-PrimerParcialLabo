//Author: Figueroa Damian

#include "OrdenesRecoleccion.h"

#include "Nexo.h"


int initOrders (eOrden* ordersList, int len)
{
	int state = -1;

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			ordersList[i].isEmpty = EMPTY;
		}
	}
	return state;
}

int freeOrderSpot (eOrden* ordersList, int len)
{
	int position;

	position = -1;

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(ordersList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}

int newOrder (eCliente* clientList, eOrden* ordersList, eLocalidades* localitiesList, int len, int* uniqueOrderID) //
{
	eOrden newOrder;
	int posToSync;

	if(ordersList != NULL && clientList != NULL && len > 0)
	{
		*uniqueOrderID = *uniqueOrderID+1;

		posToSync = pedirID(clientList, localitiesList, len);
		newOrder.idCliente = clientList[posToSync].idCliente; /// FK
		newOrder.pesoOrden = obtieneEnteroValido("\t\t\t\t\t\t\tIngrese el peso del pedido de recoleccion que desea crear: ",
				"\t\t\t\t\t\tERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR ", 100, 100000);
		newOrder.idOrden = *uniqueOrderID;
		newOrder.estado = PENDING;

		addOrder(ordersList,len,newOrder.idCliente,newOrder.pesoOrden,newOrder.idOrden,newOrder.estado); ///
	}

	return 1;
}

int addOrder (eOrden* ordersList, int len, int clientId , int orderWeight, int orderId, int status) //
{
	int pos;

	if(ordersList != NULL && len > 0)
	{
		pos = freeOrderSpot(ordersList, len);

		ordersList[pos].idCliente = clientId;
		ordersList[pos].pesoOrden = orderWeight;
		ordersList[pos].idOrden = orderId;
		ordersList[pos].estado = PENDING;
		ordersList[pos].isEmpty = FULL;
	}
	return 1;
}

int showOneOrder (eOrden ordersList)
{
	int state;

	state = -1;

		printf(" %10d | %10d | %d | %d |\n",
		ordersList.idOrden,
		ordersList.pesoOrden,
		ordersList.estado,
		ordersList.isEmpty);

		state = 0;

	return state;
}

int showListOfOrders (eOrden* ordersList, int len)
{
	int state;

	state = -1;

	if(ordersList != NULL && len > 0)
	{
		printf("\n|ID Orden | Peso| Status | IsEmpty |\n");
		printf("|____________|_____________|______________|______|\n");

		if(ordersList != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(ordersList[i].isEmpty == FULL)
				{
					showOneOrder(ordersList[i]);
				}
			}
		}
	}

	return state;
}

int arrayChargeOrders (eOrden* ordersList, eCliente* clientList, int len, int* uniqueOrderID) ///
{
	int weight;
	int status;
	int pos;
	weight = 1333;

	if(ordersList != NULL && clientList != NULL && len > 0)
	{
		for(int i = 0; i < 12; i ++)
		{
			*uniqueOrderID = *uniqueOrderID+1;

			pos = freeOrderSpot(ordersList, len);
			ordersList[pos].idOrden = *uniqueOrderID;
			ordersList[pos].pesoOrden = weight+=33;
			ordersList[pos].idCliente = clientList[i].idCliente;
			status = PENDING;
			ordersList[pos].estado = status;
			ordersList[pos].isEmpty = FULL;
		}
	}

	return 1;
}

int idOrderAskForProcess(eCliente* clientList, eOrden* ordersList, int clientsLen, int ordersLen) ///
{
	int enteredId;
	int positionToUse;
	eCliente oneClient;

	if(ordersList != NULL && clientList != NULL && ordersLen > 0)
	{
		printf("\n\t\t\t\t\t\t\t|  ID Orden  |    Peso     |  Client ID   |   Estado     |\n");
		printf("\t\t\t\t\t\t\t|____________|_____________|______________|______________|\n");

		for(int i = 0; i < ordersLen; i++)
		{
			if(ordersList[i].isEmpty == FULL && ordersList[i].estado == PENDING)
			{
				oneClient = bringClients(clientList, clientsLen, ordersList[i].idCliente);

				printf("\t\t\t\t\t\t\t| %10d | %10d  | %10d   | %10d   |\n",
				ordersList[i].idOrden,
				ordersList[i].pesoOrden,
				oneClient.idCliente,
				ordersList[i].estado);
			}
		}

		enteredId = obtieneEnteroValido("\n\n\t\t\t\t\tDespues de haber visto la lista de los Id's de los clientes disponibles, a cual desea procesar?",
		"\n\n\t\t\t\t\tERROR - (Has ingresado un ID no existente intentelo nuevamente) - ERROR", 1, 100);

		positionToUse = orderIdValidation (ordersList, ordersLen, enteredId);
	}

	return positionToUse;
}

int idOrderAsk(eOrden* ordersList, int len)
{
	int enteredId;
	int positionToUse;

	if(ordersList != NULL && len > 0)
	{
		showListOfOrders(ordersList, len);

		enteredId = obtieneEnteroValido("Despues de haber visto la lista de los Id's de los clientes disponibles, a cual desea crearle un pedido?",
				"ERROR - (Has ingresado un ID no existente intentelo nuevamente) - ERROR", 1, 100);

		positionToUse = orderIdValidation (ordersList, len, enteredId);
	}

	return positionToUse;
}

int orderIdValidation (eOrden* ordersList, int len, int enteredId)
{
	int pos;

	pos = -1;

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(enteredId == ordersList[i].idOrden && ordersList[i].isEmpty == FULL)
			{
				pos = i;
				break;
			}
		}

		if(pos == -1)
		{
			printf("Lamentamos informale que ese id no existe!");
			idOrderAsk(ordersList, len);
		}
	}

	return pos;
}

int processingOrder (eCliente* clientList, eOrden* ordersList, sPlastics* plasticsList, int clientsLen, int ordersLen) //
{
	int state;
	int posOrderToProcess;
	int weightOfOrder;
	int processedStatus;

	state = -1;

	if(clientList != NULL && ordersList != NULL && clientsLen > 0 && ordersLen > 0)
	{
		posOrderToProcess = idOrderAskForProcess(clientList, ordersList, 100, 1000);

		weightOfOrder = ordersList[posOrderToProcess].pesoOrden;

		processedStatus	= PLA_processPlastics(plasticsList, ordersLen, ordersList[posOrderToProcess].idOrden, weightOfOrder);

		if(processedStatus == 0)
		{
			ordersList[posOrderToProcess].estado = COMPLETED;
			state = 0;
		}
		else
		{
			printf("No se pudo procesar el pedido correctamente volviendo al menu!");
			return EXIT_SUCCESS;
		}
	}

	return state;
}


