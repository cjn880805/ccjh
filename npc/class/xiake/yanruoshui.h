//longnv.h
//code by zwb
//12-23

NPC_BEGIN(CNxiake_yanruoshui);

virtual void create()
{
		set_name("燕若水","yan ruoshui");

        set("gender", "男性");
        set("age", 28);
        set("long","这就是武林七公子之一的燕若水，无双无对的一个人。");
        set("title","销魂蚀骨");
        set("attitude", "friendly");
		set("icon",young_man1);

        set("per", 40);
        set("str", 40);
        set("int", 37);
        set("con", 36);
        set("dex", 58);

		set("chat_chance", 6);
		set("chat_chance_combat", 40);

        set("hp", 20500);
        set("max_hp", 20500);
        set("mp", 5000);
        set("max_mp", 5000);
        set("mp_factor", 400);

        set("combat_exp", 8000000);

        set_skill("force", 400);
        set_skill("xuanwu_douqi", 400);

        set_skill("sword", 370);
        set_skill("misssword",370);
        set_skill("viviensword",370);

        set_skill("blade", 370);
        set_skill("missblade",370);

		set_skill("parry", 360);

        set_skill("literate",360);

        set("rank_info/respect", "燕公子");

        map_skill("force", "xuanwu_douqi");
        map_skill("sword", "misssword");
        map_skill("blade", "missblade");
        map_skill("parry", "viviensword");

        create_family("落月山庄", 1, "庄主");

//        carry_object("bamboosword")->wield();
		carry_object("mujian")->wield();		//no bamboosword lanwood 2001-03-28
		set("class","traveller");

}

virtual char * chat_msg_combat(CChar * player)
{
//	char msg[255];
	if (!random(10))
	{
		perform_action("force xiruo", 1);
		return 0;
	}
	if (random(2))
		perform_action("force budu", 1);
	else
		perform_action("sword xiangsi", 1);
	return 0;
}

virtual char * chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "燕若水负手看着白云，悠悠道：山无陵，天地合，冬雷阵阵，夏雨雪……";
	case 1:
		return "燕若水望着远方涛涛大海，叹道：人间最苦是相思……";
	case 2:
		return "燕若水头也不回，哼了一声：你平素如此轻浮，怎么能体会真正的相思个中情意？";
	case 3:
		return "燕若水叹道：燕某人一生偏激，作事随心而行，虽潦倒落魄而不后悔，只是害惨了……";
	case 4:
		return "燕若水低头沉思半晌，眼中竟有泪光闪动。";
	}
	return "";
}



virtual void attempt_apprentice(CChar  * ob)
{
	if(current_time - (int) ob->query("last_time_app_master_yan") < 172800)
	{
        message_vision("燕若水笑道：你怎么这么快又回来了．．．",ob);
        return;
    }

	if(ob->query("mp_factor") < 150)
	{
        message_vision("燕若水笑道：你对武功的了解还不够．．．",ob);
		return;
	}

	if( random(400) || random((ob->query_int()+ob->query_str()+ob->query_dex()+ob->query_con())) >  50 || query("already"))
	{
		message_vision("燕若水淡淡一笑，道：我可不想误人子弟．．．你还是去再历练历练吧。",ob);
		ob->set("last_time_app_master_yan",t);
        return;
    }
	message_vision("燕若水仿佛想起了自己的初恋情人，出神了半天．．．",ob);
    command("sigh");
	message_vision("燕若水淡淡一笑，道：既是如此，我就收下你吧．．．",ob);
	recruit_apprentice(ob);
	set("already",1);
}

NPC_END;
