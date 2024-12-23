//18hell_21.h
//十八地狱第十七层烊铜地狱第4房间

ROOM_BEGIN(CR18hell_21_4);

virtual void create()			//Call it when Room Create
{
	set_name("烊铜地狱");
	
	add_npc("diyu_shizhe21");

};

virtual int do_look(CChar * me)
{
	say("地狱中布满岩石，一排排巨大的空心铜柱立于灶上，烈火熊熊，将一根根铜柱烧得通红。正前面，巨大的铜柱上捆着四个受刑者，正受炮烙之苦；远处林立着大小铜柱上面或捆着一个罪人，或两个罪人。", me);
	say("左侧岩石上倒挂有烧蜷的受刑者，正面大铜柱旁，一鬼卒用铁叉叉住受刑的罪人使其不能动弹。另一大鬼手持砍刀，凶神恶煞地向罪人怒吼震威，左边右下角加柴鬼、扇火鬼忙个不停。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
