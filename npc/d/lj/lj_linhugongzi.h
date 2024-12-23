//linhugongzi.h
//wq 2002-07-19

NPC_BEGIN(CNlj_linhugongzi);

virtual void create()
{
	set_name("令狐公子", "lin hu");
	set("long", "他身材瘦长,丰神俊朗，他就是天下闻名的令狐公子。");
	set("gender", "男性");
	set("age", 28);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man2);
	set("per",33);

	set("title","华山");
	
	set("hp", 15400);
	set("max_hp", 15400);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_factor", 60);
	
	set("combat_exp", 2000000);
	set("score", 100000);
	
	set_skill("unarmed",280);
	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("sword", 280);
	set_skill("huashan_sword", 280);

	set_skill("huashan_shenfa", 280);
	set_skill("feiyan_huixiang",280);
	set_skill("lonely_sword",280);
	set_skill("literate", 280);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	
//	create_family("华山派", 14, "弟子");
	
	carry_object("changjian")->wield();
	set("chat_chance_combat", 10);
	set("no_kill",1);
}

	
virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("sword poqi", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

void is_defeated(CChar * winner, CChar * failer)
{

	//下面是比武得胜者的处理
	winner->add_temp("lj/biwu/win",1);
	winner->delete_temp("biwu");
	if(winner->query_temp("no_fei"))
		winner->delete_temp("no_fei");
	failer->delete_temp("biwu");
	if(failer->query_temp("no_fei"))
		failer->delete_temp("no_fei");

	winner->revive(1);
	failer->revive(1);
	winner->set("hp",winner->query("max_hp"));
	winner->set("eff_hp",winner->query("max_hp"));
	winner->set("mp",winner->query("max_mp"));
	message_vision("$HIY$N身形向后一退，笑道：$n兄，承让了。",winner,failer);
	if(userp(winner))
	{
		message_vision("\n$HIY$n叹道：这位仁兄，今天我$n败的心服口服。他日若有机缘，再来请教，告辞了。",winner,failer);
		message_vision("$HIY$n说罢对在场众人拱手一礼，随司礼太监退出清凤阁去。",winner,failer);
		destruct(failer);
	}
	else if(userp(failer))
	{
		message_vision("\n$HIY$N一把摘下自己脸上的面具，摔在地下。\n只见$N满面通红，娇嗔道：“一点都不好玩。笨竹虚，死竹虚，要找老婆不会自己来找啊。”",failer);
		message_vision("$HIY$N说罢在众人惊诧的目光中，$N推开前来带路的太监，扬身直掠出宫。",failer);
		message_vision("$HIY弹指间$N的身影已消逝不见，只听见远远的传来声音“你们就继续争你们的驸马吧，本小姐再也不当这无聊的红娘了。”",failer);

		message_vision("\n$HIR你失去了招亲资格！",failer); 
		message_vision("$HIR你参加比武招亲失败，无缘见得西夏公主，亦无法求证梦姑在宫内何处，长叹之下只有放弃 ！\n\n",failer); 
		failer->del("lj");
		failer->delete_temp("lj");
		failer->enable_player();
		CContainer * env = load_room("灵州皇宫大门");
		if(env->query("start"))env->del("start");
		env = load_room("灵州皇宫大厅");
		if(env->query("start"))env->del("start");
		failer->move(load_room("灵州皇宫大门"));
	}
	else
	{
		message_vision("\n$HIY$n叹道：$N兄，今天我$n败的心服口服。他日若有机缘，再来请教，告辞了。",winner,failer);
		destruct(failer);
	}
}
NPC_END;
