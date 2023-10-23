#include "./head.h"

void pagination_search(char *** tab , int results , char ** u_page){
	int i = 0;
	int j = 0;
	j = atoi(u_page[3]);
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
void display_button_search(int results , char ** u_page){
	int n_button = 0;
	int j = 0;
	if(strlen(u_page[3]) == 0){j=0;}
	else{j=atoi(u_page[3]);}
	n_button = count_button(n_button , results);
	printf("<div class=\"divbutton\">");
	printf("<a href=\"auth_search.cgi?Username=%s&page=%d\" class=\"lbutton\"><div class=\"inbpage\"><<</div></a>"
		,u_page[1],0);
	if(j != 0){
		printf("<a href=\"auth_search.cgi?Username=%s&page=%d\" class=\"lbutton\"><div class=\"inbpage\"><</div></a>"
				,u_page[1],j-1);
	}
	for(int i = j ;i < j + 10;i++){
		if(i == n_button){break;}
		if(i == j){
			printf("<a href=\"auth_search.cgi?Username=%s&page=%d\" class=\"lbutton\"><div class=\"inbpage\">%d</div></a>"
				,u_page[1],i,i + 1);
		}
		else{	printf("<a href=\"auth_search.cgi?Username=%s&page=%d\" class=\"lbutton\"><div class=\"bpage\">%d</div></a>"
				,u_page[1],i,i + 1);
		}
		printf("<div class=\"vide\"></div>");
	}
	if(j != n_button){
		printf("<a href=\"auth_search.cgi?Username=%s&page=%d\" class=\"lbutton\"><div class=\"inbpage\">></div></a>"
				,u_page[1],j+1);
	}
	printf("<a href=\"auth_search.cgi?Username=%s&page=%d\" class=\"lbutton\"><div class=\"inbpage\">>></div></a>"
			,u_page[1],n_button - 1);
	printf("</div>");
}

void css_search(){
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
	printf("	.divtab{"
			"display:flex;"
			"flex-direction:column;"
			"justify-content:center;"
			"width:700px;}\n");
	printf(".bpage{"
			"background-color: rgb(74, 74, 75);"
			"display:flex;"
			"align-items:center;"
			"justify-content:center;"
            "border: none;"
			"width:40px;"
			"height:40px;"
			"border-radius:100px;"
			"}"
			".bpage:hover{"
        	    "background-color: rgb(230, 230, 87);"
				"font-weight:bold;"
			"}"
	);
	printf(".inbpage{"
			"background-color: rgb(230, 230, 87);"
			"font-weight:bold;"
            "display:flex;"
			"align-items:center;"
			"justify-content:center;"
            "border: none;"
			"width:40px;"
			"height:40px;"
			"border-radius:100px;"
			"}");
	printf(".divbutton{"
			"display:flex;"
			"justify-content:center;"
			"position:relative;"
			"top:95px;"
			"}"
	);
	printf(".lbutton{"
			"width:40px;"
			"height:40px;"
			"border-radius:100px;"
			"color:black;"
			"text-decoration:none;"
	"}")
	;
	printf(".vide{width:10px;}");
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
		".label{"
		"color :white; "
		"font-family:arial;"
		"position:relative;"
		"top:75px;"
		"}"
		".divsearch{"
		"display:flex;"
		"justify-content:center;"
		"}"
	);
	printf("</style>\n");
}

void html_search(char *** champ , char ** search , char * login){
	int results = 0;
	char *** tab = allouer_champ(tab);

	printf("Content-Type:text/html\n\n");

	printf("<head>\n");
	printf("<meta charset=\"UTF-8\">\n");
	printf("<title>My authlog - search</title>\n");
	css_search();
	printf("</head>\n");
	printf("<body>\n");
	printf("<div class=\"divp\">"
			"<a href=\"./acceuil.cgi\">"
			"<div class=\"imlogo\">"
			"</div>"
			"</a>"
        	"<form action=\"./auth_search.cgi\" method=\"get\">"
            "<input type=\"text\" name=\"Username\" class=\"Username\" placeholder=\"Username\" value=\"%s\">"
            "<button type=\"submit\" name=\"rechercher\" class=\"button1\" >Rechercher</button>"
        "</form>"
		"<div class=\"divid\">" 
			"<a href=\"http://www.auth.com/cgi/user_co.cgi\">"
			"<button class=\"bcreer\">Deconnexion</button>"
			"</a>"
			"<div class=\"userawsome\"></div>"
			"<p class=\"id\">%s</p>"
		"</div>" 
    	"</div>",search[1],login);
		printf("<div class=\"divsearch\">");
		printf("<div class=\"divtab\">\n");
		printf("<div class=\"label\">");
		printf("<p>resultats pour : %s </p>",search[1]);
		printf("</div>");
	if(strlen(search[1])!= 0){
		printf("<table class=\"tab\">\n");
		printf("<tbody class=\"tbody\">\n");
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
		pagination_search(tab , results , search);
		printf("</tbody>\n");
		printf("</table>\n");
	}
	printf("</div>\n");
	printf("</div>");
	if(strlen(search[1])!= 0){
		display_button_search(results , search);
	}
	printf("</body>\n");
}