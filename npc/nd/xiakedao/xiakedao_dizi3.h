// pub_dizi3.h 弟子
//code by Fisho
//date : 2000-12-13

//inherit F_MASTER;

NPC_BEGIN(CNxiakedao_dizi3);

virtual void create()
{
	set_name("青衣弟子","di zi3");
	set("long", "这是三十多岁的壮汉，膀大腰圆，是岛主从中原招募来的。");
	
	set("icon", triggerman1);
	set("gender", "男性");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 30);
	set("combat_exp", 30000);
	set("score", 10);

	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("staff", 50);

	create_family("侠客岛", 2, "弟子");
	
	carry_object("cloth")->wear();
}

virtual char * greeting(CChar * ob)
{
	return "青衣弟子说道：我也不知道侠客岛有什么作用，据说这里有很厉害的武功。";
}

NPC_END;