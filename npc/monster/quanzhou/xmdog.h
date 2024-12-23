//xmdog.h
//凶猛的狗·任务ＮＰＣ·台湾（改在泉洲）·做任务·类别：找东西·难度２０
//Teapot 2001-02-07

//自制武器经常丢失。为此修改：
//lanwood 2001-04-13
//在teapot/referent里记录武器的object_id
//可以到狗那里询问武器的位置。
//如果武器不在线，则清掉该标记，使玩家可以重新打造兵刃。

NPC_BEGIN(CNquanzhou_xmdog);


virtual void create()
{
	set_name("凶猛的狗", "sim chen");
	set("long", "爱把东西乱扔的一只狗。");
	set("title", "泉洲青龙会保管员　「我的袜子呢？」");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("no_huan",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	CNpc::do_talk(me,ask);
	me->set_temp("teapot/dog", 1);
//	AddMenuItem("向凶猛的狗询问任务", "$0askquest $1", me);
//	AddMenuItem("向凶猛的狗索要任务", "$0getquest $1", me);
//	AddMenuItem("向凶猛的狗要求清除任务", "$0cleanquest $1", me);
	AddMenuItem("与凶猛的狗谈关于连城诀的事", "$0liancheng $1", me);
	AddMenuItem("与凶猛的狗谈关于铸造兵刃的事", "$0buildss $1", me);
	AddMenuItem("与凶猛的狗谈关于判师的事", "$0panshi $1", me);
	SendMenu(me);
	return 1;
}



int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "panshi") == 0)
		return do_panshi(me, atol(arg));

	if(me->query_temp("teapot/dog"))
	{
		me->delete_temp("teapot/dog");
		/*if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "cleanquest") == 0)
			return do_cq(me);*/
		if(strcmp(comm, "liancheng") == 0)
			return do_lc(me);
		if(strcmp(comm, "buildss") == 0)
			return do_bs(me);		
	}

	if(me->query_temp("teapot/iron"))
	{
		if(strcmp(comm, "stname") == 0)
			return do_stname(arg,me);
		else if(strcmp(comm, "sttype") == 0)
			return do_sttype(me);
		else if(strcmp(comm, "stcolor") == 0)
			return do_stcolor(me);
		else if(strcmp(comm, "ssfl") == 0)
			return do_ssfl(me);
		else if(strcmp(comm, "dtrans") == 0)
			return do_dtrans(me,arg);
		else if(strcmp(comm, "dtransg") == 0)
			return do_dtransg(me,arg);
	}

	return CNpc::handle_action(comm, me, arg);

}

//判师
int do_panshi(CChar * me, int flag)
{
	if(flag)
	{
		char msg[255];

		if(! me->query_temp("xmdog/判师"))
		{
			say("嘿嘿，别玩我！狗也有自尊！", me);
			SendMenu(me);
			return 1;
		}

		//完成任务了 1 判师 2 赏金
		if(flag == 1)
		{
			int lv = me->query("betrayer");

			if(! lv) return 0;

			say("想让人忘掉你不光彩的过去，只有自残！", me);
			say(snprintf(msg, 255, "以你现在的情况，除非全部武功废掉%ld级才有希望。否则……", lv * 20), me);
			
			AddMenuItem("我愿意", snprintf(msg, 255, "$9panshi %ld 3", object_id()), me);
			AddMenuItem("算了，还是给我赏金吧。", snprintf(msg, 255, "$9panshi %ld 2", object_id()), me);
		}
		else if(flag == 3)	//判师
		{
			say("哈哈，有个性，我喜欢！", me);
			say("现在你的武功尽失，再没人知道你的过去了！", me);

			me->delete_temp("xmdog/判师");
			me->Remove_Betrayer(me);			
		}
		else
		{
			LONG money = random(50000) + 1;
			CMoney::Pay_Player(me, money);
			say(snprintf(msg, 255, "嘿嘿，刚有个女孩给了我%ld金，你先拿着花吧！", money), me);			
			me->delete_temp("xmdog/判师");
		}
		
		SendMenu(me);
		return 1;
	}

	me->add_temp("pending/xmdog_ps", 1);

	if(! random(2))
		say("这个嘛……", me);
	else
		say("不好吧……", me);

	if(random(me->query_temp("pending/xmdog_ps")) > 3)
	{
		command("sigh");
		say("看你这么诚心就告诉你吧。", me);
		say("两年前，我遇上一个极美的女孩。", me);
		say("别看我是狗，却有颗人的心。", me);
		say("那天，我又遇到她了，天下着雨。", me);
		say("我看到她身边有另外一条狗在陪她。", me);
		say("虽然我是狗，可也有脾气。", me);
		say("我怒了，和那条狗决斗，但，失败了。", me);
		say("我看到她把我最爱吃的肉包子给那条叫旺财的狗！", me);
		say("怎么样！去帮我出这口恶气吧！", me);
	}

	SendMenu(me);
	return 1;
}

