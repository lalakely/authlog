#include <stdio.h>
#include <stdlib.h>

void html_acceuil(char * login);
void css_acceuil();
char * read_file(char * login);

int main(){
    char * login = malloc(256);
    login = read_file(login);
    html_acceuil(login);
    return 0;
}

char * read_file(char * login){
    int condition = 0;
    char * tmp = malloc(256);
    FILE * f = fopen("../file/login","r");
    while(fgets(tmp , 255 , f) != NULL){}
    fclose(f);
    sscanf(tmp , "%99[^:]:%d" , login,&condition);
    if(condition == 0){
        printf("Location: http://www.auth.com/cgi/user_co.cgi\n\n");
    }
    else{
        printf("Content-Type:text/html\n\n");
    }
    return login;
}

void css_acceuil(){
    printf(
        "<style>"
                "body{"
                    "background-color: #202124;"
                    "font-family: cursive;"
                "}"
                ".Username{"
                    "background-color: rgb(89, 89, 90);"
                    "border: none;"
                    "outline: none;"
                    "padding-left:10px;"
                    "border-top-left-radius: 30px;"
                    "border-bottom-left-radius: 30px;"
                    "width: 700px;"
                    "height: 40px;"
                "}"
                ".button1{"
                    "background-color: rgb(74, 74, 75);"
                    "border: none;"
                    "border-top-right-radius: 30px;"
                    "border-bottom-right-radius: 30px;"
                    "width: 100px;"
                    "height: 42px;"
                    "position:relative;"
                    "right:5px;"
                "}"
                ".button1:hover{"
                    "background-color: rgb(230, 230, 87);"
                "}"
                ".divp{"
                    "background-size: cover;"
                    "display: flex;"
                    "justify-content: center;"
                "}"
                ".img_auth{"
                    "background-image: url(../photo/Auth.log-removebg-preview.png);"
                    "background-size: cover;"
                    "width: 500px;"
                    "height: 500px;"
                    "position: relative;"
                    "top: 30px;"
                "}"
                ".divim{"
                    "display: flex;"
                    "justify-content: center;"
                "}"
                ".tout{"
                    "background-color: #4a4a4b;"
                    "border: none;"
                    "width: 200px;"
                    "height: 42px;"
                    "border-radius: 30px;"
                    "position: relative;"
                    "top :10px;"
                "}"
                ".tout:hover{"
                    "background-color: rgb(230, 230, 87);"
                "}"
                ".divb{"
                    "position: relative;"
                    "left:10px;"
                    "width: 350px;"
                    "display: flex;"
                "}"
        ".bcreer{"
            "background-color: rgb(230, 230, 87);"
            "border: none;"
           " width: 200px;"
            "height: 42px;"
           " position:relative;"
            "border-radius: 30px;"
           " margin: 5px;"
            "color: black;"
        "}"
        ".bcreer:hover{"
            "background-color: red;"
            "font-weight: bold;"
        "}"
        ".divid{"
            "display: flex;"
            "width: 370px;"
            "height: 47px;"
            "background-color: #3b3b3b;"
            "border-radius: 100px;"
            "justify-content: center;"
            "align-items: center;"
            "position: relative;"
           " left: 1130px;"
        "}"
        ".id{"
            "color: antiquewhite;"
            "font-family: Arial, Helvetica, sans-serif;"
            "margin: 10px;"
        "}"
        ".userawsome{"
            "background-image: url(../photo/user-regular.svg);"
            "width: 35px;"
            "height: 40px;"
            "background-position: center;"
            "background-size: cover;"
            "margin: 10px;"
        "}"
            "</style>"
    );
}

void html_acceuil(char * login){
    printf(
        "<!DOCTYPE html>"
        "<html lang=\"en\">"
        "<head>"
            "<meta charset=\"UTF-8\">"
            "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
            "<title>My authlog</title>"
    );
        css_acceuil();    
    printf("</head>"
        "<body>"
            "<div class=\"divid\">"
                "<a href=\"http://www.auth.com/cgi/user_co.cgi\">"
                "<button class=\"bcreer\">Deconnexion</button>"
                "</a>"
                "<div class=\"userawsome\"></div>"
                "<p class=\"id\">%s</p>"
            "</div>"
            "<div class=\"divim\">"
                "<div class=\"img_auth\"></div>"
            "</div>"
            "<div class=\"divp\">"
                "<form action=\"./auth_search.cgi\" method=\"get\">"
                    "<input type=\"text\" name=\"Username\" class=\"Username\" placeholder=\"Username\">"
                    "<button type=\"submit\" name=\"page\" class=\"button1\" >Rechercher</button>"
                "</form>" 
            "</div>"
            "<div class=\"divp\">"
                "<a href=\"http://www.auth.com/cgi/auth_all.cgi?page=0\">"
                    "<button type=\"submit\" class=\"tout\" name=\"page\">Voir tout</button>"    
                "</a>"
            "</div>"
        "</body>"
    "</html>",login
    );
}