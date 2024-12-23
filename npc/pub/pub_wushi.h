//wushi.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_wushi);

virtual void create()
{
	set_name("巫士","wushi");

	set("icon", taoist);
	set("gender", "男性" );

	set("age", 45);
	set("long", "诡异的苗人巫士，好象想杀了你祭神。");
	set("shen_type",-1);
	set("combat_exp", 6000);
	set("mj",1);

	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);

	set("chat_chance", 30);

	set_skill("unarmed", 35);
	set_skill("blade", 20);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	carry_object("cloth")->wear();
    carry_object("mutang")->wield();
	add_money(10);

};

virtual char * chat_msg(CChar * me)
{
	return "巫士一声大喊: @@###$$!!! @@@! &*%%%%@!!!";
}

NPC_END;




