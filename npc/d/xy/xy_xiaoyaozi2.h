//xy_xiaoyaozi2.h 逍遥子（逍遥谷小院剧情NPC）
//秦波 2002、12、12

NPC_BEGIN(CNxy_xiaoyaozi2);

virtual void create()
{    
    set_name("逍遥子", "xiaoyao zi");
    set("long","只见他红唇墨发，脸如冠玉，举手投足之间神采飞扬，风度闲雅，直将这逍遥二字体现得淋漓尽致。");	
    set("title","逍遥派");
	set("gender", "男性"); 
    set("age", 23);

    set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 32);
    set("per", 40);

    set("icon",13);
	create_family("逍遥派", 1, "掌门");

    set("max_hp", 28000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 80); 
    set("combat_exp", 90000000); 
	
	set("no_kill",1);

    set_skill("force", 400);
    set_skill("beiming_shengong", 400);
    set_skill("dodge", 400);
    set_skill("lingboweibu", 400);
	set_skill("xiaoyao_bu", 400);
    set_skill("unarmed", 400);
    set_skill("liuyang_zhang", 400);
    set_skill("parry", 400);
    set_skill("blade", 400);
    set_skill("xiaoyao_dao", 400);
    set_skill("zhemei_shou", 400);
    set_skill("hand", 400);
	set_skill("lingxiao_kuaijian", 400);
	set_skill("xiaoyao_jian", 400);
	set_skill("sword", 400);
	set_skill("literate", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "lingxiao_kuaijian");
    map_skill("blade", "xiaoyao_dao");
	map_skill("sword", "xiaoyao_jian");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");

    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("changjian")->wield();

	call_out(do_die, 900);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR((me->environment())->querystr("base_name"), "逍遥谷小院" ))
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
				say("逍遥子若有所思的“唔”了一声，却并未回答你的话。",me);
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

NPC_END;




