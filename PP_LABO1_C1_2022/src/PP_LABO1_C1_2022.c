/*
 ============================================================================
 Name        : PP_LABO1_C1_2022.c Pt.1
 Author      : Juan Navarro
 Version     : div 1E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Censista.h"
#include "Zonas.h"
#include "utn.h"


#define MENSAJE_ERROR_1 "ERROR..FALTA ALTA CENSISTA\n"
#define MENSAJE_ERROR_2 "ERROR..FALTA ALTA ZONA\n"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int auxCen = -1;
	int auxZona = -1;
	int arrayLocalidades[LEN_LOCALIDADES]={AVELLANEDA,QUILMES,BERAZATEGUI};
//Nota: cuando muestro la cantidad de zonas que hay en la localidad, le tengo que restar el valor de dicha localidad
	Censista sCensista[LEN_CENSISTAS];
	Zonas sZonas[LEN_ZONAS];

	initCensista(sCensista, LEN_CENSISTAS);
	initZonas(sZonas, LEN_ZONAS);






	do {
		opcion = menu();
		switch(opcion){
		case 1:
			if(altaCensista(sCensista, LEN_CENSISTAS)==0){
				auxCen = 1;
			}else{
				printf("No hay espacio\n");
				system("pause");
			}
			break;

		case 2:
			if(auxCen == 1){
				modificarCensista(sCensista,LEN_CENSISTAS);
			}else{
				printf(MENSAJE_ERROR_1);
			}
			system("pause");
			break;

		case 3:
			if(auxCen == 1){
				bajaCensista(sCensista, LEN_CENSISTAS);
			}else{
				printf(MENSAJE_ERROR_1);
			}
			system("pause");
			break;

		case 4:
			if(cargarZonas(sZonas, LEN_ZONAS, arrayLocalidades)==0){
				auxZona = 1;
			}else{
				printf("No hay espacio\n");
				system("pause");
			}
			break;

		case 5:
			if(auxCen == 1 && auxZona == 1){
				asignarZonaACensista(sZonas, LEN_ZONAS, sCensista, LEN_CENSISTAS);
			}else{
				printf(MENSAJE_ERROR_1);
				printf(MENSAJE_ERROR_2);
			}
			system("pause");
			break;

		case 6:
			completarCenso(sZonas,LEN_ZONAS, sCensista, LEN_CENSISTAS,arrayLocalidades);
			system("pause");
			break;
		case 7:
			system("cls");
			if(auxCen == 1){
				listarCensista(sCensista, LEN_CENSISTAS);
			}else{
				printf(MENSAJE_ERROR_1);
			}
			system("pause");
			break;
		case 8:
			system("cls");
			if(auxZona == 1){
				listarZonas(sZonas, LEN_ZONAS, sCensista, LEN_CENSISTAS);
			}else{
				printf(MENSAJE_ERROR_2);
			}
			system("pause");
			break;
			/*NO SE PEDIA EXPLICITAMENTE LAS SIGUIENTES OPCIONES, PERO CONSIDERÉ BUENA PRACTICA DEJARLAS.
			 * PARA PODER OPERAR CON LAS SIGUENTES OPCIONES SE DEBERA AMPLIAR EL RANGO EN EL MENU()*/
		case 10:
			if(hardcodeoZonas(sZonas, LEN_ZONAS, sCensista, LEN_CENSISTAS)==0){
				auxZona = 1;
			}
			if(hardcodeoCensista(sCensista, LEN_CENSISTAS)==0){
				auxCen = 1;
			}
			break;
		case 11:
			modificarZonas(sZonas, LEN_ZONAS, sCensista, LEN_CENSISTAS, arrayLocalidades);
			break;
		case 12:
			bajaZonas(sZonas, LEN_ZONAS, sCensista, LEN_CENSISTAS, arrayLocalidades);
			break;
		}

	}while(opcion!=9);

	return EXIT_SUCCESS;
}
