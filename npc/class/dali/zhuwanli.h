//zhuwanli.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_zhuwanli);

virtual void create()
{
	set_name("褚千里", "zhu qianli");
	set("title", "四大卫护之一");
	set("age", 34);
	set("gender", "男性");
	set("long", "他身穿着一身黄色官服，武官打扮。手里还拿着一根鱼竿，看来挺喜欢吊鱼的");
	set("icon", young_man2);

	set("attitude", "friendly");
	set("str", 30);
	set("dex", 20);
	set("int", 20);
	set("max_force", 600);
	set("force", 600);
	set("force_factor", 20);
	set("combat_exp", 400000);
	set("repute", 100);
	set_skill("unarmed", 260);
	set_skill("dodge", 170);
	set_skill("parry", 180);
	set_skill("sword",133);
	set_skill("finger", 149);
	set_skill("literate", 110);
	set_skill("sun_finger",145);
	set_skill("force", 170);
	set_skill("whip", 260);
	set_skill("tianlong_shengong", 170);
	set_skill("qingdie_shenfa", 170);
	map_skill("dodge", "qingdie_shenfa");
	map_skill("finger","sun_finger");
	map_skill("force", "tianlong_shengong");
	create_family("大理段家", 6, "弟子");
	
	carry_object("junfu")->wear();
	carry_object("tiebian")->wield();
	add_money(3000);
};

virtual void attempt_apprentice(CChar * me)
{
//	int phlye = me->query("phlye");
	char msg[255];

/*	if(phlye != 5)
	{
		say(snprintf(msg, 255, "%s的根骨到是不错哟，我也想收你为徒，可是...", query_respect(me)), me);
		say("目前大理段氏只传武功给云南人，你还是等下辈子吧！", me);
		SendMenu(me);
		return;
	}
*/
	if ( me->query("betrayer") > 1 && DIFFERSTR(me->querystr("family/family_name"), "大理段家"))
	{ 
		say("你这个逆贼，岂能入我门下，我今天就先杀了你以示后人！");
		kill_ob(me);
		return ;  
	}

	if( me->query("family/generation") >= query("family/generation")
		&& EQUALSTR(me->querystr("family/family_name"), "大理段家"))
	{
		say("你的辈分不比我低了，我怎么能收你为徒呢？", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 0) 
	{
		say("我大理段氏乃是堂堂名门正派，对弟子要求极严。", me);
		say(snprintf(msg, 255, "在德行方面，%s是否还做得不够？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	say("好吧，我就收下你了。");
	command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}


NPC_END;
