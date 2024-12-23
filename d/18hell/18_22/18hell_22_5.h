//18hell_22.h
//十八地狱第十八层阿鼻地狱第5房间

ROOM_BEGIN(CR18hell_22_5);

virtual void create()			//Call it when Room Create
{
	set_name("阿鼻地狱");
	
	add_npc("diyu_shizhe22");

};

virtual int do_look(CChar * me)
{
	say("无数不同形状的铁门、铁窗、狱墙、岗亭半露于远处的岩层中，岩上有弯曲的石梯自上而下，石梯上有着鬼卒站哨和无数受刑者正在苦力。", me);
	say("顶部垂吊和横跨着各种大小铁链，链间蛛网密布，正中一巨型脚掌立于中央，直抵狱顶，无数罪人被踩于脚掌下，一巨蟒张开血盆大口咬着罪人缠于巨腿上，两眼不停窥视着罪人的动向。", me);
	say("左侧溜沙坡上无数罪人被鬼卒看押着正在不停地背沙。旁边，二鬼卒正在追赶和鞭打罪犯，强逼罪犯不间断地受苦。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
