#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int e_login = 0;

void writing_in_file(char *login, char *passwd);
char ** allocation_2D(char ** tab , int lignes);
char ** get_all_login(char ** all_login);
int comptage_in_file(int lignes);
void conditions(char ** all_login , char * login ,char * passwd, int lignes);
void redirection(char * login , char * passwd);
void put_login_in_file(char * login);


int main() {
    char *content_length_str = getenv("CONTENT_LENGTH");
    int content_length = atoi(content_length_str);

    char *post_data = (char *)malloc(content_length + 1);
    fgets(post_data, content_length + 1, stdin);
    
    char login[100]; 
    char passwd[100];
    int lignes = 0;
    lignes = comptage_in_file(lignes);
    char ** all_login = allocation_2D(all_login , lignes);

    all_login = get_all_login(all_login);
    if (sscanf(post_data, "login=%99[^&]&password=%s", login, passwd) != 2) {
        printf("Erreur : Les données POST ne sont pas au format attendu.\n");
        free(post_data);
        return 1;
    }
    
    conditions(all_login , login ,passwd, lignes);
    redirection(login , passwd);
    free(post_data);

    return 0;
}
char ** allocation_2D(char ** tab , int lignes){
    tab = malloc(lignes * sizeof(char*));
    for(int i = 0 ; i < lignes ; i++){
        tab[i] = malloc(257);
    }
    return tab;
}
int comptage_in_file(int lignes){
    FILE * f = fopen("../file/data.txt","r");
    char * text = malloc(257);
    while(fgets(text , 256 , f) != NULL){lignes++;}
    fclose(f);
    return lignes;
}
char ** get_all_login(char ** all_login){
    FILE * f = fopen("../file/data.txt","r");
    char * text = malloc(257);
    int k = 0;
    while(fgets(text , 256 , f) != NULL){
        for(int i = 0 ; i < strlen(text);i++){
            all_login[k][i] = text[i];
           if(text[i + 1] == ':'){break;}
        }
       
        k++;
    }
    return all_login;
}
void conditions(char ** all_login , char * login ,char * passwd, int lignes){
    for(int i = 0 ; i < lignes ; i++){
        if(strcmp(all_login[i],login) == 0){e_login = 1;}
    }
    if(strlen(login) < 8){e_login = 2;}
    if(strlen(passwd) < 8){e_login = 3;}
    if(strlen(login) < 8 && strlen(passwd) < 8){e_login = 4;}
}
void writing_in_file(char *login, char *passwd) {
    FILE *f = fopen("../file/data.txt", "a");
    fprintf(f, "%s:%s\n", login, passwd);
    fclose(f);
}
void redirection(char * login , char * passwd){
    if(e_login == 1){
        printf("Location: http://www.auth.com/cgi/user_ins.cgi?error=%d\n\n",e_login);
    }
    else if(e_login == 2){
        printf("Location: http://www.auth.com/cgi/user_ins.cgi?error=%d\n\n",e_login);
    }
    else if(e_login == 3){
        printf("Location: http://www.auth.com/cgi/user_ins.cgi?error=%d\n\n",e_login);
    }
    else if(e_login == 4){
        printf("Location: http://www.auth.com/cgi/user_ins.cgi?error=%d\n\n",e_login);
    }
    else{
        writing_in_file(login, passwd);
        put_login_in_file(login);
        printf("Location: http://www.auth.com/cgi/acceuil.cgi\n\n");
    }
}

void put_login_in_file(char * login){
    FILE * f = fopen("../file/login","a");
    fprintf(f,"%s:1\n",login);
    fclose(f);
}