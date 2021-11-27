//Author: Figueroa Damian

#ifndef CLIENTES_H_
#define CLIENTES_H_
#include "FuncionesFigueroa.h"
#include "Localidad.h"
#define FULL 0
#define EMPTY 1

struct
{
	char nombreEmpresa[20];
	char cuit[14];
	char direccion[20];
	int idLocalidad;
	int idCliente;
	int orderStatus;
	int isEmpty;

}typedef eCliente;

/// @fn int initClients(eClients*, int)
/// @brief Inicia el array de clientes en empty.
///
/// @param clientList
/// @param len
/// @return -1 si no se logro, 0 si se pudo.
int inicializaClientes (eCliente* clientList, int len);

/// @fn int freeClientSpot(eClients*, int)
/// @brief Busca lugar libre para un nuevo cliente.
///
/// @param clientList
/// @param len
/// @return devuelve -1 si no se pudo conseguir, o la posicion libre.
int espacioNuevoCliente (eCliente* clientList, int len);

/// @fn int newClient(eClients*, sLocality*, int, int*, int*)
/// @brief Pide y valida los datos para la creación de un nuevo cliente.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param uniqueID
/// @param uniqueLocalityID
/// @return -1 si no se logro, 0 si se pudo.
int nuevoCliente (eCliente* clientList, eLocalidades* localitiesList, int len, int* uniqueID, int* uniqueLocalityID);

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
int agregarCliente (eCliente* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id);

/// @fn int modifyClient(eClients*, sLocality*, int, int*)
/// @brief Pide ingresar el id de el cliente que quiere modificar y permite cambia dirección y localidad.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param uniqueLocalityID
/// @return devuelve 1 si pudo hacerlo satisfactoriamente.
int modificaCliente (eCliente* clientList, eLocalidades* localitiesList, int len, int* uniqueLocalityID);

/// @fn int idAsk(eClients*, sLocality*, int)
/// @brief Pide un id mostrando la lista de clientes existentes.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @return La posicion para usar.
int pedirID(eCliente* clientList, eLocalidades* localitiesList, int len);

/// @fn int idValidation(eClients*, sLocality*, int, int)
/// @brief Se fija si la posicion recibida por parametros existe.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param enteredId
/// @return -1 si no existe, la posicion si existe.
int validaID (eCliente* clientList, eLocalidades* localitiesList, int len, int enteredId);

/// @fn int showOneClient(eClients)
/// @brief muestra un cliente.
///
/// @param clientList
/// @return -1 si no se logro, 0 si se pudo.
int mostrarCliente (eCliente clientList);

/// @fn int showListOfClients(eClients*, int)
/// @brief muestra la lista de clientes existentes si es que existen.
///
/// @param clientList
/// @param len
/// @return -1 si no se logro, 0 si se pudo.
int mostrarListaClientes (eCliente* clientList, int len);

/// @fn int withdrawalClient(eClients*, sLocality*, int)
/// @brief Da de baja logica un cliente.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @return devuelve -1 si no se pudo dar de baja, 0 si se pudo dar de baja.
int bajaCliente (eCliente* clientList, eLocalidades* localitiesList, int len);


int arrayCharge (eCliente* clientList, int len, int* uniqueID);
int initOrdersQueue (eCliente* clientList, int len);
eCliente clientePorID(eCliente* clientList, int clientsLen, int id);
int crearClientesRandom(eCliente* clientList ,int clientsLen,int *uniqueID);


#endif /* CLIENTES_H_ */
