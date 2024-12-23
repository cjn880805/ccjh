//xy_liqiouheng.h 李秋痕（逍遥谷小院剧情NPC）
//秦波 2002、12、12

NPC_BEGIN(CNxy_liqiouheng2);

virtual void create()
{    
    set_name("蒙面少女", "meng mian nv");
    set("long","她身着一袭淡黄绸衫，肤如凝脂，眉目如画，当真仪态万方，言笑之间，一股娇媚之态自然而生。");	
    set("gender", "女性"); 
    set("age", 20);

    set("str", 20); 
    set("int", 20);
    set("con", 28);
    set("dex", 30);
    set("per", 40);

    set("icon",6);
	set("title","逍遥派");
	create_family("逍遥派", 1, "弟子");

    set("max_hp", 18000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 120); 
    set("combat_exp", 5000000); 

	set("chat_chance", 30);
	
	set("no_kill",1);

    set_skill("force", 200);
    set_skill("xiaowuxiang", 200);
    set_skill("dodge", 200);
    set_skill("xiaoyao_bu", 200);
    set_skill("unarmed", 200);
    set_skill("liuyang_zhang", 200);
    set_skill("parry", 200);
    set_skill("blade", 200);
    set_skill("xiaoyao_dao", 200);
    set_skill("zhemei_shou", 200);
    set_skill("hand", 200);
	set_skill("literate", 280);
	set_skill("music",200);
	set_skill("xiaoaojianghu",200);
    
    map_skill("force", "xiaowuxiang");
    map_skill("dodge", "xiaoyao_bu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
	map_skill("music", "xiaoaojianghu");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("xiao")->wield();

	call_out(do_die, 3600);	
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(querystr("owner"))
	{
		if(!strcmp(comm, "kill")  || !strcmp(comm, "fight") || !strcmp(comm, "cast"))
		{
			if(DIFFERSTR(querystr("owner"),me->querystr("id")))
			{
				message_vision("\n$N正欲对$n发动攻击，萧声突然一转，犹如晴天霹雳，直震得你心慌意乱，无法动弹。\n", me, this);
				me->add("hp",-100);
				me->UpdateMe();
				me->start_busy(2);
				return 1;
			}
			if(!me->query_skill("music",1))
			{
				message_vision("\n$N正欲对$n发动攻击，萧声突然一转，犹如晴天霹雳，直震得你心慌意乱，无法动弹。\n", me, this);
				me->add("hp",-100);
				me->UpdateMe();
				me->start_busy(2);
				return 1;
			}
			CContainer * weapon;
			if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "music"))
			{
				message_vision("\n$N正欲对$n发动攻击，萧声突然一转，犹如晴天霹雳，直震得你心慌意乱，无法动弹。\n", me, this);
				me->add("hp",-100);
				me->UpdateMe();
				me->start_busy(2);
				return 1;
			}
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

virtual void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		if(EQUALSTR(querystr("owner"),target->id(1)))
		{
			message_vision("\n$HIC蒙面少女恨声说道：“哼，我还会再来的！”\n", this);
			target->del("xy/renwu7_pause");
			tell_object(target,"$HIR你历经艰险，保护师伯天山铁姥闭关修炼成功，江湖经验提高了5000点。");
			target->add("combat_exp",5000);
			destruct(this);
			break;
		}
	}
}
NPC_END;




