/*
 * utn.h
 *
 *  Created on: 19 may. 2022
 *      Author: Juan-PC
 */

#ifndef UTN_H_
#define UTN_H_
/**
 * @brief Recibe un string y pone la primer letra en mayuscula (el nombre puede
 * ser compuesto e igualmente pondra la primer letra en mayuscula)
 *
 * @param string char []
 * @param len int tamaño del string
 * @return Retorna (0) si todo salio y (-1) si hubo error
 */
int primeraLetraMayuscula(char string [], int len);
/**
 * @brief Solicita al usuario una letra u otra, luego de verificarla, devuelve la letra
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje Mensaje a ser mostrado
 * @param mensajeError Es el mensaje de error a ser mostrado
 * @param char1 Letra 1
 * @param char2 Letra 2
 * @param reintentos cantidad de reintentos
 * @return Retorna (0) si obtuvo la letra deseada o (-1) si no
 *
 * ejemplo= utn_getCaracterSoN(&resultado, "Desea continuar? s/n: ","Error",'s','n',3);
 */
int utn_getCaracterSoN(char* pResultado, char* mensaje, char* mensajeError, char char1, char char2, int reintentos);
/**
 * @brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param minimo Es el numero maximo a ser aceptado
 * @param maximo Es el minimo minimo a ser aceptado
 * @return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,int minimo, int reintentos);
/**
 * @brief Obtiene un numero entero
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getInt(int* pResultado);
/**
 * @brief Verifica si la cadena ingresada es numerica
 *
 * @param cadena Cadena de caracteres a ser analizada
 * @param limite Limite de la cadena ingresada
 * @return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 */
int esNumerica(char* cadena, int limite);
/**
 * @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 *
 * @param cadena  Puntero al espacio de memoria donde se copiara la cadena obtenida
 * @param longitud longitud Define el tamaño de cadena
 * @return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
int getString(char* cadena, int longitud);
/**
 * @brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud Es la longitud del array resultado
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param reintentos Cantidad de reintentos
 * @return Retorna 0 si se obtuvo el nombre y -1 si no
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
/**
 * @brief Verifica si la cadena ingresada es un nombre valido
 *
 * @param cadena Cadena de caracteres a ser analizada
 * @param longitud Longitud de la cadena ingresada
 * @return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int esNombre(char* cadena,int longitud);
/**
 * @brief Obtiene un string valido como nombre
 *
 * @param pResultado  Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud Longitud define el tamaño de la cadena
 * @return Retorna 0 (EXITO) si se obtiene un nombre y -1 (ERROR) si no
 */
int getNombre(char* pResultado, int longitud);
/**
 * @brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param minimo Es el numero minimo a ser aceptado
 * @param maximo Es el numero maximo a ser aceptado
 * @param reintentos Cantidad de reintentos
 * @return Retorna 0 si se obtuvo el numero flotante y -1 si no
 */
int utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
/**
 * @brief Verifica si la cadena ingresada es flotante
 *
 * @param cadena Cadena de caracteres a ser analizada
 * @return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int esFlotante(char* cadena);
/**
 * @brief Verifica si la cadena ingresada es flotante
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 */
int getFloat(float* pResultado);
/**
 * @brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud  Es la longitud del array resultado
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param reintentos  Cantidad de reintentos
 * @return retorna 0 si se obtuvo la descripcion y (-1) si no
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
/**
 * @brief Obtiene un string valido como descripcion
 *
 * @param pResultado
 * @param longitud
 * @return Retorna 0 (EXITO) si se obtiene el string y -1 (ERROR) si no
 */
int getDescripcion(char* pResultado, int longitud);
/**
 * @brief Verifica si la cadena ingresada es una descripcion valida
 *
 * @param cadena Cadena de caracteres a ser analizada
 * @param longitud
 * @return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int esDescripcion(char* cadena,int longitud);


#endif /* UTN_H_ */
