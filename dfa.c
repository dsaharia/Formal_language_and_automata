#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum STATES{Q0, Q1, Q2_final};
enum STATES state = Q0;

enum STATES start(char);
enum STATES q1(char);
enum STATES q2(char);

int main() {
	enum STATES state = Q0;
	int size, i = 0;
	printf("Enter the Size of String:\n");
	scanf("%d", &size);
	char *input_str = (char *) malloc(sizeof(char) * (size+1)); // 1 extra space for null character
	if (input_str == NULL) {
		printf("Memory not allocated\n");
	}
	printf("Enter The String(Alphabets {a, b} and lowercase only):\n");
	scanf("%s", input_str);
	input_str[size] = '\0';
	printf("Entered: %s\n", input_str);
	while(input_str[i] != '\0'){
		if(state == Q0){
			state = start(input_str[i]);
		}
		else if (state == Q1){
			state = q1(input_str[i]);
		}
		else if (state == Q2_final) {
			state = q2(input_str[i]);
		}
		i++;
	}
	if (state == Q2_final)
	{
		printf("STRING ACCEPTED\n");
	}
	else {
		printf("STRING REEJCTED\n");
	}

}

enum STATES start(char ch){
	if(ch == 'a') {
		state = Q0;
	}
	else {
		state = Q1;
	}
	return state;
}
enum STATES q1(char ch){
	if(ch == 'a') {
		state = Q0;
	}
	else {
		state = Q2_final;
	}
	return state;
}
enum STATES q2(char ch){
	if(ch == 'a') {
		state = Q0;
	}
	else {
		state = Q2_final;
	}
	return state;
}