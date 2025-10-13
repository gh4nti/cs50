#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void){
	string s = get_string("Text: ");
	int numWords, numSentences, numLetters;
	numWords = numLetters = numSentences = 0;
	for(int i = 0, len = strlen(s); i < len; i++){
		if(isalpha(s[i])) numLetters++;
		if((i == 0 && s[i] != ' ') || (i != len - 1 && s[i] == ' ' && s[i + 1] != ' ')) numWords++;
		if(s[i] == '.' || s[i] == '?' || s[i] == '!') numSentences++;
	}
	float L = (numLetters / (float) numWords) * 100;
	float S = (numSentences / (float) numWords) * 100;
	int index = round(0.0588 * L - 0.296 * S - 15.8);
	if(index < 1) printf("Before Grade 1\n");
	else if(index >= 16) printf("Grade 16+\n");
	else printf("Grade %i\n", index);
}