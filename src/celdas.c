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

int check_cell(const char *str, int cell_file)
{
	if (str == NULL || cell_file == 0)
		return EXIT_FAILURE;

	int cell = atoi(str);
	return (cell == cell_file) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_address(const char *str)
{
	if (str == NULL)
		return EXIT_FAILURE;

	return (is_valid_mac(str) == EXIT_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_essid(const char *str)
{
	return (str != NULL) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_mode(const char *str)
{
	if (str == NULL)
		return EXIT_FAILURE;

	const char *valid_modes[] = {"Auto", "Ad-Hoc", "Managed", "Master", "Repeater", "Secondary", "Monitor", "Unknown"};
	for (int i = 0; i < sizeof(valid_modes) / sizeof(valid_modes[0]); i++)
	{
		if (strcmp(str, valid_modes[i]) == 0)
			return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}

int check_channel(const char *str)
{
	if (str == NULL)
		return EXIT_FAILURE;

	int channel = atoi(str);
	return (channel > 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_encryption(const char *str)
{
	if (str == NULL)
		return EXIT_FAILURE;

	return (strcmp(str, "on") == 0 || strcmp(str, "off") == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_quality(const char *str)
{
	if (str == NULL)
		return EXIT_FAILURE;

	int calidad_actual = atoi(str);
	if (calidad_actual <= 0)
		return EXIT_FAILURE;

	const char *barra = strchr(str, '/');
	if (barra == NULL || barra[1] == '\0')
		return EXIT_FAILURE;

	int calidad_maxima = atoi(barra + 1);
	return (calidad_maxima > 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_frequency(const char *str)
{
	if (str == NULL)
		return EXIT_FAILURE;

	float frecuencia = atof(str);
	return (frecuencia >= 2.4 && frecuencia <= 5.0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_signal(const char *str)
{
	if (str == NULL)
		return EXIT_FAILURE;

	int signal_level = atoi(str);
	return (signal_level >= -100 && signal_level <= 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}