#include <stdio.h>
#include <stdlib.h>
#include <celdas.h>
#include "celdas.h"
#include "comandos.h"





int wificollector_quit(){

    printf("Está seguro que desea salir del programa? [s/N]:\n");
    char respuesta = getchar();

    if (respuesta == 's' || respuesta == 'S'){
        return 0;
    } else if (respuesta == 'n' || respuesta == 'N'){
        mostrar_menu();
    }else {
        printf("El caracter introducido no es valido.\n");
        wificollector_quit();
    }
}


void wificollector_collect(){
    char *opcion_elegida;
    int posicion_celda;
    int n=0

    printf("¿Que celda quiere recolectar? (1-21): \n");
        scanf("%d", &posicion_celda);
        opcion_elegida = abrir_archivo_texto(posicion_celda);
        FILE *puntero = fopen(opcion_elegida, "r");
        free(opcion_elegida);

        int id_cell_aux;
        char address_aux[18];
        char essid_aux[28];
        char mode_aux[16];
        int channel_aux;
        char encryptation_key_aux[5];
        int quality_aux[28];
        float frequency_aux;
        int signal_level_aux;

        while (fscanf(puntero, "Cell %d\n", &id_cell_aux) == 1){

            fscanf(puntero, "Address: %17d\n", address_aux);
            fscanf(puntero, "ESSID: %27[^\n]\n", essid_aux);
            fscanf(puntero, "Mode: %15s\n", mode_aux);
            fscanf(puntero, "Channel: %d\n", channel_aux);
            fscanf(puntero, "Encryptation key: %4c\n", encyptation_key_aux);
            fscanf(puntero, "Quality= %27d\n", quality_aux);
            fscanf(puntero, "Frequency: %f\n", frecuency_aux);
            fscanf(puntero, "Signal level: %d\n", signal_level_aux);

            asignar_en_celda(id_cell_aux, address_aux, essid_aux, mode_aux, channel_aux, encryption_key_aux, quality_aux, frecuency_aux, signal_level_aux);

        }

    while(n=1){
    printf("¿Desea a~nadir otro punto de acceso? [s/N]: \n");
        scanf("%c", &opcion_elegida);
        if (opcion_elegida = 's' || opcion_elegida = 'S'){
            wificollector_collect();
        } else if (opcion_elegida = 'n' || opcion_elegida = 'N'){
            mostrar_menu();
        } else (
            printf("El caracter no es valido\n");
        )
    }

}

void wificollector_display(){
    int celda_leer;

    printf("Indique el numero de la celda de la que desea conocer su informacion (1 - 21): \n");
    scanf("%d", &celda_leer);

    if (celda_leer > pos || celda_leer < 1){
        printf("La celda que ha seleccionado esta vacia. \n");
    } else{
        printf(celda_leer, celdas.id_cell[celda_leer - 1]);
    }
}

void wificollector_display_all(){

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
void wificollector_sort() {
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
        printf("  Encryptation key: %s\n", puntero[i].encryptation_key);
        printf("  Quality: %s\n", puntero[i].quality);
        printf("  Frequency: %.2f\n", puntero[i].frequency);
        printf("  Signal level: %d\n\n", puntero[i].signal_level);
    }
}

    }