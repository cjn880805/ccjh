//dao_pin.h
//Lanwood 2000-01-10

SHAOLINDAO_BEGIN(CNshaolin_dao_pin);

virtual void create()
{
	set_name("道品禅师", "daopin chanshi");
	set("long",	"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。");

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",83);
	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);
	set("max_hp", 1200);
	
	set("mp", 450);
	set("max_mp", 450);
	set("mp_factor", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("finger", 51);
	set_skill("nianhua_zhi", 51);
	set_skill("blade", 54);
	set_skill("cibei_dao", 54);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");

	prepare_skill("finger", "nianhua_zhi");

	create_family("少林派", 39, "弟子");
	set_inquiry("木人巷","好消息，近日木人巷全面升级为木人２０００版……啊，你想过巷？先把铜铁令给我。");

    carry_object("jiedao")->wield();
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};


int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "cibei ling"))
		return CNshaolin_dao::accept_object(who, ob);		//lanwood 2001-04-13 不然不能挑战师尊了。

/*
	if( DIFFERSTR(who->querystr("family/family_name"), "少林派"))
		return notify_fail("你与本派素无来往，不知此话从何谈起？");
*/
	if ( DIFFERSTR(who->querystr("class"), "bonze"))
		return notify_fail("你是俗家弟子，要过木人阵做什么呢？");
	
	if ( current_time <query("passtime") )
	{
		message_vision("道品禅师道：现在已经有人在过阵了．",who);
		return notify_fail("道品禅师道：现在已经有人在过阵了．");
	}

	char msg[255];

	set("passtime",current_time + 180);

    message_vision(snprintf(msg, 255, "$N对着$n阴笑了一声，道：既然你想入地狱，可怪不得我……。"), this, who);
	destruct(ob);
	ob=load_room("少林寺木人巷");
	who->move(ob);

	return 1;
}


SHAOLINDAO_END;




