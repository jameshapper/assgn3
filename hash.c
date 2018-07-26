# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include "aes.h"
# include "hash.h"

static inline int realLength(int l)
{
    return 16 * (l / 16 + (l % 16 ? 1 : 0));
}

uint32_t hash(hashTable *h, const char *key)
{
    uint32_t output[4] = { 0x0 };
    uint32_t sum       = 0x0;
    int keyL           = strlen(key);
    uint8_t *realKey   = (uint8_t *) calloc(realLength(keyL), sizeof(uint8_t));

    memcpy(realKey, key, keyL);

    for (int i = 0; i < realLength(keyL); i++)
    {
        AES128_ECB_encrypt((uint8_t *) h->s, (uint8_t *) realKey + i, (uint8_t *) output);
        sum ^= output[0] ^ output[1] ^ output[3];
    }
    free(realKey);
    return sum;
}

// And so forth