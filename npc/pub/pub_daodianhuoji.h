//pub_daodianhuoji.c
//code by Fisho
//date : 2000-12-13

//inherit F_DEALER;

VENDOR_BEGIN(CNpub_daodianhuoji);

virtual void create()
{
	set_name("Ð¡»ï¼Æ","xiao huoji");

	set("icon", waiter);
	set("shen_type", 1);
	set("gender", "ÄÐÐÔ" );
	set("age", 33);
	
	set("combat_exp", 400);
	set("attitude", "friendly");
	
	carry_good("tudao",500);
	carry_good("dagger",500);
	carry_good("wandao",500);
	carry_good("gangdao",500);

	carry_object("cloth")->wear();
}

VENDOR_END;