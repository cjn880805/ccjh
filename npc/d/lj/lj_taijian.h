//taijian.h
//秦波 2002-08-01

NPC_BEGIN(CNlj_taijian);

virtual void create()
{
	set_name("太监", "tai jian");
	set("gender", "无性");
	set("icon", young_man4);
	
	set("title", "西夏皇宫");
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 45);
	set("dex", 40);
	set("per",32);
	
	set("max_hp", 46000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 200);
	set("combat_exp", 6000000);
	set("score", 300000);

	set("no_kill",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * r = load_room("灵州皇宫大门");
	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu113"))
	{
		me->disable_player("观察中");
		me->set_temp("lj/renwu113",1);
		call_out(do_gangsi, 6);	
	}
}


static void do_gangsi(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env=(CChar *)(ob->environment());
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target))
		{
			target->enable_player();
			continue;
		}
		if(DIFFERSTR(target->querystr("name"), "太监") )
		{
			message_vision("\n$N纵身一跃，勉强跳上钢丝，身形晃了几晃。", target);
			if(EQUALSTR(target->querystr("name"), "瓦耳拉齐")|| EQUALSTR(target->querystr("name"), "鹿鼎公"))
			{
				message_vision("突然$N足底一滑自钢丝上掉下，在钢丝下的泥地摔了个狗吃屎。旁边众太监纷纷窃笑不已。", target);
				message_vision("$HIR$N失去了比武招亲的资格，满脸通红的退到了皇宫大厅。", target);
				//target->move(load_room("灵州皇宫大厅"));
				destruct(target);
			}
			else
			{
				message_vision("$N凝神贯气，只见身形闪了几闪，就跃到了对岸。", target);
				target->move(load_room("灵州皇宫内书房"));
			}
		}
	}
}
	
NPC_END;

