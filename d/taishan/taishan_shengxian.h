//shengxian.h

//Sample for room: ̩ɽ���ɷ�
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_shengxian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ���ɷ�");
	
	add_npc("taishan_tianyi");     //add by zdn 200107-20

	set("monster_chance", 40);
	set("monster_type", 2);

	add_door("̩ɽ����", "̩ɽ����", "̩ɽ���ɷ�");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ���ɷ�");

	set("long","������ʮ���̵��м䣬���������˵�һ�γ�Ϊ��ʮ�ˣ�������ֱ�������ŵ�һ�γ�Ϊ��ʮ�ˡ��ɴ˿���ʯ���ϣ�������˿��Կ���ǰ����˵�Ь�ף�ǰ����˻�ͷ��ɼ���������˵ķ�����������һ����ÿ��ʮ������Ҫ��һ��Ϣ��");

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"nantian",
		"southdown" : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/jianchu" : 1,
	]));
*****************************************************/
};


FIELD_END;
