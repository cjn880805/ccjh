// pub_mengmian.c 蒙面大汉
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_mengmian);

virtual void create()
{
	set_name("蒙面大汉", "mengmian dahan" );

	set("icon", masked_man);
	set("long","他是一个蒙面大汉。");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "aggressive");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	set("max_hp", 1200+random(600));
	set("mp", 500);
	set("max_mp", 300);
	set("combat_exp", 2000+random(2000));
	set("score", 1000);
	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("yanxing_dao", 20);
	set_skill("taoism", 20);
	map_skill("parry", "yanxing_dao");
	map_skill("blade", "yanxing_dao");
	carry_object("gangdao")->wield();
}
/*
virtual char * greeting(CChar * me)
{
	CChar *guard;
	int i;
//	me=this_object();
	guard = all_inventory(me->environment());
	for(i=0; i<sizeof(guard); i++)
	{
		if( !living(guard[i]) || guard[i]==me ) continue;
		me->kill_ob(guard[i]);
	}
	command("kill zhike");
}
*/
NPC_END;