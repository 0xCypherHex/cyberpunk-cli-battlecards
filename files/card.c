#include "card.h"
#include <stdio.h>

void displayHumans(struct StHumanCards *pCard) {

  printf("+-----------------------------------*");
  printf("| %s\n", pCard->szName);
  printf("+----------------------------------+\n");
  printf("| %s\n", pCard->szName);
  printf("+----------------------------------+\n");
  printf("%s\n", pCard->szAsciiArt);
  printf("| Payload:       %d\n", pCard->iPayload);
  printf("| Passive Regen: %d\n", pCard->iPassiveRegen);
  printf("| Active Heal:   %d\n", pCard->iActiveHeal);
  printf("| Integrity:     %d\n", pCard->iIntegrity);
  printf("| Crit Chance:   %.1f%%\n", pCard->fCritChance);
  printf("+----------------------------------+\n");
}