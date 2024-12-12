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

void	fill_list(t_punto_acceso **lista, const char *info_cell_file)
{
	FILE *file = NULL;

	if (info_cell_file == NULL)
		return ;
	
	if (access(info_cell_file, F_OK) != 0)
		return ;
	
	file = fopen(info_cell_file, "r")
	if (file == NULL)
		return ;
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
		fill_list(lista, archivo_info_cell);

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

void wificollector_display(t_punto_acceso **lista){
    int celda_leer;

    printf("Indique el numero de la celda de la que desea conocer su informacion (1 - 21): \n");
    scanf("%d", &celda_leer);

    if (celda_leer > pos || celda_leer < 1){
        printf("La celda que ha seleccionado esta vacia. \n");
    } else{
        printf(celda_leer, celdas.id_cell[celda_leer - 1]);
    }
}

void wificollector_display_all(t_punto_acceso **lista){

   int obtener_valor_quality(const char *quality_str) {
    int valor = 0;
    sscanf(quality_str, "%d", &valor);
    return valor;
}

// Función para intercambiar dos elementos del array
void swap(celdas *a, celdas *b) {
    celdas temp = *a;
    *a = *b;
    *b = temp;
}

// Método para ordenar las celdas por calidad en orden decreciente
void wificollector_sort(t_punto_acceso **lista) {
    if (pos <= 1) {
        printf("No hay suficientes celdas para ordenar.\n");
        return;
    }

    // Bubble Sort
    for (int i = 0; i < pos - 1; i++) {
        for (int j = 0; j < pos - i - 1; j++) {
            int quality_j = obtener_valor_quality(puntero[j].quality);
            int quality_j1 = obtener_valor_quality(puntero[j + 1].quality);

            if (quality_j < quality_j1) {
                swap(&puntero[j], &puntero[j + 1]);
            }
        }
    }

    // Imprimir las celdas ordenadas
    printf("Celdas ordenadas por calidad (descendente):\n");
    for (int i = 0; i < pos; i++) {
        printf("Celda ID: %d\n", puntero[i].id_cell);
        printf("  Address: %s\n", puntero[i].address);
        printf("  ESSID: %s\n", puntero[i].essid);
        printf("  Mode: %s\n", puntero[i].mode);
        printf("  Channel: %d\n", puntero[i].Channel);
        printf("  encryption key: %s\n", puntero[i].encryption_key);
        printf("  Quality: %s\n", puntero[i].quality);
        printf("  Frequency: %.2f\n", puntero[i].frequency);
        printf("  Signal level: %d\n\n", puntero[i].signal_level);
    }
}

    }