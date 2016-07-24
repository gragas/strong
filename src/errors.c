#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

void fatal(char* s, int status) {
  fprintf(stderr, s);
  exit(status);
}

void log(char* s) {
  fprintf(stderr, s);
}
