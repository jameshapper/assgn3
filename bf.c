// Aneka Happer
// July 29, 2018
// assgn3

#include <stdio.h>
#include <stdlib.h>
#include "bv.h"

// Each function has its own hash function, determined by the salt. 

uint32_t hashBF(bloomF *, char *)
{

}

// Create a new Bloom Filter of a given length and hash function.

static inline bloomF *newBF(uint32_t l, uint32_t b[])
{
    bloomF *filter = (bloomF *) calloc(sizeof(bloomF));
    filter->v = (uint8_t*) calloc(l * sizeof(uint8_t) / 8 + 1);
    filter->l = l;
    filter->s = b;
    return filter;
}

// Delete a Bloom filter   

static inline void delBF(bloomF *v)
{
    free(v);
}

// Return the value of position k in the Bloom filter 

static inline uint32_t valBF(bloomF *x, uint32_t k)
{
    int i = k/8;
    int pos = k%8;
    int temp = x->v[i];

    uint8_t flag = 1;

    temp = temp >> pos;
    temp = temp & flag;

    return temp;
}

static inline uint32_t lenBF(bloomF *x) { return x->l; } 

// Count bits in the Bloom filter

static inline uint32_t countBF(bloomF *b)
{
   int len = b->l;

   int bits = len * 8;

   return bits;
}

// Set an entry in the Bloom filter 

static inline void setBF(bloomF *x, char * key)
{
    int i = k/8;
    int pos = k%8;

    uint8_t flag = 1; 

    flag = flag << pos;
    v->vector[i] = v->vector[i] | flag;
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
    int len = x->l;

    for(int i = 0; i < len; i++){
        printf("%d", i);
    }
}
