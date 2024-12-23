//xy_shiganlu.h	“玉关八友”石甘露
//秦波 2002、12、2

NPC_BEGIN(CNxy_shiganlu);

void create()
{
	set_name("石甘露","shi ganlu");
	set("gender", "女性");
	set("age", 28);
	set("long","这是一个中年美妇，一身上下打扮得干净素雅，人也斯斯文文，发髻上还插着一朵浅蓝色的小花。");

	set("attitude", "peaceful");
	set("icon",young_woman10);

	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("per", 20+random(6));
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("hand", 50);
	set_skill("lingboweibu", 50);
	set_skill("beiming_shengong",50);
	set_skill("liuyang_zhang", 50);
	set_skill("zhemei_shou", 50);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");
	
	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","花伶");
	set("no_huan",1);

};

void init(CChar * me)
{
	CNpc::init(me);
	if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_62") && me->query_temp("xy/renwu1_63")
		&& me->query_temp("xy/renwu1_64") && me->query_temp("xy/renwu1_65") && me->query_temp("xy/renwu1_66")
		&&!me->query_temp("xy/renwu1_7"))
	{
		//如果已经完成以上找人任务，再找到石甘露，她就会把养成的“红装素裹”交给玩家
		CContainer * bot = load_item("redrose");
		bot->set_name("红装素裹", "hong zhuang");
		bot->set("long","一盆叶翠枝秀的茶株，上面结着几朵白色的茶花，每朵茶花的花瓣上还缀洒着点点红斑。");
		bot->set("value", 1);      
		bot->set("unit", "株");
		bot->move(me);
		tell_object(me,"\n$HIC石甘露小心地捧出一盆已经盛开的「红装素裹」交给了你。\n石甘露微微笑道：“这盆花，可真费了我不少心思，现在要送给你，我都有些舍不得了！”");
		me->set_temp("xy/renwu1_670",1);
		me->set_temp("xy/renwu1_7",1);//“红装素裹”已经养成，可以给王夫人了。
	}
	else if (me->query_temp("xy/renwu1_3")  && !me->query_temp("xy/renwu1_42")&& !me->query_temp("xy/renwu1_4")) 
	{
		//set("昏迷",1);
		//disable_player("昏迷中");
		//set("apply/name","石甘露<昏迷中>");
		//UpdateMe();
		//set_weight(50000000);
		tell_object(me,"\n$HIC你看到蝴蝶泉边倒着一个中年妇人，看样子似乎正是你要找的人，只是她双目紧闭，好像已经昏迷过去了。\n");
		me->set_temp("xy/renwu1_31",1);//石甘露中毒昏迷
	}
}

