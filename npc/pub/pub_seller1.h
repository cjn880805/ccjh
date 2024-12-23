//seller1.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_seller1);

virtual void create()
{
	set_name("小贩子","seller");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 32);
	set("long",	"这是个小贩，别看他长的老老实实，却专门骗人");
	set("combat_exp", 300);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");
	set_inquiry("大力丸" , "看你也是正人君子，怎么问这个？");

	carry_good("bottle",20);
	carry_good("egg",20);

    carry_object("cloth")->wear();
	add_money(100);

};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && !is_fighting())
	{
		if(DIFFERSTR(me->querystr("gender"), "女性"))
			message_vision("$N吆喝道：大力丸，大力丸，一夜管睡百姑娘！", this);
	}	
}

VENDOR_END;
