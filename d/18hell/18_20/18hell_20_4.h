//18hell_20.h
//十八地狱第十六层蛆虫地狱第4房间

ROOM_BEGIN(CR18hell_20_4);

virtual void create()			//Call it when Room Create
{
	set_name("蛆虫地狱");
	
	add_npc("diyu_shizhe20");

};

virtual int do_look(CChar * me)
{
	say("狱中一巨大的岩石中间有一圆形深坑，深坑内，一大鬼、四小鬼毒蛇缠身，罪人正被毒蛇、毒蝎、蛆虫等钻咬叮食。坑外高高的岩石边，一罪人正被二鬼差揪押着欲推入坑中。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
