//Author: Figueroa Damian

#include "Localidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int harcodeaLocalidades (eLocalidades* listaDeLocalidades, int len, int* idLocalidades)
{
	int estado;
	estado = -1;

	if(listaDeLocalidades != NULL && len > 0)
	{
		char localidades[][MAX] = { "Abasto", "Agronomía", "Almagro",
		"Balvanera", "Barracas", "Barrio Norte", "Belgrano", "Boedo", "Caballito", "Capital Federal", "Chacarita", "Coghlan",
		"Colegiales", "Constitución", "Flores", "Floresta", "La Boca", "Liniers", "Mataderos", "Microcentro", "Monte Castro",
		"Montserrat","Nueva Pompeya", "Núñez"};

		for (int i = 0; i < 12; i++)
		{
			if(listaDeLocalidades[i].isEmpty == EMPTY)
			{
				strcpy((listaDeLocalidades + i)->localidad, *(localidades + i));
				(listaDeLocalidades + i)->idLocalidad = *idLocalidades = *idLocalidades+1;
				(listaDeLocalidades + i)->isEmpty = FULL;
			}
		}
	}

	return estado;
}

int inicializaLocalidades (eLocalidades* listaLocalidades, int lenLocalidades) ///
{
	int estado = -1;

	if(listaLocalidades != NULL && lenLocalidades > 0)
	{
		for(int i = 0; i < lenLocalidades; i++)
		{
			listaLocalidades[i].isEmpty = EMPTY;
		}
	}

	return estado;
}

int nuevaLocalidad(eLocalidades* listaLocalidades, int lenLocalidades, int* idLocalidades) //
{
	eLocalidades nuevaLocalidad;
	int estado;
	int aux;

	estado = -1;

	if(listaLocalidades != NULL && lenLocalidades > 0)
	{
		obtenerLocalidadValida("\n\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
		nuevaLocalidad.localidad);

		formatearChar(nuevaLocalidad.localidad);

		aux = locBuscar(listaLocalidades, lenLocalidades, nuevaLocalidad.localidad, idLocalidades);

		if(aux == 0)
		{
			*idLocalidades = *idLocalidades+1;

			cargaListaLocalidades(listaLocalidades, idLocalidades, MAX, nuevaLocalidad.localidad);

			printf("\n\t\t\t\t\t\t\t  Se agregó satisfactoriamente una nueva localidad!");
		}
		else
		{
			nuevaLocalidad.idLocalidad = *idLocalidades;
			printf("\n\t\t\t\t\t\t\t Esa localidad ya existe, intente creando una nueva!");
		}

		estado = 0;
	}

	return estado;
}

int cargaListaLocalidades(eLocalidades* localitiesList, int* uniqueLocalityID, int localitiesLen, char auxLocality []) //
{
	int state;

	state = -1;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		for(int i = 0; i < localitiesLen; i++)
		{
			if(localitiesList[i].isEmpty == EMPTY)
			{
				localitiesList[i].idLocalidad = *uniqueLocalityID;
				strcpy(localitiesList[i].localidad, auxLocality);
				localitiesList[i].isEmpty = FULL;
				break;
			}
		}
	}

	return state;
}


int borraLocalidad (eLocalidades* localitiesList, int localitiesLen) //
{
	int state;
	int positionToUse;

	state = -1;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		positionToUse = locPideId(localitiesList, localitiesLen);

		if(localitiesList[positionToUse].isEmpty == FULL)
		{
			localitiesList[positionToUse].isEmpty = EMPTY;
		}

	}
	return state;
}


int locLugarLibre (eLocalidades* localitiesList, int localitiesLen)
{
	int position;

	position = -1;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		for(int i = 0; i < localitiesLen; i++)
		{
			if(localitiesList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}

int locBuscar (eLocalidades* localitiesList, int localitiesLen, char auxLocality [], int* uniqueLocalityID)
{
	int foundId;

	foundId = 0;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		for(int i = 0; i < localitiesLen; i++)
		{
			if(strcmp(localitiesList[i].localidad, auxLocality) == 0)
			{
				foundId = localitiesList[i].idLocalidad;
			}
		}
	}
	return foundId;
}


int locImprimeLista(eLocalidades* localitiesList, int localitiesLen)
{
	int state;

	state = -1;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		printf("\n\t\t\t\t\t\t\t\t      |   Localidad  |  ID de Localidad |\n");
		printf("\t\t\t\t\t\t\t\t      |______________|__________________|\n");

		for(int i = 0; i < localitiesLen; i++)
		{
			if(localitiesList[i].isEmpty == FULL)
			{
				locImprimeLocalidad(localitiesList[i]);
			}
		}
	}

	return state;
}

int locImprimeLocalidad(eLocalidades localitiesList)
{
	int state;
	state = -1;

		printf("\t\t\t\t\t\t\t\t    %15s     -     %3d\n",
		localitiesList.localidad,
		localitiesList.idLocalidad);

		state = 0;

	return state;
}
int locPideId(eLocalidades* localitiesList, int localitiesLen)
{
	int enteredIdToRemove;
	int positionToUse;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		locImprimeLista(localitiesList, localitiesLen);

		enteredIdToRemove = obtieneEnteroValido("\n\n\t\t\t\t\tDespues de haber visto la lista de los Id's de las localidades existentes, cual desea eliminar?",
				"\n\n\t\t\t\t\tERROR - (El id ingresado no existe intentelo nuevamente) - ERROR", 1, 100);

		positionToUse = locValidaId(localitiesList, localitiesLen, enteredIdToRemove);
	}

	return positionToUse;
}

int locValidaId (eLocalidades* localitiesList, int localitiesLen, int enteredId) ///
{
	int pos;

	pos = -1;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		for(int i = 0; i < localitiesLen; i++)
		{
			if(enteredId == localitiesList[i].idLocalidad && localitiesList[i].isEmpty == FULL)
			{
				pos = i;
				break;
			}
		}
		if(pos == -1)
		{
			printf("\t\t\t\t\t\tLamentamos informale que ese id no existe reintente");
			locPideId(localitiesList,localitiesLen);
		}
	}
	return pos;
}

eLocalidades locObtenerPorId(eLocalidades* listaLocalidades, int lenLocalidades, int id)
{
	eLocalidades idLocalidadEncontrado;

	if(listaLocalidades != NULL && lenLocalidades > 0)
	{
		for(int i = 0; i < lenLocalidades; i++)
		{
			if(listaLocalidades[i].isEmpty == FULL
			&& listaLocalidades[i].idLocalidad == id)
			{
				idLocalidadEncontrado = listaLocalidades[i];
				break;
			}
		}
	}

	return idLocalidadEncontrado;
}

