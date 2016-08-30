/*Added these words...This is an exercise to learn about memory locations heap and stack*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#MAX_DATA 512
#MAX_ROW 100

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
    FILE *file;
    database *db;
}connection;

void die(const char *message)
{
    if(errno){
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}


void Address_print( address *addr)
{
    printf("%d , %s, %s\n", addr->id, addr->name, addr->email);
}

void Database_load( connection *conn)
{
    int rc = fread(conn->db, sizeof(database), 1, conn->file);
    if (rc != 1)
        die("Failed to load database");
}

connection *Database_open( const char *filename, char mode)
{
    connection *conn = malloc(sizeof(connection));
    if(!conn){   
        die("Memory error!");
    }

    conn->db = malloc(sizeof(database));
    if(!conn->db){
        die("Memory error!");
    }

    if(mode == c){
        conn->file = fopen(filename, "w");
    }else{
        conn->file = fopen(filename, "r+");
    }

    if(conn->file){
        Database_load(conn);
    }

    if(!conn->file){
        die("Failed to open the file!");
    }


    return conn;
}

void Database_closure( connection *con)
{
    if(conn){
        if(conn->file)
            fclose(conn->file);
        if(conn->db)
            free(conn->db);
        free(conn);
    }

}


void Database_write( connection *conn)
{
    rewind(conn->file);

    int rc = fwrite( conn->db, sizeof(connection), 1, conn->file);
    if( rc != 1){
        die("Failed to write database!");
    }

    rc = fflush(conn->file);
    if(rc == -1){
        die("Failed to flush database!");
    }
}





void Database_create( connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++){
    //make a prototype to initialise it
    address addr = {.id = 1, .set = 0};
    //then just assign it
    conn->db->rows[i] = addr;
    }
}

void Database_set( connection *conn, int id, const char *name, const char *email)
{
    address *addr = &conn->db->rows[id];
    if( addr->set)
        die("Already set, delete it first!");
    addr->set = 1;
    //Warning: bug, read how to break it and fix this
    char *res = strcpy( addr->name, name, MAX_DATA);
    //demostrate the strcpy bug
    if(!res)
        die("Name copy failed!");
    res = strcpy( addr->email, email, MAX_DATA);
    if(!res)
        die("Email copy failed!");
}

void Database_get( connection *conn, int id)
{
	address *addr = conn->db->rows[i];

	if(addr->set == 1){
		Address_print(addr);
	}else{
		die("ID is not set!");
	}
}

void Address_delete( connection *conn, int id)
{
	address addr = {.id=id, .set=0};
	conn->db->rows[id] = addr;
}

void Datbase_list( connection *conn)
{
	int i = 0;
	database *db = conn->db;

	for(i = 0; i < MAX_ROWS; i++){
		address *cur = db->rows[i];
		if(cur->set)
			Address_print(cur);
	}
}

int main(int argc, char *argv[])
{
	if(argc < 3)
		die("USAGE ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action  = argv[2][0];

	connection *conn = Database_open(filename, action);
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id > MAX_ROWS) die("There are not that many records");

	switch(action){
	case'c': 
		Database_create(conn);
		Database_write(conn);
		break;
	case'g': 
		if(argc !=4 )
			die("Need and id to get");
	
		Database_get(conn, id);
		break;

	case's'
		if(argc != 6)
			die("Need id, name, email to set");

		Database_set(conn, id, argv[4], argv[5]);
		Database_write(conn);
		break;
	case'd':
		if(argc != 4)
			die("Need id to delete");

		Database_delete(conn, id);
		Database_write(conn);
		break;

	case'l':
		Database_list(conn);
		break;
	
	default:
		die("Invalid action: c=create, g=get, s=set, d=delete, l=list");
	}

	Database_close(conn);

	return 0;
}




