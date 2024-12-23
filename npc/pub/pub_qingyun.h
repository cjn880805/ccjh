// pub_qingyun.c
//code by Fisho
//date : 2000-12-14
//Last Modify @ 2001-02-10
//Powerup.



NPC_BEGIN(CNpub_qingyun);

virtual void create()
{
	set_name("端木青云",  "qingyun");

	set("icon", young_man4);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("str", 35);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 500);
	set("combat_exp", 7000000);
	set("score", 50000);
	set_skill("blade",100);
	set_skill("xiaoyao_dao",100);

	set_skill("sword",250);
	set_skill("lingxiao_kuaijian",250);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("lingboweibu", 100);
	set_skill("beiming_shengong",100);
	set_skill("liuyang_zhang", 100);
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("blade", "xiaoyao_dao");

	map_skill("sword", "xiaoyao_kuaijian");
	
	set("chat_chance_combat", 40);

	
	create_family("逍遥派", 1, "弟子");
	set("title","海棠之虎");
	carry_object("cloth")->wear();
//	carry_object("gangdao")->wield();		//modify blade to gangdao lanwood 2001-01-04
	carry_object("plumsword")->wield();		//modify blade to sword Teapot 2001-02-10

}

virtual void init(CChar *ob)
{
	CNpc::init(ob);

	if(is_fighting()) return;

	if (userp(ob) && DIFFERSTR(ob->querystr("family/family_name"), "逍遥派"))
	{
		say("你好大的胆子，本派的密室也敢闯进来 ？！");
		kill_ob(ob);
	}
	else if(EQUALSTR(ob->querystr("family/family_name"), "逍遥派"))
	{
		say("师弟辛苦啦！");
	}
}

virtual char * chat_msg_combat()
{
	if(random(4) == 0)
		perform_action("sword mixhit", 1);

	return 0;
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if (ob->query_skill("beiming_shengong", 1) < 140) 
	{
		say("我逍遥派内功的源泉来自于北冥神功的心法。", ob); 
		say(snprintf(msg,255,"%s的北冥神功是否还应该有所提高啊？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	
	if (ob->query_int() < 40) 
	{
		say(" 我逍遥派武功最重视“逍遥”二字。", ob);
		say(" 而何谓“逍遥”，这只能靠你自己去领悟。", ob);
		say(snprintf(msg,255," 但是%s的悟性似乎还有待提高啊。",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	command("haha");

	say("想不到天下还能有人让我凌云十三剑不至失传！");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
	
	ob->set("title","逍遥派海棠之虎弟子");
	ob->UpdateMe();
}


NPC_END;