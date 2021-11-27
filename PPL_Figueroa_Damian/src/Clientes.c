//Author: Figueroa Damian

#include "Clientes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Nexo.h"

/// @fn int initClients(eClients*, int)
/// @brief Inicia el array de clientes en empty.
///
/// @param clientList
/// @param len
/// @return -1 si no se logro, 0 si se pudo.
int inicializaClientes (eCliente* clientList, int len)
{
	int state = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			clientList[i].isEmpty = EMPTY;
		}
	}
	return state;
}

/// @fn int freeClientSpot(eClients*, int)
/// @brief Busca lugar libre para un nuevo cliente.
///
/// @param clientList
/// @param len
/// @return devuelve -1 si no se pudo conseguir, o la posicion libre.
int espacioNuevoCliente (eCliente* clientList, int len)
{
	int position;

	position = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(clientList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}

/// @fn int newClient(eClients*, sLocality*, int, int*, int*)
/// @brief Pide y valida los datos para la creación de un nuevo cliente.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param uniqueID
/// @param uniqueLocalityID
/// @return -1 si no se logro, 0 si se pudo.
int nuevoCliente (eCliente* clientList, eLocalidades* localitiesList, int len, int* uniqueID, int* uniqueLocalityID)
{
	int state;
	eCliente newClient;
	char auxLocality[MAX];
	int auxIdlocality;

	state = -1;
	*uniqueID = *uniqueID+1;

	if(clientList != NULL && localitiesList != NULL && len > 0)
	{
		validaString("\n\t\t\t\t\t\t\tIngrese el nombre de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese el nombre de su compañia) - ERROR : \n", newClient.companyName);
		validaString("\n\t\t\t\t\t\t       Ingrese el cuit de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese el cuit de su compañia) - ERROR : \n", newClient.cuit);
		pideDireccion("\n\t\t\t\t\t\t    Ingrese la direccion de su compañia :) : ", newClient.adress);
		locImprimeLista(localitiesList, MAX);
		getValidLocality("\n\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
		auxLocality);

		formatearChar(auxLocality);

		auxIdlocality = locBuscar(localitiesList, MAX, auxLocality, uniqueLocalityID);

		if(auxIdlocality != 0)
		{
			newClient.localityId = auxIdlocality;
			printf("\n\n\t\t\t\t\t\t Localidad asignada correctamente");
		}
		else
		{
			printf("\n\n\t\t\t\t\t\tNo existe esa localidad vuelva al menu y creela");
			return EXIT_SUCCESS;
		}

		newClient.clientId = *uniqueID;
		state = 0;

		agregarCliente(clientList, len, newClient.companyName, newClient.cuit, newClient.adress, newClient.localityId, newClient.clientId);
	}

	return state;
}

/// @fn int addClient(eClients*, int, char[], char[], char[], int, int)
/// @brief Alta de cliente, obtiene una posision libre y carga todos los datos de los parametros en esa posicion.
///
/// @param clientList
/// @param len
/// @param companyName
/// @param cuit
/// @param adress
/// @param localityId
/// @param id
/// @return devuelve 1 si se pudo crear.
int agregarCliente (eCliente* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id)
{
	int pos;

	if(clientList != NULL && len > 0)
	{
		pos = espacioNuevoCliente(clientList, len);

		strcpy(clientList[pos].companyName, companyName);
		strcpy(clientList[pos].cuit, cuit);
		strcpy(clientList[pos].adress, adress);
		clientList[pos].localityId = localityId;
		clientList[pos].clientId = id;
		clientList[pos].isEmpty = FULL;
	}

	return 1;
}

/// @fn int idAsk(eClients*, sLocality*, int)
/// @brief Pide un id mostrando la lista de clientes existentes.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @return La posicion para usar.
int pedirID(eCliente* clientList, eLocalidades* localitiesList, int len)
{
	int enteredIdToRemove;
	int positionToUse;

	if(clientList != NULL && len > 0)
	{
		CLI_printClientsListWithLocalities(clientList, localitiesList, 100, 100);

		enteredIdToRemove = obtieneEnteroValido("\n\n\t\t\t\t\t\t\tDespues de haber visto la lista de los Id's disponibles, cual desea elegir?",
				"\n\n\t\t\t\t\tERROR - (El id ingresado no existe  intentelo nuevamente) - ERROR", 1, 100);

		positionToUse = validaID(clientList, localitiesList, len, enteredIdToRemove);
	}

	return positionToUse;
}

/// @fn int idValidation(eClients*, sLocality*, int, int)
/// @brief Se fija si la posicion recibida por parametros existe.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param enteredId
/// @return -1 si no existe, la posicion si existe.
int validaID (eCliente* clientList, eLocalidades* localitiesList, int len, int enteredId)
{
	int pos;

	pos = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(enteredId == clientList[i].clientId && clientList[i].isEmpty == FULL)
			{
				pos = i;
				break;
			}
		}
		if(pos == -1)
		{
			printf("\t\t\t\t\tLamentamos informale que ese id no existe");
			pedirID(clientList, localitiesList, len);
		}
	}
	return pos;
}

