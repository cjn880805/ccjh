//chengjialuo
//wq 2002-07-19

NPC_BEGIN(CNlj_chengjialu);

virtual void create()
{
	set_name("程家洛", "cheng jialuo");
	
	set("long","这是一个文士打扮的中年书生，神色和蔼。偶尔向这边看过来，顿觉他目光如电，英气逼人。");
	set("gender", "男性");
	set("age", 21);
	set("icon",young_man5);
	set("title", "红花会");
	
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("per",30);
	
	set("max_hp", 15000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_force", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	
	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("unarmed", 280);
	set_skill("parry", 280);
	set_skill("whip", 280);
	set_skill("blade", 280);
	set_skill("sword", 280);
	set_skill("hand", 280);
	set_skill("claw", 280);
	set_skill("houquan", 280);
	set_skill("yunlong_xinfa", 280);
	set_skill("yunlong_shengong", 280);
	set_skill("wuhuduanmendao", 280);
	set_skill("yunlong_jian", 280);

	set_skill("yunlong_shenfa", 280);
	set_skill("yunlong_bian", 280);
	set_skill("yunlong_shou", 280);
	set_skill("yunlong_zhua", 280);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhuduanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	
	carry_object("changjian")->wield();
	set("no_kill",1);
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
		message_vision("$HIY$N说罢在众人惊诧的目光中，$n推开前来带路的太监，扬身直掠出宫。",failer);
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