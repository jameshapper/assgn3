# ifndef NIL
# define NIL (void *) 0
# endif
# ifndef _BF_H
# define _BF_H
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct bloomF {
    uint8_t *v; // Vector
    uint32_t l; // Length
    uint32_t s[4]; // Salt
} bloomF;

// Each function has its own hash function, determined by the salt. 

uint32_t hashBF(bloomF *, char *);

// Create a new Bloom Filter of a given length and hash function.

static inline bloomF *newBF(uint32_t l, uint32_t b[])
{
    // Code
}

// Delete a Bloom filter 28

static inline void delBF(bloomF *v)
{
    // Code
}

// Return the value of position k in the Bloom filter 

static inline uint32_t valBF(bloomF *x, uint32_t k)
{
    // Code
}

static inline uint32_t lenBF(bloomF *x) { return x->l; } 

// Count bits in the Bloom filter

static inline uint32_t countBF(bloomF *b)
{
    // Code
}

// Set an entry in the Bloom filter 

static inline void setBF(bloomF *x, char * key)
{
    // Code
}

// Clear an entry in the Bloom filter 

static inline void clrBF(bloomF *x, char *key)
{
    // Code
}

// Check membership in the Bloom filter 

static inline uint32_t memBF(bloomF *x, char *key)
{
    // Code
}

static inline void printBF(bloomF *x)
{
    // Code
}

# endif