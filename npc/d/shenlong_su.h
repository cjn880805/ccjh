// shenlong_su.c 苏荃

//code by Fisho
//date:2000-12-22

NPCSHENLONG_BEGIN(CNshenlong_su);

virtual void create()
{
	set_name("苏荃", "su quan");
	set("title",  "夫人" );
	set("long", "她就是神龙教教主洪安通的夫人。 ");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
 	set("icon",young_woman3);
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1500000);
	set("score", 400000);
	
	set_skill("force", 150);
	set_skill("shenlong_xinfa", 150);
	set_skill("dodge", 180);
	set_skill("yixingbu", 160);
	set_skill("unarmed", 150);
//	set_skill("shenlong_quanfa", 150);		//没有该技能 lanwood 2000-12-29
	set_skill("parry", 150);
	set_skill("staff", 150);
	set_skill("strike", 180);
	set_skill("shedao_qigong", 120);
	set_skill("literate", 100);
//	set_skill("meiren_sanshi", 180);		//没有该技能 lanwood 2000-12-29
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
//	map_skill("strike", "meiren_sanshi");
//	map_skill("unarmed", "shenlong_quanfa");
//	map_skill("parry", "meiren_sanshi");
	map_skill("staff", "shedao_qigong");
	set_inquiry("入教"," 一般人是入不了我神龙教的. ");
	set_inquiry("口号"," 万年不老!永享仙福!寿与天齐!文武仁圣! ");
	
	set("chat_chance_combat", 50);  
	carry_object("cloth")->wear();
	add_money( 5000);
}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("usedgao"))    
			set("combat_exp",500000);
		set("hp",10);
	}
	return "";
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if (ob->query_skill("shenlong_xinfa",1) < 80 ) 
	{
		say(" 你的本门内功心法太低了,还是努努力先提高一下吧!", ob);
		SendMenu(ob);
		return;
	}
	if (ob->query_skill("shedao_qigong",1) < 80 ) 
	{
		say(" 你的本门杖法太低了,还是努努力先提高一下吧!", ob);
		SendMenu(ob);
		return;
	}
	if (ob->query("repute") > -10000  ) 
	{
		say(" 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！", ob);
		SendMenu(ob);
		return;
	}

	say(" 很好，很好。");
	command(snprintf(msg,255,"recruit %ld" ,ob->object_id() ));
}

NPCSHENLONG_END;