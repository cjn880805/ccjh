ROOM_BEGIN(CRwiz_bw6);

void create()			//Call it when Room Create
{
	set_name( "�������5�㳡");	
	set("���ɴ���", 1);

	add_door("��1�㳡", "�������1�㳡", "�������5�㳡");
	add_door("��2�㳡", "�������2�㳡", "�������5�㳡");
	add_door("��3�㳡", "�������3�㳡", "�������5�㳡");
	add_door("��4�㳡", "�������4�㳡", "�������5�㳡");
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp