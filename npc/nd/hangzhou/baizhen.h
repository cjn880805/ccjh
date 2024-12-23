// baizhen.h
//zhangdongni 2001-07-19

NPC_BEGIN(CNhangzhou_baizhen);

virtual void create()
{
	set_name("黑振", "hei zhen");
	set("title", "御前侍卫");
	set("nickname", "金爪铁钩");
	set("gender", "男性");
	set("age", 64);
	set("long", "黑振是嵩阳派高手，三十年前就驰名武林了。");
	set("combat_exp", 450000);
        set("shen_type", -1);
	set("attitude", "heroism");
	set("icon", old_man2);
	
	set("str", 30);
	set("dex", 30);
	set("int", 20);
	set("con", 20);
		
	set_skill("unarmed", 95);
	set_skill("blade", 95);
	set_skill("claw", 95);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	set_skill("sougu", 90);
	set_skill("lingxu_bu", 90);
	map_skill("dodge", "lingxu_bu");
	map_skill("claw", "sougu");
	map_skill("parry", "sougu");
	prepare_skill("claw", "sougu");
}

//    carry_object("tiejia")->wear();	



NPC_END;