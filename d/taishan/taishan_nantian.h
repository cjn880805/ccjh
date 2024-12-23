//nantian.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_nantian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");

	//add npcs into the room
	add_npc("pub_weishi2");/////////////////////////

	set("monster_chance", 50);
	set("monster_type", 2);

	add_door("̩ɽ���ɷ�", "̩ɽ���ɷ�", "̩ɽ������");
	add_door("̩ɽ���", "̩ɽ���", "̩ɽ������");
	add_door("̩ɽ�¹۷�", "̩ɽ�¹۷�", "̩ɽ������");
	add_door("̩ɽ��ʶ�", "̩ɽ��ʶ�", "̩ɽ������");

	set("long","������ʮ���̣��������̩ɽ������ڴ��������︽��ɽ�£�Ⱥɽ�����أ����������ƣ���ؿ������޿���״���������������߿ɵ�һ���м��������߱����¹۷壬���������ǵ���ʶ�֮·��");

/*****************************************************
	set("exits", ([
		"eastup" : __DIR__"tianjie",
		"northup" : __DIR__"yuhuang",
		"west" : __DIR__"yueguan",
		"southdown" : __DIR__"shengxian",
	]));
	set("objects",([
		__DIR__"npc/jiang" : 1,
		__DIR__"npc/wei-shi3" : 2,
	]));
*****************************************************/
};


FIELD_END;
