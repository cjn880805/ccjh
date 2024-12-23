//xu.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

SHENLONG_BEGIN(CNshenlong_xu);

virtual void create()
{
	set_name("许雪阁","xu xuege");
	set("title", "神龙教青龙使");
	set("nickname",  "热血神龙" );
	set("long", "这是个五十来岁的高瘦汉子，着一袭青衣，昂然挺立。" );
	set("icon",young_man5);	
	
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("con", 30);
	set("max_hp", 9000);
    set("hp",3000);
	set("max_mp",1000);
    set("mp",1000);
	set("mp_factor", 50);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

    set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("unarmed", 100);
    set_skill("strike", 90);
    set_skill("parry", 100);
    set_skill("staff", 90);
    set_skill("sword", 90);
	set_skill("literate", 90);
	
	set_skill("shenlong_xinfa", 90);
	set_skill("yixingbu", 90);
	set_skill("shenlong_bashi", 90);
	set_skill("huagu_mianzhang", 90);
	set_skill("shedao_qigong", 90);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");

	prepare_skill("unarmed", "shenlong_bashi");
	prepare_skill("strike", "huagu_mianzhang");

	create_family("神龙教",2,"弟子");

	set_inquiry("百花腹蛇膏",ask_gao);
    set_inquiry("入教",do_join);
	set_inquiry("洪安顺","教主脾气不好,要讨他欢心才好");
	set_inquiry("教主","教主脾气不好,要讨他欢心才好。");
	set_inquiry("口号","万年不老!永享仙福!寿与天齐!文武仁圣!");

	set("chat_chance", 3);
	set("chat_chance_combat", 30);

    carry_object("duanjian")->wield();
	set("no_huan",1);
}

static char * ask_gao(CNpc * npc , CChar * player)
{
	return "许雪亭悄声对你说：这可是本教禁物啊。它一遇鲜血，便生浓香，我们住在这灵蛇岛上，人人都服惯了雄黄酒，以避毒蛇，这股香气一碰到雄黄酒，便使人筋骨酥软，不能动弹。对了，你怎么也知道？";
}

static char * do_join(CNpc * npc , CChar * player)
{
	if (player->query("repute") > 0)
	{
		message_vision("$N对$n大怒道：还想入教？一看你就不是好人! ", npc, player);
		npc->kill_ob(player);
		return 0;
	}

	if(player->querymap("party") && DIFFERSTR(player->querystr("party/party_name"), "神龙教"))
	{
		message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我神龙教。", npc, player);
		return 0;
	}

	if(player->query("age") > 24)
	{
		message_vision("$N无奈地摇摇头对$n说：教主近来只喜欢招收少年男女，你无本教无缘啊。", npc, player);
		return 0;
	}

	if( EQUALSTR(player->querystr("party/party_name"), "神龙教") )
	{
		message_vision("$N摇摇头，对$n说道：你已经是我神龙教的人了。",npc, player);
		return 0;
	}

	char new_rank[40];
	snprintf(new_rank, 40, "青龙使属下");
	player->set("party/party_name","神龙教");
	player->set("party/rank", new_rank);
	player->set("party/level", 1);
	
	g_Channel.do_emote(npc,player, "smile", 0);
	message_vision("$N对$n说道：你就暂时在本使座下效力吧！",npc,player);
	return 0;
}

virtual  char  * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "许雪阁忽然一怕脑袋，说：对了，可以用百花腹蛇膏！";
	case 1:
		return "许雪阁怒道：唉，偌大一个神龙教，都毁在一个娘们手里了！";
	case 2:
		return "许雪阁叹口气，说道：唉，不杀了洪安顺，谁也活不了。";
	}
	return "";
}

virtual int  accept_object(CChar * player , CContainer * obj)
{
	CContainer * obn;
	if (!obj)
	{	
		say("你没有这件东西。",player);
		SendMenu(player);
		return 0;
	}

	if ( DIFFERSTR(obj->querystr("base_name"), "腹蛇胆") && DIFFERSTR(obj->querystr("base_name"), "百香花" ))
	{
		say("许雪阁摇头道：如果杀不了洪安顺，给我什么也没用啊。。。",player);
		SendMenu(player);
		    return 0;
	}

	if(EQUALSTR(obj->querystr("base_name"), "腹蛇胆"))
	{
		  if(query_temp("baixianghua"))
		  {
			  message_vision("许雪阁见是腹蛇胆，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!",player);
			  obn=load_item("baihua");
              obn->move(player);
		      delete_temp("fushedan");
		      delete_temp("baixianghua");
 	          return 1;		 
		  } 		
		  else	
		  {	
			if(query_temp("fushedan"))
			{
			  message_vision("许雪阁见是腹蛇胆，对$N摇头道：腹蛇胆我有了，就差百香花了。",player);
			  return 0;
			}
			else	  
			{
			  message_vision("许雪阁看见腹蛇胆，大喜道：有了腹蛇胆，只差百香花了。",player);
			  set_temp("fushedan",1);	
	          return 1;
			}
		  }
	}
	if (EQUALSTR(obj->querystr("base_name"), "百香花" ))
	{
		  if(query_temp("fushedan"))
		  {
		  message_vision("许雪阁见是百香花，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!",player);
		  obn=load_item("baihua");
          	  obn->move(player);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
 	          return 1;		 
		  } 		
		  else	
		  {	
			if(query_temp("baixianghua"))
            {
				message_vision("许雪阁见是百香花，对$N摇头道：百香花我有了，就差腹蛇胆了。",player);
			   return 0;
			}
			else	  
            {
				message_vision("许雪阁看见百香花，大喜道：有了百香花，只差腹蛇胆了。",player);
				set_temp("baixianghua",1);	
				return 1;
			}
		 }	
	}
	return 0;
}

NPC_END;