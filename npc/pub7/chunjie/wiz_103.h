
int valid_string(const char * msg);

NPC_BEGIN(CNwiz_103);

void create()
{
	set_name("蚀月", "shi yue");
	
	set("title", "红娘");
	set("long","这是蚀月巫师，这会儿她身着一袭红裳，正笑盈盈地看着你，有如戏里红娘的模样。");
	
	set("icon", young_woman1);
	set("per",40);
	
	set("gender", "女性");
	set("level", 300);
	set("age", 19);

	set("no_kill",1);

	set("chname", "比武招亲");
	set("channel", "f1");
	set("grant", 95);

	set("wait_time",3600);
	set("wait_time_biwu",5);

	set("biwu/name", "比武招亲大会");
	set("biwu/register/0", "空缺");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

	Load();

	reset();
	set("no_huan",1);
}

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}

int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}

void reset()
{
	if(query("start"))
		call_out(do_gonggao, 10);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(! is_fighting() && userp(me))
	{
		char msg[255];
		tell_object(me,snprintf(msg, 255,"蚀月说道：“千里姻缘一线牵，这位%s可是想通过比武招亲，来寻找红线那一头的姻缘？”",query_respect(me)));
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		if(!querystr("zhaoqing/owner")[0])
			AddMenuItem("发布招亲通告","zhaoqing",me);
		else if(me->query("chunjie/103/zhaoqing") && EQUALSTR(me->id(1),querystr("zhaoqing/owner")))
		{
			if(query("start"))
			{
				if(query("zhaoqing/wait_time"))
					AddMenuItem("查看报名名单","chakan",me);
				else
					AddMenuItem("查看当前入围选手名单","chakan",me);
			}
			AddMenuItem("设置自我介绍","jieshao",me);
			AddMenuItem("查看自我介绍","ck_js",me);
			if(!query("start"))
				AddMenuItem("设置招亲条件","tiaojian",me);
			AddMenuItem("查看招亲条件","ck_tj",me);
			if(!query("start"))
				AddMenuItem("正式开始招亲","start",me);
		}
		else if(query("start"))
		{
			AddMenuItem("查看招亲者资料","ck_js",me);
			AddMenuItem("查看招亲条件","ck_tj",me);
			if(query("zhaoqing/wait_time"))
			{
				AddMenuItem("查看报名名单","chakan",me);
				if(! has_register(me) )
					AddMenuItem("我要报名", "baoming", me);
				else
					AddMenuItem("取消报名", "cancel", me);
			}
			else
				AddMenuItem("查看当前入围选手名单","chakan",me);
		}
	}
	else if(!strcmp(ask, "zhaoqing") && !query("stop"))
	{
		if(!me->query("chunjie/103/ok"))
		{
			if(!me->query("chunjie/103/zhaoqing"))
			{
				if(!me->query_temp("chunjie/103/coin"))
					say("蚀月说道：“我可不能白帮人做媒哦，只要1666666两银子，我就为你布置一场比武招亲擂台赛！”",me);
				else
				{
					say("蚀月微微一笑：“姻缘簿上又将添上一笔，祝你早日找到属于自己的姻缘。你可以通过查看招亲者资料来查看你自己的情况！”",me);
					me->set("chunjie/103/zhaoqing",1);//开始招亲
					set("zhaoqing/owner",me->id(1));//设置招亲对象id
					set("zhaoqing/name",me->name(1));//设置招亲对象名称
					set("zhaoqing/gender",me->querystr("gender"));//设置招亲对象性别
				}
			}
			else
			{
				say(snprintf(msg, 255, "蚀月微微一笑：“这位%s，你不是已经在招亲吗？”",query_respect(me)),me);
			}
		}
		else
		{
			say(snprintf(msg, 255, "蚀月微微一笑：“这位%s，你不是已经招过亲了吗？”",query_respect(me)),me);
		}
	}
	else if(!strcmp(ask, "ck_js") && !query("stop") )
	{
		if(querystr("zhaoqing/描述")[0])
			say(querystr("zhaoqing/描述"),me);
		else
			say("暂无介绍。",me);
	}
	else if(!strcmp(ask, "ck_tj")&& !query("stop"))
	{
		string tj;
		tj = snprintf(msg, 255, "%s(%s)[%s]的招亲要求：\n",querystr("zhaoqing/name"),querystr("zhaoqing/owner"),querystr("zhaoqing/gender"));
		switch(query("zhaoqing/魅力要求"))
		{
		case 0:
			tj+= "1、魅力：不在意外表相貌如何。\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "1、魅力不低于：%d。\n",query("zhaoqing/魅力"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "1、魅力不高于：%d。\n",query("zhaoqing/魅力"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "1、魅力等于：%d。\n",query("zhaoqing/魅力"));
			break;
		}
		switch(query("zhaoqing/年龄要求"))
		{
		case 0:
			tj+= "2、年龄：只要年满18岁成年就行。\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "2、年龄不低于：%d。\n",query("zhaoqing/年龄"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "2、年龄不高于：%d。\n",query("zhaoqing/年龄"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "2、年龄等于：%d。\n",query("zhaoqing/年龄"));
			break;
		}
		switch(query("zhaoqing/财产要求"))
		{
		case 0:
			tj+= "3、财产：有没有钱我都不在乎。\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "3、财产不低于：%d。\n",query("zhaoqing/财产"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "3、财产不高于：%d。\n",query("zhaoqing/财产"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "3、财产等于：%d。\n",query("zhaoqing/财产"));
			break;
		}
		switch(query("zhaoqing/婚史要求"))
		{
		case 0:
			tj+= "4、婚史：过去的事情我不在意。\n";
			break;
		case 1:
			tj+= "4、婚史：只准爱我一个人。\n";
			break;
		case 2:
			tj+= "4、婚史：结过一次婚我不在意。\n";
			break;
		case 3:
			tj+= "4、婚史：结过二次婚我也不在意。\n";
			break;
		}
		switch(query("zhaoqing/总经验要求"))
		{
		case 0:
			tj+= "5、总经验：武功高低无所谓。\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "5、总经验不低于：%d。\n",query("zhaoqing/总经验"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "5、总经验不高于：%d。\n",query("zhaoqing/总经验"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "5、总经验等于：%d。\n",query("zhaoqing/总经验"));
			break;
		}
		switch(query("zhaoqing/声望要求"))
		{
		case 0:
			tj+= "6、声望：只要是对我真心的就行。\n";
			break;
		case 1:
			tj+=snprintf(msg, 255, "6、声望不低于：%d。\n",query("zhaoqing/声望"));
			break;
		case 2:
			tj+=snprintf(msg, 255, "6、声望不高于：%d。\n",query("zhaoqing/声望"));
			break;
		case 3:
			tj+=snprintf(msg, 255, "6、声望等于：%d。\n",query("zhaoqing/声望"));
			break;
		}
		switch(query("zhaoqing/方外人士要求"))
		{
		case 0:
			tj+= "7、方外人士：这个。。我不喜欢。\n";
			break;
		case 1:
			tj+= "7、方外人士：这点我不在乎。\n";
			break;
		case 2:
			tj+= "7、方外人士：既出家，何又恋红尘？\n";
			break;
		}
		say(tj.c_str(),me);
	}
	else if(!strcmp(ask, "chakan") && !query("stop"))
	{
		int state = query("state");
		char cmd[20];
		if(query("state"))
		{
			for(int i=0; i<=state; i++)
			{
				AddMenuItem(snprintf(msg, 255, "查看第%ld轮对阵形势", i), 
					snprintf(cmd, 20, "$0lookup $1 %ld", i), me);	
			}
		}
		else
		{
			CMapping * team = querymap("biwu/register");
			if(team)
			{
				CVector v;
				team->keys(v);
				int num=1;
				tell_object(me, "\n$HIR------------------比武招亲入围榜------------------");
				for(int i=0; i<v.count(); i++)
				{
					if(EQUALSTR(team->querystr(v[i]), "空缺") )
						continue;
					tell_object(me, snprintf(msg, 255, "                  %d、%s(%s)",num,team->querystr(v[i]),v[i]));
					num++;
				}
				tell_object(me, "$HIR---------------------------------------------------\n");
			}
		}
	}
	//招亲者个人设置
	else if(!query("stop") && me->query("chunjie/103/zhaoqing") && EQUALSTR(me->id(1),querystr("zhaoqing/owner")))
	{
		if(!strcmp(ask, "jieshao"))
		{
			say("注意：你可以在这里填写你的自我介绍，但介绍字数不可超过100个字，包括标点符号。",me);
			AddMenuItem("填写自我介绍", "$2flatter $1 $2", me);
		}
		else if(!strcmp(ask, "tiaojian"))
		{
			AddMenuItem("魅力要求", "per", me);
			AddMenuItem("年龄要求", "age", me);
			AddMenuItem("财产要求", "money", me);
			AddMenuItem("婚史要求", "hun", me);
			AddMenuItem("总经验要求", "combat", me);
			AddMenuItem("声望要求", "repute", me);
			AddMenuItem("是否接受方外人士", "fangwai", me);
		}
		else if(!strcmp(ask, "start"))
		{
			time_t t;
			double wait_time=query("wait_time");
			time(&t);
			t += (time_t)wait_time;
			struct tm * newtime;
			newtime = localtime( &t );

			int time_hour=query("wait_time")/3600;
			int time_min=(query("wait_time")-int(query("wait_time")/3600)*3600)/60;

			command(snprintf(msg, 255,"wiz 0 %s(%s)已在杭州红娘庄设下比武招亲擂台，请有意者前来红娘庄报名参赛。",me->name(1),me->id(1)));	
			command(snprintf(msg, 255,"wiz 0 %s(%s)的比武招亲比赛将于%d日%d:%d分正式开始！现在距离比赛开赛时间还剩%d小时%d分钟！。",me->name(1),me->id(1),newtime->tm_mday,newtime->tm_hour,newtime->tm_min,time_hour,time_min));
			set("start",1);//正式开始招亲
			set("zhaoqing/wait_time",query("wait_time")-1200);
			Save();
			remove_call_out(do_cacel);
			remove_call_out(do_gonggao);
			call_out(do_gonggao, 1200);
		}
		else if(!strcmp(ask, "per"))
		{
			AddMenuItem("魅力不低于", "$2peri $1 $2", me);
			AddMenuItem("魅力不高于", "$2perii $1 $2", me);
			AddMenuItem("魅力等于", "$2periii $1 $2", me);
		}
		else if(!strcmp(ask, "age"))
		{
			AddMenuItem("年龄不低于", "$2agei $1 $2", me);
			AddMenuItem("年龄不高于", "$2ageii $1 $2", me);
			AddMenuItem("年龄等于", "$2ageiii $1 $2", me);
		}
		else if(!strcmp(ask, "money"))
		{
			AddMenuItem("财产不低于", "$2moneyi $1 $2", me);
			AddMenuItem("财产不高于", "$2moneyii $1 $2", me);
			AddMenuItem("财产等于", "$2moneyiii $1 $2", me);
		}
		else if(!strcmp(ask, "hun"))
		{
			AddMenuItem("没有婚史", "huni", me);
			AddMenuItem("可以有过一次婚史", "hunii", me);
			AddMenuItem("可以有过二次婚史", "huniii", me);
		}
		else if(!strcmp(ask, "combat"))
		{
			AddMenuItem("总经验不低于", "$2combati $1 $2", me);
			AddMenuItem("总经验不高于", "$2combatii $1 $2", me);
			AddMenuItem("总经验等于", "$2combatiii $1 $2", me);
		}
		else if(!strcmp(ask, "repute"))
		{
			AddMenuItem("声望不低于", "$2reputei $1 $2", me);
			AddMenuItem("声望不高于", "$2reputeii $1 $2", me);
			AddMenuItem("声望等于", "$2reputeiii $1 $2", me);
		}
		else if(!strcmp(ask, "fangwai"))
		{
			AddMenuItem("允许方外人士求婚", "fangwaii", me);
			AddMenuItem("拒绝方外人士求婚", "fangwaiii", me);
		}
		else if(!strcmp(ask, "huni"))
		{
			say("你设置婚史要求为:不接受结过婚人士的报名。",me);
			set("zhaoqing/婚史要求",1);
		}
		else if(!strcmp(ask, "hunii"))
		{
			say("你设置婚史要求为:允许结过一次婚人士的报名。",me);
			set("zhaoqing/婚史要求",2);
		}
		else if(!strcmp(ask, "huniii"))
		{
			say("你设置婚史要求为:允许结过二次婚人士的报名。",me);
			set("zhaoqing/婚史要求",3);
		}
		else if(!strcmp(ask, "fangwaii"))
		{
			say("你设置出家人也可以报名。",me);
			set("zhaoqing/方外人士要求",1);
		}
		else if(!strcmp(ask, "fangwaiii"))
		{
			say("你设置不接受出家人报名。",me);
			set("zhaoqing/方外人士要求",2);
		}
	}
	else if(!strcmp(ask, "baoming") && !query("stop"))
	{
		return register_me(me);		//我要报名
	}
	else if(!strcmp(ask, "cancel") && !query("stop"))
	{
		del(snprintf(msg, 255, "biwu/register/%s", me->id(1)));
		Save();
		say("你已经取消了报名。", me);
	}
	else if(!strcmp(ask, "mingdan") && !query("stop"))
	{
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if(querystr("zhaoqing/owner")[0])
	{
		say("蚀月说道：“现在已经有人在准备招亲了，你还是等等吧！”",who);
		SendMenu(who);
		return 0;
	}

	if(query("zhaoqing/coin"))
	{
		say("蚀月说道：“现在已经有人在准备招亲了，你还是等等吧！”",who);
		SendMenu(who);
		return 0;
	}

	if(who->query("couple_betray") > 1)
	{
		say("蚀月皱着眉：“抱歉，你已经无法再婚了！！”",who);
		SendMenu(who);
		return 0;
	}
	
	if(EQUALSTR(who->querystr("class"), "bonze"))
	{	
		say("蚀月皱着眉：“这……你的钱我是不能收的！！！”",who);
		SendMenu(who);
		return 0;
	}
	
	if (EQUALSTR(who->querystr("gender"), "无性") )
	{	
		say("蚀月皱着眉：“这……你的钱我是不能收的！！！”",who);
		SendMenu(who);
		return 0;
	}
	if (DIFFERSTR(ob->querystr("id"), "coin") )
	{	
		say("蚀月说道：“这样的东西我可不能收的。”",who);
		SendMenu(who);
	}
	else if (ob->query("value") ==1666666 && !who->query("chunjie/103/ok"))
	{	
		if (!who->query_temp("chunjie/103/coin"))
		{
			who->set_temp("chunjie/103/coin",1);//交了报名费
			destruct(ob);
			say("蚀月说道：“我已经为你布置好了一场比武招亲擂台赛，你看看是否满意？”",who);
			SendMenu(who);
			set("zhaoqing/coin",1);
			
			remove_call_out(do_cacel);
			call_out(do_cacel, 600);
			return 1;
		}
		else
		{
			say("蚀月说道：“我可不能白帮人做媒哦，只要1666666两银子，我就为你布置一场比武招亲擂台赛！”",who);
			SendMenu(who);
		}
	}
	return 0;
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if(strcmp(comm, "lookup") == 0)
	{			
		return look_turn(me, atol(arg));
	}
	if(querystr("zhaoqing/owner")[0] &&!query("stop") && me->query("chunjie/103/zhaoqing") 
		&& EQUALSTR(me->id(1),querystr("zhaoqing/owner")))
	{
		if (!strcmp(comm,"flatter") )
			return do_flatter(me,arg);
		if (!strcmp(comm,"peri") )
			return do_peri(me,arg);
		if (!strcmp(comm,"perii") )
			return do_perii(me,arg);
		if (!strcmp(comm,"periii") )
			return do_periii(me,arg);
		if (!strcmp(comm,"agei") )
			return do_agei(me,arg);
		if (!strcmp(comm,"ageii") )
			return do_ageii(me,arg);
		if (!strcmp(comm,"ageiii") )
			return do_ageiii(me,arg);
		if (!strcmp(comm,"moneyi") )
			return do_moneyi(me,arg);
		if (!strcmp(comm,"moneyii") )
			return do_moneyii(me,arg);
		if (!strcmp(comm,"moneyiii") )
			return do_moneyiii(me,arg);
		if (!strcmp(comm,"combati") )
			return do_combati(me,arg);
		if (!strcmp(comm,"combatii") )
			return do_combatii(me,arg);
		if (!strcmp(comm,"combatiii") )
			return do_combatiii(me,arg);
		if (!strcmp(comm,"reputei") )
			return do_reputei(me,arg);
		if (!strcmp(comm,"reputeii") )
			return do_reputeii(me,arg);
		if (!strcmp(comm,"reputeiii") )
			return do_reputeiii(me,arg);
	}
	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 200)
	{
		say("给您的描述写得简洁漂亮点。", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg) )
		return 0;

	char msg[255];
	snprintf(msg, 255, "%s(%s)[%s]：%s",me->name(1),me->id(1),me->querystr("gender"),arg);
	set("zhaoqing/描述",msg);
	tell_object(me, "OK.");

	return 1;
}

