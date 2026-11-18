

/*
#ifndef (if not defined) pregunta si la etiqueta HUMANCARDS_H fue leida antes,
si YA existe  se salta todo hasta endif, si NO existe, entra y lee todo el
archivo. Es una medida de seguridad.
*/
#ifndef HUMANCARDS_H
#define HUMANCARDS_H

// Macro que define el tamaño del arreglo
#define HUMAN_DECK_SIZE 12

struct StHumanCards {
  char szName[50];
  char szDescription[120];
  int iPayload;      // Attack (0-50)
  int iPassiveRegen; // Passive Encryption Regen (5%)
  int iActiveHeal;   // Active Heal
  int iIntegrity;    // Health / Integrity (0-500)
  int iCritChance;   // Critical hit chance percentage (0-100)
  char szAsciiArt[1500];
};

/*
EXTERN se usa para declarar que el arreglo tipo estructura "humanDeck" existe
pero sus datos estan definidos en otro archivo (humanCards.c) con esto
permitimos que main.c acceda al arreglo sin duplicar la variable en memoria.
*/
extern struct StHumanCards humanDeck[HUMAN_DECK_SIZE];

#endif
