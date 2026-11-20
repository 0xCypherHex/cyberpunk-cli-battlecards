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

  /*
  Funcion srand

  sintaxis:
  srand (uinsigned int)time(NULL)
  srand(unsigned int seed);

  Sirve para inicializar la generación de números pseudoaleatoreos, el parametro
  seed
  */
  srand((unsigned int)time(NULL));
  void getUniqueIndices(int iIndices[], int iCount, int iMax);

  // LLamada a funciones
  displayHumanCard(&astHumanDeck[0]);
  displayMachineCard(&astMachineDeck[0]);

  return 0;
}