#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){
	// Check if arguments are not 2
	if(argc != 2){
		printf("Usage: ./caesar key\n");
		return 1;
	}
	
	// Check if argument is not int
	for(int i = 0, n = strlen(argv[1]); i < n; i++){
		if(isalpha(argv[1][i])){
			printf("Usage: ./caesar key\n");
		}
	}

	int i = atoi(argv[1]) % 26;
	string plaintext = get_string("plaintext: "); // Get plaintext
	printf("ciphertext: ");

	for(int j = 0, n = strlen(plaintext); j < n; j++){
		if(!isalpha(plaintext[j])){
			printf("%c", plaintext[j]);
			continue;
		}

		int offset = isupper(plaintext[j]) ? 65 : 97;
		int diff = plaintext[j] - offset;
		int form = (diff + i) % 26;
		printf("%c", form + offset);
	}

	printf("\n");
	return 0;
}