#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Operaciones.h"

//Declaración de funciones
void MostrarMenu(float, float, int, int, int);
int ErrorOpcion(int);
float IngresoOperando(void);
void MostrarResultados(float, float, float, float, float, float, int, int);
void MostrarCalculo(float, float);
void MostrarLoading(int);

int main(void)
{
    system("color 5B");

    setbuf(stdout,NULL);

    //Declaración de variables
    int opcion;
    float numA;
    float numB;
    float resultadoSuma = 0;
    float resultadoResta = 0;
    float resultadoDivide = 0;
    float resultadoMultiplica = 0;
    int resultadoFactorialA= 0;
    int resultadoFactorialB= 0;
    int flagA = 0;
    int flagB = 0;
    int flagYaCalculo = 0;
    int i = 0;
    int retornoErrorOpcion;
    char salir = 'n';

//-------------------------------------------------------------------------------------------------

    do{
        system("cls");
        //Muestro menú y obtengo la opción seleccionada
        MostrarMenu(numA, numB, flagA, flagB, flagYaCalculo);
        printf("                   Opcion: ");
        scanf("%d", &opcion);

        //Valido opción y la pido nuevamente en caso de error
        retornoErrorOpcion = ErrorOpcion(opcion);

        if (retornoErrorOpcion == 1) {
            MostrarMenu(numA, numB, flagA, flagB, flagYaCalculo);
            system("cls");
        }

        //Consulta antes de salir
        if (opcion == 5) {
                fflush(stdin);
                printf("\n             Esta seguro que desea salir?\n\n");
                printf("   Presione S para salir o N para continuar operando: ");
                scanf("%c", &salir);

                while (salir != 'n' && salir != 's') {
                    fflush(stdin);
                    printf("\n          ERROR. Ingrese una opcion valida: " );
                    scanf("%c", &salir);
                }
        }

        //Evaluo opciones
        switch(opcion) {

            //Ingreso de primer operando
            case 1:
                numA = IngresoOperando();
                flagA = 1;
                break;

            //Ingreso de segundo operando
            case 2:
                numB = IngresoOperando();
                flagB = 1;
                break;

            default:
                if (flagA == 1 && flagB == 1) {
                    switch(opcion) {
                        case 3:
                            system("cls");
                            MostrarCalculo(numA, numB);

                            //-----------Loading screen...
                            printf("\n                          Loading....               \n\n");

                            for (i = 0; i < 101; i++) {
                                MostrarLoading(i);
                                Sleep(25);
                            }

                            printf("\n\n            ¡Operaciones completadas con exito!              \n\n\n");

                            //-------------Fin loading screen

                            //Llamo a funciones y obtengo resultados
                            resultadoSuma = suma(numA, numB);
                            resultadoResta = resta(numA, numB);
                            resultadoDivide = division(numA, numB);
                            resultadoMultiplica = multiplicacion(numA, numB);

                            if (!(numA < 1 )) {
                                resultadoFactorialA = factorial(numA);
                            }

                            if (!(numB< 1 )) {
                                resultadoFactorialB = factorial(numB);
                            }

                            flagYaCalculo = 1;

                            system("pause");
                            system("cls");
                            break;

                        case 4:
                            if (flagYaCalculo == 1) {
                            system("cls");
                            MostrarResultados(numA ,numB, resultadoSuma, resultadoResta, resultadoDivide, resultadoMultiplica, resultadoFactorialA, resultadoFactorialB);
                            } else {
                                printf("\nAun no se ha realizado el calculo de las operaciones\n\n");
                            }

                            system("pause");
                            system("cls");
                            break;

                        default:
                            break;

                    } // Fin SWITCH

                } else if (opcion != 5 && retornoErrorOpcion == 0) {
                    printf("\nAntes de calcular, debe ingresar ambos operandos.\n\n");
                    system("pause");
                    system("cls");
                } // Fin IF
        } //Fin SWITCH

    } while(opcion != 5 || salir != 's');

    return 0;

} // Fin MAIN
//-------------------------------------------------------------------------------------------------
void MostrarMenu(float numA, float numB, int flagA, int flagB, int flagYaCalculo) {

    printf("********************************************************\n");
    printf("                       CALCULADORA                                      \n");
    printf("********************************************************\n\n");
    printf("                 Seleccione una opcion:                              \n\n");

    if (flagA == 1) {
        printf("  1. Ingresar el primer operando. (A = %.2f  )               \n", numA);
    } else {
        printf("  1. Ingresar el primer operando.  (A = NO INGRESADO )        \n");
    }

    if (flagB == 1) {
        printf("  2. Ingresar el segundo operando. (B = %.2f  )              \n", numB);
    } else {
        printf("  2. Ingresar el segundo operando. (B = NO INGRESADO )        \n");
    }

    if (flagYaCalculo == 1) {
        printf("  3. Calcular todas las operaciones: \n");
        printf("      a) Calcular la suma  (%.2f  + %.2f)  \n", numA, numB);
        printf("      b) Calcular la resta (%.2f - %.2f)\n", numA, numB);
        printf("      c) Calcular la division (%.2f / %.2f) \n", numA, numB);
        printf("      d) Calcular la multiplicacion (%.2f * %.2f) \n", numA, numB);
        printf("      e) Calcular el factorial (%d!) | (%d!)\n", (int)numA, (int)numB);
    } else {
        printf("  3. Calcular todas las operaciones: \n");
        printf("      a) Calcular la suma.                           \n");
        printf("      b) Calcular la resta. (A-B)                          \n");
        printf("      c) Calcular la division. (A/B)                       \n");
        printf("      d) Calcular la multiplicacion. (A*B)                 \n");
        printf("      e) Calcular el factorial. (A!)                       \n");
    }

    printf("  4. Informar resultados. \n");
    printf("  5. Salir.                                            \n");
    printf("                                                      \n");
    printf("********************************************************\n");

    }

