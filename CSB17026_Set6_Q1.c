/* Roll Number - CSB17026 */
// <- States ->
/* Start State - Q0, Final State - Q2 */
// <-- Transitions -->
/* Q0 -a-> Q0 , Q0 -b-> Q1
   Q1 -a-> Q0 , Q1 -b-> Q2
   Q2 -a-> Q0 , Q2 -b-> Q2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum STATES{Q0, Q1, Q2_final};
enum STATES state = Q0;
// Function prototypes
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
// Start(Q0) state simulation function
enum STATES start(char ch){
	if(ch == 'a') {
		state = Q0;
	}
	else {
		state = Q1;
	}
	return state;
}
// Q1 state simulation function
enum STATES q1(char ch){
	if(ch == 'a') {
		state = Q0;
	}
	else {
		state = Q2_final;
	}
	return state;
}
// Q2 state simulation function
enum STATES q2(char ch){
	if(ch == 'a') {
		state = Q0;
	}
	else {
		state = Q2_final;
	}
	return state;
}