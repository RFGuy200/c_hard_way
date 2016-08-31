/*this is a small steps ex17
actions: c=create, s=set, g=get, d=delete, l=list
added these comments*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


#define MAX_DATA 500
#define MAX_ROWS 100

typedef struct Address{
	int id;
	int set;
	char name[MAX_DATA];
	chare email[MAX_DATA];
}address;

typedef struct Database{
	address db[MAX_ROWS];
}database;

typedef struct Connection{
	FILE *filename;
	database *db;
}connection;



int main(int argc, char *argv[])
{
	char filename = argv[1];
	char action  = argv[2];

	int i = 0;
	connection *con = Datbase_open( filename, action);

	switch(action){
		case'c':
			Database_create(conn);
			break;
		case's':
			Database_set(conn, id, argv[4], argv[5]);
			break;
		case'g':
			Database_get(conn, id);
			break;
		case'l':
			Database_list(conn);
			break;
		case'd':
			Database_delete(conn);
			break;
		default:
			die("Inavlid action:c=create, s=set, g=get, d=delete, l=list");
	}

	return 0;
}
