//GaoCang_mg_22.h 地狱第18层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_22);

virtual void create()			
{
	set_name("阿鼻地狱");

	CDoor * a = add_yewaidoor("west", 23, 20);
	CDoor * b = add_yewaidoor("north", 23, 20);
	CDoor * c = add_yewaidoor("east", 23, 20);
	CDoor * d = add_yewaidoor("south", 23, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("烊铜地狱", "高昌烊铜地狱", "高昌阿鼻地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("无数不同形状的铁门、铁窗、狱墙、岗亭半露于远处的岩层中，岩上有弯曲的石梯自上而下，石梯上有着鬼卒站哨和无数受刑者正在苦力。", me);
	say("顶部垂吊和横跨着各种大小铁链，链间蛛网密布，正中一巨型脚掌立于中央，直抵狱顶，无数罪人被踩于脚掌下，一巨蟒张开血盆大口咬着罪人缠于巨腿上，两眼不停窥视着罪人的动向。", me);
	say("左侧溜沙坡上无数罪人被鬼卒看押着正在不停地背沙。旁边，二鬼卒正在追赶和鞭打罪犯，强逼罪犯不间断地受苦。", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
