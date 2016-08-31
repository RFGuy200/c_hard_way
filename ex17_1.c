/*this is a small steps ex17
actions: c=create, s=set, g=get, d=delete, l=list
added these comments*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_DATA 500
#define MAX_ROWS 100

typedef struct Address{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
}address;

typedef struct Database{
	address rows[MAX_ROWS];
}database;

typedef struct Connection{
	FILE *filename;
	database *db;
}connection;

void die(char *message)
{
	if(errno){
		perror("ERROR");
	}else{ printf("ERROR: %s\n", message);	
	}
}

connection* Database_open(const char *filename, char mode)
{
	connection* conn = malloc(sizeof(connection));
	conn->db = malloc(sizeof(database));	
	
	
	if(mode == 'c'){
		conn->filename = fopen(filename, "w");
	}else{
		conn->filename = fopen(filename , "r+");
	}
	return conn;
}


void Database_create(connection *conn)
{
	int i =0;
	address addr = {.set=0, .id=i};
	for(i = 0; i <MAX_ROWS; i++){
		conn->db->rows[i] = addr;
	}
}

void Database_write(connection *conn)
{
	rewind(conn->filename);
	int rc = fwrite(conn->db, sizeof(database), 1, conn->filename);
	rc = fflush(conn->filename);
}




int main(int argc, char *argv[])
{
	char filename = argv[1];
	char action  = argv[2];

	

	int i = 0;
	connection *conn = Database_open( filename, action);//creates db in RAM and opens file

	switch(action){
		case'c':
			Database_create(conn);//populates db in RAM
			Database_write(conn);//populates file
			break;
		case's':
			//Database_set(conn, id, argv[4], argv[5]);
			break;
		case'g':
			//Database_get(conn, id);
			break;
		case'l':
			//Database_list(conn);
			break;
		case'd':
			//Database_delete(conn);
			break;
		default:
			die("Inavlid action:c=create, s=set, g=get, d=delete, l=list");
	}

	return 0;
}
