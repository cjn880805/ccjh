//laoniansengren.h
//code by zwb
//12-16
//inherit F_DEALER;

VENDOR_BEGIN(CNDaLi_laoniansengren);

virtual void create()
{
	set_name("老年僧人","lao nian seng ren");

	set("gender", "男性" );
	set("age", 80);
	set("long","他是寺中掌管烟火的僧人。");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "老僧");
 	set("icon",old_monk);

	carry_good("xiang",20);

	set_inquiry("一阳指" ,ask_me);
 
	carry_object("c_jiasha")->wear();
}

virtual char * greeting(CChar * me)
{
	char msg[255];

	return snprintf(msg,255,"老年僧人笑咪咪地说道：这位%s买柱香吧。",query_respect(me));
}

static char * ask_me(CNpc * this_object , CChar * this_player)
{
	if(this_player->query_temp("marks/ask_tempyyz")==1)
	{
		this_player->add_temp("marks/ask_tempyyz",1);
		return "你去问问其它人吧，我也没有见过，听说有其他人看过。";
	}
	this_player->set_temp("marks/ask_tempyyz",0l);
	return "什么？你找错人了，我从没听说过。";
/*
	if(this_object->query_temp("mark/ask_temp2"))
	{
		this_object->set_temp("mark/ask_temp3",1);
		return "“失窃的那天晚上我看见一个黑影往后面跑了。“";
	}
	else
		return "“你胡说八道什么？”";
*/
}

VENDOR_END;
