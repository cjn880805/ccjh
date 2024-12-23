//guiyunge.h

//Sample for room:  ���ҹ��Ƹ�
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_guiyunge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ҹ��Ƹ�");
	
	add_npc("pub_boydizi");
	add_npc("pub_girldizi");
	
	add_door("���ҹ�����", "���ҹ�����", "���ҹ��Ƹ�");
	add_door("������Ů��", "������Ů��", "���ҹ��Ƹ�");
	add_door("���Ҵ�����", "���Ҵ�����", "���ҹ��Ƹ�");

	set("long","���Ƹ�ԭ���ƴ����������ʦ�ĵ������δ�������䣬ɮ��ʿ���������ؽ������Ƹ�������Ů�壬���Ͽɵִ���������ǹ����á�");
    
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
