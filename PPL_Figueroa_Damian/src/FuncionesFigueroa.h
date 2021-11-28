//Author: Figueroa Damian

#ifndef FUNCIONESFIGUEROA_H_
#define FUNCIONESFIGUEROA_H_
#define MAX 100
#define MAX2 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimirMenu(void);
void imprimirSubMenu(void);
void imprimeMenuInformes (void);
int obtieneEnteroValido(char mensaje [], char error [], int min, int max);
int soloEnteros(char integrer[], char mensaje[],char error [], int min, int max);
int obtieneString(char mensaje[],char str[]);
int validaChar(char str[]);
int pideDireccion (char message [], char str[]);
int validaString(char mensaje[], char mensajeError[], char *input);
int argentinianCuitValidation (char mensaje[], char mensajeError[], char *input);
int obtenerLocalidadValida(char mensaje[], char mensajeError[], char *input);
int validaChar(char str[]);
void formatearChar(char str[]);


#endif /* FUNCIONESFIGUEROA_H_ */
