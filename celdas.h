#define CELDAS_H
#define CELDAS_H

typedef struct {
    int id_cell;
    char address[18];
    char essid[28];
    char mode[16];
    int Channel;
    char encryptation_key[5];
    char quality[28];
    float frequency;
    int signal_level;
} celdas;

int opcion_de_menu;
struct celdas; 
struct quality;
char *abrir_archivo_texto;

void asignar_en_celda(int id_cell_aux, char address_aux[], char essid_aux[], char mode_aux[], int channel_aux, char encryption_key_aux[], char quality_aux[], float frecuency_aux, int signal_level_aux){

int contador_celdas = 0;  