/*this is a small steps ex17
actions: c=create, s=set, g=get, d=delete, l=list
added these comments*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_DATA 100
#define MAX_ROWS 100

typedef struct Address{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
	char last_name[MAX_DATA];
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
	exit(1);
}

void Database_load(connection *conn)
{
	int rc = fread(conn->db, sizeof(database), 1 ,conn->filename);
	if(rc!=1)
		die("Failed to load database");
}

connection* Database_open(const char *filename, char mode)
{
	connection* conn = malloc(sizeof(connection));
	if(!conn)
		die("Failed to allocate memory for database");
	conn->db = malloc(sizeof(database));	
	if(!conn->db)
		die("Failed to allocate memory for database");
	
	
	if(mode == 'c'){
		conn->filename = fopen(filename, "w");
	if(!conn->filename)
		die("Failed to create database file");
	}else{
		conn->filename = fopen(filename , "r+");
		if(!conn->filename)
			die("Failed to open database file for update");
		if(conn->filename)
			Database_load(conn);
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
	if(rc != 1)
		die("Error writing the file");
	rc = fflush(conn->filename);
	if(rc == -1)
		die("Error flushing the file");
}


void Database_set(connection *conn, int id, const char *name,  const char *last_name, const char *email)
{
	address *addr = &conn->db->rows[id];
	if(addr->set)
		die("id already exists, delete it first");
	addr->set = 1;
	addr->id = id;
	char *rc = strcpy(addr->name, name);
	if(!rc)
		die("Error copying name");
	rc = strcpy(addr->email, email);
	if(!rc)
		die("Error copying email");
	rc = strcpy(addr->last_name, last_name);
	if(!rc)
		die("Error copying last name");

}

void Address_print(address *addr)
{
	printf("%s, %s, %s, %i, %i\n", addr->name, addr->last_name, addr->email, addr->set, addr->id);
} 


void Database_get(connection *conn, int id)
{
	address *addr = &conn->db->rows[id];
	if(!addr->set)
		die("id does not exist");
	Address_print(addr);
}


void Database_list(connection *conn)
{
	database *db = conn->db;
	int i =0;

	for(i = 0; i < MAX_DATA; i++){
		address *addr = &db->rows[i];
		if(addr->set)
			Address_print(addr);
	}
}

void Database_close(connection *conn)
{
	if(conn){
		if(conn->filename)
			fclose(conn->filename);
		if(conn->db)
			free(conn->db);
		free(conn);
	}
}

void Database_delete( connection *conn, int id)
{
	address addr = {.id=id, .set=0};
	conn->db->rows[id] = addr;

}

void Database_find(connection *conn, const char *name)
{
	int i = 0;
	int found = 0;
	for(i = 0; i < MAX_ROWS; i++){
		address *addr = &conn->db->rows[i];
		if(strstr(addr->name, name)||strstr(addr->last_name, name)){
			Address_print(addr);
			found = 1;
		}
	}
	if(found == 0)
		puts("Entry does not exists");

}
	

int main(int argc, char *argv[])
{
	if(argc < 3)
		die("Too few arguments");
	char *filename = argv[1];
	char action  = argv[2][0];
	int id = 0;



	if (argc > 3)
		id = atoi(argv[3]);

	connection *conn = Database_open( filename, action);//creates db in RAM and opens file

	switch(action){
		case'c':
			Database_create(conn);//populates db in RAM
			Database_write(conn);//populates file
			break;
		case's':
			if(argc < 7)
				die("Not enough arguments, need id, name, last name, email");
			Database_set(conn, id, argv[4], argv[5], argv[6]);
			Database_write(conn);
			break;
		case'g':
			if(argc < 4)
				die("Need id");
			Database_get(conn, id);
			break;
		case'l':
			Database_list(conn);
			break;
		case'd':
			if(argc < 4)
				die("Need id");
			Database_delete(conn, id);
			Database_write(conn);
			break;
		case'f':
			Database_find(conn, argv[3]);
			break;
		default:
			die("Inavlid action:c=create, s=set, g=get, d=delete, l=list");
	}
	
	Database_close(conn);

	return 0;
}
