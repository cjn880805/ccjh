ROOM_BEGIN(CRwiz_bw5);

void create()			//Call it when Room Create
{
	set_name( "�������4�㳡");	
	set("���ɴ���", 1);

	add_door("��1�㳡", "�������1�㳡", "�������4�㳡");
	add_door("��2�㳡", "�������2�㳡", "�������4�㳡");
	add_door("��3�㳡", "�������3�㳡", "�������4�㳡");
	add_door("��5�㳡", "�������5�㳡", "�������4�㳡");
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp