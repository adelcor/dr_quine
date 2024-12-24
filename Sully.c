#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMPLATE "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c%1$c#define TEMPLATE %2$c%3$s%2$c%1$c%1$cint main(void)%1$c{%1$c%5$cint contador = %4$d;%1$c%5$cif (contador <= 0) return (0);%1$c%5$cchar nombre_archivo_actual[100];%1$c%5$csprintf(nombre_archivo_actual, %2$cSully_%%d.c%2$c, contador);%1$c%5$cif (!strcmp(nombre_archivo_actual, __FILE__)) contador--;%1$c%5$cchar nuevo_archivo_fuente[100];%1$c%5$csprintf(nuevo_archivo_fuente, %2$cSully_%%d.c%2$c, contador);%1$c%5$cchar nuevo_ejecutable[100];%1$c%5$csprintf(nuevo_ejecutable, %2$cSully_%%d%2$c, contador);%1$c%5$cFILE *archivo = fopen(nuevo_archivo_fuente, %2$cw%2$c);%1$c%5$cif (archivo == NULL) return (1);%1$c%5$cfprintf(archivo, TEMPLATE, 10, 34, TEMPLATE, contador, 9);%1$c%5$cfclose(archivo);%1$c%5$cchar comando_compilar[300];%1$c%5$csprintf(comando_compilar, %2$cgcc -o %%s %%s%2$c, nuevo_ejecutable, nuevo_archivo_fuente);%1$c%5$csystem(comando_compilar);%1$c%5$cchar comando_ejecutar[200];%1$c%5$csprintf(comando_ejecutar, %2$c./%%s%2$c, nuevo_ejecutable);%1$c%5$csystem(comando_ejecutar);%1$c%5$creturn (0);%1$c}%1$c"

int main(void)
{
	int contador = 5;
	if (contador <= 0) return (0);
	char nombre_archivo_actual[100];
	sprintf(nombre_archivo_actual, "Sully_%d.c", contador);
	if (!strcmp(nombre_archivo_actual, __FILE__)) contador--;
	char nuevo_archivo_fuente[100];
	sprintf(nuevo_archivo_fuente, "Sully_%d.c", contador);
	char nuevo_ejecutable[100];
	sprintf(nuevo_ejecutable, "Sully_%d", contador);
	FILE *archivo = fopen(nuevo_archivo_fuente, "w");
	if (archivo == NULL) return (1);
	fprintf(archivo, TEMPLATE, 10, 34, TEMPLATE, contador, 9);
	fclose(archivo);
	char comando_compilar[300];
	sprintf(comando_compilar, "gcc -o %s %s", nuevo_ejecutable, nuevo_archivo_fuente);
	system(comando_compilar);
	char comando_ejecutar[200];
	sprintf(comando_ejecutar, "./%s", nuevo_ejecutable);
	system(comando_ejecutar);
	return (0);
}