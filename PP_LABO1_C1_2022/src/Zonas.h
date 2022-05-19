/*
 * Zonas.h
 *
 *  Created on: 19 may. 2022
 *      Author: Juan-PC
 */

#ifndef ZONAS_H_
#define ZONAS_H_

#include "Censista.h"

#define LEN_ZONAS 200
#define LEN_HARCOD_ZONAS 5

#define LEN_LOCALIDADES 4

#define AVELLANEDA 0
#define LANUS 1
#define LOMAS_DE_ZAMORA 2
#define BANFIELD 3



#define PENDIENTE 1
#define FINALIZADO 2

typedef struct {

	char calle1[51];
	char calle2[51];
	char calle3[51];
	char calle4[51];

}Calles;

typedef struct{

	int estadoZona;
	Calles Manzana;//4 calles de cada zona
	int localidad;
	int isEmpty;
	int idZona;
	int idCensista;
	int cantCenInSitu;
	int cantCenDigital;
	int cantCenAusentes;

}Zonas;
/**
 * @brief Inicializa el array de zonas colocando el campo isEmpy en 1
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido y (0) si todoOk
 */
int initZonas (Zonas pArray[],int len);
/**
 * @brief Busca un espacio libre en el array de zonas
 *
 * @param pArray
 * @param len
 * @return int retorna (-1) si el puntero es NULL o el len es invalido
 *  o no pudo encontrar un espacio libre y si pudo encontrar espacio, retorna el indice
 */
int buscarEspacioLibreZonas(Zonas pArray[],int len);
/**
 * @brief Da de alta a una zona
 *
 * @param pArray
 * @param len
 * @param arrayLocalidades
 * @return int retorna (-1) si el puntero es NULL o el len es invalido y (0) si pudo dar de alta a la zona
 */
int cargarZonas(Zonas pArray[],int len, int arrayLocalidades[]);
/**
 * @brief Muestra todas las zonas
 *
 * @param pArray
 * @param lenZonas
 * @param pArrayCensista
 * @param lenCensista
 * @return int retorna (-1) si los puntero son NULL o los len son invalidos y (0) si todoOk
 */
int listarZonas(Zonas pArray[],int lenZonas,Censista pArrayCensista[],int lenCensista);
/**
 * @brief Muestra una zona con todos sus datos
 *
 * @param unaZona
 * @param pArrayCensista
 * @param lenCensista
 */
void mostrarZona(Zonas unaZona,Censista pArrayCensista[],int lenCensista);
/**
 * @brief Busca una zona por el numero de zona (ID)
 *
 * @param pArray
 * @param lenZona
 * @param idZona
 * @return int retorna (-1) si el puntero es NULL o el len es invalido
 *  o no pudo encontrar una zona y si pudo encontrarla, retorna su indice
 */
int buscarZonaById(Zonas pArray[],int lenZona,int idZona);
/**
 * @brief se asigna un censista responsable a la zona.
 *
 * @param sZonas
 * @param lenZona
 * @param sCensista
 * @param lenCensista
 * @return int retorna (-1) si los puntero son NULL o los len son invalidos
 *  o no pudo encontrar una zona sin asignar y (0) si pudo asignar zona a censista
 */
int asignarZonaACensista(Zonas sZonas[],int lenZona, Censista sCensista[], int lenCensista);
/**
 * @brief Se cargan los datos para FINALIZAR el censo en la zona
 *
 * @param sZonas
 * @param lenZonas
 * @param sCensista
 * @param lenCensista
 * @param arrayLocalidades
 * @return int retorna (-1) si los puntero son NULL o los len son invalidos
 *  o no pudo encontrar la zona y (0) si pudo completar el censo
 */
int completarCenso(Zonas sZonas[],int lenZonas,Censista sCensista[],int lenCensista);
/**
 * @brief Modifica los datos de una zona
 *
 * @param sZonas
 * @param lenZonas
 * @param sCensista
 * @param lenCensista
 * @param arrayLocalidades
 * @return int retorna (-1) si los puntero son NULL o los len son invalidos
 *  o no pudo encontrar la zona o el usuario rechaza modificarla y (0) si el usuario acepto modificar esa zona
 */
int modificarZonas(Zonas sZonas[],int lenZonas,Censista sCensista[],int lenCensista,int arrayLocalidades[]);
/**
 * @brief SubMenu para elegir la opcion que se desea modificar
 *
 * @param sZonas
 * @param lenZonas
 * @param id
 * @param sCensista
 * @param lenCensista
 * @return int retorna la opcion ingresada por el usuario
 */
int subMenuZonas(Zonas sZonas[], int lenZonas, int id,Censista sCensista[],int lenCensista);
/**
 * @brief Estructura que hardcodea varias zonas
 *
 * @param sZonas
 * @param lenZonas
 * @param sCensista
 * @param lenCensista
 * @return int retorna (-1) si los puntero son NULL o los len son invalidos y (0) si todoOk
 */
int hardcodeoZonas(Zonas sZonas[], int lenZonas,Censista sCensista[],int lenCensista);
/**
 * @brief se realiza la baja logica de la zona, colocando el campo isEmpty en 0
 *
 * @param sZonas
 * @param lenZonas
 * @param sCensista
 * @param lenCensista
 * @param arrayLocalidades
 * @return int retorna (-1) si los puntero son NULL o los len son invalidos o
 * no se encontro la zona y (0) si pudo dar de baja la zona
 */
int bajaZonas(Zonas sZonas[],int lenZonas,Censista sCensista[],int lenCensista, int arrayLocalidades[]);

#endif /* ZONAS_H_ */
