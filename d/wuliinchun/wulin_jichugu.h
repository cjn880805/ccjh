//wulin_jichugu.h 济楚谷
//秦波 2002.5.31

WL_BEGIN(CRWuLin_jichugu);

virtual void create()			
{
	set_name("济楚谷");

	add_door("武陵春簇带峰","武陵春簇带峰", "武陵春济楚谷");

};

virtual int valid_leave(CChar * me, const char * dir)
{
	CContainer * env=me->environment();
	if(env->query("no_move") )
	{
		if(me->querymap("lj"))
		{
			message_vision("$HIR你看着群情激昂的人群，吓的不敢动弹。", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);

}
WL_END;
