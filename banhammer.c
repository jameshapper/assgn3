// Aneka Happer
// July 20, 2018
// assgn3
// banhammer.c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bf1.h"
#include "aes.h"

int main(void){
    
    uint32_t salt[4] = {0, 1, 2, 3};
    //char word[10];

    bloomF *filter1 = newBF(1000, salt);
    
    printf("an element of vector1 is: %u\n", filter1->v[0]);

    //printf("an element of vector1 is: %u\n enter word: ", filter1->v[0]);

    //scanf("%c", &word);

    //hashBF(filter1, word);

    /*for(int i = 0; i < 32; i++){
        int val = valBF(filter1, i);
        printf("%d\n", val);
    }*/

}
