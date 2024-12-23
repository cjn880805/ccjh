//biguan.h

//Sample for room: 闭关室
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_biguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "闭关室");

	add_npc("lingjiu_tonglao");

	add_door("灵鹫闭关室大门", "灵鹫闭关室大门", "灵鹫闭关室");


    set("sleep_room", 1);   

/*****************************************************
  set("exits",([
      "south" : __DIR__"men3",
  ]));
  set("objects",([
      CLASS_D("lingjiu")+"/tonglao" : 1,
  ]));
********************************************/
};


ROOM_END;
