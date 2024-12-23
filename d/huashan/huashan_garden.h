//garden.h

//Sample for room: ��ɽ��԰
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_garden);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��԰");
	
	add_npc("huashan_yuelingshan");       //add by zdn 2001-07-20
	add_npc("helpnpc012");

	add_door("��ɽ������Ϊ��", "��ɽ������Ϊ��", "��ɽ��԰");
	add_door("��ɽ�鷿", "��ɽ�鷿", "��ɽ��԰");
	add_door("��ɽ����", "��ɽ����", "��ɽ��԰");
	add_door("��ɽ��Ժ", "��ɽ��Ժ", "��ɽ��԰");
	add_door("��ɽ����", "��ɽ����", "��ɽ��԰");

	set("long", "����һ��԰�ӣ�ͥԺ���ģ����ֻ������ǲ��١��ٻ����ţ�ɽʯ��׾���������壬���ɴ��񣬾���ɷ�����ˡ��峺��Ϫ����������һ��Сͤ�ӣ�����Ϫˮ��������ȥ������ͨ��������Ϊ����������һ�����ȣ�����С�ݴ���������ζ������������ȥ������");  
    
 
/*****************************************************
	set("exits",([
		"east"      : __DIR__"buwei1",
		"west"      : __DIR__"chufang",
		"north"     : __DIR__"changlang",
		"south"     : __DIR__"shufang",
		"southwest" : __DIR__"houyuan",
	]));
********************************************/
};


ROOM_END;
