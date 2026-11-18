
// Include Guards
#ifndef MACHINECARDS_H
#define MACHINECARDS_H

#define MACHINE_DECK_SIZE 12

struct StMachineCards {

  char szName[50];      // Nombre del personaje
  int iPayload;         // Ataque (Payload)
  int iEncryptionRegen; // Regeneración pasiva (Encryption)
  float fDefense;       // Defensa / Probabilidad de esquivar
  int iHPIntegrity;
  float fCritChance;
  char szAsciiArt[1500];
};

// Para que main.c pueda ver el mazo
extern struct StMachineCards MachineDeck[];

#endif
