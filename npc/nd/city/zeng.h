// zeng.h  曾柔
//zhangdongni 2001-07-18

NPC_BEGIN(CNcity_zeng);

virtual void create()
{

	set_name("温柔", "zeng rou");
	set("shen_type", 1);

	set("gender", "女性");
	set("age", 16);
	set("per", 25);
	set("con", 22);
	set("int", 22);
	set("dex", 20);
	set("str", 20);
	set("long",
                   "她是韦爵爷不知道第几房的小妾，在这里开个成衣铺，卖些不知道\n"
                   "哪来的衣服。有人说那都是韦爵爷从宫中弄出来的禁品。话这么说，\n"
                   "生意照样红活。\n");
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("icon", young_woman1);
/*	set("vendor_goods", ({
		__DIR__"cloth/belt",
		__DIR__"cloth/boots",
		__DIR__"cloth/bu-shoes",
		__DIR__"cloth/cloth",
		__DIR__"cloth/color-dress",
		__DIR__"cloth/fu-cloth",
		__DIR__"cloth/gui-dress",
		__DIR__"cloth/hat",
		__DIR__"cloth/jade-belt",
		__DIR__"cloth/liu-dress",
		__DIR__"cloth/marry-dress",
		__DIR__"cloth/mini-dress",
		__DIR__"cloth/moon-dress",
		__DIR__"cloth/pink-dress",
		__DIR__"cloth/qi-dress",
		__DIR__"cloth/red-dress",
		__DIR__"cloth/scarf",
		__DIR__"cloth/sha-dress",
		__DIR__"cloth/xian-cloth",
		__DIR__"cloth/xiu-cloth",
		__DIR__"cloth/xiu-scarf",
		__DIR__"cloth/yan-dress",
		__DIR__"cloth/zi-dress",
	}));
	
	
}

            carry_object("cloth")->wear();
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
*/
}
NPC_END;