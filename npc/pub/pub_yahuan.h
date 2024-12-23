// pub_yahuan.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_yahuan);

virtual void create()
{
	set_name("丫环","ya huan"  );

	set("icon", young_woman7);
	set("gender", "女性" );
	set("age", 18);
	set("long", "这是一个容貌清秀的丫环，正在打闹的开心。");
	set("shen_type", 1);
	set("combat_exp", 1000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_hp", 300);
	set("mp", 100);
	set("max_mp", 100);
	set("score", 800);
	
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
	carry_object("hongchouxiaoshan")->wear();
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"丫环笑着说道：这位%s，过来和我们一起玩吧。",query_respect(ob) );
}
NPC_END;