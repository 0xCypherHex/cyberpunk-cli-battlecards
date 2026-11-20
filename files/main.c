#include "cardPrototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main(void) {
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  srand((unsigned int)time(NULL));

  // LLamada a funciones
  displayHumanCard(&astHumanDeck[0]);
  displayMachineCard(&astMachineDeck[0]);

  return 0;
}