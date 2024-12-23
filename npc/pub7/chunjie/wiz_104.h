
NPC_BEGIN(CNwiz_104);

void create()
{
	set_name("寒雨", "han yu");
	
	set("title", "贺岁使者");
	set("long","这就是104寒雨巫师，他抱着一堆礼物，正愁眉苦脸的不知道该怎么分呢！");
	
	set("icon", young_man5);
	set("per",40);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 24);

	set("chat_chance", 3);
	call_out(do_lidan, 900);
	set("no_kill",1);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "寒雨愤怒地说道：“那些可恶的礼物强盗，我要将他们碎撕万段！”";
	case 1:
        return "寒雨叹了口气：“谁要是帮我找回了礼单，我一定好好谢谢他！”";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!me->query("chunjie/104/ok"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("拜年","bai",me);
			AddMenuItem("礼单","lidan",me);
		}
		else if(!strcmp(ask, "bai") )
		{
			say("寒雨笑了笑：“新年快乐！你要是帮我找回了礼单，我就更快乐了！”",me);
		}
		else if(!strcmp(ask, "lidan") )
		{
			say("寒雨高兴地说道：“啊，你找到我的礼单了？快拿给我看看！”",me);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "礼单碎片") && EQUALSTR(ob->querystr("id"), "li dan") && !query("stop"))
	{
		destruct(ob);
		char msg[255];
		int exp;
		static char baowu[24][20]={"taibaizao","38huoqiang","diaojiandai","jinhuantoushi","btzheng",
		"xuantiebishou","bolanxie","haoseshan","xiantianyu","poliquan","fannaomao","shajiezhi","tiancanbaojia",
		"newyear","newyear1","zidiaopifeng","liaochengpao","dagoubang","yinguozhu","dulonglian","shenshe_staff",
		"ruanweijia","zhangmenhuan","yinmopao"};

		if( !me->query("chunjie/104/ok"))
		{
			if(me->query("chunjie/104/count")==166)
			{
				me->add("chunjie/104/count",1);
				tell_object(me,"\n$HIC寒雨高兴得点了点头：“拼出来不少了，谢谢你！送份小礼物给你，聊表谢意！祝你新年快乐！”");
				load_item(baowu[random(24)])->move(me);
			}
			else if(me->query("chunjie/104/count")==666)
			{
				me->set("chunjie/104/ok",1);
				me->del("chunjie/104/count");
				tell_object(me,"\n$HIC寒雨高兴得跳了起来：“哎呀，太谢谢了，这下礼单齐了！这礼单上的头份礼物就送给你吧！”");
				load_item("ytjian")->move(me);
			}
			else
			{
				me->add("chunjie/104/count",1);
				tell_object(me,snprintf(msg, 255,"\n$HIC寒雨皱了皱眉头：“可惜，只找到了%d张碎片，不过还是要谢谢你，这点小意思，就请收下吧！”",me->query("chunjie/104/count")));			
				if(me->query("level")>10)
					exp=random(81)+100+me->query("chunjie/104/count")/2;
				else
					exp=1;
				me->add("combat_exp",exp);
				tell_object(me,snprintf(msg,255,"$HIR你获得了%d点的经验奖励。\n", exp));
			}
		}
		else
		{
			tell_object(me,"\n$HIC寒雨笑呵呵道：“今天还有很多人要来我领礼物呢，你既然已经领过了，就把机会留给别人吧！”");	
		}
		return 1;
	}
	return 0;
}

static void do_lidan(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;

	int index=random(MAX_ROOM_NUM);
	CContainer * env = load_room(global_room_name[index]);
	g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "强盗在%s出现了。",env->querystr("base_name")));
	g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "$HIR猛然间，%s窜出几个人来，高呼：屋子里面的人听着，男的站左边，女的站右边！大爷们现在开始打劫！打劫！打劫！\n",env->querystr("base_name")));

	for(int i=0;i<6;i++)
		load_npc("pub_qiangdao")->move(env);

	me->call_out(do_lidan, 900);
}
NPC_END;
