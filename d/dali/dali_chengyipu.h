//chengyipu.h

//Sample for room: Ѧ�ǳ�����
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_chengyipu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѧ�ǳ�����");

	add_npc("pub_xueboss");		//add by lanwood 2001-03-18

	add_door("����Ƕ�", "����Ƕ�", "�����Ѧ�ǳ�����");

	set("long", "����һ�����ֺŵĹ���ׯ����������˸�ʽ����������񡢾˿������Ƥ������춷��л������ȹ��ˮ��ɫ�ް�������ɫ�Ż���������һ���㡣" );

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
