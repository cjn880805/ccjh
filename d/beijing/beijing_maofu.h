//maofu.h
//Sample for room: ë������

ROOM_BEGIN(CRBeiJing_maofu);

virtual void create()			
{
	set_name( "����ë��");

	add_npc("pub_shiwei");
	add_npc("pub_shiwei");
	
	add_door("��������", "��������", "����ë��");
	add_door("����ë������", "����ë������", "����ë��");

	set("long", "һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴������ࡣ�����д����������أ��䱸ɭ�ϡ����Ϲ���������������Ȼд�Ŵ��ġ�ë���֡�" );

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