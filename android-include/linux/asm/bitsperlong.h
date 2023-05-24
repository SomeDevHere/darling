#ifndef __ASM_BITSPERLONG_H
#define __ASM_BITSPERLONG_H
#if (defined(__x86_64__) && ! defined(__ILP32__)) || defined(__aarch64__)
#define __BITS_PER_LONG 64
#endif
#endif /* __ASM_BITSPERLONG_H */

#include <asm-generic/bitsperlong.h>