int do_ssfl(CChar * me)
{
	if (!me->querystr_temp("teapot/f_ironname")[0])
		return notify_fail("请先设置武器的名字。");
	if (!me->querystr_temp("teapot/irontype")[0])
		return notify_fail("请先设置武器的类别。");
	
	char msg[80];

	CContainer * obj = load_item("ssword");
	obj->set_name( me->querystr_temp("teapot/f_ironname"), "tealeaf");
	obj->set("base_name", snprintf(msg, 80, "s_weapon_%s", me->id(1)));
	obj->set("staticname",me->querystr_temp("teapot/f_ironname"));
	obj->set("skill_type", me->querystr_temp("teapot/irontype"));
	
	obj->set("cumpower", me->query("teapot/cumpower"));	//lanwood 2001-03-37
	obj->set("owner", me->querystr("id"));	//added by lanwood 2001-03-11
	obj->create();		//计算攻击

	obj->move(me);
	obj->Save();
	
	me->delete_temp("teapot/iron");
	me->set("teapot/referent", obj->object_id());	//记录武器的id
	me->Save();
	return 1;
}

int do_sttype(CChar * me)
{
	AddMenuItem("锤", "$0dtrans $1 hammer", me); 
	AddMenuItem("剑", "$0dtrans $1 sword", me); 
	AddMenuItem("杖", "$0dtrans $1 staff", me); 
	AddMenuItem("棍", "$0dtrans $1 club", me); 
	AddMenuItem("鞭", "$0dtrans $1 whip", me); 
	AddMenuItem("刀", "$0dtrans $1 blade", me); 
	AddMenuItem("斧头","$0dtrans $1 axe", me); 
	SendMenu(me);

    return 1; 
}

int do_dtrans(CChar * me, char * arg)
{
//	char msg[255];

	if(! strlen(arg))
		return notify_fail("你想打造什么？");
	me->set_temp("teapot/irontype",arg);
	tell_object(me,"Ok.");

	do_bs(me);		//lanwood 2001-03-27
	return 1;
}

int do_stcolor(CChar * me)
{
	AddMenuItem("白", "$0dtransg $1 $HIW", me); 
	AddMenuItem("灰", "$0dtransg $1 $WHT", me); 
	AddMenuItem("红", "$0dtransg $1 $HIR", me); 
	AddMenuItem("黄", "$0dtransg $1 $HIY", me); 
	AddMenuItem("绿", "$0dtransg $1 $HIG", me); 
	AddMenuItem("蓝", "$0dtransg $1 $HIB", me); 
	AddMenuItem("靛","$0dtransg $1 $HIC", me); 
	SendMenu(me);

    return 1; 

}

int do_dtransg(CChar * me, char * arg)
{
	char msg[255];

	snprintf(msg, 255, "%s",me->querystr_temp("teapot/ironname"));

	if(! strlen(arg))
		return notify_fail("你想打造什么？");
	if(!me->querystr_temp("teapot/ironname")[0])
		return notify_fail("请先设置武器的名字。");

	snprintf(msg, 255, "%s%s$COM",arg,me->querystr_temp("teapot/ironname"));

	me->set_temp("teapot/f_ironname",msg);
	tell_object(me,"Ok.");
	
	do_bs(me);		//lanwood 2001-03-27
	return 1;
}


int do_stname(char * arg,CChar * me)
{
	if (ccheck_legal_name(arg)=="")
	{
		me->set_temp("teapot/f_ironname",arg);
		tell_object(me,"Ok.");
	}
	else
	{
		tell_object(me,ccheck_legal_name(arg));
	}

	do_bs(me);		//lanwood 2001-03-27

	return 1;
}


