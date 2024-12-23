//fawang.h
//code by zwb
//1-15
//inherit F_MASTER;

ZUSHI_BEGIN(CNxueshan_fawang);

virtual void create()
{
	   set_name("金轮明王", "inlun fawang");
	   set("long","他是雪山寺的护教法王。在雪山寺的地位仅次与掌门人鸠摩香。身穿一件紫红袈裟，头带僧帽。");
	   set("title", "法王" );
	   set("gender", "男性");
	   set("age", 50);
	   set("icon",old_man1);
	   set("foolid",156);        
	   set("attitude", "peaceful");
	   set("shen_type", -1);
	   set("str", 30);
	   set("int", 30);
	   set("con", 30);
	   set("dex", 30);
	   set("max_hp", 15000);
	   set("mp", 4500);
	   set("max_mp", 4500);
	   set("mp_force", 100);
	   set("combat_exp", 1500000);
	   set("score", 200000);
	   
	   set_skill("force", 280);
	   set_skill("xiaowuxiang", 280);
	   set_skill("dodge", 280);
	   set_skill("shenkong_xing", 280);
	   set_skill("unarmed", 280);
	   set_skill("yujiamu_quan", 250);
	   set_skill("parry", 250);
	   set_skill("sword", 250);
	   set_skill("mingwang_jian", 250);
	   set_skill("mizong_xinfa", 300);
	   set_skill("literate", 280);
	   set_skill("hammer", 320);
	   set_skill("riyue_lun", 320 );
	   
	   
	   map_skill("force", "xiaowuxiang");
	   map_skill("dodge", "shenkong_xing");
	   map_skill("unarmed", "yujiamu_quan");
	   map_skill("parry", "riyue_lun");
	   map_skill("sword", "mingwang_jian");
	   map_skill("hammer", "riyue_lun");
	   
	   create_family("雪山寺", 2, "护教法王");
	   set("class", "bonze");
	   
	   carry_object("jinlun")->wield();
	   carry_object("p_jiasha")->wear();
	   carry_object("sengmao")->wear();
	   add_money(5000);
	   set("no_huan",1);
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[40];
	
	if (DIFFERSTR(player->querystr("gender"), "男性"))
		  {
		say(" 修习密宗内功需要纯阳之体。",player);
		say(" 这位施主还是请回吧！",player);
		SendMenu(player);
		return;
		  }
	
		  if (DIFFERSTR(player->querystr("class"), "bonze"))
		  {
			  say(" 我佛门的清规戒律甚多。",player);
			  say(" 这位施主还是请回吧！",player);
			  SendMenu(player);
			  return;
		  }
		  
		  if (DIFFERSTR(player->querystr("family/family_name"), "雪山寺"))
		  {
			  say(" 这位施主既非本寺弟子，还是请回吧！",player);
			  SendMenu(player);
			  return;
		  }
		  
		  if (player->query_skill("mizong_xinfa", 1) < 100) 
		  {
			  say(" 入我雪山寺，修习密宗心法是首要的。",player);
			  say(" 这位施主是否还应该多多钻研本门的心法？",player);
			  SendMenu(player);
			  return;
		  }
		  g_Channel.do_emote(this, player, "smile", 0);
		  g_Channel.do_emote(this, player, "nod", 0);
		  
		  say("你就随我学习佛法吧！");		
		  command(snprintf(msg,40,"recruit %ld",player->object_id()) );
		  
		  player->set("title","活佛");
		  player->UpdateMe();
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "雪山寺大殿" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s点了点头，收下了你送过来的包裹。",name(1)));
		tell_object(who, "\n$YEL你完成了替福威镖局押运暗镖的任务。");
		tell_object(who, snprintf(msg, 255, "$YEL获得了%d的经验奖励，江湖声望上升了%d点",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)压运暗镖成功，获得了%d的经验奖励，江湖声望上升了%d点！", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}
ZUSHI_END;