//gouzazhong.h
//wq 2002 -07-19

NPC_BEGIN(CNlj_gouzhazhong);

virtual void create()
{
	set_name("狗杂种","gou zazhong");
	
	set("gender", "男性");
	set("age", 20);
	set("long", "他大约二十多岁，穿着一身破烂的衣服，却也挡不住他一身的英气。");
	set("icon",young_man4);
	
	set("title","塞外");
	set("attitude", "peaceful");
	
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);
	set("per",31);
	
	set("hp", 22000);
	set("max_hp", 22000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 100);
	
	set("combat_exp", 1000000);
	set("score", 30000);
	set_skill("force", 100);                            
	set_skill("unarmed", 100);                         
	set_skill("dodge", 100);                     
	set_skill("parry", 100);           

	carry_object("cloth")->wear();
	set("no_kill",1);
}

NPC_END;