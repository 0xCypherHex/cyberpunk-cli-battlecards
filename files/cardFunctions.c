#include "cardPrototypes.h"
#include <stdio.h>
#include <stdlib.h>

void displayHumanCard(struct StHumanCards *pCard) {
  printf("+----------------------------------+\n");
  printf("| %s\n", pCard->szName);
  printf("+----------------------------------+\n");
  printf("%s\n", pCard->szAsciiArt);
  printf("+----------------------------------+\n");
  printf("| Payload:       %d\n", pCard->iPayload);
  printf("| Passive Regen: %d\n", pCard->iPassiveRegen);
  printf("| Active Heal:   %d\n", pCard->iActiveHeal);
  printf("| Integrity:     %d\n", pCard->iIntegrity);
  printf("| Crit Chance:   %.1f%%\n", pCard->fCritChance);
  printf("+----------------------------------+\n");
}

void displayMachineCard(struct StMachineCards *pCard) {
  printf("+----------------------------------+\n");
  printf("| %s\n", pCard->szName);
  printf("+----------------------------------+\n");
  printf("%s\n", pCard->szAsciiArt);
  printf("+----------------------------------+\n");
  printf("| Payload:       %d\n", pCard->iPayload);
  printf("| Passive Regen: %d\n", pCard->iPassiveRegen);
  printf("| Defense:       %.1f%%\n", pCard->fDefense);
  printf("| Integrity:     %d\n", pCard->iIntegrity);
  printf("| Crit Chance:   %.1f%%\n", pCard->fCritChance);
  printf("+----------------------------------+\n");
}

// Esta función llena un arreglo con una cantidad determinada (iCount) de
// números aleatorios entre 0 y iMax - 1, asegurando que ninguno se repita.
// iCount: Cuantos números únicos necesitamos (3 cartas para cada jugador).
void getUniqueIndices(int iIndices[], int iCount, int iMax) {

  int iPicked = 0; // Contador de indices validos que llevamos guardados

  // Este ciclo se repite hasta conseguir la cantidad de indices pedidos
  while (iPicked < iCount) {

    // Generamos un indice pedido entre 0 y iMax
    int iRandIndice = rand() % iMax;

    // Esta es una bandera que indica si el número se repitió
    // 0 = no repetido; 1 = repetido
    int iFlagDuplicate = 0;

    // Recorremos los indices guardados anteriormente
    for (int i = 0; i < iPicked; i++) {

      // Si el indice se repite sale del for
      if (iIndices[i] == iRandIndice) {

        iFlagDuplicate = 1;
        break;
      }
    }

    // Si iFlagDuplicate == 0
    if (!iFlagDuplicate) {

      // Guarda el número genrado en la siguiente posicion libre
      iIndices[iPicked] = iRandIndice;
      iPicked++;
    }
  }
}