int do_bs(CChar * me)
{
	LONG objectid;

	//先检查是否已经有标记
	if(( objectid = me->query("teapot/referent")) )
	{
		char msg[255];
		CContainer * weapon = find_item(objectid);
		if(! weapon || ! weapon->environment() || DIFFERSTR(weapon->querystr("owner"), me->id(1)) )
		{
			say("可怜的家伙，你的武器已经丢了，还是重新再锻造一把吧！", me);
			SendMenu(me);
			me->del("teapot/referent");
			return 1;
		}

		//告诉玩家武器的方位
		say(snprintf(msg, 255, "%s似乎在%s里。", weapon->name(1), (weapon->environment())->name(1)) );
		SendMenu(me);
		return 1;
	}

	if(me->query("age") < 16)
	{
		say("小孩子玩什么刀枪？边儿上玩去！", me);
		SendMenu(me);
		return 1;
	}

	if (!me->query_temp("teapot/iron"))
	{
		message_vision("凶猛的狗说：没有原初铁胚，如何铸造兵刃？",me);
		return 1;
	}
	
	AddMenuItem("设置兵刃的名称。", "$2stname $1 $2", me);
	AddMenuItem("设置兵刃的类别。", "$0sttype $1", me);
//	AddMenuItem("设置兵刃的颜色。", "$0stcolor $1", me);
	AddMenuItem("铸造", "$0ssfl $1 ", me);
	SendMenu(me);
	return 1;
}



/*
// shui/id shui/name shui/overtime shui/exp shui/finish

int do_gq(CChar * me)
{
	static struct{
		char areaname[20];	//区域名称
		int  time;			//时间:与距离泉州远近有关系。大约是０～６０。。。
		int	 exp;			//经验:与区域大小有关系。大约是区域文件数＊４。。。
	} gneerroom[37] = {	
		{"白驼",  60,200,},
		{"北京",  30,160,},

		{"长安",  20,70,},
		{"成都",  30,80,},
		{"峨嵋",  40,250,},
		{"大理",  20,720,},
		{"福州",  5,90,},

		{"佛山",  10,120,},
		{"关外",  50,150,},
		{"杭州",  20,400,},
		{"古墓",  30,80,},
		{"衡山",  20,200,},

		{"黑木",  30,170,},
		{"恒山",  20,80,},
		{"黄河",  30,200,},
		{"华山",  25,210,},
		{"灵州",  45,140,},

		{"灵鹫",  50,160,},
		{"明教",  35,160,},
		{"梅庄",  25,80,},
		{"青城",  10,80,},
		{"泉州",  1,80,},

		{"嵩山",  15,100,},
		{"苏州",  10,200,},
		{"桃花",  10,64,},
		{"万劫",  35,72,},
		{"天龙",  28,96,},

		{"武当",  20,208,},
		{"侠客",  25,120,},
		{"襄阳",  20,140,},
		{"逍遥",  20,50,},
		{"西域",  25,60,},

		{"血刀",  35,120,},
		{"扬州",  10,120,},
		{"燕子",  15,120,},
		{"终南",  20,220,},
		{"重阳",  25,60,},
	};

	
	
	long i;
	long e;
	time_t t;
	char msg[255];
	
		
	i=time(&t);

	e=me->query("dog/overtime");
	if(e && i>e)
	{
	    say("凶猛的狗奇怪的看了你一眼。",me);
		say("凶猛的狗说：你没完成任务来见我，我得罚你。", me);
		SendMenu(me);
		me->set("dog/finish",0);	
		me->del("dog/id");		
		me->del("dog/name");	
		me->del("dog/overtime");	
		me->del("dog/exp");		
		me->set("hp",me->query("hp")/3);
		me->set("mp",me->query("mp")/3);
	}

	if(e && i<=e)
	{
	    say("凶猛的狗奇怪的看了你一眼。",me);
		say("凶猛的狗说：我要你找的东西呢？", me);
		SendMenu(me);
		return 0;
	}



	i=me->query("level");
	e=i/3;
	i=i-e+2*random(e);
	string shuiname;
	string shuiid;
	int shuitime;
	int shuiexp;

	int task = random(37);

	CRoom * troom;

	shuiname=GetARoom(gneerroom[task].name);
	troom=load_room(shuiname);
	
	static char goodname[15][20]={"袜子","帽子","钥匙","生死簿","银环","汉玉扳指","《短歌行》","陈年老酒","金丝鱼竿","糖凤凰","半月琴","环河镜","《若星汉的天空下》","烈风印","筮铁盘"};
	CContainer * goood;
	
	goood=load_item("giftbox");
	goood->set("name",goodname[random(15)]);
	goood->set("id","lost item");
	goood->set("value",0);
	goood->set("owner",me->query("id"));

	shuiexp=gneerroom[task].exp;
	shuitime=gneerroom[task].time;

	me->set("dog/name",shuiname);
	me->set("dog/areaname",gneerroom[task].name);
	me->set("dog/exp",shuiexp);
	me->set("dog/itemname",goood->querystr("name"));

// good:owner
// me:name areaname exp itemname overtime

    DTItemList search;
	POSITION p;
	CContainer * obje;
	CChar * allwho = NULL;
	
	CopyList(&search, troom->Get_ItemList());

	goood->move(troom);

	p = search.GetHeadPosition();
	while(p)
	{
		obje = search.GetNext(p);
		if( ! obje->Query(IS_LIVING) || obje==me )
			continue;
		
		allwho = (CChar *)obj;
		if( userp(allwho))
			continue;		

		if (random(2)==0)
			goood->move(allwho);
	}

	say(snprintf(msg, 255, "凶猛的狗道：我的%s(lost item)不见了，可能是上次去%s旅游的时候丢了。", goood->name(1),me->querystr("dog/areaname").c_str()), me);

	i=400-me->query("level");
	i=i+shuitime*2;
	i=(i+random(i))/2;
	me->set("dog/overtime",time(&t)+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "凶猛的狗道：给你%d分%d秒去找到它吧。", e,i), me);
	SendMenu(me);

	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish

int do_aq(CChar * me)
{
	if(!me->query("dog/overtime"))
	{
		say("我的记性不好，常常把东西丢掉，我希望你能帮我找回来。", me);
		say("找到的东西越多，给你的奖励就越高。", me);
		say("当然，如果要了任务而没完成，是要受惩罚的。", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	time_t t;
	char msg[255];

	i=time(&t);
	e=me->query("dog/overtime");
	if (i>e)
	{
		say("时间已经过了，要你找的东西已经对我没用啦。", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say("凶猛的狗叹了口气，道：我说我记性不好，你却来问我我要你找什么。。。", me); //不告诉:>
//	say(snprintf(msg, 255, "水栀子说道：啊，你现在的任务是寻找%s(%s)。", me->querystr("shui/name").c_str(),me->querystr("shui/id").c_str()), me);
//	say(snprintf(msg, 255, "水栀子说道：距离任务时限还有%d分%d秒……", e,i), me);
	SendMenu(me);
	return 1;
}

// shui/id shui/name shui/overtime shui/exp shui/finish




int do_cq(CChar * me)
{
	if(!me->query("dog/overtime"))
	{
		say("你并没有领取任务……", me);
		SendMenu(me);
		return 1;
	}
//还没想好怎么做。
		say("这个——梅海那小子今天下午光在发呆，到现在还没做呢。", me);
		SendMenu(me);
		return 1;
return 1;
}
*/

