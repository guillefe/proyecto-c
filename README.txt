# **Recolector de Redes Inalámbricas** 

## Tabla de Contenidos

1. [Descripción](#descripción)
2. [Objetivo del Proyecto](#objetivo-del-proyecto)
3. [Requisitos](#requisitos)
4. [Entregas](#entregas)
5. [Instalación](#instalación)
6. [Uso](#uso)
7. [Contribuir](#contribuir)
8. [Licencia](#licencia)

---

## Descripción

**Recolector de Redes Inalámbricas** es una aplicación diseñada para recopilar y gestionar datos sobre redes inalámbricas detectadas por dispositivos móviles en espacios abiertos. El objetivo principal es ofrecer a los usuarios un conjunto de herramientas para analizar redes Wi-Fi, incluyendo operaciones como la recopilación de datos, visualización y procesamiento.

---

## Objetivo del Proyecto

El cliente SAUCEM S.L. solicita una aplicación robusta capaz de:

- Recopilar información sobre las redes inalámbricas detectadas.
- Procesar, almacenar y manejar la información relacionada con cada celda (punto de acceso).
- Ofrecer operaciones como ordenar, mostrar detalles, exportar/importar datos, etc.

La información recolectada incluirá campos como: Identificador de Celda, Dirección MAC, ESSID, Modo, Canal, Cifrado, y Calidad de la señal.

---

## Requisitos

### Requisitos del Cliente:

1. La aplicación se ejecuta desde un terminal de comandos.
2. Presenta un menú interactivo con operaciones.
3. Las operaciones deben ser robustas y manejar situaciones con entradas incorrectas.
4. El diseño debe considerar la orientación a celdas (puntos de acceso).
5. La aplicación debe guardar información de las redes en archivos binarios.

### Requisitos de la Empresa:

- **company_require_divided**: Código dividido en funciones agrupadas.
- **company_require_documented**: Documentación detallada para funciones, variables y estructuras.
- **company_require_gccclean**: Compilación sin errores ni advertencias con -Wall.
- **company_require_style**: Código ajustado a la Guía de Estilo de C.
- **company_require_noleaks**: Gestión correcta de memoria dinámica.
- **company_require_balanced**: Distribución equilibrada del trabajo en equipos.
- **company_require_working_in_teams**: Equipos de 2 personas.
- **company_require_your_program_compiles_and_executes_in_uc3m_labs_or_virtual_machines_provided**.

---

## Entregas

### Entrega 1 (10%)

- Implementación de las operaciones: `wificollector_quit`, `wificollector_collect`, `wificollector_display`, `wificollector_display_all`.
- Uso de arrays estáticos con tamaño máximo de 200.
- Tamaño máximo para cadenas de caracteres: 80.

### Entrega 2 (15%)

- Implementación de operaciones adicionales: `wificollector_sort`, usando arrays dinámicos inicializados con un tamaño de 5, incrementando en 5 elementos con `realloc()`.

### Entrega 3 (15%)

- Implementación con listas dinámicas y manejo correcto de liberación de memoria.

---

## Instalación

Para instalar y compilar la aplicación:

1. **Requisitos previos**:
   - Sistema operativo: [Linux/Mac/Windows]
   - Lenguaje de programación: C (C99 o superior)

2. **Instalación**:

   ```bash
   git clone https://github.com/usuario/recolector-redes.git
   cd recolector-redes
   make
