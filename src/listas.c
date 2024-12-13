#include "wificollector.h"

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

char *trim(char *str, const char *characters)
{
    if (str == NULL || characters == NULL)
        return str;

    char *start = str;
    char *end = str + strlen(str) - 1;

    while (*start && strchr(characters, *start))
        start++;

    while (end >= start && strchr(characters, *end))
        *end-- = '\0';

    return start;
}

int rellenar_nodo(t_punto_acceso *nodo, const char *linea)
{
	char *temporal = NULL;
	int rtrn = EXIT_SUCCESS;
	char linea_copia[MAX_VALUE_LENGTH];

	if (nodo == NULL || linea == NULL)
		return (EXIT_FAILURE);

	snprintf(linea_copia, MAX_VALUE_LENGTH, "%s", linea);
	
	if (strncmp(linea, CELL_STRING, strlen(CELL_STRING)) == 0)
	{
		// Linea Cell N
		temporal = linea_copia + strlen(CELL_STRING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->id_cell, MAX_VALUE_LENGTH, "%s", temporal);
	}
	else if (strncmp (linea, ADDRESS_STRING, strlen(ADDRESS_STRING)) == 0)
	{
		// Linea Address
		temporal = linea_copia + strlen(ADDRESS_STRING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->mac_address, MAX_VALUE_LENGTH, "%s", temporal);
	}
	else if (strncmp (linea, ESSID_STRING, strlen(ESSID_STRING)) == 0)
	{
		// Linea ESSID
		temporal = linea_copia + strlen(ESSID_STRING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->essid, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, MODE_STRING, strlen(MODE_STRING)) == 0)
	{
		// Linea Mode
		temporal = linea_copia + strlen(MODE_STRING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->mode, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, CHANNEL_SRTING, strlen(CHANNEL_SRTING)) == 0)
	{
		// Linea Channel
		temporal = linea_copia + strlen(CHANNEL_SRTING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->channel, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, ENCRYPTION_STRING, strlen(ENCRYPTION_STRING)) == 0)
	{
		// Linea Encryption
		temporal = linea_copia + strlen(ENCRYPTION_STRING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->encryption, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, QUALITY_STRING, strlen(QUALITY_STRING)) == 0)
	{
		// Linea Quality
		temporal = linea_copia + strlen(QUALITY_STRING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->quality, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, FREQUENCY_STRING, strlen(FREQUENCY_STRING)) == 0)
	{
		// Linea Frequency
		temporal = linea_copia + strlen(FREQUENCY_STRING);
		temporal = trim(temporal, " \"=:\n");
		snprintf(nodo->frequency, MAX_VALUE_LENGTH, "%s", temporal);
	}
		else if (strncmp (linea, SIGNAL_STRING, strlen(SIGNAL_STRING)) == 0)
	{
		// Linea Signal
		temporal = linea_copia + strlen(SIGNAL_STRING);
		temporal = trim(temporal, " \"=:\n");
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

int comprobar_nodo(t_punto_acceso **lista, t_punto_acceso *nodo, int cell_file)
{
	t_punto_acceso *nodo_actual = NULL;
	if (nodo == NULL)
		return EXIT_FAILURE;

	nodo_actual = *lista;

	if (check_cell(nodo->id_cell, cell_file) == EXIT_FAILURE ||
		check_address(nodo->mac_address) == EXIT_FAILURE ||
		check_essid(nodo->essid) == EXIT_FAILURE ||
		check_mode(nodo->mode) == EXIT_FAILURE ||
		check_channel(nodo->channel) == EXIT_FAILURE ||
		check_encryption(nodo->encryption) == EXIT_FAILURE ||
		check_quality(nodo->quality) == EXIT_FAILURE ||
		check_frequency(nodo->frequency) == EXIT_FAILURE ||
		check_signal(nodo->signal_level) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}

	while (nodo_actual)
	{
		if (strcmp(nodo->mac_address, nodo_actual->mac_address) == 0)
			return EXIT_FAILURE;
		nodo_actual = nodo_actual->next;
	}

	return EXIT_SUCCESS;
}

int	numero_nodos(t_punto_acceso **lista)
{
	t_punto_acceso *nodo_actual;
	int nodos = 0;

	if (*lista == NULL)
		return 0;
	
	nodo_actual = *lista;

	while (nodo_actual)
	{
		nodos++;
		nodo_actual = nodo_actual->next;
	}

	return nodos;
}

t_punto_acceso *nodo_head(t_punto_acceso *nodo)
{
	if (nodo == NULL)
		return NULL;
	
	while (nodo->prev)
		nodo = nodo->prev;
	
	return nodo;
}


t_punto_acceso *nodo_tail(t_punto_acceso *nodo)
{
	if (nodo == NULL)
		return NULL;
	
	while (nodo->next)
		nodo = nodo->next;
	
	return nodo;
}