//majiu.h

//Sample for room: �ƺ����
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ����");

	//add npcs into the room
//	add_npc("animal_zaohongma");/////////////////////////
//	add_npc("animal_ziliuma");
//	add_npc("animal_huangbiaoma");
	add_npc("pub_mafu");

				
	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("�ƺӿ͵�", "�ƺӿ͵�", "�ƺ����");

	set("long","���ǿ�ջ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������һ����ۡ���������µ���ľ���϶���һ����ľ��(paizi)��");
	set("no_fight", "1");
	set("no_beg", "1");
	

/*****************************************************
	set("outdoors", "huanghe");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		__DIR__"npc/mafu": 1,
	]));
	set("item_desc", ([
	"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz
          ���ݳ�:  ridelz

TEXT]));
	set("exits",([ 
	    "east"      : __DIR__"kedian",
	]));
********************************************/
};


CHANGAN_END;
