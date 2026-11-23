#include "cardPrototypes.h"
#include <stdio.h>
#include <stdlib.h>

static void displayCenteredAscii(const char *pszAsciiArt, int iSizeWitdh) {

  if (pszAsciiArt == NULL) {

    return;
  }

  // Apuntamos al primer byte de la linea que vamos a imprimir
  const char *pLineStart = pszAsciiArt;

  // Repetimos hasta llegar al final de la cadena
  while (*pLineStart != '\0') {

    // Puntero explorador que inicia en la linea actual
    const char *pCursor = pLineStart;

    // Contador de caracteres que se ven en pantalla
    int iVisualChar = 0;

    // Avanzamos el explorador hasta encontrar un salto de linea
    while (*pCursor != '\0' && *pCursor != '\n') {

      // Byte de continuación en UTF-8 = 0x80
      if ((unsigned char)*pLineStart && 0xC0 != 0x80) {
      }
    }
  }
}

void displayHumanCard(struct StHumanCards *pCard) {
  printf("+----------------------------------+\n");
  printf("| %-32.32s |\n", pCard->szName);
  printf("+----------------------------------+\n");
  displayCenteredAscii(pCard->szAsciiArt, 34);
  printf("+----------------------------------+\n");
  printf("| Payload:       %17d |\n", pCard->iPayload);
  printf("| Passive Regen: %17d |\n", pCard->iPassiveRegen);
  printf("| Active Heal:   %17d |\n", pCard->iActiveHeal);
  printf("| Integrity:     %17d |\n", pCard->iIntegrity);
  printf("| Crit Chance:   %16.1f%% |\n", pCard->fCritChance);
  printf("+----------------------------------+\n");
}

void displayMachineCard(struct StMachineCards *pCard) {
  printf("+----------------------------------+\n");
  printf("| %-32.32s |\n", pCard->szName);
  printf("+----------------------------------+\n");
  displayCenteredAscii(pCard->szAsciiArt, 34);
  printf("+----------------------------------+\n");
  printf("| Payload:       %17d |\n", pCard->iPayload);
  printf("| Passive Regen: %17d |\n", pCard->iPassiveRegen);
  printf("| Defense:       %16.1f%% |\n", pCard->fDefense);
  printf("| Integrity:     %17d |\n", pCard->iIntegrity);
  printf("| Crit Chance:   %16.1f%% |\n", pCard->fCritChance);
  printf("+----------------------------------+\n");
}
// Esta función llena un arreglo con una cantidad determinada (iCount) de
// números aleatorios entre 0 y iMax - 1, asegurando que ninguno se repita.
// iCount: Cuantos números únicos necesitamos (3 cartas para cada jugador).
void getUniqueIndices(int aiIndices[], int iCount, int iMax) {

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
      if (aiIndices[i] == iRandIndice) {

        iFlagDuplicate = 1;
        break;
      }
    }

    // Si iFlagDuplicate == 0
    if (!iFlagDuplicate) {

      // Guarda el número genrado en la siguiente posicion libre
      aiIndices[iPicked] = iRandIndice;
      iPicked++;
    }
  }
}