int do_lc(CChar * me)
{
	char msg[255];

	if(!me->query_temp("teapot/lcj2") || !me->query_temp("teapot/lcj3") || me->query_temp("teapot/lcj3")!=1 || !me->query_temp("teapot/lcj4") || me->query_temp("teapot/lcj4")!=1 || !me->query_temp("teapot/lcj5") || me->query_temp("teapot/lcj5")!=1 || !me->PresentName("poembook", IS_ITEM) )
	{
		if(! me->query_temp("teapot/xmdog"))
		{
			say("连城诀关系到一个很大的秘密……", me);
			say("而连城诀的秘密据说藏在一本书中。", me);
			say("若你能找到那本书给我，我有重谢！", me);

			me->set_temp("teapot/xmdog", 1);
		}
		else
			say("不是和你说找到连城决有重谢么！你还有完没完？！", me);

		SendMenu(me);
		return 1;
	}

	CContainer * obj;
	obj=me->PresentName("poembook", IS_ITEM);
	destruct(obj);
    message_vision("$N交给$n一本黄皮小册子。", me,this);
    message_vision("$N哈哈大笑，道：今天此书终于落在我的手里！多谢，多谢！",this);
	int i;
	i=(150-me->query("level"))*15;
	
	i=i+me->query_temp("teapot/lcj2")-current_time;
	i=random(i)+1;
    message_vision(snprintf(msg, 255, "$N获得了%d经验！", i), me,this);

	me->set_temp("teapot/lcj2",0l);
	me->set_temp("teapot/lcj3",0l);
	me->set_temp("teapot/lcj4",0l);
	me->set_temp("teapot/lcj5",0l);

	g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s完成了连城诀的任务，获得%ld点经验。", me->name(1), i));

	return 1;
}




static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$n看见$N走了过来，吠叫了两声。", who, me);

	return;
}


// good:owner
// me:name areaname exp itemname overtime

