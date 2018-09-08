// Aneka Happer
// July 29, 2018
// assgn3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bf1.h"
#include "aes.h"

static inline int realLength(int l)
{
    return 16 * (l / 16 + (l % 16 ? 1 : 0));
}

// Each function has its own hash function, determined by the salt. 

uint32_t hashBF(bloomF *x, char *key)
{
    uint32_t output[4] = { 0x0 };
    uint32_t sum       = 0x0;
    int keyL    = strlen(key);

    uint8_t *realKey   = (uint8_t *) calloc(realLength(keyL), sizeof(uint8_t));

    memcpy(realKey, key, keyL);

    AES128_ECB_encrypt((uint8_t *) x->s, (uint8_t *) realKey, (uint8_t *) output);
    sum ^= output[0] ^ output[1] ^ output[2] ^ output[3];

    printf(" hash: %u \n", sum);
    printf(" output0: %u\n output1: %u\n output2: %u\n output3: %u\n", output[0], output[1], output[2], output[3]);

    free(realKey);

    return sum;
}
