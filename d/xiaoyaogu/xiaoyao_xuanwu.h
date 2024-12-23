//xiaoyao_xuanwu.h 玄武塔
//秦波 2002、12、17

XiaoYao_BEGIN(CRXiaoYao_xuanwu);

virtual void create()
{
	set_name( "玄武塔");

	add_door("逍遥谷空地", "逍遥谷空地", "逍遥谷玄武塔");	

	set("long","这儿看上去破败苍凉，到处结满蛛尘，似乎已经很久没有人来过了。");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("xy/renwu4_3") )
	{
		say("你用力推开破旧的塔门，一条尘封的通道逐渐显现出来。",me);
		say("通道深处漆黑一片，里面还不时传出一些奇异的声音。",me);
		if(me->query_temp("xy/renwu4_1") && !me->query("xy/renwu4_53"))
		{
			if(me->query_temp("xy/renwu4_1")==2)
				say("尽管你心中非常害怕，不过好在有师叔在一旁，心里便踏实了许多，于是你鼓起勇气，走进了塔内。",me);
			else
				say("尽管你心中非常害怕，不过好在有师伯在一旁，心里便踏实了许多，于是你鼓起勇气，走进了塔内。",me);
			AddMenuItem("进入玄武塔", "$0jinru $1", me);
		}
		else
		{
			say("只吓得你心惊胆寒，不敢再近前一步！看来还是得请师伯或者师叔出马，来为你壮壮胆！",me);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("xy/renwu4_1") ||!me->query("xy/renwu4_3")  )
		return 0;
	if(!strcmp(comm, "jinru"))
		return do_jinru(me, arg);
	return 0;
}


int do_jinru(CChar *me, char * arg)
{
	me->move(load_room("逍遥谷玄武塔塔底11"));
	//这里要将带的NPC也抓进来
	if(me->query_temp("xy/renwu4_1"))
	{
		CContainer * XyNpc;
		CChar * Xy_Npc ;
		if(me->query_temp("xy/renwu4_1")==1)
		{
			XyNpc=present("tong lao");
			Xy_Npc= load_npc("xy_tielao");
		}
		else
		{
			XyNpc=present("li qiou heng");
			Xy_Npc= load_npc("xy_liqiouheng");
		}
		if(XyNpc)
		{
			destruct(XyNpc);
		}
		Xy_Npc->move(load_room("逍遥谷玄武塔塔底11"));
		Xy_Npc->set_leader(me);
		Xy_Npc->set("owner",atoi(me->id(1)));
	}
	return 1;
}

XiaoYao_END;
