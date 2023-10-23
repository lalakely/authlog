#include "./head.h"

int main(){
	int line = 0;
	char ** text = allocation_text(text);
	char ** w_sessions = allocation_text(w_sessions);
	char ** neded_data = allocation_text(neded_data);
	char *** champ = allouer_champ(champ);

	char * from_prog = malloc(256);
	from_prog = getenv("QUERY_STRING");
	char ** u_page = allocation_text(u_page);
	u_page = split_url(from_prog , u_page);
	char * login = malloc(256);
	login = read_file(login);

	text = get_data_from_file(text , &line);
	w_sessions = get_w_sessions_all(w_sessions , text, &line);
	neded_data = get_neded_data(w_sessions , neded_data , line);
	champ = split(champ , neded_data);
	html_all(champ , u_page , login);

	return 0;
}
