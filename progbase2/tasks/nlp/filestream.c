
#include "filestream.h"
#include "nlp.h"
char * Sentence_readFromFile(FILE *fin, char * buffer);
Sentence * Sentence_getFromStr(char *str);
Word * Word_getFromStr(char * str, char ** strOut);
char * skipSpaceInStr(char * str);
int Word_getSize(char * str);
int Text_writeToFile(Text * text ,const char * writeFileName,const char * readFileName);





enum { BUFFER_SIZE = 1000};



int Text_writeToFile(Text * text ,const char * writeFileName,const char * readFileName) {
  FILE * fout = fopen(writeFileName, "w");
  FILE * fin = fopen(readFileName, "r");

  if (fout == NULL) {
      printf("Could not open file\n");
      return -1;
  }
  char s [150];
  int count = 0;
  while ( !feof(fin)) {
    fscanf(fin,"%s",s);
    //fgets(s,150,fin);
    //s[strlen(s) - 1] = '\0';
    count = 0;
    Sentence * currSentence = text->sentences;
    while(currSentence != NULL){
        Word * currWord = currSentence->words;
        while (currWord != NULL) {
          if (strcmp(currWord->value,s) == 0) {
               count ++;
           }
           currWord = currWord->next;
        }
        currSentence = currSentence->next;
    }
    fprintf(fout,"%s : %d \n", s,count);


  }

  fclose(fin);
  fclose(fout);
  return 0;
}



Text * Text_readFromFile(Text * self, char * fileName) {
    if (self == NULL) {
        return NULL;
    }
    if (strlen(fileName) == 0){
        printf("Invalid file name\n");
        return NULL;
    }
    FILE * fin = fopen(fileName, "r");
    if (fin == NULL){
        printf("Could not open file\n");
        return NULL;
    }
    char * buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (buffer == NULL){
        fclose(fin);
        return NULL;
    }
    while (!feof(fin)){
        buffer = Sentence_readFromFile(fin, buffer);
        self->sentences = Sentence_addLast(self->sentences, Sentence_getFromStr(buffer));

    }

    free(buffer);
    fclose(fin);

    return self;
}



Sentence * Sentence_getFromStr(char *str){
    Sentence * sentence = Sentence_new();
    while(*str != '\0'){
        sentence->words =  Word_addLast(sentence->words, Word_getFromStr(str, &str));
    }
    return sentence;

}
char * Sentence_readFromFile(FILE *fin, char * buffer){
    int i = 0;

    for (; !feof(fin) && i < BUFFER_SIZE; i++){
        buffer[i] = fgetc(fin);
        if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?') {
            break;
        }
    }
    buffer[i] = '\0';
    return buffer;
}

int Word_getSize(char * str){
    str = skipSpaceInStr(str);
    int size = 0;
    for(;isalnum(*str);str++){
        size ++;
    }
    return size;
}

char * skipSpaceInStr(char * str){
    for(;!isalnum(*str); str++);
    return str;
}

Word * Word_getFromStr(char * str, char ** strOut){
   str = skipSpaceInStr(str);
    char * symbols = (char *)malloc(sizeof(char) * (Word_getSize(str)+1));
    int i = 0;
    for(; isalnum(*str); str++, i++){
        symbols[i] = *str;

    }
    symbols[i] = '\0';
    Word * word = Word_new(symbols);
    *strOut = str;
    return word;
}
