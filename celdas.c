#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../incl/celdas.h"
#include "../incl/comandos.h"

// AQUI CREAMOS LA MEMORIA DINAMICA
celdas *puntero = NULL;
int numElementos = 0;
int pos = 0;

void iniciar_memoria(){
    puntero = (celdas*)malloc(5 * sizeof(celdas));

        if(puntero == NULL) {
            printf("Error al asignar memoria\n");
            exit(1);
        }
}
   
//----------------------------------------------

typedef struct{
    int primer_valor;
    char barra = '/';
    int segundo_valor;
} quality;

char *abrir_archivo_texto(int posicion_celda){
    char ruta_archivo[150] = "../info_celdas/info_cell_";
    char collect_2 = ".txt";
    strcat(ruta_archivo, posicion_celda);
    strcat(ruta_archivo, collect_2);

    return ruta_archivo;
}


void asignar_en_celda(int id_cell_aux, char address_aux[], char essid_aux[], char mode_aux[], int channel_aux, char encryption_key_aux[], int quality_aux[], float frecuency_aux, int signal_level_aux){

    pos++;

    if (pos%5 == 0){
        struct celdas *puntero= (struct celdas*) realloc(celdas, (pos + 5) *sizeof(celdas));
        celdas = puntero;
        }

    puntero[pos-1].id_cell = id_cell_aux;
    strcpy(puntero[pos-1].address, address_aux);
    strcpy(puntero[pos-1].essid, essid_aux);
    strcpy(puntero[pos-1].mode, mode_aux);
    puntero[pos-1].channel = channel_aux;
    strcpy[puntero[pos-1].encrypion_key, encryption_key_aux];
    strcpy(puntero[pos-1].quality, quality_aux);
    puntero[pos-1].frecuency = frecuency_aux;
    puntero[pos-1].signal_level = signal_level_aux;
}