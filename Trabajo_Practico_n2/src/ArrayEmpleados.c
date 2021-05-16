#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "UTN.h"
#define OCUPADO 1
#define VACIO 0

int iniciarEmpleados(eEmpleado* listaEmpleados, int tam)
{
	int i;
	int retornoVacio = -1;

	for(i=0; i<tam; i++)
	{
	    listaEmpleados[i].isEmpty = VACIO;
	    retornoVacio = 0;
	}

	return retornoVacio;
}

eEmpleado AltaEmpleado(eSector* listaSector, int tamSector)
{
	eEmpleado miEmpleado;

		printf("Ingrese el ID: ");
		scanf("%d", &miEmpleado.id);

		printf("Ingrese el nombre del empleado: ");
		fflush(stdin);
		scanf("%[^\n]", miEmpleado.nombre);

		printf("Ingrese el apellido del empleado: ");
		fflush(stdin);
		scanf("%[^\n]", miEmpleado.apellido);

		utn_getNumeroFlotante(&miEmpleado.salario, "Ingrese el salario del empleado: ", "Error, ingrese un salario valido\n", 1, 9999999, 2);

		mostrarSectores(listaSector, tamSector);
		printf("Ingrese el sector del empleado: ");
		scanf("%d", &miEmpleado.sector);
		if(miEmpleado.sector < 1 || miEmpleado.sector > 3)
		{
			while(miEmpleado.sector < 1 || miEmpleado.sector > 3)
			{
				mostrarSectores(listaSector, tamSector);
				printf("Error, ingresa un sector valido.");
				scanf("%d", &miEmpleado.sector);
			}
		}

		miEmpleado.isEmpty = OCUPADO;


	return miEmpleado;
}

int aniadirEmpleado(eEmpleado* listaEmpleados, eSector* listaSector, int tamSector, int tam)
{
	int i;
	    i = buscarLibre(listaEmpleados, tam);
	    if(i!=-1)
	    {
	        listaEmpleados[i] = AltaEmpleado(listaSector, tamSector);
	    }
	return i;
}

int encontrarEmpleadoPorID(eEmpleado* listaEmpleados, int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaEmpleados[i].isEmpty == OCUPADO)
		{
			if(listaEmpleados[i].id == id)
			{
				index = 0;
				break;
			}
		}
		else
		{
			index = -1;
		}
	}

	return index;
}

int bajaEmpleado(eEmpleado* listaEmpleados, int tam, eSector* listaSector, int tamSector)
{
	int retornoBaja = -1;
	int i;
	int index;
	int id;

	listarEmpleadosConDescripcion(listaEmpleados, tam, listaSector, tamSector);

	printf("Ingrese el ID: ");
	scanf("%d", &id);
	if(id < 1 || id > 1000)
	{
		while(id < 1 || id > 1000)
		{
			printf("Error, ingrese un ID valido.\n");
			scanf("%d", &id);
		}

	}
	index = encontrarEmpleadoPorID(listaEmpleados, tam, id);

	if(index == 0)
	{
		for(i=0; i<tam; i++)
		{
			listaEmpleados[i].isEmpty = VACIO;
			retornoBaja = 0;
			break;
		}
	}
	else
	{
		retornoBaja = -1;
	}
	return retornoBaja;
}

int buscarLibre(eEmpleado* listaEmpleados, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty==VACIO)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mostrarSectores(eSector* listaSector, int tamSector)
{
	int i;
	for(i=0 ; i<tamSector; i++)
	{
		printf("%2d %22s\n", listaSector[i].sector, listaSector[i].descripcion);
	}
}

