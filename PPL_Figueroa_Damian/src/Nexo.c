//Author: Figueroa Damian

#include "Nexo.h"

eCliente obtenerClientes(eCliente* listaClientes, int lenClientes, int id)
{
	eCliente unCliente;

	if(listaClientes != NULL && lenClientes > 0)
	{
		for(int i = 0; i < lenClientes; i++)
		{
			if(listaClientes[i].idCliente == id && listaClientes[i].isEmpty == FULL)
			{
				unCliente = listaClientes[i];
				break;
			}
		}
	}

	return unCliente;
}

eOrden traerOrdenes(eOrden* listaOrdenes, int lenOrden, int id)
{
	eOrden unaOrden;

	unaOrden.isEmpty = EMPTY;

	if(listaOrdenes != NULL && lenOrden > 0)
	{
		for(int i = 0; i < lenOrden; i++)
		{
			if(listaOrdenes[i].estado == COMPLETED
			&& listaOrdenes[i].idCliente == id)
			{
				unaOrden = listaOrdenes[i];
				break;
			}
		}
	}

	return unaOrden;
}

ePlasticos traerPlasticos (ePlasticos* listaPlasticos, int lenPlasticos, int id)
{
	ePlasticos ordenProcesada;

	if(listaPlasticos != NULL && lenPlasticos > 0)
	{
		for(int i = 0; i < lenPlasticos; i++)
		{
			if(listaPlasticos[i].isEmpty == FULL && listaPlasticos[i].idOrden == id)
			{
				ordenProcesada = listaPlasticos[i];
				break;
			}
		}
	}

	return ordenProcesada;
}

int deliverOrders (eOrden* listaOrdenes, int lenOrden, int id)
{
	int contadorPendientes;

	contadorPendientes = 0;

	if(listaOrdenes != NULL && lenOrden > 0)
	{
		for(int i = 0; i < lenOrden; i++)
		{
			if(listaOrdenes[i].isEmpty == FULL && listaOrdenes[i].idCliente == id && listaOrdenes[i].estado == PENDING)
			{
				contadorPendientes++;
			}
		}
	}

	return contadorPendientes;
}

int mostrarClientesOrdenesPendientes (eCliente* clientList, eOrden* ordersList ,eLocalidades* localitiesList, int clientsLen, int lenOrders, int localitiesLen) // 6
{
	int contadorPedidospPendientes;
	int state;
	eLocalidades auxLocalityId;

	state = -1;
	contadorPedidospPendientes = 0;

	if(clientList != NULL && ordersList != NULL && clientsLen > 0 && lenOrders > 0)
	{
		printf("\n \t\t  |ID Cliente|  Nombre de la compa�ia |          Cuit      |              Direccion    |         Localidad       |   PEDIDOS  |\n");
		printf(" \t\t  |__________|________________________|____________________|___________________________|_________________________|____________|\n");

		   for(int i = 0; i < clientsLen; i++)
		   {
			   if(clientList != NULL && clientList[i].isEmpty == FULL)
			   {
				   auxLocalityId = locObtenerPorId(localitiesList, localitiesLen, clientList[i].idLocalidad);
				   contadorPedidospPendientes = deliverOrders (ordersList, lenOrders, clientList[i].idCliente);

					printf("\t\t  | %5d    |    %15s     |    %15s  |%25s |  %18s     |  %5d     |\n",
					clientList[i].idCliente,
					clientList[i].nombreEmpresa,
					clientList[i].cuit,
					clientList[i].direccion,
					auxLocalityId.localidad,
					contadorPedidospPendientes);
			   }
		   }
		   contadorPedidospPendientes = 0;
	}

	return state;
}

int ordenPendienteClienteInfo (eCliente* clientList, eOrden* ordersList, int clientsLen, int lenOrders) // 7
{
	int state;
	eCliente auxClient;

	state = -1;

	if(clientList != NULL && ordersList != NULL && clientsLen > 0 && lenOrders > 0)
	{
		printf("\n\n\t\t\t\t\t\t\t|      Cuit     |        Direccion           |      Peso    |\n");
		printf("\t\t\t\t\t\t\t|_______________|____________________________|______________|\n");

		for(int i = 0; i < lenOrders; i++)
		{
			if(ordersList[i].estado == PENDING && ordersList[i].isEmpty == FULL)
			{
				auxClient = obtenerClientes(clientList, MAX, ordersList[i].idCliente);

				printf("\t\t\t\t\t\t\t| %10s |%24s    |     %5d    |\n",
				auxClient.cuit,
				auxClient.direccion,
				ordersList[i].pesoOrden);

				state = 0;
			}
		}
	}
	return state;
}

