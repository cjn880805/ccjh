//wei_jhlz.h 江湖郎中
//小宝任务

NPC_BEGIN(CNwei_jhlz);

virtual void create()
{
	set_name("江湖郎中", "jianghulangzhong");
	set("title","妙妙手");
	set("long","江湖郎中");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("icon",young_man5); 
	set("env/wimpy", 100);      
	
	set("max_hp", 4500);
	set("hp",  1500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("score", 80000);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed",180);
	set_skill("parry", 180);
	set("no_kill",1);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("wei/renwu1") && !me->query("wei/renwu5"))
	{
		if(me->query_temp("wei/renwu5_8") && !me->query_temp("wei/renwu5_10"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("询问关于忘情散的问题","wang",me);
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "wang") )
			{
				if(!me->query_temp("wei/renwu5_9"))
				{
					say("江湖朗中说道：听说关外天池之水，饮后可让人却烦恼！",me);
					me->set_temp("wei/renwu5_9",1);//得知忘情散配方之天池之水
					SendMenu(me);
					return 1;
				}
				else
				{
					say("江湖朗中说道：大理一带，有一种断肠花，使用后会犹如死而复生，忘却生前的一切！",me);
					me->set_temp("wei/renwu5_10",1);//得知忘情散配方之断肠花
					SendMenu(me);
					return 1;
				}
			}
		}
		else if(me->query_temp("wei/renwu5_1") && !me->query_temp("wei/renwu5_3"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("询问关于沐剑萍的问题","mu",me);
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "mu") )
			{
				say("她正托我帮她找老山叁，你有吗？",me);
				me->set_temp("wei/renwu5_2",1);//找老山参给江湖郎中
				SendMenu(me);
				return 1;
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(environment()->querystr("base_name"),"杭州茅家埠" ))
	{
		if(EQUALSTR(ob->querystr("name"), "老山叁") && EQUALSTR(ob->querystr("id"), "shanshen")
			&& me->query_temp("wei/renwu5_2") && !me->query_temp("wei/renwu5_3"))
		{
			destruct(ob);
			tell_object(me,"\n江湖郎中匆匆忙忙跑掉了。\n");
			me->set_temp("wei/renwu5_3",1);//给江湖郎中老山叁
			move(load_room("temp_lz"));
			return 1;
		}
	}
	return 1;
}

NPC_END;