
#ifndef PROCESS_H
#define PROCESS_H
#include "nlp.h"

Text * Text_process(Text * text);
Sentence * Sentence_process(Sentence * sentence);
Word * Word_process(Word * self);
void Word_tolower(Word * self);


#endif
