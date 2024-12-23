//shilin.h

//Sample for room: �����·��ʯ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_shilin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����·��ʯ��");

	add_npc("pub_caishiren");     // add by zdn 2001-07-13

	add_door("����ǲ�ɽ", "����ǲ�ɽ", "�����·��ʯ��");
	add_door("����ǳ���", "����ǳ���", "�����·��ʯ��");

	set("long", "�����������洦�ɼ���ʯ���죬ʯ��Լ���ʯ��ͦ����������ʣ��������ˡ�����ʯ���ܾۣ��罣��ſգ�çç�Բԣ�ٲȻһƬ�ֺ���εΪ׳�ۡ����Ӵ�ɽ֮�л����ֱк���ɵ�ˮ���ƣ���ɽȪ��ۣ�������������");
	
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
