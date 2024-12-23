ROOM_BEGIN(CRwiz_bw5);

void create()			//Call it when Room Create
{
	set_name( "武道场第4广场");	
	set("门派大赛", 1);

	add_door("第1广场", "武道场第1广场", "武道场第4广场");
	add_door("第2广场", "武道场第2广场", "武道场第4广场");
	add_door("第3广场", "武道场第3广场", "武道场第4广场");
	add_door("第5广场", "武道场第5广场", "武道场第4广场");
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp