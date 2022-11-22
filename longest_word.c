#include "longest_word.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

void compare(LongestWord *str, LongestWord *longest) {
  if (str->length > longest->length) {
    wcsncpy(longest->word, str->word, LIMIT);
    longest->length = str->length;
  }
}

LongestWord searchLongestWord(char *file) {
  FILE *ptr = fopen(file, "r");
  if (ptr == NULL) {
    puts("File can't be opened");
  }

  setlocale(LC_CTYPE, "");
  LongestWord longestWord = {.word = L"", .length = 0};
  LongestWord aux;
  while (fgetws(aux.word, LIMIT, ptr) != NULL) {
    aux.length = wcslen(aux.word) - 1;
    aux.word[aux.length] = '\0';
    compare(&aux, &longestWord);
  }

  fclose(ptr);
  ptr = NULL;

  return longestWord;
}
