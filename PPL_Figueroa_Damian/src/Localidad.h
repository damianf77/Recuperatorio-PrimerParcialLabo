//Author: Figueroa Damian

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include "FuncionesFigueroa.h"
#define FULL 0
#define EMPTY 1

struct
{
	char localidad[MAX];
	int idLocalidad;
	int isEmpty;

}typedef eLocalidades;

//brief Inicia el vector de localidades en EMPTY.
//return 0 si pudo -1 si no pudo.
int inicializaLocalidades (eLocalidades* localitiesList, int localitiesLen);

//brief Harcodea localidades
//return0 si pudo -1 si no pudo.
int harcodeaLocalidades (eLocalidades* localitiesList, int len, int* uniqueLocalityID);

//brief Busca un lugar libre en el vector para crear una nueva localidad.
//return 0 si pudo -1 si no pudo.
int locLugarLibre (eLocalidades* localitiesList, int localitiesLen);

//brief Pide todos los datos para una nueva localidad y se los pasa LOC_chargeLocalitiesList
//return 0 si pudo -1 si no pudo.
int nuevaLocalidad(eLocalidades* localitiesList, int len, int* uniqueLocalityID);

//brief Da de baja logica una localidad.
//return 0 si pudo -1 si no pudo.
int borraLocalidad (eLocalidades* localitiesList, int localitiesLen);

//brief Pide un id para dar de baja una localidad.
//return La posicion si existe o -1 si no existe.
int locPideId(eLocalidades* localitiesList, int localitiesLen);

//brief Valida si existe un id para dar de baja una localidad.
//return La posicion si existe o -1 si no existe.
int locValidaId (eLocalidades* localitiesList, int localitiesLen, int enteredId);

//brief Alta de nueva localidad
//return 0 si la pudo crear o -1 si no pudo crearla.
int cargaListaLocalidades(eLocalidades* localitiesList, int* uniqueLocalityID, int localitiesLen, char auxLocality []);
int locBuscar (eLocalidades* localitiesList, int localitiesLen, char auxLocality [], int* uniqueLocalityID);
int locImprimeLocalidad(eLocalidades localitiesList);
int locImprimeLista(eLocalidades* localitiesList, int len);
eLocalidades locObtenerPorId(eLocalidades* localitiesList, int localitiesLen, int id);


#endif /* LOCALIDAD_H_ */
