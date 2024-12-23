//pub_jueqingdizi.h

NPC_BEGIN(CNpub_jueqingdizi);

void create()
{
	set_name("绝情谷弟子", "JueQingGu dizi");
    set("gender", "女性");
	set("icon", girl1);

    set("age", 20);
    
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill",1);//不被列入万劫谷的任务中

}

void init(CChar * me)
{
	CNpc::init(me);

	if(!me->query_temp("gumu/jq_y"))	
	{
		CContainer * env = me->environment();
		if(!me->query_temp("gumu/jq_count"))
			me->set_temp("gumu/jq_count",random(22)+10);
		me->set_temp("gumu/jq_y",1);
		me->add_temp("gumu/jq_count",-1);
		if(me->query_temp("gumu/jq_count")<2)
		{
			me->set_temp("gumu/jq_count",1);
			me->move(load_room("绝情谷大厅"));
		}
		else
		{
			CChar * robber;
			CFightRoom * obj;

			obj = (CFightRoom *)load_item("fight_room");		
			obj->set("room_locked", FIGHT_LOCKED);
			obj->set_name( "绝情谷战斗", "fight_room_jueqing");		
			obj->move(env);
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

			static char tufei[18][20]={"pub_gaoming","pub_duguo","pub_guoda","pub_liuquan","pub_maxiaotian","pub_wanghu","pub_wuan","pub_zhuzhao","pub_sangyuan","pub_wangmu","pub_henmantian","pub_guochou","pub_zhaoba","pub_feiying","pub_huanhai","pub_xuecai","pub_youzhu","pub_zangma"};
			int j=random(2);
			for(int i=0;i<j+1;i++)
			{
				robber = load_npc(tufei[random(18)]);
				robber->set_name("绝情谷弟子", "jue qing dizi");
				robber->set("title", "守山使者");
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);				
			}
			obj->Begin_Fight(0);
		}
	}
}


int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n对$N皱了皱眉头：不要惹我，今天心情一直不好。", me, this);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;