/// @fn int modifyClient(eClients*, sLocality*, int, int*)
/// @brief Pide ingresar el id de el cliente que quiere modificar y permite cambia dirección y localidad.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param uniqueLocalityID
/// @return devuelve 1 si pudo hacerlo satisfactoriamente.
int modificaCliente (eCliente* clientList, eLocalidades* localitiesList, int len, int* uniqueLocalityID)
{
	int positionToUse;
	int option;
	char auxLocality[MAX];
	int newLocalityId;

	if(clientList != NULL && len > 0)
	{
		positionToUse = pedirID(clientList, localitiesList, len);

		 option = obtieneEnteroValido("\n\n\t\t\tIngrese la opcion que desea llevar a cabo para modificar { 1 - Direccion - 2 - Localidad }: ",
				 "\n\n\t\t\tERROR - (That option to modify doesn't exist try again) - ERROR",1,2);
		switch(option)
		{
			case 1:
				pideDireccion("\n\t\t\t\t\t\t\t\t\tIngrese la direccion de su compañia: ", clientList[positionToUse].adress);
			break;
			case 2:
				locImprimeLista(localitiesList, MAX);
				getValidLocality("\n\t\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
						"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
						auxLocality);

						formatearChar(auxLocality);

						newLocalityId = locBuscar(localitiesList, MAX, auxLocality, uniqueLocalityID);

						if(newLocalityId != 0)
						{
							clientList[positionToUse].localityId = newLocalityId;
						}
						else
						{
							printf("\n\n\t\t\t\t\tNo existe esa localidad vuelva al menu y creela");
							return EXIT_SUCCESS;
						}
			break;
		}
	}
	return 1;
}

/// @fn int withdrawalClient(eClients*, sLocality*, int)
/// @brief Da de baja logica un cliente.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @return devuelve -1 si no se pudo dar de baja, 0 si se pudo dar de baja.
int bajaCliente (eCliente* clientList, eLocalidades* localitiesList, int len)
{
	int state;
	int positionToUse;

	state = -1;

	if(clientList != NULL && len > 0)
	{
		positionToUse = pedirID(clientList, localitiesList, len);

			if(clientList[positionToUse].isEmpty == FULL)
			{
				clientList[positionToUse].isEmpty = EMPTY; /// Baja logica
				 state = 0;
			}
	}

	return state;
}

/// @fn int showOneClient(eClients)
/// @brief muestra un cliente.
///
/// @param clientList
/// @return -1 si no se logro, 0 si se pudo.
int mostrarCliente (eCliente clientList)
{
	int state;

	state = -1;

		printf("\t\t\t\t\t %10d | %10s | %10s | %10s | %10d |\n",
		clientList.clientId,
		clientList.companyName,
		clientList.cuit,
		clientList.adress,
		clientList.localityId);

		state = 0;

	return state;
}

/// @fn int showListOfClients(eClients*, int)
/// @brief muestra la lista de clientes existentes si es que existen.
///
/// @param clientList
/// @param len
/// @return -1 si no se logro, 0 si se pudo.
int mostrarListaClientes (eCliente* clientList, int len)
{
	int state;

	state = -1;

	if(clientList != NULL && len > 0)
	{
		printf("\n\t\t\t\t\t|ID Cliente |  Nombre de la compañia | Cuit | Direccion | Localidad|PEDIDOS|\n");
		printf("\t\t\t\t\t|____________|_____________|______________|______|______________|________|\n");

		for(int i = 0; i < len; i++)
		{
			if(clientList[i].isEmpty == FULL)
			{
				mostrarCliente(clientList[i]);
				state = 0;
			}
		}
	}

	return state;
}

eCliente clientePorID(eCliente* clientList, int clientsLen, int id)
{
	eCliente foundClientId;

	if(clientList != NULL && clientsLen > 0)
	{
		for(int i = 0; i < clientsLen; i++)
		{
			if(clientList[i].isEmpty == FULL
			&& clientList[i].localityId == id)
			{
				foundClientId = clientList[i];
				break;
			}
		}
	}
	return foundClientId;
}

int crearClientesRandom(eCliente* clientList ,int clientsLen,int *uniqueID)
{
	int state;

	state = -1;

	if(clientList != NULL && clientsLen > 0)
	{
		char companyName [][MAX] =  {
		"Coca Cola", "Aguas Beyse", "Ivess","Avalos e Hijos",
		"El Noble", "Termolab","San Patricia", "Pepsico",
		"La Chancha", "Aguas German", "Don Mariano",
		"Gianni el Noble"};

		char cuit [][MAX] = {
				"20-25789963-6", "27-32654787-9",
				"27-42512245-0", "20-45412573-6",
				"21-48512245-6", "27-43212245-0",
				"27-23512245-0", "22-25753854-8",
				"20-25789963-6", "26-25789963-1",
				"27-42512245-0", "20-45412573-6"};

		char adress [][MAX] = {"Ricardo Fort 234", "Argelia 4588",
				"Andres Baranda 582", "Estrada 1258", "Zeballos 3030",
				"V.Ocampo 254", "Madariaga 854", "Carlos Calvo 3334"
				,"Av. Rivadavia 1999", "Scarafilo Escaloneta 44",
				"Presidente Peron 854", "Av. 9 de Julio 854"};

		int idLocalidades[]={1,2,3,4,5,6,4,5,8,9,6,4,2,15,12,20,25,10};

		for (int i = 0; i < 12; i++)
		{
			if(clientList[i].isEmpty == EMPTY)
			{
				strcpy((clientList + i)->companyName, *(companyName + i));
				(clientList + i)->localityId = *(idLocalidades +i);
				(clientList + i)->clientId = *uniqueID = *uniqueID+1;
				strcpy((clientList + i)->cuit , *(cuit +i));
				strcpy((clientList + i)->adress , *(adress +i));
				(clientList + i)->isEmpty = FULL;
			}
		}
	}
	return state;
}
