//amends.h 补偿支票
//muri 2001-11-16

ITEM_BEGIN(CIamends)

void create(int nFlag = 0)	
{
	set_name("保险支票", "gift");
	set_weight(10);
    set("no_give", "好大方的人呀，不如给我吧！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_get", "巫师都赔的要破产了，你还忍心要双份的？");
    set("no_drop","这么珍贵的东西你也扔？！");

	set("long", "这是巫师补偿给你的保险支票。");
	set("unit", "个");	

	set("open_msg", "偷偷的看了一下支票上的面额");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	int exp = 2000 + random(1000)*me->query("level");
	LONG money = (5 + random(30)) * 2500;
 	char msg[255];
    
	me->add("combat_exp", exp);
	CMoney::Pay_Player(me, money);

	message_vision(snprintf(msg, 255, "$HIY$N%s，眼睛猛然一亮。", querystr("open_msg")), me);
	tell_object(me, snprintf(msg, 255, "$HIW你晃悠着这张支票，从巫师的钱包里面大模大样的掏走了%ld点金，顺便砍了他一刀，获得了%ld经验。", money,exp));
	destruct(this);
	return 1;
}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;
