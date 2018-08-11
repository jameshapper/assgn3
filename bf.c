// Aneka Happer
// July 29, 2018
// assgn3

#include <stdio.h>
#include <stdlib.h>
#include "bv.h"

// Each function has its own hash function, determined by the salt. 

uint32_t hashBF(bloomF *x, char *key)
{
    uint32_t output[4] = { 0x0 };
    uint32_t sum       = 0x0;
    int keyL           = strlen(key);
    uint8_t *realKey   = (uint8_t *) calloc(realLength(keyL), sizeof(uint8_t));
    uint32_t saltarray[4] = x->s;

    memcpy(realKey, key, keyL);

    AES128_ECB_encrypt((uint8_t *) saltarray, (uint8_t *) realKey, (uint8_t *) output);
    sum ^= output[0] ^ output[1] ^ output[2] ^ output[3];

    printf(" hash: %u \n", sum);
    printf(" output0: %u\n output1: %u\n output2: %u\n output3: %u\n", output[0], output[1], output[2], output[3]);

    free(realKey);

    return sum;
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
    uint32_t k = hashBF(key);
    int i = k/8;
    int pos = k%8;

    uint8_t flag = 1; 

    flag = flag << pos;
    x->v[i] = x->v[i] | flag;
}

// Clear an entry in the Bloom filter 

static inline void clrBF(bloomF *x, char *key)
{
    uint32_t k = hashBF(key);
    int i = k/8;
    int pos = k%8;

    uint8_t flag = 1;
    flag = ~flag; 

    flag = flag << pos;
    x->v[i] = x->v[i] | flag;
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
