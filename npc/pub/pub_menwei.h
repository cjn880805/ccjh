//pub_menwei.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_menwei);

virtual void create()
{
	set_name("门卫", "men wei" );

	set("icon", young_man1);
	set("nickname", "铁狮子");
	set("gender", "男性" );
	set("age", 22);
	set("long", "这是个年富力强的卫兵，样子十分威严。");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("max_hp", 1200);
	set("mp", 200);
	set("max_mp", 200);
	set("combat_exp", 9000+random(1000));
	set("score", 12000);
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 30+random(10));
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor",20);
	
	add_money(20);
	carry_object("dadao")->wield();
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	if( EQUALSTR(ob->querystr("family/family_name"), "白驼山派"))
	{ 
		return snprintf(msg,255,"门卫笑吟吟地说道：这位%s您辛苦了，快请进吧　。",query_respect(ob));
	}
	if(!ob->query("family/family_name"))
	{ 
		return snprintf(msg,255,"门卫满脸笑容地说道：这位%s您是来拜师的吧。师傅就在里面，快请进吧。",query_respect(ob));
	}
	if( ob->query("repute")>200)
	{ 
		return snprintf(msg,255,"门卫两眼一瞪，说道：这位%s你是来找麻烦的吧。我劝你不要轻举妄动！",query_respect(ob));
	}
	return "";
}

NPC_END;