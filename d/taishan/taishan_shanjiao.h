//shanjiao.h

//Sample for room: ̩ɽɽ��
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_shanjiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽɽ��");

	add_npc("wiz_guard");

	add_door("̩ɽ��ڷ�", "̩ɽ��ڷ�", "̩ɽɽ��");
	add_door("�ƺӰ���5", "�ƺӰ���5", "̩ɽɽ��");
	add_door("̩ɽ�����", "̩ɽ�����", "̩ɽɽ��");

	set("no_fight", 1);

/*****************************************************
	set("exits", ([
		"north" : __DIR__"daizong",
		"south" : __DIR__"yidao3",
	]));
	
*****************************************************/
};


ROOM_END;
