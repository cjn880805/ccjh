//yuhuang.h

//Sample for room: ̩ɽ��ʶ�
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_yuhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ��ʶ�");

	set("monster_chance", 10);
	//add npcs into the room
	add_npc("pub_weishi");
	add_npc("pub_weishi");
	add_npc("pub_weishi");
	
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ��ʶ�");
	add_door("̩ɽ���˷�", "̩ɽ���˷�", "̩ɽ��ʶ�");
	add_door("̩ɽ����̨", "̩ɽ����̨", "̩ɽ��ʶ�");
	add_door("̩ɽ�չ۷�", "̩ɽ�չ۷�", "̩ɽ��ʶ�");

	set("long","�˴�����̩ɽ������������һ����۹ۣ���ǰΪ�ŵǷ�̨�������ʵ۷�������ʽ������������С�̨����һ���ֱ�����˵�Ǻ������������Զ����һʯ�٣����顸����С���´������������ϱ���������������֮��������̨��");

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"nantian",
		"eastdown"  : __DIR__"riguan",
		"west"      : __DIR__"zhangren",
		"up"        : __DIR__"fengchan",
	]));
	set("objects",([
		__DIR__"npc/wei-shi2" : 3,
	]));
*****************************************************/
};


FIELD_END;