int modificarEmpleado(eEmpleado* listaEmpleados,int tam, eSector* listaSector, int tamSector)
{
	int idIngresado;
	int i;
	int opcion;

		printf("Ingrese el ID: ");
		scanf("%d", &idIngresado);

		for(i=0; i<tam; i++)
		{
			if(idIngresado == listaEmpleados[i].id)
			{
				do
				{
				 printf("1.Modificar nombre del empleado\n");
				 printf("2.Modificar apellido del empleado\n");
				 printf("3.Modificar salario del empleado\n");
				 printf("4.Modificar sector del empleado\n");
				 printf("5.Salir\n");
				 printf("\n¿Que quiere modificar?: ");
				 scanf("%d", &opcion);

				switch(opcion)
				{
					case 1:
						printf("Ingrese el nuevo nombre: ");
						fflush(stdin);
						scanf("%[^\n]", listaEmpleados[i].nombre);
						printf("Nombre modificado con exito.\n");
					break;

					case 2:
						 printf("Ingrese el nuevo apellido: ");
						 fflush(stdin);
						 scanf("%[^\n]", listaEmpleados[i].apellido);
						 printf("Apellido modificado con exito.\n");
					break;

					case 3:
						utn_getNumeroFlotante(&listaEmpleados[i].salario, "Ingrese el nuevo salario", "Error ingrese un salario valido", 1, 9999999, 2);
						printf("Salario modificado con exito.\n");
					break;

					case 4:
						mostrarSectores(listaSector, tamSector);
						printf("Ingrese un nuevo sector: ");
						printf("Sector modificado con exito.\n");
					break;

					case 5:
						printf("Ha salido con exito de las modificaciones.\n");
						printf("**********************************************\n");

					break;

					}
				}while(opcion != 5);

			}
		}
		return i;
}

void listarEmpleadosConDescripcion(eEmpleado* listaEmpleados, int tam, eSector* listaSector, int tamSector)
{
	int i;
	eSector miSector;

	printf("*******************************************************************************\n");
	for(i=0; i<tam; i++)
	{

		if(listaEmpleados[i].isEmpty == OCUPADO)
		{
			miSector = buscarSectorPorID(listaSector, tamSector, listaEmpleados[i].sector);
			printf("%2d %15s %15s %.2f %15s\n",  listaEmpleados[i].id,
												 listaEmpleados[i].nombre,
												 listaEmpleados[i].apellido,
												 listaEmpleados[i].salario,
												 miSector.descripcion
												 );

		}
	 }
	printf("*******************************************************************************\n");

}

eSector buscarSectorPorID(eSector* listaSector, int tamSector, int sector)
{
	int i;
	eSector miSector;

	for(i=0; i<tamSector; i++)
	{
		if(listaSector[i].sector == sector)
		{
			miSector = listaSector[i];
			break;
		}
	}

	return miSector;
}

void ordenarPorApellido(eEmpleado* listaEmpleados, int tam)
{
    int i;
    int j;

    eEmpleado auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listaEmpleados[i].apellido, listaEmpleados[j].apellido)>0)
            {
                auxEmpleado = listaEmpleados[i];
                listaEmpleados[i] = listaEmpleados[j];
                listaEmpleados[j] = auxEmpleado;
            }
        }
    }
}

float totalSalarios(eEmpleado* listaEmpleados, int tam)
{
	float total;
	int i;

	total = 0;

	for(i=0; i<tam; i++)
	{
		if(listaEmpleados[i].isEmpty == OCUPADO)
		{
			if(listaEmpleados[i].salario > 0)
			{
				total = listaEmpleados[i].salario + total;
			}
		}
	}

	return total;
}

int contadorEmpleados(eEmpleado* listaEmpleados, int tam)
{
	int contadorE;
	int i;

	contadorE = 0;
	for(i=0; i<tam; i++)
	{
		if(listaEmpleados[i].isEmpty != VACIO)
		{
			contadorE++;
		}
	}

	return contadorE;
}

float promedioSalarios(eEmpleado* listaEmpleados, int tam)
{
	float promedio;
	float total;
	int divisor;
	int i;

	total = totalSalarios(listaEmpleados, tam);
	divisor = contadorEmpleados(listaEmpleados, tam);

	for(i=0; i<tam; i++)
	{
		if(listaEmpleados[i].isEmpty == OCUPADO)
		{
			if(total != 0)
			{
				promedio = (float) total / divisor;
			}
		}
	}

	return promedio;
}

int empleadosConSalarioMayorAlPromedio(eEmpleado* listaEmpleados, int tam)
{
	float promedio;
	int contadorMayorAlPromedio;
	int i;

	contadorMayorAlPromedio = 0;

	for(i=0; i<tam; i++)
	{
		if(listaEmpleados[i].isEmpty == OCUPADO)
		{
			promedio = promedioSalarios(listaEmpleados, tam);
			if(listaEmpleados[i].salario > promedio)
			{
				contadorMayorAlPromedio++;
			}
		}
	}

	return contadorMayorAlPromedio;

}

int recorrerEmpleados(eEmpleado* listaEmpleados, int tam)
{
	int i;
	int empleados = -1;

	for(i=0; i<tam; i++)
	{
			if(listaEmpleados[i].isEmpty != VACIO)
			{
				empleados = 0;
			}
	}

	return empleados;
}
