#include "card.h"
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

void getUniqueIndices(int iIndices[], int iCount, int iMax) {
  int iPicked = 0;

  while (iPicked < iCount) {
    int iRand = rand() % iMax;
    int iDuplicate = 0;

    for (int i = 0; i < iPicked; i++) {
      if (iIndices[i] == iRand) {
        iDuplicate = 1;
        break;
      }
    }

    if (!iDuplicate) {
      iIndices[iPicked] = iRand;
      iPicked++;
    }
  }
}