//majiu.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	//add npcs into the room
//	add_npc("animal_zaohongma");
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_ziliuma");
//	add_npc("pub_mafu");
			

	add_door("�����Ǳ�Ӫ", "�����Ǳ�Ӫ", "����������");

	set("long", "���Ǿ�Ӫ���ϵ����ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ֻҪ�������������Ǿͻ����ǣ�����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·�����������µ���ľ���϶���һ����ľ��(paizi)��    �����жѷ������Ѳ��ϣ�������һ����ۡ�" );
    set("no_fight", "1");
    set("no_beg", "1");

/*****************************************************
      set("outdoors", "city");
      
      set("objects", ([
               "/d/city/npc/zaohongma": 1,
               "/d/city/npc/huangbiaoma": 1,
               "/d/city/npc/ziliuma": 1,
               __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ������һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz

TEXT]));
      set("exits",([ 
          "east"  : __DIR__"bingying",
      ]));
********************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;