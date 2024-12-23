VENDOR_BEGIN(CNPub_pihuoshang);

virtual void create()
{
	set_name("皮货商","pihuoshang");

	set("icon", pawnshop_boss);
	set("gender", "男性" );
	set("age", 25);
	set("long","这是一位皮货商，他自己也是满身皮裘。");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 30);

	set("chat_chance", 20);

	carry_good("piqiu",  50);
	carry_good("goupi", 50);
	carry_good("diaopi", 50);
	carry_good("hupi", 50);
	carry_good("shepi", 50);
	carry_good("boots", 50);
	carry_good("pixue", 50);
	carry_good("beixin", 50);
	carry_good("shoutao", 50);
	carry_good("yaodai", 50);
};


VENDOR_END;
