#ifndef SOURCE_H_
#define SOURCE_H_

#include "expr.h"

typedef struct {
  int fd;
} Source;

Source* Source_new(int fd);
void Source_destroy(Source* s);
SExprBuf* Source_next_sexpr_buf(Source *s);
SExpr* Source_next_sexpr(Source* s);

#endif
