
#include "operaciones.h"
/**
 * @fn float suma(float, float)
 * @brief Recibe los 2 valores ingresados por el usuario, los suma y devuelve el resultado
 *
 * @param operando1 1er valor ingresado por el usuario obtenido en la funcion main
 * @param operando2 2do valor ingresado por el usuario obtenido en la funcion main
 * @return retorna el resultado de la suma
 */
float suma(float operando1, float operando2)
{
	float suma;

	suma = operando1 + operando2;

	return suma;
}

/**
 * @fn float resta(float, float)
 * @brief Recibe los 2 valores ingresados por el usuario, los resta y devuelve el resultado
 *
 * @param operando1 1er valor ingresado por el usuario obtenido en la funcion main
 * @param operando2 2do valor ingresado por el usuario obtenido en la funcion main
 * @return retorna el resultado de la resta
 */
float resta(float operando1, float operando2)
{
	float resta;

	resta = operando1 - operando2;

	return resta;
}

/**
 * @fn float division(float, float)
 * @brief Recibe los 2 valores ingresados por el usuario, con un if pregunto si el 2do operando tiene un valor "0", si es asi
 * la variable sera retornada con un valor "-1" sino los valores se dividiran y se retornara el resultado de dicha division
 *
 * @param operando1 1er valor ingresado por el usuario obtenido en la funcion main
 * @param operando2 2do valor ingresado por el usuario obtenido en la funcion main
 * @return retornara el resultado de la division o un valor "-1"
 */
float division(float operando1, float operando2)
{
	float division;

	if(operando2 == 0)
	{
		division = -1;
	}
	else
	{
		division = operando1 / operando2;
	}

	return division;
}

/**
 * @fn float multiplicacion(float, float)
 * @brief Recibe los 2 valores ingresados por el usuario, los multiplica y devuelve el resultado
 *
 * @param operando1 1er valor ingresado por el usuario obtenido en la funcion main
 * @param operando2 2do valor ingresado por el usuario obtenido en la funcion main
 * @return retorna el resultado de la multiplicacion
 */
float multiplicacion(float operando1, float operando2)
{
	float multiplicacion;

	multiplicacion = operando1 * operando2;

	return multiplicacion;
}

/**
 * @fn float factorial(float, float, float*)
 * @brief Recibe los 2 valores ingresados por el usuario, inicializo en 1 el puntero y la variable a retornar, en ambos if pregunto si el valor
 * del primer operando es "0", si es asi, el valor a retornar sera "1", sino con for y contadores realizo el factorial del numero obtenido
 * y luego devuelvo el resultado del primer operando a travez del retorno y el resultado del segundo a travez del puntero
 *
 * @param operando1 1er valor ingresado por el usuario obtenido en la funcion main
 * @param operando2 2do valor ingresado por el usuario obtenido en la funcion main
 * @param punteroFactorial2 puntero utilizado para obtener el valor factorial del segundo operando
 * @return retorna el resultado del factorial del primer operando
 */
float factorial(float operando1, float operando2, float* punteroFactorial2)
{
	float factorial1;
	int i;
	int j;

	factorial1 = 1;
	*punteroFactorial2 = 1;

	if(operando1 == 0)
	{
		factorial1 = 1;
	}
	else
	{
		for(i = operando1 ; i > 1 ; i--)
		{
			factorial1 = factorial1 * i;
		}
	}

	if(operando2 == 0)
	{
		*punteroFactorial2 = 1;
	}
	else
	{
		for(j = operando2 ; j > 1 ; j--)
		{
			*punteroFactorial2 = *punteroFactorial2 * j;
		}
	}

	return factorial1;
}