int mostrarOrdenCompletaPeso (eCliente* clientList, eOrden* ordersList, ePlasticos* plasticsList, int clientsLen, int ordersLen) // 8
{
	int state;
	ePlasticos auxPlastic;
	eCliente oneClient;

	state = -1;

	if(clientList != NULL && ordersList != NULL && clientsLen > 0 && ordersLen > 0)
	{
		printf("\n \t\t\t  |        Cuit     |         Direccion        | Cantidad HDPE | Cantidad LDPE | Cantidad PP   |Cantidad no reciclable|\n");
		printf(" \t\t\t  |_________________|__________________________|_______________|_______________|_______________|______________________|\n");

		for(int i = 0; i < ordersLen; i++)
		{
			if(ordersList[i].isEmpty == FULL)
			{
				oneClient = obtenerClientes(clientList, clientsLen, ordersList[i].idCliente);
				auxPlastic = traerPlasticos(plasticsList, ordersLen, ordersList[i].idOrden);

				if(oneClient.isEmpty == FULL && ordersList[i].estado == COMPLETED)
				{

					printf(" \t\t\t  |  %10s  | %23s  |    %5d      |    %5d      |    %5d      |       %5d          |\n" ,
					oneClient.cuit,
					oneClient.direccion,
					auxPlastic.HDPE,
					auxPlastic.LDPE,
					auxPlastic.PP,
					auxPlastic.basuraDesechable);
					state = 0;
				}
			}
		}
	}

	return state;
}

int ordenPendienteLocalidad (eLocalidades* localitiesList, eCliente* clientList, eOrden* ordersList, int clientsLen, int lenOrders, int* uniqueLocalityID) // 9
{
	int state;
	char locality[MAX];
	int ordersByLocalityCounter;
	int localityFoundId;

	ordersByLocalityCounter = 0;

	state = -1;

	if(clientList != NULL && ordersList != NULL && localitiesList != NULL && clientsLen > 0 && lenOrders > 0)
	{
		obtenerLocalidadValida("\n\t\t\t\t\t\tIngrese la localidad de donde quiere filtrar sus pedidos: ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de donde quiere filtrar sus pedidos) - ERROR : \n",
		locality);

		formatearChar(locality);

		localityFoundId = locBuscar(localitiesList, clientsLen, locality, uniqueLocalityID);

		if(localityFoundId != 0)
		{
			printf("\n\n\t\t\t\t\t\tLa localidad que has elegido para  filtar los pedidos es %s\n\n", locality);

			printf("\n\t\t\t\t\t\t\t\t   | Localidad | Pedidos Pendientes |\n");
			printf("\t\t\t\t\t\t\t\t   |___________|____________________|\n");

			for(int i = 0; i < clientsLen; i++)
			{
				if(clientList[i].isEmpty == FULL && clientList[i].idLocalidad == localityFoundId)
				{
					ordersByLocalityCounter+= deliverOrders(ordersList, lenOrders, clientList[i].idCliente);
				}
			}
			printf("\t\t\t\t\t\t\t\t   |%10s |       %5d        |\n",
			locality,
			ordersByLocalityCounter);

			state = 0;
		}
		else
		{
			printf("\nEsa localidad no existe, intente agregandola\n"
					"Volviendo al menu principal");

			return EXIT_SUCCESS;
		}
	}
	return state;
}

int promedioPPporCliente (eCliente* clientList, eOrden* ordersList,ePlasticos* plasticsList, int clientsLen, int ordersLen) // 10
{
	int state;
	int ppAverageResults;
	int i;

	i = 0;
	state = -1;

	if(clientList != NULL && ordersList != NULL && clientsLen > 0 && ordersLen > 0)
	{
		printf("\n\t\t\t\t\t\t\t\t| Nombre de Cliente | Promedio de PP reciclado |");
		printf("\n\t\t\t\t\t\t\t\t|___________________|__________________________|\n");

		for(i = 0; i < clientsLen; i++)
		{
			if(clientList[i].isEmpty == FULL)
			{
				ppAverageResults = cuentaClientesPorOrden(ordersList, plasticsList, ordersLen,clientList[i].idCliente);
				if(ppAverageResults > 0)
				{
					printf("\t\t\t\t\t\t\t\t|     %10s    |   %10d             |\n",
					clientList[i].nombreEmpresa,
					ppAverageResults);
				}
			}
		}

		state = 0;
	}


	return state;
}

