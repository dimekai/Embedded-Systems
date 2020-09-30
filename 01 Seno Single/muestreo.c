#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MUESTRAS 512

void generarSeno(float seno[]);
void guardarDatos(float datos[]);

int main(){

	float seno[MUESTRAS];
	generarSeno(seno);
	guardarDatos(seno);

	return 0;
}


void guardarDatos(float datos[]){
	
	FILE * archivo;
	register int n;

	archivo = fopen("seno.dat", "w");
	
	if (!archivo)
	{
		perror("Error al abrir el archivo.\n");
		exit(EXIT_FAILURE);
	}

	for (n = 0; n < MUESTRAS; n++)
	{
		fprintf(archivo, "%f\n", datos[n]);
	}

	// Cerramos el archivo
	fclose(archivo);

}

void generarSeno(float seno[]){

	float f = 1000, fs = 45000;
	register int n;

	for (n = 0; n < MUESTRAS; n++)
	{
		seno[n] = sinf(2 * M_PI * f * n / fs);
	}

}