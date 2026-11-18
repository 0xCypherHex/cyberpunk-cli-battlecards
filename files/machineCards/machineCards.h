
// Include Guards
#ifndef MACHINECARDS_H
#define MACHINECARDS_H

struct StMachineCards {

  char szName[50];           // Nombre del personaje
  int iPayload;              // Ataque (Payload)
  int iEncryptionRegen;      // Regeneración pasiva (Encryption)
  int iDefense;              // Defensa / Probabilidad de esquivar
  int iHPIntegrity;
  int iCritChance; // HP (Integrity sobre 200)
};

// Para que main.c pueda ver el mazo
extern struct StMachineCards MachineDeck[];

#endif
