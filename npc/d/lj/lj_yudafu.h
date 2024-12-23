//lj_yudafu.h	郁达夫
//秦波 2002、6、1

NPC_BEGIN(CNlj_yudafu);

void create()
{
	set_name("郁达夫","yuda fu");
	set("long", "他就是在辽东北海一带大大有名的玄冥岛岛主。");
	set("title", "玄冥岛岛主");
	set("gender", "男性");
	set("age", 33);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 27);
	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);

	set("max_hp", 15000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 160);

	set("combat_exp", 4500000);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("claw",300);

	set_skill("wuwen_zhua",300);
	set_skill("guimei_shenfa",300);
	set_skill("wudu_shengong", 300);
    set_skill("tangshoudao", 300);
  
	map_skill("force", "wudu_shengong");
	map_skill("dodge", "guimei_shenfa");
	map_skill("parry", "tangshoudao");
	map_skill("claw", "wuwen_zhua");
	prepare_skill("claw", "wuwen_zhua");
	set("no_talk",1);
	
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu4"))
	{
		AddMenuItem("武林集会", "$0ask1 $1", me);
		if(me->query("lj/renwu4_tiaojian"))
			AddMenuItem("条件", "$0ask11 $1", me);
		SendMenu(me);	
		return 1;
	}
	return CNpc::do_talk(me, ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query("lj/renwu4"))
	{
		if(strcmp(comm, "ask1") == 0)
			return do_ask1(me);	
		if(strcmp(comm, "ask11") == 0)
			return do_ask11(me);	
	}
	if(me->query("lj/renwu6") && ! me->query("lj/renwu_lost"))
	{
		me->del("lj/renwu6");
		if(me->query("lj/renwu7"))me->del("lj/renwu7");
		me->set("lj/renwu5",1);
		me->set("lj/renwu55",1);
		say("郁达夫说道：武老大的确是此次万仙大会的召集人，已定于在武陵春召开大会，我也是时候启程了！", me);
		say("郁达夫说道：哎，还真希望铁姥留有解生死符秘方给弟子。", me);
		say("郁达夫说道：要不她一旦死去，我们这一百单八号人物就都得去陪葬了！", me);
		call_out(do_wanxuanhuei, 1);
		SendMenu(me);
	}
	else if(me->query("lj/renwu5"))
	{
		say("郁达夫说道：武老大的确是此次万仙大会的召集人，已定于在武陵春召开大会，我也是时候启程了！", me);
		say("郁达夫说道：哎，还真希望铁姥留有解生死符秘方给弟子。", me);
		say("郁达夫说道：要不她一旦死去，我们这一百单八号人物就都得去陪葬了！", me);
		call_out(do_wanxuanhuei, 1);
		SendMenu(me);
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_ask1(CChar * me)
{
	say("郁达夫说道：关于武林集会，本人确实知道得不少，只要你能帮我一件事，我自可告诉你。",  me);
	SendMenu(me);
	me->set("lj/renwu4_tiaojian",1);
	return 1;
}

int do_ask11(CChar * me)
{
	if(!me->query("lj/renwu4_hueifu"))
	{
		say("郁达夫说道：我有一知己现在隐居在武陵春某处，你若能将我手信送去，在下不胜感激。",  me);
		SendMenu(me);
		if(!me->query("lj/renwu4_xin"))
		{
			CContainer * bot;
			bot = load_item("xin");
			bot->set("long","这是一封玄冥岛岛主郁达夫写给武陵春笑语老人的书信。");
			bot->set("value", 0l);
			bot->set("xiaoyuelaoren", 1);
			bot->move(me);
			me->set("lj/renwu4_xin",1);
			tell_object(me, "你拿到了一封玄冥岛岛主郁达夫写给武陵春笑语老人的书信。。");
		}
	}
	else
	{
		tell_object(me, "郁达夫说道：多谢您的仗义相助！");
		tell_object(me, "郁达夫说道：武老大的确是此次万仙大会的召集人，已定于在武陵春召开大会，我也是时候启程了，！");
		tell_object(me, "郁达夫说道：哎，还真希望铁姥留有解生死符秘方给弟子，要不她一旦死去，我们这一百单八号人物就都得去陪葬了！");
		me->set("lj/renwu5",1);
		me->del("lj/renwu4");
		me->del("lj/renwu4_tiaojian");
		me->del("lj/renwu4_hueifu");
		me->del("lj/renwu4_xin");
		me->add("combat_exp",500);
		me->UpdateMe();
		tell_object(me, "\n$HIR你完成了“替郁达夫送信”的任务，获得了500点的经验奖励。\n");
		call_out(do_wanxuanhuei, 1);
	}
	return 1;
}


static void do_wanxuanhuei(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env ;
	CNpc * wanxuanhuei;
	int i,j;
	env = load_room("武陵春捻金峰");
	if(!env->query("lj/wanxuanhuei"))
	{
		env->set("lj/wanxuanhuei",1);
		wanxuanhuei = load_npc("lj_shuxia");
		wanxuanhuei->move(env);

		env = load_room("武陵春雪鬓峰");
		if(!env->query("lj/wanxuanhuei"))
		{
			env->set("lj/wanxuanhuei",1);
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("武陵春雪柳谷");
		j=random(6)+6;
		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("武陵春簇带峰");
		j=random(6)+6;
		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("武陵春风鬓峰");
		j=random(6)+6;
		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("武陵春济楚谷");
		if(env->querymap("lj"))env->del("lj");
		j=11;
		static char ljdongzhu[11][20]={"lj_wulaoda","lj_duanmufang","lj_ganshuangqing","lj_hefueren","lj_hedongzhu",
			"lj_andongzhu","lj_qingdaozhu","lj_qudaozhu","lj_yundaozhu","lj_zhuyadaguai","lj_zhuyaerguai"};

		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc(ljdongzhu[i]);
			wanxuanhuei->move(env);
		}
	}

}

NPC_END;




