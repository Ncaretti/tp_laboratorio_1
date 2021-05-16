/*
 * ArrayEmpleados.h
 *
 *  Created on: 15 may. 2021
 *      Author: Seether
 */

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

typedef struct
{
	int sector;
	char descripcion[20];

}eSector;

typedef struct
{
	int id;
	char nombre[20];
	char apellido[20];
	float salario;
	int sector;
	int isEmpty;

}eEmpleado;

/** \brief Indica que todas las posiciones en el array estan vacias,
 * esta funcion coloca la bandera (isEmpty) en VACIO en
 * todas las posiciones del array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int iniciarEmpleados(eEmpleado* listaEmpleados, int tam);



/**
 * @fn eEmpleado AltaEmpleado(eSector*, int)
 * @brief Funcion que permite ingresar los datos del empleado
 *
 * @param listaSector lista donde se almacenan los sectores disponibles para seleccionar
 * @param tamSector tamaño de la lista donde se encuentran los sectores
 * @return
 */
eEmpleado AltaEmpleado(eSector* listaSector, int tamSector);



/**
 * @fn int aniadirEmpleado(eEmpleado*, eSector*, int, int)
 * @brief Funcion que llama a "AltaEmpleado" para luego subir ese array a una lista
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param listaSector lista donde se almacenan los sectores disponibles para seleccionar
 * @param tamSector tamaño de la lista donde se encuentran los sectores
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
int aniadirEmpleado(eEmpleado* listaEmpleados, eSector* listaSector, int tamSector, int tam);



/**
 * @fn int encontrarEmpleadoPorID(eEmpleado*, int, int)
 * @brief Permite machear un id ingresado por el usuario con un id ya listado
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @param id el id ingresado por el usuario llamado por parametro
 * @return
 */
int encontrarEmpleadoPorID(eEmpleado* listaEmpleados, int tam,int id);



/**
 * @fn int bajaEmpleado(eEmpleado*, int, eSector*, int)
 * @brief Permite dar de baja un empleado a traves del id ingresado por el usuario, esta funcion esta validada por la anterior
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param listaSector lista donde se almacenan los sectores disponibles para seleccionar
 * @param tamSector tamaño de la lista donde se encuentran los sectores
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
int bajaEmpleado(eEmpleado* listaEmpleados, int tam, eSector* listaSector, int tamSector);



/**
 * @fn int imprimirEmpleados(eEmpleado*, int)
 * @brief A traves de un for busca un espacio libre en el array
 *
* @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
int buscarLibre(eEmpleado* listaEmpleados, int tam);



/**
 * @fn void mostrarSectores(eSector*, int)
 * @brief funcion que tiene cargado el id de los sectores con su descripcion
 *
 * @param listaSector lista donde se almacenan los sectores disponibles para seleccionar
 * @param tamSector tamaño de la lista donde se encuentran los sectores
 */
void mostrarSectores(eSector* listaSector, int tamSector);



/**
 * @fn int modificarEmpleado(eEmpleado*, int, eSector*, int)
 * @brief le pide al usuario que ingrese un id existente en el array para permitirle modificar el nombre, el apellido
 * o el sector del array seleccionado
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param listaSector lista donde se almacenan los sectores disponibles para seleccionar
 * @param tamSector tamaño de la lista donde se encuentran los sectores
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
int modificarEmpleado(eEmpleado* listaEmpleados,int tam, eSector* listaSector, int tamSector);

/**
 * @fn void listarEmpleadosConDescripcion(eEmpleado*, int, eSector*, int)
 * @brief Es la funcion que termina siendo llamada a la hora de listar empleados, imprime en orden los arrays cargados en "AltaEmpleado"
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param listaSector lista donde se almacenan los sectores disponibles para seleccionar
 * @param tamSector tamaño de la lista donde se encuentran los sectores
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 */
void listarEmpleadosConDescripcion(eEmpleado* listaEmpleados, int tam, eSector* listaSector, int tamSector);



/**
 * @fn eSector buscarSectorPorID(eSector*, int, int)
 * @brief funcion que machea el id obtenido por parametro con el id de la lista de sectores
 *
 * @param listaSector lista donde se almacenan los sectores disponibles para seleccionar
 * @param tamSector tamaño de la lista donde se encuentran los sectores
 * @param sector parametro por referencia que viene cargado con el valor a machear
 * @return
 */
eSector buscarSectorPorID(eSector* listaSector, int tamSector, int sector);



/**
 * @fn int ordenarEmpleado(eEmpleado*, int, int)
 * @brief Funcion que ordena el array de listaEmpleados por orden alfabetico del campo "apellido"
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
void ordenarPorApellido(eEmpleado* listaEmpleados, int tam);



/**
 * @fn int contadorEmpleados(eEmpleado*, int)
 * @brief cuenta de 1 en 1 los empleados que hay ingresados en el array
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
int contadorEmpleados(eEmpleado* listaEmpleados,int tam);



/**
 * @fn float totalSalarios(eEmpleado*, int)
 * @brief Funcion que acumula los salarios de los usuarios que estan en el array
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
float totalSalarios(eEmpleado* listaEmpleados, int tam);



/**
 * @fn float promedioSalarios(eEmpleado*, int)
 * @brief Funcion que calcula el promedio de los salarios
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
float promedioSalarios(eEmpleado* listaEmpleados, int tam);



/**
 * @fn int empleadosConSalarioMayorAlPromedio(eEmpleado*, int)
 * @brief Con esta funcion se determina que empleados del array tienen un sueldo mayor al devuelto por la funcion "promedioSalarios"
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
int empleadosConSalarioMayorAlPromedio(eEmpleado* listaEmpleados, int tam);



/**
 * @fn int recorrerEmpleados(eEmpleado*, int)
 * @brief Funcion que recorre la lista de empleados y devuelve un "0" si encontro al menos 1 lista dada de alta o -1 si no encontro
 * ninguna
 *
 * @param listaEmpleados lista donde se encuentran los datos obtenidos en "AltaEmpleado"
 * @param tam tamaño de la lista donde se encuentran los datos del empleado
 * @return
 */
int recorrerEmpleados(eEmpleado* listaEmpleados, int tam);


#endif /* ARRAYEMPLEADOS_H_ */
