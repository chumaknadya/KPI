#include "process.h"
#include "nlp.h"

Text * Text_process(Text * text);
Sentence * Sentence_process(Sentence * sentence);
Word * Word_process(Word * self);
void Word_tolower(Word * self);





void Word_tolower(Word * self) {
    for(int i = 0; (self->value)[i] != '\0'; i++) {
        if(isupper(self->value[i])) {
            self->value[i] = tolower(self->value[i]);
        }
    }
}



Text * Text_process(Text * text) {
    Sentence * currSentence = text->sentences;
    while(currSentence != NULL) {
        Sentence_process(currSentence);
        currSentence = currSentence->next;
    }
    return text;
}

Sentence * Sentence_process(Sentence * sentence){
    Word * currWord = sentence->words;
    while(currWord != NULL) {

       Word_process(currWord);

        currWord = currWord->next;
    }
    return sentence;
}
Word * Word_process(Word * self) {
    Word_tolower(self);

    return self;
}
