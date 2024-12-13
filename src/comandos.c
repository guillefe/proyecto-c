#include "wificollector.h"

/**************************/
/* Funciones auxiliares */
/**************************/

void imprimir_nodo(t_punto_acceso *nodo)
{
    if (nodo == NULL)
        return ;
    printf("Cell %s\n", nodo->id_cell);
    printf("Address: %s\n", nodo->mac_address);
    printf("ESSID: %s\n", nodo->essid);
    printf("Mode: %s\n", nodo->mode);
    printf("Channel: %s\n", nodo->channel);
    printf("Encryption_key: %s\n", nodo->encryption);
    printf("Quality: %s\n", nodo->quality);
}

int	fill_list(t_punto_acceso **lista, const char *info_cell_file, int id_file)
{
	FILE *file = NULL;
    t_punto_acceso *nodo = NULL;
    char buffer[1024];
    int rtrn;

	if (info_cell_file == NULL)
		return EXIT_FAILURE;
	
	if (access(info_cell_file, F_OK) != 0)
    {
        printf("No se pudo acceder al archivo: %s\n\n", info_cell_file);
		return EXIT_FAILURE;
    }
	
	file = fopen(info_cell_file, "r");
	if (file == NULL)
		return EXIT_FAILURE;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (strncmp(buffer, "Cell", 4) == 0)
        {
            if (nodo != NULL)
            {
                rtrn = comprobar_nodo(lista, nodo, id_file);
                if (rtrn == EXIT_FAILURE)
                {
                    vaciar_nodo(nodo);
                }
                else
                {
                    agregar_nodo_fin_lista(lista, nodo);
                    nodo = nuevo_nodo();
                }
            }
            else
                nodo = nuevo_nodo();
        }
        if (nodo != NULL)
        {
            rtrn = rellenar_nodo(nodo, buffer);
            if (rtrn == EXIT_FAILURE)
                vaciar_nodo(nodo);
        }
    }

    // Procesar el último nodo después de salir del bucle
    if (nodo != NULL)
    {
        rtrn = comprobar_nodo(lista, nodo, id_file);
        if (rtrn == EXIT_FAILURE)
        {
            vaciar_nodo(nodo);
            free(nodo);
        }
        else
        {
            agregar_nodo_fin_lista(lista, nodo);
        }
    }

    fclose(file);
    
    if (*lista == NULL)
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

/**************************/

int wificollector_quit()
{
    char respuesta[MAX_VALUE_LENGTH];
    int quit = FALSE;

    while (1)
    {
        printf("Está seguro que desea salir del programa? [s/N]: ");
        if (fgets(respuesta, sizeof(respuesta), stdin) == NULL)
        {
            printf("\n");
            printf("Error al leer la entrada. Intentelo de nuevo\n");
            return quit;
        }
        if (strlen(respuesta) == 2)
        {
            if (strncmp(respuesta, "s", 1) == 0)
            {
                quit = TRUE;
                break;
            }
            else if (strncmp(respuesta, "N", 1) == 0)
            {
                quit = FALSE;
                break;
            }
        }
        else
            printf("El valor introducido no es valido.\n\n");
    }
    printf("\n");
    return(quit);
}


int wificollector_collect(t_punto_acceso **lista)
{  
    int añadir_nodo = TRUE;
    int opcion;
    int rtrn;
    char entrada[MAX_VALUE_LENGTH];
    char archivo_info_cell[MAX_VALUE_LENGTH];

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
                return EXIT_FAILURE;
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
		rtrn = fill_list(lista, archivo_info_cell, opcion);
        (void)rtrn;

		// Pregunta si se quiere cargar otro punto de acceso
		while (TRUE)
		{
			printf("¿Desea añadir otro punto de acceso? [s/N]: ");
			if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            {
                printf("\n");
                printf("Error al leer la entrada. Intentelo de nuevo\n");
                return EXIT_FAILURE;
            }
			if (strlen(entrada) == 2)
            {
                if (strncmp(entrada, "s", 1) == 0)
                {
                    añadir_nodo = TRUE;
                    break;
                }
                else if (strncmp(entrada, "N", 1) == 0)
                {
                    añadir_nodo = FALSE;
                    break;
                }
                else
                    printf("Valor incorrecto\n");
            }
			else
				printf("Error al leer la entrada. Intentelo de nuevo\n");
		}
	}

    return EXIT_SUCCESS;
}

