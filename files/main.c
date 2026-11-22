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
  Funcion srand de la biblioteca <stdlib.h> y <time.h> para time(NULL)

  Significdo de esta sintaxis:

  srand (unsigned int)time(NULL);

srand(...): Función de <stdlib.h> que recibe un entero sin signo (unsigned int)
y establece el punto de partida de rand(). Solo debe llamarse una vez al inicio
de main().

time(NULL): Función de <time.h> que devuelve el tiempo actual del calendario
(normalmente los segundos transcurridos desde el 1 de enero de 1970, Unix
epoch). Pasar NULL significa que no quieres guardar el resultado en una variable
time_t adicional, solo recibir su valor de retorno.

(unsigned int): Es un cast (conversión explícita de tipo). time() devuelve un
tipo time_t (que puede ser con signo o de 64 bits según la plataforma), mientras
que srand() espera unsigned int. Hacer el cast evita advertencias del compilador
(como conversion from 'time_t' to 'unsigned int' may change value).



  +++¿Para que es ?+++

  Sirve para inicializar la semilla (seed) de la generación de números
  pseudoaleatoreos de C -rand()- usando la hora actual del sistema.

  Usar srand(unsigned int) es necesario ya que la funcion rand() por si sola no
  genera números aleatoreos, si no que utiliza una formula matemática
  determinista a partir de un valor inicial llamado semilla.

  -Sin srand(...): C asume una semilla fija por defecto (usualmente 1). Cada vez
  que ejecutas el programa, rand() escupe exactamente la misma secuencia de
  números.

  -Con srand(time(NULL)): Como la hora del reloj del sistema cambia cada
  segundo, la semilla es distinta en cada ejecución y la secuencia de rand()
  varía.

  time(NULL) te devuelve la cantidad de segundos que han pasado desde el 1 de
  enero de 1970 (un número gigante como 1795233300).

  */
  srand((unsigned int)time(NULL));

  int iHumanIdx[3];
  int iCount = 3;
  int iMax = 12;

  // Función que aleatoriza los indices
  getUniqueIndices(iHumanIdx, iCount, HUMAN_DECK_SIZE);

  displayHumanCard(&astHumanDeck[0]);
  displayMachineCard(&astMachineDeck[0]);

  return 0;
}