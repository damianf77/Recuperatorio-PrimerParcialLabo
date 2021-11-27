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

/// @fn int LOC_init(sLocality*, int)
/// @brief Inicia el vector de localidades en EMPTY.
///
/// @param localitiesList
/// @param localitiesLen
/// @return 0 si pudo -1 si no pudo.
int inicializaLocalidades (eLocalidades* localitiesList, int localitiesLen);

/// @fn int LOC_hardcodeLocalities(sLocality*, int, int*)
/// @brief Harcodea localidades
///
/// @param localitiesList
/// @param len
/// @param uniqueLocalityID
/// @return0 si pudo -1 si no pudo.
int harcodeaLocalidades (eLocalidades* localitiesList, int len, int* uniqueLocalityID);

/// @fn int LOC_freeSpot(sLocality*, int)
/// @brief Busca un lugar libre en el vector para crear una nueva localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @return 0 si pudo -1 si no pudo.
int locLugarLibre (eLocalidades* localitiesList, int localitiesLen);

/// @fn int LOC_newLocality(sLocality*, int, int*)
/// @brief Pide todos los datos para una nueva localidad y se los pasa LOC_chargeLocalitiesList
///
/// @param localitiesList
/// @param len
/// @param uniqueLocalityID
/// @return 0 si pudo -1 si no pudo.
int nuevaLocalidad(eLocalidades* localitiesList, int len, int* uniqueLocalityID);

/// @fn int LOC_withdrawal(sLocality*, int)
/// @brief Da de baja logica una localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @return 0 si pudo -1 si no pudo.
int borraLocalidad (eLocalidades* localitiesList, int localitiesLen);

/// @fn int LOC_idAsk(sLocality*, int)
/// @brief Pide un id para dar de baja una localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @return La posicion si existe o -1 si no existe.
int locPideId(eLocalidades* localitiesList, int localitiesLen);

/// @fn int LOC_idValidation(sLocality*, int, int)
/// @brief Valida si existe un id para dar de baja una localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @param enteredId
/// @return La posicion si existe o -1 si no existe.
int locValidaId (eLocalidades* localitiesList, int localitiesLen, int enteredId);

/// @fn int LOC_chargeLocalitiesList(sLocality*, int*, int, char[])
/// @brief Alta de nueva localidad
///
/// @param localitiesList
/// @param uniqueLocalityID
/// @param localitiesLen
/// @param auxLocality
/// @return 0 si la pudo crear o -1 si no pudo crearla.
int cargaListaLocalidades(eLocalidades* localitiesList, int* uniqueLocalityID, int localitiesLen, char auxLocality []);
int locBuscar (eLocalidades* localitiesList, int localitiesLen, char auxLocality [], int* uniqueLocalityID);
int locImprimeLocalidad(eLocalidades localitiesList);
int locImprimeLista(eLocalidades* localitiesList, int len);
eLocalidades locObtenerPorId(eLocalidades* localitiesList, int localitiesLen, int id);


#endif /* LOCALIDAD_H_ */
