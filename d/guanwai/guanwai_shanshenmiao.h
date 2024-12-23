//shanshenmiao.h

//Sample for room: ɽ����
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_shanshenmiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ����");
	
	add_npc("pub_xiaozei");    // add by zdn 2001-07-13
	add_npc("pub_wanghu");

	set("monster_chance", 1);

	add_door("�����·2", "�����·2", "����ɽ����");

	set("long","����һ����ľ���ʯͷ�ݳɵ�С����ǰ����ɢ����һЩȻ���Ļҽ������﹩����ɽ��ү�ϰ�ͷ����λ(lingwei)����˵�������вɲ��˵���ʦү������ÿ����ɽ�ڲεĲοͶ�Ҫ��������ݣ�ϣ���ܵõ������˼ҵı��ӡ�" );


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
