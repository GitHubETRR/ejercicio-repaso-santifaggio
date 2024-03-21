#include <stdio.h>

#define CANT_CORREDORES 5
#define CANT_MAX_LETRAS 50


typedef struct {
    char nombre[CANT_MAX_LETRAS];
    char nacionalidad[CANT_MAX_LETRAS];
    unsigned int titulos; 
} corredor;


corredor INGRESAR_DATOS(corredor persona);
void PROCESAR_DATOS(corredor persona[], int cantidad);
void MOSTRAR_DATOS(corredor persona[], int cantidad);
void MOSTRAR_OPCIONES(void);


int main(void) {
    corredor persona[CANT_CORREDORES];
    for (int i = 0; i < CANT_CORREDORES; i++)
        persona[i].titulos = 0; 
        

    unsigned int corredoresIngresados = 0;
    printf("menu\n");
    int opcionElegida;

    do {
        MOSTRAR_OPCIONES();
        printf("opción elegida: ");
        scanf("%i", &opcionElegida);
        while (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3) {
            printf("elegir de nuevo entre 1, 2 o 3\n");
            printf("opción elegida: ");
            scanf("%i", &opcionElegida);
        }

        switch (opcionElegida) {
            case 1:
                persona[corredoresIngresados] = INGRESAR_DATOS(persona[corredoresIngresados]);
                corredoresIngresados++;
                break;

            case 2:
                MOSTRAR_DATOS(persona, corredoresIngresados);
                PROCESAR_DATOS(persona, corredoresIngresados); // Cambio de "salario" a "titulos"
                break;
        }

    } while (opcionElegida != 3);
    return 0;
}

corredor INGRESAR_DATOS(corredor persona) {
    printf("escribir el nombre del corredor: ");
    scanf("%s", persona.nombre);
    printf("escribir la nacionalidad del corredor: ");
    scanf("%s", persona.nacionalidad);
    printf("escribir la cantidad de títulos del corredor: ");
    scanf("%u", &persona.titulos);
    return persona;
}

void PROCESAR_DATOS(corredor persona[], int cantidad) {
    unsigned int promedio = 0;
    unsigned int maximo = 0;
    for (int i = 0; i < cantidad; i++) {
        if (persona[i].titulos > persona[maximo].titulos) {
            maximo = i;
        }
        promedio += persona[i].titulos;
    }
    promedio /= cantidad;
    printf("%s tiene la mayor cantidad de títulos de rally con: %u\n", persona[maximo].nombre, persona[maximo].titulos);
    printf("el promedio de títulos de todos los corredores es: %u\n", promedio);
}

void MOSTRAR_DATOS(corredor persona[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("%i. NOMBRE: %s, NACIONALIDAD: %s, TÍTULOS: %u\n", i + 1, persona[i].nombre, persona[i].nacionalidad, persona[i].titulos);
    }
}

void MOSTRAR_OPCIONES(void) {
    printf("1: escribir los datos de un corredor\n");
    printf("2: mostrar los datos y procesar la info\n");
    printf("3: salir del programa\n");
}
