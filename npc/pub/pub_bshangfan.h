VENDOR_BEGIN(CNPub_bshangfan);

void create()
{
	set_name("台夷妇女","bshangfan");

	set("icon", young_woman6);
	set("gender", "女性" );
	set("age", 32);
	set("long", "一个台夷妇女，背着个竹篓贩买些丝织物品和手工艺品。");
	set("combat_exp", 2500);
    set("per", 17);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");

	carry_good("ttoujin", 50);
	carry_good("tduanqun", 50);

	add_money(100);


};

VENDOR_END;
