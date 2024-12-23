//mantianxing.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_mantianxing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("pub_youke");  // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("������ſ���", "������ſ���", "����������");
	add_door("����Ȳݶ�", "����Ȳݶ�", "����������");

    set("long","������һƬ������ƽԭ����������û���κ�Сɽ���꣬����һ����Ҳ�Ҳ�����̧����ȥ����ƽ�߱�ֱ�Ľ�������ѩԭ�ָ������ߡ���˵ҹ�������������ڵ����ɱ�������Ƕ�����ɽ�����Ƕ��ڴ������ϲԵı��ӡ�" );

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