virtual int accept_object(CChar * who, CContainer * ob)
{
//	long i;
//	char msg[255];

/*	if ( ob->querystr("id") != "lost item" || ob->querystr("name") != who->querystr("dog/itemname") )
	{	
		say("凶猛的狗奇怪的看了一眼，说：这是什么东西？", who);
		SendMenu(who);
		return 0;
	}

	if ( ob->querystr("owner") != who->querystr("id") )
	{	
		say(snprintf(msg, 255, "凶猛的狗说道：我丢的%s不是这个，这个怕是别人丢掉的吧……", who->querystr("dog/itemname").c_str()), who);
		SendMenu(who);
		return 0;
	}



	long e;
	time_t t;

	e=who->query("dog/overtime");
	i=time(&t);

	if (i>e)
	{
		destruct(ob);	
		say("凶猛的狗叹了口气，道：现在它已经对我没用啦！", who);
		SendMenu(who);
		return 1;
	}
	
	who->add("dog/finish",1);
	i=who->query("dog/exp");
	e=who->query("dog/finish");
	if(e<20)
		i=i*(e+20)/20;		// Gains more exp 
	else
		i=i*2;				// Limit:2
	i=(random(i)+i)*4/3;	// keep i @ 1.

	who->add("combat_exp",i);
	who->del("dog/name");
	who->del("dog/itemname");
	who->del("dog/areaname");
	who->del("dog/exp");
	who->del("dog/overtime");
	 
    message_vision("$n对$N哈哈一笑，道：不错，不错。", who,this);
    message_vision(snprintf(msg, 255, "$N获得了%d经验！", i), who,this);
*/
	//1, 银铃的任务
	if(who->query_temp("银铃/判师") == ob->object_id())
	{
		say("哈哈！", who);
		say("我太高兴了！你真行啊！", who);
		say("说吧，你想求我什么事！", who);

		who->delete_temp("银铃/判师");
		who->set_temp("xmdog/判师", 1);

		char tmp[80];

		if(who->query("betrayer"))
			AddMenuItem("和它谈判师的事", snprintf(tmp, 80, "$9panshi %ld 1", object_id()), who);
		AddMenuItem("和它谈赏金的事", snprintf(tmp, 80, "$9panshi %ld 2", object_id()), who);
		AddMenuItem("没事", "", who);
		SendMenu(who);

		destruct(ob);
		return 1;
	}

	if (!ob->query("is_iron"))
		return 0;
	int i;
	i=who->query("teapot/referent");

	if (i && i>0)
		return 0;

	who->set_temp("teapot/iron",1);
	if(who->query_temp("自制"))
		who->delete_temp("自制");
	destruct(ob);

	return 1;
}


// good:owner
// me:name areaname exp itemname overtime


virtual void die()
{
	revive(1);
	message_vision("$N吠叫了两声。", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}





char * ccheck_legal_name(const char * name)
{
   int i;
   CVector v;
   CVector valid_char;
   unsigned char ch[3];
   
   v.append("你");
   v.append("我");
   v.append("他");
   v.append("她");
   v.append("它");
   v.append("再拔剑");
   v.append("请输入姓名");

   valid_char.append("。");
   valid_char.append("‘");
   valid_char.append("’");
   valid_char.append("“");
   valid_char.append("”");
   valid_char.append("，");
   valid_char.append("、");
   valid_char.append("—");
   valid_char.append("》");
   valid_char.append("《");
   valid_char.append("（");
   valid_char.append("）");
   valid_char.append("…");
   valid_char.append("！");
   valid_char.append("？");
   valid_char.append("￥");
   valid_char.append("；");
   valid_char.append("：");
   valid_char.append("　");
      
   i = strlen(name);
   
   if( (strlen(name) < 2) || (strlen(name) > 14 ) ) 
   {
		return "对不起，名字必须是 1 到 7 个中文字。";
   }

   while(i--) 
   {
	   ch[0] = (unsigned char)name[i];
	   if( ch[0] <=' ' ) 
	   {
		   return "对不起，名字不能用控制字元。";
	   }

	   if( i%2==0 )
	   {
		   if(! ( ch[0] > 160 && ch[0] <255) ) 

	   		   return "对不起，请您用「中文」取名字。";

		   ch[1] = (unsigned char)name[i + 1];
		   if(! ( ch[1] > 160 && ch[1] <255) ) 

	   		   return "对不起，请您用「中文」取名字。";
		   ch[2] = 0;
		   if(valid_char.find((char *)ch) != valid_char.end() )
			   return "对不起，请您起个象「名字」的名字。";			
	   }
   }


   if( v.find(name) != v.end()) 
   {
		return "对不起，这种名字会造成其他人的困扰。";
   }

   return "";
}


NPC_END;

// shui/id shui/name shui/overtime shui/exp shui/finish

