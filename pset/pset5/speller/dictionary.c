#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 1000

typedef struct node{
    char word[LENGTH + 1];
    struct node *next;
} node;

node *hashtable[HASHTABLE_SIZE];

unsigned int numWords;
bool isLoadedDict;

unsigned int hash(const char *word){
    int hash = 0;
    int n;
    
    for(int i = 0; word[i] != '\0'; i++){
        if(isalpha(word[i])) n = word[i] - 'a' + 1;
        else n = 27;
        hash = ((hash << 3) + n) % HASHTABLE_SIZE;
    }
    return hash;
}

bool check(const char *word){
    char checkWord[strlen(word)];
    strcpy(checkWord, word);

    for(int i = 0; checkWord[i] != '\0'; i++) checkWord[i] = tolower(checkWord[i]);
    int index = hash(checkWord);
    
    if(hashtable[index] != NULL){
        for(node *nodeptr = hashtable[index]; nodeptr != NULL; nodeptr = nodeptr -> next){
            if(strcmp(nodeptr -> word, checkWord) == 0) return true;
        }
    }
    return false;
}

bool load(const char *dictionary){
    FILE *infile = fopen(dictionary, "r");
    if(infile == NULL) return false;

    for(int i = 0; i < HASHTABLE_SIZE; i++) hashtable[i] = NULL;
    char word[LENGTH + 1];

    while(fscanf(infile, "%s", word) != EOF){
        numWords++;
        node *newNodePtr;
        
        do{
            newNodePtr = malloc(sizeof(node));
            if(newNodePtr == NULL) free(newNodePtr);
        } while(newNodePtr == NULL);
        
        strcpy(newNodePtr -> word, word);
        int index = hash(word);

        newNodePtr -> next = hashtable[index];
        hashtable[index] = newNodePtr;
    }
    fclose(infile);
    isLoadedDict = true;
    return true;
}

unsigned int size(void){
    if(!isLoadedDict) return 0;
    return numWords;
}

bool unload(void){
    if(!isLoadedDict) return false;
    for(int i = 0; i < HASHTABLE_SIZE; i++){
        if(hashtable[i] == NULL){
            node *ptr = hashtable[i];
            while(ptr != NULL){
                node *predptr = ptr;
                ptr = ptr -> next;
                free(predptr);
            }
        }
    }
    return true;
}