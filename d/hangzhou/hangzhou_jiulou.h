//jiulou.h

//Sample for room: ¥��¥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_jiulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "¥��¥");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	add_npc("pub_caozhangguei");

	set("no_fight",1);
	set("no_cast",1);
	set("no_beg",1);

	add_door("������ʯ���10", "������ʯ���10", "����¥��¥");
	add_door("����¥��¥��¥", "����¥��¥��¥", "����¥��¥");

	set("long","����¥��¥����Բ�������˲�֪�������ʽ�����Ǻ���һ�������κ������Ƕ�һ���������ﳢ�������������ֺ��ļ����˸�ʽ�˵ȡ���С��������ȥ��æ���к����ˡ�ǽ�Ϲ��ż۸�����(paizi)��" );


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
