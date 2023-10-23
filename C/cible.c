#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** split_champ(char * data , char ** champ);

int main(){
	printf("Content-Type:text/html\n\n");
	char * data = malloc(256);
	data = getenv("QUERY_STRING");
	char ** champ = malloc(100 * sizeof(char *));
	for(int i = 0 ;i < 100 ; i++){
		champ[i] = malloc(256);
	}
	champ = split_champ(data , champ);
	printf("<h1>Bonjour</h1>");
	printf("<h1> %s </h1>",champ[1]);
	return 0;
}

char ** split_champ(char * data , char ** champ){
	int k = 0;
	int l = 0;
	for(int i = 0 ; i < strlen(data) ;i++){
		if(data[i] == '=' ||data[i] == '&'){
			k++;
			l = 0;
		}
		else{
			champ[k][l] = data[i];
			l++;
		}
		
	}
	return champ;
}
