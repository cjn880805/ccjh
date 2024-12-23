//wyshangfan.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_wyshangfan);

virtual void create()
{
	set_name("乌夷商贩","shangfan");

	set("icon", drugstore_boss);
	set("gender", "男性" );
	set("age", 22);
	set("long", "一位乌夷族的商贩，挑着一担皮毛野味在贩卖。");
	set("combat_exp", 5000);
    set("str", 22);
    set("dex", 11);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");
	carry_good("wdahui", 50);

	add_money(100);

};

VENDOR_END;
