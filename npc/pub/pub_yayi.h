//yayi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yayi);

virtual void create()
{
	set_name("衙役","yayi");

	set("icon", tipstaff);
	set("gender", "男性");
	set("age", 25);

	set("long", "一个高大威猛的汉子，因为久在官府做事，脸上已经磨炼得毫无表情。");
	set("combat_exp", 7500);
	set("shen_type", 1);
    set_skill("unarmed", 30);
    set_skill("dodge", 30);

	carry_object("yayi_cloth")->wear();
	carry_object("qimeigun")->wield();

};



NPC_END;
