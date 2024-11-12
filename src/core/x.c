#include <stdio.h>
#include <string.h>

void guardar_en_archivo(const char *ruta, const char *mensaje) {
    FILE *archivo = fopen(ruta, "a"); // Abre el archivo en modo append
    if (archivo != NULL) {
        fprintf(archivo, "%s\n", mensaje); // Escribe el mensaje en el archivo
        fclose(archivo); // Cierra el archivo
    } else {
        perror("Error al abrir el archivo"); // Manejo de errores
    }
}

void guardar_en_log(const char *mensaje) {
    guardar_en_archivo("registro.log", mensaje); // Guarda el mensaje en el archivo .log
}

// Nueva función para eliminar un mensaje específico
void eliminar_mensaje(const char *ruta, const char *mensaje) {
    FILE *archivo = fopen(ruta, "r");
    FILE *temp = fopen("temp.txt", "w"); // Archivo temporal
    char linea[256];

    if (archivo != NULL && temp != NULL) {
        while (fgets(linea, sizeof(linea), archivo)) {
            if (strcmp(linea, mensaje) != 0) {
                fputs(linea, temp); // Escribe solo las líneas que no coinciden
            }
        }
        fclose(archivo);
        fclose(temp);
        remove(ruta); // Elimina el archivo original
        rename("temp.txt", ruta); // Renombra el archivo temporal
    } else {
        perror("Error al abrir el archivo"); // Manejo de errores
    }
}

// Nueva función para editar un mensaje específico
void editar_mensaje(const char *ruta, const char *mensaje_viejo, const char *mensaje_nuevo) {
    FILE *archivo = fopen(ruta, "r");
    FILE *temp = fopen("../cache/temp.txt", "w"); // Archivo temporal
    char linea[256];

    if (archivo != NULL && temp != NULL) {
        while (fgets(linea, sizeof(linea), archivo)) {
            if (strcmp(linea, mensaje_viejo) == 0) {
                fputs(mensaje_nuevo, temp); // Escribe el nuevo mensaje
            } else {
                fputs(linea, temp); // Escribe la línea original
            }
        }
        fclose(archivo);
        fclose(temp);
        remove(ruta); // Elimina el archivo original
        rename("../cache/temp.txt", ruta); // Renombra el archivo temporal
    } else {
        perror("Error al abrir el archivo"); // Manejo de errores
    }
}

// Ejemplo de uso
int main() {
    guardar_en_archivo("archivo.txt", "Este es un mensaje en archivo.txt");
    guardar_en_log("Este es un mensaje en registro.log");

    // Ejemplo de eliminación
    eliminar_mensaje("archivo.txt", "Este es un mensaje en archivo.txt");

    // Ejemplo de edición
    editar_mensaje("registro.log", "Este es un mensaje en registro.log", "Mensaje editado en registro.log");

    return 0;
}