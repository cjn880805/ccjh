//nvxiangfang.h

//Sample for room: Ů�᷿
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_nvxiangfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ů�᷿");

	add_npc("guiyun_xiaolan"); 
	add_npc("guiyun_xiaoju");      // add by zdn 2001-07-14

	add_door("����ׯ", "����ׯ", "����ׯŮ�᷿");

	set("long"," �����ǹ���ׯŮ���ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧�߽ż��ӣ�����������ݽ�һ�ż��ʣ�����һ��������ɢ�ŵ������㡣" );
	set("sleep_room",1);
	

/*****************************************************
	set("exits", ([
		"east" : __DIR__"huating",
	]));
********************************************/
};


ROOM_END;
