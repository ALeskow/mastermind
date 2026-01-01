#include<iostream>
#include<random>

int main() {
	// Useful stuff
	int colors = 6;
	int spaces = 4;
	int max_attempts = 10;
	char* password = new char(spaces);
	char trash;
	
	// Random stuff
	std::random_device dev;
	std::mt19937 gen(dev());
	std::uniform_int_distribution<int> dist(0, colors-1);
	
	// Generate password
	for (int i = 0; i < spaces; i++) {
		int rand = dist(gen);
		password[i] = '0' + rand; // [X, X, X, X] 
	}
	
	// Attempts
	for (int i = 0; i < max_attempts; i++){
		printf("Tentativa Nº %d: ", i);
		
		char* attempt = new char(spaces); // [X, X, X, X]
		bool* aux_p = new bool(spaces);
		bool* aux_a = new bool(spaces);
		for	(int j = 0; j < spaces; j++){
			scanf("%c", &attempt[j]);
		}
		scanf("%c", &trash);
		printf("Your attempt was: %s\n", attempt);
		
		// Feedback Black
		for (int j = 0; j < spaces; j++){
			if (password[j] == attempt[j]){
				printf("O");
				aux_p[j] = 0;
				aux_a[j] = 0;
			}
			else {
				aux_p[j] = 1;
				aux_a[j] = 1;
			}
		}
		
		// Win
		bool win = true;
		for (int j = 0; j < spaces; j++){
			if(aux_p[j] == 1){
			win = false;
			break;
			}
		}
		
		if (win == true) {
			printf("\nYou Won!\n");
			break;
		}
		
		// Feedback White
		for (int j = 0; j < spaces; j++){
			if (aux_a[j] == 1){
				for (int k = 0; k < spaces; k++){
					if (aux_p[k] == 1 && k!=j && password[k] == attempt[j]){
						aux_p[k] = 0;
						aux_a[j]= 0;
						printf("X");
						break;
					}
				}
			}
		}
		printf("\n");
	}
}
