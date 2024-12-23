//majiu.h

//Sample for room: 马厩
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城马厩");

	//add npcs into the room
//	add_npc("animal_zaohongma");
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_ziliuma");
//	add_npc("pub_mafu");
			

	add_door("大理城兵营", "大理城兵营", "大理城马厩");

	set("long", "这是军营边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人只要带马来，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净。一直伺候到客人离城上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。    马厩中堆放著几堆草料，正中有一口泔槽。" );
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
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz

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
