#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c_error = 0;
void condition_connex(char * login ,char * passwd);
void redirection(char * login , char * passwd);
void put_login_in_file(char * login);

int main() {
    char *content_length_str = getenv("CONTENT_LENGTH");
    int content_length = atoi(content_length_str);

    char *post_data = (char *)malloc(content_length + 1);
    fgets(post_data, content_length + 1, stdin);

    char login[100]; 
    char passwd[100];
    if (sscanf(post_data, "login=%99[^&]&password=%s", login, passwd) != 2) {
        printf("Erreur : Les données POST ne sont pas au format attendu.\n");
        free(post_data);
        return 1;
    }

    condition_connex(login , passwd);
    redirection(login , passwd);
    free(post_data);
    return 0;
}

void condition_connex(char * login , char * passwd){
    FILE * f = fopen("../file/data.txt" , "r");
    char * text = malloc(257);
    char * c_login = malloc(257);
    char * c_passwd = malloc(257);
    while(fgets(text , 256 , f) != NULL){
        sscanf(text , "%99[^:]:%s" , c_login , c_passwd);
        if(strcmp(login , c_login) != 0){
            c_error = 1;
        }
        if(strcmp(login , c_login) == 0 && strcmp(passwd , c_passwd) != 0){
            c_error = 2;
            break;
        }
        if(strcmp(login , c_login) == 0 && strcmp(passwd , c_passwd) == 0){
            c_error = 0;
            break;
        }
    }
    fclose(f);
}
void redirection(char * login , char * passwd){
    if(c_error == 1){
        printf("Location: http://www.auth.com/cgi/user_co.cgi?error=%d&login=%s\n\n",c_error,login);
    }
    else if(c_error == 2){
        printf("Location: http://www.auth.com/cgi/user_co.cgi?error=%d&login=%s\n\n",c_error,login);
    }
    else{
        put_login_in_file(login);
        printf("Location: http://www.auth.com/cgi/acceuil.cgi\n\n");
    }
}

void put_login_in_file(char * login){
    FILE * f = fopen("../file/login","a");
    fprintf(f,"%s:1\n",login);
    fclose(f);
}