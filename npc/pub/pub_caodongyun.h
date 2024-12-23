//pub_caodongyun.h
//无情 2002、2、10

NPC_BEGIN(CNpub_caodongyun);

void create()
{
	set_name("曹东云", "cao dong yun");

	set("icon", taoist_with_sword);
	set("gender", "男性");
	set("level", 80);

	set("max_hp", 30000);
	set("max_mp", 4000);
	set("mp_factor", 80);

	set("combat_exp", 2300000);

	set("cast_chance", 40);
//	set("nkgain", 300);

	set("str", 33);
	set("con", 37);
	set("int", 35);
	set("dex", 36);

	set_skill("zhanjiang_jue", 276);
	set_skill("club", 276);
	set_skill("changquan", 276);
	set_skill("cuff", 276);
	set_skill("guimei_shenfa", 276);
	set_skill("dodge", 276);
	set_skill("hunyuan_yiqi", 276);
	set_skill("force", 276);

	map_skill("club", "zhanjiang_jue");
	map_skill("cuff", "changquan");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");

	prepare_skill("cuff", "changquan");

	set("apply/armor", 220);
	set("apply/damage", 150);
	set("no_kill",1);//不被列入万劫谷的任务中

	carry_object("tieqiao")->wield();

}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("club killyou", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	case 4:
		perform_action("force recover", 0);
		break;
	case 5:
		perform_action("force recover", 0);
		break;
	case 6:
		perform_action("force recover", 0);
		break;
	case 7:
		perform_action("force recover", 0);
		break;
	case 8:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}
virtual void die()
{
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}
NPC_END;



