// Prototipos
#ifndef CARD_H
#define CARD_H

#include "humanCards/humanCards.h"
#include "machineCards/machineCards.h"

// Mostrar cartas
void displayHumanCard(struct StHumanCards *pCard);
void displayMachineCard(struct StMachineCards *pCard);

// Barajear Cartas - Obtener cartas sin repetir
void getUniqueIndices(int aiIndices[], int iCount, int iMax);

#endif