//tanhai.h

//Sample for room: ̩ɽ̽��ʯ
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_tanhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ̽��ʯ");

	set("monster_chance", 30);

	add_door("̩ɽ�չ۷�", "̩ɽ�չ۷�", "̩ɽ̽��ʯ");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ̽��ʯ");

	set("long","����һ���ɽ�����ͻ���ľ�ʯ����Լ�����࣬��ֱָ��������ʯ��������ƾ������Ұ�������������о��ߵ�ɫ���ˣ���ͨ��һ�㶼�����ʵ����̽��ʯ��");
	

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"riguan",
		"east" : __DIR__"dongtian",
	]));
*****************************************************/
};


FIELD_END;
