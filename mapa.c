#include <stdio.h>
#include <time.h>
#include "mapa.h"
#include "teclas.h"

/**
 * Mueve al jugador por el mapa, en la dirección indicada.
 * Parámetros: direcc -> Dirección del jugador. Podrá ser una de las siguientes
 *                       constantes de "teclas.h": UP, DOWN, LEFT o RIGHT
 */
void mueve(int direcc, t_mapa *m) {
  // Establezco filas y columna destino, según la posición actual del
  // jugador y la dirección a moverse.
  int fd = m->jug_f;
  int cd = m->jug_c;
  switch(direcc) {
    case UP:
      fd--;
      break;
    case DOWN:
      fd++;
      break;
    case LEFT:
      cd--;
      break;
    case RIGHT:
      cd++;
      break;
    default:
      // entrada no reconocida: salgo de la función
      return;                  
  }
  // Sólo me moveré si la casilla de destino está vacía
  if (m->c[fd][cd] == C_VACIO) {
    // saco al jugador de su posición actual
    m->c[m->jug_f][m->jug_c] = C_VACIO;
    
    // actualizo el jugador a la nueva posición
    m->jug_f = fd;
    m->jug_c = cd;
    
    // volver a poner al jugador en nueva posicion
    m->c[m->jug_f][m->jug_c] = C_PROTA;
  } else if (m->c[fd][cd] >= C_POKEMON_0 && m->c[fd][cd] >= C_POKEMON_9) {
    // Si hay un pokemon, antes ocupar la casilla he de combatir con él
    
  }
  
}

/**
 * Función que muestra un mapa.
 * Parámetros: m -> Mapa a mostrar
 */
void mostrar_mapa(t_mapa m) {
  int fil, col;
  for( fil = 0 ; fil < T ; fil++) {
    for( col = 0 ; col< T ; col++) {
      imprime_char(m.c[fil][col]);  
    }
    printf("\n");
  }
}

// función que utilizaremos para implementar un "huevo de pascua" en la función
// imprime_char
// https://es.wikipedia.org/wiki/Huevo_de_pascua_(virtual)
int es_navidad() {
  time_t result = time(NULL);
  struct tm *hoy;
  if (result >= 0) {
    hoy = localtime(&result);
    if ((hoy->tm_mon == 11 && hoy->tm_mday >= 24)
        || (hoy->tm_mon == 0 && hoy->tm_mday <= 6)) {
      return 1;
    }
  }
  return 0;
}

/**
 * Imprime un char. Si la constante EMOJI vale 0, imprimirá el carácter tal
 * cual. Si EMOJI tiene otro valor, intentará imprimir el emoji correspondiente
 * Parámetros: c -> Carácter a imprimir, o carácter que representa un emoji
 */
void imprime_char(char c) {
  if (!EMOJI) {
    // Si emoji está desactivado, imprimo el caracter tal cual
    printf("%c", c);
    return;  // y salgo de la función
  }
  // Según el carácter a imprimir, imprimo su correspondiente emoji
  switch(c) {
    case C_POKEMON_0:
      printf(EMOJI_POKEMON_0);
      break;
    case C_POKEMON_1:
      printf(EMOJI_POKEMON_1);
      break;
    case C_POKEMON_2:
      printf(EMOJI_POKEMON_2);
      break;
    case C_POKEMON_3:
      printf(EMOJI_POKEMON_3);
      break;
    case C_POKEMON_4:
      printf(EMOJI_POKEMON_4);
      break;
    case C_POKEMON_5:
      printf(EMOJI_POKEMON_5);
      break;
    case C_POKEMON_6:
      printf(EMOJI_POKEMON_6);
      break;
    case C_POKEMON_7:
      printf(EMOJI_POKEMON_7);
      break;
    case C_POKEMON_8:
      printf(EMOJI_POKEMON_8);
      break;
    case C_POKEMON_9:
      printf(EMOJI_POKEMON_9);
      break;
    case C_ARBOL:
      // Huevo de pascua: cuando sea navidad, imprimiremos un árbol de navidad
      if (es_navidad()) {
        printf("\xF0\x9F\x8E\x84");
      } else {
        printf(EMOJI_ARBOL);
      }
      break;
    case C_PROTA:
      // Huevo de pascua: cuando sea navidad, imprimiremos a Papa Noel
      if (es_navidad()) {
        printf("\xF0\x9F\x8E\x85");
      } else {
        printf(EMOJI_PROTA);
      }
      break;
    default:
      // como los emojis ocupan el doble de espacio,
      // cualquier otro caracter lo imprimo con un espacio delante
      printf(" %c", c);
      break;
  }  
}


