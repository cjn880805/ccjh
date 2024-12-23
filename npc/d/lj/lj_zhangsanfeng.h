//zhangsanfeng.h
//wq
//2002-07-19
NPC_BEGIN(CNlj_zhangsanfeng);

virtual void create()
{
	set_name("张三枫","zhang sanfeng");
	set("title", "少年" );
	set("long", "他身穿一件污秽的衣服，不修边幅。身材高大，眉清目秀，双眼射出精芒。");
	set("gender", "男性");
	set("age", 18);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	
	set("per",34);

	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 100);
	set("combat_exp", 2000000);
	set("score", 1200000);

	set_skill("force", 280);
	set_skill("taiji_shengong", 280);
	set_skill("dodge", 280);
	set_skill("tiyunzong", 280);
	set_skill("unarmed", 280);
	set_skill("taiji_quan", 280);
	set_skill("parry", 280);
	set_skill("sword", 280);
	set_skill("taiji_jian", 280);
	set_skill("blade", 280);
	set_skill("taiji_dao", 280);
	set_skill("taoism", 280);
	set_skill("literate", 280);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

//	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	set("chat_chance_combat", 30);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_kill",1);
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
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