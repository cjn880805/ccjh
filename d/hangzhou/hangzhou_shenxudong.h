//shenxudong.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shenxudong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	add_npc("xiaoyao_mengmianr");

	add_door("����������", "����������", "��������");

	set("long","�����񷶥�ϵ�ʯ���������һ����⣬��������һ���족�����ϱ�����ɽ��·��" );
	

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
