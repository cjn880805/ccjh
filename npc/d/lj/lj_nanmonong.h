//nanmonong.h
//wq 2002-07-6

NPC_BEGIN(CNlj_nanmonong);

virtual void create()
{
	set_name("慕容", "mu rong");
	set("long","他长的玉树临风，风流倜傥。只是双眼中偶尔流露出的凶光让人不寒而栗。");
	set("age", 27);

	set("title","姑苏");
	set("attitude", "friendly");
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",young_man2);
	
	set("per",33);
	
	set("hp", 25000);
	set("max_hp", 25000);
	set("mp", 14500);
	set("max_mp", 14500);
	set("mp_factor", 100);
	set("combat_exp", 2000000);
	set("score", 50000);
	
	set_skill("xingyi_zhang",300);
	set_skill("strike",300);
	set_skill("finger",300);
	set_skill("dodge",300);
	set_skill("force", 300);
	set_skill("canhe_zhi", 300);
	set_skill("murong_jianfa",300);
	set_skill("shenyuan_gong", 300);
	set_skill("yanling_shenfa", 300);
	set_skill("douzhuan_xingyi", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("literate", 300);
	set_skill("murong_daofa", 300);
	set_skill("blade",300);
	
	map_skill("blade", "murong_daofa");
	map_skill("finger", "canhe_zhi");
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	map_skill("parry", "douzhuan_xingyi");
	map_skill("sword", "murong_jianfa");
	
	prepare_skill("finger", "canhe_zhi");

	if(random(2))
		carry_object("sword_1")->wield();
	else
		carry_object("blade_1")->wield();
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
		message_vision("\n$HIY$n叹道：这位仁兄，今天我$N败的心服口服。他日若有机缘，再来请教，告辞了。",winner,failer);
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