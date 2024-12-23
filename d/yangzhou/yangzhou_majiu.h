//majiu.h

//Sample for room: 马厩
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "马厩");

	//add npcs into the room
//	add_npc("pub_mafu");
//	add_npc("animal_zaohongma");
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_ziliuma");


	add_door("扬州客店", "扬州客店", "扬州马厩");

    set("outdoors", "city");
    set("no_fight", "1");
    set("no_beg", "1");
    
/*****************************************************
      set("objects", ([
               __DIR__"npc/zaohongma": 1,
               __DIR__"npc/huangbiaoma": 1,
               __DIR__"npc/ziliuma": 1,
               __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      北京城:  ridebj
          苏州城:  ridesz
          杭州城:  ridehz
          福州城:  ridefz
          大理城:  ridedl
          襄阳城:  ridexy
          永登城:  rideyd
          伊犁镇:  rideyl
          佛山镇:  ridefs
          峨嵋山:  rideem

TEXT]));
      set("exits",([ 
          "west"      : __DIR__"kedian",
      ]));
********************************************/
};


ROOM_END;
