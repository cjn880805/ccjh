ROOM_BEGIN(CRwiz_bw3);

void create()			//Call it when Room Create
{
	set_name( "�������2�㳡");	
	set("���ɴ���", 1);

	add_door("��1�㳡", "�������1�㳡", "�������2�㳡");
	add_door("��3�㳡", "�������3�㳡", "�������2�㳡");
	add_door("��4�㳡", "�������4�㳡", "�������2�㳡");
	add_door("��5�㳡", "�������5�㳡", "�������2�㳡");
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp