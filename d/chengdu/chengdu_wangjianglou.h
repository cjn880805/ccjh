//wangjianglou.h

//Sample for room: ����¥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_wangjianglou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");

	add_npc("pub_shinu1");   //zdn 2001-07-12 add
	add_npc("pub_duguqiu");

	add_door("�ɶ���", "�ɶ���", "�ɶ�����¥");

	set("long",	"����¥�����������������Ľǣ�������˽ǣ��������ߣ��̽Ƿ����������������������ϣ�Զ�����Ϻӣ�������棬�ۻ���ʵΪʤ����¥�����⣬����ǧ�����죬ÿ�������뵣��������䣬�����������������ǡ�¥ǰѦ�ξ�����˵��ΪѦ��Ưϴһ�ֺ�ɫʫ�������ǧ��: �޲��ž������أ���ɫ�ż�����䡣��Ҳ����һ��Ů�Ĵ�����Ψһ����"	);

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




