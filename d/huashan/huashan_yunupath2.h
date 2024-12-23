//yunupath2.h

//Sample for room: 华山玉女峰山路2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunupath2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山玉女峰山路2");
	
	add_npc("pub_jianke");            //add by zdn 20017-07-17


	add_door("华山玉女峰山路1", "华山玉女峰山路1", "华山玉女峰山路2");
	add_door("华山思过崖", "华山思过崖", "华山玉女峰山路2");

	set("long", "这里是玉女峰后山的一条山路。路边长满了翠竹，每当微风拂过，竹叶便沙沙作响，显得分外的幽静。");  
    
 
/*****************************************************
      set("outdoors", "xx");
      set("exits",([  
          "southup"   : __DIR__"siguoya",
          "northdown" : __DIR__"yunupath1",
      ]));
********************************************/
};


ROOM_END;
