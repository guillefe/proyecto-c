#ifndef _LISTAS_H
#define _LISTAS_H

#define CELL_STRING "Cell"
#define ADDRESS_STRING "Address"
#define ESSID_STRING "ESSID"
#define MODE_STRING "Mode"
#define CHANNEL_SRTING "Channel"
#define ENCRYPTION_STRING "Encryption key"
#define QUALITY_STRING "Quality"
#define FREQUENCY_STRING "Frequency"
#define SIGNAL_STRING "Signal level"
#define MAX_VALUE_LENGTH 50

typedef struct s_punto_acceso {
    int                     index;
    char 					id_cell[MAX_VALUE_LENGTH];
    char 					mac_address[MAX_VALUE_LENGTH];
    char 					essid[MAX_VALUE_LENGTH];
    char					mode[MAX_VALUE_LENGTH];
    char  		 			channel[MAX_VALUE_LENGTH];
    char  		 			encryption[MAX_VALUE_LENGTH];
    char  					quality[MAX_VALUE_LENGTH];
    char  		 			frequency[MAX_VALUE_LENGTH];
    char  		 			signal_level[MAX_VALUE_LENGTH];
	struct s_punto_acceso 	*next;
	struct s_punto_acceso 	*prev;
} t_punto_acceso;

t_punto_acceso *nuevo_nodo(void);
void agregar_nodo_fin_lista(t_punto_acceso **nodo_cabeza, t_punto_acceso *nodo_nuevo);
void liberar_lista(t_punto_acceso **nodo_cabeza);
void liberar_un_nodo(t_punto_acceso **nodo_cabeza, t_punto_acceso *nodo_eliminar);
int rellenar_nodo(t_punto_acceso *nodo, const char *linea);
void	vaciar_nodo(t_punto_acceso *nodo);
int comprobar_nodo(t_punto_acceso **lista, t_punto_acceso *nodo, int cell_file);
int	numero_nodos(t_punto_acceso **lista);
t_punto_acceso *nodo_head(t_punto_acceso *nodo);
t_punto_acceso *nodo_tail(t_punto_acceso *nodo);
#endif