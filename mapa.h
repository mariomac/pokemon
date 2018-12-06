#ifndef _MAPA_H_
#define _MAPA_H_

// Si 0 --> Desactiva Emojis (para terminales antiguos)
#define EMOJI 1

// Chars del mapa, tal y como se representan internamente
#define C_VACIO     ' '
#define C_ARBOL     'A'
#define C_PROTA     '@'
#define C_POKEMON_0 '0'
#define C_POKEMON_1 '1'
#define C_POKEMON_2 '2'
#define C_POKEMON_3 '3'
#define C_POKEMON_4 '4'
#define C_POKEMON_5 '5'
#define C_POKEMON_6 '6'
#define C_POKEMON_7 '7'
#define C_POKEMON_8 '8'
#define C_POKEMON_9 '9'

// Emojis para cada elemento del mapa, según su código estándar
// https://apps.timwhitlock.info/emoji/tables/unicode
#define EMOJI_ARBOL     "\xF0\x9F\x8C\xB2"
#define EMOJI_PROTA     "\xF0\x9F\x98\x8B"
#define EMOJI_POKEMON_0 "\xF0\x9F\x90\x93"
#define EMOJI_POKEMON_1 "\xF0\x9F\x8E\x83"
#define EMOJI_POKEMON_2 "\xF0\x9F\x90\xB8"
#define EMOJI_POKEMON_3 "\xF0\x9F\x90\xB7"
#define EMOJI_POKEMON_4 "\xF0\x9F\x90\x9D"
#define EMOJI_POKEMON_5 "\xF0\x9F\x98\xBB"
#define EMOJI_POKEMON_6 "\xF0\x9F\x90\xA5"
#define EMOJI_POKEMON_7 "\xF0\x9F\x90\x80"
#define EMOJI_POKEMON_8 "\xF0\x9F\x98\x88"
#define EMOJI_POKEMON_9 "\xF0\x9F\x92\xA9"

// Tamaño del mapa
#define T 12

typedef struct {
  int jug_f, jug_c; // posición del jugador
  char c[T][T+1];
} t_mapa;

// Prototipos de las funciones. Su implementación está en mapas.c

/**
 * Función que muestra un mapa.
 * Parámetros: m -> Mapa a mostrar
 */
void mostrar_mapa(t_mapa m);

/**
 * Mueve al jugador por el mapa, en la dirección indicada.
 * Parámetros: direcc -> Dirección del jugador. Podrá ser una de las siguientes
 *                       constantes de "teclas.h": UP, DOWN, LEFT o RIGHT
 */
void mueve(int direcc, t_mapa *m);

/**
 * Imprime un char. Si la constante EMOJI vale 0, imprimirá el carácter tal
 * cual. Si EMOJI tiene otro valor, intentará imprimir el emoji correspondiente
 * Parámetros: c -> Carácter a imprimir, o carácter que representa un emoji
 */
void imprime_char(char c);

#endif






