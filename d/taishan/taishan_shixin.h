//shixin.h

//Sample for room: ̩ɽ����ʯ
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_shixin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ����ʯ");

	set("monster_chance", 30);

	add_door("̩ɽ������", "̩ɽ������", "̩ɽ����ʯ");

	set("long","�������������ķ嶥���������ʯ������һ�𣬾�˵�������Ĵ���⣬��������ʯʱʯ��㲻�ᶯҡ����֮��ҡ����ֹ��");
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));
	set("objects", ([
		__DIR__"npc/yujizi" : 1,
		__DIR__"npc/yuyinzi" : 1,
		__DIR__"npc/yuqingzi" : 1,
	]));
*****************************************************/
};


FIELD_END;
