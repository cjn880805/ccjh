//mudao.h

//Sample for room: Ĺ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_mudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ĺ��");

	add_npc("taohua_huang");
	add_npc("taohua_shoumu");        //add by zdn 2001-07-20


	add_door("�һ���", "�һ���", "�һ���Ĺ��");

	set("long", "����ͨ��Ĺ�ҵ�ͨ����ͨ��ʮ�ֿ�������������һ�Ŵ���ҹ���飬�յ�����Ĺ����ͬ���硣Ĺ����ͷ����Ĺ�ҡ�");
	

/*****************************************************
	set("exits", ([
		"up"   : __DIR__"mudi",
		"down" : __DIR__"mushi",
	]));
********************************************/
};


ROOM_END;
