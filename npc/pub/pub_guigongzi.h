NPC_BEGIN(CNpub_guigongzi);

virtual void create()
{
	set_name("贵公子","guigongzi");
	
	set("icon", young_man1);
	set("gender", "男性" );
	set("age", 29);
	set("long", "这是一介翩翩贵公子，长得到也算玉树临风、一表人才，可偏偏一双眼睛却爱斜着瞟人。");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("per", 26);
	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 1200);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	add_money(100);
	
};

NPC_END;
