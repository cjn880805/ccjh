//dongyidao.h

//Sample for room:  ���ݶ����
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_dongyidao);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݶ����");

	add_npc("pub_tiaofu");
        add_npc("pub_playboy");
        add_npc("pub_daoke");           //add by zdn 2001-07-16

	add_door("���ݶ���","���ݶ���","���ݶ����");
	add_door("̩ɽ�����","̩ɽ�����","���ݶ����");

    set("long","������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡��������ݿ쵽�ˡ�");
	

/********************************************************
	set("exits", ([
		"west" : "/d/city/dongmen",
		"east" : __DIR__"yidao1",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 3,
	]));
********************************************************/
 
};


ROOM_END;
