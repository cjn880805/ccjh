// likexiu.h
//zhangdn 2001-07-19

NPC_BEGIN(CNhangzhou_likexiu);

virtual void create()
{
	set_name("李以秀", "li yixiu");
	set("title", "杭州提督");	
	set("gender", "男性");
	set("age", 54);
	set("long","李以秀一身军功而成封疆大吏，一身武功自然不容轻视。");
	set("combat_exp", 150000);
        set("shen_type", -1);
	set("attitude", "heroism");
	set("icon",old_man1);

	set_skill("unarmed", 75);
	set_skill("blade", 75);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	
//	carry_object("gangdao")->wield();
        carry_object("tiejia")->wear();
        
	
	
}
NPC_END;
