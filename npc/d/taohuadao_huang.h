// taohuadao_huang.c
//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

NPC_BEGIN(CNtaohuadao_huang);

virtual void create()
{
    set_name("蓉儿",  "huang rong" );
    set("gender", "女性");
    set("age", 36);
        set("icon",young_woman10);

    set("long", "她是北侠靖哥哥的夫人，黄老怪的爱女，前任丐帮帮主。");
	
    set("attitude", "peaceful");
	
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);
	
    set("hp", 2000);
    set("max_hp", 2000);
    set("mp", 2000);
    set("max_mp", 2000);
    set("mp_factor", 0l);
	
    set("combat_exp", 500000);
    
	
    set_skill("force", 120);
    set_skill("bibo_shengong", 120);
    set_skill("unarmed", 120);
    set_skill("luoying_shenzhang", 120);
    set_skill("dodge", 180);
    set_skill("anying_fuxiang", 120);
    set_skill("parry", 120);
    set_skill("sword", 120);
    set_skill("luoying_shenjian", 120);
    set_skill("qimen_wuxing", 120);
	
    map_skill("force"  , "bibo_shengong");
    map_skill("unarmed", "luoying_shenzhang");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("sword"  , "luoying_shenjian") ;
	
	set_inquiry("少林","少林寺老和我爹爹过不去。我得想办法弄点他们的东西才行……。");

    create_family("桃花岛", 2, "弟子");
	
    carry_object("ruanwei")->wear();
    carry_object("shudai")->wear();
	set("no_huan",1);
	
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "damo ling") || DIFFERSTR(ob->querystr("name"), "达摩令" ))
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "清月牌", "qingyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}


NPC_END;