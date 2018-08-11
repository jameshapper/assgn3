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

uint32_t hashBF(bloomF *, char *);                          // Each function has its own hash function, determined by the salt. 

static inline bloomF *newBF(uint32_t l, uint32_t b[]);      // Create a new Bloom Filter of a given length and hash function.

static inline void delBF(bloomF *v);                        // Delete a Bloom filter   

static inline uint32_t valBF(bloomF *x, uint32_t k);        // Return the value of position k in the Bloom filter 

static inline uint32_t lenBF(bloomF *x);                    // Returns length of the Bloom filter 

static inline uint32_t countBF(bloomF *b);                  // Count bits in the Bloom filter

static inline void setBF(bloomF *x, char * key);            // Set an entry in the Bloom filter 

static inline void clrBF(bloomF *x, char *key);             // Clear an entry in the Bloom filter 

static inline uint32_t memBF(bloomF *x, char *key);         // Check membership in the Bloom filter 

static inline void printBF(bloomF *x);                      // prints Bloom filter

# endif
