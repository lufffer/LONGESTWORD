#include <wchar.h>

#define LIMIT 28

typedef struct LongestWord {
  unsigned length;
  wchar_t word[LIMIT];
} LongestWord;

LongestWord searchLongestWord(char *file);

void compare(LongestWord *str, LongestWord *longest);
