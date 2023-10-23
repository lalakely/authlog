#include "./head.h"

char ** get_w_sessions_all(char ** w_sessions , char ** text , int * line){
	int k = 0;
	for(int i = 0 ; i < *line ; i++){
		if(strstr(text[i] , "session") != NULL){
			strcpy(w_sessions[k] , text[i]);
			k++;
		}
	}
	*line = k;
	return w_sessions;
}

void pagination_all(char *** tab , int results , char ** u_page){
	int i = 0;
	int j = 0;
	j = atoi(u_page[1]);
	for(i = j * n_page ; i < n_page * (j + 1) ;i++){
		if(i>=results){break;}
		printf("		<tr>\n");
		printf("		<td>"
				"<a href=\"auth_search.cgi?Username=%s&rechercher=\">"
				"%s" 
				"</a>" 
		"</td>\n",tab[i][0],tab[i][0]);
		if(strcmp(tab[i][1] , "closed") == 0){
		printf("		<td class=\"closed\">%s</td>\n",tab[i][1]);
		}
		else{
			printf("		<td class=\"opened\">%s</td>\n",tab[i][1]);
		}
		printf("			<td> %s </td>\n" , date_to_string(tab[i][2]));
		printf("		</tr>\n");
	}
}
void display_button_all(int results , char ** u_page){
	int n_button = 0;
	int j = 0;
	if(strlen(u_page[1]) == 0){j=0;}
	else{j=atoi(u_page[1]);}
	n_button = count_button(n_button , results);
	printf("<form action=\"./auth_all.cgi\">");
	printf("<div class=\"divbutton\">");
	printf("<button class=\"inbpage\" name=\"page\" value=\"0\"><<</button>");
	if(j != 0){
		printf("<button class=\"inbpage\" name=\"page\" value=\"%d\"><</button>",j - 1);
	}
	for(int i = j ;i < j+10;i++){
		if(i == n_button){break;}
		if(i == j){
			printf("<button class=\"inbpage\" name=\"page\" value=\"%d\">%d</button>",i,i + 1);
		}
		else{printf("<button class=\"bpage\" name=\"page\" value=\"%d\">%d</button>",i,i + 1);}
	}
	if(j != n_button){
		printf("<button class=\"inbpage\" name=\"page\" value=\"%d\">></button>",j + 1);
	}
	printf("<button class=\"inbpage\" name=\"page\" value=\"%d\">>></button>",n_button - 1);
	printf("</div>");
	printf("</form>");
}
void css_all(){
	printf("<style>\n");
	printf("	td {"
				"border: 1px solid #333;"
				"padding :10px;"
				"width : 200px;"
				"height : 50px;"
				"flex-direction : column;"
				"justify-content:center;"
				"justify-content:center;}\n");
	printf("	body{"
				"background-color:#202124;"
				"font-size :14px;"
				"font-family:arial,sans-serif;"
				"font-weight:bold;"
				"color :#bdc1c6;"
				"}");
	printf("	.dtable{background-color : rgb(89, 89, 90);}");
	printf("	.tab{justify-content:center;"
				"position:relative;"
				"top:75px;"
				"}\n");
	printf("    .button1{"
            	"background-color: rgb(74, 74, 75);"
            	"border: none;"
            	"border-top-right-radius: 30px;"
            	"border-bottom-right-radius: 30px;"
            	"width: 100px;"
            	"height: 40px;"
            	"position:relative;"
            	"right:5px;"
				"top :10px;"
				"left :220px;"
        	"}"
        	".button1:hover{"
        	    "background-color: rgb(230, 230, 87);"
        	"}");
	printf(".Username{"
            "background-color: rgb(89, 89, 90);"
            "border: none;"
			"outline:none;"
            "padding-left:10px;"
            "border-top-left-radius: 30px;"
            "border-bottom-left-radius: 30px;"
			"position:relative;"
			"top :10px;"
			"left :220px;"
            "width: 600px;"
            "height: 40px;"
        "}");
	printf(".divp{display:flex;"
			"position:fixed;"
			"top:0px;"
			"background-color:#202124;"
			"width:1500px;"
			"z-index:10;}");
	printf(".imlogo{"
		 "background-image: url(../photo/Auth.log_2-removebg-preview.png);"
            "background-size: cover;"
            "width: 200px;"
            "height: 45px;"
            "position: relative;"
		"}"
	);
	printf(".line{position :relative;top :300px;}");
	printf(".closed{color :red; font-weight :bold;}");
	printf(".opened{color :beige; font-weight:bold;}");
	printf("	.divtab{display:flex;justify-content:center;}\n");
	printf(".bpage{"
			"background-color: rgb(74, 74, 75);"
            "border: none;"
			"width:40px;"
			"height:40px;"
			"border-radius:100px;"
			"margin:5px;"
			"}"
			".bpage:hover{"
        	    "background-color: rgb(230, 230, 87);"
				"font-weight:bold;"
			"}"
	);
	printf(".inbpage{"
			"background-color: rgb(230, 230, 87);"
			"font-weight:bold;"
            "border: none;"
			"width:40px;"
			"height:40px;"
			"border-radius:100px;"
			"margin:5px;"
			"}");
	printf(".divbutton{"
			"display:flex;"
			"justify-content:center;"
			"position:relative;"
			"top:95px;"
			"}"
	);
	printf(
		".divid{"
            "display: flex;"
            "width: 370px;"
            "height: 47px;"
            "background-color: #3b3b3b;"
            "border-radius: 100px;"
            "justify-content: center;"
            "align-items: center;"
            "position: relative;"
			"top:8px;"
           " left: 233px;"
        "}"
		".userawsome{"
            "background-image: url(../photo/user-regular.svg);"
            "width: 35px;"
            "height: 40px;"
            "background-position: center;"
            "background-size: cover;"
            "margin: 10px;"
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
	);
	printf("</style>\n");
}

