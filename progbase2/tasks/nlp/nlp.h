#ifndef NLP_H

#define NLP_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>


typedef struct Text Text;
typedef struct Sentence Sentence;
typedef struct Word Word;
struct Word {
  char * value;
  Word * next;
};
struct Sentence {
  Word * words;
  Sentence * next;

};
struct Text {
  Sentence * sentences;
};


void Word_free(Word ** self);
void Word_freeAll (Word ** self);
Word * Word_new(char * value);
Word * Word_addLast(Word * self, Word * addWord);
bool Word_isStopWord(Word * self);



void Sentence_free(Sentence ** self);
void Sentence_freeAll (Sentence ** self);
Sentence * Sentence_new(void);
Sentence * Sentence_addLast(Sentence * self, Sentence * addSentence);



void Text_free(Text ** self);
Text * Text_new (void);



//Text *Text_readFromFile(Text *self, char *fileName);
//Text* Text_process(Text * text);
//int Text_writeToFile(Text * text ,const char * writeFileName,const char * readFileName);





#endif
