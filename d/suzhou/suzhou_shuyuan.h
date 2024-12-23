//shuyuan.h

//Sample for room: ��Ժ
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ժ");

	//add npcs into the room
	add_npc("pub_jiaoxi");/////////////////////////
	add_npc("pub_marulong");

	add_door("������", "������", "������Ժ");

	set("long", "��������Ժ�Ľ��ã�����������һ����Ⱦ��һλ�Ϸ�������̫ʦ���Ͻ�ѧ��������������������ѧ��ѧ����һ�Ź��ⰻȻ���鰸��������ǰ�棬���ϰ��ż��������˵���װ�鼮�� " );
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
