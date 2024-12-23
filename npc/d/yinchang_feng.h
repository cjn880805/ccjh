// yinchang_feng.c 风清扬

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_feng);

virtual void create()
{
	set_name("风清越", "feng qingyang");
	set("title", "华山第十二代剑宗长老");
	set("long", "这便是当年名震江湖的华山名宿风清越。他身著青袍，神气抑郁脸如金纸。身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤神色，显然对当年的剑宗气宗之争一直难以忘怀。");
	set("gender", "男性");
	set("age", 68);
        set("icon",old_man1);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("hp", 4800);
	set("max_hp", 15000);
	set("mp", 4400);
	set("max_mp", 4400);
	set("mp_factor", 200);
	
	set("combat_exp", 1750000);
	set("score", 200000);
	
	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 220);
	set_skill("strike", 200);
	set_skill("zixia_shengong", 200);
	set_skill("poyu_quan", 170);
	set_skill("fanliangyi_dao", 180);
	set_skill("huashan_sword", 200);
	set_skill("hunyuan_zhang", 170);
	set_skill("lonely_sword", 200);
	set_skill("feiyan_huixiang",200);
	set_skill("literate", 120);
	
	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "feiyan_huixiang");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	map_skill("blade", "fanliangyi_dao");
	map_skill("strike", "hunyuan_zhang");
	
	create_family("华山派", 12, "弟子");
	
	set("chat_chance_combat", 60);
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}
virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword pozhang", 1);
		break;
	case 1:
		perform_action("sword pojian", 1);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say(" 非也，非也，这招应该剑意曲而剑势直。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="zhang-sanfeng")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/
NPC_END;