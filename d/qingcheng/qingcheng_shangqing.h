//shangqing.h

//Sample for room: ������幬
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_shangqing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������幬");
	
	add_npc("qingcheng_yuyan");          //add by zdn 2001-07-20


	add_door("�������ŵ�", "�������ŵ�", "������幬");
	add_door("��Ǻ�Ӧͤ", "��Ǻ�Ӧͤ", "������幬");
	add_door("����ɷ��", "����ɷ��", "������幬");


    

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"sanwanjiudao",
		"westup"   : __DIR__"huyingting",
		"west"     : __DIR__"yuanyangjing",
		"east"     : __DIR__"maguchi",
		"south"    : __DIR__"songfengguan",
	]));
*****************************************************/
};


ROOM_END;