int do_peri(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<11)
			say("你设置的魅力要求莫免也太低了吧。",me);
		else if(num>40)
			say("你设置的魅力要求莫免也太高了吧。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的魅力要求是不低于%d。",num),me);
			set("zhaoqing/魅力",num);
			set("zhaoqing/魅力要求",1);
		}
	}
	else
	{
		say("你设置的魅力无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_perii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<11)
			say("你设置的魅力要求莫免也太低了吧。",me);
		else if(num>40)
			say("你设置的魅力要求莫免也太高了吧。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的魅力要求是不高于%d。",num),me);
			set("zhaoqing/魅力",num);
			set("zhaoqing/魅力要求",2);
		}
	}
	else
	{
		say("你设置的魅力无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_periii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<11)
			say("你设置的魅力要求莫免也太低了吧。",me);
		else if(num>40)
			say("你设置的魅力要求莫免也太高了吧。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的魅力要求是等于%d。",num),me);
			set("zhaoqing/魅力",num);
			set("zhaoqing/魅力要求",3);
		}
	}
	else
	{
		say("你设置的魅力无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_agei(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<18)
			say("你设置的年龄要求莫免也太低了吧，至少也要成年吧！",me);
		else if(num>500)
			say("你设置的年龄要求莫免也太高了吧，这样的年龄只有神仙才有呀。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的年龄要求是不低于%d。",num),me);
			set("zhaoqing/年龄",num);
			set("zhaoqing/年龄要求",1);
		}
	}
	else
	{
		say("你设置的年龄无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_ageii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<18)
			say("你设置的年龄要求莫免也太低了吧，至少也要成年吧！",me);
		else if(num>500)
			say("你设置的年龄要求莫免也太高了吧，这样的年龄只有神仙才有呀。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的年龄要求是不高于%d。",num),me);
			set("zhaoqing/年龄",num);
			set("zhaoqing/年龄要求",2);
		}
	}
	else
	{
		say("你设置的年龄无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_ageiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<18)
			say("你设置的年龄要求莫免也太低了吧，至少也要成年吧！",me);
		else if(num>500)
			say("你设置的年龄要求莫免也太高了吧，这样的年龄只有神仙才有呀。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的年龄要求是等于%d。",num),me);
			set("zhaoqing/年龄",num);
			set("zhaoqing/年龄要求",3);
		}
	}
	else
	{
		say("你设置的年龄无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_moneyi(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的财产要求莫免也太低了吧，不如不设置了吧！",me);
		else if(num>500000000)
			say("你设置的财产要求莫免也太高了吧。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的财产要求是不低于%d。",num),me);
			set("zhaoqing/财产",num);
			set("zhaoqing/财产要求",1);
		}
	}
	else
	{
		say("你设置的财产无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_moneyii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的财产要求莫免也太低了吧，不如不设置了吧！",me);
		else if(num>500000000)
			say("你设置的财产要求莫免也太高了吧。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的财产要求是不高于%d。",num),me);
			set("zhaoqing/财产",num);
			set("zhaoqing/财产要求",2);
		}
	}
	else
	{
		say("你设置的财产无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_moneyiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的财产要求莫免也太低了吧，不如不设置了吧！",me);
		else if(num>500000000)
			say("你设置的财产要求莫免也太高了吧。",me);
		else
		{
			say(snprintf(msg, 255,"你设置的财产要求是等于%d。",num),me);
			set("zhaoqing/财产",num);
			set("zhaoqing/财产要求",3);
		}
	}
	else
	{
		say("你设置的财产无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_combati(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的总经验要求莫免也太低了吧，还不如不设置！",me);
		else if(num>200000000)
			say("你设置的总经验要求莫免也太高了吧，细数江湖，还找不到呢！",me);
		else
		{
			say(snprintf(msg, 255,"你设置的总经验要求是不低于%d。",num),me);
			set("zhaoqing/总经验",num);
			set("zhaoqing/总经验要求",1);
		}
	}
	else
	{
		say("你设置的总经验无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_combatii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的总经验要求莫免也太低了吧，还不如不设置！",me);
		else if(num>200000000)
			say("你设置的总经验要求莫免也太高了吧，细数江湖，还找不到呢！",me);
		else
		{
			say(snprintf(msg, 255,"你设置的总经验要求是不高于%d。",num),me);
			set("zhaoqing/总经验",num);
			set("zhaoqing/总经验要求",2);
		}
	}
	else
	{
		say("你设置的总经验无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_combatiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的总经验要求莫免也太低了吧，还不如不设置！",me);
		else if(num>200000000)
			say("你设置的总经验要求莫免也太高了吧，细数江湖，还找不到呢！",me);
		else
		{
			say(snprintf(msg, 255,"你设置的总经验要求是等于%d。",num),me);
			set("zhaoqing/总经验",num);
			set("zhaoqing/总经验要求",3);
		}
	}
	else
	{
		say("你设置的总经验无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_reputei(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的声望要求莫免也太低了吧，还不如不设置！",me);
		else if(num>100000000)
			say("你设置的声望要求莫免也太高了吧，细数江湖，还找不到呢！",me);
		else
		{
			say(snprintf(msg, 255,"你设置的声望要求是不低高于%d。",num),me);
			set("zhaoqing/声望",num);
			set("zhaoqing/声望要求",1);
		}
	}
	else
	{
		say("你设置的声望无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_reputeii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的声望要求莫免也太低了吧，还不如不设置！",me);
		else if(num>100000000)
			say("你设置的声望要求莫免也太高了吧，细数江湖，还找不到呢！",me);
		else
		{
			say(snprintf(msg, 255,"你设置的声望要求是不高于%d。",num),me);
			set("zhaoqing/声望",num);
			set("zhaoqing/声望要求",2);
		}
	}
	else
	{
		say("你设置的声望无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

int do_reputeiii(CChar *me,char * arg)
{
	int num=atoi(arg);
	if(num)
	{
		char msg[255];
		if(num<100)
			say("你设置的声望要求莫免也太低了吧，还不如不设置！",me);
		else if(num>100000000)
			say("你设置的声望要求莫免也太高了吧，细数江湖，还找不到呢！",me);
		else
		{
			say(snprintf(msg, 255,"你设置的声望要求是等于%d。",num),me);
			set("zhaoqing/声望",num);
			set("zhaoqing/声望要求",3);
		}
	}
	else
	{
		say("你设置的声望无法用常理去度量，还是重新设置吧！", me);
	}
	SendMenu(me);
	return 1;
}

static void do_gonggao(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	char msg[255];
	if(npc->query("zhaoqing/wait_time")>0)
	{
		char msg[255];
		time_t t;
		double wait_time=npc->query("zhaoqing/wait_time");
		time(&t);
		t += (time_t)wait_time;
		struct tm * newtime;
		newtime = localtime( &t );
		
		int time_hour=npc->query("zhaoqing/wait_time")/3600;
		int time_min=(npc->query("zhaoqing/wait_time")-int(npc->query("zhaoqing/wait_time")/3600)*3600)/60;
		
		npc->command(snprintf(msg, 255,"wiz 0 %s(%s)已在杭州红娘庄设下比武招亲擂台，请有意者前来红娘庄报名参赛。",npc->querystr("zhaoqing/name"),npc->querystr("zhaoqing/owner")));	
		npc->command(snprintf(msg, 255,"wiz 0 %s(%s)的比武招亲比赛将于%d日%d:%d分正式开始！现在距离比赛开赛时间还剩%d小时%d分钟！。",npc->querystr("zhaoqing/name"),npc->querystr("zhaoqing/owner"),newtime->tm_mday,newtime->tm_hour,newtime->tm_min,time_hour,time_min));
		
		npc->set("zhaoqing/wait_time",npc->query("zhaoqing/wait_time")-1200);
		
		npc->Save();
		npc->call_out(do_gonggao, 1200);
	}
	else
	{
		npc->del("zhaoqing/wait_time");
		npc->command(snprintf(msg, 255,"wiz 0 %s(%s)的比武招亲比赛正式开始了，不知道谁会是最后的幸运儿呢！\n",npc->querystr("zhaoqing/name"),npc->querystr("zhaoqing/owner")));	
		CNwiz_103 * npc1=(CNwiz_103 *)npc;
		CMapping * team=npc1->querymap("biwu/register");
		if(npc1->query_count(team))
		{
			npc1->do_start();
		}
		else
		{
			CUser * me=find_online(npc->querystr("zhaoqing/owner"));
			if(!me)
			{
				me = add_user();
				me->set("id", npc->querystr("zhaoqing/owner"));
				me->LoadFromServer();
				me->del("chunjie/103/zhaoqing");
				me->set("chunjie/103/ok",1);
				me->Save();
			}
			else
			{
				me->del("chunjie/103/zhaoqing");
				me->set("chunjie/103/ok",1);
			}

			npc1->command(snprintf(msg, 255,"wiz 0 可惜可惜，%s(%s)的比武招亲大赛至今仍然没有人来报名，本次招亲活动现在取消！\n",npc1->querystr("zhaoqing/name"),npc1->querystr("zhaoqing/owner")));	
			npc1->del("zhaoqing");
			npc1->del("biwu");
			npc1->del("start");
			npc1->del("state");
			npc1->set("biwu/name", "比武招亲大会");
			npc1->set("biwu/register/0", "空缺");
			npc1->set("biwu/turn0/0", "0");
			npc1->Save();
		}
	}
}

//超时还未举办比赛着，取消其资格。
static void do_cacel(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("start"))
	{
		npc->del("zhaoqing");
	}
}

//报名程序
int register_me(CChar * me)
{
	//首先检测是否符合报名条件
	if(query("zhaoqing/魅力"))
	{
		switch(query("zhaoqing/魅力要求"))
		{
		case 1:
			if(me->query("per")<query("zhaoqing/魅力"))
			{
				say("你的魅力不够，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("per")>query("zhaoqing/魅力"))
			{
				say("你的魅力太高，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("per")!=query("zhaoqing/魅力"))
			{
				say("你的魅力不符合要求，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(query("zhaoqing/年龄"))
	{
		if(me->query("age")<16)
		{
			say("蚀月拍了拍你的头：“还是等你长大点再来吧！”", me);
			SendMenu(me);
			return 1;
		}
		switch(query("zhaoqing/年龄要求"))
		{
		case 1:
			if(me->query("age")<query("zhaoqing/年龄"))
			{
				say("你的年龄太小，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("age")>query("zhaoqing/年龄"))
			{
				say("你的年龄太大，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("age")!=query("zhaoqing/年龄"))
			{
				say("你的年龄不符合要求，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	switch(query("zhaoqing/方外人士要求"))
	{
	case 0:
	case 2:
		if(EQUALSTR(me->querystr("class"), "bonze"))
		{
			say("既然您已经出家，何必再惹这段红尘？", me);
			SendMenu(me);
			return 1;
		}
		break;
	}
	if(query("zhaoqing/财产"))
	{
		switch(query("zhaoqing/财产要求"))
		{
		case 1:
			if(me->query("balance")<query("zhaoqing/财产"))
			{
				say("你的钱太少，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("balance")>query("zhaoqing/财产"))
			{
				say("你的钱太多，招亲者不愿意让你报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("balance")!=query("zhaoqing/财产"))
			{
				say("你的财产不符合要求，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(query("zhaoqing/总经验"))
	{
		switch(query("zhaoqing/总经验要求"))
		{
		case 1:
			if(me->query("combat_exp")<query("zhaoqing/总经验"))
			{
				say("你的武功太低，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("combat_exp")>query("zhaoqing/总经验"))
			{
				say("你的武功太高，招亲者不愿意让你报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("combat_exp")!=query("zhaoqing/总经验"))
			{
				say("你的总经验不符合要求，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(query("zhaoqing/声望"))
	{
		switch(query("zhaoqing/声望要求"))
		{
		case 1:
			if(me->query("repute")<query("zhaoqing/声望"))
			{
				say("你的声望太低，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("repute")>query("zhaoqing/声望"))
			{
				say("你的声望太高，招亲者不愿意让你报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("repute")!=query("zhaoqing/声望"))
			{
				say("你的声望不符合要求，不够资格报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if (me->querymap("couple"))
	{
		say("你不是已经结婚吗？重婚是犯法的。", me);
		SendMenu(me);
		return 1;
	}
	if (EQUALSTR(me->querystr("gender"), "无性") )
	{
		say("蚀月皱着眉，露出了厌恶的表情：“这……你不是害人嘛！！！”", me);
		SendMenu(me);
		return 1;
	}
	if (EQUALSTR(me->querystr("gender"), querystr("zhaoqing/gender")) )
	{
		say("蚀月惊讶地“啊”了一声：“这个，你还是等有异性朋友招亲时再来报名吧！”", me);
		SendMenu(me);
		return 1;
	}
	if(query("zhaoqing/婚史"))
	{
		switch(query("zhaoqing/婚史要求"))
		{
		case 1:
			if(me->query("couple_betray")>query("zhaoqing/婚史要求")-1)
			{
				say("你的经历太多，招亲者不愿意让你报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 2:
			if(me->query("couple_betray")>query("zhaoqing/婚史要求")-1)
			{
				say("你的经历太多，招亲者不愿意让你报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		case 3:
			if(me->query("couple_betray")>query("zhaoqing/婚史要求")-1)
			{
				say("你的经历太多，招亲者不愿意让你报名。", me);
				SendMenu(me);
				return 1;
			}
			break;
		}
	}
	if(has_register(me))	
		say("您已登记。请耐心等待比武招亲开始。", me);
	else
	{
		register_join(me, querymap("biwu/register"));
		say("记下了，请耐心等待比武招亲开始。", me);			
	}
	SendMenu(me);
	return 1;
}

//检测是否已经报名过
int has_register(CChar * me)
{
	CMapping * team = querymap("biwu/register");
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
}

//登记
void register_join(CChar * me, CMapping * team)
{
	if(team)
	{
		team->set(me->id(1), me->name(1));
		Save();
	}
}

//查询报名总数
int query_count(CMapping * team)
{
	if(! team) return 0;
	return team->GetCount();
}

void do_start()
{
	char msg[255];

	del("biwu/register/0");

	CMapping * reg = querymap("biwu/register");
	CMapping * result = querymap("biwu/turn0");

	if(! result)
	{
		CMapping m;
		set(msg, m);
		result = querymap(msg);
	}

	if(! reg || ! result) return ;

	int st = 0, team = 0;
	CVector v;
	reg->keys(v);

	if(query("state"))	//在已分组的条件下继续分组
	{
		team = result->GetCount();
		for(int i=0; i<team; i++)
		{
			CMapping * ptr = result->querymap(snprintf(msg, 255, "%ld", i));
			const char * key = ptr->querystr("A");
			v.remove(key);
			key = ptr->querystr("B");

			if(key[0])
			{
				st = 0;
				v.remove(key);
			}
			else
				st = 1;			
		}

		if(st) team--;
	}	

	int count;
	int i=0;
	char str[20];
	add("state",1);

	while(( count = v.count()))
	{
		const char * key = v[random(count)];

		if(! st)
		{
			result->set(snprintf(str, 20, "%ld/A", team), key);
			v.remove(key);
		}

		if(count > 1 || st)
		{
			key = v[random(count - 1)];

			result->set(snprintf(str, 20, "%ld/B", team), key);
			v.remove(key);
			st = 0;
		}
		add("zhaoqing/biwu/start",1);
		i++;
		do_ready1(team,i);//开始比武;
		team ++;
	}
	Save();
}

int do_ready1(int team,int i)
{
	char msg[255],tmp[20],tmp1[20];
	int state = query("state") - 1;
	if(state < 0) return 0;

	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("没有该组。summon <组号>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	int wait_time = query("wait_time_biwu");

	command(snprintf(msg, 255, "wiz 0 %s(%s)的比武招亲比赛第%s轮第%s组将由%s与%s进行角逐！\n", 
		querystr("zhaoqing/name"),querystr("zhaoqing/owner"),
		chinese_number(query("state"), tmp),chinese_number(i, tmp1), 
		key1, key2));

	if(fighter1 && fighter2)
	{		
		snprintf(msg, 255, "\n\n$HIG【比武招亲】%s和%s请准备好！", fighter1->name(1), fighter2->name(1), wait_time);

		tell_object(fighter1, msg);
		tell_object(fighter2, msg);	
	}
	else
	{
		command("wiz 0 比武招亲当时不在线的按弃权处理，对手自动进入下轮。");	
	}

	do_ready(this, wait_time, team);
	Save();
	return 1;
}

static void do_ready(CContainer * ob, LONG wait_time, LONG team)
{
	CNwiz_103 * me = (CNwiz_103 *)ob;

	if(wait_time <= 0)
	{
		me->do_summon(me, team);
		me->do_biwu(team);
		return;
	}

	char msg[255];
	int state = me->query("state") - 1;
	if(state < 0) return;

	CMapping * ptr = me->querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return;
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	snprintf(msg, 255, "\n\n$HIR【比武招亲】你距离比赛还有%ld分钟！时间到自动切入战斗，请做好准备。\n\n", wait_time);

	if(fighter1)
		tell_object(fighter1, msg);
	if(fighter2)
		tell_object(fighter2, msg);

	me->call_out(do_ready, 60, wait_time - 1, team);
}

//抓人
int do_summon(CChar * me, int team)
{
	char msg[255];

	int state = query("state") - 1;
	if(state < 0) return 0;

	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("没有该组。summon <组号>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	CContainer * r = me->environment();//这里要改一下，不能在NPC旁边比武，要换个专用场地

	if(fighter1) 
	{
		fighter1->move(r);
		if(fighter1->query("mp")>fighter1->query("max_mp")*4)
			fighter1->set("mp",fighter1->query("max_mp")*4);
		message_vision("$N从天而降！", fighter1);
	}
	
	if(fighter2) 
	{
		fighter2->move(r);
		if(fighter2->query("mp")>fighter2->query("max_mp")*4)
			fighter2->set("mp",fighter2->query("max_mp")*4);
		message_vision("$N从天而降！", fighter2);
	}
	
	return 1;
}

//比武开始
int do_biwu(int team)
{
	char msg[255];

	int state = query("state") - 1;
	if(state < 0) return 0;
	
	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("没有该组。biwu <组号>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);

	if(fighter1 && fighter2)	//两人均在线，开始比武
	{	
		fighter1->set_temp("biwu/npc", object_id());	//将本NPC注册
		fighter1->set_temp("biwu/team", team);		
		fighter2->set_temp("biwu/npc", object_id());	//将本NPC注册
		fighter2->set_temp("biwu/team", team);

		full_me(fighter1);
		full_me(fighter2);

		fighter1->set_weight(50000000);
		fighter2->set_weight(50000000);

		fighter1->set_temp("no_fei", 1);	//禁止逃跑	
		fighter2->set_temp("no_fei", 1);	

		CContainer * env = Do_BiShi(fighter1, fighter2, "比武招亲", 0);
		env->set("room_locked", FIGHT_LOCKED);	//战斗锁死.

		//加入战斗检测链表
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(fighter1) 
		register_winner(fighter1, team);
	else if(fighter2) 
		register_winner(fighter2, team);
	else
		return notify_fail("都不在线。");

	return 1;
}

void full_me(CChar * me)
{
	int hp = me->query("hp");
	int max_hp = me->query("max_hp");

	if(hp < max_hp)
	{
		me->set("hp", max_hp);
		me->set("eff_hp", max_hp);
	}

	hp = me->query("mp");
	max_hp = me->query("max_mp");

	if(hp < max_hp * 2)
	{
		me->set("mp", max_hp * 2);
	}
	
	message_vision("$YEL只见$N浑身金光乍现，散发无穷活力！", me);
	me->FlushMyInfo();	
}


void set_biwu(CContainer * ob)
{
	char msg[40];

	snprintf(msg, 40, snprintf(msg, 40, "%ld", ob->object_id()));

	if( m_biwulist.find(msg) == m_biwulist.end() )
		m_biwulist.append(msg);
}

void do_snoop(CContainer * env)
{
	const char * ch = querystr("channel");
	if(! ch[0])	return;
		
	env->set("channel_cast", ch);
	env->set("channel_id", querystr("chname"));
	set_temp("is_boardcast", env->object_id());			
}

void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//下面是比武得胜者的处理
	register_winner(winner, team);

	winner->delete_temp("biwu");
	failer->delete_temp("biwu");

	winner->revive(1);
	failer->revive(1);

	winner->delete_temp("no_fei");
	failer->delete_temp("no_fei");	

	full_me(winner);
	full_me(failer);

	winner->set_weight(50000);
	failer->set_weight(50000);

	CContainer * env = winner->environment();
	remove_biwu(env);

	if(env->object_id() == query_temp("is_boardcast"))
		transfer_info();
}

//得胜者进入下一轮名单
void register_winner(CChar * who, int team)
{
	char msg[255], tmp[20];
	int state = query("state");
			
	if(team % 2 == 0)
		snprintf(msg, 255, "biwu/turn%ld/%ld/A", state, team/2);
	else
		snprintf(msg, 255, "biwu/turn%ld/%ld/B", state, team/2);

	set(msg, who->querystr("id"));	

	const char * zuname = querystr("biwu/name");
	g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, "恭喜%s(%s)赢得了本场比赛顺利进入%s第%s轮比赛！\n", 			
			who->name(1), who->id(1), zuname, chinese_number(state+1, tmp) ));
	
	add("zhaoqing/biwu/end",1);
	int start=query("zhaoqing/biwu/start");
	if(start==query("zhaoqing/biwu/end"))
	{
		if(start!=1)
		{
			add("state",1);
			del("zhaoqing/biwu/start");
			del("zhaoqing/biwu/end");
			for(int i=0;i<start/2;i++)
			{
				add("zhaoqing/biwu/start",1);
				do_ready1(i,i+1);//开始比武;
			}
		}
		else
		{
			g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, "恭喜恭喜！%s(%s)技压群雄，获得了本次比武招亲擂台赛的优胜！", who->name(1), who->id(1)));
			g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, 	"无论%s(%s)和%s(%s)是否能够成为一对欢喜冤家，都让我们恭祝他们开心幸福，万事如意！\n", querystr("zhaoqing/name"),querystr("zhaoqing/owner"),who->name(1), who->id(1)));
			
			if(DIFFERSTR(who->querystr("gender"), "无性") && !who->querymap("couple"))
			{
				int ft;
				CUser * me=find_online(querystr("zhaoqing/owner"));
				if(!me)
				{
					set_temp("逃跑",1);
					me = add_user();
					me->set("id", querystr("zhaoqing/owner"));
					me->LoadFromServer();
					if(DIFFERSTR(me->querystr("gender"), "无性") && DIFFERSTR(me->querystr("class"), "bonze") && !me->querymap("couple") )
					{
						me->set("couple/id", who->querystr("id"));
						me->set("couple/name", who->querystr("name"));
						if(EQUALSTR(who->querystr("gender"), "男性") )
							me->set("couple/gender", "老公");
						else
							me->set("couple/gender", "老婆");
						me->del("chunjie/103/zhaoqing");
						me->set("chunjie/103/ok",1);
						me->Save();
					}
					else
					{
						ft=1;
					}
				}
				else
				{
					if(DIFFERSTR(me->querystr("gender"), "无性") && DIFFERSTR(me->querystr("class"), "bonze") && !me->querymap("couple") )
					{
						me->set("couple/id", who->querystr("id"));
						me->set("couple/name", who->querystr("name"));
						if(EQUALSTR(who->querystr("gender"), "男性") )
							me->set("couple/gender", "老公");
						else
							me->set("couple/gender", "老婆");
					}
					else
					{
						ft=1;
					}
				}
				if(ft!=1)
				{
					who->set("couple/id", me->querystr("id"));
					who->set("couple/name", me->querystr("name"));
					if(EQUALSTR(me->querystr("gender"), "男性") )
						who->set("couple/gender", "老公");
					else
						who->set("couple/gender", "老婆");
					
					if(EQUALSTR(who->querystr("class"), "bonze") )//出家人此时需要被逐出师门
					{
						g_Channel.do_channel(&g_Channel, 0, "news", 
								snprintf(msg, 255, "%s脱下身上的僧袍，面向西方恭恭敬敬地跪下来磕了几个响头，从此恢复了自由身。",who->name(1)));
						CMapping * skills = who->query_skills();
						CVector v;
						skills->keys(v);
						for(int i=0; i<v.count(); i++)
						{
							if((*skills)[v[i]]>351) 
								(*skills)[v[i]] = 351;
						}
						
						who->FlushMySkill(who);
						who->release_master();
						
						who->add("betrayer", 1);
						who->set("title","普通百姓");
						who->del("class");
						who->del("zhangmen");
						who->del("family");
						who->del("party");
						who->del("beggarlvl");
						
						who->UpdateMe();
					}
					g_Channel.do_channel(&g_Channel, 0, "news", 
						snprintf(msg, 255, "%s与%s今日指天为誓，拜土为盟，永结同心，生生世世，不违此约……",querystr("zhaoqing/name"),who->name(1)));

					if(query_temp("逃跑"))
					{
						destruct(me);
						delete_temp("逃跑");
					}
					//巫师赠送礼物
					static char baowu[23][20]={"taibaizao","38huoqiang","diaojiandai","jinhuantoushi",
						"xuantiebishou","bolanxie","haoseshan","xiantianyu","poliquan","fannaomao","shajiezhi","tiancanbaojia",
						"newyear","newyear1","zidiaopifeng","liaochengpao","dagoubang","yinguozhu","dulonglian","shenshe_staff",
						"ruanweijia","zhangmenhuan","yinmopao"};
					load_item(baowu[random(23)])->move(who);
					tell_object(who,"蚀月满面含笑道：这是我的一点小小心意送给你们，祝你们夫妻开心幸福，万事如意！。");

					//发送礼物给所有在线用户
					MAP2USER * user;
					iterator_user p;
					CUser * obj;
					user = users();
					for ( p=user->begin(); p!=user->end(); p++)
					{
						obj = p->second;
						char msg[255];
						CContainer * gift;
						
						snprintf(msg, 255, "天上飘扬着落下一个袋子，不偏不倚落在你的怀中……\n你打开一看，看到了一张喜帖，一瓶酒和一块蛋糕。");
						tell_object(obj,msg);
						
						gift=load_item("cake");
						gift->move(obj);
						
						if (EQUALSTR(obj->querystr("gender"), "男性"))	//竹叶青
						{
							gift=load_item("jiuping2");
							gift->move(obj);
						}
						
						if (EQUALSTR(obj->querystr("gender"), "女性"))	//女儿红
						{
							gift=load_item("nverhong");
							gift->move(obj);
						}
						
						if (EQUALSTR(obj->querystr("gender"), "无性"))	//壮阳酒
						{
							gift=load_item("jiuping");
							gift->move(obj);
						}
						
						gift=load_item("anmenkey");
						snprintf(msg, 255, "%s和%s的结婚喜帖",who->name(1),who->querystr("couple/name"));
						gift->set_name(msg, "xi tie");
						gift->set("value",0l);
						gift->set("long","这是一张喜帖。");
						gift->set("unit","张");
						gift->move(obj);
					}
				}
			}
			del("zhaoqing");
			del("biwu");
			del("start");
			del("state");
			set("biwu/name", "比武招亲大会");
			set("biwu/register/0", "空缺");
			set("biwu/turn0/0", "0");
		}
	}
	Save();
}

void remove_biwu(CContainer *ob)
{
	char msg[80];
	m_biwulist.remove(snprintf(msg, 40, "%ld", ob->object_id()));
}

//随机转播
void transfer_info()
{
	while(m_biwulist.count())
	{
		CContainer * env = find_object(atol(m_biwulist[0]));
		if(env)
		{
			do_snoop(env);
			return;
		}
		m_biwulist.remove(m_biwulist[0]);
	}
}

//查看对阵形式
int look_turn(CChar * me, int turn)
{
	if(turn < 0 || turn > query("state")) return notify_fail("没有进行到这轮。");

	char msg[255], str[20];
	CMapping * m = querymap(snprintf(msg, 40, "biwu/turn%ld", turn));
	CMapping * reg = querymap("biwu/register");
	CMapping * ptr;
	int i;
	
	if(! m || ! reg) return notify_fail("还没有结果。");

	tell_object(me, snprintf(msg, 255, "\n比武招亲第%s轮对阵形式", chinese_number(turn+1, str)));
	tell_object(me, "-------------------------------------------------------");

	int count = (reg->GetCount() + 1) / 2;
	//判断是否优胜
	CMapping * next = querymap(snprintf(msg, 40, "biwu/turn%ld", turn + 1));
	int win;
	CVector v, team;

	if(next)
	{
		next->keys(v);
		for(int t = 0; t<v.count(); t++)
		{
			CMapping * line = next->querymap(v[t]);
			if(! line) continue;

			if(line->querystr("A")[0])
				team.append(line->querystr("A"));
			if(line->querystr("B")[0])
				team.append(line->querystr("B"));
		}
	}

	for(i=0; i<count; i++)
	{
		ptr = m->querymap(snprintf(msg, 255, "%ld", i));
		if(! ptr) continue;
		
		const char * key1 = ptr->querystr("A");
		const char * key2 = ptr->querystr("B");

		if(team.find(key1) != team.end())
			win = 1;
		else if(team.find(key2) != team.end())
			win = 2;
		else 
			win = 0;
		tell_object(me, snprintf(msg, 255, "$HIY第%s组：%s%s(%s)$HIY VS %s%s(%s)", 
				chinese_number(i + 1, str), 
				(win == 1 ? "$HIC" : ""),
				(key1[0] ? reg->querystr(key1) : "空缺"), 
				key1,
				(win == 2 ? "$HIC" : ""),
				(key2[0] ? reg->querystr(key2) : "空缺"), 
				key2) );
	}

	return 1;
}

protected:
	CVector		m_biwulist;


NPC_END;
