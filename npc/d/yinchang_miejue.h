// yinchang_miejue.c 灭绝师太

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_miejue);

virtual void create()
{
	set_name("灭尽师太", "miejue shitai");
	set("long","她是峨嵋派的第三代弟子，现任峨嵋派掌门人。");
	set("gender", "女性");
	set("age", 62);
        set("icon",old_woman);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 100000);
	set("class", "bonze");
	set("chat_chance_combat", 60);
	
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 1500);
	set("max_mp_factor", 1500);
	
	set("combat_exp", 2000000);
	set("score", 1000);
	set_skill("persuading", 150);
	set_skill("throwing", 180);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("finger", 180);
	set_skill("parry", 180);
	set_skill("strike", 180);
	set_skill("sword", 180);
	set_skill("blade", 180);
	set_skill("literate", 100);
	set_skill("mahayana", 180);
	set_skill("buddhism", 180);
	set_skill("jinding_zhang", 180);
	set_skill("tiangang_zhi", 180);
	set_skill("huifeng_jian", 180);
	set_skill("yanxing_dao", 180);
	set_skill("zhutian_bu", 180);
	set_skill("linji_zhuang", 180);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("blade","yanxing_dao");
	map_skill("parry","huifeng_jian");
	create_family("峨嵋派", 3, "掌门人");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

/*	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
	}) );
*/
virtual char * chat_msg_combat()
{
	perform_action("sword mie", 1);
	return 0;
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say(" 纵死侠骨香，除魔卫道定要此精神。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="zhou-zhiruo")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;