//caoping.h

//Sample for room:  神龙教草坪 
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_caoping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教草坪");
	
	add_npc("shenlong_old");
	add_npc("shenlong_girl");          //add by zdn 2001-07-20

	add_door("神龙教空地", "神龙教空地", "神龙教草坪");
};

virtual int do_look(CChar * me)
{
	if(me->query_temp("wei/renwu4_5")  )
	{
		say("乱石缝中，露出一个黑呼呼的洞口。",me);
		CContainer * baishu=me->present("bai shu");
		if(baishu)
		{
			AddMenuItem("丢下小白鼠","$0baishu $1",me);
		}
		SendMenu(me);
	}
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu4_5") )
		return 0;
	if (me->query_temp("wei/renwu4_6") )
		return 0;
	if(!strcmp(comm, "baishu"))
	{
		CContainer * baishu=me->present("bai shu");
		if(baishu)
		{
			baishu->move(me->environment());
			baishu->set("owner",me->id(1));
			me->set_temp("wei/renwu4_6",1);//丢下了白鼠
			((CChar *)baishu)->call_out(do_yingsheng, 30);
		}
		return 1;
	}
	return 0;
}

static void do_yingsheng(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			tell_object(me, "$HIR\n突见一条洪荒巨蟒从洞中窜了出来，张着血盆大口，蛇芯吞吐之间，腥臭扑鼻。");
			tell_object(me, "$HIR小白鼠闻到它的呼吸，浑身抽搐而死，这恐怖的场面令你几尽昏到！");
			tell_object(me, "$HIR你惊慌之间，不知道如何是好！！！\n");
			CNpc * she = load_npc("qishe");
			((CChar *)she)->set("owner",me->id(1));
			((CChar *)she)->move(env);
			((CChar *)she)->call_out(do_pao, 10);
			tell_object(me, "\n$HIR蕲蛇上下仔细的打量着你！");

			CContainer * xionghuang=me->present("xionghuang");
			if(xionghuang)
				tell_object(me, "$HIR蕲蛇试图向你扑来，可是你身上好象有令它害怕的东西！");
			else
				((CChar *)she)->kill_ob((CChar *)me);
		}
		destruct(npc);
	}
}

static void do_pao(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0] && !npc->is_fighting())
	{
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
			tell_object(me, "$HIR\n蕲蛇悻悻的爬回洞中，你错失了锄掉祸害、取得蕲蛇胆的良机。\n");
		destruct(npc);
	}
}
ROOM_END;
//last, register the room into ../server/RoomSetup.cpp