void html_all(char *** champ , char ** u_page ,char * login){
	int results = 0;
	char *** tab = allouer_champ(tab);

	printf("Content-Type:text/html\n\n");
	printf("<head>\n");
	printf("<meta charset=\"UTF-8\">\n");
	printf("<title>auth</title>\n");
	css_all();
	printf("</head>\n");
	printf("<body>\n");
	printf("<div class=\"divp\">"
			"<a href=\"./acceuil.cgi\">"
			"<div class=\"imlogo\">"
			"</div>"
			"</a>"
        	"<form action=\"./auth_search.cgi\" method=\"get\">"
            "<input type=\"text\" name=\"Username\" class=\"Username\" placeholder=\"Username\">"
            "<button type=\"submit\" name=\"rechercher\" class=\"button1\" >Rechercher</button>"
        "</form>"
		"<div class=\"divid\">" 
			"<a href=\"http://www.auth.com/cgi/user_co.cgi\">"
			"<button class=\"bcreer\">Deconnexion</button>"
			"</a>"
			"<div class=\"userawsome\"></div>"
			"<p class=\"id\">%s</p>"
		"</div>"
    	"</div>",login);
	printf("<div class=\"divtab\">\n");
	printf("<table class=\"tab\">\n");
	printf("<tbody>\n");
	printf("		<tr class=\"dtable\">\n");
	printf("	<td> USER </td>\n");
	printf("	<td> SESSION </td>\n");
	printf("	<td> TIME </td>\n");
	printf("		</tr>\n");
	for(int i = 0 ; i < number ; i++){
		int k = 0;
		while(champ[i][k] != NULL){
			if(strcmp(champ[i][k] , "session") == 0){
					if(strcmp(champ[i][k + 1] , "opened") == 0 ||strcmp(champ[i][k + 1] , "closed") == 0){
						strcpy(tab[results][0],champ[i][k + 4]);
						strcpy(tab[results][1],champ[i][k + 1]);
						strcpy(tab[results][2] , champ[i][0]);
						results++;
					}
			}
			k++;
		}
	}
	pagination_all(tab , results , u_page);
	printf("</tbody>\n");
	printf("</table>\n");
	printf("</div>\n");
	display_button_all(results , u_page);
	printf("</body>\n");
}