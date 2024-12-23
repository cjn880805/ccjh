//lianhuashi.h

//Sample for room:  ��������ʯ
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_lianhuashi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������ʯ");

	add_npc("emei_su");		
	add_npc("emei_ling");		

	add_door("���һ��϶�", "���һ��϶�", "��������ʯ");
	add_door("���Ҿ��϶���", "���Ҿ��϶���", "��������ʯ");
	add_door("����������1", "����������1", "��������ʯ");

	set("long","��������ʯ���˴���ʯ�����ݺᣬ��������������ܽ�أ��·��������ϸ������������һ�֣��С������硹���ɴ�������ֱ��ϴ��أ�������ͨ���϶�����ͨ���϶���");

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