int ErrorOpcion(int opcionCheck) {

    if (!(opcionCheck >= 1 && opcionCheck <= 5)) {
        printf("¡ERROR!\n");
        printf("%d no es una opcion valida\n", opcionCheck);
        fflush(stdin);
        system( "PAUSE" );
        return 1;
    }
    return 0;
}

float IngresoOperando(void) {

    float num;

    printf("                   Ingrese el operando: ");
    scanf("%f", &num);
    system("cls");

    return num;

}

void MostrarResultados(float num1, float num2, float resultadoSuma, float resultadoResta, float resultadoDivide, float resultadoMultiplica, int resultadoFactorialA, int resultadoFactorialB) {

    printf("********************************************************\n");
    printf("                       CALCULADORA                                      \n");
    printf("********************************************************\n\n");
    printf("                 Informe de resultados:                               \n \n" );
    printf("a) El resultado de %.2f + %.2f es: %.2f \n", num1, num2, resultadoSuma);
    printf("b) El resultado de %.2f - %.2f es: %.2f  \n", num1, num2, resultadoResta);

    if (num2 != 0) {
        printf("c) El resultado de %.2f / %.2f es: %.2f \n", num1, num2, resultadoDivide);
    }
    else {
        printf("c) El resultado de %.2f / %.2f es: No es posible dividir por cero\n", num1, num2);
    }

    printf("d) El resultado de %.2f * %.2f es: %.2f   \n", num1, num2, resultadoMultiplica);

    if (!(num1 < 1 )) {
        printf("e) El factorial de %d es       : %d \n", (int)num1, resultadoFactorialA);
    } else {
        printf("e) El factorial de %d es       : No es posible operar con 0 y/o negativos\n", (int)num1);
    }

    if(!(num2 < 1)) {
        printf(    "   El factorial de %d es       : %d  \n\n", (int)num2, resultadoFactorialB);
     }else {
        printf(    "   El factorial de %d es        : No es posible operar con 0 y/o negativos\n\n", (int)num2);
     }
    printf("********************************************************\n\n");
    }

void MostrarCalculo(float num1, float num2) {
    printf("********************************************************\n");
    printf("                       CALCULADORA                                      \n");
    printf("********************************************************\n\n");
    printf("              Calculando todas las operaciones...           \n\n");
    printf("      a) Calculando la suma...  (%.2f  + %.2f)  \n", num1, num2);
    printf("      b) Calculando la resta... (%.2f - %.2f)\n", num1, num2);
    printf("      c) Calculando la division... (%.2f / %.2f) \n", num1, num2);
    printf("      d) Calculando la multiplicacion... (%.2f * %.2f) \n", num1, num2);
    printf("      e) Calculando el factorial... (%d!) | (%d!)  \n\n\n", (int)num1, (int)num2);
    printf("********************************************************\n");
}

void MostrarLoading(int n) {

    int i;

    printf("             \r           ");

    for(i=0; i<34; i++) {
        printf("°");

        if(i == 16 && n !=100) {
            printf("%02d%%", n);
        }
    }

    printf("        \r           ");

    for(i=0; i<n/3; i++)  {
        printf("Û");

        if(i==16) {
            printf("%02d%%", n);
        }
    }
}

