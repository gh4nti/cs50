#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX 9 // Max no. of candidates

typedef struct{ // Candidate's name and no. of votes
	string name;
	int votes;
}
candidate;

candidate candidates[MAX]; // Array of candidates
int candidate_count; // No. of candidates

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[]){

	if(argc < 2){
		printf("Usage: ./plurality [candidate...]\n");
		return 1;
	}

	candidate_count = argc - 1;
	
	if(candidate_count > MAX){
		printf("Maximum number of candidates are %i\n", MAX);
		return 2;
	}

	for(int i = 0; i < candidate_count; i++){
		candidates[i].name = argv[i + 1];
		candidates[i].votes = 0;
	}

	int voterCount = get_int("Number of voters: ");

	for(int i = 0; i < voterCount; i++){
		string name = get_string("Vote: ");
	
		if(!vote(name)){
			printf("Invalid vote.\n");
		}
	
	}
	print_winner(); // Prints the winner
	return 0;
}

bool vote(string name){
	
	for(int i = 0; i < candidate_count; i++){
	
		if(strcmp(name, candidates[i].name) == 0){
			candidates[i].votes++;
			return true;
		}
	
	}
	return false;
}

void print_winner(void){
	int maxVotes = candidates[0].votes;
	
	for(int i = 0; i < candidate_count; i++){

		if(candidates[i].votes > maxVotes){
			maxVotes = candidates[i].votes;
		}

	}

	for(int i = 0; i < candidate_count; i++){

		if(candidates[i].votes == maxVotes){
			printf("%s\n", candidates[i].name);
		}

	}
}