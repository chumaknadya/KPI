#include "nlp.h"
#include "filestream.h"
#include "process.h"


int main (void) {

  Text * text = Text_new();
  text = Text_readFromFile(text,"input.txt");
  text = Text_process(text);
  Text_writeToFile(text ,"output.txt","stopwords.txt");
  Text_free(&text);


  return 0;
}
