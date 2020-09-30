# Aplicación para la función Seno

* En este ejemplo práctico generamos 512 muestras para la función `seno` con el fin de de poner visualizarlo utilizando la herramienta de `gnuplot`.
* Para poder ejecutar el siguiente programo haremos lo siguiente:


```bash
> gcc muestreo.c -o muestro -lm -Wall
> gnuplot
   > plot "seno.dat" with lines
```

## Explicación
* `-lm` : Al utilizar el comando `-lm` lo que hace es que _linkear_ los archivos para poder trabajar con ello y que no marque errores.
* `-Wall`: Al usar este comando, le dice al compilador que nos muestre todos aquellos __warnings__. Esto es útil para visualizar aquellas variables y/o espacios de memoria no usados.