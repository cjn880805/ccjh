//fangtang.h



//Sample for room: 明教饭堂

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_fangtang);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "明教饭堂");



	CBox * box = Add_Box();
	box->add_object("jiuping", 1);	
	box->set_name( "铁柜");	

	add_door("明教广场", "明教广场", "明教饭堂");



	set("long", "这里便是明教的饭堂。摆满了长长的餐桌和长凳，几位年轻教众正来回忙碌着布置。桌上摆了几盆豆腐，花生，青菜以及大鱼，大肉，鸡，酒等美味食。东边的走廊通向广场。");



/*****************************************************

      set("exits",([ 

          "east" : __DIR__"square", 

      ]));



      set("objects",([

          "/d/hangzhou/npc/obj/jiuping": 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

      ]));

//      

********************************************/

};





ROOM_END;
