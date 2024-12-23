//yzjw_jiaowai4.h

//Sample for room:  扬州密林4
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_jiaowai4);
virtual void create()			//Call it when Room Create
{
	set_name( "扬州密林4");

	add_npc("gaibang_zhao_gouer");	

	add_door("扬州密林5","扬州密林5","扬州密林4");
	add_door("扬州树林3","扬州树林3","扬州密林4");

    set("long","扬州郊外的茂密树林，阴森可怖。抬头不见天日。这里也是扬州命案发生最多的地方。鸟兽蛇虫游荡不穷。");
 
};


ROOM_END;
