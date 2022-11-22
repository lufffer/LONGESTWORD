#include "longest_word.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("Not file found.\n\nEnter longest_word -h for help");
  } else if (argc == 2 && strcmp(argv[1], "-h") == 0) {
    if (strcmp(argv[1], "-h") == 0) {
      puts("Modo de empleo: longest_word FILE...\n");
      puts("Busca y devuelve la palabra más larga y su longitud en uno o v"
           "arios archivos\n");
      puts("Opciones:");
      puts("-h:\tPrint this help");
    }
  } else {
    setlocale(LC_ALL, "");
    LongestWord longestWords[argc - 1];
    for (int i = 1; i < argc; ++i) {
      longestWords[i - 1] = searchLongestWord(argv[i]);
    }

    LongestWord longestWord = {.word = L"", .length = 0};
    for (int i = 0; i < argc - 1; ++i) {
      compare(&longestWords[i], &longestWord);
    }

    /* From C11 standard, chapter §7.29.2.1 */
    /* Specifies that a following d, i, o, u, x, or X conversion specifier
     * applies to a long int or unsigned long int argument; that a following n
     * conversion specifier applies to a pointer to a long int argument; that a
     * following c conversion specifier applies to a wint_t argument; that a
     * following s conversion specifier applies to a pointer to a wchar_t
     * argument; or has no effect on a following a, A, e, E, f, F, g, or G
     * conversion specifier. */
    printf("Longest word: %ls \nLength: %d\nBytes: %zu\n", longestWord.word,
           longestWord.length, longestWord.length * sizeof(wchar_t));
  }

  return 0;
}
