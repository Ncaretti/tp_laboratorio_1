#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utnInputs.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *archivo;
	int retorno = -1;

	archivo = fopen(path, "r+");

	if (archivo == NULL)
	{
		printf("Error, no se pudo abrir el archivo. Verifique si existe o si el archivo esta abierto.\n");
		system("pause");
	}
	else
	{
		retorno = 0;
		printf("El archivo se abrio con exito.\n");
		retorno = parser_EmployeeFromText(archivo, pArrayListEmployee);
	}

	fclose(archivo);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *archivo = NULL;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		printf("El archivo se abrio con exito\n");
		archivo = fopen(path, "rb");

		if (archivo != NULL)
		{
			if (!parser_EmployeeFromBinary(archivo, pArrayListEmployee))
			{
				retorno = 0;
			}
		}
	}
	else
	{
		printf("Error, no se pudo abrir el archivo. Verifique si existe o si el archivo esta abierto.\n");
	}

	fclose(archivo);
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee *pEmpleadoParametros;
	int retorno = -1;
	int respuesta = 1;
	int cantidadEmpleados;
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];

	if(pArrayListEmployee != NULL)
	{
		while (respuesta == 1)
		{
			cantidadEmpleados = ll_len(pArrayListEmployee);
			sprintf(id, "%d", cantidadEmpleados);

			printf("Ingrese el nombre del empleado: ");
			fflush(stdin);
			scanf("%[^\n]", nombre);

			printf("\nIngrese las horas trabajadas del empleado: ");
			fflush(stdin);
			scanf("%[^\n]", horasTrabajadas);

			printf("\nIngrese el sueldo del empleado: ");
			fflush(stdin);
			scanf("%[^\n]", sueldo);

			pEmpleadoParametros = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, pEmpleadoParametros);

			printf("*******************************************************\n");
			printf("¿Quiere ingresar otro empleado? 1(si)/2(no).\n");
			scanf("%d", &respuesta);
			system("cls");
		}
		retorno = 1;
	}
	else
	{
		printf("***************************************************\n");
		printf("Error, no se pueden ingresar empleados.\n");
		printf("***************************************************\n");
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int id;
	char nombre[120];
	int horasTrabajadas;
	int sueldo;
	int tamanioLista;
	Employee *listaEmpleados;
	tamanioLista = ll_len(pArrayListEmployee);

	for (i = 1; i < tamanioLista; i++)
		{
			listaEmpleados = (Employee*) ll_get(pArrayListEmployee, i);

			printf("%d\t %s\t %d\t %d\n", employee_getId(listaEmpleados, &id),
										  employee_getNombre(listaEmpleados, nombre),
										  employee_getHorasTrabajadas(listaEmpleados, &horasTrabajadas),
										  employee_getSueldo(listaEmpleados, &sueldo));
			}
	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	setbuf(stdout, NULL);
	int retorno = -1;
	int idIngresado;
	int respuesta;
	int respuestaSwitch;
	char nuevoNombre[50];
	int nuevoSueldo;
	int nuevoHorasTrabajadas;
	int respuestaWhile = 1;
	Employee *pEmpleado;

	while(respuestaWhile == 1)
	{
		printf("\n***************************************************************************\n");
		printf("Para ver la lista de empleados ingrese '1' si no desea verla ingrese '2': ");
		scanf("%d", &respuesta);

		if (respuesta == 1)
		{
			printf("*********************************************************\n");
			controller_ListEmployee(pArrayListEmployee);
			printf("*********************************************************\n");
		}

		printf("Ingrese el ID del empleado a modificar: ");
		scanf("%d", &idIngresado);

		if (pArrayListEmployee != NULL)
		{
			pEmpleado = ll_get(pArrayListEmployee, idIngresado);

				utn_getInt(&respuestaSwitch, "Elija una opcion: \n1_Modificar nombre\n2_Modificar sueldo\n3_Modificar horas trabajadas\n4_Salir", "Error, elija una opcion valida.\n", 1, 4, 2);

				switch (respuestaSwitch)
				{
					case 1:
						printf("\nIngrese el nuevo nombre: ");
						fflush(stdin);
						scanf("%[^\n]", nuevoNombre);
						employee_setNombre(pEmpleado, nuevoNombre);
						printf("\n*************************************\n");
						printf("Nombre modificado con exito.\n");
						printf("*************************************\n");
					break;

					case 2:
						utn_getInt(&nuevoSueldo, "Ingrese el nuevo sueldo: ", "Error, ingrese un sueldo valido.\n",1, 10000000, 2);
						employee_setSueldo(pEmpleado, nuevoSueldo);
						printf("\n*************************************\n");
						printf("Sueldo modificado con exito.\n");
						printf("*************************************\n");
					break;

					case 3:
						utn_getInt(&nuevoHorasTrabajadas, "Ingrese la nueva cantidad de horas trabajadas: ", "Error, ingrese una cantidad de horas validas.\n", 1, 10000, 2);
						employee_setHorasTrabajadas(pEmpleado, nuevoHorasTrabajadas);
						printf("\n*************************************\n");
						printf("Horas trabajadas modificadas con exito.\n");
						printf("*************************************\n");
					break;

					case 4:
						printf("\n*************************************\n");
						printf("Ha salido con exito.\n");
						printf("*************************************\n");
						system("pause");
					break;

				 }
				retorno = 1;
			}
			printf("¿Desea seguir editando? 1(si)/2(no)");
			scanf("%d", &respuestaWhile);
	}

		return retorno;
}




