//hehuating.h

//Sample for room: �ɻ���
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_hehuating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ɻ���");
	
	add_npc("pub_shennongdizi");              //add by zdn 2001-07-16
	add_npc("pub_niefeiqong"); 

	add_door("������԰", "������԰", "���ݺɻ���");
	add_door("���ݹ�ľ��ڭ", "���ݹ�ľ��ڭ", "���ݺɻ���");

	set("long", "�ɻ������������������䣬��ָ�ˬ������ȡ���䣺��һˮ�����̣�ǧ���Ա�족֮ʫ�⡣��ǰ����ƽ̨���ٺɳأ�Ϊ�����ͺ�����ʤ�����ʳơ��ɻ������������л�̨ͥԺ����ʯ�������Գ�һ����" );
	
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
