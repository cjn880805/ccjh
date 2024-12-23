// meizhuang_danqingsheng.c 
//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNmeizhuang_danqingsheng);

virtual void create()
{
	set_name("碧血汗青", "danqing sheng");
	set("title", "梅庄四庄主");
	set("long","他就是梅庄四位庄主排行第四的汗青生。身穿一件干干净净的青色长袍。他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。");
	set("gender", "男性");
	set("age", 40);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
 	set("icon",old_man2);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	set("combat_exp", 300000);
	set("repute", 15000);
	set("score", 60000);
	set("item_count", 1);
	
	set_skill("force", 100);
	set_skill("wuzheng_xinfa", 120);
	set_skill("dodge", 100);
	set_skill("piaoyibu", 110);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("wuyun_jianfa", 100);
	set_skill("literate", 130);
	
	map_skill("force", "wuzheng_xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun_jianfa");
	map_skill("sword", "wuyun_jianfa");
	
	create_family("梅庄", 1, "庄主");

	set_inquiry("东方爱莲","东方教主文成武德，千秋万载，一桶浆糊。");
	set_inquiry("任无月","……。");
	set_inquiry("梅花令","梅花令乃我梅庄信物。");
//	set_inquiry("令牌",ask_me);
	carry_object("changjian")->wield();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query("repute") < 0) 
	{
		say("我梅庄虽然不是什么名门正派, 但择徒也极为严格。", ob);
		say(snprintf(msg,255,"在品行方面，%s是否还做得不够？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query_skill("wuzheng_xinfa",1) < 30) 
	{
		say("我是不轻易收徒的。", ob);
		say(snprintf(msg,255,"在我梅庄的内功上，%s是否还应该多下点功夫？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	say("好吧，在下就收下你了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}


virtual int prevent_learn(CChar * me, const char * arg)
{
	if (me->query_temp("teapot/plum") == 1 )
        message_vision("碧血汗青看了看$N，说道：我已经实现了当年的诺言，现在不用再教你什么了。", me);

    me->add_temp("teapot/plum", -1);
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
    
    if (! me->query_temp("teapot/plum"))
        return 0;

    return 1;
}

virtual int accept_object(CChar * me , CContainer * item)
{
	
	if ( EQUALSTR(item->querystr("base_name"), "meihualing" ))
	{
		if (!me->query_temp("teapot/plum")) 
			me->set_temp("teapot/plum",4);
		
		message_vision("碧血汗青看了看$N的梅花令，说道：既是如此，你可从我这里学点东西。", me);;
		me->add_temp("teapot/plum", 4);
		destruct(item);
		return 1;
	}

	if (item->query("ry/menpiao") &&  EQUALSTR(item->querystr("owner1"), me->id(1)))
	{
		if (me->query_temp("ry/renwu1_1")) 
		{
			char msg[255];
			say(snprintf(msg,255,"碧血汗青看了看你递过来的「%s」，说道：咦！这个宝贝真的肯送给我吗？一定有什么企图，你就老实说吧！”",item->querystr("name")), me);
			me->set_temp("ry/renwu1_2",4);//送给四庄主门票
			SendMenu(me);
			destruct(item);
			return 1;
		}
	}
	return 0;
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu1_2") ==4)
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问关于前教主被关押的事","jiaozhu",me);
			AddMenuItem("就是白送的！希望你喜欢","song",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "jiaozhu") )
		{
			tell_object(me,"\n$HIR碧血汗青脸色顿时阴了下来，哼道：“看你来时鬼鬼祟祟的就知道没安好心，果然不出所料是来找那个老家伙的！废话少说，看招吧！”\n");
			((CUser *)this)->Ready_PK();
			((CUser *)me)->Ready_PK();
			me->kill_ob(this);	
			this->kill_ob(me);
			set("owner",me->object_id());
		}
		else if(!strcmp(ask, "song") )
		{
			say("碧血汗青笑说道：“不错不错！”",me);
			tell_object(me,"\n$HIC你完成了送票的任务，得到金钱50元的奖励。\n");
			me->delete_temp("ry");
			me->delete_temp("no_fei");
			CMoney::Pay_Player(me, 50);
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual void die()
{
	if(query("owner"))
	{
		CChar * killer;
		CChar * owner;
		if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
		{
			//检查owner
			owner = (CChar *)find_object(query_temp("fight/owner"), 1);
			if(owner && owner->query_temp("fight/will_nk") == object_id())
				killer = owner;
			
			CContainer * obj = load_item("baozi");
			obj->set_name("水下石室钥匙","yao si");
			obj->set("long","这是一枚钥匙。");
			obj->set("owner1",killer->id(1));
			obj->set("ry/yaosi",1);
			obj->move(environment());
		}
	}
	CNpc::die();
}

/*static char * ask_me(CNpc *who,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (!(me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "梅庄"))
		//return query_respect(me) +"与本派素无来往，不知此话从何谈起？";
		return  snprintf(msg,255,"%s与本派素无来往，不知此话从何谈起？",query_respect(me) );

	if (who->query("item_count") < 1)
		return "你来晚了，梅花令牌不在此处。";
	who->add("item_count", -1);
	obj = load_item("meihualing");//梅花令 lanwood 2000-12-28
	obj->move(me);
	return "好吧，这块梅花令牌就交给你保管了。";
}*/ 

NPC_END;