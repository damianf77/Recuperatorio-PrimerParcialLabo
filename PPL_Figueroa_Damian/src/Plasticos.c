//Author: Figueroa Damian

#include "Plasticos.h"

#include "Nexo.h"

int iniciaArrPlastico (ePlasticos* listaPlasticos, int lenPlasticos)
{
	int state = -1;

	if(listaPlasticos != NULL && lenPlasticos > 0)
	{
		for(int i = 0; i < lenPlasticos; i++)
		{
			listaPlasticos[i].isEmpty = EMPTY;
		}
	}
	return state;
}

int PLA_freeArraySpot (ePlasticos* plasticsList, int plasticsLen)
{
	int position;

	position = -1;

	if(plasticsList != NULL && plasticsLen > 0)
	{
		for(int i = 0; i < plasticsLen; i++)
		{
			if(plasticsList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}

int PLA_processPlastics (ePlasticos* plasticsList, int plasticsLen, int id, int weightOfOrder) //
{
	int state;
	int posToProcess;

	state = -1;

	if(plasticsList != NULL && plasticsLen > 0)
	{
		posToProcess = PLA_freeArraySpot(plasticsList, plasticsLen);

		plasticsList[posToProcess].idOrden = id;

		if(weightOfOrder > 0)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\tEl pedido pesa: %d Kl ",weightOfOrder);

			plasticsList[posToProcess].HDPE = obtieneEnteroValido("\n\t\t\t\t\t\t\tCuanto de este pedido de recoleccion le corresponde a HDPE?: ",
			"\n\t\t\t\t\t\t\tERROR - Reingrese un peso correcto - ERROR ", 1, weightOfOrder);

			weightOfOrder = weightOfOrder - plasticsList[posToProcess].HDPE;
			printf("\n\n\t\t\t\t\t\t\t\t\tBasura restante: %d Kl", weightOfOrder);
		}

		if(weightOfOrder > 0)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\tEl pedido pesa: %d Kl",weightOfOrder);

			plasticsList[posToProcess].LDPE = obtieneEnteroValido("\n\t\t\t\t\t\t\tCuanto de este pedido de recoleccion le corresponde a LDPE?: ",
			"\n\t\t\t\t\t\t\tERROR - Reingrese un peso correcto - ERROR ", 1, weightOfOrder);

			weightOfOrder = weightOfOrder - plasticsList[posToProcess].LDPE;
			printf("\n\n\t\t\t\t\t\t\t\t\tBasura restante: %d Kl", weightOfOrder);
		}

		if(weightOfOrder > 0)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\tEl pedido pesa: %d Kl",weightOfOrder);

			plasticsList[posToProcess].PP = obtieneEnteroValido("\n\t\t\t\t\t\t\tCuanto de este pedido de recoleccion le corresponde a PP?: ",
			"\n\t\t\t\t\t\t\tERROR - Reingrese un peso correcto - ERROR ", 1, weightOfOrder);
			weightOfOrder = weightOfOrder - plasticsList[posToProcess].PP;

			printf("\n\n\t\t\t\t\t\t\t\t\tBasura restante: %d Kl", weightOfOrder);
		}

		plasticsList[posToProcess].basuraDesechable = weightOfOrder;
		printf("\n\t\t\t\t\t\tEl plastico no reciclado ser� considerado basura y este es de: %d Kl", plasticsList[posToProcess].basuraDesechable);

		state = 0;
		plasticsList[posToProcess].isEmpty = FULL;
	}


	return state;
}
