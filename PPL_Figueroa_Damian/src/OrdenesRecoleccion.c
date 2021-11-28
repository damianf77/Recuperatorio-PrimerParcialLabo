//Author: Figueroa Damian

#include "OrdenesRecoleccion.h"

#include "Nexo.h"


int iniciarOrden (eOrden* ordersList, int len)
{
	int estado = -1;

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			ordersList[i].isEmpty = EMPTY;
		}
	}
	return estado;
}

int espacioLibreOrden (eOrden* ordersList, int len)
{
	int posicion;

	posicion = -1;

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(ordersList[i].isEmpty == EMPTY)
			{
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}

int nuevaOrden (eCliente* clientList, eOrden* ordersList, eLocalidades* localitiesList, int len, int* uniqueOrderID) //
{
	eOrden nuevaOrden;
	int posicion;

	if(ordersList != NULL && clientList != NULL && len > 0)
	{
		*uniqueOrderID = *uniqueOrderID+1;

		posicion = pedirID(clientList, localitiesList, len);
		nuevaOrden.idCliente = clientList[posicion].idCliente; /// FK
		nuevaOrden.pesoOrden = obtieneEnteroValido("\t\t\t\t\t\t\tIngrese el peso del pedido de recoleccion que desea crear: ",
				"\t\t\t\t\t\tERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR ", 100, 100000);
		nuevaOrden.idOrden = *uniqueOrderID;
		nuevaOrden.estado = PENDING;

		agregarOrden(ordersList,len,nuevaOrden.idCliente,nuevaOrden.pesoOrden,nuevaOrden.idOrden,nuevaOrden.estado); ///
	}

	return 1;
}

int agregarOrden (eOrden* ordersList, int len, int clientId , int orderWeight, int orderId, int status) //
{
	int posicion;

	if(ordersList != NULL && len > 0)
	{
		posicion = espacioLibreOrden(ordersList, len);

		ordersList[posicion].idCliente = clientId;
		ordersList[posicion].pesoOrden = orderWeight;
		ordersList[posicion].idOrden = orderId;
		ordersList[posicion].estado = PENDING;
		ordersList[posicion].isEmpty = FULL;
	}
	return 1;
}

int mostrarOrden (eOrden listaOrdenes)
{
	int estado;

	estado = -1;

		printf(" %10d | %10d | %d | %d |\n",
		listaOrdenes.idOrden,
		listaOrdenes.pesoOrden,
		listaOrdenes.estado,
		listaOrdenes.isEmpty);

		estado = 0;

	return estado;
}

int mostarListaOrdenes (eOrden* listaOrdenes, int len)
{
	int estado;

	estado = -1;

	if(listaOrdenes != NULL && len > 0)
	{
		printf("\n|ID Orden | Peso| Status | IsEmpty |\n");
		printf("|____________|_____________|______________|______|\n");

		if(listaOrdenes != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(listaOrdenes[i].isEmpty == FULL)
				{
					mostrarOrden(listaOrdenes[i]);
				}
			}
		}
	}

	return estado;
}

int arrayChargeOrders (eOrden* listaOrdenes, eCliente* listaClientes, int len, int* ordenID) ///
{
	int peso;
	int estado;
	int pos;
	peso = 1333;

	if(listaOrdenes != NULL && listaClientes != NULL && len > 0)
	{
		for(int i = 0; i < 12; i ++)
		{
			*ordenID = *ordenID+1;

			pos = espacioLibreOrden(listaOrdenes, len);
			listaOrdenes[pos].idOrden = *ordenID;
			listaOrdenes[pos].pesoOrden = peso+=33;
			listaOrdenes[pos].idCliente = listaClientes[i].idCliente;
			estado = PENDING;
			listaOrdenes[pos].estado = estado;
			listaOrdenes[pos].isEmpty = FULL;
		}
	}

	return 1;
}

int idOrdenPedido(eCliente* listaClientes, eOrden* listaOrdenes, int lenClientes, int lenOrdenes) ///
{
	int idIngresado;
	int posicion;
	eCliente unCliente;

	if(listaOrdenes != NULL && listaClientes != NULL && lenOrdenes > 0)
	{
		printf("\n\t\t\t\t\t\t\t|  ID Orden  |    Peso     |  Client ID   |   Estado     |\n");
		printf("\t\t\t\t\t\t\t|____________|_____________|______________|______________|\n");

		for(int i = 0; i < lenOrdenes; i++)
		{
			if(listaOrdenes[i].isEmpty == FULL && listaOrdenes[i].estado == PENDING)
			{
				unCliente = obtenerClientes(listaClientes, lenClientes, listaOrdenes[i].idCliente);

				printf("\t\t\t\t\t\t\t| %10d | %10d  | %10d   | %10d   |\n",
				listaOrdenes[i].idOrden,
				listaOrdenes[i].pesoOrden,
				unCliente.idCliente,
				listaOrdenes[i].estado);
			}
		}

		idIngresado = obtieneEnteroValido("\n\n\t\t\t\t\tDespues de haber visto la lista de los Id's de los clientes disponibles, a cual desea procesar?",
		"\n\n\t\t\t\t\tERROR - (Has ingresado un ID no existente intentelo nuevamente) - ERROR", 1, 100);

		posicion = validaOrden (listaOrdenes, lenOrdenes, idIngresado);
	}

	return posicion;
}

int pedirId(eOrden* listaOrdenes, int len)
{
	int idIngresado;
	int posicion;

	if(listaOrdenes != NULL && len > 0)
	{
		mostarListaOrdenes(listaOrdenes, len);

		idIngresado = obtieneEnteroValido("Despues de haber visto la lista de los Id's de los clientes disponibles, a cual desea crearle un pedido?",
				"ERROR - (Has ingresado un ID no existente intentelo nuevamente) - ERROR", 1, 100);

		posicion = validaOrden (listaOrdenes, len, idIngresado);
	}

	return posicion;
}

int validaOrden (eOrden* ordersList, int len, int enteredId)
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
			pedirId(ordersList, len);
		}
	}

	return pos;
}

int procesaOrden (eCliente* listaClientes, eOrden* listaOrdenes, ePlasticos* listaPlasticos, int lenClientes, int lenOrdenes) //
{
	int estado;
	int posicion;
	int pesoOrden;
	int estadoProceso;

	estado = -1;

	if(listaClientes != NULL && listaOrdenes != NULL && lenClientes > 0 && lenOrdenes > 0)
	{
		posicion = idOrdenPedido(listaClientes, listaOrdenes, 100, 1000);

		pesoOrden = listaOrdenes[posicion].pesoOrden;

		estadoProceso	= PLA_processPlastics(listaPlasticos, lenOrdenes, listaOrdenes[posicion].idOrden, pesoOrden);

		if(estadoProceso == 0)
		{
			listaOrdenes[posicion].estado = COMPLETED;
			estado = 0;
		}
		else
		{
			printf("No se pudo procesar el pedido correctamente volviendo al menu!");
			return EXIT_SUCCESS;
		}
	}

	return estado;
}


