//aobai.h

//Sample for room: ��������
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_aobai);

virtual void create()
{
	set_name( "����");

	add_npc("pub_bing");
	add_npc("shaolin_aobai");
	add_npc("pub_sunchengxian");//�����������
	
	add_door("��������", "��������", "��������");

	set("long", "һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴������ࡣ�Ŷ�������һ�����ң�д�š����޵�һ��ʿ���ݸ����������֣������йٱ����أ��䱸ɭ�ϡ����Ϲ���������������Ȼд�š������֡�" );

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
