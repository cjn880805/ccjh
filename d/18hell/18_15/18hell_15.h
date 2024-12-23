//18hell_15.h
//十八地狱第十一层剥皮地狱BOSS房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_15);

virtual void create()			//Call it when Room Create
{
	set_name("剥皮狱底");
	
	add_npc("tudou");
	add_npc("diyu_shizhe15");

};

virtual int do_look(CChar * me)
{
	say("正中一巨大的黑无常立于土坡显赫之地，右手执“正在捉你”的招魂牌，左手正指向正前方，给亏心者以心灵的震撼。黑无常左侧，一兽头拿鬼双手高扬颈绳，疾步上前欲将恶人行刑正法，使其难逃法网。", me);
	say("无常右侧一巨鬼双手紧握铁链，依于身边只待黑无常一声令下，欲将越狱者擒活治罪。土坡上，一巨大木架上捆绑着受刑者四肢，二鬼正在紧张地将罪人剥皮，旁边等待剥皮者若干，被鬼卒押着排队等候行刑。", me);
	say("左前，一淫妇被捆绑在木桩上，正被二鬼卒挖心。场景右侧，两根巨大的木桩和一巨大的木板上捆绑着罪人（其中有一金发、碧眼、高鼻的白人罪鬼），有的被挖心，有的被割舌，有的被剥皮。 ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
