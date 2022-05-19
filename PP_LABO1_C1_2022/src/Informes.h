/*
 * Informes.h
 *
 *  Created on: 19 may. 2022
 *      Author: Juan-PC
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Zonas.h"
#include "Censista.h"

int cantidadCensistasActivosConZonaPendiente(Zonas sZonas[], int lenZona, Censista sCensista[], int lenCensista);
int censistaConZonaMasCensada(Zonas sZonas[], int lenZona, Censista sCensista[], int lenCensista);
int nombreLocalidadMasAusentes(Zonas sZonas[], int lenZona, Censista sCensista[], int lenCensista);

#endif /* INFORMES_H_ */
