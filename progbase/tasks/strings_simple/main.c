#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <progbase.h>
#include <pbconsole.h>

	char is_vowel(char c){
		if (c == 'a' || c == 'e' || c == 'u' || c == 'i'  || c == 'o' || c == 'y' ||
		c == 'A' || c == 'E' || c == 'U' || c == 'I' || c == 'O' || c == 'Y') {
			return 1;
		}
		return 0;
}
	char is_upper(char c ){
		if (c == 'B' || c == 'C' || c == 'D' || c == 'F'  || c == 'G' || c == 'H' ||
		c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'P'
		|| c == 'Q' || c == 'R' || c == 'S' || c == 'T'  || c == 'V' || c == 'W'
		|| c == 'X' || c == 'Z' ) {
			return 1;
		}
		return 0;
}

	

int main(void) {
	char text[510] =" If you want to tell people the truth, make them laugh, oterwise they kill you."
" Most people are other people. Their thoughts are someone else`s opinions, their lives a mimicry, their passions a quotation.\n"
" One can always be kind to people about whom one cares nothing. Selfishness is not living as one wishes to live, it is asking others to live as one wishes to live.\n"
" Some things are more precious because they don’t last long. It is so easy to convince others; it is so difficult to convince oneself.\n";
	int length = strlen(text);
	int textIndex = 0;
	char word[500] = "";
	int wordIndex = 0;
	int count = 0;
	int rowIndex = 0;
	int colIndex = 0;
	int sentencesCount = 0;
	char arr[10][500];
	int return_vow = 0;
	int return_up = 0;
	int textIndexj = 0;



	conClear();
	conSetAttr(BG_BLUE);
	printf ("Task1\n");
	printf ("Вивести текст повністю у консолі та загальну кількість символів у тексті\n");
	conSetAttr(BG_DEFAULT);
	puts("===========================================================================\n");
	
	puts(text); 
	printf ("characters = %d\n",length);
	
	conSetAttr(BG_BLUE);
	printf ("Task2\n");
	printf ("Вивести текст без шістнадцяткових цифр та символів пунктуації та кількість виведених символів.\n");
	conSetAttr(BG_DEFAULT);
	puts("=================================================================================================\n");
	
	for (textIndex = 0; textIndex < length; textIndex++) {
		char ch = text[textIndex];
		if (!isxdigit(ch) && !ispunct(ch)) {
			word[wordIndex] = ch;
			wordIndex++;
			count ++;
		} else {
			word[wordIndex] = '\0';
			if (strlen(word) > 0) {
				printf("%s",word);
				wordIndex = 0;
				word[0] = '\0';
			}
		}
	}
	printf("\n");
	printf("characters : %d\n",count);



	conSetAttr(BG_BLUE);
	printf ("Task3\n");
	printf ("Вивести всі речення тексту, кожне речення із нового рядка та із відміткою про кількість\n символів у виведеному реченні. Речення розділяти спеціальними рядками (наприклад: ------);\n");
	conSetAttr(BG_DEFAULT);
	puts("=============================================================================================\n");
	
	for (textIndex = 0; textIndex < length; textIndex++) {
		char ch = text[textIndex];
		char nextChar = text[textIndex + 1];
		if ((ch == '.' || ch == '!' || ch == '?') && (isspace(nextChar) || nextChar == '\0')) {
			textIndex++;
			arr[rowIndex][colIndex] = '\0';
			rowIndex++;
			colIndex = 0;
		} else {
			arr[rowIndex][colIndex] = ch;
			colIndex++;
		}
	}
	sentencesCount = rowIndex;
	for (rowIndex = 0; rowIndex < sentencesCount; rowIndex++) {
		puts(arr[rowIndex]);
		printf ("characters : %d\n",strlen(arr[rowIndex]));
		puts("--------");
	}

	conSetAttr(BG_BLUE);
	printf ("Task4\n");
	printf ("Вивести загальну кількість слів у тексті (всі слова - неперервні послідовності літер)\n");
	conSetAttr(BG_DEFAULT);
	puts("==========================================================================================\n");
	
	count = 0;
	for (textIndex = 0; textIndex < length; textIndex++) {
		char ch = text[textIndex];
		if ( !ispunct(ch) && !isspace(ch) && !isdigit(ch)) {
			word[wordIndex] = ch;
			wordIndex++;
			count ++;
		} else {
			word[wordIndex] = '\0';
			if (strlen(word) > 0) {
				printf("%s",word);
				wordIndex = 0;
				word[0] = '\0';
			}
		}
	}
	printf("\n");
	printf ("characters : %d\n",count);

	
	conSetAttr(BG_BLUE);
	printf ("Task5\n");
	printf ("У одному рядку, через кому і один пробіл, вивести всі слова, що починаються на приголосну \nлітеру у нижньому регістрі. Також вивести загальну кількість таких слів.\n");
	conSetAttr(BG_DEFAULT);
	puts("===============================================================================================\n");
	count = 0;

	return_vow = is_vowel(text[0]);
	return_up = is_upper(text[0]);
	for(textIndex = 0; textIndex <= length; textIndex++){
		if ((text[textIndex] == ' ') && (textIndex < length) ) {
			return_vow = is_vowel(text[textIndex + 1]);
			return_up = is_upper(text[textIndex + 1]);
			if (return_vow == 0 && return_up == 0) {
				if (count > 0) {
				printf(",");
				}
			}
		}
		if ( return_up == 0 && return_vow == 0 && text[textIndex] != '.' && text[textIndex] != ',' ) {
			putchar(text[textIndex]);
			count++;
			
		}
	}
	puts("");
	printf("characters: %d\n", count);




	conSetAttr(BG_BLUE);
	printf ("Task6\n");
	printf ("У одному рядку, через кому і один пробіл, вивести всі слова, у яких починаються та \nзакінчуються на голосну літеру. Також вивести загальну кількість таких слів.\n");
	conSetAttr(BG_DEFAULT);
	puts("========================================================================================\n");
	count = 0;
	return_vow = is_vowel(text[0]);
	for (textIndex = 0; textIndex <= length; textIndex++) {
		if (text[textIndex] == ' ') {
			return_vow = is_vowel(text[textIndex + 1]);
			if (return_vow == 1) {
				for (textIndexj = textIndex + 1; textIndexj <= length; textIndexj++) {
					if (text[textIndexj] == ' ' || text[textIndexj] == '\0') {
						return_vow = is_vowel(text[textIndexj - 1]);
						if (return_vow == 1) {
							if (count > 0) {
								putchar(',');
							}
						}
						break;
					}
				}
			}
		}
		if (return_vow == 1 && text[textIndex] != '.' && text[textIndex] != ';' && text[textIndex] != ',') {
			putchar(text[textIndex]);
			count++;
		}
	}
	puts("");
	
	printf("characters: %d\n", count);


	

	return 0;
}

