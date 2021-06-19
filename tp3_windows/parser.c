#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int resultado;
	int i = 0;
	if (pFile == NULL)
	{
		printf("Error, no se pudo leer el archivo.");
	}
	else
	{
		char id[50], nombre[50], horasTrabajadas[50], sueldo[50];
		do
		{
			resultado = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);

			if (resultado == 4)
			{
				Employee *empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				i++;

				ll_add(pArrayListEmployee, empleado);
			}
			else
			{
			break;
			}

		} while (!feof(pFile));
	}
	return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee *pBinario;

	do
	{
		pBinario = employee_new();

		if (fread(pBinario, sizeof(Employee), 1, pFile) == 1)
		{
			ll_add(pArrayListEmployee, pBinario);
		}
		else
		{
			employee_delete(pBinario);
		}

	} while (!feof(pFile));


	return retorno;
}
