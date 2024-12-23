//xin.h 
//edit by wolfman
//2001-7-24
//取得天涯寒月牌

ITEM_BEGIN(CIguyuepai)

virtual void create(int nFlag = 0)		
{
	set_name("古月牌", "guyue pai");
	set_weight(10000);
	
	set("unit", "盒");
	set("material", "steel");
	set("long","据说如果能够收集到十二块不同的月牌，就有可能得到天涯寒月牌。");
};

virtual int do_look(CChar * me)
{
	say("你拿起月牌看了看，发现牌上好像刻有东西，当你想看清楚一点时却发现什么都没有。",me);
	say("据说如果能够收集到十二块不同的月牌，就有可能得到天涯寒月牌。",me);
	AddMenuItem("摆弄","$0combine $1",me);
	AddMenuItem("算了","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "combine") == 0)
		return do_combine(me, arg);
	return 0;
}

int do_combine(CChar *me, char * arg)
{
	char msg[255];
	
	char *bookname[]={"18niou",
		"sword_book1",
		"sword_book2",
		"jiuyin1",
		"hanyuepai",
		"literateb4",
		"lbook3",
		"book_iron",
		"quanpu",
		"miaoshou"};
	int i;
	
	CContainer * yu;
	yu=me->present("yuyue pai");
	
	CContainer * qian;
	qian=me->present("qianyue pai");
	
	CContainer * ming;
	ming=me->present("mingyue pai");
	
	CContainer * leng;
	leng=me->present("lengyue pai");
	
	CContainer * quan;
	quan=me->present("quanyue pai");
	
	CContainer * lian;
	lian=me->present("lianyue pai");
	
	CContainer * qing;
	qing=me->present("qingyue pai");
	
	CContainer * fu;
	fu=me->present("fuyue pai");
	
	CContainer * shui;
	shui=me->present("shuiyue pai");
	
	CContainer * ying;
	ying=me->present("yingyue pai");
	
	CContainer * xie;
	xie=me->present("xieyue pai");
	
	CContainer * an;
	an=me->present("anyue pai");
	
	if (yu && qian && ming && leng && quan && lian && qing && fu && shui && ying && xie && an)
	{
		destruct(yu);
		destruct(qian);
		destruct(ming);
		destruct(leng);
		
		destruct(quan);
		destruct(lian);
		destruct(qing);
		destruct(fu);
		
		destruct(shui);
		destruct(ying);
		destruct(xie);
		destruct(an);
		
		message_vision("$HIC突然十二块月牌同时发出强烈的光茫，你不由自主的闭上了眼睛……$COM",me);
		message_vision("$HIC喀哒一声响，$N感觉到十二月牌在$N手中合而为一，急忙睁开眼睛望去……$COM",me);
		i=random(10);
		yu=load_item(bookname[i]);		//动态装物品
		yu->move(me);					//把物品给玩家

		switch(i)
		{
		case 4:
			tell_object(me,"$HIY恭喜你得到了天涯寒月牌。$COM");
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n\n$HIC%s$HIY历尽千辛万苦，终于获得了天涯寒月牌。\n\n$COM", me->name(1)));
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s获得了天涯寒月牌。", me->name(1)));
			break;
			
		default:
			char msg[255];
			snprintf(msg,255,"$HIY突然$N脸色$HIR忽红$HIW忽白$HIY，身体摇摇欲坠，几乎要跌倒在地，原来$N得到的是%s。$COM",yu->querystr("name"));
			message_vision(msg,me);
		}
		return 1;	
	}
	
	tell_object(me,"你把月牌在手里摆弄了几下，什么事也没发生。");
	return 1;
	
/*
	ob->set_name("雨月牌", "yuyue pai");
	ob->set_name("浅月牌", "qianyue pai");
	ob->set_name("明月牌", "mingyue pai");
	ob->set_name("冷月牌", "lengyue pai");
	
	ob->set_name("泉月牌", "quanyue pai");
	ob->set_name("怜月牌", "lianyue pai");
	ob->set_name("清月牌", "qingyue pai");
	ob->set_name("水月牌", "shuiyue pai");
	
	ob->set_name("影月牌", "yingyue pai");
	ob->set_name("斜月牌", "xieyue pai");
	ob->set_name("暗月牌", "anyue pai");
	ob->set_name("浮月牌", "fuyue pai");
*/
}

ITEM_END;








