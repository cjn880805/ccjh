//gongmen.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_gongmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");     //zdn 2001-07-12 add

	add_door("�������", "�������", "����ǻʹ�����");
	add_door("����ǻʹ�ǰ��", "����ǻʹ�ǰ��", "����ǻʹ�����");

	set("long", "�����Ǵ���ʹ��Ĺ��ţ��ſڷ��������ߴ�ʯʨ������ʵ�û��һ����ӣ���������ֹ���ǽ���ʹ������������֣������ͽ���ʹ��ˡ�" );

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
