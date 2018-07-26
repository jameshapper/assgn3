# ifndef NIL
# define NIL (void *) 0
# endif

# ifndef _HASH_H
# define _HASH_H
# include <stdint.h>
# include "ll.h"

uint32_t hasher(const char *key);

# endif
