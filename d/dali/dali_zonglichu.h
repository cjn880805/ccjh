//zonglichu.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_zonglichu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("pub_shiwei");
	add_npc("pub_shiwei2");  //zdn 2001-07-12 add

	add_door("���������˾����", "���������˾����", "�������������");
	add_door("���������˾����", "���������˾����", "�������������");
	add_door("���������˾ͽ��", "���������˾ͽ��", "�������������");
	add_door("�������������", "�������������", "�������������");

	set("long", "��������������̫���������֮������������������þ������������ܰ��˺ܶ�軨�����涷�ޡ��軨�Ǵ���������������˶���Ҳ���Ӱ��мӡ�" );
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
