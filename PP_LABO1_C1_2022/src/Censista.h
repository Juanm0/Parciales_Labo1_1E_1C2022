/*
 * Censista.h
 *
 *  Created on: 19 may. 2022
 *      Author: Juan-PC
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#define LEN_CENSISTAS 200
#define LEN_HARCOD_CENSISTA 5

#define ACTIVO 1//cuando se le asigna una zona el censista es activo
#define LIBERADO 2//cuando termina de censar el censista esta liberado
#define INACTIVO 3//cuando se da de baja el censista es inactivo

typedef struct{

	int dia;
	int mes;
	int anio;

}Nacimiento;

typedef struct {

	char calle[51];
	int altura;

}Direccion;

typedef struct {
	char nombre[150];
	char apellido[150];
	int edad;
	Nacimiento fechaNac;
	Direccion domicilio;
	int estadoCensista;
	int idCensista;
	int isEmpty;

}Censista;
/**
 * @brief Menu de opciones
 *
 * @return int opcion que eligio el usuario
 */
int menu(void);
/**
 * @brief SubMenu para modificar datos del censista
 *
 * @param sCensista
 * @param len
 * @param id
 * @return int opcion que eligio el usuario
 */
int subMenu(Censista sCensista[], int len, int id);
/**
 * @brief Muestra todos los censistas
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido y (0) si todoOk
 */
int listarCensista(Censista pArray[],int len);
/**
 * @brief Inicializa el array de censistas colocando el campo isEmpy en 1
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido y (0) si todoOk
 */
int initCensista (Censista pArray[],int len);
/**
 * @brief Da de alta a un censista
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido y (0) si pudo dar de alta al censista
 */
int altaCensista (Censista pArray[],int len);
/**
 * @brief Busca un espacio libre en el array de censistas
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido
 *  o no pudo encontrar un espacio libre y si pudo encontrar espacio, retorna el indice
 */
int buscarEspacioLibre(Censista pArray[], int len);
/**
 * @brief Modifica a un censista
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido o no pudo encontrar al censista
 * retorna (0) si el usuario confirmo la modificacion
 */
int modificarCensista(Censista pArray[], int len);
/**
 * @brief Muestra a un censista con todos sus datos
 *
 * @param unCensista
 */
void mostrarCensista(Censista unCensista);
/**
 * @brief Busca un censista por su ID
 *
 * @param pArray
 * @param len
 * @param id
 * @return int retorna (-1) si el puntero es NULL o el len es invalido
 *  o no pudo encontrar un censista y si pudo encontrarlo, retorna el indice
 */
int buscarCensistaById(Censista pArray[],int len,int id);
/**
 * @brief Da de baja a un censista colocando su campo estado en INACTIVO
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido
 *  o no pudo encontrar un censista y (0) si pudo darlo de baja
 */
int bajaCensista(Censista pArray[],int len);
/**
 * @brief Estructura que hardcodea a varios censistas
 *
 * @param sCensista
 * @param lenCensista
 * @return int retorna (-1) si el puntero es NULL o el len es invalido y (0) si todoOK
 */
int hardcodeoCensista(Censista sCensista[],int lenCensista);

#endif /* CENSISTA_H_ */
