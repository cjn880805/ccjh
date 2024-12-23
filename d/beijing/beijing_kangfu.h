//kangfu.h

//Sample for room: ��������
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_kangfu);

virtual void create()			
{
	set_name( "��������");

	add_npc("pub_shiwei");
	add_npc("shaolin_shenzhao");
	add_npc("pub_jinjiu");

	set("no_fight",1);
	set("no_cast",1);
	
	add_door("��������", "��������", "��������");

	set("long", "һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴������ࡣ�����д����������أ��䱸ɭ�ϡ����Ϲ���������������Ȼд�Ŵ��ġ������֡�" );

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
