//yidao.h

//Sample for room: ̩ɽ�����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_yidao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ�����");
	
	add_npc("taishan_yuyinzi");       //add by zdn 2001-07-20
	add_npc("helpnpc016");

	add_door("̩ɽɽ��", "̩ɽɽ��", "̩ɽ�����");
	add_door("���ݶ����", "���ݶ����", "̩ɽ�����");
	add_door("Ȫ��ɽ·1", "Ȫ��ɽ·1", "̩ɽ�����");

	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"yidao2",
		"north" : __DIR__"taishanjiao",
	]));
	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));
*****************************************************/
};


ROOM_END;
