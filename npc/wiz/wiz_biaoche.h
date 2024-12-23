//wiz_biaoche.h 运镖任务
//秦波 2002、2、12


NPC_BEGIN(CNwiz_biaoche);

void create()
{
	set_name("镖车", "biao che");
	set("title", "福威镖局");
	set("gender", "雄性");
	set("icon", tiger);
    set("long","一匹骏马拉着的一辆小车，上面堆满了金银珠宝。");
	set("race", "野兽");
	set("age", 5);
	set("attitude","heroism");
	set("str", 1);
	set("dex", 1);
	set("con", 1);
	set("int", 1);
	set("repute", 10000);
	set("hp", 180000);
	set("max_hp", 180000);
	set("combat_exp", 1);
	set_weight(50000000);
	call_out(selfdest2,7200);
	set("no_huan",1);

};

void bl_move()
{
	char msg[255];
	CContainer * obj;
	obj=environment();

	CChar * player1;
	CChar * player2;
	CChar * player3;
	player1=(CChar * ) obj->present(querystr("keeper1"));
	player2=(CChar * ) obj->present(querystr("keeper2"));
	player3=(CChar * ) obj->present(querystr("keeper3"));
	set("eff_hp",query("max_hp"));

	static char baowu[121][20]={
		"baihongjian","bilinzhen","bishou","blade_1","blade_2","cleansword","dadao","zimuzhen",
		"dadao2","dafu","dagger","duanjian","fandog_sword","fenshuici","fork","fuchen","futou","green_sword",
		"green_water_sword","hammer","heilongbian",	"hothammer","huaji","hugesword","huoqiang","jinhua","jinlun",
		"jiujiebian","kandao","kuihuazhen","langyabang","leizhendang","longquansword","mandao","panguanbi",
		"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ring_whip","ruanjian","sea_wood",
		"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
		"sword_2","sword_3","taomujian","tiepipa","tongren","walkingstick","wandao","wodao","wuqing_sword","xblade",
		"xem_sword","xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun","youlongsword",
		"yufeng_zhen","yuxiao","yuzhu_zhang","zijinchui","zijin_staff",
		"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
		"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
		"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
		"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
		"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
		"rumengdai",
	};
	CContainer * bot;

	int i,j;
	int mp_b,hp_b;
	i=query("teapot/bl");

	if(player1->query("mp")<player1->query("max_mp")-800 && player1->query("hp")<player1->query("max_hp")-400)
	{
		if (random(i)>10 && player1->query("kill/guilt")==0)
		{
			mp_b=player1->query("max_mp")-player1->query("mp");
			if(mp_b>800)mp_b=800;
			mp_b=random(mp_b)+1;
			hp_b=player1->query("max_hp")-player1->query("hp");
			if(hp_b>400)hp_b=400;
			hp_b=random(hp_b)+1;
			message_vision(snprintf(msg, 255, "$HIR路边的一个大娘看着%s气喘嘘嘘、可怜兮兮的模样，一不忍心，叹了口气，转身从家里盛出一碗八宝粥来，递到了你的面前。", player1->name(1)),this);
			message_vision(snprintf(msg, 255,"$HIR%s喜出望外，连声道谢，狼吞虎咽的喝了下去，精力立即大振。", player1->name(1)),this);
			message_vision(snprintf(msg, 255, "$HIR%s的体力恢复了%d点、精力恢复了%d点。",player1->name(1),hp_b,mp_b), this);
			player1->add("mp",mp_b);
			player1->add("hp",hp_b);
		}
	}

	if(player2->query("mp")<player2->query("max_mp")-800 && player2->query("hp")<player2->query("max_hp")-400)
	{
		if (random(i)>10 && player2->query("kill/guilt")==0)
		{
			mp_b=player2->query("max_mp")-player2->query("mp");
			if(mp_b>800)mp_b=800;
			mp_b=random(mp_b)+1;
			hp_b=player2->query("max_hp")-player2->query("hp");
			if(hp_b>400)hp_b=400;
			hp_b=random(hp_b)+1;
			message_vision(snprintf(msg, 255, "$HIR路边的一个大娘看着%s气喘嘘嘘、可怜兮兮的模样，一不忍心，叹了口气，转身从家里盛出一碗八宝粥来，递到了你的面前。", player2->name(1)),this);
			message_vision(snprintf(msg, 255,"$HIR%s喜出望外，连声道谢，狼吞虎咽的喝了下去，精力立即大振。", player2->name(1)),this);
			message_vision(snprintf(msg, 255, "$HIR%s的体力恢复了%d点、精力恢复了%d点。",player2->name(1),hp_b,mp_b), this);
			player2->add("mp",mp_b);
			player2->add("hp",hp_b);
		}
	}

	if(player3->query("mp")<player3->query("max_mp")-800 && player3->query("hp")<player3->query("max_hp")-400)
	{
		if (random(i)>10 && player3->query("kill/guilt")==0)
		{
			mp_b=player3->query("max_mp")-player3->query("mp");
			if(mp_b>800)mp_b=800;
			mp_b=random(mp_b)+1;
			hp_b=player3->query("max_hp")-player3->query("hp");
			if(hp_b>400)hp_b=400;
			hp_b=random(hp_b)+1;
			message_vision(snprintf(msg, 255, "$HIR路边的一个大娘看着%s气喘嘘嘘、可怜兮兮的模样，一不忍心，叹了口气，转身从家里盛出一碗八宝粥来，递到了你的面前。", player3->name(1)),this);
			message_vision(snprintf(msg, 255,"$HIR%s喜出望外，连声道谢，狼吞虎咽的喝了下去，精力立即大振。", player3->name(1)),this);
			message_vision(snprintf(msg, 255, "$HIR%s的体力恢复了%d点、精力恢复了%d点。",player3->name(1),hp_b,mp_b), this);
			player3->add("mp",mp_b);
			player3->add("hp",hp_b);
		}
	}

	if (!random(15)&&random(i)>25 && player1->query("kill/guilt")==0&& player2->query("kill/guilt")==0&& player3->query("kill/guilt")==0)
	{
		hp_b=query("max_hp")-query("hp");
		if(hp_b>30000)hp_b=30000;
		hp_b=random(hp_b)+1;
		add("hp",hp_b);
		hp_b=hp_b*100/query("max_hp");
		message_vision(snprintf(msg, 255, "$HIR%s、%s、%s望着已经破烂不堪的镖车，不由连连的叹气。", player1->name(1), player2->name(1), player3->name(1)),this);
		message_vision(snprintf(msg, 255,"$HIR%s眼尖，忽然发现不远处有着一个铁匠铺，喜出望外：兄弟们，我们有救了，去那里把镖车修一下吧！", player2->name(1)),this);
		message_vision(snprintf(msg, 255, "$HIR镖车经过铁匠师傅的修理，耐久度上升了%ld点。",hp_b), this);
	}

	if (i==44 && player1->query("kill/guilt")==0 && player2->query("kill/guilt")==0 && player3->query("kill/guilt")==0)
	{
		if(player1->query("hp")<player1->query("max_hp"))player1->set("hp",player1->query("max_hp"));
		player1->set("eff_hp",player1->query("max_hp"));
		if(player1->query("mp")<player1->query("max_mp"))player1->set("mp",player1->query("max_mp"));
		if(player2->query("hp")<player2->query("max_hp"))player2->set("hp",player2->query("max_hp"));
		player2->set("eff_hp",player2->query("max_hp"));
		if(player2->query("mp")<player2->query("max_mp"))player2->set("mp",player1->query("max_mp"));
		if(player3->query("hp")<player3->query("max_hp"))player3->set("hp",player3->query("max_hp"));
		player3->set("eff_hp",player3->query("max_hp"));
		if(player3->query("mp")<player3->query("max_mp"))player3->set("mp",player1->query("max_mp"));

		message_vision(snprintf(msg, 255, "$HIR%s、%s、%s疲惫不堪的继续押着镖车继续前进，但神色中逐渐失去了起镖时的那股豪情壮志。", player1->name(1), player2->name(1), player3->name(1)),this);
		message_vision(snprintf(msg, 255,"$HIR前方突然又冒出一团人马，%s绝望的往地下一坐，从行囊中扯出了一块白布，打算用手上的武器挑起来，以希求保住一条命回家。", player2->name(1)),this);
		message_vision(snprintf(msg, 255, "$HIR迎面走来一个山大王模样打扮的壮汉，望了望镖车上飘扬的三面小镖旗，冲着%s、%s、%s抱了一个拳，说道：",player1->name(1), player2->name(1), player3->name(1)), this);
		message_vision("$HIR“原来三位是福威镖局林老爷子的朋友，失敬了。前面不远处就是兄弟的地盘，三位给个面子去敝处休息一阵，好让兄弟也报答一下林老爷子以前的一段香火恩情。”", this);
		message_vision(snprintf(msg, 255, "$HIR%s与%s互相望了望，半信半疑，但望着周围疲惫的伙计们，又看了看坐在地下的%s,不由的硬着头皮只好跟着这群绿林好汉上了山去。", player1->name(1), player3->name(1), player2->name(1)),this);
		message_vision(snprintf(msg, 255,"$HIR一夜无话，第二天%s、%s、%s安全无恙的下山之后，才体会到了镖车上插的小小镖旗真的在江湖上很有点分量。",player1->name(1), player2->name(1), player3->name(1)),this);
	}

	if (i==51)
	{
	    int lev=query("type");
		message_vision("前方一位大腹便便商人打扮的胖汉，笑嘻嘻的迎了过来，原来他就是委托护送这趟镖的主人。",this);
		set("chat_chance",0l);
		if(EQUALSTR(querystr("keeper1"), player1->querystr("id")))
		{
			int exp = query("hp") / lev + 1;
			set("keeper1_exp", exp +random(exp/4));
			player1->add("combat_exp",query("keeper1_exp"));
			int repute=random(100)+100;
			if(player1->query("repute")<0)
				repute=-repute;
			player1->add("repute",repute);
			if(EQUALSTR(querystr("主人"), player1->querystr("id")))
			{
				message_vision(snprintf(msg, 255, "%s招呼着趟子手将镖车赶了过去，向胖汉做了一个揖，说道：幸不辱命！",player1->name(1)),this);
				int mey =query("hp")/lev*5 + 1;
				mey =mey+random(mey);
				CMoney::Pay_Player(player1, mey);
				if(query("lev")==4 && (player1->query("baobiao/count_ok")%10)==8)
				{
					message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！同时获得镖银分红%d两！江湖威望上升了1点。$COM\n", query("keeper1_exp"),repute,mey), player1);
					player1->add("威望",1);
				}
				else
					message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！同时获得镖银分红%d两！$COM\n", query("keeper1_exp"),repute,mey), player1);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s压镖成功，获得%ld经验！同时获得镖银分红%d两！", player1->name(1), query("keeper1_exp"),mey));

			}
			else 
			{
				message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！！$COM\n", query("keeper1_exp"),repute), player1);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s压镖成功，获得%ld经验！", player1->name(1), query("keeper1_exp")));
			}

			del("keeper1");
			del("keeper1_exp");
			player1->delete_temp("保镖");
			player1->add("baobiao/count_ok",1);
			if(player1->query("baobiao/count_ok")/100*100==player1->query("baobiao/count_ok"))
			{
				bot=load_item(baowu[random(121)]);
				bot->move(player1);
				g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, 
					"$HIR%s(%s)连续保镖成功累计达到%d次，额外获得福威镖局赠送的一件宝物（$HIW%s$HIR）奖励。$COM\n", 
					player1->name(1),player1->id(1),player1->query("baobiao/count_ok"),bot->name(1)));
				tell_object(player1, snprintf(msg, 255, 
					"你连续保镖成功累计达到%d次，额外获得福威镖局赠送的一件宝物（$HIW%s$HIR）奖励。$COM\n", 
					player1->query("baobiao/count_ok"),bot->name(1)));
			}
			player1->add("baobiao/count_exp",query("keeper1_exp"));
			player1->set("baobiao/last_exp",query("keeper1_exp"));
			if(player1->query("zhang/问题3"))
				player1->add("zhang/保镖",1);
			if(player1->query("zhang/保镖")==5||player1->query("zhang/保镖")==15||player1->query("zhang/保镖")==30)
			{
				tell_object(player1, "$HIC\n你似乎隐隐约约的觉察出了一些什么，觉得有必要去向张首辅汇报一下。\n");
			}
			if(player1->query("tradepro/index")==9)
			{
				tell_object(player1,snprintf(msg, 255,  "\n$HIW恭喜你完成了%s委托你的任务！\n",player1->querystr("tradepro/quest_npc_name")));
				player1->set("tradepro/quest_ok",1);
			}
		}

		if(EQUALSTR(querystr("keeper2"), player2->querystr("id")))
		{
			int exp = query("hp") / lev + 1;
			set("keeper2_exp", exp +random(exp/4));
			player2->add("combat_exp", query("keeper2_exp"));
			int repute=random(100)+100;
			if(player2->query("repute")<0)
				repute=-repute;
			player2->add("repute",repute);
			if(EQUALSTR(querystr("主人"), player2->querystr("id")))
			{
				message_vision(snprintf(msg, 255, "%s招呼着趟子手将镖车赶了过去，向胖汉做了一个揖，说道：幸不辱命！",player2->name(1)),this);
				int mey =query("hp")/lev*5 + 1;
				mey =mey+random(mey);
				CMoney::Pay_Player(player2, mey);
				if(query("lev")==4 && (player2->query("baobiao/count_ok")%10)==8)
				{
					message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！同时获得镖银分红%d两！江湖威望上升了1点。$COM\n", query("keeper2_exp"),repute,mey), player2);
					player2->add("威望",1);
				}
				else
				message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！同时获得镖银分红%d两！$COM\n", query("keeper2_exp"),repute,mey), player2);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s压镖成功，获得%ld经验！同时获得镖银分红%d两！", player2->name(1), query("keeper2_exp"),mey));

			}
			else 
			{
				message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！$COM\n", query("keeper2_exp"),repute), player2);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s压镖成功，获得%ld经验！", player2->name(1), query("keeper2_exp")));
			}

			del("keeper2");
			del("keeper2_exp");
			player2->delete_temp("保镖");
			player2->add("baobiao/count_ok",1);
			if(player2->query("baobiao/count_ok")/100*100==player2->query("baobiao/count_ok"))
			{
				bot=load_item(baowu[random(121)]);
				bot->move(player2);
				g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, 
					"$HIR%s(%s)连续保镖成功累计达到%d次，额外获得福威镖局赠送的一件宝物（$HIW%s$HIR）奖励。$COM\n", 
					player2->name(1),player2->id(1),player2->query("baobiao/count_ok"),bot->name(1)));
				tell_object(player2, snprintf(msg, 255, 
					"你连续保镖成功累计达到%d次，额外获得福威镖局赠送的一件宝物（$HIW%s$HIR）奖励。$COM\n", 
					player2->query("baobiao/count_ok"),bot->name(1)));
			}
			player2->add("baobiao/count_exp",query("keeper2_exp"));
			player2->set("baobiao/last_exp",query("keeper2_exp"));
			if(player2->query("zhang/问题3"))
				player2->add("zhang/保镖",1);
			if(player2->query("zhang/保镖")==5||player2->query("zhang/保镖")==15||player2->query("zhang/保镖")==30)
			{
				tell_object(player2, "$HIC\n你似乎隐隐约约的觉察出了一些什么，觉得有必要去向张首辅汇报一下。\n");
			}
		}

		if(EQUALSTR(querystr("keeper3"), player3->querystr("id")))
		{
			int exp = query("hp") / lev + 1;
			set("keeper3_exp", exp + random(exp/4));
			player3->add("combat_exp", query("keeper3_exp"));
			int repute=random(100)+100;
			if(player3->query("repute")<0)
				repute=-repute;
			player3->add("repute",repute);
			if(EQUALSTR(querystr("主人"), player3->querystr("id")))
			{
				message_vision(snprintf(msg, 255, "%s招呼着趟子手将镖车赶了过去，向胖汉做了一个揖，说道：幸不辱命！",player3->name(1)),this);
				int mey =query("hp")/lev*5 + 1;
				mey =mey+random(mey);
				CMoney::Pay_Player(player3, mey);
				if(query("lev")==4 && (player3->query("baobiao/count_ok")%10)==8)
				{
					message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！同时获得镖银分红%d两！江湖威望上升了1点。$COM\n", query("keeper3_exp"),repute,mey), player3);
					player3->add("威望",1);
				}
				else
				message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！同时获得镖银分红%d两！$COM\n", query("keeper3_exp"),repute,mey), player3);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s压镖成功，获得%ld经验！同时获得镖银分红%d两！", player3->name(1), query("keeper3_exp"),mey));

			}
			else 
			{
				message_vision(snprintf(msg, 255, "$HIR$N押镖成功，获得了%d经验、%d的江湖声望！$COM\n", query("keeper3_exp"),repute), player3);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s压镖成功，获得%ld经验！", player3->name(1), query("keeper3_exp")));
			}

			del("keeper3");
			del("keeper3_exp");
			player3->delete_temp("保镖");
			player3->add("baobiao/count_ok",1);
			if(player3->query("baobiao/count_ok")/100*100==player3->query("baobiao/count_ok"))
			{
				bot=load_item(baowu[random(121)]);
				bot->move(player3);
				g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, 
					"$HIR%s(%s)连续保镖成功累计达到%d次，额外获得福威镖局赠送的一件宝物（$HIW%s$HIR）奖励。$COM\n", 
					player3->name(1),player3->id(1),player1->query("baobiao/count_ok"),bot->name(1)));
				tell_object(player3, snprintf(msg, 255, 
					"你连续保镖成功累计达到%d次，额外获得福威镖局赠送的一件宝物（$HIW%s$HIR）奖励。$COM\n", 
					player3->query("baobiao/count_ok"),bot->name(1)));
			}
			player3->add("baobiao/count_exp",query("keeper3_exp"));
			player3->set("baobiao/last_exp",query("keeper3_exp"));
			if(player3->query("zhang/问题3"))
				player3->add("zhang/保镖",1);
			if(player3->query("zhang/保镖")==5||player3->query("zhang/保镖")==15||player3->query("zhang/保镖")==30)
			{
				tell_object(player3, "$HIC\n你似乎隐隐约约的觉察出了一些什么，觉得有必要去向张首辅汇报一下。\n");
			}
		}
		if(! querystr("keeper1")[0] && !querystr("keeper2")[0]&& !querystr("keeper3")[0])
			call_out(selfdest1, 3);

		return ;	// 到达目的地！
	}

	if(!player1 || !player2 || !player3)
	{
	    message_vision("$HIR趟子手回头看看，见少了几位护镖的镖头，不由的有些慌乱，不时回头张望。。。",this);
		message_vision("$HIR趟子手回头看看，见护镖的镖头始终少了几位不到，终于乱做一团，不一会儿四处散去。",this);
		remove_call_out(selfdest);
		call_out(selfdest,1);
		return ;
	}
	else
	{
		message_vision(snprintf(msg, 255, "%s喝道：快走！快走！兄弟们，到了前头再去休息！\n",player1->name(1)), this);
		message_vision("趟子手挥舞着长鞭，赶着镖车向前方走去。",this);
	
//		static char bnline1[51][20]={"福州西","福州南","福州南门","泉州中洲桥","泉州莆仙平原","泉州山路4","泉州山路5","泉州北门","泉州","泉州西门吊桥","佛山林间道14","佛山林间道13","佛山林间道11","佛山林间道10","佛山林间道9","佛山林间道8","佛山东门","佛山西门","佛山西门","佛山林间道7","佛山林间道6","佛山林间道5","佛山林间道4","佛山林间道3","佛山林间道2","佛山林间道1","大理城黄土路","大理城南门","大理城西","大理城北门","大理城茶花山1","大理城茶花山2","大理城茶花山5","大理城茶花山南","大理城大叠水瀑布","大理城清溪三潭","大理城碧鸡山顶","大理城沿池小路2","大理城滇池沿岸1","大理城罗伽甸","大理城农田2","大理城农田3","大理城山路7","大理城山路8","大理城阳宗镇","大理城密林","大理城林中山涧","大理城半山竹林","大理城步雄部","大理城星云湖畔","大理城玉霞山"};
//		static char bnline2[51][20]={"福州西","福州南","福州南门","泉州中洲桥","泉州莆仙平原","泉州山路4","泉州山路3","泉州山路2","泉州山路1","泰山大驿道","泰山山脚","黄河岸边5","南阳城","北京汝州城","北京大驿道9","北京大驿道8","北京大驿道4","北京大驿道3","北京大驿道2","北京大驿道1","北京东南","北京皇城","北京大驿道5","黑木崖黄土路3","黑木崖平定州","黑木崖黄土路2","黑木崖乱石坡","黑木崖黄土路4","黑木崖龙门渡口","黄河2","黄河3","黄河永登","黄河沙土路","黄河古浪","黄河打柴沟","黄河乌鞘岭","黄河武威","黄河土门子","黄河石峡子","黄河冰草湾","黄河营盘水","黄河古长城","黄河","灵州宣和堡","灵州鸣沙洲","灵州青铜峡","灵州小坝","灵州黄羊滩","灵州西","灵州东","灵州大将军府"};

		static char bnline1[51][20]={"福州西","福州闽中大道","衡山黄土路","佛山南岭山口","武当黄土路2","武当黄土路3","武当松林","武当青石大道1","武当三不管","峨嵋小路","峨嵋青石阶","大理城官道1","大理城官道2","大理城官道3","大理城南诏德化碑","大理城太和城","大理城北门","大理城洱水桥","大理城下关城","大理城苍山中部","大理城苍山山路","大理城河上","大理城河边","大理城山林","大理城葛鲁城","大理城镇雄","大理城巴的甸","大理城东泸水河谷","大理城碧罗雪山","大理城山路2","大理城山路4","大理城山路5","大理城山路6","大理城古道","大理城绿玉溪沿岸","大理城双鹤桥","大理城南门","大理城林间小道2","大理城黑龙岭","大理城林间小道1","大理城清溪三潭","大理城碧鸡山顶","大理城沿池小路2","大理城滇池沿岸1","大理城罗伽甸","大理城农田2","大理城农田3","大理城山路7","大理城山路8","大理城阳宗镇","大理城桑林"};
		static char bnline2[51][20]={"福州西","福州南","福州南门","泉州中洲桥","泉州莆仙平原","泉州山路4","泉州山路3","杭州青石大道1","杭州青石大道2","杭州青石大道3","杭州洪春桥","杭州青石大道4","杭州青石大道5","杭州沿湖大道1","杭州沿湖大道2","杭州大路1","杭州沿湖大道3","杭州青石大道19","杭州青石大道20","杭州苏堤7","杭州苏堤6","杭州苏堤5","杭州苏堤4","杭州苏堤3","杭州苏堤2","杭州苏堤1","杭州青石大道6","杭州青石大道7","杭州青石大道8","杭州青石大道9","杭州青石大道10","杭州青石大道11","杭州青石大道12","杭州青石大道13","杭州青石大道14","杭州青石大道15","杭州玉皇山脚","杭州山路7","杭州玉皇山顶","杭州山路6","杭州玉皇山","杭州青石大道17","杭州青石大道18","杭州石屋洞","杭州满觉陇","杭州水乐洞","杭州烟霞洞","杭州山路5","杭州土路","杭州茅家埠","杭州黄泥岭"};
		static char bnline3[51][20]={"福州西","福州南","福州南门","泉州中洲桥","泉州莆仙平原","泉州山路4","泉州山路3","泉州山路2","泉州山路1","泰山大驿道","泰山山脚","黄河岸边5","南阳城","北京汝州城","北京大驿道9","北京大驿道8","北京大驿道4","北京大驿道3","北京大驿道2","北京大驿道1","北京东南","北京皇城","北京大驿道5","黑木崖黄土路3","黑木崖平定州","黑木崖黄土路2","黑木崖乱石坡","黑木崖黄土路4","黑木崖龙门渡口","黄河2","黄河3","黄河永登","黄河沙土路","黄河古浪","黄河打柴沟","黄河乌鞘岭","黄河武威","黄河土门子","黄河石峡子","黄河冰草湾","黄河营盘水","黄河古长城","黄河","灵州宣和堡","灵州鸣沙洲","灵州青铜峡","灵州小坝","灵州黄羊滩","灵州西","灵州东","灵州大将军府"};
		static char bnline4[51][20]={"福州西","福州闽中大道","衡山黄土路","佛山南岭山口","佛山北门","佛山东门","佛山东门","佛山林间道8","佛山林间道9","佛山林间道10","佛山林间道11","佛山林间道13","佛山林间道14","泉州西门吊桥","泉州","泉州北门","泉州山路5","泉州山路4","泉州莆仙平原","泉州山路4","泉州山路3","杭州青石大道1","杭州青石大道2","杭州青石大道3","杭州洪春桥","杭州青石大道4","杭州青石大道5","杭州沿湖大道1","杭州沿湖大道2","杭州大路1","杭州沿湖大道3","杭州青石大道19","杭州青石大道20","杭州苏堤7","杭州苏堤6","杭州苏堤5","杭州苏堤4","杭州苏堤3","杭州苏堤2","杭州苏堤1","杭州青石大道6","杭州青石大道7","杭州青石大道8","杭州青石大道9","杭州青石大道10","杭州青石大道11","杭州青石大道12","杭州青石大道13","杭州青石大道14","杭州清波门","杭州聚景园"};

		CRoom * troom;
		switch(query("teapot/idx"))
		{
		case 0:
			troom=load_room(bnline1[i]);
			break;
		case 1:
			troom=load_room(bnline2[i]);
			break;
		case 2:
			troom=load_room(bnline3[i]);
			break;
		case 3:
			troom=load_room(bnline4[i]);
			break;
		}
		if(atoi(querystr("劫镖者")))
			del("劫镖者");
		move(troom);
		player1->move(troom);
		player2->move(troom);
		player3->move(troom);

		if(player1->query_temp("biaoche/tangzishou")||player2->query_temp("biaoche/tangzishou")||player3->query_temp("biaoche/tangzishou"))
		{
			CNpc * tangzishou = load_npc("pub_tangzishou");
			tangzishou->set("owner",querystr("name"));
			tangzishou->move(troom);	
		}

		if (random(3000))
		{
			message_vision("燕——雄——京——兆——，我——武——维——扬",this);
		}
		else
		{
			message_vision("我——武——维——扬,燕——雄——京——兆——",this);
		}

		set("teapot/bl",i+1);
		//保镖人在保镖时确保不被玩家攻击
		if(player1)
			player1->set_temp("保镖",1);
		if(player2)
			player2->set_temp("保镖",1);
		if(player3)
			player3->set_temp("保镖",1);
		switch(query("teapot/idx"))
		{
		case 0:	
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s、%s、%s执行运镖任务，走到%s了。",player1->name(1),player2->name(1),player3->name(1),bnline1[i]));
			break;
		case 1:
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s、%s、%s执行运镖任务，走到%s了。",player1->name(1),player2->name(1),player3->name(1),bnline2[i]));
			break;
		case 2:
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s、%s、%s执行运镖任务，走到%s了。",player1->name(1),player2->name(1),player3->name(1),bnline3[i]));
			break;
		}
		for(j=0;j<10000;j++)
		{
		}
		return ;
	}
}

