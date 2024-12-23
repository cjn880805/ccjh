//pub_mengzeshizhe.h
//梦泽山人

NPC_BEGIN(CNpub_mengzeshizhe);

void create()
{
	set_name("梦泽山人", "shan ren");
    set("gender", "男性");
	set("icon", young_monk);
    set("age", 60);
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);

	set("hp",990000);
	set("max_hp",990000);
	set("mp",990000);
	set("max_mp",990000);
	set("mp_factor", 3000);

	set("combat_exp", 99900000);
	set("score", 400000);
	 
	set_skill("force", 500);             
	set_skill("taixuan_gong", 500);    
	set_skill("unarmed", 500);           
	set_skill("dodge", 500);      	     
	set_skill("parry", 500);             
	
	map_skill("force", "taixuan_gong");
	map_skill("unarmed", "taixuan_gong");
	map_skill("dodge", "taixuan_gong");
	map_skill("parry", "taixuan_gong");

	set_inquiry("寻宝", ask_for_back);

}

static char * ask_for_back(CNpc * npc, CChar * who)
{
	message_vision("$n向前挪了挪，$N顿时眼前看到一团耀眼的白光，不由的伸手遮住了双眼。", who, npc);
	who->delete_temp("mf/pass");
	who->move(load_room("扬州客店"));
	return 0;
}

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	if(! is_fighting() && userp(me))
	{
		if(me->query_temp("mf/pass"))
		{
			if(me->query_temp("mf/pass")==2)
			{
				CContainer * env = load_room("pk");
				if(!env->query("free_mf"))
				{
					message_vision(snprintf(msg, 255, "$HIR梦泽山人冷竣的眼光扫向了%s,哼道：“这里是梦泽宝地，你已经到了该离开的时候了。”\n", me->name()), this);
					me->move(load_room("佛山烧饼油条铺"));
				}
			}
			else
			{
				DTItemList * list = me->Get_ItemList();
				POSITION p = list->GetHeadPosition();
				CContainer * obj;
				while(p)
				{
					obj = list->GetNext(p);
					if(userp(obj))
					{
						message_vision(snprintf(msg, 255, "$HIR梦泽山人冷竣的眼光扫向了%s,哼道：“这里是梦泽宝地，与我无缘者不可入内。”\n", me->name()), this);
						obj->move(load_room("扬州客店"));
						me->move(load_room("佛山烧饼油条铺"));
					}
				}
				if(!random(10))
				{
					if(me->query("hp")<me->query("max_hp"))me->set("hp",me->query("max_hp"));
					me->set("eff_hp",me->query("max_hp"));
					if(me->query("mp")<me->query("max_mp"))me->set("mp",me->query("max_mp"));
				}
			}
		}	
		else 
		{
			message_vision(snprintf(msg, 255, "$HIR梦泽山人冷竣的眼光扫向了%s,哼道：“这里是梦泽宝地，与我无缘者不可入内。”\n", me->name()), this);
			me->move(load_room("扬州客店"));
		}
	}
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N斜眼看了看，皱了皱眉，丢了一句“懒的理你”就转过身去。", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;




