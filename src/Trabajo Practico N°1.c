/*
 ============================================================================
 Name        : Caretti, Nicolas
 Division    : 1B
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
  a) Calcular la suma (A+B)
  b) Calcular la resta (A-B)
  c) Calcular la division (A/B)
  d) Calcular la multiplicacion (A*B)
  e) Calcular el factorial (A!)
 4. Informar resultados
  a) “El resultado de A+B es: r”
  b) “El resultado de A-B es: r”
  c) “El resultado de A/B es: r” o “No es posible dividir por cero”
  d) “El resultado de A*B es: r”
  e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(void)
{
	int opcion;
	float operando1;
	float operando2;
	int flagOperando1;
	int flagOperando2;
	int flagModificar1;
	int flagModificar2;
	float reSuma;
	float reResta;
	float reDivision;
	float reMultiplicacion;
	float reFactorial1;
	float punteroFactorial2;

	flagOperando1 = 0;
	flagOperando2 = 0;
	flagModificar1 = 0;
	flagModificar2 = 0;


	setbuf(stdout, NULL);

	while(opcion != 5)
	{

		if(flagOperando1 == 0)
		{
			printf("1- Ingresar 1er operando\n");
		}
		else
		{
			printf("1- Ingresar 1er operando %.2f\n", operando1);
		}

		if(flagOperando2 == 0)
		{
			printf("2- Ingresar 2do operando\n");
		}
		else
		{
			printf("2- Ingresar 2do operando %.2f\n", operando2);
		}

		printf("3- Calcular todas las operaciones\n");
		printf("4- Informar resultados\n");
		printf("5- Salir\n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				printf("1er operando: ");
				scanf("%f", &operando1);
				flagOperando1 = 1;
				flagModificar1 = 1;
			break;

			case 2:
				printf("2do operando: ");
				scanf("%f", &operando2);
				flagOperando2 = 1;
				flagModificar2 = 1;
			break;

			case 3:
				if(flagOperando1 == 0 || flagOperando2 == 0)
				{
					printf("Error, ingrese los 2 numeros a calcular.\n\n");
					system ("pause");
				}
				else
				{
					flagModificar1 = 0;
					flagModificar2 = 0;

					printf("a) Calcular la suma (%.2f + %.2f)\n", operando1, operando2);
					reSuma = suma(operando1, operando2);

					printf("b) Calcular la resta (%.2f - %.2f)\n", operando1, operando2);
					reResta = resta(operando1, operando2);

					printf("c) Calcular la division (%.2f / %.2f)\n", operando1, operando2);
					reDivision = division(operando1, operando2);

					printf("d) Calcular la multiplicacion (%.2f * %.2f)\n", operando1, operando2);
					reMultiplicacion = multiplicacion(operando1, operando2);

					printf("e) Calcular el factorial (%.2f! y %.2f!)\n\n", operando1, operando2);
					reFactorial1 = factorial(operando1, operando2, &punteroFactorial2);

					system ("pause");


				}
			break;

			case 4:


				if(flagOperando1 == 0 || flagOperando2 == 0)
				{
					printf("Error, primero calcule las operaciones.\n\n");
					system ("pause");
				}
				else if(flagModificar1 == 1 || flagModificar2 == 1)
				{
					printf("Error, modifico algun operando, vuelva a calcular las operaciones.\n");
					system ("pause");
				}
				else
					{
					printf("a) El resultado de %.2f + %.2f es: %.2f\n", operando1, operando2, reSuma);

					printf("b) El resultado de %.2f - %.2f es: %.2f\n", operando1, operando2, reResta);

					if(reDivision == -1)
					{
						printf("c) Error, no se puede dividir por cero\n");
					}
					else
					{
						printf("c) El resultado de %.2f / %.2f es: %.2f\n", operando1, operando2, reDivision);
					}

					printf("d) El resultado de %.2f * %.2f es: %.2f\n", operando1, operando2, reMultiplicacion);

					printf("a) El factorial de %.f es %.f y el de %.f es %.f\n\n", operando1, reFactorial1, operando2, punteroFactorial2);

					system ("pause");
				}
			break;

			case 5:
				printf("Ha salido de la calculadora.");
			break;

			default:
				printf("Error, ingrese una opcion del 1 al 5.\n\n");
				system ("pause");
			break;
		}
	}

	return 0;
}
