#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>		// para funcion kill y SIGUSR1
#define NUM_PROC 4
#define N 128	// Numero de datos

// Hay 19 señales en Linux para ocuparse
void proceso_padre(pid_t pid[NUM_PROC]);
void proceso_hijo(int np);
void manejador(int sig);

int main()
{	
	pid_t pid[NUM_PROC];  // guarda pids de los hijos
	register int np;

	printf("Probando procesos\n");	

	if (signal(SIGUSR1, manejador) == SIG_ERR){
		perror("Error en el manejador\n");
		exit(EXIT_FAILURE);
	}

	for (np = 0; np < NUM_PROC; np++)
	{
		pid[np] = fork();
		if (pid[np] == -1)
		{
			perror("Error al crear el proceso\n");
			exit(EXIT_FAILURE);
		}

		if (!pid[np])
		{
			// le pasamos el numero de proceso (np)
			proceso_hijo(np);
		}
	}
	proceso_padre(pid);
	
	return 0;
}

void manejador(int sig){
	if (sig == SIGUSR1)
	{
		printf("Señal de usuario 1 hace uso del manejador\n");
	}
}

// Clave: Mandarle un indice
// Np es el indice que ayuda a la distribución de tareas y procesos
void proceso_hijo(int np)
{
	printf("Proceso hijo %d ejecutado con pid: %d \n", np, getpid());
	
	pause();
	printf("Se recibio la señal en el proceso hijo\n");

	exit(np);  // Es el numero del proceso hijo que ha terminado
}

void proceso_padre(pid_t pid[NUM_PROC])
{
	register int np;
	int estado;
	pid_t pidh;

	for (np = 0; np < NUM_PROC; np++)
	{

		kill(pid[np], SIGUSR1); // en este instante se maneja ese manejador
		sleep(3);  // Cada 3 segundos manda la señal

		// El estado regresara el mayor o menor
		pidh = wait(&estado);
		printf("Proceso con PID: %d y retorno %d \n", pidh, (estado>>8));
	}
}



