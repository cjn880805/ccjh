//18hell_12.h
//十八地狱第八层铁床地狱第5房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_12_5);

virtual void create()			//Call it when Room Create
{
	set_name("铁床地狱");
	
	add_npc("diyu_shizhe12");

};

virtual int do_look(CChar * me)
{
	say("岩层中有围城，围城吸巨石，巨石间有木柱、石柱、木质串斗房架、铁栏、木栏等。巨型石拱内置一巨的铁钉床，床头有兽型浮雕，滚烫的铁钉床上躺着烧焦若干罪人。", me);
	say("鬼差们举起铁锤击打罪人，有的用铁叉叉制罪人受刑，铁床边二鬼卒用铁铲向床下添加着燃料，还有数鬼卒强抢押着受罪者的拖往铁床，床的另一边吹火加柴鬼若干。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
