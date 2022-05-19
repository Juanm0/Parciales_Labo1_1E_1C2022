/*
 * Zonas.c
 *
 *  Created on: 19 may. 2022
 *      Author: Juan-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Zonas.h"
#include "Censista.h"
#include "utn.h"


int autoIncrementarIdZonas()
{
    static int id = 200;
    id++;
    return id;
}

int initZonas (Zonas pArray[],int len) {
	int retorno = -1;

	if(pArray != NULL && len > 0) {

		for(int i=0;i<len;i++)
		{
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int cargarZonas(Zonas pArray[],int len, int arrayLocalidades[]) {
	int retorno = -1;
	int index;
	int localidad;

	if(pArray != NULL && len > 0) {

		index = buscarEspacioLibreZonas(pArray, len);
		if(index != -1) {

			system("cls");
			printf("  ******CARGAR ZONAS A CENSAR***** \n\n");
			if(utn_getNumero(&localidad, "Localidad?\n[1]AVELLANEDA\n[2]QUILMES\n[3]BERAZATEGUI\nIngrese opcion: ", "eRROR..Localidad invalida", 3, 1, 3)==0
			&& utn_getDescripcion(pArray[index].Manzana.calle1, sizeof(pArray[index].Manzana.calle1), "CALLE 1: ", "eRROR..Calle invalida", 3)==0
			&& utn_getDescripcion(pArray[index].Manzana.calle2, sizeof(pArray[index].Manzana.calle2), "CALLE 2: ", "eRROR..Calle invalida", 3)==0
			&& utn_getDescripcion(pArray[index].Manzana.calle3, sizeof(pArray[index].Manzana.calle3), "CALLE 3: ", "eRROR..Calle invalida", 3)==0
			&& utn_getDescripcion(pArray[index].Manzana.calle4, sizeof(pArray[index].Manzana.calle4), "CALLE 4: ", "eRROR..Calle invalida", 3)==0)
			{

				pArray[index].idZona = autoIncrementarIdZonas();
				pArray[index].isEmpty = 0;
				pArray[index].localidad = localidad-1;
				arrayLocalidades[localidad-1]++;
				pArray[index].estadoZona = PENDIENTE;
				pArray[index].idCensista = -1;
				pArray[index].cantCenInSitu = 0;
				pArray[index].cantCenDigital = 0;
				pArray[index].cantCenAusentes = 0;
				retorno = 0;

			}

		}

	}

	return retorno;
}

int buscarEspacioLibreZonas(Zonas pArray[], int len) {

	int retorno = -1;
	if(pArray != NULL && len > 0) {
		for (int i = 0; i < len; i++) {

			if (pArray[i].isEmpty == 1) {
				retorno = i;
				break;
		    }
		}

	}
	return retorno;//Si retorno es -1 quiere decir que no hay espacios libres
}

int asignarZonaACensista(Zonas sZonas[],int lenZona, Censista sCensista[], int lenCensista) {
	int retorno = -1;
	int auxIdCensista;
	int indexCensista;
	int indexZona;
	int auxIdZona;
	char salir;
	int flag = 0;

	if(sZonas != NULL && lenZona > 0 && sCensista != NULL && lenCensista > 0) {

		do{
			salir = 's';
			printf("----------------------------------------------------------------------------------------------------\n");
			printf("                                       ZONAS SIN ASINAR  \n");
			printf("----------------------------------------------------------------------------------------------------\n");
			printf("Num.Zona   LOCALIDAD                 RADIO DE LA ZONA                     ESTADO      CENSISTA     \n");
			printf("----------------------------------------------------------------------------------------------------\n");
			for(int i = 0; i < lenZona; i++){
				if(sZonas[i].idCensista == -1){
					mostrarZona(sZonas[i], sCensista, lenCensista);
					flag = 1;
				}
			}
			if(flag!=0){
				listarCensista(sCensista, lenCensista);
				if(utn_getNumero(&auxIdCensista, "Ingrese ID de censista a asignar: ", "eRROR..ID invalida",9999, 0, 3)==0
				&&(indexCensista = buscarCensistaById(sCensista, lenCensista, auxIdCensista))!=-1){
					if(sCensista[indexCensista].estadoCensista == LIBERADO){

						if(utn_getNumero(&auxIdZona, "Ingrese numero de zona: ", "eRROR..Zona invalida",9999, 0, 3)==0
						&& (indexZona = buscarZonaById(sZonas, lenZona,auxIdZona))!=-1){

							if(sZonas[indexZona].idCensista ==-1){

							sCensista[indexCensista].estadoCensista = ACTIVO;
							sZonas[indexZona].idCensista = auxIdCensista;
							printf("ZONA ASIGNADA\n");
							retorno = 0;
							}else{
								printf("La zona ya tiene un censista asignado\n");
							}
						}else{
							printf("No se pudo encontrar la zona\n");
						}
					}else{
						printf("El Censista no esta liberado\n");
					}

				}else{
					printf("No se encontro el Censista\n");
				}
				if(utn_getCaracterSoN(&salir, "Continuar?(s/n): ", "eRROR..Ingrese (s/n)", 's', 'n', 3)==-1){
					break;
				}
			}else{
				printf("No hay Zonas sin asignar\n");
				break;
			}


		}while(salir!='n');

	}

	return retorno;
}

void mostrarZona(Zonas unaZona, Censista pArray[],int lenCensista) {

	char estado[51];
	char localidad[51];
	int indexCensista;
	char auxNombre[150];
	char auxApellido[150];
	if(unaZona.isEmpty == 0) {

		switch(unaZona.estadoZona){
		case PENDIENTE:
			strncpy(estado,"PENDIENTE",sizeof(estado));
			break;
		case FINALIZADO:
			strncpy(estado,"FINALIZADO",sizeof(estado));
			break;
		}
		switch(unaZona.localidad) {
		case AVELLANEDA:
			strncpy(localidad,"AVELLANEDA",sizeof(localidad));
			break;
		case QUILMES:
			strncpy(localidad,"QUILMES",sizeof(localidad));
			break;
		case BERAZATEGUI:
			strncpy(localidad,"BERAZATEGUI",sizeof(localidad));
			break;

		}
		if(unaZona.idCensista!=-1){
			indexCensista=buscarCensistaById(pArray, lenCensista, unaZona.idCensista);
			strncpy(auxNombre,pArray[indexCensista].nombre,sizeof(auxNombre));
			strncpy(auxApellido,pArray[indexCensista].apellido,sizeof(auxApellido));
		}else{
			strncpy(auxNombre,"SIN ",sizeof(auxNombre));
			strncpy(auxApellido,"ASIGNAR",sizeof(auxApellido));
		}
		printf("|%-10d|%-10s|%s - %s - %s - %-10s|%-10s|%s %-10s|\nCant.Censados in situ: %d Cant.Censo Digital: %d Cant.Ausentes: %d\n",
				unaZona.idZona,
				localidad,
				unaZona.Manzana.calle1,
				unaZona.Manzana.calle2,
				unaZona.Manzana.calle3,
				unaZona.Manzana.calle4,
				estado,
				auxNombre,
				auxApellido,
				unaZona.cantCenInSitu,
				unaZona.cantCenDigital,
				unaZona.cantCenAusentes
				);
		for(int i = 0; i<17;i++){
					printf("-----+");
					if(i==16){
						printf("\n");
					}
				}
	}
}

int listarZonas(Zonas pArray[],int lenZonas,Censista pArrayCensista[],int lenCensista) {

	int retorno = -1;

	if(pArray != NULL && lenZonas > 0 && pArrayCensista != NULL && lenCensista > 0)
	{
		printf("                                         LISTA DE ZONAS   \n");
		printf("----------------------------------------------------------------------------------------------------\n");
		printf("Num.Zona   LOCALIDAD                 RADIO DE LA ZONA                     ESTADO      CENSISTA     \n");
		printf("----------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < lenZonas; i++)
		{
			mostrarZona(pArray[i],pArrayCensista,lenCensista);
		}
		retorno = 0;
	}
	return retorno;
}

int buscarZonaById(Zonas pArray[],int lenZona,int idZona) {

	int retorno = -1;
	if(pArray != NULL && lenZona > 0 && idZona > 0) {
		for (int i = 0; i < lenZona; i++) {

			if (pArray[i].isEmpty == 0 && pArray[i].idZona == idZona) {
				retorno = i;
				break;
		    }
		}
	}
	return retorno;//Si retorno es -1 quiere decir que no hay espacios libres
}

int completarCenso(Zonas sZonas[],int lenZonas,Censista sCensista[],int lenCensista,int arrayLocalidades[]) {
	int retorno = -1;
	int auxIdZona;
	int indexZona;
	int flag=0;
	int indexCensista;
	char salir;
	if(sZonas != NULL && lenZonas > 0 && sCensista != NULL && lenCensista > 0) {

		do{
			salir='n';
			system("cls");
			printf("----------------------------------------------------------------------------------------------------\n");
			printf("                                    LISTA DE ZONAS PENDIENTES\n");
			printf("----------------------------------------------------------------------------------------------------\n");
			printf("Num.Zona   LOCALIDAD                     RADIO DE LA ZONA                     ESTADO      CENSISTA     \n");
			printf("----------------------------------------------------------------------------------------------------\n");
			for(int i = 0; i<lenZonas; i++){
				if(sZonas[i].estadoZona==PENDIENTE){
					mostrarZona(sZonas[i], sCensista, lenCensista);
					flag=1;
				}
			}
			if(flag==0){
				printf("No hay zonas pendientes\n");
				break;
			}else if(utn_getNumero(&auxIdZona, "Num. de zona que desea finalizar Censo: ", "eRROR..Numero invalido", 9999, 0, 3) == 0
					&& (indexZona=buscarZonaById(sZonas, lenZonas, auxIdZona)) != -1){

					if(sZonas[indexZona].estadoZona==PENDIENTE && sZonas[indexZona].idCensista!=-1){

						if (utn_getNumero(&sZonas[indexZona].cantCenInSitu, "Ingrese cantidad de censados in situ: ", "eRROR..Cantidad invalida", 9999, 0, 3)==0
						&& utn_getNumero(&sZonas[indexZona].cantCenDigital, "Ingrese cantidad de censados virtuales: ", "eRROR..Cantidad invalida", 9999, 0, 3)==0
						&& utn_getNumero(&sZonas[indexZona].cantCenAusentes, "Ingrese cantidad de censados ausentes: ", "eRROR..Cantidad invalida", 9999, 0, 3)==0){

							indexCensista=buscarCensistaById(sCensista, lenCensista, sZonas[indexZona].idCensista);
							if(indexCensista!=-1){
								sZonas[indexZona].estadoZona = FINALIZADO;
								sCensista[indexCensista].estadoCensista=LIBERADO;
								retorno = 0;
							}
						}
					}else{
						printf("Primero debe asignarle un censista a la zona\n");
					}
			}else{
				printf("No se encontro la zona\n");
			}
			utn_getCaracterSoN(&salir, "SALIR?(s/n): ", "eRROR..Ingrese (s/n)", 's', 'n', 3);

		}while(salir!='s');

	}

	return retorno;
}


int modificarZonas(Zonas sZonas[],int lenZonas,Censista sCensista[],int lenCensista,int arrayLocalidades[]) {
	int retorno = -1;
	int auxIdZona;
	int indexZona;
	char opcion;
	int auxLocalidad;
	int auxCalle;
	int auxIdCensista;
	int indexCensista;
	if(sZonas != NULL && lenZonas > 0 && sCensista != NULL && lenCensista > 0){
		if(utn_getNumero(&auxIdZona, "Ingrese numero de zona a modificar: ", "eRROR..Zona invalida",9999, 0, 3)==0
		&& (indexZona = buscarZonaById(sZonas, lenZonas, auxIdZona))!=-1){
			mostrarZona(sZonas[indexZona], sCensista, lenCensista);
			utn_getCaracterSoN(&opcion, "Confirma MODIFICAR a esta zona?(S/N): ", "Error, ingrese S/N", 's', 'n', 3);

			if(opcion == 's'){
				retorno = 0;
				do{
				switch(subMenuZonas(sZonas, lenZonas, auxIdZona, sCensista, lenCensista)){
				case 1:
					if(utn_getNumero(&auxLocalidad, "Localidad?\n[1]AVELLANEDA\n[2]QUILMES\n[3]BERAZATEGUI\nIngrese nueva opcion: ",
							"eRROR..Localidad invalida", 3, 1, 3)==0){

						arrayLocalidades[sZonas[indexZona].localidad]--;
						sZonas[indexZona].localidad = auxLocalidad-1;
						arrayLocalidades[auxLocalidad-1]++;
					}
					break;
				case 2:
					if(utn_getNumero(&auxCalle, "Cual calle quiere modificar?(1-4): ", "eRROR..Numero invalido", 4,1,3)==0){

						switch(auxCalle){
						case 1:
							utn_getDescripcion(sZonas[indexZona].Manzana.calle1, sizeof(sZonas[indexZona].Manzana.calle1),
												"CALLE 1: ", "eRROR..Calle invalida", 3);
							break;
						case 2:
							utn_getDescripcion(sZonas[indexZona].Manzana.calle2, sizeof(sZonas[indexZona].Manzana.calle2),
												"CALLE 2: ", "eRROR..Calle invalida", 3);
							break;
						case 3:
							utn_getDescripcion(sZonas[indexZona].Manzana.calle3, sizeof(sZonas[indexZona].Manzana.calle3),
												"CALLE 3: ", "eRROR..Calle invalida", 3);
							break;
						case 4:
							utn_getDescripcion(sZonas[indexZona].Manzana.calle4, sizeof(sZonas[indexZona].Manzana.calle4),
												"CALLE 4: ", "eRROR..Calle invalida", 3);
							break;
						}
					}
					break;
				case 3:
					utn_getNumero(&sZonas[indexZona].estadoZona, "*el estado solo se puede cambiar a PENDIENTE\n[1]PENDIENTE\nIngrese numero: ", "eRROR..Numero invalido", 1, 1, 3);
					break;
				case 4:
					if(utn_getNumero(&auxIdCensista, "Ingrese ID de censista a asignar: ", "eRROR..ID invalida",9999, 0, 3)==0
					&&(indexCensista = buscarCensistaById(sCensista, lenCensista, auxIdCensista))!=-1){
						if(sCensista[indexCensista].estadoCensista == LIBERADO){

							if(sZonas[indexZona].idCensista!=-1){
								sCensista[buscarCensistaById(sCensista, lenCensista, sZonas[indexZona].idCensista)].estadoCensista=LIBERADO;
								//Si el censista ya fue asignado antes, se le cambiara el estado por LIBERADO al censista de antes
							}
							sCensista[indexCensista].estadoCensista = ACTIVO;
							sZonas[indexZona].idCensista = auxIdCensista;
						}else{
							printf("ERROR..EL CENSISTA DEBE ESTAR LIBERADO\n");
						}
					}else{
						printf("ERROR..ID INVALIDO\n");
					}
					break;
				case 5:
					opcion = 'n';
					break;
				}

				}while(opcion!='n');


			}
		}
	}

	return retorno;
}

int subMenuZonas(Zonas sZonas[], int lenZonas, int id,Censista sCensista[],int lenCensista)
{
	int opcion;
	int index;
	index = buscarZonaById(sZonas, lenZonas, id);
	system("cls");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("                               INGRESE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR                 SALIR[5] \n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Num.Zona   LOCALIDAD[1]                     RADIO DE LA ZONA[2]                ESTADO[3]      CENSISTA[4]     \n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	mostrarZona(sZonas[index],sCensista,lenCensista);
	utn_getNumero(&opcion, "Indique opcion: ","eRROR..Opcion invalida",5, 1, 3);

	return opcion;
}

int bajaZonas(Zonas sZonas[],int lenZonas,Censista sCensista[],int lenCensista, int arrayLocalidades[]) {
	int retorno = -1;
	int auxIdZona;
	int indexZona;
	char opcion;
	if(sZonas != NULL && lenZonas > 0 && sCensista != NULL && lenCensista > 0){
		if(utn_getNumero(&auxIdZona, "Ingrese numero de zona a dar de baja: ", "eRROR..Zona invalida",9999, 0, 3)==0
				&& (indexZona = buscarZonaById(sZonas, lenZonas, auxIdZona))!=-1){

			mostrarZona(sZonas[indexZona], sCensista, lenCensista);
			if(utn_getCaracterSoN(&opcion, "Confirma DAR DE BAJA a esta zona?(S/N): ", "Error, ingrese S/N", 's', 'n', 3)==0
			&& opcion == 's'){

				arrayLocalidades[sZonas[indexZona].localidad]--;
				if(sZonas[indexZona].idCensista!=-1){
					sCensista[buscarCensistaById(sCensista, lenCensista, sZonas[indexZona].idCensista)].estadoCensista=LIBERADO;
					//Si el censista ya fue asignado antes, se le cambiara el estado por LIBERADO al censista de antes
				}
				sZonas[indexZona].isEmpty = 1;
				retorno = 0;
			}

		}else{
			printf("No se encontro la zona\n");
		}
	}


	return retorno;
}

int hardcodeoZonas(Zonas sZonas[], int lenZonas,Censista sCensista[],int lenCensista) {
	int retorno = -1;
	int auxIndex;
	Zonas sHardcodZona[LEN_HARCOD_ZONAS]=
	{{PENDIENTE, {"Ayolas","Tucuman","Int.Pedro Oliveri","Beruti"},QUILMES,0 ,autoIncrementarIdZonas(),-1,0,0,0 },
	{PENDIENTE, {"1° de Mayo","Rodolfo Lopez","La Rioja","C.389"},AVELLANEDA,0 ,autoIncrementarIdZonas(),-1,0,0,0 },
	{PENDIENTE, {"Av.Lamadrid","Favaloro","Zorilla","9 de Julio"},BERAZATEGUI,0 ,autoIncrementarIdZonas(),-1,0,0,0 },
	{PENDIENTE, {"Gral.Lavalle","Alsina","San Martin","Chacabuco"},AVELLANEDA,0 ,autoIncrementarIdZonas(),-1,0,0,0},
	{PENDIENTE, {"Gral.Paz","Av. Programacion","MitreS","C.814"},QUILMES,0 ,autoIncrementarIdZonas(),-1,0,0,0}};


	if(sZonas != NULL && lenZonas > 0 && sCensista != NULL && lenCensista > 0) {

		auxIndex = buscarEspacioLibreZonas(sZonas, lenZonas);
		for(int i = 0; i < LEN_HARCOD_ZONAS; i++){
			sZonas[auxIndex]=sHardcodZona[i];
			auxIndex++;
		}
		retorno = 0;
	}

	return retorno;
}
