//pinghuqiuyue.h

//Sample for room: ����ƽ������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_pinghuqiuyue);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ƽ������");
	
	add_npc("pub_youke");
	add_npc("pub_whitelady");         //add by zdn 2001-07-14

	add_door("���ݰ׵�", "���ݰ׵�", "����ƽ������");
	add_door("���ݷź�ͤ", "���ݷź�ͤ", "����ƽ������");
	add_door("���ݹ�ɽ", "���ݹ�ɽ", "����ƽ������");

	set("long"," ƽ������������ˮ�������������ȣ�ֱ�ڲ��ʡ����С������ƽ���ƾ�����ʱ�º����������������д������ҹʱ��µ��յ�������ɫ���������߱��Ƿź�ͤ�����������ǰ׵̡����߾��ǹ�ɽ");

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
