//xiaolu1.h

//Sample for room: 华山小山路
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_xiaolu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山小山路");
	
	add_npc("pub_youke");          //add by zdn 2001-07-17


	add_door("华山玉女峰", "华山玉女峰", "华山小山路");
	add_door("华山小筑", "华山小筑", "华山小山路");

	set("long", "这里是华山的一条小山路，地势较为平缓，不似其它地方那么险峻。你走在这里，四周静悄悄的，你就象走进了一个世外桃源。");  
    
 
/*****************************************************
      set("exits",([  
          "southwest"     : __DIR__"yunu",
          "northeast"     : __DIR__"xiaolu2",
      ]));
********************************************/
};


ROOM_END;
