#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celdas.h"
#include "comandos.h"

void mostrar_menu(){
    printf("[2024] SUCEM S.L Recolector de redes inalambricas\n\n");
    printf ("[1]wificollector_quit\n");
    printf ("[2]wificollector_collect\n");
    printf ("[3]wificollector_show_data_one_network\n");
    printf ("[4]wificollector_select_best\n");
    printf ("[5]wificollector_delete_net\n");
    printf ("[6]wificollector_sort\n");
    printf ("[7]wificollector_export\n");
    printf ("[8]wificollector_import\n");
    printf ("[9]wificollector_display\n");
    printf ("[10]wificollector_display_all\n\n");
}

int obtener_opcion(void)
{
    char entrada[100];
    int opcion = -1;

    while (1)
    {
        printf ("Opcion elegida: ");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("Error al leer la entrada. Intentelo de nuevo\n");
            continue;
        }
        opcion = atoi(entrada);
        if ( opcion > 0 || opcion <= 10 )
            break;
        else
            printf("Error, opcion invalida\n");
        printf("\n");
    }

    return opcion;
}

void menu (){
    int opcion_de_menu;
    int quit = FALSE;
    t_punto_acceso *lista = NULL;

    while (quit == FALSE)
    {
        mostrar_menu();
        opcion_de_menu = obtener_opcion();
        switch (opcion_de_menu) {
            case 1:
                quit = wificollector_quit();
                break;
            case 2:
                wificollector_collect();
                break;
            case 6:
                wificollector_sort();
                break;
            case 9:
                wificollector_display();
                break;
            case 10:
                wificollector_display_all();
                break;
            default:
                printf("Este metodo todavia no esta implementado.\n");
            printf("Seleccione una opcion entre: [1],[2],[9],[10]\n");
        }
    }
}

int main(int argc, char* argv[]){
    menu();
    return 0;
}