#include "expr.h"
#include "errors.h"

SExprBuf* SExprBuf_new() {
  SExprBuf* sexpr_buf = malloc(sizeof(SExprBuf));
  sexpr_buf->size = SEXPRBUF_DEFAULT_SIZE;
  sexpr_buf->pos = 0;
  sexpr_buf->open_parens = 0;
  sexpr_buf->can_close = 0;
  sexpr_buf->buf = malloc(SEXPRBUF_DEFAULT_SIZE);
}

void SExprBuf_destroy(SExprBuf* sexpr_buf) {
  free(sexpr_buf->buf);
  free(sexpr_buf);
}

int SExprBuf_bind(SExprBuf* sexpr_buf, Source* s) {
  sexpr_buf->pos += 1;
  if (sexpr_buf->pos >= sexpr_buf->size) {
    size_t old_size = sexpr_buf->size;
    sexpr_buf->size *= 2;
    if (old_size >= sexpr_buf->size) {
      fatal("The SExpr buf size is too big to fit in a size_t.", 1);
    }
    sexpr_buf->buf = realloc(sexpr_buf->buf, sexpr_buf->size);
  }
  char c;
  ssize_t bytes_read = read(source->fd, &c, 1);
  if (bytes_read == -1) {
    fatal("Could not read from the given Source.", 1);
  } else if (bytes_read == 0) {
    return -1; // EOF
  }
  sexpr_buf->buf[pos] = c;
  if (c == '(') {
    sexpr_buf->open_parens += 1;
    sexpr_buf->can_close = 1;
  } else if (c == ')') {
    sexpr_buf->open_parens -= 1;
    if (sexpr_buf->can_close && (sexpr_buf->open_parens == 0)) {
      return 1;
    } else if (sexpr_buf->open_parens < 0) {
      return -1;
    }
  }
  return 0;
}

SExpr* SExpr_from_buf(SExprBuf* sexpr_buf) {
  if (sexpr_buf == NULL) {
    return NULL;
  }
  SExpr s;
  return s;
}
