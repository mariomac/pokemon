#ifndef _POKEMON_H_
#define _POKEMON_H_

#define MAX_NPOK 100

#define ESTADO_SUENYO     's'
#define ESTADO_ENVENENADO 'v'
#define ESTADO_BIEN       'b'
#define ESTADO_CONFUSION  'c'

#define RES_OK 0
#define RES_NO_ENCONTRADO -1
#define RES_INDISPUESTO -2

// Datos de un pokemon
typedef struct {
  char nombre[MAX_NPOK];
  int vida;
  char estado;
  // cuando el estado no es ESTADO_BIEN, el numero de turnos que quedan para que se ponga bien
  int turnos_para_bien;
} t_pokemon;

// Bolsa de pokemon. Lo implementamos como una lista, con un un número variable de pokemons
typedef struct {
  int num;
  t_pokemon pok[MAX_NPOK];
} t_bolsa_pokemon;

// Muestra por pantalla los datos de un pokemon
void mostrar_pokemon(t_pokemon p);

// Busca un pokemon por nombre. Si se encuentra y está en buen estado, se saca de *bolsa y se copia en *p,
// y retorna RES_OK.
// Si el pokemon no existe, retorna RES_NO_ENCONTRADO.
// Si el pokemon existe pero su estado no es ESTADO_BIEN, no lo saca de la bolsa, y retorna un RES_INDISPUESTO
int sacar_pokemon(char *nombre, t_bolsa_pokemon *bolsa, t_pokemon *p);

#endif
