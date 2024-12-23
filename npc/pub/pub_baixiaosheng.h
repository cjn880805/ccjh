// pub_baixiaosheng 百晓生
//秦波 2002、3、5

NPC_BEGIN(CNpub_baixiaosheng);

virtual void create()
{
	set_name("百晓生", "bai xiao sheng");
	set("gender", "男性");
	set("age", 45);
	set("icon",triggerman2);
	
	set("combat_exp", 7000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	set("no_talk",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	CContainer * bot;
	if(me->query_temp("gumu/jq_gu"))
	{
		say("你已经通过了考验，绝情谷在长白山一带,快点去那里吧。", me);
	}
	else if(me->query_temp("gumu/jq_dan"))
	{
		if(me->query_temp("gumu/jq_kill"))
		{
			if(me->query_temp("gumu/jq_kill")<5)
			{
				if(me->query_temp("gumu/jq_renwu")==1)
					say(snprintf(msg, 255, "帮我杀了%s(%s)吗？", me->querystr_temp("gumu/kill_name"),me->querystr_temp("gumu/kill_id")), me);
				else
				{
					me->add_temp("gumu/jq_kill",1);
					me->add_temp("gumu/jq_renwu",-do_jq_kill(me));
				}
			}
			else
			{
				say("哈哈哈，我的武林名人谱上终于完成了。",me);
				say("好好好，你的表现不错，已经通过了考验，这把钥匙你拿去，绝情谷在长白山一带。", me);
				bot = load_item("anjinmenkey");
				bot->set("owner",me->querystr("id"));
//				bot->set_name(snprintf(msg, 40, "%s的镖旗", me->name(1)));
				bot->move(me);
				me->delete_temp("gumu/jq_dan");
				me->delete_temp("gumu/jq_kill");
				me->delete_temp("gumu/jq_renwu");
				me->set_temp("gumu/jq_gu",1);
			}
		}
		else
		{
			if(! strlen(ask))
			{
				AddMenuItem("询问[绝情谷]的位置", "wen", me);
			}
			else if(strcmp(ask, "wen") == 0)
			{
				say("你想去绝情谷，那里危险的很啊！你真的愿意去？", me);
				AddMenuItem("愿意", "y", me);
				AddMenuItem("算了还是下次吧", "n", me);
			}
			else if(strcmp(ask, "y") == 0)
			{
				me->set_temp("gumu/jq_kill",1);
				say("那你先帮我去杀掉几个人，让我看看你的实力吧！", me);
				me->set_temp("gumu/jq_renwu",do_jq_kill(me));
			}
			else if(strcmp(ask, "n") == 0)
			{
				say("呵呵，看起来你还得多增加点胆色才成啊。", me);
				me->delete_temp("gumu/jq_dan");
			}
		}
	}
	SendMenu(me);
	return 1;
}
int do_jq_kill(CChar * me)
{
	static struct{
		char name[20];
		char id[20];
		int  exp;			
	} lvlmax[5] = {			
		{"卓一行","zhun yi hang", 60,},
		{"水云烟", "shui yun yan", 60,},
		{"李秋痕", "li qiou hen", 60,},
		{"独孤求", "du gu qiu", 60,},
		{"宁月", "ning yue", 60,},
	};

	char msg[255];
	const char * shuiname = "";
	const char * shuiid = "";
	int shuiexp = 0;

	int task = me->query_temp("gumu/jq_kill")-1;
	shuiname=lvlmax[task].name;
	shuiid=lvlmax[task].id;
	shuiexp=lvlmax[task].exp;
	
	me->set_temp("gumu/kill_name",shuiname);
	me->set_temp("gumu/kill_id",shuiid);

	if(!me->query_temp("gumu/jq_renwu"))
		say(snprintf(msg, 255, "百晓生说：既然你对自己很有信心，那么你就去帮我把%s(%s)杀了吧！", shuiname, shuiid), me);
	else
	{
		say("百晓生说：不错不错，我的武林名人谱上又可以勾掉一笔了。", me);
		say(snprintf(msg, 255, "百晓生说：不过我对你的能力还是有点不放心，你再去帮我把%s(%s)杀了吧！", shuiname, shuiid), me);
	}
	int exp=shuiexp+random(shuiexp);
	exp=exp+(me->query("level")-50)*2/3;
	me->set_temp("gumu/kill_exp", exp);

	return 1;
}
NPC_END;