int clienteMasOrdenes (eCliente* clientList, eLocalidades* localitiesList,eOrden* ordersList, int clientsLen, int ordersLen, int status) // 11 12 13
{
	int state;
	int posOfMostClient;
	int maxMostOrders;
	eLocalidades auxFoundLocalityId;

	state = -1;

	if(clientList != NULL && ordersList != NULL && clientsLen > 0 && ordersLen > 0)
	{
		for(int i = 0; i < clientsLen; i++)
		{
			state = buscaMayoriaOrdenes(ordersList, ordersLen, clientList[i].idCliente, status);

			if(i == 0 || maxMostOrders < state)
			{
				maxMostOrders = state;
				posOfMostClient = i;
				auxFoundLocalityId = locObtenerPorId(localitiesList, MAX, clientList[posOfMostClient].idLocalidad);
			}
		}
		printf("\n \t\t  |ID Cliente|  Nombre de la compa�ia |          Cuit      |              Direccion    |         Localidad       |   PEDIDOS  |\n");
		printf(" \t\t  |__________|________________________|____________________|___________________________|_________________________|____________|\n");

		printf("\t\t  | %5d    |    %15s     |    %15s  |%25s |  %18s     |  %5d     |\n",
		clientList[posOfMostClient].idCliente,
		clientList[posOfMostClient].nombreEmpresa,
		clientList[posOfMostClient].cuit,
		clientList[posOfMostClient].direccion,
		auxFoundLocalityId.localidad,
		maxMostOrders);
	}

	return state;
}

int plasticoRecicladoLocalidad(eCliente* clientList, eLocalidades* localitiesList,eOrden* ordersList, ePlasticos* plasticList, int clientsLen, int ordersLen, int* uniqueLocalityID)
{
	int state;
	char locality[MAX];
	int localityFoundId;

	state = -1;

	if(clientList != NULL && localitiesList != NULL
	&& ordersList != NULL && plasticList != NULL
	&& clientsLen > 0 && ordersLen > 0)
	{
		obtenerLocalidadValida("\n\t\t\t\t\t\tIngrese la localidad de donde quiere filtrar sus pedidos: ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de donde quiere filtrar sus pedidos) - ERROR : \n",
		locality);

		formatearChar(locality);

		localityFoundId = locBuscar(localitiesList, clientsLen, locality, uniqueLocalityID);

		if(localityFoundId != 0)
		{
			printf("\n\n\t\t\t\t\t\tLa localidad que has elegido para  filtar los pedidos es %s\n\n", locality);

			printf("\n \t|      Localidad     | Cantidad HDPE  |   Cantidad LDPE  | Cantidad PP | Cantidad no reciclable|\n");
			printf(" \t|____________________|________________|__________________|_____________|_______________________|\n");

			for(int i = 0; i < clientsLen; i++)
			{
				if(clientList[i].isEmpty == FULL && clientList[i].idLocalidad == localityFoundId)
				{
					imprimirPlasticoRecicladoLocalidad(clientList, localitiesList, ordersList, plasticList, clientsLen, ordersLen, locality, clientList[i].idCliente);
					state = 0;
				}
			}
		}
	}
	return state;
}

int imprimirPlasticoRecicladoLocalidad(eCliente* clientList, eLocalidades* localitiesList,eOrden* ordersList, ePlasticos* plasticList, int clientsLen, int ordersLen, char locality[], int id)
{
	int state;
	ePlasticos auxPlastic;
	int ppAcumulator;
	int LDPEAcumulator;
	int HDPEAcumulator;
	int thrashAcumulator;

	ppAcumulator = 0;
	LDPEAcumulator = 0;
	HDPEAcumulator = 0;
	thrashAcumulator = 0;

	state = -1;

	for(int i = 0; i < ordersLen; i++)
	{
		if(ordersList[i].idCliente == id && ordersList[i].estado == COMPLETED)
		{
			auxPlastic = traerPlasticos(plasticList, ordersLen, ordersList[i].idOrden); /// PK

			if(auxPlastic.isEmpty == FULL)
			{
				ppAcumulator += auxPlastic.PP;
				LDPEAcumulator +=auxPlastic.LDPE;
				HDPEAcumulator += auxPlastic.HDPE;
				thrashAcumulator += auxPlastic.basuraDesechable;
				state = 0;
			}
		}
	}

		printf(" \t|%12s        |      %5d     |    %5d         |   %5d     |      %5d            |\n" ,
		locality,
		HDPEAcumulator,
		LDPEAcumulator,
		ppAcumulator,
		thrashAcumulator);

	return state;
}



