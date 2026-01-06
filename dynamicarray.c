#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_SIZE 2

int *vector_resize(int* old_array, size_t new_capacity) {
    
    int* new_array = realloc(old_array, new_capacity * sizeof(int));
    if(!new_array) {
        printf("Not enough memory to allocate the new vector size of %zu!\n", new_capacity);
        return NULL;
    }
    
    return new_array;
    
}

int main() {
    int *dynarray = NULL;  // Vector definition
    
    // Control variables
    size_t size = 0;
    float loadfactor = 0;
    size_t capacity = INITIAL_SIZE;

    // Vector capacity reservation
    dynarray = malloc(INITIAL_SIZE * sizeof(int));
    if(!dynarray) {
        printf("There not enought memory for the vector size requested!\n");
        return 1;
    }
    
    clock_t start = clock();

    for (size_t i = 0; i < 4294967296; i++) {        
        loadfactor = (float)size / capacity;
        if (loadfactor >= 0.7f) {
            size_t new_capacity = capacity * 2;
            int* new_array = vector_resize(dynarray, new_capacity);
            if (new_array == NULL) {
                printf("Not enough capacity to complete the task!\n");
                return 1;
            }
            else {
                dynarray = new_array;
                capacity = new_capacity;    
            }
        }
        
        dynarray[i] = i * 100;
        size++;
               
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nCapacity: %zu, Size: %zu\n", capacity, size);
    printf("\n=== VECTOR DINÁMICO COMPLETO ===\n");
    printf("Elementos totales: %zu\n", size);
    printf("Capacidad final: %zu\n", capacity);
    printf("Load factor final: %.2f\n", (float)size / capacity);
    printf("Tiempo total: %.3f segundos\n", time_taken);

    free(dynarray);
    dynarray = NULL; // Avoid dangling pointer

    return 0;
}