virtual int do_look(CChar * me)
{
	if(me->query_temp("xy/renwu1_31") && !me->query_temp("xy/renwu1_42"))
	{
		say("她腿上有一处伤口，青紫色肿了一块，似是被何毒物所伤。", me);
		SendMenu(me);
		me->set_temp("xy/renwu1_4",1);//观察到石甘露中毒昏迷
		return 1;
	}
	
	return CChar::do_look(me);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("xy/renwu1_82") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("告诉石甘露关于寻找福地之事","fudi",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "fudi") )
		{
			say("石甘露说道：“大理城郊方圆不止千里，此去定然艰险万分！”",me);
			say("石甘露接着说道：“此乃我在山中寻得宝物，叫「银月之匙」，传说是能打开通往月宫之路的时空之匙，虽然略嫌迷信，但也是我的一番心意，请好好收藏。”",me);
			tell_object(me,"石甘露给了你数量1的银月之匙。");
			me->delete_temp("xy");
			me->del("xy/renwu1");
			me->set("xy/renwu2",1);//逍遥任务第二部分：取得银月之匙
			CContainer * bot = load_item("yingyue_si");
			bot->set("owner",me->id(1));
			bot->move(me);
			SendMenu(me);
		}
		return 1;
	}
	else if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_670"))
	{
		if(!me->query_temp("xy/renwu1_67"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("转告石甘露关于七夕相聚之事","qixi",me);
			}
			else if(!strcmp(ask, "qixi") )
			{
				char msg[255];
				if (me->query_temp("xy/renwu1_61")&& me->query_temp("xy/renwu1_670") )
				{
					if(!me->query_temp("xy/renwu1_67") )
						me->set_temp("xy/renwu1_67",1);//通知石甘露参加七夕相聚
					if(EQUALSTR(me->querystr("family/family_name"), "逍遥派")&& EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))//逍遥弟子
					{
						say("石甘露道：“我们八师兄妹此番相聚，全仰仗师叔之力，只望七夕之时，师叔也能赏光参加！",me);
					}
					else
						say(snprintf(msg, 255, "石甘露道：“我们八师兄妹此番相聚，全仰仗%s之力，只望七夕之时，%s也能赏光参加！",query_respect(me),query_respect(me)),me);
				}
				else
					say("石甘露很疑惑的看你。",me);
			}
			SendMenu(me);
		}
		return 1;
	}
	else if(me->query_temp("xy/renwu1_42") && !me->query_temp("xy/renwu1_43"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问关于栽种「红装素裹」的要领", "zai",me);	
		}
		else if(!strcmp(ask, "zai") )
		{
			say("石甘露含笑道：多谢这位大侠相救之恩，栽花这等小事，尽可放心交与我。？",me);
			me->set_temp("xy/renwu1_43",1);//石甘露答应种花
		}
		SendMenu(me);
		return 1;
	}
	else if(me->query_temp("xy/renwu1_5") && !me->query_temp("xy/renwu1_7"))
	{
		say("石甘露说道：“要将花种育好，仍需一段时间。而我现在却很想再见到其他七位师兄弟。不知恩公可否帮忙寻找，并请告诉大师兄康流水一声，定个时间相聚逍遥林，互诉别离。”",me);
		SendMenu(me);
		return 1;
	}
	else if(me->query_temp("xy/renwu1_31") && !me->query_temp("xy/renwu1_42"))
	{
		switch(me->query_temp("xy/renwu1_32"))
		{
		case 0:
			say("对方显然无法和你讲话。", me);
			me->add_temp("xy/renwu1_32",1);
			break;
		case 1:
			say("你轻轻推了推石甘露，但见她双目紧闭，没有半点清醒过来的意思。", me);
			me->add_temp("xy/renwu1_32",1);
			break;
		case 2:
			say("石甘露腿上的毒气似乎还在不断扩散，若不再及时救治，恐有性命之忧。", me);
			me->add_temp("xy/renwu1_32",1);
			break;
		case 3:
			say("正在你一筹莫展之时，突然想起逍遥谷中那位“药到命除”的薛神医，也不知他会不会有什么办法！", me);
			break;
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "花种") && EQUALSTR(ob->querystr("id"), "hua zhong")
		&& me->query_temp("xy/renwu1_43") && !me->query_temp("xy/renwu1_5") )
	{
		destruct(ob);
		say("石甘露向你询问道：“不知恩公用何药物解我所中之毒？” ",me);
		say("你如实回答说是「解毒清心丸」。 ",me);
		say("石甘露竟一阵晕眩，失声道：“原来是薛师兄，想我“函谷八友”，只因一个不得已的原因而分散各地。如今却机缘巧合，竟会是多年未见的师兄救我一命！”",me);
		say("石甘露说道：“要将花种育好，仍需一段时间。而我现在却很想再见到其他七位师兄弟。不知恩公可否帮忙寻找，并请告诉大师兄康流水一声，定个时间相聚逍遥林，互诉别离。”",me);
		SendMenu(me);
		me->set_temp("xy/renwu1_5",1);//答应石甘露寻找函谷八友
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(me->query_temp("xy/renwu1_31") && !me->query_temp("xy/renwu1_42"))
	{
		if(!strcmp(comm, "fight") )
		{
			tell_object(me,"石甘露已经无法战斗了。");
			return 1;
		}
		else if(!strcmp(comm, "apprentice")  )
		{
			tell_object(me,"你必须先把石甘露弄醒。");
			return 1;
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;




