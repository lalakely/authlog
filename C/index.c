#include <stdio.h>
#include <stdlib.h>

void read_index_html();
void deconnexion_auto();

int main(){
	deconnexion_auto();
	read_index_html();
	return 0;
}

void deconnexion_auto(){
    FILE * f = fopen("file/login","r");
    char * tmp = malloc(256);
    while(fgets(tmp , 256 , f)!= NULL){}
    char * login = malloc(256);
    sscanf(tmp,"%99[^:]:1",login);
    fclose(f);

    FILE * k = fopen("file/login" , "a");
    fprintf(f , "%s:0\n" , login);
    fclose(k);
}

void read_index_html(){
	printf("Content-Type: text/html\n\n");
	FILE * f = fopen("htmls/index.html" , "r");
	char * tmp = malloc(256);
	while(fgets(tmp , 256 , f) != NULL){
		printf("%s" , tmp);
	}
}
