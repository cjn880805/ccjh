//huqiu.h

//Sample for room: ����ɽ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_huqiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ");

	CBox * box = Add_Box();
	box->add_object("eluanshi", 1);	
	box->set_name( "����");	

	add_npc("pub_luxiuwen");

	add_door("������ʯ�ٵ�2", "������ʯ�ٵ�2", "���ݻ���ɽ");
	add_door("����ͷ��ɽ", "����ͷ��ɽ", "���ݻ���ɽ");

	set("long", "����ɽ����ɽ���ƶ׻������������ഫ��������а׻�������Ĺ�ϣ���������ɽǰ�����Ĺȣ���ľ��ï����ɫ�������ɽ���ɿ�㣬ʯ�������������ۻ롣�С�ɽ���������ɫ������Ϊ�����е�һ��ʤ����" );

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
