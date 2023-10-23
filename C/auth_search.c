#include "./head.h"

int main(){
	int line = 0;
	char ** text = allocation_text(text);
	char ** w_sessions = allocation_text(w_sessions);
	char ** neded_data = allocation_text(neded_data);
	char *** champ = allouer_champ(champ);
	char * from_prog = malloc(256);
	char ** search = allocation_text(search);
	char * login = malloc(256);
	login = read_file(login);

	from_prog = getenv("QUERY_STRING");
	search = split_url(from_prog , search);
	text = get_data_from_file(text , &line);
	w_sessions = get_w_sessions(w_sessions , text,search , &line);
	neded_data = get_neded_data(w_sessions , neded_data , line);
	champ = split(champ , neded_data);
	html_search(champ , search , login);
	return 0;
}