char * chat_msg()
{
	char msg[255];

	CContainer * obj;
	obj=environment();

	CChar * player1;
	CChar * player2;
	CChar * player3;
	player1=(CChar * ) obj->present(querystr("keeper1"));
	player2=(CChar * ) obj->present(querystr("keeper2"));
	player3=(CChar * ) obj->present(querystr("keeper3"));
	set("eff_hp",query("max_hp"));

	if(!player1 || !player2 || !player3)
	{
		message_vision("$HIR趟子手回头看看，见少了几位护镖的镖头，不由的有些慌乱，不时回头张望!",this);
		add("lost",1);
		if(query("lost")>50)
		{
			message_vision("$HIR趟子手回头看看，见护镖的镖头始终少了几位不到，终于乱做一团，不一会儿四处散去。",this);
			remove_call_out(selfdest);
			call_out(selfdest,3);
			return "";
		}
		return "";
	}

	if (!random(2))
	{
		if(random(4)==0)
		{
			message_vision("趟子手挥舞着镖旗，高声喝道：燕——雄——京——兆——.", this);
			message_vision("趟子手迎空击出一个响鞭，喊道：我——武——维——扬", this);
			if(!player1 || !player2 || !player3)
			{
				message_vision("$HIR趟子手回头看看，见少了几位护镖的镖头，不由的有些慌乱，不时回头张望。",this);
				add("lost",1);
				if(query("lost")>50)
				{
					message_vision("$HIR趟子手回头看看，见护镖的镖头始终少了几位不到，终于乱做一团，不一会儿四处散去。",this);
					remove_call_out(selfdest);
					call_out(selfdest,1);
					return "";
				}
				return "";
			}
			else
				bl_move();
		}
		else
		{
			if(!random(3))
			{
				if(!player1 || !player2 || !player3)
				{
					message_vision("$HIR趟子手回头看看，见少了几位护镖的镖头，不由的有些慌乱，不时回头张望。",this);
					add("lost",1);
					if(query("lost")>50)
					{
						message_vision("$HIR趟子手回头看看，见护镖的镖头始终少了几位不到，终于乱做一团，不一会儿四处散去。",this);
						remove_call_out(selfdest);
						call_out(selfdest,1);
						return "";
					}
					return "";
				}
				else
				{
					message_vision("突然窜出了几条黑影！为首者大喝道：",this);
					message_vision("$HIR此山是我开，",this);
					message_vision("$HIR此树是我栽;",this);
					message_vision("$HIR要想从此过，",this);
					message_vision("$HIR留下买路财！",this);
					call_robber();
				}
			}
			else
				switch(random(5))
				{
					case 0:
						message_vision(snprintf(msg, 255, "%s高声喊道：兄弟们，小心了，这里是强盗长期出没的地方，大家精神点。",player1->name(1)), this);
						break;
					case 1:
						message_vision(snprintf(msg, 255,"%s对着旁边的%s和%s说道：这里地势这么险恶，是强人经常出没的地方啊，两位兄弟，千万不要掉以轻心呀,上回我就差点栽在这里了。",player2->name(1),player1->name(1),player3->name(1)), this);
						break;
					case 2:
						message_vision(snprintf(msg, 255,"%s向着趟子手说：兄弟们加把油啊，把镖送到地头我请大家上太白楼一醉方休。",player3->name(1)), this);
						break;
					case 3:
						message_vision(snprintf(msg, 255,"%s对%s说道：我们走镖的还是多交朋友少结冤家的好，刀口上舔血的日子多个朋友日后好相见啊!",player1->name(1),player3->name(1)), this);
						break;
					case 4:
						message_vision("福~~~威~~~天~~~下~~、畅~~~~通~~~~无~~阻~~",this);
						break;
			}

		}
	}	
	else
	{
		switch(random(7))
		{
		case 0:
			message_vision(snprintf(msg, 255, "%s说道：这般天气热，晒的要杀人了！兄弟们，我们休息下吧！",player2->name(1)), this);
			break;
		case 1:
			message_vision(snprintf(msg, 255, "%s贼兮兮的凑到%s身边，笑嘻嘻的轻声说道：这么一车子银两看着真眼红，不如我们合伙做了%s,二一添做五，分了如何？",player3->name(1),player2->name(1),player1->name(1)), this);
			break;
		case 2:
			message_vision("趟子手挥舞着镖旗，高声喝道：燕——雄——京——兆——", this);
			break;
		case 3:
			message_vision("趟子手迎空击出一个响鞭，喊道：我——武——维——扬", this);
			break;
		case 4:
			message_vision(snprintf(msg, 255, "%s猛然看见旁边的树林中人影一闪，不由的一阵惊呼：兄弟们打起点精神，前边的地形好象不对。",player2->name(1)),this);
			break;
		case 5:
			message_vision("趟子手嘀咕起来：这天气真热啊，有一碗冰镇的酸梅汤就好了。",this);
			break;
		case 6:
			if(!DIFFERSTR(player3->querystr("gender"), "男性"))
				message_vision(snprintf(msg, 255, "%s黯然叹了起来：她在他乡还好吗？能等到我赚到这笔钱回家去娶她吗？",player3->name(1)),this);
			else
				message_vision(snprintf(msg, 255, "%s幽然叹道：真是一个没良心的人，居然要我出门来挣这种刀口上的钱来给他讨小老婆。",player3->name(1)),this);
			break;
		}
	}
	return "";
}

