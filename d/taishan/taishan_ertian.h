//ertian.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_ertian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");

	set("monster_chance", 40);
	set("monster_type", 2);

	add_door("̩ɽ������", "̩ɽ������", "̩ɽ������");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ������");

	set("long","�����ֽС������š���һ��ĵ�ɽ���������ﶼ���ۼ��������������̩ɽ��һ�밡�����ǰ���վ���ʮ���̣��ܶ��˶�������ԥ������");
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"wudafu",
		"southdown" : __DIR__"huima",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/tiansong" : 1,
		__DIR__"npc/tianbai" : 1,
	]));
*****************************************************/
};


FIELD_END;
