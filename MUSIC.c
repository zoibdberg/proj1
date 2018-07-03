#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define A4 440
bool is_rest(char *str)
{
	if(str[0] == '\0')
	{
		return true;
	}
	return false;
}
double notefunc(char *note){
	double var = 2.0 * (note[0] - 'A');
	if(note[1] == '#') var++;
	if(note[1] == 'b') var--;
	if(note[1] != '#' && note[1] != 'b')
       	{
		int octave = note[1] - '0';
		return 12 * octave + var;	
	}

	int octave = note[2] - '0';
	return 12 * octave + var;
}

double frequency(char *note){
	double i = notefunc(note) - 49;
	return A4 * pow(2.0, i/12.0);
}

int main(int argc, char *argv[]){
	if(is_rest(*argv) == true) return false;
	printf("%f",frequency(argv[1]));
	return 0;
}
