// xiaoyao_mengmianr.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxiaoyao_mengmianr);

virtual void create()
{
	set_name("蒙面人", "mengmian ren");
	set("long", "一个蒙着面部，身穿黑色夜行衣服的神秘人。 ");
	set("gender", "男性");

	set("age", 25);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
 	set("icon", masked_man);
	
	set("max_hp", 1500);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 0l);
	set("combat_exp", 10000);
	
	set_skill("force", 30);
	set_skill("dodge", 25);
	set_skill("parry", 20);
	set_skill("blade", 30);
	set_skill("lingboweibu", 25);
	set_skill("beiming_shengong", 30);
	set_skill("xiaoyao_dao", 30);
	
	map_skill("blade", "xiaoyao_dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	
	create_family("逍遥派", 5, "弟子");
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}
NPC_END;




