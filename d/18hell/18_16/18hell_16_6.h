//18hell_16.h
//十八地狱第十二层畜性地狱第6房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_16_6);

virtual void create()			//Call it when Room Create
{
	set_name("畜性地狱");
	
	add_npc("diyu_shizhe16");

};

virtual int do_look(CChar * me)
{
	say("洞口前一巨鬼手提一罪人，从一巨石上将罪人扔进狱中，四周高墙耸立，高墙下是木桩栏成的畜圈，圈中，牛、羊、猪、狗、狼、虎、貂、狮等动物正在撕咬吞食罪人，残肢、断腿、破头、裂肚，罪人痛苦异常。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
