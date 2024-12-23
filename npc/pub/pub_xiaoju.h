//xiaoju.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaoju);

virtual void create()
{
	set_name("小菊","xiaoju");

	set("icon", young_woman2);
	set("long", "一个模样乖巧的小丫环，瓜子脸，肤色白晰。细看时，嘴角有一颗小痣。");
	set("gender", "女性");
	set("age", 15);
	set("combat_exp", 1000);
    set_skill("dodge", 10);
    set_skill("unarmed", 10);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	set("shen_type", 1);

	add_money(1);
	carry_object("red_cloth")->wear();


};

NPC_END;
