//wuhoucigate.h

//Sample for room: ���������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_wuhoucigate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������");

	add_npc("pub_shiwei");   //zdn 2001-07-12 add

	add_door("�ɶ���", "�ɶ���", "�ɶ����������");

	set("long",	"����ԭ����������������˽��˳�������������ԭ�������ǰ�����츣������������������ȥ������Ϊ���Т֮�ס���������Ű������ǧ�����£�����ͷ���Բ�ȥ�ס�"	);
	

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
