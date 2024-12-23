//duaner.h
//wq 2002-07-19

NPC_BEGIN(CNlj_duaer);

virtual void create()
{
	set_name("段玉", "duan yu");
	set("long", "他长的眉清目秀，是有名的爱情圣手。");
	set("gender", "男性");
	set("icon", young_man4);
	
	set("title", "大理");
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 45);
	set("dex", 40);
	set("per",32);
	
	set("max_hp", 26000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 100);
	set("combat_exp", 2000000);
	set("score", 300000);
	
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("cuff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("finger", 300);
	set_skill("kurong_changong", 300);
	set_skill("tiannan_step", 300);
	set_skill("jinyu_quan", 300);
	set_skill("wuluo_zhang", 300);
	set_skill("duanjia_sword", 300);
	set_skill("sun_finger", 300);
	set_skill("lm_shangyang", 300);
	set_skill("literate", 300);
	
	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("finger", "sun_finger");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("parry", "sun_finger");
	map_skill("sword", "duanjia_sword");

	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");
	
	carry_object("cloth")->wear();
	carry_object("sword_1")->wield();
	add_money(5000);
	set("no_kill",1);

};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * r = load_room("灵州皇宫大门");
	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu115") )
	{
		me->set_temp("lj/renwu115",1);
		me->disable_player("等待中");
		call_out(do_start, 5);
	}
}

static void do_start(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * r = load_room("灵州皇宫大厅");
	message_vision("\n$HIR正在你等的焦急的时候，大殿后走出一个白白胖胖的太监,慢慢走到殿前，细声细气的说道：", me);
	message_vision("$HIR“请各位公子入内书房比试，林暮明姑娘你女扮男装有所不便请在此处稍息。”\n", me);
	message_vision("$HIR林暮明“哼”的一声，掉头拂袖而去。", me);
	message_vision("$HIR\n你不由得暗自庆幸百晓声的人皮面具制作精细，比之单单扮男装不易察觉多了！\n", me);
	me->enable_player();
	if(!r->query("start"))
		r->set("start",1);

	DTItemList * list = r->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target))
		{
			target->enable_player();
			continue;
		}
		if(DIFFERSTR(target->querystr("name"), "林暮明") && DIFFERSTR(target->querystr("name"), "段玉"))
			target->move(load_room("灵州皇宫幽兰涧"));
		else if(EQUALSTR(target->querystr("name"), "林暮明"))
			destruct(target);

	}
	me->move(load_room("灵州皇宫幽兰涧"));
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

