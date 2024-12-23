// linzhennan.c 林震南
//sound 2001-07-18

NPC_BEGIN(CNfuzhou_linzhennan);

virtual void create()
{
	set_name("林震西", "lin zhennan");
	set("gender", "男性");
	set("age", 45);
	set("icon",triggerman1);
	set("long", "他就是「福威镖局」的总镖头－－林震西。");
	
	set("combat_exp", 30000);
	set("shen_type", 1);
	
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 10);
	
	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("pixie_sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	map_skill("parry", "pixie_sword");
	map_skill("sword", "pixie_sword");
//	set("price", 100000);	

	set_inquiry("向阳老宅", "林震西说道：那是我从前在福建时住的家院，已经破败了。");
	set_inquiry("林图远", "林震西大怒：小孩子这么没礼貌，直呼先人名讳！");
	set_inquiry("运镖任务", "先付上押金再说。巨型镖车18万、大型镖车10万、中型8万、小型5万。考虑清楚，不要给错了。");
	set_inquiry("押运暗镖", "林震西四周忘了忘，小声的说道：走暗镖你有这个能耐吗？这个镖我可丢不起的。先押30000押金吧！");
	set_inquiry("聘请趟子手", ask_dashou);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
//	set("暗镖",1);  //暗镖开关
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	set("no_huan",1);
};