int wificollector_display(t_punto_acceso **lista)
{
    int display = TRUE;
    char cell_opt[MAX_VALUE_LENGTH];
    char again_opt[MAX_VALUE_LENGTH];
    t_punto_acceso *nodo_actual = NULL;

    if (lista == NULL || *lista == NULL)
    {
        printf("Error: La lista esta vacia\n\n");
        return EXIT_SUCCESS;
    }

    while (display)
    {
        while (TRUE)
        {
            printf("Indique el número de la celda de la que desea conocer su información (1 - 21): ");
            if (fgets(cell_opt, sizeof(cell_opt), stdin) == NULL)
            {
                printf("\n");
                printf("Error al leer la entrada. Intentelo de nuevo\n");
                return EXIT_FAILURE;
            }
            printf("\n");
            if (atoi(cell_opt) > 0 && atoi(cell_opt) <= 21)
                break;
            else
                printf("Error: Valor introducido invalido\n");
        }

        nodo_actual = *lista;
        while (nodo_actual)
        {
            if (strncmp(nodo_actual->id_cell, cell_opt, strlen(nodo_actual->id_cell)) == 0)
            {
                imprimir_nodo(nodo_actual);
                printf("\n");
            }
            nodo_actual = nodo_actual->next;
        }
        
		while (TRUE)
		{
			printf("¿Desea añadir otro punto de acceso? [s/N]: ");
            if (fgets(again_opt, sizeof(again_opt), stdin) == NULL)
            {
                printf("\n");
                printf("Error al leer la entrada. Intentelo de nuevo\n");
                return EXIT_FAILURE;
            }
            if (strlen(again_opt) == 2)
            {
                if (strncmp(again_opt, "s", 1) == 0)
                    break;
                else if (strncmp(again_opt, "N", 1) == 0)
                {
                    display = FALSE;
                    break;
                }
                printf("El caracter introducido no es valido\n");
            }
			else
				printf("Error, el valor introducido no es valido\n");
		}
    }
    return EXIT_SUCCESS;
}

void wificollector_display_all(t_punto_acceso **lista)
{
    t_punto_acceso *nodo_actual = NULL;

    if (lista == NULL || *lista == NULL)
    {
        printf ("Error: La lista esta vacia\n\n");
        return ;
    }
    
    nodo_actual = *lista;
    while (nodo_actual)
    {
        imprimir_nodo(nodo_actual);
        printf("\n");
        nodo_actual = nodo_actual->next;
    }
}


// Método para ordenar las celdas por calidad en orden decreciente
int wificollector_sort(t_punto_acceso **lista)
{
    int index = 1;
    t_punto_acceso *nodo_max_quality = NULL;
    t_punto_acceso *nodo_actual = NULL;

    if (lista == NULL || *lista == NULL)
        return EXIT_FAILURE;

    int cuenta_nodos = numero_nodos(lista);
    if (cuenta_nodos <= 0)
        return EXIT_FAILURE;


    while (index <= cuenta_nodos)
    {
        nodo_actual = *lista;
        nodo_max_quality = NULL;

        while (nodo_actual) {
            if (nodo_actual->index == 0) 
            {
                if (nodo_max_quality == NULL || atoi(nodo_actual->quality) > atoi(nodo_max_quality->quality))
                    nodo_max_quality = nodo_actual;
            }
            nodo_actual = nodo_actual->next;
        }

        if (nodo_max_quality) {
            nodo_max_quality->index = index;
            index++;
        }
    }

    index = 1;
    nodo_actual = *lista;
    while (nodo_actual)
    {
        if (index == nodo_actual->index)
        {
            imprimir_nodo(nodo_actual);
            printf("\n");
            nodo_actual = nodo_head(nodo_actual);
            index++;
        }
        else
            nodo_actual = nodo_actual->next;
    }

    nodo_actual = *lista;
    while (nodo_actual)
    {
        nodo_actual->index = 0;
        nodo_actual = nodo_actual->next;
    }

    return EXIT_SUCCESS;
}
