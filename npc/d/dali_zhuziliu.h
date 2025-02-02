//zhuziliu.h
//code by zwb
//12-16

NPC_BEGIN(CNDaLi_zhuziliu);

virtual void create()
{
	set_name("朱书生","zhu zi liu");

	set("gender", "男性");
	set("age", 55);
	set("long", "一等大师的四大弟子之一，是个大近视眼，现在襄阳协助靖哥哥、蓉儿守城。");
 	set("attitude", "peaceful");
 	set("icon",old_man1);
	
	set("per", 17);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 1500);
	set("max_mp", 1500);
	
	set("combat_exp", 100000);
	set("score", 20000);
	 
	set_skill("force", 50);
	set_skill("kurong_changong", 50);
	set_skill("finger", 50);
	set_skill("sun_finger", 50);
	set_skill("cuff", 50);
	set_skill("jinyu_quan", 50);
	set_skill("dodge", 50);
	set_skill("tiannan_step", 50);
	set_skill("parry", 50);
	
	map_skill("force", "kurong_changong");
	map_skill("finger", "sun_finger");
	map_skill("cuff", "jinyu_quan");
	map_skill("dodge", "tiannan_step");
	map_skill("parry", "sun_finger");
	prepare_skill("finger", "sun_finger");
	prepare_skill("cuff", "jinyu_quan");

	carry_object("cloth")->wear();
};




NPC_END;
