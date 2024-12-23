// fang.h 方人智
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_fang);

virtual void create()
{
	set("icon",young_man2);
	set_name("方智仁", "fang renzhi");
	set("gender", "男性");
	set("age", 20);
	set("long", "他就是「青城派」年轻一代弟子，以智计为师尊喜爱。");

	set("combat_exp", 50000);
	set("shen_type", -1);

	set_skill("sword", 50);
	set_skill("pixie_sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	map_skill("parry", "pixie_sword");
	map_skill("sword", "pixie_sword");
	create_family("青城派", 6, "弟子");

	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
}

NPC_END;