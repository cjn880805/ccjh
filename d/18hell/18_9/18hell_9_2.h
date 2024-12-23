//18hell_9.h
//十八地狱第五层黑身地狱第2房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_9_2);

virtual void create()			//Call it when Room Create
{
	set_name("黑身地狱");
	
	add_npc("diyu_shizhe9");

};

virtual int do_look(CChar * me)
{
	say("牢房边一厉鬼执鞭猛抽戴枷锁的受刑者，将其驱赶至黑身泥潭去受刑。近处一深不可测的巨大黑泥潭内盛满黑色污水，无数受刑者在潭内挣扎。右侧潭边二鬼正架一受刑者欲推向黑潭之中。 ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
