//zhangfu.h
//Sample for room: �Ÿ�����

ROOM_BEGIN(CRBeiJing_zhangfu);

virtual void create()			
{
	set_name( "�����Ÿ�");

	add_npc("pub_shiwei");
	add_npc("pub_shiwei");
	
	add_door("��������", "��������", "�����Ÿ�");
	add_door("�����Ÿ�����", "�����Ÿ�����", "�����Ÿ�");

	set("long", "һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴������ࡣ�����д����������أ��䱸ɭ�ϡ����Ϲ���������������Ȼд�Ŵ��ġ��š��֡�" );

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