void call_robber()
{
	CChar * robber;
	CContainer * env = environment();

	CChar * player1;
	CChar * player2;
	CChar * player3;
	player1=(CChar * ) env->present(querystr("keeper1"));
	player2=(CChar * ) env->present(querystr("keeper2"));
	player3=(CChar * ) env->present(querystr("keeper3"));
	if(player2->query_temp("teapot/baobiao"))player2->delete_temp("teapot/baobiao");
	if(player3->query_temp("teapot/baobiao"))player3->delete_temp("teapot/baobiao");
	set("eff_hp",query("max_hp"));
	
	CFightRoom * obj;

	if(!player1 || !player2 || !player3)
	{
	   	message_vision("$HIR趟子手回头看看，见少了几位护镖的镖头，不由的有些慌乱，不时回头张望。",this);
		add("lost",1);
		if(query("lost")>30)
		{
			message_vision("$HIR趟子手回头看看，见护镖的镖头始终少了几位不到，终于乱做一团，不一会儿四处散去。",this);
			remove_call_out(selfdest);
			call_out(selfdest,3);
			return ;
		}
		return ;
	}
	else
	{
			obj = (CFightRoom *)load_item("fight_room");		
		
			obj->set("room_locked", FIGHT_LOCKED);
			obj->set_name( "劫镖战斗", "fight_room_jiebiao");		
			obj->move(env);

			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);

			if(player1) 
			{
				player1->move(obj);
				obj->Join_Team(player1, CFightRoom::FIGHT_TEAM_B);
			}

			if(player2) 
			{
				player2->move(obj);
				obj->Join_Team(player2, CFightRoom::FIGHT_TEAM_B);
			}
			if(player3) 
			{
				player3->move(obj);
				obj->Join_Team(player3, CFightRoom::FIGHT_TEAM_B);
			}
			if(player1->query_temp("biaoche/tangzishou")||player2->query_temp("biaoche/tangzishou")||player3->query_temp("biaoche/tangzishou"))
			{
				CNpc * tangzishou = load_npc("pub_tangzishou");
				tangzishou->set("owner",querystr("name"));
				tangzishou->move(obj);
				obj->Join_Team(tangzishou, CFightRoom::FIGHT_TEAM_B);
			}
		static char qiangdao[15][20]={"pub_liujue","pub_gaoming","pub_zhongbuliang","pub_baiyulang","pub_weiziyi","pub_mowentian","pub_liufeiyan","pub_caodongyun","pub_duguo","pub_guoda","pub_liuquan","pub_maxiaotian","pub_wanghu","pub_wuan","pub_zhuzhao"};
		static char tufei[17][20]={"pub_duguo","pub_guoda","pub_liuquan","pub_maxiaotian","pub_wanghu","pub_wuan","pub_zhuzhao","pub_sangyuan","pub_wangmu","pub_henmantian","pub_guochou","pub_zhaoba","pub_feiying","pub_huanhai","pub_xuecai","pub_youzhu","pub_zangma"};
		static char xiaozei[9][20]={"pub_wangmu","pub_henmantian","pub_guochou","pub_zhaoba","pub_feiying","pub_huanhai","pub_xuecai","pub_youzhu","pub_zangma"};

		for(int i=0;i<random(3)+2;i++)
		{
			if(query("lev")==1)
				robber = load_npc(qiangdao[random(15)]);
			else if(query("lev")==2)
				robber = load_npc(tufei[random(17)]);
			else if(query("lev")==3)
				robber = load_npc(xiaozei[random(9)]);
			else
				robber = load_npc(qiangdao[random(15)]);
			//NPC获得部分绝招防御功能
			if(query("lev")==1 || query("lev")==4)
			{
				robber->set("bigboss",1);
				if(!random(5-query("lev")+1))
					robber->set("no_缠字决",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_连字诀",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_千环套狗",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_相思无用",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_势合形离",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_点字决",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_天外飞龙",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_拼命",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_祭血神刀",1);
			}
			//增加NPC的防御、躲闪、攻击、HP、MP、总经验、先天属性
			if(query("lev")==4)
			{
				robber->add_temp("apply/defense", 300/query("type"));
				robber->add_temp("apply/parry", 300/query("type"));
				robber->add_temp("apply/damage", 300/query("type"));
				robber->add("max_hp",robber->query("max_hp"));
				robber->add("hp",robber->query("hp"));
				robber->add("max_mp",robber->query("max_mp")/3);
				robber->add("mp",robber->query("mp")/3);
				robber->add("combat_exp",robber->query("combat_exp")/2);
				robber->add("str",robber->query("str")/2);
				robber->add("dex",robber->query("dex")/2);
				robber->add("con",robber->query("con")/2);
				robber->add("int",robber->query("int")/2);
			}
			char msg[255];
			robber->set("id",snprintf(msg, 255,"%s%d",robber->querystr("id"),random(1000)));
			robber->move(obj);
			obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);				
		}
		obj->Begin_Fight(0);	
	}
}


