//nanyangcity.h

//Sample for room:  ������
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
RESIDENT_BEGIN(CRnanyangcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	if(random(2))
		add_npc("pub_playboy");

	set("resident", "����");
	set("capacity", 5);
				
	add_npc("pub_hongxian");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");

	add_door("�ƺӰ���5", "�ƺӰ���5", "������");
	add_door("�������ݳ�", "�������ݳ�", "������");

	add_door("����ӭ��¥", "����ӭ��¥", "������");
	add_door("����������ջ", "����������ջ", "������");
/********************************************************
	set("long", @LONG
������ǵ�����������Ĺʾӡ������ǲ�����Ϊ�س�Ҫ�壬
���������Ŀ����ر�࣬����Ҳ�����ȫ����¥����ջ����꣬
�����Ӷ��ǡ������˿����٣�����������ɫ�ҴҵĽ������ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"hanshui2",
		"north" : __DIR__"yidao3",
		"east" : __DIR__"kedian1",
		"west" : __DIR__"jiulou1",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));
	set("outdoors", "shaolin");
****************************************************************/
};


RESIDENT_END;
