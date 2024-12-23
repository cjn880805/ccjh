//renwuyue.h	任我行
//code by zwb
//12-16
//inherit F_MASTER;


NPC_BEGIN(CNHeiMUYa_renwuyue);

virtual void create()
{
	set_name("任无月","ren wuyue");

	set("title",  "日月神教原教主" );
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀,身材甚高，一头黑发，穿的是一袭青衫。");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_man2);
	
	set("hp", 9000);
	set("max_hp", 9000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 400);
	set("combat_exp", 6000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("changquan", 200);
	set_skill("xingxiu_duzhang", 200);
	set_skill("lingxu_bu", 200);
	set_skill("damo_jian", 200);
	set_skill("taiji_jian", 200);
	set_skill("huifeng_jian", 200);
	set_skill("taishan_sword", 200);
	set_skill("hengshan_jian", 200);
	set_skill("hengshan_sword", 200);
	set_skill("huashan_sword", 200);
	set_skill("songshan_sword", 200);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "kuihua_xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");

	set_inquiry("比剑",ask_bijian);
	set_inquiry("教主",ask_jiaozhu);
	set_inquiry("黑木令","要拿黑木令？老夫想先看看你的剑法！");

	carry_object("bluecloth")->wear();
	carry_object("changjian")->wield();
}

static char * ask_bijian(CNpc * npc , CChar * player)
{
	CContainer * obj;
	char msg[255];
	LONG ID=player->object_id();

	message_vision("$N躬身说道：“今日有幸拜见任老前辈，还望多加指教。”\n$n笑道：“不用客气，你来解我寂寞，可多谢你啦。”\n$N道：“不敢。”\n$n点了点头，说道：“我只想瞧瞧你的剑法，并非真的过招，再说，我也未必能胜得了你。”\n$n月大喝一声：“少林剑法！”", 
		player, npc);

	g_Combatd.Do_Attack(npc,player, CCombatd::TYPE_QUICK);

	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“才一招。”", player);
		return "";
	}

	npc->command("enable 0 sword taiji_jian");
	message_vision("任无月大喝一声：“武当剑法！”", player);
	g_Combatd.Do_Attack(npc, player, CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“才两招。”",player);
		return "";
	}

	npc->command("enable 0 sword huifeng_jian");
	message_vision("任无月大喝一声：“峨嵋剑法！”",player);
	g_Combatd.Do_Attack(npc,player, CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“才三招。”",player);
		return "";
	}

	npc->command("enable 0 sword songshan_sword");
	message_vision("任无月大喝一声：“嵩山剑法！”",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“才四招。”",player);
		return "";
	}
	
	npc->command("enable 0 sword taishan_sword");
	message_vision("任无月大喝一声：“泰山剑法！”", player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0|| !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“才五招。”",player);
		return "";
	}
	
	npc->command("enable 0 sword huashan_sword");
	message_vision("任无月大喝一声：“华山剑法！”",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0  || !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“才六招。”",player);
		return "";
	}
	
	npc->command("enable 0 sword hengshan_sword");
	message_vision("任无月大喝一声：“衡山剑法！”",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“才七招。”",player);
		return "";
	}
	
	npc->command("enable 0 sword hengshan_jian");
	message_vision("任无月大喝一声：“恒山剑法！”",player);
	g_Combatd.Do_Attack(npc,player,CCombatd::TYPE_QUICK);
	if(player->query("hp") < 0 || !(npc->environment())->Present(ID))
	{
		message_vision("任无月叹了口气，说道：“还是没过八招。”",player);
		return "";
	}

	obj = load_item("kuihua");
	obj -> move(player);
	npc->say(snprintf(msg,255,"“这位%s不错，黑木令现在没什么用了，给你一本书吧，看不看就是你自己的事了。”",query_respect(player)), player);
	npc->SendMenu(player);
	return "";
}


static char * ask_jiaozhu(CNpc * npc , CChar * me)
{
	CContainer * obj;
	char msg[255];
	if(me->query("level") < 45 ||me->query_temp("ry/renwu1_1"))
	{
		npc->say(snprintf(msg,255,"“这位%s，闲着没事问这些干什么！”",query_respect(me)), me);
		npc->SendMenu(me);
		return "";
	}
	if ( me->query("ry/jq")==me->query("age") )
	{
		npc->say(snprintf(msg,255,"“这位%s，你想问些什么呢？”",query_respect(me)), me);
		npc->SendMenu(me);
		return "";
	}

	obj = load_item("baozi");
	obj->set_name("22世纪东方艺术展门票","men piao");
	obj->set("long","这是一张薄薄的纸片，上面写着“22世纪东方艺术展入场卷”的字样。");
	obj->set("owner1",me->id(1));
	obj->set("ry/menpiao",1);
	obj -> move(me);
	npc->say(snprintf(msg,255,"“这位%s，问这个干嘛，莫非也有所耳闻？本教前任教主任我行似乎并没有离世，他好像被困在一个极其幽避的所在，由四个分别奢好琴、棋、书、画的武林高手看管。”",query_respect(me)), me);
	npc->say(snprintf(msg,255,"“这里有一张艺术展门票，或许他们会喜欢，就送你给吧，希望你能找到线索救出他老人家。”", me);
	npc->say(snprintf(msg,255,"“哎！其实我也是听别人说的，谁知道是真是假呢。你可别告诉别人，就当我没说过好了。”", me);
	npc->SendMenu(me);
	me->set_temp("ry/renwu1_1",1);//启动日月任务，拿到门票
	me->set_temp("no_fei",1);
	tell_object(me,"\n$HIC你得到数量1的22世纪东方艺术展门票。\n");
	return "";
}

NPC_END;
