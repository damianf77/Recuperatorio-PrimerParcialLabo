//Author: Figueroa Damian

#ifndef PLASTICOS_H_
#define PLASTICOS_H_

#define FULL 0
#define EMPTY 1
#include "FuncionesFigueroa.h"

struct
{
	int idOrden;
	int HDPE;
	int LDPE;
	int PP;
	int basuraDesechable;
	int isEmpty;

}typedef ePlasticos;

//brief Inicia el Array de ordenes en vacio.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int iniciaArrPlastico(ePlasticos *listaPlasticos, int lenPlasticos);
//brief busca una posicion disponible para guardar el pedido procesado junto con todos sus plasticos.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int PLA_freeArraySpot (ePlasticos* plasticsList, int plasticsLen);

//brief Procesa el pedido completo que le llega por parametros desde la funcion de procesar de ordenes.
//return devuelve -1 si no se pudo realizar y 0 si se pudo.
int PLA_processPlastics (ePlasticos* plasticsList, int plasticsLen, int id, int weightOrder);



#endif /* PLASTICOS_H_ */
