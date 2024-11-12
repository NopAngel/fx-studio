#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10


typedef struct {
    char key[50];

    char value[50];
} CacheEntry;


CacheEntry cache[CACHE_SIZE];
int cache_count = 0;


void cache_set(const char *key, const char *value) {

    if (cache_count < CACHE_SIZE) {
        strncpy(cache[cache_count].key, key, sizeof(cache[cache_count].key));

        strncpy(cache[cache_count].value, value, sizeof(cache[cache_count].value));

        cache_count++;

    } else {
        printf("Cache is full!\n");

    }
}

const char* cache_get(const char *key) {

    for (int i = 0; i < cache_count; i++) {
        if (strcmp(cache[i].key, key) == 0) {

            return cache[i].value;

        }

    }

    return NULL; 
}

int version_main() {

    cache_set("campo1", "valor1");

    const char *valor = cache_get("campo1");

    if (valor) {

        printf("Valor de campo1: %s\n", valor);

    } else {

        printf("Campo no encontrado\n");

    }
    return 0;
}