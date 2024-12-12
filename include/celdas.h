#ifndef CELDAS_H
#define CELDAS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "listas.h"
#include "comandos.h"

#define TRUE 1
#define FALSE 0

int opcion_de_menu;
struct celdas; 
struct quality;
char *abrir_archivo_texto;

void asignar_en_celda(int id_cell_aux, char address_aux[], char essid_aux[], char mode_aux[], int channel_aux, char encryption_key_aux[], char quality_aux[], float frecuency_aux, int signal_level_aux){

int contador_celdas = 0;
/**
 * @brief Verifica si la celda especificada coincide con el archivo de celda.
 *
 * @param str Cadena que representa la celda.
 * @param cell_file Entero que representa el archivo de celda.
 * @return EXIT_SUCCESS si la celda coincide, de lo contrario EXIT_FAILURE.
 */
int check_cell(const char *str, int cell_file);

/**
 * @brief Verifica si la dirección MAC es válida.
 *
 * @param str Cadena que representa la dirección MAC.
 * @return EXIT_SUCCESS si la dirección MAC es válida, de lo contrario EXIT_FAILURE.
 */
int check_address(const char *str);

/**
 * @brief Verifica si el ESSID no es nulo.
 *
 * @param str Cadena que representa el ESSID.
 * @return EXIT_SUCCESS si el ESSID no es nulo, de lo contrario EXIT_FAILURE.
 */
int check_essid(const char *str);

/**
 * @brief Verifica si el modo es válido.
 *
 * @param str Cadena que representa el modo.
 * @return EXIT_SUCCESS si el modo es válido, de lo contrario EXIT_FAILURE.
 */
int check_mode(const char *str);

/**
 * @brief Verifica si el canal es válido.
 *
 * @param str Cadena que representa el canal.
 * @return EXIT_SUCCESS si el canal es válido, de lo contrario EXIT_FAILURE.
 */
int check_channel(const char *str);

/**
 * @brief Verifica si la encriptación está activada o desactivada.
 *
 * @param str Cadena que representa el estado de la encriptación.
 * @return EXIT_SUCCESS si la encriptación es "on" o "off", de lo contrario EXIT_FAILURE.
 */
int check_encryption(const char *str);

/**
 * @brief Verifica la calidad de la señal.
 *
 * @param str Cadena que representa la calidad de la señal en el formato "actual/maxima".
 * @return EXIT_SUCCESS si la calidad es válida, de lo contrario EXIT_FAILURE.
 */
int check_quality(const char *str);

/**
 * @brief Verifica si la frecuencia está en el rango válido.
 *
 * @param str Cadena que representa la frecuencia.
 * @return EXIT_SUCCESS si la frecuencia está entre 2.4 GHz y 5.0 GHz, de lo contrario EXIT_FAILURE.
 */
int check_frequency(const char *str);

/**
 * @brief Verifica si el nivel de señal está en el rango válido.
 *
 * @param str Cadena que representa el nivel de señal en dBm.
 * @return EXIT_SUCCESS si el nivel de señal está entre -100 dBm y 0 dBm, de lo contrario EXIT_FAILURE.
 */
int check_signal(const char *str);
#endif