static char * ask_dashou(CNpc * npc , CChar * player)
{
	if(player->query_temp("biaoche/owner"))
	{
		if(player->query_temp("biaoche/money"))
		{
			player->delete_temp("biaoche/money");
			player->delete_temp("biaoche/owner");
			player->set_temp("biaoche/tangzishou",1);
			return "林震西说道：好吧，既然你对自己信心不足，我就派个趟子手陪你走一趟吧！";
		}
		else
		{
			player->set_temp("biaoche/dashou",1);
			return "林震西说道：镖局最近生意一直比较忙，我实在是腾不出什么人来呀！这样吧，你给我个15万，我再考虑考虑。";
		}
	}
	else
		return "林震西说道：你请趟子手做什么？！";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * bot1;
	char msg[255];
	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if (DIFFERSTR(ob->querystr("id"), "coin") )
	{	
		say("来接车运镖是需要留下押金的，这是祖宗传下来的规矩！", who);
		SendMenu(who);
		return 0;
	}
	if (ob->query("value") ==30000 && query("暗镖") && !who->query_temp("lin/baoguo/start"))
	{
		static char obj_man[15][20]={"inlun fawang","ding","xiaoyao nv","zhang sanfeng","huang laoguai","xuanci dashi", "wang chongyang",
			"zhang wudi","tie lao","yue bufan","long er","hong qigong","miejin shitai","duan zhengpu","ouyang feng"};
		static char obj_name[15][20]={"金轮明王","丁老仙","逍遥女","张三丰","黄老怪","玄赐大师", "王重阳",
			"张无敌","天山铁姥","岳不凡","龙儿","洪叫化","灭尽师太","段正朴","白老庄主"};
		
		int id=random(15);
		tell_object(who,"\n$HIR林震西悄悄的塞给了你一个东东，你仔细一看，原来只是个包裹。");
		tell_object(who,snprintf(msg, 255,"$HIR林震西压低了喉咙，轻声的和你说道：你把这个东西帮我悄悄的送给%s，事成之后，必有重谢。\n", obj_name[id]));
		bot1 = load_item("baoguo");
		bot1->set("owner1",who->id(1));
		bot1->set("obj",obj_man[id]);
		int exp,repute;
		if(who->query("level")<80)
		{
			exp=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/2);
			exp=int(exp/2+random(int(exp/2)));
			if(exp>3500) exp=3000+random(500);
			repute=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/5);
			repute=int(repute/2+random(int(repute/2)));
			if(repute>2500) repute=2000+random(500);
			if(who->query("repute")>0)repute=-repute;
			if(who->query_temp("lin/baoguo/count")>150 && !random(3))
				who->set_temp("lin/baoguo/count",int(who->query_temp("lin/baoguo/count")/(random(3)+1)));
		}
		else
		{
			exp=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/2);
			exp=int(exp/4+random(int(exp/4)));
			if(exp>6000) exp=5000+random(1000);
			repute=int(who->query("level")*(10+who->query_temp("lin/baoguo/count")*(1+random(2)))/5);
			repute=int(repute/4+random(int(repute/4)));
			if(repute>4000) repute=3000+random(1000);
			if(who->query("repute")>0)repute=-repute;
			if(who->query_temp("lin/baoguo/count")>150 && !random(3))
				who->set_temp("lin/baoguo/count",int(who->query_temp("lin/baoguo/count")/(random(3)+1)));
		}
		bot1->set("exp",exp);
		bot1->set("repute",repute);
		bot1->move(who);

		who->set_temp("lin/baoguo/start",1);
		who->set_temp("no_fei",1);
		who->set_weight(50000000);
		destruct(ob);
		return 1;
	}
	else if ((ob->query("value") !=180000)&&(ob->query("value") !=100000) && (ob->query("value") !=80000) &&(ob->query("value") !=50000))
	{	
		if (ob->query("value") ==150000 && who->query_temp("biaoche/dashou"))
		{
			who->set_temp("biaoche/money",1);
			who->delete_temp("biaoche/dashou");
			destruct(ob);
			return 1;
		}
		else
		{
			say("巨型镖车18万押金、大型镖车10万押金、中型镖车8万押金、小型镖车5万押金。", who);
			say("看清楚价格了，镖车一旦推出，概不退换的。", who);
			message_vision(snprintf(msg, 255, "你付了%d的钱。",ob->query("value")),this);
			SendMenu(who);
		}
		return 0;
	}

	CChar * bot = load_npc("wiz_biaoche");
	bot->set("主人",who->querystr("id"));
	if( ob->query("value") ==180000)
	{
		bot->set_name(snprintf(msg, 40, "%s的巨型镖车", who->name(1)));
		bot->set("type",6);//巨型镖车最高经验奖励为3万+7千，由镖车的HP除以这个参数获得
		bot->set("max_lev",180);
		bot->set("min_lev",130);
		bot->set("lev",4);
	}
	else if( ob->query("value") ==100000)
	{
		bot->set_name(snprintf(msg, 40, "%s的大型镖车", who->name(1)));
		bot->set("type",10*0.8);//大型镖车最高经验奖励为1万8千+4千5百，由镖车的HP除以这个参数获得
		bot->set("max_lev",160);
		bot->set("min_lev",90);
		bot->set("lev",1);
	}
	else if( ob->query("value") ==80000)
	{
		bot->set_name(snprintf(msg, 40, "%s的中型镖车", who->name(1)));
		bot->set("type",18*0.8);//中型镖车最高经验奖励为1万+2千5百，由镖车的HP除以这个参数获得
		bot->set("max_lev",110);
		bot->set("min_lev",75);
		bot->set("lev",2);
	}
	else
	{
		bot->set_name(snprintf(msg, 40, "%s的小型镖车", who->name(1)));
		bot->set("type",25*0.8);//小型镖车最高经验奖励为7千+2千，由镖车的HP除以这个参数获得
		bot->set("max_lev",90);
		bot->set("min_lev",60);
		bot->set("lev",3);
	}
	bot->move(environment());
	bot->set("ip/ip_address",who->querystr_temp("client/ip_address"));
	bot->set("ip/ip_local",who->querystr_temp("client/ip_local"));
	message_vision("林震西挥了挥手，后面走来一个帐房先生模样打扮的人，将押金收了起来。", who);
	message_vision("紧跟着后院中几个趟子手推出了一辆镖车，来到$N的面前。\n", who);

	for(int i=0;i<3;i++)
	{
		bot1 = load_item("biaoqi");
		bot1->set("主人",who->querystr("id"));
		bot1->set_name(snprintf(msg, 40, "%s的镖旗", who->name(1)));
		bot1->move(who);
	}
	who->set_temp("biaoche/owner",1);
	message_vision("林震西从怀中掏出了三面小型镖旗，递到$N的手上，说道：运镖江湖，全靠拳头是不行的。", who);
	message_vision("你再找两位帮手，一人送给他们一面镖旗，插在这辆镖车上面，相信江湖上的朋友见到这面镖旗，多少都会给些面子。\n", who);
	destruct(ob);
	add("yunbiao_count",1);
	return 1;
}

NPC_END;