int imprimeClientePorLocalidad(eCliente clientList, eLocalidades* localitiesList, int clientsLen, int localitiesLen)
{
	int state;
	eLocalidades auxFoundLocalityId;

	state = -1;

	if(localitiesList != NULL && clientsLen > 0 && localitiesLen > 0)
	{
		auxFoundLocalityId = locObtenerPorId(localitiesList, localitiesLen, clientList.idLocalidad);

		printf("\t\t\t\t  | %5d    |    %15s     |    %15s  |%25s |  %18s      |\n",
		clientList.idCliente,
		clientList.nombreEmpresa,
		clientList.cuit,
		clientList.direccion,
		auxFoundLocalityId.localidad);
	}

	return state;
}

int imprimirListaClientesLocalidades(eCliente* clientList, eLocalidades* localitiesList, int clientsLen, int localitiesLen)
{
	int state;

	state = -1;

	if(localitiesList != NULL && clientsLen > 0 && localitiesLen > 0)
	{
		printf("\n \t\t\t\t  |ID Cliente|  Nombre de la compa�ia |          Cuit       |              Direccion    |         Localidad       |\n");
		printf(" \t\t\t\t  |__________|________________________|_____________________|___________________________|_________________________|\n");
		for(int i = 0; i < clientsLen; i++)
		{
			if(clientList[i].isEmpty == FULL)
			{
				imprimeClientePorLocalidad(clientList[i], localitiesList, clientsLen, localitiesLen);
			}
		}

		state = 0;
	}

	return state;
}

int ppAcumulador (ePlasticos* plasticList,int lenPlastic, int id)
{
	int ppAcumulator;

	ppAcumulator = 0;

	if(plasticList != NULL && lenPlastic > 0)
	{
		for(int i = 0; i < lenPlastic; i++)
		{
			if(plasticList[i].isEmpty == FULL && plasticList[i].idOrden == id)
			{
				ppAcumulator = ppAcumulator + plasticList[i].PP;
			}
		}
	}

	return ppAcumulator;
}

int cuentaClientesPorOrden (eOrden* ordersList, ePlasticos* plasticsList,int ordersLen, int id)
{
	int clientsCounter;
	int ppAverageResults;
	int acumulatorReturn;

	clientsCounter = 0;
	acumulatorReturn = 0;
	ppAverageResults = 0;

	if(ordersList != NULL && ordersLen > 0)
	{
		for(int i = 0; i < ordersLen; i++)
		{
			if(ordersList[i].isEmpty == FULL && ordersList[i].estado == COMPLETED
			&& ordersList[i].idCliente == id)
			{
				acumulatorReturn += ppAcumulador(plasticsList, ordersLen, ordersList[i].idOrden);
				clientsCounter++;

			}
		}
		if(clientsCounter > 0)
		{
			ppAverageResults = acumulatorReturn / clientsCounter;
		}
	}

	return ppAverageResults;
}

int buscaMayoriaOrdenes (eOrden* ordersList, int ordersLen, int id, int status)
{
	int contadorPendingOrders;

	contadorPendingOrders = 0;

	if(ordersList != NULL && ordersLen > 0)
	{
		for(int i = 0; i < ordersLen; i++)
		{
			if((status == 0 || status == 1) && ordersList[i].isEmpty == FULL && ordersList[i].idCliente == id && ordersList[i].estado == status)
			{
				contadorPendingOrders++;
			}
			else
			{
				if(status == 2 && ordersList[i].isEmpty == FULL && ordersList[i].idCliente == id)
				{
					contadorPendingOrders++;
				}
			}
		}

	}
	return contadorPendingOrders;
}
