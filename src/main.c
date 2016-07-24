#include <stdio.h>
#include "repl.h"

void REPL();

int main(int argc, char** argv) {
  if (argc == 0) {
    REPL();
  }
}
