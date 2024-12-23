//newgift.h ��������

ITEM_BEGIN(CInewgift);

virtual void create(int nFlag = 0)		
{
	set_name( "��������","li wu");	
	set_weight(100);

	set("long", "����һ����������,�򿪺���˵�����д�ϲ!");
	set("unit", "��");
	set("value", 100);
};

virtual int Can_Use()
{
	return 1;
}


virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("����ô�Լ�����æ���������򿪡�");

	char msg[255];
	int exp,money;
	CContainer * bot;
	CContainer * RMB;
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
	switch(random(5))
	{
	case 0:
		message_vision("$NС������Ĵ��������һ���â����֮��......" , me);
		if(me->query("kill/flee")<11)
		{
			if(me->query("kill/flee")>=me->query("kill/death"))
			{
				me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+1);
				me->del("kill/death");
			}
		}
		message_vision("��ף����˳�ģ�$HIW������$COMΪ���ô���µ�һ���и������壬��$N������һ�ű����𵤡� ", me);
		message_vision("$HIR$N�����˱����𵤣���Ѹ�ٽ���$N���ڸ�����ɢ�����������뵤��������澭������\n$N�ľ����͵�һ�񣬹�ϲ��ϲ��$N��������츳���һ��������!\n", me);
		break;
	case 1:
		message_vision("$NС������Ĵ��������һ���â����֮��......" , me);
		if(me->query("per")<38)
			me->add("per", 1);
		message_vision("��ף�´����֣�$HIWʴ��$COMΪ�������´�����������������Ϊ���硣" , me);
		message_vision("$HIR$N�����������ˣ�\n", me);
		break;
	case 2:
		message_vision("$N���������Ĵ����������ֻ���׹�һ��......" , me);
		message_vision("��ף�ϼ���Բ��$HIWʯ��$COM��л��Ҷ�������֧�֣������İٱ����������������$N��" , me);
		bot=load_item(baowu1[random(121)]);
		bot->move(me);
		message_vision("$N�����һ������($HIR$n$COM)������\n", me,bot);
		break;
	case 3:
		message_vision("$NС������Ĵ��������һ���â����֮��......" , me);
		message_vision("��ף��չ��ͼ��$HIW����$COMΪ����$N�µ�һ����ҵ�гɣ�����ָ����$N���书��" , me);
		exp=me->query("level")*(50+random(50));
		me->add("combat_exp",exp);
		message_vision(snprintf(msg, 255,"$N�������ָ���£������%d��ʵս���齱����\n",exp), me);
		break;
	case 4:
		money=me->query("level")*(200+random(200));
		message_vision("$NС������Ĵ��������һ���â����֮��......" , me);
		message_vision("$N��ϲ���ƣ�$HIW����$COMΪ����$Nһ���и��õĿ�ʼ����$N������һ�������" , me);
		message_vision(snprintf(msg, 255,"$HIR$N������ɺ������͵�%d����ҡ�\n",money), me);
		RMB=load_item("coin");
		RMB->set_amount(money);
		RMB->move(me);
		break;
	}
	destruct(this);
	me->start_busy(2);
	return 1;
}

ITEM_END;
