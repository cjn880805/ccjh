//sun.h
//code by cat
//2001-4-2

NPC_BEGIN(CNGuMu_sun);

virtual void create()
{
	set_name("孙奶奶","sun nana");
	
	set("gender", "女性");
	set("age", 58);
	set("long",
		"她是一名和蔼可亲的老婆婆，一张生满鸡皮疙瘩的丑脸,但奇丑之中却含仁慈温柔之意.");
	set("attitude", "friendly");
	set("icon",old_woman);
	
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("foolid",60);
	set("chat_chance_combat", 9);
	
	set("chat_chance", 1);
	
	set("hp", 3500);
	set("max_hp", 5400);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 40);
	
	set("combat_exp", 1000000);
	
	
	set_skill("force", 150);
	set_skill("yunv_xinfa", 150);    //玉女心法
	set_skill("sword", 150);
	set_skill("yunv_jian", 150);     //玉女剑
	set_skill("dodge", 160);
	set_skill("yunv_shenfa", 160);   //玉女身法
	set_skill("parry", 130);
	set_skill("unarmed",100);
	set_skill("meinv_quan", 120);    //美女拳法
	set_skill("literate",120);
	set_skill("qufeng",100);         //驱蜂之术
	set_skill("tianluo_diwang", 150);
	
	map_skill("force", "yunv_xinfa");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "meinv_quan");
	map_skill("unarmed", "meinv_quan");
	
	create_family("古墓派", 3, "弟子");
	
	set_inquiry("进入古墓","本门重地，谢绝外人进入。");
	set_inquiry("玉女剑法","玉女剑法和全真剑法合壁，天下无敌！");
	set_inquiry("古墓派","我的林祖师婆婆本来和重阳先师是一对璧人，可是...");
	set_inquiry("玉蜂浆","做玉蜂浆要玉蜂蜜，可我现在老了，慢手慢脚的都不敢去采蜜了。");
	
	carry_object("baipao")->wear();
	set("no_huan",1);

}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed you", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "fengmi") || DIFFERSTR(ob->querystr("name"), "玉蜂蜜" ))
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("honey");

	message_vision("$N给了$n一瓶玉蜂浆道：“老啦，不中用啦，谢谢你帮我把蜜采回来。”", this, who);
	ob->move(who);

	return 1;
}


virtual void attempt_apprentice(CChar  * player)
{
	if(player->query("per") < 25)
	{
		say(" 尊容实在不敢恭维，恐怕学不了玉女心法。",player);
		SendMenu(player);
		return;
	}
	if(player->query_dex() < 20)
	{
		say(" 你的身法太差，不适合学我古墓派的武功。",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 25)
	{
		say(" 你的悟性太差，不适合学我古墓派的武功。",player);
		SendMenu(player);
		return;
	}
	if(EQUALSTR(player->querystr("family/family_name"), "古墓派") && EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" 你是那个魔头的门下？本门叛逆，走吧。",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") < 0)
	{
		say(" 古墓派已经出过一个魔头，我不愿让古墓派再有这等事发生。",player);
		SendMenu(player);
		return;
	}
	if((EQUALSTR(player->querystr("gender"), "男性") ) && (! player->query_temp("pending/join_gumu")))
	{
		say(" 我派心法不太适合男子修习，你想清楚了没有？不要后悔哟。",player);
		SendMenu(player);
		player->set_temp("pending/join_gumu", 1);
		return;
	}
	if(EQUALSTR(player->querystr("gender"), "无性"))
	{
		say("你这个@#%%^&^&##!@#@$^$(&(%#$E#",player);
		SendMenu(player);
		return;
	}
	else
	{
	    say(" 好吧，我就收下你这个徒弟了。");
		recruit_apprentice(player);
	}
	return;
}
NPC_END;
