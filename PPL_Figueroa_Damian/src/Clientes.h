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
	int estadoOrden;
	int isEmpty;

}typedef eCliente;

//brief Inicia el array de clientes en empty.
//return -1 si no se logro, 0 si se pudo.
int inicializaClientes (eCliente* clientList, int len);

//brief Busca lugar libre para un nuevo cliente.
//return devuelve -1 si no se pudo conseguir, o la posicion libre.
int espacioNuevoCliente (eCliente* clientList, int len);

//brief Pide y valida los datos para la creación de un nuevo cliente.
//return -1 si no se logro, 0 si se pudo.
int nuevoCliente (eCliente* clientList, eLocalidades* localitiesList, int len, int* uniqueID, int* uniqueLocalityID);

//brief Alta de cliente, obtiene una posision libre y carga todos los datos de los parametros en esa posicion.
//return devuelve 1 si se pudo crear.
int agregarCliente (eCliente* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id);

//brief Pide ingresar el id de el cliente que quiere modificar y permite cambia dirección y localidad.
//return devuelve 1 si pudo hacerlo satisfactoriamente.
int modificaCliente (eCliente* clientList, eLocalidades* localitiesList, int len, int* uniqueLocalityID);

//brief Pide un id mostrando la lista de clientes existentes.
//return La posicion para usar.
int pedirID(eCliente* clientList, eLocalidades* localitiesList, int len);

//brief Se fija si la posicion recibida por parametros existe.
//return -1 si no existe, la posicion si existe.
int validaID (eCliente* clientList, eLocalidades* localitiesList, int len, int enteredId);

//brief muestra un cliente.
//return -1 si no se logro, 0 si se pudo.
int mostrarCliente (eCliente clientList);

//brief muestra la lista de clientes existentes si es que existen.
//return -1 si no se logro, 0 si se pudo.
int mostrarListaClientes (eCliente* clientList, int len);

//brief Da de baja logica un cliente.
//return devuelve -1 si no se pudo dar de baja, 0 si se pudo dar de baja.
int bajaCliente (eCliente* clientList, eLocalidades* localitiesList, int len);


int arrayCharge (eCliente* clientList, int len, int* uniqueID);
int initOrdersQueue (eCliente* clientList, int len);
eCliente clientePorID(eCliente* clientList, int clientsLen, int id);
int crearClientesRandom(eCliente* clientList ,int clientsLen,int *uniqueID);


#endif /* CLIENTES_H_ */
