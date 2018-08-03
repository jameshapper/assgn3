# include <stdlib.h>
# include <stdint.h>
# include "ll.h"

listNode *newNode(const char * oldspeak, const char * newspeak){
    listNode *speakNode = malloc(sizeof(listNode));
    speakNode->oldspeak = oldspeak;
    speakNode->newspeak = newspeak;
    speakNode->next = NULL;
    return speakNode;
}

void delNode(listNode * speakNode){
    free(speakNode)
}

void delLL(listNode *);

listNode *insertLL(listNode **, const char *, const char *);

listNode *findLL(listNode **, const char *);

void printLL(listNode *);