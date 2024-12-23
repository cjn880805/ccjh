// yuyan.h 余人彦
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_yuyan);

virtual void create()
{
	set("icon",young_man1);
	set_name("鱼彦仁", "yu renyan");
	set("gender", "男性");
	set("age", 20);
	set("long", "他就是「青城派」掌门人鱼海沧的独生爱子。可是他实在很不争气。");

	set("combat_exp", 40000);
	set("shen_type", -1);

	set_skill("sword", 40);
	set_skill("pixie_sword", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	map_skill("parry", "pixie_sword");
	map_skill("sword", "pixie_sword");
	create_family("青城派", 6, "弟子");

	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
}

NPC_END;