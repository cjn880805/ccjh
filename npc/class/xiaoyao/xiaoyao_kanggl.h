// xiaoyao_kanggl.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxiaoyao_kanggl);

virtual void create()
{
	set_name("康流水","kang guangling");
	set("long", "只见他白发童颜，容貌奇古，笑眯眯的脸 极为和蔼，手中抱着一具瑶琴。 ");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);
 	set("icon",old_man1);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 60);
	set("combat_exp", 200000);
	set("score", 50000);
	
	set_skill("blade",100);
	set_skill("xiaoyao_dao",100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("lingboweibu", 100);
	set_skill("beiming_shengong",100);
	set_skill("liuyang_zhang", 100);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("blade", "xiaoyao_dao");
	
	set("book_count", 1);
	
	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","琴颠");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
	set("no_talk",1);
	set("no_huan",1);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() )
	{
		if(me->query_temp("xy/renwu1_8") && !me->query_temp("xy/renwu1_81"))
		{
			tell_object(me,"\n虽然你一路未歇，但仍未能赶上七夕之约。此时逍遥林内冷冷清清，想必大伙都已散去了。\n");
			me->set_temp("xy/renwu1_81",1);//七夕相聚结束
		}
		else if( me->query_temp("xy/renwu1_6") && !me->query_temp("xy/renwu1_61")) 
		{
			tell_object(me,"\n只见康流水正在抚琴，且抚抚停停，断断续续，时时摇头。");
			tell_object(me,"你见到便上前相询，原来康流水尝闻嵇康死后《广陵散》便从此绝响，每念及此，总会遗憾万分。\n");
		}
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("base_name"), "musicbook1") && EQUALSTR(ob->querystr("skill/name"), "music")
		&& who->query_temp("xy/renwu1_6") && !who->query_temp("xy/renwu1_61") )
	{
		destruct(ob);
		tell_object(who,"$HIC康流水惊讶地“啊”了一声！");
		tell_object(who,"$HIC康流水由衷地向你表示感谢！");
		tell_object(who,"\n你道出来意，康流水微一沉吟，便道：“烦劳转告我的其他师兄弟，今年$HIC七夕聚于逍遥林$COM。”\n");
		who->set_temp("xy/renwu1_61",1);//通知康流水参加七夕相聚
		return 1;
	}
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		AddMenuItem("向康流水请教关于棋谱的问题", "qipu",me);	
		AddMenuItem("向康流水请教关于禁令的问题", "jingling",me);

		if(me->query_temp("xy/renwu1_81") && !me->query_temp("xy/renwu1_82"))
		{
			AddMenuItem("向康流水致歉","zhiqian",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qipu") )
	{
		CContainer *obj;
		if (query("book_count") < 1)
			say("你来晚了，棋谱我已经赠送给别入了。",me);   
		else
		{
			add("book_count", -1);                  
			say("好吧，那我就把它送给你了。 ", me);
			message_vision("康流水微笑着从怀中拿出了一本书，交了给$N  ",me);
			obj=load_item("hand_book");//棋谱
			obj->move(me);
			say("这本棋谱可千万不要随便给别人。 ", me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if (DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			say("你不是我们逍遥派的门人，打听这些做什么？",me);
		}
		else if(me->query_temp("xiaoyao/禁令")==5)
		{
			me->add_temp("xiaoyao/禁令",1);
			say( "师祖禁止我们使用「刀神一笑」，其实全是为了我们好，是怕给丁春秋这个恶贼知道了。",me);
		}
		else
		{
			me->delete_temp("xiaoyao/禁令");
			say("「刀神一笑」我没见到谁用过，不过听师傅说过，这招是「逍遥刀」中最厉害的一招。",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "zhiqian") )
	{
		if(me->query_temp("xy/renwu1_81") && !me->query_temp("xy/renwu1_82"))
		{
			if(!me->query_temp("xy/renwu1_82") )
				me->set_temp("xy/renwu1_82",1);//康流水告之石甘露在找自己
			if(EQUALSTR(me->querystr("family/family_name"), "逍遥派")&& EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))//逍遥弟子
				say("康流水呵呵一笑，道：“石师妹一直惦记着师叔，请无论如何都要去见她一面。”",me);
			else
				say(snprintf(msg, 255,"康流水呵呵一笑，道：“石师妹一直惦记着%s，请无论如何都要去见她一面。”",query_respect(me)),me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me, ask);

}
NPC_END;




