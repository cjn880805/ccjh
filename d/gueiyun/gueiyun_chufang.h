//chufang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("pub_cunfu");     // add by zdn 2001-07-13

	add_door("����ׯ", "����ׯ", "����ׯ����");

	set("long"," �����ǹ���ׯ�ĳ�����һ�����¸����������æ��æȥ����������������ĳ����ˡ�������Ӷ��ˣ��͸Ͽ��ҳ���Ҫ (serve)Щ�Եİɡ�" );
    
	set("ricewater", 5);

/*****************************************************
	set("exits", ([
		"south" : __DIR__"huayuan",
	]));
********************************************/
};


ROOM_END;
