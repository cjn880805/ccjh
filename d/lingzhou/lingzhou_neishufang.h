//neishufang.h

//Sample for room: 内书房


ROOM_BEGIN(CRLingZhou_neishufang);

virtual void create()		
{
	set_name( "内书房");

	add_door("灵州皇宫幽兰涧东", "灵州皇宫幽兰涧东", "灵州皇宫内书房");
	add_door("灵州皇宫青凤阁", "灵州皇宫青凤阁", "灵州皇宫内书房");

	set("no_fight",1);
	set("no_cast",1);
	add_npc("lj_gongnv");

};

int valid_leave(CChar * me, const char * dir)
{
	CContainer * env=me->environment();
	if(EQUALSTR(dir,"灵州皇宫青凤阁"))
	{
		if(!me->query("lj/renwu11"))
		{
			message_vision("$HIR皇宫卫士伸手拦住了你，“大胆狂徒，皇宫也是你可以乱闯的地方？”", me);
			return 0;
		}
		else if(EQUALSTR(me->querystr("gender"), "女性") )
		{
			if(DIFFERSTR(me->querystr_temp("apply/name"),"竹虚"))
			{
				message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你是女人，何必来参加比武招亲呢？！”", me);
				return 0;
			}
			else if(!me->query_temp("lj/renwu111"))
			{
				message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你的易容术未免有点浅薄了……”", me);
				return 0;
			}
			else if(!env->query("start"))
			{
				message_vision("$HIR宫女拦住了你，“这位公子,请在此地稍做休息。。”", me);
				return 0;
			}
			else
			{
				return CRoom::valid_leave(me, dir);
			}
		}
		else
		{
			message_vision("$HIR我昏！你是男的，怎么可能接到这个任务呢？出老千呀！", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
