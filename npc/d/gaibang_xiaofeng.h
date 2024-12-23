//xiaofeng.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_xiaofeng);

virtual void create()
{
	set_name("萧峰","xiao feng");

	set("gender", "男性");
	set("nickname","铁掌降龙");
	set("age", 28);
	set("long","他就是丐帮前任帮主，因为有外国的血统而被民族极端分子迫害得下岗了,他身穿一件普通的粗布褂子，腰间用一条麻绳随便一系。他身高六尺有余，体格十分魁梧，长有一张线条粗旷、十分男性化的脸庞，双目如电，炯炯有神。");
	set("attitude", "peaceful");
 	set("icon",young_man6);
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);

	set_inquiry("丐帮","东北西北东西北。");
	set_inquiry("拜师","你可以去东城门的我帮总舵拜鲁帮主。");

	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 120);             // 基本内功
	set_skill("huntian_qigong", 120);    // 混天气功
	set_skill("unarmed", 120);           // 基本拳脚
	set_skill("xianglong_zhang", 120);   // 降龙十八掌
	set_skill("dodge", 120);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 120);        // 逍遥游
	set_skill("parry", 120);             // 基本招架
	set_skill("begging", 50);            // 叫化绝活
//	set_skill("checking", 50);           // 道听途说
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	
	carry_object("cloth")->wear();
};

virtual char * chat_msg(CChar * player)
{
	switch(random(2))
	{
	case 0:
		return "萧大哥叹了口气道：“唉……想不到我老萧大好男儿，居然被牛夫人这样一个女子所骗！";
	case 1:
		return "萧大哥喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”";
	}
	return "";
}


virtual void init(CChar * player)
{
	if(userp(player))
	{
		remove_call_out(check_skills);
		call_out(check_skills, 2, player->object_id());
	}
}

static void check_skills(CContainer * npc , LONG param1 , LONG param2)
{
	CChar * player = (CChar *)(npc->environment())->Present(param1);
	
	if(! player) return;		//没有玩家返回。lanwood 2000-12-30

	CMapping * skl = player->query_skills();
	int counter,ob_shen;

	ob_shen=player->query("repute");

	counter=0;

	CVector v;

	skl->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		if((*skl)[v[i]]>=100)
			counter++;
	}

	if(counter>=3)
	{
		if(!(npc->environment())->query("no_fight"))
			npc->call_out(do_kill,1,param1);
		return ;
	}
	else 
	{
		npc->call_out(waiting,0,param1);
		return ;
	}
	
}

static void do_kill(CContainer * ob ,LONG param1 , LONG param2)
{
	CChar * npc=(CChar *)ob;
	CChar * player=(CChar *)(npc->environment())->Present(param1);
	char msg[255];

	if(!player) return;

	if(player->query("yipin/joined"))
		return ;
	if(player && (npc->environment())->query("no_fight"))
	{
		message_vision(snprintf(msg,255,"$N对$n说道：老子一见一品堂高手就生气。",query_rude(player)),npc,player);
		npc->kill_ob(player);
		player->fight_ob(npc);

		npc->call_out(checking,0,param1);
	}
	else
		npc->call_out(waiting,1,param1);

}

static void waiting(CContainer * ob , LONG param1 , LONG param2)
{
	CChar * npc=(CChar *)ob;
	CChar * player=(CChar *)(npc->environment())->Present(param1);

	if(player)
	{
		if(npc->is_fighting())
		{
			npc->call_out(checking,0,param1);
			return ;
		}
		else if(living(npc) && !(player->environment())->query("no_fight"))
			return ;
	}

	npc->remove_call_out(waiting);
	npc->call_out(waiting,20,param1);

}

static void checking(CContainer * ob ,LONG param1 , LONG param2)
{
	CChar * npc=(CChar *)ob;
	CChar * player=(CChar *)(npc->environment())->Present(param1);
	CContainer * corpse;

	if(! player) return;

	if(npc->is_fighting())
	{
		npc->call_out(checking,1,param1);
		return ;
	}

	corpse =(npc->environment())->PresentName("corpse_ob",IS_CORPSE);

	if(corpse && corpse->querystr("victim_name") == player->name())
	{
		npc->call_out(do_back,1,param1);
		return ;
	}

	npc->call_out(waiting,0,param1);
}

static void do_back(CContainer * npc , LONG param1 , LONG param2)
{
	CChar * player=(CChar *)(npc->environment())->Present(param1);

	if(!player) return;

	npc->move(load_room("/d/city/dongdajie2"));
	npc->set("combat_exp",1000000);
	message_vision("萧峰走了过来，拍了拍身上的尘土，微微一笑说道：又除了一个坏蛋。",player);
}



NPC_END;
