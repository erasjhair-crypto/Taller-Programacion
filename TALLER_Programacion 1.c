#include<stdio.h>
#include<string.h>
#define n_productos 10
int main(int argc, char const *argv[])
{
    char nombres[n_productos][20];
    float valor[n_productos];
    int  productos=0, opc1, seguir=1,i;
    do
    {
        printf("\nCuantos productos desea ingresar? [Max 10]: ");
        scanf("%d",&productos);
        if (productos<=0 || productos>n_productos)
        {
            printf("\nNumero no valido (0-10), intente de nuevo");
        }
    } while (productos<=0 || productos>n_productos);
    for ( i = 0; i < productos; i++)
    {
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        scanf("%19s", nombres[i]);
        do{
            printf("\nIngrese el precio de %s (maximo 10): ", nombres[i]);
            scanf("%f", &valor[i]);
            if (valor[i] <= 0 || valor[i] > 10) {
                printf("\nNumero no valido (0-10), intente de nuevo");
            }
        } while (valor[i] <= 0 || valor[i] > 10);
    }

   
    

    do
    {
        printf("\n1. Calcular el precio total del inventario \n2. Encontrar el producto mas caro y el mas barato \n3. Calcular el precio promedio de todos los productos \n4. Buscar un producto por su nombre y mostrar su precio \n5. Salir \nIngrese una opcion: ");
        scanf("%d", &opc1);
        switch (opc1) {
            case 1: {
                float totalI = 0.0;
                for (i = 0; i < productos; i++) {
                    totalI += valor[i];
                }
                printf("\nEl precio total del inventario es: %.2f ", totalI);
                break;
            }
            case 2: {
                int mas_caro = 0,mas_barato = 0;
                for (i = 1; i < productos; i++) {
                    if (valor[i] > valor[mas_caro]) {
                        mas_caro = i;
                    }
                    if (valor[i] < valor[mas_barato]) {
                        mas_barato = i;
                    }
                }
                printf("\nProducto mas caro: %s (Precio: %.2f) ", nombres[mas_caro], valor[mas_caro]);
                printf("\nProducto mas barato: %s (Precio: %.2f) ", nombres[mas_barato], valor[mas_barato]);
                break;
            }
            case 3: {
                float suma = 0;
                for (i = 0; i < productos; i++) {
                    suma += valor[i];
                }
                float promedio = suma / productos;
                printf("\nEl precio promedio de los productos es: %.2f ", promedio);
                break;
            }
            case 4: {

                
                char buscar[20];
                int encontrado = -1;

                printf("\nIngrese el nombre del producto a buscar: ");
                
                scanf("%19s", buscar);

                for (i = 0; i < productos; i++) {
                    if (strcmp(nombres[i], buscar) == 0) {
                        encontrado = i;
                        break;
                    }
                }

                if (encontrado != -1) {
                    printf("\nProducto: %s cuesta: %.2f ", nombres[encontrado], valor[encontrado]);
                } else {
                    printf("\nProducto no encontrado en el inventario ");
                }
                break;
            }
            case 5:
                printf("\nFinalizando programa");
                seguir = 0;
                break;
            default:
                printf("\nOpcion no valida, intente de nuevo");
                break;
        }
    } while (seguir==1);
    return 0;
}



