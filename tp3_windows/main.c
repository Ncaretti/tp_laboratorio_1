#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utnInputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int opcion;
    int retornoMenu;
    int retornoGuardarTexto;
    int retornoGuardarBinario;
    int flagArchivoTexto = 0;
    int flagArchivoBinario = 0;
    int retornoEdit;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	retornoMenu = utn_getInt(&opcion,
    		    						"Menu:\n"
										 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
										 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
										 "3. Alta de empleado\n"
										 "4. Modificar datos de empleado\n"
										 "5. Baja de empleado\n"
										 "6. Listar empleados\n"
										 "7. Ordenar empleados\n"
										 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
										 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
										 "10. Salir\n", "\nError: Seleccione una opcion valida.\n", 1, 10, 2);

    	if (retornoMenu != 0)
    	{
    		printf("\nHa ocurrido un error.");
    		break;
    	}

        switch(opcion)
        {
            case 1:
            	if(flagArchivoTexto == 0)
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
            		flagArchivoTexto = 1;
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("El archivo ya ha sido abierto.\n");
            		printf("**********************************************************\n");
            	}
            break;

            case 2:
            	if(flagArchivoBinario == 0)
            	{
            		controller_loadFromBinary("data.bin", listaEmpleados);
            		flagArchivoBinario = 1;
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("El archivo ya ha sido abierto.\n");
            		printf("**********************************************************\n");
            	}
            break;

            case 3:
            	if(flagArchivoTexto == 1)
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("Error, el archivo 'data.csv' no ha sido abierto.\n");
            		printf("**********************************************************\n");
            	}
            break;

            case 4:
            	if(flagArchivoTexto == 1)
            	{
            		retornoEdit = controller_editEmployee(listaEmpleados);
            		if(retornoEdit == 1)
            		{
            		    printf("**********************************************************\n");
            		    printf("El empleado ha sido editado con exito/Ha salido con exito\n");
            		    printf("**********************************************************\n");
            		}
            		else
            		{
            		    printf("**********************************************************\n");
            		    printf("Ha ocurrido un error en la edicion del empleado.\n");
            		    printf("**********************************************************\n");
            		 }
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("Error, el archivo 'data.csv' no ha sido abierto.\n");
            	    printf("**********************************************************\n");
            	}
            break;

            case 5:
            	if(flagArchivoTexto == 1)
            	{
            		controller_removeEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("Error, el archivo 'data.csv' no ha sido abierto.\n");
            	    printf("**********************************************************\n");
            	}
            break;

            case 6:
            	if(flagArchivoTexto == 1)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("Error, el archivo 'data.csv' no ha sido abierto.\n");
            	    printf("**********************************************************\n");
            	}
            break;

            case 7:
            	if(flagArchivoTexto == 1)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("Error, el archivo 'data.csv' no ha sido abierto.\n");
            		printf("**********************************************************\n");
            	}
            break;

            case 8:
            	if(flagArchivoTexto == 1)
            	{
            		retornoGuardarTexto = controller_saveAsText("data.csv",listaEmpleados);

            		if(retornoGuardarTexto == 0)
            		{
            			printf("**********************************************************\n");
            			printf("Se ha guardado con exito.\n");
            			printf("**********************************************************\n");
            		}
            		else
            		{
            			printf("**********************************************************\n");
            			printf("Error, no se ha podido guardar.\n");
            			printf("**********************************************************\n");
            		}
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("Error, el archivo 'data.csv' no ha sido abierto.\n");
            	    printf("**********************************************************\n");
            	}
            break;

            case 9:
            	if(flagArchivoBinario == 1)
            	{
            		retornoGuardarBinario = controller_saveAsBinary("data.bin", listaEmpleados);

            		if(retornoGuardarBinario == 0)
            		{
            		     printf("**********************************************************\n");
            		     printf("Se ha guardado con exito.\n");
            		     printf("**********************************************************\n");
            		}
            		else
            		{
            		     printf("**********************************************************\n");
            		     printf("Error, no se ha podido guardar.\n");
            		     printf("**********************************************************\n");
            		 }
            	}
            	else
            	{
            		printf("**********************************************************\n");
            		printf("Error, el archivo 'data.csv' no ha sido abierto.\n");
            	    printf("**********************************************************\n");
            	}
            break;

            case 10:
            	printf("***********************************************\n");
            	printf("Gracias por usar la aplicacion.\n");
            	printf("***********************************************\n");
            break;
        }
    }while(opcion != 10);
    return 0;

}
