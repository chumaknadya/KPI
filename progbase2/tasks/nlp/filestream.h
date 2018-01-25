




#ifndef FILESTREAM_H
#define FILESTREAM_H

#include "nlp.h"



Text * Text_readFromFile(Text *self, char *fileName);
int Text_writeToFile(Text * text ,const char * writeFileName,const char * readFileName);

#endif