static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CNwiz_biaoche * npc = (CNwiz_biaoche *)ob;

	CContainer * me = ob->environment();

	CUser * player1;
	CUser * player2;
	CUser * player3;
	CUser * player4;
	player1=find_online(npc->querystr("keeper1"));
	player2=find_online(npc->querystr("keeper2"));
	player3=find_online(npc->querystr("keeper3"));
	if(atoi(npc->querystr("劫镖者")))
		player4=find_online(npc->querystr("劫镖者"));
	
	if(player1)
	{
		player1->delete_temp("保镖");
		player1->del("baobiao/count_ok");
	}
	if(player2)
	{
		player2->delete_temp("保镖");
		player2->del("baobiao/count_ok");
	}
	if(player3)
	{
		player3->delete_temp("保镖");
		player3->del("baobiao/count_ok");
	}
	if(atoi(npc->querystr("劫镖者")))
	{
		if(player4)
		{
			int repute=random(100)+100;
			int lev=npc->query("type");
			if(player4->query("repute")<0)
				repute=-repute;
			player4->add("repute",repute);
			int mey =npc->query("max_hp")/lev*2;
			mey=mey+random(10000);
			CMoney::Pay_Player(player4, mey);
			char msg[255];
			tell_object(player4, snprintf(msg, 255,"\n你打劫成功，截获镖银%d。\n",mey));
			player4->command(snprintf(msg, 255, "chat 0 哈哈哈，就凭你们这三脚猫的功夫，也想出来混，大爷我今天心情好，就放你们一条生路，%s留下，其他人快滚！", npc->name(1)));
		}
	}
	else
	{
		if(userp(me))
			tell_object((CChar *)me, "镖车碎做一团，金银珠宝全部散落在地下，林中窜出一群强盗，一拥而上，不一会儿就抢了精光。");
		else
			tell_room(me, "镖车碎做一团，金银珠宝全部散落在地下，林中窜出一群强盗，一拥而上，不一会儿就抢了精光。");
	}
	destruct(ob);
	return;
}


