#include "nlp.h"
//definition
/*struct Word {
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
*/

//free function
void Word_free(Word ** self) {
    assert(NULL != self);
    free((*self)->value);
    free(*self);
    *self = NULL;
}

void Sentence_free(Sentence ** self) {
    assert(NULL != self);
    Word_freeAll(&(*self)->words);
    free(*self);
    *self = NULL;
}
void Text_free(Text ** self){
    assert(NULL!= self);
    if((*self)->sentences != NULL) {
            Sentence_freeAll(&((*self)->sentences));
    }
    free(*self);
    *self = NULL;

}


//freeAll function
void Word_freeAll (Word ** self) {
  if ( self != NULL) {
    Word * curr = *self;
    Word * tmp;
    while(curr != NULL){
        tmp = curr->next;
        Word_free(&curr);
        curr = tmp;
      }
  }

}
void Sentence_freeAll(Sentence ** self){

  if (self != NULL) {
    Sentence * curr=*self;
    Sentence * tmp;
    while(curr != NULL){
        tmp = curr->next;
        Sentence_free(&curr);
        curr = tmp;
    }
  }
}




// creation
Word * Word_new(char * value) {
    Word * node = (Word *)malloc(sizeof(Word));
    node->value = value;
    node->next = NULL;

    return node;
}

Sentence * Sentence_new(void) {
    Sentence * node = (Sentence *)malloc(sizeof(Sentence));
    node->next = NULL;
    node->words = NULL;
    return node;
}
Text * Text_new (void) {
  Text * node = (Text *)malloc(sizeof(Text));
  node->sentences = NULL;

  return node;
}



//add function
Word * Word_addLast(Word * self, Word * addWord) {
     if (self == NULL) {
          self = addWord;

      } else {
         Word * cur = self;
         while (cur->next != NULL) {
              cur = cur->next;
         }
         cur->next = addWord;
     }
     return self;
}
Sentence * Sentence_addLast(Sentence * self, Sentence * addSentence) {
    if (self == NULL) {
          self = addSentence;

    } else {
    Sentence * cur = self;
    while (cur->next != NULL) {
          cur = cur->next;
    }
    cur->next = addSentence;
  }
  return self;
}




//my task
bool Word_isStopWord(Word * self) {
  FILE *fin = fopen("stopwords.txt","r");
  if (fin == NULL) {
    return NULL;
  }
  char s [150];

  while(!feof(fin)) {
   //  fgets(s, 130, fin);
   //  s[strlen(s)-1] = '\0';
      fscanf(fin,"%s",s);
      if (strcmp(self->value,s) == 0) {
            return true;
      }

    }
    fclose(fin);

  return false;
}
