#include "cardPrototypes.h"
#include <stdio.h>
#include <stdlib.h>

// Funcion privada para acomodar el ArtASCII dentro de la carta
// Usamos una constante en a la direccion del AsciiArt porque solo lo va a leer
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

    // Avanzamos el explorador hasta encontrar un salto de linea en la cadena
    while (*pCursor != '\0' && *pCursor != '\n') {

      /*
          Encontrar un caracter real (que se pueda visualizar):

          En el estándar UTF-8, los bytes se identifican por sus primeros bits:

          1-. Carácter ASCII normal: empieza con 0...

          2-. Primer byte de un símbolo especial: empieza con 11...

          3-. Bytes extra (de continuación) de ese mismo símbolo: siempre
          empiezan con 10...

          La operación hace esto en binario:

          4-. 0xC0 en binario es 11000000. Al hacer & 0xC0, apagamos los últimos
         6 bits y nos quedamos solo con los 2 primeros bits

          5-. 0x80 en binario es 10000000

          6-. Si el resultado es distinto de 0x80 (!= 0x80), significa que ese
         byte es el inicio de un carácter real y sumamos iVisualLen++. Si es
         igual a 0x80, es solo un byte extra de relleno de un símbolo que ya
         contamos, así que lo ignoramos

          */

      // (c & 0xC0) != 0x80 Con esta condición contamos los caracteres de una
      // cadena que no son de continuación.
      // Byte de continuación en UTF-8 = 0x80
      // decimos que si el caracter es especial con el operador de bitwise AND
      // comparando los 8 bits de un byte con los 8 bits de 0xC0 y es diferente
      // de 0x80
      if (((unsigned char)*pCursor & 0xC0) != 0x80) {

        iVisualChar++;
      }
      pCursor++; // Movemos el explorador al siguiente byte
    }

    /*
      Aqui realizamos operaciones con punteros para saber cuantos bytes mide
      cada linea y saber los espacios que hay a la derecha y a la izquierda para
      evitar que el texto se descuadre y pasarselo al printf
    */

    // Primero restamos los punteros para obtener los bytes de una linea
    int iByteLine = (int)(pCursor - pLineStart);

    // Despues obtenemos la cantidad de espacios a la izquierda: la mitad del
    // espacio sobrante Tenemos que dividir entre dos para eliminar decimales y
    // redondear y contar al borde | y siempre de los caracteres exactos
    int iLeftPad = (iSizeWitdh - iVisualChar) / 2;

    // Espacios a la derecha: el resto exacto, evitamos que se desborde.
    int iRightPad = iSizeWitdh - iVisualChar - iLeftPad;

    // Evitar valores nevativos
    if (iLeftPad < 0)
      iLeftPad = 0;
    if (iRightPad < 0)
      iRightPad = 0;

    // Imprime: '|' + espacios izq + la línea exacta por bytes + espacios der +
    // '|'
    printf("|%*s%.*s%*s|\n", iLeftPad, "", iByteLine, pLineStart, iRightPad,
           "");

    // Si nos encontramos con un salto de linea '\n' pasamos a la siguiente
    // linea
    if (*pCursor == '\n') {

      pLineStart = pCursor + 1;
    } else if (*pCursor == '\0') {

      // Si no encontramos con el caracter nulo significa que ya termino y nos
      // salimos del ciclo
      break;
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