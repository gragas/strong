#ifndef EXPR_H_
#define EXPR_H_

#include "source.h"
#include <stdint.h>

typedef struct {
  int8_t value;
} Int8Expr;

typedef struct {
  int16_t value;
} Int16Expr;

typedef struct {
  int32_t value;
} Int32Expr;

typedef struct {
  int64_t value;
} Int64Expr;


typedef struct {
  uint8_t value;
} Uint8Expr;

typedef struct {
  uint16_t value;
} Uint16Expr;

typedef struct {
  uint32_t value;
} Uint32Expr;

typedef struct {
  uint64_t value;
} Uint64Expr;


typedef struct {
  float value;
} Float32Expr;

typedef struct {
  double value;
} Float64Expr;


typedef union {
  Int8Expr  int8Expr;
  Int16Expr int16Expr;
  Int32Expr int32Expr;
  Int64Expr int64Expr;

  Uint8Expr  uint8Expr;
  Uint16Expr uint16Expr;
  Uint32Expr uint32Expr;
  Uint8Expr  uint8Expr;

  Float32Expr float32Expr;
  Float64Expr float64Expr;

  void* SExprs;
} SExpr;


typedef struct {
  size_t size, pos;
  int32_t open_parens, can_close;
  char* buf;
} SExprBuf;

SExprBuf* SExprBuf_new(void);
void SExprBuf_destroy(SExprBuf* sexpr_buf);
int SExprBuf_bind(SExprBuf* sexpr_buf, Source* s);
SExpr* SExpr_from_buf(SExprBuf* sexpr_buf);

#endif
