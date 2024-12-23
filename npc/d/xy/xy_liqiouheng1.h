//xy_liqiouheng.h 李秋痕（逍遥谷小院剧情NPC）
//秦波 2002、12、12

NPC_BEGIN(CNxy_liqiouheng1);

virtual void create()
{    
    set_name("李秋痕", "li qiou heng");
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

    set_skill("force", 300);
    set_skill("xiaowuxiang", 300);
    set_skill("dodge", 300);
    set_skill("xiaoyao_bu", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
	set_skill("literate", 280);
    
    map_skill("force", "xiaowuxiang");
    map_skill("dodge", "xiaoyao_bu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("gangdao")->wield();

	call_out(do_die, 900);	
}

int do_talk(CChar * me, char * ask = NULL)
{
	if((EQUALSTR((me->environment())->querystr("base_name"), "逍遥谷小院" )))
	{
		if(me->query("xy/renwu7_2") && me->query_temp("xy/renwu7_3") && me->query("xy/renwu7_3")<1)
		{
			if(! strlen(ask))
			{
				AddMenuItem("关于李沧海","li",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "li") )
			{
				say("李秋痕道：“小妹已经长大，又学了些武功，总不成天天守在姐姐，姐夫身边，所以我便让她到江湖中历练去了。”",me);
				say("李秋痕道：“怎么，师侄这么热心的问及家妹，莫非也是看上了她的美貌？”",me);
				say("你慌忙应道：“怎么会，只是因为没有见到小师叔，随口问问罢了！”",me);
				if(!me->query("xy/renwu7_31"))
				{
					me->set("xy/renwu7_31",1);//询问李沧海去向事件
					me->add("xy/完成度",1);
				}
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

virtual void die()
{
	if(querystr("owner1")[0])
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
			if(EQUALSTR(querystr("owner1"),target->id(1)))
			{
				message_vision("\n$HIC李秋痕恨声说道：“哼，好个乖巧的师侄，居然这样对待师叔，我们等着瞧！”\n", this);
				target->del("xy/renwu7_pause");
				tell_object(target,"$HIR你历经艰险，保护师伯天山铁姥闭关修炼成功，江湖经验提高了5000点。");
				target->add("combat_exp",5000);
				destruct(this);
				break;
			}
		}
	}
	else
		CNpc::die();
}

NPC_END;




