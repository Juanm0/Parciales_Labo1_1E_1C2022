/*
 * Informes.c
 *
 *  Created on: 19 may. 2022
 *      Author: Juan-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Zonas.h"
#include "Censista.h"
#include "Informes.h"



int cantidadCensistasActivosConZonaPendiente(Zonas sZonas[], int lenZona, Censista sCensista[], int lenCensista) {

//	a. Informar cantidad de censistas en estado Activo con zona Pendiente.
	int retorno = -1;
	int contadorCensistas=0;
	int indexCensista;
	if(sZonas != NULL && lenZona > 0 && sCensista != NULL && lenCensista > 0) {


		for(int i = 0; i<lenZona; i++){
				if(sZonas[i].estadoZona == PENDIENTE){

					if(sZonas[i].isEmpty == 0 && sZonas[i].idCensista != -1){

						if((indexCensista = buscarCensistaById(sCensista, lenCensista, sZonas[i].idCensista))!=-1 &&
							sCensista[indexCensista].estadoCensista == ACTIVO)  {

							contadorCensistas++;
							retorno = 0;
						}
					}

				}

			}
			if(contadorCensistas != 0){
				printf("La cantidad de censistas en estado ACTIVO y con zonas PENDIENTES es de %d censistas\n",contadorCensistas);
			}else{
				printf("No hubo censistas estado ACTIVO y con zonas PENDIENTES\n");
			}


	}

	return retorno;
}



int nombreLocalidadMasAusentes(Zonas sZonas[], int lenZona, Censista sCensista[], int lenCensista) {

//	c. Informar nombre de localidad con más casas ausentes.
	int retorno = -1;
	int maximoAvellaneda=0;
	int maximoLanus=0;
	int maximoLomas=0;
	int maximoBanfield=0;


	if(sZonas != NULL && lenZona > 0 && sCensista != NULL && lenCensista > 0) {

		for(int i = 0; i<lenZona; i++){

					if(sZonas[i].estadoZona == FINALIZADO && sZonas[i].isEmpty == 0){

						if(sZonas[i].localidad == AVELLANEDA){

							maximoAvellaneda = maximoAvellaneda + sZonas[i].cantCenAusentes;

						}
						if(sZonas[i].localidad == LANUS){

							maximoLanus = sZonas[i].cantCenAusentes;

						}
						if(sZonas[i].localidad == LOMAS_DE_ZAMORA){

							maximoLomas = sZonas[i].cantCenAusentes;

						}
						if(sZonas[i].localidad == BANFIELD){

							maximoBanfield = sZonas[i].cantCenAusentes;

						}


					}else{
						printf("No hay zonas finalizadas todavia\n");
					}

				}
				if(maximoAvellaneda > maximoLanus && maximoAvellaneda > maximoLomas && maximoAvellaneda > maximoBanfield){
					printf("La localidad que tuvo mas casas ausentes es AVELLANEDA\n");
				}
				if(maximoLanus > maximoAvellaneda && maximoLanus > maximoLomas && maximoLanus > maximoBanfield){
					printf("La localidad que tuvo mas casas ausentes es LANUS\n");
				}
				if(maximoLomas > maximoAvellaneda && maximoLomas > maximoLanus && maximoLomas > maximoBanfield){
					printf("La localidad que tuvo mas casas ausentes es LOMAS DE ZAMORA\n");
				}
				if(maximoBanfield > maximoAvellaneda && maximoBanfield > maximoLomas && maximoBanfield > maximoLanus){
					printf("La localidad que tuvo mas casas ausentes es BANFIELD\n");
				}


	}

	return retorno;
}

int censistaConZonaMasCensada(Zonas sZonas[], int lenZona, Censista sCensista[], int lenCensista) {
//	d. Informar el censista cuya zona fue la más censada (total censados presencial y virtual)
	int retorno = -1;
	int maximoZona=0;
	int indexCensista=-1;
	int auxZonas;

	if(sZonas != NULL && lenZona > 0 && sCensista != NULL && lenCensista > 0) {


		for(int i = 0; i<lenZona; i++){
					if(sZonas[i].estadoZona == FINALIZADO && sZonas[i].isEmpty==0 ){

						auxZonas = (sZonas[i].cantCenInSitu + sZonas[i].cantCenDigital);
						if(auxZonas > maximoZona){

							maximoZona = auxZonas;
							indexCensista = buscarCensistaById(sCensista, lenZona, sZonas[i].idCensista);
						}

					}

				}
				if(indexCensista != -1){
					printf("El censista cuya zona fue la más censada (total censados presencial y virtual) es: %s con %d personas censadas\n",sCensista[indexCensista].nombre,maximoZona);
				}else{
					printf("No se encontro un censista con una zona mas censada\n");
				}


	}


	return retorno;
}
