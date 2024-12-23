//lj_zhoubotong 
//wq
//2002-07-19

NPC_BEGIN(CNlj_zhoubotong);

virtual void create()
{
	set_name("周不通", "zhou botong");
	set("gender", "男性");
	set("age", 26);
	
	set("title", "青年");
	set("long","他就是全真教掌门人的师弟，武功高强人却有点呆头呆脑的。");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("foolid",33);

	set("per",18);
	
	set("hp", 19500);
	set("max_hp", 19500);
	
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 100);
	
	set("combat_exp", 20000000);
	set("score", 500000);
	
	set_skill("force", 280);
	set_skill("dodge", 290);
	set_skill("parry", 280);
	set_skill("unarmed",300);
	set_skill("kongming_quan",300);
	set_skill("jinyan_gong",300);
	set_skill("xiantian_qigong",300);
	
	map_skill("force", "xiantian_qigong");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "kongming_quan");
	map_skill("unarmed", "kongming_quan");
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