//tongzi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tongzi);

virtual void create()
{
	set_name("童子","tongzi");
	
	set("icon", boy2);
	set("long", "这是一个十五六岁的少年，眉清目秀，聪明伶俐，深得岛主喜爱。");
	set("gender", "男性");
	set("age", 15);
	set("shen_type",100);
	set("attitude", "peaceful");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("hp", 200);
	set("max_hp", 600);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 10);
	
	set("combat_exp", 3000);
	set("score", 10);
	
	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("hand", 40);
	set_skill("staff", 40);
	
	create_family("侠客岛", 3, "弟子");
	
};


NPC_END;
