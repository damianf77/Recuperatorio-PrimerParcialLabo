//Author: Figueroa Damian

#include "Clientes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Nexo.h"

// brief: Inicia el array de clientes

int inicializaClientes (eCliente* listaCliente, int len)
{
	int state = -1;

	if(listaCliente != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			listaCliente[i].isEmpty = EMPTY;
		}
	}
	return state;
}


/// @brief Busca espacio libre para un nuevo cliente.
/// @return devuelve -1 si encontro, o posicion libre.

int espacioNuevoCliente (eCliente* listaClientes, int len)
{
	int position;

	position = -1;

	if(listaClientes != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(listaClientes[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}


// @brief Pide y valida los datos para la creación de un nuevo cliente.
// @return -1 si falla, 0 si termina bien.
int nuevoCliente (eCliente* listaClientes, eLocalidades* listaLocalidades, int len, int* uniqueID, int* idLocalidad)
{
	int estado;
	eCliente nuevoCliente;
	char localidadAux[MAX];
	int idLocalidadAux;

	estado = -1;
	*uniqueID = *uniqueID+1;

	if(listaClientes != NULL && listaLocalidades != NULL && len > 0)
	{
		validaString("\n\t\t\t\t\t\t\tIngrese el nombre de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese el nombre de su compañia) - ERROR : \n", nuevoCliente.nombreEmpresa);
		validaString("\n\t\t\t\t\t\t       Ingrese el cuit de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese el cuit de su compañia) - ERROR : \n", nuevoCliente.cuit);
		pideDireccion("\n\t\t\t\t\t\t    Ingrese la direccion de su compañia :) : ", nuevoCliente.direccion);
		locImprimeLista(listaLocalidades, MAX);
		obtenerLocalidadValida("\n\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
		localidadAux);

		formatearChar(localidadAux);

		idLocalidadAux = locBuscar(listaLocalidades, MAX, localidadAux, idLocalidad);

		if(idLocalidadAux != 0)
		{
			nuevoCliente.idLocalidad = idLocalidadAux;
			printf("\n\n\t\t\t\t\t\t Localidad asignada correctamente");
		}
		else
		{
			printf("\n\n\t\t\t\t\t\tNo existe esa localidad vuelva al menu y creela");
			return EXIT_SUCCESS;
		}

		nuevoCliente.idCliente = *uniqueID;
		estado = 0;

		agregarCliente(listaClientes, len, nuevoCliente.nombreEmpresa, nuevoCliente.cuit, nuevoCliente.direccion, nuevoCliente.idLocalidad, nuevoCliente.idCliente);
	}

	return estado;
}

// @brief Obtiene una posision libre y carga todos los datos en esa posicion.
// @return devuelve 1 si es correcto.
int agregarCliente (eCliente* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id)
{
	int pos;

	if(clientList != NULL && len > 0)
	{
		pos = espacioNuevoCliente(clientList, len);

		strcpy(clientList[pos].nombreEmpresa, companyName);
		strcpy(clientList[pos].cuit, cuit);
		strcpy(clientList[pos].direccion, adress);
		clientList[pos].idLocalidad = localityId;
		clientList[pos].idCliente = id;
		clientList[pos].isEmpty = FULL;
	}

	return 1;
}

// @brief Pide un id mostrando la lista de clientes existentes.
// @return La posicion.
int pedirID(eCliente* clientList, eLocalidades* localitiesList, int len)
{
	int enteredIdToRemove;
	int positionToUse;

	if(clientList != NULL && len > 0)
	{
		imprimirListaClientesLocalidades(clientList, localitiesList, 100, 100);

		enteredIdToRemove = obtieneEnteroValido("\n\n\t\t\t\t\t\t\tDespues de haber visto la lista de los Id's disponibles, cual desea elegir?",
				"\n\n\t\t\t\t\tERROR - (El id ingresado no existe  intentelo nuevamente) - ERROR", 1, 100);

		positionToUse = validaID(clientList, localitiesList, len, enteredIdToRemove);
	}

	return positionToUse;
}

// @brief Se fija si la posicion recibida por parametros existe.
// @return -1 si no existe, la posicion si existe.
int validaID (eCliente* clientList, eLocalidades* localitiesList, int len, int enteredId)
{
	int pos;

	pos = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(enteredId == clientList[i].idCliente && clientList[i].isEmpty == FULL)
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

// @brief Pide ingresar el id de el cliente que quiere modificar y permite cambia dirección y localidad.
// @return devuelve 1 si pudo hacerlo satisfactoriamente.
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
				pideDireccion("\n\t\t\t\t\t\t\t\t\tIngrese la direccion de su compañia: ", clientList[positionToUse].direccion);
			break;
			case 2:
				locImprimeLista(localitiesList, MAX);
				obtenerLocalidadValida("\n\t\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
						"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
						auxLocality);

						formatearChar(auxLocality);

						newLocalityId = locBuscar(localitiesList, MAX, auxLocality, uniqueLocalityID);

						if(newLocalityId != 0)
						{
							clientList[positionToUse].idLocalidad = newLocalityId;
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

// @brief Da de baja logica un cliente.
// @return devuelve -1 si no se pudo dar de baja, 0 si se pudo dar de baja.
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

// @brief muestra un cliente.
// @return -1 si no se logro, 0 si se pudo.
int mostrarCliente (eCliente clientList)
{
	int state;

	state = -1;

		printf("\t\t\t\t\t %10d | %10s | %10s | %10s | %10d |\n",
		clientList.idCliente,
		clientList.nombreEmpresa,
		clientList.cuit,
		clientList.direccion,
		clientList.idLocalidad);

		state = 0;

	return state;
}

// @brief muestra la lista de clientes existentes si es que existen.
// @return -1 si no se logro, 0 si se pudo.
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
			&& clientList[i].idLocalidad == id)
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
				strcpy((clientList + i)->nombreEmpresa, *(companyName + i));
				(clientList + i)->idLocalidad = *(idLocalidades +i);
				(clientList + i)->idCliente = *uniqueID = *uniqueID+1;
				strcpy((clientList + i)->cuit , *(cuit +i));
				strcpy((clientList + i)->direccion , *(adress +i));
				(clientList + i)->isEmpty = FULL;
			}
		}
	}
	return state;
}
