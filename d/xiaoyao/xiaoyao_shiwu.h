//shiwu.h

//Sample for room: ʯ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_shiwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ʯ��");

	add_npc("xiaoyao_xiaoyaozi");

	add_door("��ң��С��1", "��ң��С��1", "��ң��ʯ��");

	set("long", "���������е�һ��ʯ�ݣ������Ե�ʲô�徻�ͼ��ӣ������в�û��ʲô�ر�İ�������������ܵ��κζ�����ɧ�ţ��Ǹ������ڹ��ĺõط���");
	

/*****************************************************
	set("exits", ([ 
		"south" : __DIR__"xiaodao4",
	]));
********************************************/
};


ROOM_END;
