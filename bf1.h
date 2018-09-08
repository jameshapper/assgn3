// Aneka Happer
// July 29, 2018
// assgn3
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

uint32_t hashBF(bloomF *x, char *key);

// Create a new Bloom Filter of a given length and hash function.

static inline bloomF *newBF(uint32_t l, uint32_t b[])
{
    bloomF *filter = (bloomF *) malloc(sizeof(bloomF));
    filter->v = (uint8_t*) malloc(l * sizeof(uint8_t) / 8 + 1);
    filter->l = l;
    //filter->s = b[];
    memcpy(filter->s,b,4);
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
    uint32_t k = hashBF(x, key);
    int i = k/8;
    int pos = k%8;

    uint8_t flag = 1; 

    flag = flag << pos;
    x->v[i] = x->v[i] | flag;
}

// Clear an entry in the Bloom filter 

static inline void clrBF(bloomF *x, char *key)
{
    uint32_t k = hashBF(x, key);
    int i = k/8;
    int pos = k%8;

    uint8_t flag = 1;
    flag = ~flag; 

    flag = flag << pos;
    x->v[i] = x->v[i] | flag;
}

// Check membership in the Bloom filter 

/*static inline uint32_t memBF(bloomF *x, char *key)
{
    // Code
}*/

static inline void printBF(bloomF *x)
{
    int len = x->l;

    for(int i = 0; i < len; i++){
        printf("%d", i);
    }
}

# endif