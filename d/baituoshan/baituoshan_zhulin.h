//zhulin.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_zhulin);

virtual void create()			//Call it when Room Create
{
	set_name( "����ɽ����");

	add_npc("animal_qingshe");/////////////////////////
	add_npc("animal_mangshe");


	add_door("����ɽ�ݴ�2", "����ɽ�ݴ�2", "����ɽ����");
	add_door("����ɽ�Ҷ�", "����ɽ�Ҷ�", "����ɽ����");

	set("long", "�����������֣������߳�û���ϱ�����ݴԡ�������һ�����Ҷ���");

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
