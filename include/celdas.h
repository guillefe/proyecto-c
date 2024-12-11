#ifndef CELDAS_H
#define CELDAS_H

#define TRUE 1
#define FALSE 0
#define MAX_VALUE_LENGTH 20

typedef struct s_punto_acceso {
    char 					id_cell[MAX_VALUE_LENGTH];
    char 					mac_address[MAX_VALUE_LENGTH];
    char 					essid[MAX_VALUE_LENGTH];
    char					mode[MAX_VALUE_LENGTH];
    char  		 			channel[MAX_VALUE_LENGTH];
    char  		 			encryptation[MAX_VALUE_LENGTH];
    char  					quality[MAX_VALUE_LENGTH];
    char  		 			frequency[MAX_VALUE_LENGTH];
    char  		 			signal_level[MAX_VALUE_LENGTH];
	struct s_punto_acceso 	*next;
	struct s_punto_acceso 	*prev;
} t_punto_acceso;

int opcion_de_menu;
struct celdas; 
struct quality;
char *abrir_archivo_texto;

void asignar_en_celda(int id_cell_aux, char address_aux[], char essid_aux[], char mode_aux[], int channel_aux, char encryption_key_aux[], char quality_aux[], float frecuency_aux, int signal_level_aux){

int contador_celdas = 0;
#endif