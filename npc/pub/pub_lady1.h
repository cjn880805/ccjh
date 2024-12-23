//lady1.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_lady1);

virtual void create()
{
	set_name("苏州女孩","lady");
	
	set("icon", young_woman4);
	set("gender", "女性" );
	set("age", 16);
	set("long","这是个十六、七岁的苏州女孩，清丽绝俗，一脸温柔的颜色。"); 
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
};


NPC_END;
