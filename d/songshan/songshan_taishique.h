//taishique.h

//Sample for room: ̫����
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_taishique);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̫����");
	
	add_npc("songshan_ding");         //add by zdn 2001-07-20


	add_door("�������ݳ�", "�������ݳ�", "��ɽ̫����");
	add_door("��ɽ���и�", "��ɽ���и�", "��ɽ̫����");
	add_door("������ʯ��", "������ʯ��", "��ɽ̫����");

	set("long", "��ɽ�ųƷ��⣬�ֳƳ�ɽ��Ϊ�����е���������̫�����Ҷ�ɽ������ɡ������ʱ�� '�Ը�' ��ȡ��ʫ�� '����ά�ߣ���������' ��������֮Ϊ����С���졣�׸����࣬����� '����̫������' ���֣�׭�Ĺ��ӣ��Ծ���������������ȥ����ɽ�����µ�·����һ��������������ˡ� ");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"east"  : "/d/shaolin/ruzhou",
		"west"  : "/d/shaolin/shijie1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		__DIR__"npc/yao" : 1,
	]));
********************************************/
};


ROOM_END;
