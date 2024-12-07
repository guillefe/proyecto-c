/*********************************************************************************************************************
 *
 * NOMBRE DE ARCHIVO: README
 *
 * AUTORES:    Martin Alexander Suárez Cumbicus
 *			   Guillermo Fernandez Palomino
 *  	
 *********************************************************************************************************************/

El programa maneja informacion sobre redes inalambricas que se almacenan en ficheros de datos.
El programa interactua con el usuario mediante un menu main().
Sus opciones son: //Options for the user:
 	-salir del menu correspondiente preguntandoselo reiteradamente al usuario.
	-leer los datos de redes de la carpeta "input_files" y los almacena en celdas.
	-imprimir por pantalla las celdas almacenas por orden decreciente segun su calidad de señal 
	-mostrar un unico elemento que sea por decision del usuario.
 	- muestra las redes alacenada en la memoria.

La carpeta input_files tiene la informacion que debe leer para el programa

La carpeta incl tiene dos ficheros:
	* celdas.h con la estructura de informacion que representa en el almacen de datos
	* comandos.h con la inicializacion de las funcione del programa

La carpetasrc tiene tres documentos:
	* main.c tiene el control del programa
	* celdas.c contiene los comandos de control del almacenamiento
	* comandos.c contiene las funciones que dan para el uso del usuario 

Para compilar el programa utilizamos el makefile:
	make


