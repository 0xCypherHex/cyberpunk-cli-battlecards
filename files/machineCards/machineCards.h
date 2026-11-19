// Include Guards
#ifndef MACHINECARDS_H
#define MACHINECARDS_H

#define MACHINE_DECK_SIZE 12

struct StMachineCards {
  char szName[50];   // Character name
  int iPayload;      // Attack (0-100)
  int iPassiveRegen; // Passive Encryption Regen
  float fDefense;    // Defense / Dodge chance (0-100)
  int iIntegrity;    // Health / Integrity (0-200)
  float fCritChance; // Critical hit chance percentage (0-100)
  char szAsciiArt[1500];
};

// Para que main.c pueda ver el mazo
extern struct StMachineCards machineDeck[MACHINE_DECK_SIZE];

#endif
