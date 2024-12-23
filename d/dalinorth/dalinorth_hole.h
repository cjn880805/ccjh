//hole.h

//Sample for room: �����֥�ƶ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_hole);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����֥�ƶ�");

	add_npc("pub_youke");     // add by zdn 2001-07-13

	add_door("����ǳ���", "����ǳ���", "�����֥�ƶ�");

	set("long", "���Ż��۽��붴�ڣ��ػ����У����ã�����һ����Ȼ���ʣ�ʯ���飬ʯ��ʯ����������͸��������ʤ�����ձ�Ӱ�����´����ң�Ϫ�ƽ�ˮ�������ֺ���ʯ��δ䣬���Ŀɰ���");
	
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
