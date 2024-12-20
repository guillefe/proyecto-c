#ifndef _WIFICOLLECTOR_H
#define _WIFICOLLECTOR_H

#include "listas.h"
#include "celdas.h"

void mostrar_menu();
int wificollector_quit();
int wificollector_collect(t_punto_acceso **lista);
int wificollector_display(t_punto_acceso **lista);
void wificollector_display_all(t_punto_acceso **lista);
int wificollector_sort(t_punto_acceso **lista);

char   *get_input(const char *promt, char *buffer);

#endif