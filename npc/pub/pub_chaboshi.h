// pub_chaboshi.c
//code by Fisho
//date : 2000-12-13

//inherit F_DEALER;

VENDOR_BEGIN(CNpub_chaboshi);

virtual void create()
{
	set_name("茶博士","cha boshi");

	set("icon", pub_boss);
	set("title", "茶馆老板");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 35);
	set("long","这个茶博士可是衡阳城里消息灵通人士，每日迎来送往，所以对城里的一举一动都了如指掌。");
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	carry_good("peanut",10);
	carry_good("tofu",10);

	carry_object("cloth")->wear();
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch(random(2)) 
	{
	case 0 :
		return snprintf(msg,255,"这位%s，哈你家快请进来喝杯热茶。",query_respect(ob));
	case 1 :
		return snprintf(msg,255,"哈你家！这位%s，哈你家小店卖茶不卖酒，哈你家！",query_respect(ob));
	}
	return "";
}
VENDOR_END;