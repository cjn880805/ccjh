//dingyueshitai.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan_dingyueshitai);

virtual void create()
{

		set_name("定岳师太","dingyue shitai");
	set("foolid",147);
        set("gender", "女性");
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",old_woman);

        set("mp", 2400);
        set("max_mp", 2400);
        set("mp_factor", 30);
        set("max_hp",2000);
        set("combat_exp", 1000000);
        set("shen_type", 1);

        set_skill("unarmed", 130);
        set_skill("sword", 130);
        set_skill("force", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("hengshan_jian", 130);
        set_skill("lingxu_bu", 130);

        map_skill("sword", "hengshan_jian");
        map_skill("parry", "hengshan_jian");
        map_skill("dodge", "lingxu_bu");

        create_family("恒山派", 13, "弟子");
		set_inquiry("自杀","很遗憾。我的匕首卖光了。");
        carry_object("changjian")->wield();
        carry_object("xuan_cloth")->wear();
		set("no_huan",1);
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "dagger") || DIFFERSTR(ob->querystr("name"), "普通匕首" ) )
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "浅月牌", "qianyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}



NPC_END;