//xiaolama.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaolama);

virtual void create()
{
	set_name("С����","xiao lama");

	set("icon", young_monk);
	set("long","����ѩɽ�µ�С����,���Ϲ��������Ц��");


	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 300);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 500);
	set("score", 100);

	set_skill("force", 15);
	set_skill("dodge", 15);
	set_skill("unarmed", 15);
	set_skill("parry", 15);


	carry_object("cloth")->wear();


};

NPC_END;
