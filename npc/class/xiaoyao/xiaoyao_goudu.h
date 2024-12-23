// xiaoyao_goudu.c

//code by Fisho
//date:2000-12-22

/*
Edit by wolfman 2001-6-28
修正论语无法拿取的问题，只能拿一次
*/

NPC_BEGIN(CNxiaoyao_goudu);

virtual void create()
{
	set_name("孔乙已",  "gou du");
	set("long", "他看上去也是几十岁的人了，却是纯然一个书呆子的模样。 ");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);
 	set("icon",old_man1);
	
	set("max_hp", 2400);
	set("mp", 800);
	set("max_mp", 800);
	set("mp_factor", 60);
	set("combat_exp", 150000);
	set("score", 40000);
	
	set_skill("blade",60);
	set_skill("xiaoyao_dao",60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("lingboweibu", 60);
	set_skill("beiming_shengong",60);
	set_skill("zhemei_shou", 60);
	
	map_skill("unarmed", "zhemei_shou");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("blade", "xiaoyao_dao");
	
	set("book_count", 1);
	
	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","书呆");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();		//blade modified to gangdao, lanwood 2000-12-30
	set("no_talk",1);
	set("no_huan",1);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() && me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_64")) 
	{
		tell_object(me,"\n孔乙己拉着你问道：“‘同心之言，其臭如兰，’这个‘臭’字，该作何解释？”\n");
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "「易经系辞篇」") && EQUALSTR(ob->querystr("skill/name"), "qimen_wuxing")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_64") && !who->query_temp("xy/renwu1_640") )
	{
		destruct(ob);
		tell_object(who,"\n你对孔乙己说道：“这是易经系辞篇的言辞，臭即为嗅的意思，如果尊驾想更进一步研究的话，这本系辞篇就送你吧。”\n");
		who->set_temp("xy/renwu1_640",1);//给孔乙己一本易经系辞篇
		return 1;
	}
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("向孔乙己请教关于论语的问题", "lunyu",me);	
		AddMenuItem("向孔乙己请教关于刀中的秘密的问题", "jingling",me);

		if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_640") && !me->query_temp("xy/renwu1_64"))
		{
			AddMenuItem("转告孔乙己关于七夕相聚之事","qixi",me);
		}
		SendMenu(me);
	}
	else if(!strcmp(ask, "lunyu") )
	{
		CContainer *obj;
		CContainer * r = load_room("逍遥林小道2");
		
		if(EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv") && (r->query_temp("no_book")==1))
		{
			r->add_temp("no_book",-1);
			say("师叔想要《论语》，拿去就是。",me);
			message_vision("孔乙已从怀里掏出一本旧书，交了给$N。 ",me);
			obj=load_item("literateb4");//论语
			obj->move(me);
			say("这本书可千万不要借给别人啊，他们一借就不还的了。 ", me);
			SendMenu(me);
			return 1;
		}
		else if (query("book_count") < 1)
		{
			say( "你来晚了，那本《论语》我已经赠送给别人了。",me); 
			SendMenu(me);
			return 1;
		}
		else
		{
			add("book_count", -1);                  
			say("哈哈，《论语》就没有了，这里还有我派高手从少林窃来的书。窃书不能算偷", me);
			say("既然你那么好学，我就把它送给你吧。 ", me);
			message_vision("孔乙已翻箱倒柜找了半天，找出一本旧书，交了给$N。",me);
			
			if (random(2) == 1) 
				obj=load_item("strike_book");//掌法总谱
			else 
				obj=load_item("book_paper");//易筋经文学篇
			obj->move(me);
			
			say("茴字有三种写法，你知道几种？ ", me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			say("你不是我们逍遥派的门人，打听这些做什么？",me);
		}
		else if(me->query_temp("xiaoyao/禁令")==3)
		{
			me->add_temp("xiaoyao/禁令",1);
			say("「逍遥刀」中的秘密，听说和师祖年青时的一段感情纠葛有关。具体是怎么缘故，也许只有师傅知道！",me);
		}
		else
		{
			me->delete_temp("xiaoyao/禁令");
			say( "师祖不允许我们使用「逍遥刀」中的绝招，作为弟子，我们自当遵守才是。",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61")&& me->query_temp("xy/renwu1_640") )
		{
			if(!me->query_temp("xy/renwu1_64") )
				me->set_temp("xy/renwu1_64",1);//通知孔乙己参加七夕相聚
			say("只见孔乙己却拿着那本系辞篇沉醉的看了起来，也不知道有没有听到你所说的话。",me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me, ask);
}
NPC_END;




