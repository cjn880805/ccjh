//dazongzi.h 粽子

FOOD_BEGIN(CIda__zongzi);

virtual void create(int nFlag = 0)		
{
	set_name( "粽子");	
	set_weight(100);
	set("long", "一个香喷喷的肉粽子，包它的粽子叶泛出一股清香。");
	set("unit", "个");
	set("value", 100);

};


virtual int do_use(CChar * me, CContainer * target)
{

	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。");

	char msg[255];
	int exp,money;
	CContainer * bot;
	CContainer * RMB;
	static char baowu[78][20]={
		"baihongjian","bilinzhen","bishou","blade_1","blade_2","cleansword","dadao","zimuzhen",
		"dadao2","dafu","dagger","duanjian","fandog_sword","fenshuici","fork","fuchen","futou","green_sword",
		"green_water_sword","hammer","heilongbian",	"hothammer","huaji","hugesword","huoqiang","jinhua","jinlun",
		"jiujiebian","kandao","kuihuazhen","langyabang","leizhendang","longquansword","mandao","panguanbi",
		"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ring_whip","ruanjian","sea_wood",
		"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
		"sword_2","sword_3","taomujian","tiepipa","tongren","walkingstick","wandao","wodao","wuqing_sword","xblade",
		"xem_sword","xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun","youlongsword",
		"yufeng_zhen","yuxiao","yuzhu_zhang","zijinchui","zijin_staff",
	};

	static char baowu1[121][20]={
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

	switch(random(6))

	{

	case 0:

		if(!random(5))

		{

			if(me->query("per")<20)

				message_vision("$N剥开了粽子，口水顿时就流了下来，忍不住张开血盆大口一口将粽子囫囵吞下。" , me);

			else

				message_vision("$N剥开了粽子，香气顿时弥散开来，忍不住轻轻的尝了一口。" , me);

			if(me->query("kill/flee")<11)

			{

				if(me->query("kill/flee")>=me->query("kill/death"))

				{

					me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+1);

					me->del("kill/death");

				}

			}
			me->add("shop/粽子_baoming",1);
			message_vision("只听：“咯”的一下，竟有什么东西崩了牙，你吐出来一看，原来竟是。。。。" , me);

			message_vision("$HIR$N服用了保命金丹！金丹迅速进入$N的内腑，发散成热流，化入丹田后融入奇经八脉。\n$N的精神猛的一振，恭喜恭喜！$N获得了上天赋予的一条新生命!\n", me);

		}

		else

		{

			message_vision("$N小心剥开了粽子上的竹叶，看着冒着白气的糯米，可爱的红豆，真有点舍不得咬下去。" , me);

			message_vision("$HIR“由于$N是如此的多愁善感，所以重出江湖巫师小组决定，暂时奖励$N五点魅力是十分合适的……”", me);

			if(!me->query_temp("apply/per"))

				me->set_temp("apply/per",5);

		}

		break;

	case 1:

		if(!random(5))

		{

			if(me->query("per")<20)

				message_vision("$N剥开了粽子，口水顿时就流了下来，忍不住张开血盆大口一口将粽子囫囵吞下。" , me);

			else

				message_vision("$N剥开了粽子，香气顿时弥散开来，忍不住轻轻的尝了一口。" , me);

			if(me->query("per")<38)

				me->add("per", 1);

			message_vision("只听：“咯”的一下，竟有什么东西崩了牙，你吐出来一看，原来竟是。。。。" , me);

			message_vision("$HIR$N吞下一颗还春丹，突然感到一股电流穿过身体般的颤栗，脸色由青转白，由白转红。\n心中不禁暗自得意“这韦春花的手艺还真不错”!\n$N的魅力增加了！\n", me);

		}

		else

		{

			message_vision("$N小心剥开了粽子上的竹叶，看着冒着白气的糯米，可爱的红豆，真有点舍不得咬下去。" , me);

			message_vision("$HIR“由于$N是如此的多愁善感，所以重出江湖巫师小组决定，暂时奖励$N五点魅力是十分合适的……”", me);

			if(!me->query_temp("apply/per"))

				me->set_temp("apply/per",5);

		}

		break;

	case 2:

		if(random(3))

		{

			if(me->query("per")<20)

				message_vision("$N剥开了粽子，口水顿时就流了下来，忍不住张开血盆大口一口将粽子囫囵吞下。" , me);

			else

				message_vision("$N剥开了粽子，香气顿时弥散开来，忍不住轻轻的尝了一口。" , me);

			message_vision("只听：“咯”的一下，竟有什么东西崩了牙，你吐出来一看，竟发现一个金币，仔细看去，却见上面印着：" , me);

			message_vision("江湖商行恭喜你中奖，请您稍侯，衡阳茶馆将即刻派店小二奉送最新江湖装备一件。" , me);

			tell_object(me, "\n$HIR小的乃是奉衡阳茶馆老板之令前来给您送上礼物一份，还请笑纳。");

			if(query("宝贝"))

				bot=load_item(baowu1[random(121)]);

			else

				bot=load_item(baowu[random(78)]);

			bot->move(me);

			message_vision("$N获得了一件宝物($HIR$n$COM)奖励。\n", me,bot);

		}

		else

		{

			message_vision("$N小心剥开了粽子上的竹叶，看着冒着白气的糯米，可爱的红豆，真有点舍不得咬下去。" , me);

			message_vision("$HIR“由于$N是如此的多愁善感，所以重出江湖巫师小组决定，暂时奖励$N五点魅力是十分合适的……”", me);

			if(!me->query_temp("apply/per"))

				me->set_temp("apply/per",5);

		}

		break;

	case 3:

		if(me->query("per")<20)

			message_vision("$N剥开了粽子，口水顿时就流了下来，忍不住张开血盆大口一口将粽子囫囵吞下。" , me);

		else

			message_vision("$N剥开了粽子，香气顿时弥散开来，忍不住轻轻的尝了一口。" , me);

		message_vision("只听：“咯”的一下，竟有什么东西崩了牙，你吐出来一看，竟发现一个金币，仔细看去，却见上面印着：" , me);

		message_vision("江湖商行恭喜你中奖，请您稍侯，成都武馆将即刻派宋教头前来给您送上奖品。" , me);

		tell_object(me, "\n$HIR小的乃是奉成都武馆馆主之命前来给您送上礼物一份，还请笑纳。");

		exp=me->query("level")*(50+random(50));

		me->add("combat_exp",exp);
		me->add("shop/粽子_exp",exp);

		message_vision(snprintf(msg, 255,"$N在宋教头的指导下，获得了%d的实战经验奖励。\n",exp), me);

		break;

	case 4:

		if(me->query("per")<20)

			message_vision("$N剥开了粽子，口水顿时就流了下来，忍不住张开血盆大口一口将粽子囫囵吞下。" , me);

		else

			message_vision("$N剥开了粽子，香气顿时弥散开来，忍不住轻轻的尝了一口。" , me);

		message_vision("只听：“咯”的一下，竟有什么东西崩了牙，你吐出来一看，竟发现一个金币，仔细看去，却见上面印着：" , me);

		message_vision("江湖商行恭喜你中奖，请您稍侯，扬州钱庄将即刻派王供奉给您送上大奖。" , me);

		tell_object(me, "\n$HIR小的乃是奉扬州钱庄老板之命前来给您送上礼物一份，还请笑纳。");

		money=me->query("level")*(200+random(200));

		RMB=load_item("coin");

		RMB->set_amount(money);

		RMB->move(me);
		me->add("shop/粽子_money",money);

		message_vision(snprintf(msg, 255,"$N获得了扬州钱庄赠送的%d金币。\n",money), me);

		break;

	case 5:

		message_vision("$N小心剥开了粽子上的竹叶，看着冒着白气的糯米，可爱的红豆，真有点舍不得咬下去。" , me);

		message_vision("$HIR“由于$N是如此的多愁善感，所以重出江湖巫师小组决定，暂时奖励$N五点魅力是十分合适的……”", me);

		me->set_temp("apply/per",5);

		break;

	}

	destruct(this);

	me->start_busy(2);
	me->add("shop/粽子",1);

	return 1;

}


FOOD_END;
