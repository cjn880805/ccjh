//18hell_8_7.h
//十八地狱第四层沸屎地狱第7房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_8_7);

virtual void create()			//Call it when Room Create
{
	set_name("沸屎地狱");
	
	add_npc("diyu_shizhe8");

};

virtual int do_look(CChar * me)
{
	say("形成转角的围城高墙间有钢链，中间高墙上一铁锅内沸烟滚滚，二鬼分立锅旁，手持长柄瓢，将锅内烧得滚烫的污浆从高墙上倾泻到墙下的受刑者身上。。", me);
	say("无数受刑者挣扎在被木据、铁链困围的平台上，有少许受刑者晕趴于木桩上，不得动弹。右侧高高的石岩上，数鬼推押着受刑者到沸屎地狱受刑。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
