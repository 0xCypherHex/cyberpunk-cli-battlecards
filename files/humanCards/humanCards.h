
// Include Guards
#ifndef HUMANCARDS_H
#define HUMANCARDS_H

struct StHumanCards {

  char szName[50];         // Nombre del personaje
  char szDescription[120]; // Descripción
  int iPayload;            // Ataque (Payload)
  int iEncryptionRegen;    // Regeneración pasiva (Encryption)
  int iActiveHeal;         // Regeneración activa / Heal
  int iIntegrity;          // Vida (Integrity sobre 500)
  char szSpecialName[60];  // Nombre del ataque especial
  char szSpecialDesc[150]; // Descripción del ataque especial
  char szAction[150];
};

// Para que main.c pueda ver el mazo
extern struct StHumanCards humanDeck[];

#endif
