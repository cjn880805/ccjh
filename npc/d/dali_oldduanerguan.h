//oldduanerguan.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNDaLi_oldduanerguan);

virtual void create()
{
	set_name("老段恶贯","duan er guan");

	set("gender", "男性");
	set("nickname", "恶贯满盈");
	set("age", 54);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "一看就知道他是武功高强的坏人。");
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 50);
 	set("icon",old_man1);

	set_skill("finger", 150);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("staff", 150);
	set_skill("parry", 150);
	set_skill("sun_finger", 150);
	set_skill("kurong_changong", 150);
	set_skill("tiannan_step", 150);
	set_skill("lingshe_zhangfa", 150);
	map_skill("dodge", "tianna_step");
	map_skill("force", "kurong_changong");
	map_skill("parry", "sun_finger");
	map_skill("staff", "lingshe_zhangfa");
	map_skill("finger", "sun_finger");
	prepare_skill("finger", "sun_finger");

	carry_object("bluecloth")->wear();
};


NPC_END;
