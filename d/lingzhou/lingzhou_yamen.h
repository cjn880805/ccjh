//yamen.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yamen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_yayi");/////////////////////////
	add_npc("helpnpc018");

	add_door("���ݶ�", "���ݶ�", "��������");

	set("long", "�������ݸ������ڵأ���ɫ����ƽʱ�������ţ���ǰ�ĸ��������������û����ɵ�����ˮ���վ�š������и���ġ�");  
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
