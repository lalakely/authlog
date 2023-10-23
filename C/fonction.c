#include "./head.h"

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

char ** allocation_text(char ** text){
	text = malloc(3500 * sizeof(char *));
	for(int i = 0 ; i < 3500 ; i++){
		text[i] = malloc(256);
	}
	return text;
}

char ** get_data_from_file(char ** text , int * line){
	FILE * f = fopen("/var/log/auth.log" , "r");
	while(fgets(text[(*line)] , 256 , f) != NULL){(*line)++;
		if(*line == 3500){break;}
	}
	fclose(f);
	return text;
}

char ** get_w_sessions(char ** w_sessions , char ** text ,char ** search, int * line){
	int k = 0;
	for(int i = 0 ; i < *line ; i++){
		if(strstr(text[i] , "session") != NULL){
			if(strstr(text[i] , search[1]) != NULL){
				strcpy(w_sessions[k] , text[i]);
				k++;
			}
		}
	}
	*line = k;
	return w_sessions;
}

char ** get_neded_data(char ** text , char ** neded_data , int line){
	int k = 0;
	for(int i  = 0 ; i < line ; i ++){
		if( ( line - i ) <= number){
			strcpy(neded_data[k] , text[i]);
			k++;
		}
	}
	return neded_data;
}

char *** allouer_champ(char *** champ){
	champ = malloc(500 * sizeof(char **));
	for(int i = 0 ; i < 500 ; i++){
		champ[i] = allocation_text(champ[i]);
	}
	return champ;
}

char *** split(char *** champ , char ** text){
	for(int i = 0 ; i < number ; i++){
		int k = 0;
		int l = 0;
		for(int j = 0 ; j < strlen(text[i]) ; j++){
			if(text[i][j] == '.'||text[i][j] == ' ' || text[i][j] == '(' || text[i][j] == 'T'){
				k++;
				l = 0;
			}
			else{
				champ[i][k][l] = text[i][j];
				l++;
			}
		}
	}
	return champ;
}

int count_button(int n_button ,int results){
	while(results > 0){
	results-=n_page;
	n_button++;}
	return n_button;
}

char * date_to_string(char * string)
{
	char dateStr[11] , cmonth[11]; 
    strcpy(dateStr , string);

    int year, month, day;
    sscanf(dateStr, "%d-%d-%d", &year, &month, &day);

    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    mktime(&date);

    char joursSemaine[7][20] = {"Alahady", "Alatsinainy", "Talata", "Alarobia", "Alakamisy", "Zoma", "Sabotsy"};
    
    switch (month) {
        case 1:  strcpy(cmonth,"Janoary");   break;
        case 2:  strcpy(cmonth,"Febroary");   break;
        case 3:  strcpy(cmonth,"Martsa");      break;
        case 4:  strcpy(cmonth,"Aprily");     break;
        case 5:  strcpy(cmonth,"May");       break;
        case 6:  strcpy(cmonth,"Jiona");      break;
        case 7:  strcpy(cmonth,"Jolay");   break;
        case 8:  strcpy(cmonth,"Aogositra");      break;
        case 9:  strcpy(cmonth,"Septambra"); break;
        case 10: strcpy(cmonth,"Octobra");   break;
        case 11: strcpy(cmonth,"Novambra");  break;
        case 12: strcpy(cmonth,"Desambra");  break;
    }

    sprintf(string,"%s %d %s %d\n", joursSemaine[date.tm_wday], day , cmonth , year);
	return string;
}

char ** split_url(char * data , char ** champ){
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

