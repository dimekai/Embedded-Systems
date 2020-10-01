/**
* @brief: muestreo.c
* @desc: Este programa genera una señal senoindal y 
*        la guarda en un archivo
**/

#include <stdio.h>
#include "archivos.h"
#include "procesamiento.h"
#include "defs.h"

int main(){

	float seno[MUESTRAS];
	generarSeno(seno);
	guardarDatos(seno);

	return 0;
}