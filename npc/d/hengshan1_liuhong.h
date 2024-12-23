//liuhong.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan1_liuhong);

virtual void create()
{

		set_name("刘虹","liu hong");

	set("foolid",143);        set("gender", "女性");
        set("class", "swordsman");
        set("long", "她是刘清风的女儿。");
        set("age", 17);
        set("attitude", "peaceful");
        set("per", 29);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",young_woman11);

        set("mp", 500);
        set("max_mp", 500);
        set("mp_factor", 10);
        set("max_hp",700);
        set("combat_exp", 100000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("force", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("hengshan_sword", 40);
        set_skill("lingxu_bu", 40);

        map_skill("sword", "hengshan_sword");
        map_skill("parry", "hengshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("衡山派", 14, "弟子");

		set_inquiry("任务","我现在的任务是混进梅庄，可是我……");

        carry_object("changjian")->wield();
        carry_object("female1_cloth")->wear();
		set("no_huan",1);
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "ling pai") || DIFFERSTR(ob->querystr("name"), "梅花令牌") )
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "斜月牌", "xieyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}



NPC_END;