/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int tamanioLista;
	int idIngresado;
	int respuesta;
	Employee *puntero;

	printf("\n***************************************************************************\n");
	printf("Para ver la lista de empleados ingrese '1' si no desea verla ingrese '2': ");
	scanf("%d", &respuesta);

	if (respuesta == 1)
	{
		printf("*********************************************************\n");
		controller_ListEmployee(pArrayListEmployee);
		printf("*********************************************************\n");
	}

	printf("Ingrese el id al que quiere dar de baja: ");
	scanf("%d", &idIngresado);

	if (pArrayListEmployee != NULL)
	{
		tamanioLista = ll_len(pArrayListEmployee);
		if (idIngresado > 0 && idIngresado <= tamanioLista)
		{
			puntero = ll_get(pArrayListEmployee, idIngresado);
			free(puntero);
			ll_remove(pArrayListEmployee, idIngresado);

			printf("*********************************************************\n");
			printf("Se elimino correctamente\n");
			printf("*********************************************************\n");
			retorno = 1;
			system("pause");
			system("cls");
		}
		else
		{
			printf("*********************************************************\n");
			printf("Error, ingrese un id entre 1 y %d\n\n", tamanioLista);
			printf("*********************************************************\n");
			system("pause");
			system("cls");
		}
	}
	else
	{
		printf("*********************************************************\n");
		printf("Error, el empleado no se ha encontrado.\n");
		printf("*********************************************************\n");
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int subMenu;
	int tamanioLista;
	int respuestaSeguir = 0;

	if (pArrayListEmployee != NULL)
	{

		tamanioLista = ll_len(pArrayListEmployee);
		if (tamanioLista > 0)
		{
			do
			{

				do
				{
					system("cls");
					printf("****************************MENU****************************\n");
					printf("1. Ordenar por id.\n");
					printf("2. Ordenar por nombre.\n");
					printf("3. Ordenar por horas de trabajo.\n");
					printf("4. Ordenar por salario.\n");
					printf("5. Salir.\n");
					printf("****************************MENU****************************\n");
				}

				while (utn_getInt(&subMenu, "Ingrese una opcion: ","Error, ingrese una opcion valida.\n", 1, 5, 5) == -1);

				switch (subMenu)
				{
					case 1:
						do
						{
							system("cls");
							printf("****************************ID****************************\n");
							printf("1. Ordenar ascendente \n");
							printf("2. Ordenar descendente\n");
							printf("3. Salir.\n");
							printf("****************************ID****************************\n");
						}

						while (utn_getInt(&subMenu, "Ingrese una opcion: ","Error, ingrese una opcion valida.\n", 1, 5, 5) == -1);
						switch (subMenu)
						{
							case 1:
								ll_sort(pArrayListEmployee, employee_compareById,-1);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 2:
								ll_sort(pArrayListEmployee, employee_compareById,1);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 3:
							break;
						}
						break;

					case 2:
						do
						{
							system("cls");
							printf("****************************NOMBRE****************************\n");
							printf("1. Ordenar ascendente \n");
							printf("2. Ordenar descendente\n");
							printf("3. Salir.\n");
							printf("****************************NOMBRE****************************\n");
						}

						while (utn_getInt(&subMenu, "Ingrese una opcion: ","Error, ingrese una opcion valida.\n", 1, 5, 5) == -1);

						switch (subMenu)
						{
							case 1:
								ll_sort(pArrayListEmployee, employee_compareByNombre,1);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 2:
								ll_sort(pArrayListEmployee, employee_compareByNombre,0);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 3:
							break;
						}
						break;

					case 3:
						do
						{
							system("cls");
							printf("****************************HORAS TRABAJADAS****************************\n");
							printf("1. Ordenar ascendente \n");
							printf("2. Ordenar descendente\n");
							printf("3. Salir.\n");
							printf("****************************HORAS TRABAJADAS****************************\n");
						}
						while (utn_getInt(&subMenu, "Ingrese una opcion: ","Error, ingrese una opcion valida.\n", 1, 5, 5) == -1);
						switch (subMenu)
						{
							case 1:
								ll_sort(pArrayListEmployee,employee_compareByHorasTrabajadas, -1);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 2:
								ll_sort(pArrayListEmployee,employee_compareByHorasTrabajadas, 1);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 3:
							break;

						}
						break;

					case 4:

						do
						{
							system("cls");
							printf("****************************SUELDO****************************\n");
							printf("1. Ordenar ascendente \n");
							printf("2. Ordenar descendente\n");
							printf("3. Salir.\n");
							printf("****************************SUELDO****************************\n");
						}
						while (utn_getInt(&subMenu, "Ingrese una opcion: ","Error, ingrese una opcion valida.\n", 1, 5, 5) == -1);

						switch (subMenu)
						{
							case 1:
								ll_sort(pArrayListEmployee, employee_compareBySueldo, -1);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 2:
								ll_sort(pArrayListEmployee, employee_compareBySueldo, 1);
								controller_ListEmployee(pArrayListEmployee);
								system("pause");
							break;

							case 3:
							break;
						}
						break;

					case 5:
						printf("Ha salido del menu de ordenamiento.\n");
						respuestaSeguir = 1;
					break;
				}

				retorno = 0;
			}
			while (respuestaSeguir == 0);

		}
		else
		{
			printf("\nNo hay empleados para ordenar.\n");
			system("pause");
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *archivo;
	Employee *auxEmpleado;
	int retorno = -1;
	int tamanioLista;
	int i;

	tamanioLista = ll_len(pArrayListEmployee);

	archivo = fopen(path, "r+");

	if (archivo == NULL)
	{
		archivo = fopen(path, "w+");
	}

	if (tamanioLista > 0)
	{
		for (i = 0; i < tamanioLista; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			fprintf(archivo, "%d,%s,%d,%d\n", auxEmpleado->id,
											   auxEmpleado->nombre,
											   auxEmpleado->horasTrabajadas,
											   auxEmpleado->sueldo);
			retorno = 0;
		}
	}
	fclose(archivo);

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *archivo;
	Employee *auxEmpleado;
	int retorno = -1;
	int tamanioLista;
	int i;

	tamanioLista = ll_len(pArrayListEmployee);
	archivo = fopen(path, "r+b");

	if (archivo== NULL)
	{
		archivo = fopen(path, "w+b");
	}

	if (tamanioLista > 0)
	{
		for (i = 0; i < tamanioLista; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			fprintf(archivo, "%d,%s,%d,%d\n", auxEmpleado->id,
											   auxEmpleado->nombre,
											   auxEmpleado->horasTrabajadas,
											   auxEmpleado->sueldo);
		}
		retorno = 0;
	}

	fclose(archivo);
	return retorno;
}
