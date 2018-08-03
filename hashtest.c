# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include "aes.h"
# include "hashtest.h"


static inline int realLength(int l)
{
    return 16 * (l / 16 + (l % 16 ? 1 : 0));
}

uint32_t hasher(const char *key)
{
    uint32_t output[4] = { 0x0 };
    uint32_t sum       = 0x0;
    int keyL           = strlen(key);
    uint8_t *realKey   = (uint8_t *) calloc(realLength(keyL), sizeof(uint8_t));
    uint32_t saltarray[4] = {0, 1, 2, 3};

    memcpy(realKey, key, keyL);

    AES128_ECB_encrypt((uint8_t *) saltarray, (uint8_t *) realKey, (uint8_t *) output);
    sum ^= output[0] ^ output[1] ^ output[2] ^ output[3];

    printf(" hash: %u \n", sum);
    printf(" output0: %u\n output1: %u\n output2: %u\n output3: %u\n", output[0], output[1], output[2], output[3]);

    free(realKey);

    return sum;
}

