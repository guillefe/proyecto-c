#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celdas.h"
#include "comandos.h"

/**
 * Crea un nuevo nodo de tipo t_punto_acceso.
 * 
 * Esta funcion assigna memoria para un nuevo nodo de tipo t_punto_accesso,
 * inicializa todos los campos a cero y devuelve un puntero al nodo.
 * 
 * @return Un puntero al nuevo nodo inicializado, o NULL si la reserva de memoria falla
 */
t_punto_acceso *nuevo_nodo(void)
{
	t_punto_acceso *nodo;

	nodo = malloc(sizeof(t_punto_acceso));
	if (nodo == NULL)
		return NULL;
	
	memset(nodo, 0, sizeof(t_punto_acceso));

	return nodo;
}

/**
 * Agrega un nuevo nodo al final de la lista enlazada.
 *
 * Esta función toma un puntero a la cabeza de la lista y un puntero al nuevo nodo,
 * y lo agrega al final de la lista. Si la lista está vacía, el nuevo nodo se convierte
 * en la cabeza de la lista.
 *
 * @param nodo_cabeza Un puntero al puntero de la cabeza de la lista.
 * @param nodo_nuevo Un puntero al nuevo nodo que se agregará al final de la lista.
 */
void agregar_nodo_fin_lista(t_punto_acceso **nodo_cabeza, t_punto_acceso *nodo_nuevo)
{
	t_punto_acceso *nodo_temporal;

	if (*nodo_cabeza == NULL)
		*nodo_cabeza = nodo_nuevo;
	else
	{
		nodo_temporal = *nodo_cabeza;
		while (nodo_temporal->next != NULL)
			nodo_temporal = nodo_temporal->next;
		nodo_temporal->next = nodo_nuevo;
		nodo_nuevo->prev = nodo_temporal;
	}
	nodo_nuevo->next = NULL;
}

/**
 * Libera todos los nodos de la lista enlazada.
 *
 * Esta función recorre la lista enlazada desde la cabeza y libera la memoria
 * de cada nodo. Al finalizar, el puntero a la cabeza de la lista se establece en NULL.
 *
 * @param nodo_cabeza Un puntero al puntero de la cabeza de la lista.
 */
void liberar_lista(t_punto_acceso **nodo_cabeza)
{
	t_punto_acceso *temporal;

	while (*nodo_cabeza != NULL)
	{
		temporal = *nodo_cabeza;
		*nodo_cabeza = (*nodo_cabeza)->next;
		free(temporal);
	}
	*nodo_cabeza = NULL;
}

/**
 * Libera un nodo específico de la lista enlazada.
 *
 * Esta función toma un puntero a la cabeza de la lista y un puntero al nodo que se desea eliminar.
 * Ajusta los punteros de los nodos adyacentes para mantener la integridad de la lista y libera
 * la memoria del nodo eliminado.
 *
 * @param nodo_cabeza Un puntero al puntero de la cabeza de la lista.
 * @param nodo_eliminar Un puntero al nodo que se desea eliminar.
 */
void liberar_un_nodo(t_punto_acceso **nodo_cabeza, t_punto_acceso *nodo_eliminar)
{
	if (*nodo_cabeza == NULL || nodo_eliminar == NULL)
		return;

	if (*nodo_cabeza == nodo_eliminar)
		*nodo_cabeza = nodo_eliminar->next;
	
	if (nodo_eliminar->prev != NULL)
		nodo_eliminar->prev->next = nodo_eliminar->next;

	if (nodo_eliminar->next != NULL)
		nodo_eliminar->next->prev = nodo_eliminar->prev;

	free(nodo_eliminar);
}

unsigned char 