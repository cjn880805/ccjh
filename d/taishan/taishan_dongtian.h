//dongtian.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_dongtian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");
	
	add_npc("taishan_jianchu");        //add by zdn 2001-07-20

	set("monster_chance", 20);

	add_door("̩ɽ̽��ʯ", "̩ɽ̽��ʯ", "̩ɽ������");

	set("long","������᷶��Ķ�����ڡ��������ξ���������Ͽ�ڡ�ӥ��ȣ������ɽ��");
	

/*****************************************************
	set("exits", ([
		"west" : __DIR__"tanhai",
	]));
*****************************************************/
};


FIELD_END;
