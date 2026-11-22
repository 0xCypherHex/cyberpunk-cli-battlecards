// Prototipos
#ifndef CARD_H
#define CARD_H

#include "humanCards/humanCards.h"
#include "machineCards/machineCards.h"

// Mostrar cartas
void displayHumanCard(struct StHumanCards *pCard);
void displayMachineCard(struct StMachineCards *pCard);

// Funcion privada para acomodar el ArtASCII dentro de la carta
static void displayCenteredAscii(const char *pszArtAscii, int iSizeWidth);

// Barajear Cartas - Obtener cartas sin repetir
void getUniqueIndices(int Indices[], int iCount, int iMax);

#endif