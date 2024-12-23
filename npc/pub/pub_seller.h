//seller.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_seller);

virtual void create()
{
	set_name("小贩","seller");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 32);
	set("long","这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。");
	set("combat_exp", 300);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");

	carry_good("walkingstick",20);
	carry_good("shoes",20);
	carry_good("bottle",20);
	carry_good("egg",20);

	carry_object("cloth")->wear();
	add_money(100);


};


VENDOR_END;
