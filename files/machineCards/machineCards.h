
// Include Guards
#ifndef MACHINECARDS_H
#define MACHINECARDS_H

struct StMachineCards {

  char szName[50];           // Nombre del personaje
  char szDescription[120];   // Descripción
  int iPayload;              // Ataque (Payload)
  int iEncryptionRegen;      // Regeneración pasiva (Encryption)
  int iDefense;              // Defensa / Probabilidad de esquivar
  int iIntegrity;            // HP (Integrity sobre 200)
  char szSpecialName[60];    // Nombre del ataque especial
  char szSpecialDesc[150];   // Descripción del ataque especial
  char szSpecialAction[150]; // Efecto especial
};

// Para que main.c pueda ver el mazo
extern struct StMachineCards MachineDeck[];

#endif