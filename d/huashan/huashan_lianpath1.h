//lianpath1.h

//Sample for room: 华山莲花峰小路
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_lianpath1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山莲花峰小路");


	add_door("华山镇岳宫", "华山镇岳宫", "华山莲花峰小路");
	add_door("华山沉香劈山处", "华山沉香劈山处", "华山莲花峰小路");

	set("long", "小路通往莲花峰，周围静静悄悄，微闻蝉鸣。四望密林幽谷，让人胆寒。");  
    
 
/*****************************************************
      set("exits",([  
          "westup"   : __DIR__"chengxiang",
          "eastdown" : __DIR__"lianpath1",
      ]));
********************************************/
};


ROOM_END;
