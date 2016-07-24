#include "source.h"

Source* Source_new(int fd) {
  Source* s = malloc(sizeof(Source));
  s->fd = fd;
  return s;
}

void Source_destroy(Source* s) {
  free(s);
}

SExpr* Source_next_sexpr(Source* s) {
  SExprBuf sexpr_buf = Source_next_sexpr_buf(s);
  SExpr* sexpr = SExpr_from_buf(sexpr_buf);
  SExprBuf_destory(sexpr_buf); sexpr_buf = NULL;
  return sexpr;
}

SExpr* Source_next_sexpr_buf(Source* s) {
  // Reads from source until an sexpr is found and returns it
  // If no sexpr is found, returns NULL
  SExprBuf sexpr_buf = SExprBuf_new();
  int found_sexpr;
  while (1) {
    found_sexpr = SExprBuf_bind(sexpr_buf, s);
    if (found_sexpr == -1) {
      return NULL;
    } else if (found_sexpr == 1) {
      break;
    } else if (found_sexpr != 0) {
      fatal("ERROR: SExprBuf_bind should only return -1, 0, or 1.", 1);
    }
    // found_sexpr must be 0; no sexpr has been found *yet*; continue
  }
  return sexpr_buf;
}
