//newgift.h 神秘礼物

ITEM_BEGIN(CInewgift);

virtual void create(int nFlag = 0)		
{
	set_name( "神秘礼物","li wu");	
	set_weight(100);

	set("long", "这是一份新年礼物,打开盒子说不定有大惊喜!");
	set("unit", "个");
	set("value", 100);
};

virtual int Can_Use()
{
	return 1;
}


virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("别那么性急，先忙完了再来打开。");

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
		message_vision("$N小心翼翼的打开神秘礼物，一阵光芒四射之后......" , me);
		if(me->query("kill/flee")<11)
		{
			if(me->query("kill/flee")>=me->query("kill/death"))
			{
				me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+1);
				me->del("kill/death");
			}
		}
		message_vision("恭祝万事顺心！$HIW生有涯$COM为了让大家新的一年有个好身体，给$N送上了一颗保命金丹。 ", me);
		message_vision("$HIR$N服用了保命金丹！金丹迅速进入$N的内腑，发散成热流，化入丹田后融入奇经八脉。\n$N的精神猛的一振，恭喜恭喜！$N获得了上天赋予的一条新生命!\n", me);
		break;
	case 1:
		message_vision("$N小心翼翼的打开神秘礼物，一阵光芒四射之后......" , me);
		if(me->query("per")<38)
			me->add("per", 1);
		message_vision("恭祝新春快乐！$HIW蚀月$COM为了让你新春更加有魅力，亲手为你打扮。" , me);
		message_vision("$HIR$N的魅力增加了！\n", me);
		break;
	case 2:
		message_vision("$N满怀激动的打开了神秘礼物，只见白光一闪......" , me);
		message_vision("恭祝合家团圆！$HIW石化$COM感谢大家多年来的支持，从他的百宝箱里递了样东西给$N。" , me);
		bot=load_item(baowu1[random(121)]);
		bot->move(me);
		message_vision("$N获得了一件宝物($HIR$n$COM)奖励。\n", me,bot);
		break;
	case 3:
		message_vision("$N小心翼翼的打开神秘礼物，一阵光芒四射之后......" , me);
		message_vision("恭祝大展鸿图！$HIW无情$COM为了让$N新的一年事业有成，亲自指点了$N的武功！" , me);
		exp=me->query("level")*(50+random(50));
		me->add("combat_exp",exp);
		message_vision(snprintf(msg, 255,"$N在无情的指导下，获得了%d的实战经验奖励。\n",exp), me);
		break;
	case 4:
		money=me->query("level")*(200+random(200));
		message_vision("$N小心翼翼的打开神秘礼物，一阵光芒四射之后......" , me);
		message_vision("$N恭喜发财！$HIW寒雨$COM为了让$N一年有个好的开始，给$N送上了一个红包！" , me);
		message_vision(snprintf(msg, 255,"$HIR$N获得了由寒雨赠送的%d个金币。\n",money), me);
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
