// pub_chuanfu2.c 老船夫
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_chuanfu2);

virtual void create()
{
	set_name("老船夫2","chuan fu2");

	set("icon", old_man1);
	set("gender", "男性");
	set("age", 56);
	set("long",	"这是一个老船夫。饱经风霜的脸上什么也看不出来。");

	set("combat_exp", 1000000);
	set("shen_type", 1);

	set("str",800);

	set("max_mp", 100);
	set("mp", 100);
	set("mp_factor", 500);

	set_skill("force", 100);
	set_skill("unarmed", 300);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	
    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 2000)
	{
        message_vision(snprintf(msg,255,"老船夫对$N说：好！这位%s请上船吧。" ,query_respect(who) ), who);
		tell_object(who, "渡船终于到岸了。你走下船来。" ) ;
		destruct(ob);
		//me->Move (load_room("少林码头1")) ;//没有该场景
        
		//who->Move (load_room("/d/city/duchuan"));//没有该场景
		//call_out(goto_matou1, time, who->object_id()) ;
       	return 1;
	}
    else  
		message_vision("老船夫皱眉对$N说：您给的也太少了吧？", who);
	return 0;
}

/*
static void goto_matou1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);

	if(! me) return;
	tell_object(me, "渡船终于到岸了。你走下船来。" ) ;
	me->Move (load_room("/d/shaolin/matou1")) ;//没有该场景
}
*/
NPC_END;