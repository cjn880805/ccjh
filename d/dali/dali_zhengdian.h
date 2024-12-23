//zhengdian.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_zhengdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("pub_shinu1");   // zdn 2001-07-12 add
	add_npc("pub_zhaojunzhu");

	add_door("����ǻʹ�ǰ��", "����ǻʹ�ǰ��", "����ǻʹ�����");

	set("long", "�����Ǵ�����ʹ����������ʵ�ͨ���������ﴦ����£������ڻʵ۲��ڣ������Եò���ô�н��������ǳ��ȡ�" );

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
