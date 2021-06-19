#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{
	Employee *persona = malloc(sizeof(Employee));
	return persona;
}

void employee_delete(Employee *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	int idAux;
	int sueldoAux;
	int horasAux;

	Employee *empleado = employee_new();
	idAux = atoi(idStr);
	sueldoAux = atoi(sueldo);
	horasAux = atoi(horasTrabajadasStr);

	employee_setId(empleado, idAux);
	employee_setNombre(empleado, nombreStr);
	employee_setSueldo(empleado, sueldoAux);
	employee_setHorasTrabajadas(empleado, horasAux);

	return empleado;
}

//---------------------------------SETTERS----------------------------------------

int employee_setId(Employee *this, int id)
{
	int retorno = 1;

	if (id > 0)
	{
		this->id = id;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int employee_setNombre(Employee *this, char *nombre)
{
	int retorno = 1;

	if (nombre[0] != '\0')
	{
		strncpy(this->nombre, nombre, sizeof(this->nombre));
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo)
{
	int retorno = 1;

	if (sueldo > 0)
	{
		this->sueldo = sueldo;
	}
	else
	{
		retorno = -1;
	}


	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
	int retorno = 1;

	if (horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//---------------------------------GETTERS----------------------------------------

int employee_getId(Employee *this, int *id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = this->id;
	}
	return retorno;
}

char* employee_getNombre(Employee *this, char* nombre)
{
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
	}
	return nombre;
}

int employee_getSueldo(Employee *this, int* sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = this->sueldo;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = this->horasTrabajadas;
	}
	return retorno;
}

//---------------------------------COMPARES----------------------------------------

int employee_compareById(void* empleado1, void* empleado2)
{
	//0 Si son iguales, 1 Si son mayores, -1 Si son menores
	int resultado = 0;
	Employee* vEmpleado1 = NULL;
	Employee* vEmpleado2 = NULL;
	int id1;
	int id2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		vEmpleado1 = (Employee*) empleado1;
		vEmpleado2 = (Employee*) empleado2;

		employee_getId(vEmpleado1, &id1);
		employee_getId(vEmpleado2, &id2);

			if(id1 > 1 && id2 > 1)
			{
				//printf("%d\n", id1);
				//printf("%d\n", id2);

				if(id1 > id2)
				{
					resultado = 1;
				}
				else
				{
					if(id1 < id2)
					{
						resultado = -1;
					}
				}
			}
			//printf("%d\n", resultado);
	}

	return resultado;
}

int employee_compareByNombre(void* empleado1, void* empleado2)
{
	int resultado = 0;
	Employee* vEmpleado1 = NULL;
	Employee* vEmpleado2 = NULL;
	char nombre1[120];
	char nombre2[120];

	if(empleado1!=NULL && empleado2!=NULL)
	{
		vEmpleado1 = (Employee*) empleado1;
		vEmpleado2 = (Employee*) empleado2;

		employee_getNombre(vEmpleado1, nombre1);
		employee_getNombre(vEmpleado2, nombre2);

		if((!employee_getNombre(vEmpleado1,nombre1)) && (!employee_getNombre(vEmpleado2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}
	return resultado;
}

int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	//0 Si son iguales, 1 Si son mayores, -1 Si son menores
	int resultado = 0;
	Employee* vEmpleado1 = NULL;
	Employee* vEmpleado2 = NULL;
	int horas1;
	int horas2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		vEmpleado1 = (Employee*) empleado1;
		vEmpleado2 = (Employee*) empleado2;

		employee_getHorasTrabajadas(vEmpleado1, &horas1);
		employee_getHorasTrabajadas(vEmpleado2, &horas2);

		if(horas1 > 1 && horas2 > 1)
		{
			//printf("%d\n", sueldo1);
			//printf("%d\n", sueldo2);
			if(horas1 > horas2)
			{
				resultado = 1;
			}
			else
			{
				if(horas1 < horas2)
				{
					resultado = -1;
				}
			}
		}
		//printf("%d\n", resultado);
	}

	return resultado;
}

int employee_compareBySueldo(void* empleado1, void* empleado2)
{
	//0 Si son iguales, 1 Si son mayores, -1 Si son menores
	int resultado = 0;
	Employee* vEmpleado1 = NULL;
	Employee* vEmpleado2 = NULL;
	int sueldo1;
	int sueldo2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		vEmpleado1 = (Employee*) empleado1;
		vEmpleado2 = (Employee*) empleado2;

		employee_getSueldo(vEmpleado1, &sueldo1);
		employee_getSueldo(vEmpleado2, &sueldo2);

		if(sueldo1 > 1 && sueldo2 > 1)
		{
			//printf("%d\n", sueldo1);
			//printf("%d\n", sueldo2);
			if(sueldo1 > sueldo2)
			{
				resultado = 1;
			}
			else
			{
				if(sueldo1 < sueldo2)
				{
					resultado = -1;
				}
			}
		}
		//printf("%d\n", resultado);
	}

	return resultado;
}
