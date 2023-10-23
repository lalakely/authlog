#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void user_ins_css();
void user_ins_html(int error);
char * get_c_error(char * from_prog , char * c_error);

int main(){

    char * from_prog = malloc(256);
    char * c_error = malloc(256);
    int error = 0;
    from_prog = getenv("QUERY_STRING");

    c_error = get_c_error(from_prog , c_error);
    error = atoi(c_error);
    user_ins_html(error);
    return 0;
}
char * get_c_error(char * from_prog , char * c_error){
    sscanf(from_prog ,"error=%s",c_error);
    return c_error;
}
void user_ins_css(){
    printf("<style>"
        "body{"
            "background-color: #202124;"
        "}"
        ".divlog{"
            "display: flex;"
            "justify-content: center;"  
        "}"
        ".divp{"
            "display: flex;"
           " background-color: #39393a;"
            "width: 1000px;"
            "height: 500px;"
            "border-radius: 30px;"
            "position: relative;"
            "top: 130px;"
        "}"
        ".login{"
            "width: 300px;"
            "height: 42px;"
            "border: none;"
            "outline: none;"
            "padding-left:10px;"
            "background-color: rgb(89, 89, 90);"
            "border-radius: 30px;"
            "margin: 5px;"
        "}"
        ".divconnex{"
            "display: flex;"
            "justify-content: center;"
        "}"
        ".bconnex{"
            "background-color: rgb(74, 74, 75);"
            "border: none;"
            "width: 200px;"
            "height: 42px;"
            "position:relative;"
            "border-radius: 30px;"
            "margin: 5px;"
        "}"
        ".bconnex:hover{"
            "background-color: rgb(230, 230, 87);"
            "font-weight: bold;"
        "}"
        ".bcreer{"
            "background-color: rgb(74, 74, 75);"
            "border: none;"
            "width: 200px;"
            "height: 42px;"
            "position:relative;"
            "border-radius: 30px;"
            "margin: 5px;"
        "}"
        ".bcreer:hover{"
            "background-color: rgb(230, 230, 87);"
            "font-weight: bold;"
        "}"
        ".formp{"
            "display: flex;"
            "flex-direction: column;"
            "align-items: center;"
            "position: relative;"
            "width: 500px;"
            "bottom: 75px;"
        "}"
        ".img_auth{"
            "background-image: url(../photo/INSCRIPTIONlog-removebg-preview.png);"
            "background-size: cover;"
            "width: 250px;"
            "height: 250px;"
            "position: relative;"
            "top: 50px;"
        "}"
        ".imlogo{"
            "background-image: url(../photo/Auth.log_2-removebg-preview.png);"
            "background-size: cover;"
            "width: 200px;"
            "height: 45px;"
        "}"
        ".connexion{"
            "display: flex;"
            "font-family: Arial, Helvetica, sans-serif;"
            "margin: 10px;"
        "}"
        ".secon{"
            "font-weight: bold;"
            "text-decoration: none;"
            "color: black;"
            "margin-left: 5px;"
        "}"
        ".error{"
            "font-family: Arial, Helvetica, sans-serif;"
            "font-size: 12px;"
            "color: red;"
            "position: relative;"
            "left:15px;"
        "}"
        ".leftp{"
            "background: url(../photo/logoonly-removebg-preview.png);"
            "width: 500px;"
            "height: 500px;"
            "background-color: rgb(76, 76, 77);"
           "border-radius: 30px;"
            "box-shadow: -10px 0px 30px#202124;"
        "}"
        ".img2{"
           "background-size: cover;"
            "background-position: center;"
            "background-image: url(../photo/illu_inscri.png);"
            "width: 350px;"
            "height: 350px;"
            "position: relative;"
            "top: 150px;"
            "left:85px;"
        "}"
    "</style>");
}

void user_ins_html(int error){
        printf("Content-Type:text/html\n\n");
    printf("<!DOCTYPE html>"
"<html lang=\"en\">"
"<head>"
    "<meta charset=\"UTF-8\">"
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
    "<title>Inscription-My Authlog</title>");
    user_ins_css();
printf("</head>"
"<body>"
    "<a href=\"../index.cgi\">"
        "<div class=\"imlogo\"></div>"
    "</a>");
    printf("<div class=\"divlog\">"
        "<div class=\"divp\">"
            "<div class=\"formp\">"
                "<div class=\"img_auth\"></div>"
                "<form action=\"../cgi/inscri.cgi\" method=\"post\">"
                    "<div>"
                        "<input type=\"text\" name=\"login\" placeholder=\"Login\" class=\"login\" required>"
                    "</div>");
                   if(error == 1){
                    printf("<div class=\"error\">"
                            "utilisateur déja existant"
                            "</div>");
                   }
                   if(error == 2 || error == 4){
                    printf("<div class=\"error\">"
                            "Entrez 8 caracteres au minimum"
                            "</div>");
                   }
                    printf("<div>"
                        "<input type=\"password\" name=\"password\" placeholder=\"Password\" class=\"login\" required >"
                    "</div>");
                    if(error == 3 || error == 4){
                    printf("<div class=\"error\">"
                            "Entrez 8 caracteres au minimum"
                            "</div>");
                    }
                    printf("<div class=\"divconnex\">"
                        "<button class=\"bcreer\">Créer un compte</button>"
                    "</div>"
                "</form>"
                "<div class=\"connexion\">"
                    "Vous avez déja un compte?"
                    "<a href=\"../cgi/user_co.cgi\" class=\"secon\">Se connecter</a>"
                "</div>"
            "</div>"
             "<div class=\"leftp\">"
                "<div class=\"img2\"></div>"
            "</div>"
        "</div>"
    "</div>" 
"</body>"
"</html>");
}