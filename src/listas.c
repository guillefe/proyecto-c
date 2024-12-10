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


// Funci�n para validar una direcci�n MAC
int is_valid_mac(const char *mac) {
    // Verificar la longitud: debe ser exactamente 17 caracteres
    if (strlen(mac) != 17) {
        return EXIT_FAILURE;
    }

    // Verificar cada car�cter
    for (int i = 0; i < 17; i++) {
        if (i % 3 == 2) {
            // Cada tercer car�cter debe ser ':' o '-'
            if (mac[i] != ':' && mac[i] != '-') {
                return EXIT_FAILURE;
            }
        } else {
            // Los otros caracteres deben ser d�gitos hexadecimales
            if (!isxdigit(mac[i])) {
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}

int rellenar_nodo(t_punto_acceso *nodo, const char *linea)
{
	int rtrn = EXIT_FAILURE;
	char *temporal = NULL;

	if (nodo == NULL || linea == NULL)
		return (EXIT_FAILURE);
	
	if (strncmp(linea, CELL_STRING, strlen(CELL_STRING)) == 0)
	{
		// Linea Cell N
		temporal = strchr(linea, ' ');
		if (temporal != NULL)
		{
			nodo->id_cell = atoi(temporal);
			if (nodo->id_cell > 0 && nodo->id_cell <= 21)
				rtrn = EXIT_SUCCESS;
		}
	}
	else if (strncmp (linea, ADDRESS_STRING, strlen(ADDRESS_STRING)) == 0)
	{
		// Linea Address
		temporal = strchr(linea, ' ');
		while (isspace((unsigned char)*temporal))
			temporal++;
		if (temporal != NULL)
		{

		}
	}

	return rtrn;
}