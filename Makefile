# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -MMD
SRC_DIR = src
OBJ_DIR = obj
TARGET = wificollector
DEBUG_FLAGS = -g -O0

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
DEPS = $(OBJECTS:.o=.d)

# Reglas principales
all: $(TARGET)

# Regla para construir el ejecutable en modo normal
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Compilado con éxito: $(TARGET)"

# Regla para construir objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado: $<"

# Crear el directorio de objetos si no existe
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Limpiar compilaciones previas
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Limpieza completa"

# Regla para construir el ejecutable en modo depuración
debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

# Incluir dependencias generadas automáticamente
-include $(DEPS)

# Marcar reglas como PHONY
.PHONY: all clean debug
