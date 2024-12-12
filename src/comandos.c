#include "wificollector.h"

/**************************/
/* Funciones auxiliares
/**************************/
char *trim(char *str, const char *characters)
{
    char *end = NULL;
    int i;

    if (str == NULL)
        return NULL;

    // Trim leading characters
    while (*str != '\0')
    {
        if (strchr(characters, *str))
            str++;
        else
            break;
    }

    // If all characters are trimmed
    if (*str == '\0')
        return str;

    // Trim trailing characters
    end = str + strlen(str) - 1;
    while (end > str)
    {
        if (strchr(characters, *end))
            end--;
        else
            break;
    }

    // Null-terminate the string
    *(end + 1) = '\0';

    return str;
}

int	fill_list(t_punto_acceso **lista, const char *info_cell_file)
{
	FILE *file = NULL;
    t_punto_acceso *nodo = NULL;
    char buffer[1024];
    int rtrn;

	if (info_cell_file == NULL)
		return EXIT_FAILURE;
	
	if (access(info_cell_file, F_OK) != 0)
		return EXIT_FAILURE;
	
	file = fopen(info_cell_file, "r")
	if (file == NULL)
		return EXIT_FAILURE;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (strncmp(buffer, "Cell", 4) == 0)
        {
            if (nodo != NULL)
            {
                rtrn = comprobar_nodo(lista, nodo);
                if (rtrn == EXIT_FAILURE)
                    vaciar_nodo(nodo);
            }
            else
                agregar_nodo_fin_lista(lista, nodo);
            nodo = nuevo_nodo();
        }
        if (nodo != NULL)
        {
            rtrn = rellenar_nodo(nodo, buffer);
            if (rtrn == EXIT_FAILURE)
                vaciar_nodo(nodo);
        }

    }
    
    if (*lista == NULL)
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

/**************************/

int wificollector_quit()
{
    char respuesta;
    int quit = FALSE;

    while (1)
    {
        printf("Está seguro que desea salir del programa? [s/N]:\n");
        respuesta = getchar();

        if (respuesta == 's')
        {
            quit = TRUE;
            break;
        }
        else if (respuesta == 'N')
        {
            quit = FALSE;
            break;
        }
        else
            printf("El caracter introducido no es valido.\n");
    }

    return(quit);
}


void wificollector_collect(t_punto_acceso **lista)
{  
    int añadir_nodo = TRUE;
    int rtrn;
    int opcion;
	char opcion_char;
    char entrada[MAX_VALUE_LENGTH];
    char archivo_info_cell[MAX_VALUE_LENGTH];
	t_punto_acceso *nodo_actual;

	nodo_actual = *lista;

    while (añadir_nodo)
    {
		// Pregunta si se quiere recolectar
        while (TRUE)
        {
            printf("¿Qué celda quiere recolectar? (1-21): ");
            if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            {
                printf("\n");
                printf("Error al leer la entrada. Intentelo de nuevo\n");
                continue;
            }
            printf("\n");
            opcion = atoi(entrada);
            if ( opcion > 0 && opcion <= 21 )
                break;
            else
                printf("Error, opcion invalida\n");
        }

		// Se consigue el nombre del archivo
        snprintf(archivo_info_cell, MAX_VALUE_LENGTH, "info_cell_%d.txt", opcion);

		// Se rellena la lista con la informacion del archivo
		rtrn = fill_list(lista, archivo_info_cell);

		// Pregunta si se quiere cargar otro punto de acceso
		while (TRUE)
		{
			printf("¿Desea añadir otro punto de acceso? [s/N]: ");
			
			opcion_char = getchar();
			printf("\n");

			if (opcion_char == 's')
				break;
			else if (opcion_char == 'N')
			{
				añadir_nodo = FALSE;
				break;
			}
			else
				printf("Error al leer la entrada. Intentelo de nuevo\n");
		}
	}
}

void wificollector_display(t_punto_acceso **lista)
{

}

void wificollector_display_all(t_punto_acceso **lista)
{

}


// Método para ordenar las celdas por calidad en orden decreciente
int wificollector_sort(t_punto_acceso **lista)
{
    int cuenta_nodos = 0;
    char *mac_list = NULL;

    if (lista == NULL || *lista == NULL)
        return ;
    
    cuenta_nodos = numero_nodos(lista);
    mac_list = calloc(cuenta_nodos, 17 * sizeof(char *))
}