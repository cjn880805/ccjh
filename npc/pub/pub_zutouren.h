//zutouren.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zutouren);

virtual void create()
{
	set_name("族头人","zu tou ren");

	set("icon", old_man1);
	set("age", 42);
	set("gender", "男性");
	set("long", "这位是哈尼的族头人，哈尼是大理国的第三大族，大多聚在大都附近。此人貌甚精明，身穿对襟衣，亦是白布包头。他坐在大土司的右下首，对来人细细打量着。");
	set("attitude", "peaceful");

	set("str", 30);
	set("per", 20);
	set("dex", 36);
	set("combat_exp", 100000);
	set("shen_type", 1);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 70);
	set_temp("apply/armor", 70);

	carry_object("guazi")->wear();

};


NPC_END;
