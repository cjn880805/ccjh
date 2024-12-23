//zhangshugen.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_zhangshugen);

virtual void create()
{

	set_name("张树根","zhang shu gen");

	set("title", "红花会十三当家" );
	set("nickname",  "铁头鲨鱼" );
	set("long", "铁头鲨鱼张树根在会中坐第十三把交椅，出身船家，兵器是铁桨。");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 21);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man2);
	
	set("max_hp", 3300);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 150000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("club", 80);
	set_skill("houquan", 80);
	set_skill("yunlong_shengong", 80);
	set_skill("zui_gun", 100);
	set_skill("yunlong_shenfa", 80);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("club", "zui_gun");
	map_skill("parry", "zui_gun");
	set("env/wimpy", 20);

	carry_object("cloth")->wear();
	carry_object("tiejiang")->wield();
}


NPC_END;