/*
 ============================================================================
 Name        : main.c
 Author      : Figueroa Damian
 */


#include "Nexo.h"

int main(void)
{
	setbuf(stdout,NULL);

	eCliente clientList[MAX];
	eOrden ordersList[MAX2];

	eLocalidades localitiesList[MAX];
	sPlastics plasticsList[MAX2];

	int uniqueID;
	int uniqueOrderID;
	int uniqueLocalityID;

	int menuOption;
	int subMenu;

	int maxHardcodeLocalitiesFlag;
	int clientsCounter;
	int ordersCounter;
	int firstObligatoryLocality;

	/// Flags
	ordersCounter = 0;
	firstObligatoryLocality = 0;
	clientsCounter = 0;
	maxHardcodeLocalitiesFlag = 0;

	/// Id's Generators
	uniqueOrderID = 0;
	uniqueID = 0;
	uniqueLocalityID = 0;

	/// Init Arrays
	initOrders(ordersList, MAX2);
	inicializaClientes(clientList, MAX);
	inicializaLocalidades(localitiesList,MAX);
	PLA_initArray(plasticsList, MAX2);

	do
	{
		imprimirMenu();
		menuOption = obtieneEnteroValido("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 7: ",
		"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 7);

		switch(menuOption)
		{
			case 1:
				do
				{
					imprimirSubMenu();
					subMenu = obtieneEnteroValido("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 7: ",
					 "\n\n\t\t\t\t\tERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n",
					 1, 7);
					switch(subMenu)
					{
						case 1:
							if(firstObligatoryLocality > 0)
							{
								nuevoCliente(clientList, localitiesList, MAX, &uniqueID, &uniqueLocalityID);
								printf("\n\n\t\t\t\t\t\t\t\t\tMostrando nuevo cliente");

								CLI_printClientsListWithLocalities(clientList, localitiesList, MAX, MAX);
								clientsCounter++;
							}
							else
							{
								printf("\n\n\t\t\t\t\t\t\tERROR - (Debe crear al menos una localidad) - ERROR");
							}
						break;

						case 2:
							nuevaLocalidad(localitiesList, MAX, &uniqueLocalityID);
							firstObligatoryLocality++;
						break;

						case 3:
							if(firstObligatoryLocality > 0)
							{
								borraLocalidad(localitiesList, MAX);
								firstObligatoryLocality--;
							}
							else
							{
								printf("\n\n\t\t\t\t\t\tERROR - (Debe crear al menos una localidad antes de poder dar de baja) - ERROR");
							}
						break;
						case 4:
							harcodeaLocalidades(localitiesList,MAX,&uniqueLocalityID);
							firstObligatoryLocality = 12;
						break;
						case 5:
								locImprimeLista(localitiesList, MAX);
						break;
						case 6:
							if(maxHardcodeLocalitiesFlag == 0)
							{
								harcodeaLocalidades(localitiesList,MAX,&uniqueLocalityID);
								crearClientesRandom(clientList, MAX, &uniqueID);
								arrayChargeOrders(ordersList,clientList,MAX,&uniqueOrderID); /// Ordenes
								CLI_printClientsListWithLocalities(clientList, localitiesList, MAX, MAX);

								maxHardcodeLocalitiesFlag = 1;
								clientsCounter+=clientsCounter+12;
								ordersCounter+=ordersCounter+12;
							}
							else
							{
								printf("\n\t\t\tLas localidades ya fueron cargadas,"
										" cargarlas mas de una vez podria ocasionar un problema en el programa\n"
										"\n\t\t\t\t\t\t Volviendo al menu\n\n");
							}
						break;
					}
				}while(subMenu != 7);
			break;

			case 2:
				if(clientsCounter > 0)
				{
					modificaCliente(clientList, localitiesList, MAX, &uniqueLocalityID);
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ningun cliente existente, cree uno antes de poder modificarlo!");
				}
			break;
			case 3:
				if(clientsCounter > 0)
				{
					bajaCliente(clientList, localitiesList, MAX);
					clientsCounter--;
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ningun cliente existente, cree uno antes de poder modificarlo!");
				}
			break;
			case 4:
				if(clientsCounter > 0)
				{
					newOrder(clientList, ordersList, localitiesList, MAX, &uniqueOrderID);
					ordersCounter++;
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ningun cliente existente, cree uno antes de poder asignarle un pedido!");
				}
			break;
			case 5:
				if(ordersCounter > 0)
				{
					processingOrder(clientList, ordersList, plasticsList, MAX, MAX2);
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ninguna orden creada, cree una antes de poder procesarla!");
				}
			break;
			case 6:
				do
				{
					imprimeMenuInformes();
					menuOption = obtieneEnteroValido("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 11: ",
					"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 11);

					switch(menuOption)
					{
						case 1:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showClientsWithPendingOrders(clientList, ordersList, localitiesList, MAX, MAX2, MAX);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 2:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showPedingOrdersWithClientsInfo(clientList, ordersList, MAX, MAX2);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 3:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showCompleteOrdersWithWeight(clientList, ordersList, plasticsList, MAX, MAX2);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 4:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showPendingOrdersByLocality(localitiesList,clientList, ordersList,MAX,MAX2,&uniqueLocalityID);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 5:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								averagePPRecicledByClient(clientList, ordersList, plasticsList, MAX, MAX2);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 6:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, PENDING);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 7:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, COMPLETED);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 8:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, ALL);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 9:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								plasticRecicledByLocality(clientList, localitiesList, ordersList, plasticsList, MAX, MAX2, &uniqueLocalityID);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}

						break;
						case 10:
							if(clientsCounter > 0)
							{
								CLI_printClientsListWithLocalities(clientList, localitiesList, MAX, MAX);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes creados, cree uno poder entrar a esta opcion");
							}
						break;
					}
				}while (menuOption != 11);
			break;
			}
		}while(menuOption!= 7);




}
