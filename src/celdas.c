#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celdas.h"
#include "comandos.h"

// Función para validar una dirección MAC
int is_valid_mac(const char *mac) {
    // Verificar la longitud: debe ser exactamente 17 caracteres
    if (strlen(mac) != 17) {
        return EXIT_FAILURE;
    }

    // Verificar cada carácter
    for (int i = 0; i < 17; i++) {
        if (i % 3 == 2) {
            // Cada tercer carácter debe ser ':' o '-'
            if (mac[i] != ':' && mac[i] != '-') {
                return EXIT_FAILURE;
            }
        } else {
            // Los otros caracteres deben ser dígitos hexadecimales
            if (!isxdigit(mac[i])) {
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}