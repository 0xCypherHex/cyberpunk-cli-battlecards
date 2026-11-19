// Prototipos

#ifndef CARD_H
#define CARD_H

#include "humanCards/humanCards.h"
#include "machineCards/machineCards.h"

// Mostrar cartas

void displayHumans(struct StHumanCards *pCard);
void displayMachineCards(struct StMachineCards *pCard);

// Barajear Cartas - Obtener cartas sin repetir

void getUniqueIndices(int iIndices[], int iCount, int iMax);

#endif