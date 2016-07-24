#include "repl.h"
#include "read.h"
#include "eval.h"
#include "print.h"

void REPL() {
  while (1) {
    print(eval(read()));
  }
}
