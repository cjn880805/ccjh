//jiashan.h

//Sample for room: 华山假山小池
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_jiashan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山假山小池");
	
	add_npc("huashan_shidaizi");      //add by zdn 2001-07-20


	add_door("华山后院", "华山后院", "华山假山小池");

	set("long", "这是另一个小园子，里头有个小池塘。四周布有假山，增添林园美景。下雨时雨水落入溪塘中，清脆的水珠声有如玉珠落盘般悦耳。水气朦胧中抬头西望，只见远处苍山如黛，若隐若现，雨景妙趣无穷。");  
    
 
/*****************************************************
	set("exits",([
		"east" : __DIR__"houyuan",
	]));
********************************************/
};


ROOM_END;
