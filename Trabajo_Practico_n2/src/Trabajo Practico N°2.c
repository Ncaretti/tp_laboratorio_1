/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmpleados.h"
#include "UTN.h"

#define OCUPADO 1
#define VACIO 0
#define T 1000
#define S 3

void menuDeOpciones();

int main(void)
{
	setbuf(stdout, NULL);

	menuDeOpciones();

	return 0;
}

void menuDeOpciones()
{
	eEmpleado listaEmpleados[T];
	eSector listaSector[S] = { {1, "Sistemas"}, {2, "Economia"},{3, "Salud"}};
	int opcion;
	int retornoVacio;
	int retornoBaja;
	int index;
	float total;
	float promedio;
	int mayorAlPromedio;
	int empleados;

	retornoVacio = iniciarEmpleados(listaEmpleados, T);
	if (retornoVacio == 0) {
		iniciarEmpleados(listaEmpleados, T);
	} else {
		printf("Error, no se puede vaciar la lista");
	}

	do {
		printf("1.ALTAS\n");
		printf("2.BAJAS\n");
		printf("3.MODIFICAR\n");
		printf("4.INFORMAR\n");
		printf("5. SALIR\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			index = aniadirEmpleado(listaEmpleados, listaSector, S, T);
			if (index != -1) {
				printf("El empleado se ha cargado con exito.\n");
				printf("**********************************************\n");
			}
			else
			{
				printf("No hay mas lugar en la lista.");
				printf("**********************************************\n");

			}
		break;

		case 2:
			if ((empleados = recorrerEmpleados(listaEmpleados, T)) == -1) {
				printf("Error, no hay empleados dados de alta.\n");
				printf("**********************************************\n");
			}
			else
			{
				retornoBaja = bajaEmpleado(listaEmpleados, T, listaSector, S);
				if (retornoBaja != -1) {
					printf("Empleado dado de baja con exito.\n");
					printf("**********************************************\n");
				}
				else
				{
					printf(
							"No se encontro un empleado con ese ID o ya ha sido dado de baja.\n");
					printf(
							"*****************************************************************\n");
				}
			}

		break;

		case 3:
			if ((empleados = recorrerEmpleados(listaEmpleados, T)) == -1)
			{
				printf("Error, no hay empleados dados de alta.\n");
				printf("**********************************************\n");
			}
			else
			{
				modificarEmpleado(listaEmpleados, T, listaSector, S);
			}
		break;

		case 4:
			if ((empleados = recorrerEmpleados(listaEmpleados, T)) == -1)
			{
				printf("Error, no hay empleados dados de alta.\n");
				printf("**********************************************\n");
			}
			else
			{
				do
				{
					printf("1.Lista de empleados ordenado por apellido.\n");
					printf(
							"2.Total, promedio de los salarios y empleados que superan salario promedio.\n");
					printf("3.Volver al menu.\n");
					printf("Elija una opcion: ");
					scanf("%d", &opcion);

					switch (opcion)
					{
						case 1:
							ordenarPorApellido(listaEmpleados, T);
							listarEmpleadosConDescripcion(listaEmpleados, T,listaSector, S);
						break;

						case 2:
							total = totalSalarios(listaEmpleados, T);
							promedio = promedioSalarios(listaEmpleados, T);
							mayorAlPromedio = empleadosConSalarioMayorAlPromedio(listaEmpleados, T);

							if (total != 0)
							{
								printf("************************************************************************************************\n");
								printf("-La suma de todos los salarios da un total de: %.2f\n",total);
								printf("-El promedio por salario es de: %.2f\n",promedio);
								if (promedio != 0)
								{
									printf("-Cantidad de empleados con sueldo mayor al promedio: %d\n", mayorAlPromedio);
								}
								printf("************************************************************************************************\n");
							}
							else
							{
								printf("No hay empleados ingresados.");
								printf("**********************************************\n");
							}
						break;

						case 3:
							printf("Ha vuelto al menu con exito.\n");
							printf("**********************************************\n");
						break;

						default:
							printf("Error, elija una opcion valida\n");
							printf("**********************************************\n");
						break;
					}
				} while (opcion != 3);
			}
			break;

		case 5:
			printf("Ha salido con exito.");
		break;

		default:
			printf("Error, elija una opcion valida\n");
			printf("**********************************************\n");
		break;
		}
	} while (opcion != 5);
}
