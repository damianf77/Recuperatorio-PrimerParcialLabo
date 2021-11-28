//Author: Figueroa Damian

#include "FuncionesFigueroa.h"

void imprimirMenu(void)
{
			printf("\t\t\t\t         Bienvenido, seleccione alguna de las Opciones: \t\t\t\t  \n\n");
			printf("\t\t\t\t 1) Alta: clientes, Localidades - Baja: Localidades - Carga: Localidades \n");
			printf("\t\t\t\t 2) Modificar datos de cliente \n");
			printf("\t\t\t\t 3) Baja de cliente \n");
			printf("\t\t\t\t 4) Crear pedido de recolección \n");
			printf("\t\t\t\t 5) Procesar residuos \n");
			printf("\t\t\t\t 6) Mostrar Informes \n");
			printf("\t\t\t\t 7) Salir \n");
}

void imprimirSubMenu(void)
{

	printf("\t\t\t\t         			 Opciones: \t\t\t\t  \n\n");
	printf("\t\t\t\t 1) Alta de cliente \n");
	printf("\t\t\t\t 2) Agregar Localidad \n");
	printf("\t\t\t\t 3) Baja de Localidad \n");
	printf("\t\t\t\t 4) Cargar localidades predeterminadas \n");
	printf("\t\t\t\t 5) Mostrar localidades existentes \n");
	printf("\t\t\t\t 6) Cargar localidades predeterminadas y clientes de prueba \n");
	printf("\t\t\t\t 7) Volver al menu principal \n");

}

void imprimeMenuInformes(void)
{
	printf("\t\t\t\t         	Informes, opciones: \t\t\t\t  \n\n");
	printf("\t\t\t\t 1) Imprimir Clientes: con todos sus datos y “pedidos de recolección” en “Pendiente” \n");
	printf("\t\t\t\t 2) Imprimir Clientes: con pedidos en estado pendiente con CUIT, Direccion y cantidad de kilos a recolectar \n");
	printf("\t\t\t\t 3) Imprimir Pedidos procesados: Con CUIT, Direccion, cantidad de kilos reciclados de cada tipo de plastico \n");
	printf("\t\t\t\t 4) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad \n");
	printf("\t\t\t\t 5) Cantidad de kilos de polipropileno reciclado promedio por cliente \n");
	printf("\t\t\t\t 6) Cliente con más pedidos pendientes \n");
	printf("\t\t\t\t 7) Cliente con más pedidos completados \n");
	printf("\t\t\t\t 8) Cliente con más pedidos \n");
	printf("\t\t\t\t 9) Ingrese una localidad para mostrar el total de los plasticos reciclados de esa zona \n");
	printf("\t\t\t\t 10) Mostrar Lista de clientes \n");
	printf("\t\t\t\t 11) Salir \n\n");
}

int obtieneEnteroValido(char mensaje [], char error [], int min, int max) ///
{
	char integrer[MAX];
	int validIntegrer;

	validIntegrer = soloEnteros(integrer,error,mensaje, min, max);

	return validIntegrer;

}

int soloEnteros(char integrer [],char error [], char mensaje[], int min, int max) ///
{
	int resultado = 0;
	int valido;
	do
	{
		valido = 1;
		printf ("%s",mensaje);
		scanf ("%s", integrer);

		while(valido == 0)
		{
			char *ptr;

			ptr = integrer;

			if(!isdigit(*ptr))
			printf("\n\n\t\t\t\t\t    ERROR - (Has ingresado %s y solo se aceptan numeros) - ERROR\n", integrer);
			valido = 0;
		}

		if (valido == 1)
		{
			resultado = atof(integrer);
			if (resultado < min || resultado > max)
			{
				valido = 0;
			}

			if(valido == 0)
			{
				printf("%s", error);
			}
		}
	} while (!valido);

	return resultado;
}

int obtieneString(char mensaje[],char str[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s", str);

    return 1;
}

int pideDireccion (char message[], char str[])
{
    printf("%s",message);
    fflush(stdin);
    scanf("%[^\n]s",str);

    return 1;
}

int validaString(char mensaje[], char mensajeError[], char *input) ///
{
    int retorno = -1;
    char aux[256];

    obtieneString(mensaje, aux);

    while (retorno == -1)
    {
        if (validaChar(aux) == 0)
        {
            obtieneString(mensajeError, aux);
        }
        else
        {
            retorno = 0;
            strcpy(input, aux);
        }
    }
    return retorno;
}

int obtenerLocalidadValida(char mensaje[], char mensajeError[], char *input) ///
{
    int retorno = -1;
    char aux[256];

    obtieneString(mensaje, aux);

    while (retorno == -1)
    {
        if (validaChar(aux) == 0)
        {
            obtieneString(mensajeError, aux);
        }
        else
        {
            retorno = 0;
            strcpy(input, aux);
        }
    }
    return retorno;
}

int validaChar(char str[])
{
   int i=0;

   while(str[i] != '\0')
   {
       if((i==0&&str[i]==32) && (str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }

   return 1;
}

void formatearChar(char str[]) ///
{
	int strLenght;
	int i;

	strLenght=strlen(str);
	strlwr(str);

	if(str != NULL)
	{
		for(i = 0;i<strLenght;i++)
		{
			if(i == 0 || str[i-1]==32)
			{
				str[i]= toupper(str[i]);
			}
		}
	}

}
