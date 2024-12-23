// shutong.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_shutong);

virtual void create()
{
	set_name("书童", "shu tong");
	set("gender", "男性");
	set("age", 35);
	set("icon", boy1);
	set("long", "他是庄主的随身书童，平素看管藏书。");
	set("combat_exp", 10000);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
	set("shen_type", -1);

	add_money(300);
	carry_object("cloth")->wear();
}

NPC_END;