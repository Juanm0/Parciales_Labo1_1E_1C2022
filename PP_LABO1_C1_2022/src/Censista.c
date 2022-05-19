/*
 * Censista.c
 *
 *  Created on: 19 may. 2022
 *      Author: Juan-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Censista.h"
#include "utn.h"


int autoIncrementarId()
{
    static int id = 1000;
    id++;
    return id;
}

int menu(void)
{
	int opcion;
	system("cls");
	printf("[***MENU PRINCIPAL***]\n\n");
	    	printf("1. CARGAR CENSISTA\n");
	    	printf("2. MODIFICAR CENSISTA\n");
	    	printf("3. DAR DE BAJA CENSISTA\n");
	    	printf("4. CARGAR ZONA\n");
	    	printf("5. ASIGNAR UNA ZONA A CENSAR\n");
	    	printf("6. CARGA DE DATOS\n");
	    	printf("7. MOSTRAR CENSISTAS\n");
	    	printf("8. MOSTRAR ZONAS\n");
//	    	printf("10. HARDCODEO DE ZONAS Y CENSISTAS\n");
//	    	printf("11. MODIFICAR ZONA\n");
//	    	printf("12. DAR DE BAJA UNA ZONA\n");
	    	printf("9. SALIR\n");
	utn_getNumero(&opcion, "Ingrese opcion: ","eRROR..OPCION invalida", 9, 1, 3);
	//para usar todas las opciones cambiar el 9 por el 12

	return opcion;
}

int initCensista (Censista pArray[],int len) {
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

int altaCensista (Censista pArray[],int len) {
	int retorno=-1;
	int index;
	index=buscarEspacioLibre(pArray, len);
	if(pArray != NULL && len > 0 && index != -1) {

		system("cls");
		printf("  ******Alta de Censistas***** \n\n");
		if(utn_getNombre(pArray[index].nombre, sizeof(pArray[index].nombre), "Ingrese nombre: ", "eRROR..Nombre invalido", 3)==0
		&& utn_getNombre(pArray[index].apellido, sizeof(pArray[index].nombre), "Ingrese apellido: ", "eRROR..Apellido invalido", 3)==0
		&& utn_getNumero(&pArray[index].fechaNac.dia, "[FECHA DE NACIMIENTO]\nIngrese dia: ", "eRROR..Dia invalido", 31, 1, 3)==0
		&& utn_getNumero(&pArray[index].fechaNac.mes, "Ingrese mes: ", "eRROR..Ingrese el mes en numero, ej: ENERO = 1", 12, 1, 3)==0
		&& utn_getNumero(&pArray[index].fechaNac.anio, "Ingrese anio: ", "eRROR..Anio invalido", 2023, 1800, 3)==0
		&& utn_getDescripcion(pArray[index].domicilio.calle,sizeof(pArray[index].domicilio.calle), "[DOMICILIO]\nIngrese calle: ", "eRROR..Calle invalida",3)==0
		&& utn_getNumero(&pArray[index].domicilio.altura,"Ingrese altura: ","eRROR..Altura invalida", 20000,0, 3)==0)
		{
			pArray[index].edad = 2022 - pArray[index].fechaNac.anio;
			pArray[index].idCensista = autoIncrementarId();
			pArray[index].isEmpty = 0;
			pArray[index].estadoCensista = LIBERADO;
			retorno = 0;
		}
	}

	return retorno;
}

int buscarEspacioLibre(Censista pArray[], int len) {

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

int modificarCensista(Censista pArray[], int len) {

	int retorno=-1;
	int auxId;
	int index;
	char opcion;
	int auxOpcion;
	system("cls");
	printf("    ****   MODIFICAR CENSISTA   ****  \n\n");
	utn_getNumero(&auxId, "Ingrese ID: ", "Error, el id ingresado es invalido", 9999, 0, 3);
	if(pArray != NULL && len > 0 && auxId > 0) {
		index = buscarCensistaById(pArray, len, auxId);
		if(index != -1) {
			mostrarCensista(pArray[index]);
			utn_getCaracterSoN(&opcion, "Confirma MODIFICAR a este censista?(S/N): ", "Error, ingrese S/N", 's', 'n', 3);
			if(opcion == 's') {
				retorno = 0;
				do {
					switch(subMenu(pArray, len, auxId)){
					case 1:
						utn_getNombre(pArray[index].nombre, sizeof(pArray[index].nombre), "Ingrese nuevo Nombre: ", "eRROR..Nombre invalido", 3);
						break;
					case 2:
						utn_getNombre(pArray[index].apellido, sizeof(pArray[index].apellido), "Ingrese nuevo Apellido: ", "eRROR..Apellido invalido", 3);
						break;
					case 3:
						utn_getNumero(&auxOpcion, "Que quiere modificar?\n[1]DIA\n[2]MES\n[3]ANIO\nIndique opcion: ", "eRROR..Opcion invalida", 3, 1, 3);
						switch(auxOpcion) {
						case 1:
							utn_getNumero(&pArray[index].fechaNac.dia, "Ingrese nuevo dia: ", "eRROR..Dia invalido", 31, 1, 3);
							break;
						case 2:
							utn_getNumero(&pArray[index].fechaNac.mes, "Ingrese nuevo mes: ", "eRROR..Ingrese el mes en numero, ej: MARZO = 3", 12, 1, 3);
							break;
						case 3:
							if((utn_getNumero(&pArray[index].fechaNac.anio, "Ingrese anio: ", "eRROR..Anio invalido", 2004, 1800, 3))==0){
								pArray[index].edad = 2022 - pArray[index].fechaNac.anio;
							}
							break;
							auxOpcion=-1;
						}

						break;
					case 4:
						utn_getNumero(&pArray[index].edad, "Ingrese nueva edad: ", "eRROR..Edad invalida",2022 - pArray[index].fechaNac.anio,2021 - pArray[index].fechaNac.anio, 3);
						break;
					case 5:
						utn_getNumero(&auxOpcion, "Que quiere modificar?\n[1]CALLE\n[2]ALTURA\nIndique opcion: ", "eRROR..Opcion invalida", 2, 1, 3);
						switch(auxOpcion) {
						case 1:
							utn_getDescripcion(pArray[index].domicilio.calle,sizeof(pArray[index].domicilio.calle), "Ingrese nueva calle: ", "eRROR..Calle invalida",3);
							break;
						case 2:
							utn_getNumero(&pArray[index].domicilio.altura,"Ingrese nueva altura: ","eRROR..Altura invalida", 20000,0, 3);
							break;
							auxOpcion = -1;
						}
						break;
					case 6:
						opcion = 'n';
						break;
					}

				}while(opcion=='s');
			}
		}
	}

	return retorno;
}

int buscarCensistaById(Censista pArray[],int len,int id) {

	int retorno = -1;
	if(pArray != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {

			if (pArray[i].isEmpty == 0 && pArray[i].idCensista == id) {
				retorno = i;
				break;
		    }
		}
	}
	return retorno;//Si retorno es -1 quiere decir que no hay espacios libres
}

void mostrarCensista(Censista unCensista) {

	char estado[51];
	if(unCensista.isEmpty == 0) {

		switch(unCensista.estadoCensista){
		case ACTIVO:
			strncpy(estado,"ACTIVO",sizeof(estado));
			break;
		case LIBERADO:
			strncpy(estado,"LIBERADO",sizeof(estado));
			break;
		case INACTIVO:
			strncpy(estado,"INACTIVO",sizeof(estado));
			break;
		}

		printf("|%d|%-10s|%-15s|%02d/%02d/%-10d|%-10d|%-10s %d|%-10s|\n",
				unCensista.idCensista,
				unCensista.nombre,
				unCensista.apellido,
				unCensista.fechaNac.dia,
				unCensista.fechaNac.mes,
				unCensista.fechaNac.anio,
				unCensista.edad,
				unCensista.domicilio.calle,
				unCensista.domicilio.altura,
				estado
				);
		for(int i = 0; i<17;i++){
					printf("-----+");
					if(i==16){
						printf("\n");
					}
				}

	}
}

int subMenu(Censista sCensista[], int len, int id)
{
	int opcion;
	int index;

	index = buscarCensistaById(sCensista, len, id);
	system("cls");
	printf("     *******************  INGRESE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR  ****************** \n");
	printf("---------------------------------------------------------------------------------------------------\n");
	printf("ID    NOMBRE[1]     APELLIDO[2]   FECHA DE NAC.[3]  EDAD[4]    DOMICILIO[5]    ESTADO     SALIR[6]\n");
	printf("----------------------------------------------------------------------------------------------------\n");
	mostrarCensista(sCensista[index]);
	utn_getNumero(&opcion, "Indique opcion: ","eRROR..Opcion invalida",6, 1, 3);

	return opcion;
}

int bajaCensista(Censista pArray[],int len) {
	int retorno = -1;
	int auxId;
	int index;
	char opcion;

	if(pArray != NULL && len > 0) {

		system("cls");
		printf("    ****   DAR DE BAJA A CENSISTA   ****  \n\n");
		if(utn_getNumero(&auxId, "Ingrese ID: ", "eRROR..ID invalido", 9999, 0, 3)==0
		&& (index = buscarCensistaById(pArray, len, auxId))!=-1) {

			if(pArray[index].estadoCensista != ACTIVO){
						mostrarCensista(pArray[index]);
						utn_getCaracterSoN(&opcion, "Esta seguro de que desea DAR DE BAJA a este censista?(s/n): ","eRROR..Ingrese (S/N)", 's', 'n', 3);
						if(opcion == 's'){
							pArray[index].estadoCensista = INACTIVO;
							retorno = 0;
						}
					}else{
						printf("El censista esta activo y no puede darlo de baja\n");
					}

				}else{
					printf("Censista no encontrado\n");
				}
		}





	return retorno;
}

int listarCensista(Censista pArray[],int len) {

	int retorno = -1;

	if(pArray != NULL && len > 0)
	{
		printf("     ***************************  LISTA DE CENSISTAS  ********************************     \n");
		printf("-----------------------------------------------------------------------------------------\n");
		printf("ID    NOMBRE     APELLIDO        FECHA DE NAC.      EDAD      DOMICILIO         ESTADO  \n");
		printf("------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < len; i++)
		{
			mostrarCensista(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int hardcodeoCensista(Censista sCensista[],int lenCensista) {
	int retorno = -1;
	int auxIndex;
	Censista sHardcodCensista[LEN_HARCOD_CENSISTA]= {{"Juan", "Navarro", 21,{14,4,2000} ,{"Colon",3245},LIBERADO,autoIncrementarId(),0 },
													{"Franco", "Carrizo", 18,{12,5,2004} ,{"Av.Roca",6345},LIBERADO,autoIncrementarId(),0 },
													{"Gabriel", "Perez", 42,{17,2,1980} ,{"Paso",3456},LIBERADO,autoIncrementarId(),0 },
													{"Paula", "Medina", 22,{6,3,2000} ,{"H.Primo",9844},LIBERADO,autoIncrementarId(),0 },
													{"Camila", "Guerrero", 30,{28,1,1992} ,{"Laprida",1213},LIBERADO,autoIncrementarId(),0}};
	if( sCensista != NULL && lenCensista > 0) {

		auxIndex = buscarEspacioLibre(sCensista, lenCensista);
		for(int i = 0; i < LEN_HARCOD_CENSISTA; i++){
			sCensista[auxIndex]=sHardcodCensista[i];
			auxIndex++;
		}
		retorno = 0;
	}

	return retorno;
}
