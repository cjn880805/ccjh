ROOM_BEGIN(CRvoid_room);

void create()			//Call it when Room Create
{
	//set name of our room
	set_name( " ±ø’ÀÌµ¿");
	
};

int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "get") == 0
		||strcmp(comm, "drop") == 0
		||strcmp(comm, "give") == 0
		||strcmp(comm, "use") == 0)
			return 1;

	return CRoom::handle_action(comm, me, arg, tar);
}

ROOM_END;
