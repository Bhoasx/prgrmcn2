#include <stdio.h>
#include <string.h>

#define MAX_PRODUC 100
#define MAX_NOMBRE 50

// DeclaraciÃ³n de arreglos para manejar los datos de los productos
char nombre_prod[MAX_PRODUC][MAX_NOMBRE];
int tiempo_produccion[MAX_PRODUC];
int costo_recursos[MAX_PRODUC];
int demanda[MAX_PRODUC];
int contador = 0;

void agg_prod() {
    printf("================================================\n");
    if (contador >= MAX_PRODUC) {
        printf("\nNo se pueden agregar mas productos. Se alcanzo el limite maximo.\n");
        return;
    }

    printf("\nIngrese el nombre del producto: ");
    scanf(" %s", nombre_prod[contador]);
    printf("Ingrese el tiempo de produccion (por unidad): ");
    scanf("%d", &tiempo_produccion[contador]);
    printf("Ingrese el costo de recursos (por unidad): ");
    scanf("%d", &costo_recursos[contador]);
    printf("Ingrese la demanda (unidades): ");
    scanf("%d", &demanda[contador]);

    contador++;
    printf("\nProducto agregado exitosamente!\n");
    printf("================================================\n");
}

void edit_product() {
    printf("================================================\n");
    char search_name[MAX_NOMBRE];
    printf("\nIngrese el nombre del producto a editar: ");
    scanf(" %s", search_name);

    for (int i = 0; i < contador; i++) {
        if (strcmp(nombre_prod[i], search_name) == 0) {
            printf("\nEditando producto: %s\n", nombre_prod[i]);
            printf("Ingrese el nuevo nombre: ");
            scanf(" %s", nombre_prod[i]);
            printf("Ingrese el nuevo tiempo de produccion (por unidad): ");
            scanf("%d", &tiempo_produccion[i]);
            printf("Ingrese el nuevo costo de recursos (por unidad): ");
            scanf("%d", &costo_recursos[i]);
            printf("Ingrese la nueva demanda (unidades): ");
            scanf("%d", &demanda[i]);

            printf("\nProducto actualizado exitosamente!\n");
            printf("================================================\n");
            return;
        }
    }

    printf("\nProducto no encontrado.\n");
}

void elimin_product() {
    printf("================================================\n");
    char search_name[MAX_NOMBRE];
    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf(" %s", search_name);

    for (int i = 0; i < contador; i++) {
        if (strcmp(nombre_prod[i], search_name) == 0) {
            for (int j = i; j < contador - 1; j++) {
                strcpy(nombre_prod[j], nombre_prod[j + 1]);
                tiempo_produccion[j] = tiempo_produccion[j + 1];
                costo_recursos[j] = costo_recursos[j + 1];
                demanda[j] = demanda[j + 1];
            }
            contador--;
            printf("\nProducto eliminado exitosamente!\n");
            printf("================================================\n");
            return;
        }
    }

    printf("\nProducto no encontrado.\n");
}

void calcular_requeri(int tiempo_dispo, int recursos_dispo) {
    printf("================================================\n");
    if (contador == 0) {
        printf("\nNo hay productos disponibles.\n");
        return;
    }

    int total_time = 0;
    int total_resources = 0;

    for (int i = 0; i < contador; i++) {
        total_time += tiempo_produccion[i] * demanda[i];
        total_resources += costo_recursos[i] * demanda[i];
    }

    printf("\nTiempo total requerido: %d unidades\n", total_time);
    printf("Recursos totales requeridos: %d unidades\n", total_resources);

    if (total_time <= tiempo_dispo && total_resources <= recursos_dispo) {
        printf("\nLa fabrica puede cumplir con la demanda dentro de los limites disponibles.\n");
    } else {
        printf("\nLa fabrica no puede cumplir con la demanda con los limites disponibles.\n");
    }
    printf("================================================\n");
}

void imprimir_prod() {
    printf("================================================\n");
    if (contador == 0) {
        printf("\nNo hay productos disponibles.\n");
        return;
    }

    printf("\nProductos actuales:\n");
    printf("\nProducto         Nombre                      T-Prod               Costo              Demanda\n");
    for (int i = 0; i < contador; i++) {
        printf("   %d          %s                          %d                   %d                 %d\n", i + 1, nombre_prod[i], tiempo_produccion[i], costo_recursos[i], demanda[i]);
    }
    printf("================================================\n");
}

int main() {
    int opcion;
    int tiempo_dispo, recursos_dispo;

    printf("\nIngrese el tiempo de produccion disponible: ");
    scanf("%d", &tiempo_dispo);
    printf("Ingrese los recursos disponibles: ");
    scanf("%d", &recursos_dispo);

    do {
        printf("\n--- Menu de Optimizacion de Produccion ---\n");
        printf("1. Agregar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Mostrar Productos\n");
        printf("5. Calcular Requerimientos\n");
        printf("6. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agg_prod();
                break;
            case 2:
                edit_product();
                break;
            case 3:
                elimin_product();
                break;
            case 4:
                imprimir_prod();
                break;
            case 5:
                calcular_requeri(tiempo_dispo, recursos_dispo);
                break;
            case 6:
                printf("\nSaliendo del programa.\n");
                break;
            default:
                printf("\nOpcion invalida. Por favor intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}
