//gumujiaohe.h

//Sample for room: ��ľ��ڭ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_gumujiaohe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��ڭ");
	
	add_npc("pub_dipi");     //add by zdn 2001-07-16

	add_npc("pub_nieming");
	add_door("���ݺɻ���", "���ݺɻ���", "���ݹ�ľ��ڭ");

	set("long", "��ľ��ڭ�ںɻ��������棬һ�Ų�ͬͼ����©����ʹ��͸��©�����������в���ˮ��ɽɫ�͸ߵʹ����¥�󣬴˴��;����С��Ʋ���Ӱ��֮��������׿���ң������������ɪ¥������һ�֡�ͥԺ��������Ϳռ䲻��֮�С�" );
	

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
