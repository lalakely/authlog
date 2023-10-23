#ifndef VAR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define n_page 10
#define number 250
#define VAR

char ** allocation_text(char ** text);
char ** get_data_from_file(char ** text , int * line);
char ** get_neded_data(char ** text , char ** neded_data , int line);
char ** get_w_sessions(char ** w_sessions , char ** text ,char ** search, int * line);
char *** allouer_champ(char *** champ);
char *** split(char *** champ , char ** text);
char ** split_url(char * data , char ** champ);
int count_button(int n_button ,int results);
char * date_to_string(char * string);
char * read_file(char * login);

void display_button_search(int results , char ** u_page);
void pagination_search(char *** tab , int results , char ** u_page);
void html_search(char *** champ ,char ** search,char * login);
void css_search();

void pagination_all(char *** tab , int results , char ** u_page);
void display_button_all(int results , char ** u_page);
void css_all();
void html_all(char *** champ , char ** u_page , char * login);
char ** get_w_sessions_all(char ** w_sessions , char ** text , int * line);


#endif