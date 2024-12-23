// pub_huqingyu.c

// code by Fisho
// date:2000-12-17
//inherit F_CLEAN_UP;
char * check_legal_name(const char * name);

NPC_BEGIN(CNpub_huqingyu);

virtual void create()
{
	set_name("胡庆余", "hu qingyu");

	set("icon", pawnshop_boss);
	set("gender", "男性" );
	set("age", 63);
	set("long","胡庆余是当世一大巫医，他的本事神奇无比。真有生死肉骨之功。");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	say("我包办改名，判师，这个价格嘛...!嘿嘿,一律一百万金。", me);
	AddMenuItem("改名", "$2name $1 $2", me);
	AddMenuItem("叛师", "$0beipan $1", me);
	SendMenu(me);
	
	return 1;
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "胡庆余翘着二郎腿:要想唤回你们的青春,拿出你的诚意来!!";
	case 1:
		return "胡庆余冷笑道:要叛师? 容易。快快拿出你的银子来!";
	case 2:
		return "胡庆余淡淡说道:改个名,就是新人了。";
	}
	return "";
}
/*
virtual void init(CChar *me)
{
	CChar * ob;
	add_action("do_name","name");
	add_action("do_beipan","beipan");
//  add_action("do_age","age");
}
*/
virtual int handle_action(char * comm, CChar * me, char *arg)
{
	if(strcmp(comm, "name") == 0)
		return do_name(arg, me);
	if(strcmp(comm, "age") == 0)
		return do_age(me);
	if(strcmp(comm, "beipan") == 0)
		return do_beipan(me);

	return 0;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	char msg[255];
	if( EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000000)
	{
		command("nod");
        say(snprintf(msg,255," 好吧，%s你说个章程！",me->name() ), me);
        me->set_temp("marks/huqingyu",1);
		AddMenuItem("我想改名。", "$2name $1 $2", me);
		AddMenuItem("我想判师。", "$0beipan $1", me);
//		AddMenuItem("我想改年龄。", "$0age $1", me);
		SendMenu(me);

	}
	destruct(ob);
	return 1;
}


int do_name(char * arg,CChar * me)
{
	if(! me->query_temp("marks/huqingyu"))
		return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？");

	if( strlen(arg) > 10 )
        return notify_fail("胡庆余惊呼起来：哪有这么长的名字？");
	
	if( strlen(arg) < 4 )
        return notify_fail("胡庆余哼了一声：这么短算啥名字？");

	char msg[255];
	
	strcpy(msg, check_legal_name(arg));

	if(msg[0])
	{
		return notify_fail(msg);
	}
		
	me->delete_temp("marks/huqingyu");
	if (EQUALSTR(me->querystr("gender"), "女性"))
        message_vision("胡大夫大笔一挥就改了$N的芳名 !真爽呆了...." ,me);
	else
        message_vision("胡大夫大笔一挥就改了$N的大名..真神!!" ,me);
	me->set_name(arg);
	me->UpdateMe();
	if(me->query("corps/level")==1)
	{
		CContainer * env = load_room(me->querystr("corps/id"));
		env->set("corps/owner_name",me->name());
		env->Save();
	}
	
	return 1;
}

int do_beipan(CChar * me)
{
	if(! me->query_temp("marks/351"))
	{
		me->set_temp("marks/351",1);
		return notify_fail("$HIR胡庆余翻着黑白眼：受贵派掌门委托，必须废掉你身上所有超过351级的技能以示惩戒，方可判出师门。\n你权衡一下再来找我。");
	}
	
	if(! me->query_temp("marks/huqingyu"))
	{
		return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？");
	}

	me->delete_temp("marks/huqingyu");
	me->delete_temp("marks/351");

	//if (me->query_combat_exp() < 10000)
	//	return notify_fail("真冤枉!!你的经验还可以随便叛师的! ");
	
	CMapping * skills = me->query_skills();
	CVector v;
	skills->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		if((*skills)[v[i]]>351) 
			(*skills)[v[i]] = 351;
	}
	//对逍遥派的处以清除内力的处罚
	if(EQUALSTR(me->querystr("family/family_name"), "逍遥派") )
	{
		int max_mp=me->query_skill("force",1) * 10+me->query_skill("beiming_shengong",1)*5;
		if(max_mp < me->query("max_mp"))
			me->set("max_mp",max_mp);
	}
	me->FlushMySkill(me);
	me->release_master();

	me->add("betrayer", 1);
	me->set("title","普通百姓");
	me->del("class");
	me->del("zhangmen");
	me->del("family");
	me->del("party");
	me->del("beggarlvl");

	me->UpdateMe();
    message_vision("胡大夫笑道: 江湖上海阔天空, 都是$N的天地了! " , me);
	
	return 1;
}

int do_age(CChar * me)
{
	if(! me->query_temp("marks/huqingyu"))
	{
		return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？");
	}
	me->delete_temp("marks/huqingyu");
	
	return notify_fail("胡庆余翻着黑白眼：年龄暂时就不考虑了！");
	
	if (me->query("mud_age")<864000)
	{
		return notify_fail("胡大夫道: 你还很年轻的, 这一百万金白花了! ");
	}
		
	return 1;
}

NPC_END;