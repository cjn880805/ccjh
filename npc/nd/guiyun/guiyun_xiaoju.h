// xiaoju.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_xiaoju);

virtual void create()
{
	set_name("小菊", "xiao ju");
	set("long", "一个模样乖巧的小丫环，瓜子脸，肤色白晰。细看时，嘴角有一颗小痣。");
	set("gender", "女性");
	set("age", 15);
	set("icon", girl1);
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