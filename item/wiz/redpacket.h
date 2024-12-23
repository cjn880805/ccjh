//redpacket.h 红包
//lanwood 2001-09-29

ITEM_BEGIN(CIredpacket)

void create(int nFlag = 0)	
{
	set_name("红包", "gift");
	set_weight(10);
    set("no_give", "每个人只有一个，你都这么大方！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_get", "每个人只有一个，不要这么贪心！");
    set("no_drop","这么珍贵的东西你也扔？！");

	set("long", "这是庆祝节日的礼物。");
	set("unit", "个");	

	set("open_msg", "打开了红包");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	int exp = 2000 + random(1000);
	LONG money = (5 + random(30)) * 2500;
	char msg[255];
    
	me->add("combat_exp", exp);
	CMoney::Pay_Player(me, money);

	message_vision(snprintf(msg, 255, "$HIY$N%s，周身顿时被一片金色光芒笼罩。", querystr("open_msg")), me);
	tell_object(me, snprintf(msg, 255, "$HIW你被奖励了%ld点经验和%ld金。", exp, money));
	destruct(this);
	return 1;
}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;