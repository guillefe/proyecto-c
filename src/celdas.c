#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celdas.h"
#include "comandos.h"

// Funci�n para validar una direcci�n MAC
int is_valid_mac(const char *mac) {
    // Verificar la longitud: debe ser exactamente 17 caracteres
    if (strlen(mac) != 17) {
        return EXIT_FAILURE;
    }

    // Verificar cada car�cter
    for (int i = 0; i < 17; i++) {
        if (i % 3 == 2) {
            // Cada tercer car�cter debe ser ':' o '-'
            if (mac[i] != ':' && mac[i] != '-') {
                return EXIT_FAILURE;
            }
        } else {
            // Los otros caracteres deben ser d�gitos hexadecimales
            if (!isxdigit(mac[i])) {
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}