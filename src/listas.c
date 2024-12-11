#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "celdas.h"
#include "comandos.h"

#define CELL_STRING "Cell"
#define ADDRESS_STRING "Address"
#define ESSID_STRING "ESSID"
#define MODE_STRING "Mode"
#define CHANNEL_SRTING "Channel"
#define ENCRYPTION_STRING "Encryption key"
#define QUALITY_STRING "Quality"
#define FREQUENCY_STRING "Frequency"
#define SIGNAL_STRING "Signal level"

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

int rellenar_nodo(t_punto_acceso *nodo, const char *linea)
{
	char *temporal = NULL;
	int	clave_longitud = 0;
	int rtrn = EXIT_SUCCESS;

	if (nodo == NULL || linea == NULL)
		return (EXIT_FAILURE);
	
	if (strncmp(linea, CELL_STRING, strlen(CELL_STRING)) == 0)
	{
		// Linea Cell N
		temporal = linea + strlen(CELL_STRING) - 1;
		snprintf(nodo->id_cell, MAX_VALUE_LENGTH, "%s", temporal);
	}
	else if (strncmp (linea, ADDRESS_STRING, strlen(ADDRESS_STRING)) == 0)
	{
		// Linea Address
		temporal = linea + strlen(ADDRESS_STRING) - 1;
		snprintf(nodo->mac_address, MAX_VALUE_LENGTH, "%s", temporal);
	}
	else if (strncmp (linea, ESSID_STRING, strlen(ESSID_STRING)) == 0)
	{
		// Linea ESSID
		temporal = linea + strlen(ESSID_STRING) - 1;
		snprintf(nodo->essid, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, MODE_STRING, strlen(MODE_STRING)) == 0)
	{
		// Linea Mode
		temporal = linea + strlen(MODE_STRING) - 1;
		snprintf(nodo->mode, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, CHANNEL_SRTING, strlen(CHANNEL_SRTING)) == 0)
	{
		// Linea Channel
		temporal = linea + strlen(CHANNEL_SRTING) - 1;
		snprintf(nodo->channel, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, ENCRYPTION_STRING, strlen(ENCRYPTION_STRING)) == 0)
	{
		// Linea Encryption
		temporal = linea + strlen(ENCRYPTION_STRING) - 1;
		snprintf(nodo->encryptation, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, QUALITY_STRING, strlen(QUALITY_STRING)) == 0)
	{
		// Linea Quality
		temporal = linea + strlen(QUALITY_STRING) - 1;
		snprintf(nodo->quality, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, FREQUENCY_STRING, strlen(FREQUENCY_STRING)) == 0)
	{
		// Linea Frequency
		temporal = linea + strlen(FREQUENCY_STRING) - 1;
		snprintf(nodo->frequency, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, SIGNAL_STRING, strlen(SIGNAL_STRING)) == 0)
	{
		// Linea Signal
		temporal = linea + strlen(SIGNAL_STRING) - 1;
		snprintf(nodo->signal_level, MAX_VALUE_LENGTH, "%s", temporal);
	}
	else
		rtrn = EXIT_FAILURE;
	return rtrn;
}

void	vaciar_nodo(t_punto_acceso *nodo)
{
	memset(nodo, 0, sizeof(t_punto_acceso));
}