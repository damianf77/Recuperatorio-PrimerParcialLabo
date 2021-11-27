//Author: Figueroa Damian

#ifndef PLASTICOS_H_
#define PLASTICOS_H_

#define FULL 0
#define EMPTY 1
#include "FuncionesFigueroa.h"

struct
{
	int orderId;
	int HDPE;
	int LDPE;
	int PP;
	int desechableThrash;
	int isEmpty;

}typedef sPlastics;

/// @fn int PLA_initArray(sPlastics*, int)
/// @brief Inicia el Array de ordenes en vacio.
///
/// @param plasticsList
/// @param plasticsLen
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int PLA_initArray (sPlastics* plasticsList, int plasticsLen);

/// @fn int PLA_freeArraySpot(sPlastics*, int)
/// @brief busca una posicion disponible para guardar el pedido procesado junto con todos sus plasticos.
///
/// @param plasticsList
/// @param plasticsLen
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int PLA_freeArraySpot (sPlastics* plasticsList, int plasticsLen);

/// @fn int PLA_processPlastics(sPlastics*, int, int, int)
/// @brief Procesa el pedido completo que le llega por parametros desde la funcion de procesar de ordenes.
///
/// @param plasticsList
/// @param plasticsLen
/// @param id
/// @param weightOrder
/// @return devuelve -1 si no se pudo realizar y 0 si se pudo.
int PLA_processPlastics (sPlastics* plasticsList, int plasticsLen, int id, int weightOrder);



#endif /* PLASTICOS_H_ */
