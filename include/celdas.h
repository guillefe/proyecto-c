#ifndef CELDAS_H
#define CELDAS_H

#define TRUE 1
#define FALSE 0

typedef enum e_mode
{
	mode_auto = 0,
	mode_ad_hoc,
	mode_managed,
	mode_master,
	mode_repeater,
	mode_secondary,
	mode_monitor,
	mode_unknown
} e_mode;

typedef enum e_encryptation
{
	encryptation_on = 0,
	encryptation_off
} e_encryptation;

typedef struct s_quality
{
	int	current_level;
	int	max_level;
} t_quality;

typedef struct s_punto_acceso {
    int 					id_cell;
    char 					mac_address[20];
    char 					essid[20];
    e_mode					mode;
    int 					channel;
    e_encryptation 			encryptation;
    t_quality				cuality;
    float 					frequency;
    int 					signal_level;
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