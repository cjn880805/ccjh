// xiaolan.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_xiaolan);

virtual void create()
{
	set_name("小兰", "xiao lan");
	set("long", "一个模样乖巧的小丫环，扎两个发环，眼睛大大的，嘴角浅浅一对酒窝。");
	set("gender", "女性");
	set("age", 15);
	set("icon", girl2);
	set("combat_exp", 1000);
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", 1);

	add_money(100);
//	carry_object("red_cloth")->wear();
}

NPC_END;