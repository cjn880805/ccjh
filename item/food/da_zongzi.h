//dazongzi.h ����

FOOD_BEGIN(CIda__zongzi);

virtual void create(int nFlag = 0)		
{
	set_name( "����");	
	set_weight(100);
	set("long", "һ��������������ӣ�����������Ҷ����һ�����㡣");
	set("unit", "��");
	set("value", 100);

};


virtual int do_use(CChar * me, CContainer * target)
{

	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�");

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

				message_vision("$N���������ӣ���ˮ��ʱ�������������̲�ס�ſ�Ѫ����һ�ڽ������������¡�" , me);

			else

				message_vision("$N���������ӣ�������ʱ��ɢ�������̲�ס����ĳ���һ�ڡ�" , me);

			if(me->query("kill/flee")<11)

			{

				if(me->query("kill/flee")>=me->query("kill/death"))

				{

					me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+1);

					me->del("kill/death");

				}

			}
			me->add("shop/����_baoming",1);
			message_vision("ֻ������������һ�£�����ʲô���������������³���һ����ԭ�����ǡ�������" , me);

			message_vision("$HIR$N�����˱����𵤣���Ѹ�ٽ���$N���ڸ�����ɢ�����������뵤��������澭������\n$N�ľ����͵�һ�񣬹�ϲ��ϲ��$N��������츳���һ��������!\n", me);

		}

		else

		{

			message_vision("$NС�İ����������ϵ���Ҷ������ð�Ű�����Ŵ�ף��ɰ��ĺ춹�����е��᲻��ҧ��ȥ��" , me);

			message_vision("$HIR������$N����˵Ķ���ƸУ������س�������ʦС���������ʱ����$N���������ʮ�ֺ��ʵġ�����", me);

			if(!me->query_temp("apply/per"))

				me->set_temp("apply/per",5);

		}

		break;

	case 1:

		if(!random(5))

		{

			if(me->query("per")<20)

				message_vision("$N���������ӣ���ˮ��ʱ�������������̲�ס�ſ�Ѫ����һ�ڽ������������¡�" , me);

			else

				message_vision("$N���������ӣ�������ʱ��ɢ�������̲�ס����ĳ���һ�ڡ�" , me);

			if(me->query("per")<38)

				me->add("per", 1);

			message_vision("ֻ������������һ�£�����ʲô���������������³���һ����ԭ�����ǡ�������" , me);

			message_vision("$HIR$N����һ�Ż�������ͻȻ�е�һ�ɵ������������Ĳ�������ɫ����ת�ף��ɰ�ת�졣\n���в������Ե��⡰��Τ���������ջ��治��!\n$N�����������ˣ�\n", me);

		}

		else

		{

			message_vision("$NС�İ����������ϵ���Ҷ������ð�Ű�����Ŵ�ף��ɰ��ĺ춹�����е��᲻��ҧ��ȥ��" , me);

			message_vision("$HIR������$N����˵Ķ���ƸУ������س�������ʦС���������ʱ����$N���������ʮ�ֺ��ʵġ�����", me);

			if(!me->query_temp("apply/per"))

				me->set_temp("apply/per",5);

		}

		break;

	case 2:

		if(random(3))

		{

			if(me->query("per")<20)

				message_vision("$N���������ӣ���ˮ��ʱ�������������̲�ס�ſ�Ѫ����һ�ڽ������������¡�" , me);

			else

				message_vision("$N���������ӣ�������ʱ��ɢ�������̲�ס����ĳ���һ�ڡ�" , me);

			message_vision("ֻ������������һ�£�����ʲô���������������³���һ����������һ����ң���ϸ��ȥ��ȴ������ӡ�ţ�" , me);

			message_vision("�������й�ϲ���н��������Ժ������ݽ������ɵ�С���������½���װ��һ����" , me);

			tell_object(me, "\n$HIRС�����Ƿ��������ϰ�֮��ǰ��������������һ�ݣ�����Ц�ɡ�");

			if(query("����"))

				bot=load_item(baowu1[random(121)]);

			else

				bot=load_item(baowu[random(78)]);

			bot->move(me);

			message_vision("$N�����һ������($HIR$n$COM)������\n", me,bot);

		}

		else

		{

			message_vision("$NС�İ����������ϵ���Ҷ������ð�Ű�����Ŵ�ף��ɰ��ĺ춹�����е��᲻��ҧ��ȥ��" , me);

			message_vision("$HIR������$N����˵Ķ���ƸУ������س�������ʦС���������ʱ����$N���������ʮ�ֺ��ʵġ�����", me);

			if(!me->query_temp("apply/per"))

				me->set_temp("apply/per",5);

		}

		break;

	case 3:

		if(me->query("per")<20)

			message_vision("$N���������ӣ���ˮ��ʱ�������������̲�ס�ſ�Ѫ����һ�ڽ������������¡�" , me);

		else

			message_vision("$N���������ӣ�������ʱ��ɢ�������̲�ס����ĳ���һ�ڡ�" , me);

		message_vision("ֻ������������һ�£�����ʲô���������������³���һ����������һ����ң���ϸ��ȥ��ȴ������ӡ�ţ�" , me);

		message_vision("�������й�ϲ���н��������Ժ�ɶ���ݽ��������ν�ͷǰ���������Ͻ�Ʒ��" , me);

		tell_object(me, "\n$HIRС�����Ƿ�ɶ���ݹ���֮��ǰ��������������һ�ݣ�����Ц�ɡ�");

		exp=me->query("level")*(50+random(50));

		me->add("combat_exp",exp);
		me->add("shop/����_exp",exp);

		message_vision(snprintf(msg, 255,"$N���ν�ͷ��ָ���£������%d��ʵս���齱����\n",exp), me);

		break;

	case 4:

		if(me->query("per")<20)

			message_vision("$N���������ӣ���ˮ��ʱ�������������̲�ס�ſ�Ѫ����һ�ڽ������������¡�" , me);

		else

			message_vision("$N���������ӣ�������ʱ��ɢ�������̲�ס����ĳ���һ�ڡ�" , me);

		message_vision("ֻ������������һ�£�����ʲô���������������³���һ����������һ����ң���ϸ��ȥ��ȴ������ӡ�ţ�" , me);

		message_vision("�������й�ϲ���н��������Ժ����Ǯׯ��������������������ϴ󽱡�" , me);

		tell_object(me, "\n$HIRС�����Ƿ�����Ǯׯ�ϰ�֮��ǰ��������������һ�ݣ�����Ц�ɡ�");

		money=me->query("level")*(200+random(200));

		RMB=load_item("coin");

		RMB->set_amount(money);

		RMB->move(me);
		me->add("shop/����_money",money);

		message_vision(snprintf(msg, 255,"$N���������Ǯׯ���͵�%d��ҡ�\n",money), me);

		break;

	case 5:

		message_vision("$NС�İ����������ϵ���Ҷ������ð�Ű�����Ŵ�ף��ɰ��ĺ춹�����е��᲻��ҧ��ȥ��" , me);

		message_vision("$HIR������$N����˵Ķ���ƸУ������س�������ʦС���������ʱ����$N���������ʮ�ֺ��ʵġ�����", me);

		me->set_temp("apply/per",5);

		break;

	}

	destruct(this);

	me->start_busy(2);
	me->add("shop/����",1);

	return 1;

}


FOOD_END;
