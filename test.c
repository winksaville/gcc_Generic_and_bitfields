#include <stdio.h>

struct S {
  int b0:4;
  unsigned int b1:4;
  unsigned long long int b33:33;
};

#define type2str(__x) _Generic((__x), \
  int : "int", \
  unsigned int : "unsigned int", \
  unsigned long long int : "unsigned long long int", \
  default : "unknown")

int main(void) {
  struct S s = { .b0=3, .b1=4, .b33=0x1FFFFFFFF };
  (void)s; // Not used

                                                   // gcc     | clang output
  printf("type2str(s.b0):  %s\n", type2str(s.b0)); // unknown | int
  printf("type2str(s.b1):  %s\n", type2str(s.b1)); // unknown | unsigned int
  printf("type2str(s.b33): %s\n", type2str(s.b33));// unknown | unsigned long long int

  printf("s.b33=0x%llx s.b33 << 10 = 0x%llx\n", s.b33, s.b33 << 10);

  return 0;
}