static void selfdest1(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(userp(me))
		tell_object((CChar *)me, "$HIR一旁的一群壮汉不慌不忙的将镖银卸下车来，放到旁边的一辆大车上，缓缓的驶向远方。$COM");
	else
		tell_room(me, "$HIR一旁的一群壮汉不慌不忙的将镖银卸下车来，放到旁边的一辆大车上，缓缓的驶向远方。$COM");

	destruct(ob);
	return;
}

static void selfdest2(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
	return;
}

void die()
{
	selfdest(this, 0, 0);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obj;
	char msg[255];
	CChar * player2,*player3;

	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if(querystr("keeper3")[0])
		return notify_fail("燕——雄——京——兆——，我——武——维——扬");

	if(DIFFERSTR(ob->querystr("id"), "biaoqi") )
	{	
		say("没有镖局的镖旗，怎么行走江湖？", who);
		SendMenu(who);
		return 0;
	}

	if(DIFFERSTR(querystr("主人"), ob->querystr("主人")))
	{
		say("这个镖车有了主人，他邀请了你一起去保镖了吗？", who);
		SendMenu(who);
		return 0;
	}
	
	if(DIFFERSTR(who->querystr("id"), querystr("主人")))
	{
		if(EQUALSTR(querystr("ip/ip_address"),who->querystr_temp("client/ip_address")))
		{
			if(EQUALSTR(querystr("ip/ip_local"),who->querystr_temp("client/ip_local")))
			{
				say("我看你眼熟，你再怎么变我也看的出，老实说，是不是刚才你已经报过名来着？", who);
				SendMenu(who);
				return 0;
			}
		}
		if(EQUALSTR(querystr("ip1/ip_address"),who->querystr_temp("client/ip_address")))
		{
			if(EQUALSTR(querystr("ip1/ip_local"),who->querystr_temp("client/ip_local")))
			{
				say("我看你眼熟，你再怎么变我也看的出，老实说，是不是刚才你已经报过名来着？", who);
				SendMenu(who);
				return 0;
			}
		}
	}

	if(querystr("keeper1")[0] && querystr("keeper2")[0] && DIFFERSTR(querystr("keeper1"), who->querystr("id"))&& DIFFERSTR(querystr("keeper2"), who->querystr("id")))
	{
		say("你愿意来保镖，是件好事。", who);
	
		if(query("min_lev") > who->query("level"))
		{
			say("不过走镖是一件刀口舔血的勾当，你的水平。。。。", who);
			SendMenu(who);
			return 0;
		}
		if(query("max_lev") < who->query("level"))
		{			
			say("不过以大侠您的身手，来屈就着保这个小镖，是不是有点失了身份。。。。", who);
			SendMenu(who);
			return 0;
		}
		set("keeper3", who->querystr("id"));
		int exp = query("hp") / 5 + 1;
		set("keeper3_exp", exp + random(exp/2));

		obj = environment();
		player2=(CChar * ) obj->present(querystr("keeper1"));
		player3=(CChar * ) obj->present(querystr("keeper2"));

		if(querystr("keeper1")[0] && !player2 && querystr("keeper2")[0] && !player3)
		{
			del("keeper1");
			del("keeper1_exp");
			del("keeper2");
			del("keeper2_exp");
			del("keeper3");
			del("keeper3_exp");
			say("咦，刚才说要保镖的人去哪里了呀？你去找找，人少了可不安全呀！", who);
			SendMenu(who);
			return 0;
		}

//		player2->delete_temp("teapot/baobiao");
//		player3->delete_temp("teapot/baobiao");

		message_vision(snprintf(msg, 255,"$HIR趟子手们将%s的镖旗查插在了镖车上。",who->name(1)), this);
		message_vision("趟子手挥舞着镖旗，高声喝道：起镖了！",this);

		set("teapot/idx",random(4));
		set("chat_chance", 70);
		set_heart_beat(1);
		bl_move();
	}
	else if(querystr("keeper1")[0] && DIFFERSTR(querystr("keeper1"), who->querystr("id")))
	{
		say("你愿意来保镖，是件好事。", who);
	
		if(query("min_lev")>who->query("level"))
		{
			say("不过走镖是一件刀口舔血的勾当，你的水平。。。。", who);
			SendMenu(who);
			return 0;
		}
		if(query("max_lev")<who->query("level"))
		{			
			say("不过以大侠您的身手，来屈就着保这个小镖，是不是有点失了身份。。。。", who);
			SendMenu(who);
			return 0;
		}
		if (who->query_temp("teapot/baobiao"))
		{
			say("不要着急了，等着看看还有没有别人来一起护镖。", who);
			SendMenu(who);
			return 0;
		}
		
		set("keeper2", who->querystr("id"));
		int exp = query("hp") / 5 + 1;
		set("keeper2_exp", exp + random(exp/2));
		say("压镖这种危险的事，还是人多点好，还是等等吧,我们凑齐了三个人在走。", who);				 

		who->set_temp("teapot/baobiao",1);
		
		say("不要着急了，等着看看还有没有别人来一起护镖。", who);
		SendMenu(who);
		message_vision(snprintf(msg, 255,"$HIR趟子手们将%s的镖旗查插在了镖车上。",who->name(1)), this);
		set("ip1/ip_address",who->querystr_temp("client/ip_address"));
		set("ip1/ip_local",who->querystr_temp("client/ip_local"));
	}
	
	else
	{
		say("你愿意来保镖，是件好事。", who);
	
		if(query("min_lev")>who->query("level"))
		{
			say("不过走镖是一件刀口舔血的勾当，你的水平。。。。", who);
			SendMenu(who);
			return 0;
		}
		if(query("max_lev")<who->query("level"))
		{			
			say("不过以大侠您的身手，来屈就着保这个小镖，是不是有点失了身份。。。。", who);
			SendMenu(who);
			return 0;
		}
		if (who->query_temp("teapot/baobiao"))
		{
			say("不要着急了，等着看看还有没有别人来一起护镖。", who);
			SendMenu(who);
			return 0;
		}

		set("keeper1", who->querystr("id"));
		int exp = query("hp") / 5 + 1;
		set("keeper1_exp", exp + random(exp/2));
		say("压镖这种危险的事，还是人多点好，还是等等吧,我们凑齐了三个人在走。", who);

		who->set_temp("teapot/baobiao",1);

		say("不要着急了，等着看看还有没有别人来一起护镖。", who);
		SendMenu(who);
		message_vision(snprintf(msg, 255,"$HIR趟子手们将%s的镖旗查插在了镖车上。",who->name(1)), this);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(!strcmp(comm, "kill")  || !strcmp(comm, "fight") || !strcmp(comm, "cast") )
	{
		CContainer * env = environment();
		if(!me->query_temp("劫镖"))
		{
			message_vision("$HIR$N看着$n旁边的三位彪形大汉虎视耽耽的模样，手脚不由一软，打算劫镖的念头不由的散去。", me, this);
			return 1;
		}
		else if(DIFFERSTR(env->querystr("base_name"),"fight_room"))
		{
			set("劫镖者",me->id(1));
			
			CChar * player1;
			CChar * player2;
			CChar * player3;
			player1=(CChar * ) env->present(querystr("keeper1"));
			player2=(CChar * ) env->present(querystr("keeper2"));
			player3=(CChar * ) env->present(querystr("keeper3"));
			CFightRoom * obj;
			
			if(!player1 || !player2 || !player3)
			{
				return CNpc::handle_action(comm, me, arg);
			}
			else
			{
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name( "劫镖战斗", "fight_room_jiebiao");		
				obj->move(env);
				
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);

				move(obj);
				obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
				
				if(player1) 
				{
					player1->move(obj);
					obj->Join_Team(player1, CFightRoom::FIGHT_TEAM_B);
				}
				
				if(player2) 
				{
					player2->move(obj);
					obj->Join_Team(player2, CFightRoom::FIGHT_TEAM_B);
				}
				if(player3) 
				{
					player3->move(obj);
					obj->Join_Team(player3, CFightRoom::FIGHT_TEAM_B);
				}
				if(player1->query_temp("biaoche/tangzishou")||player2->query_temp("biaoche/tangzishou")||player3->query_temp("biaoche/tangzishou"))
				{
					CNpc * tangzishou = load_npc("pub_tangzishou");
					tangzishou->set("owner",querystr("name"));
					tangzishou->move(obj);
					obj->Join_Team(tangzishou, CFightRoom::FIGHT_TEAM_B);
				}
				me->set_temp("pending/PK",1);
				obj->Begin_Fight(0);
				return 1;
			}
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;




