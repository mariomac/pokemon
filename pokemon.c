#include <stdio.h>

#include "mapa.h"
#include "teclas.h"

#include "pokemon.h"
#include <string.h>

void mostrar_pokemon(t_pokemon p) {
  printf("%s (estado: %c, vida: %d)\n",
    p.nombre, p.estado, p.vida);
}

int sacar_pokemon(char *nombre, t_bolsa_pokemon *bolsa, t_pokemon *p) {
  int pos = 0;
  while (pos < bolsa->num &&
        strcasecmp(nombre, bolsa->pok[pos].nombre) != 0) {
    pos++;
  }
  if (pos >= bolsa->num ) {
    return RES_NO_ENCONTRADO;
  }
  if (bolsa->pok[pos].estado != ESTADO_BIEN) {
    return RES_INDISPUESTO;
  }
  *p = bolsa->pok[pos];
  
  // FALTA: eliminar el pokemon de la bolsa

  return RES_OK;
}

main() {
  t_mapa m = {
    7, 4, {
    "AAAAAAAAAAAA",
    "AA    A 1 AA",
    "A 0   A2   A",
    "A     AAA3AA",
    "A          A",
    "AAAA       A",
    "A          A",
    "A   @      A",
    "A8     A  AA",
    "A        4 A",
    "AA5 6 7A  AA",
    "AAAAAAAAAAAA",    
  }};


  // bucle principal del juego, que se repetirá mientras no se pulse 'Q'
  int tecla;
  do {
    borrar_pantalla();
    mostrar_mapa(m);
    int i;
    for (i = '0' ; i <= '9' ; i++) {
      imprime_char(i);
    }
    printf("\n");
    for (i = '0' ; i <= '9' ; i++) {
      printf(" %c", i);
    }
    tecla = lee_tecla();
    mueve(tecla, &m);
    
  } while(tecla != CANCEL);
}




















