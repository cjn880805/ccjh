// pub_chuanfu.c 老船夫
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_chuanfu);

virtual void create()
{
	set_name("老船夫","chuan fu");

	set("icon", old_man2);
	set("gender", "男性");
	set("age", 56);
	set("long","这是一个老船夫。饱经风霜的脸上透出一丝狡猾。他经常出海，以前曾经去过桃花岛。现在他拥有一艘大船可以出海。");
	
	set("combat_exp", 1000000);
	set("shen_type", 1);
	
	set("eff_hp",2000);
	set("hp",2000);
	set("max_mp", 1000);
	set("mp", 1000);
	set("mp_factor", 100);
	
	set_skill("force", 200);
	set_skill("unarmed", 400);
	set_skill("dodge", 200);
	set_skill("parry", 200);

	set_inquiry("桃花岛" , "桃花岛上是一群妖魔！不过有个小妖女很美丽，啧啧！");
	set_inquiry("出海" ,chu_hai);
		
 	carry_object("cloth")->wear();
	set("no_huan",1);
}

static char * chu_hai(CNpc * who ,CChar *me)
{
	if (EQUALSTR(me->querystr("family/family_name"), "桃花岛"))
	{
        message_vision("老船夫一招手，叫来几个年轻船夫。",me);
        message_vision("年轻船夫和$N上了船，一声「起锚」船就开走了，但老船夫却没上船......", me);
		tell_object(me, "大船终于停在了一个小岛边。你走下船来。" ) ;
		me->move (load_room("桃花岛海滩") );//没有该场景
        //me->Move (load_room("dahai"));//桃花岛大海
        //tell_object(me,  "你在海上航行了很久很久......."  ) ;
		//who->call_out(goto_taohua,10,me->object_id()) ;
       	return "";
	}
	else  
		message_vision("老船夫上上下下打量了$N一下：什么！出海？你不要命了？！船夫又想了一下：不过...如果给我一两金子，或许可以考虑。",me);
	me->set_temp ("出海" , 1 );
	return "";
}

virtual int accept_object(CChar * who, CContainer *ob)
{
	char msg[255];
    if (!who->query_temp("出海"))
    {
		message_vision("老船夫笑着对$N说：无功不受禄，您还是自己留着吧！", who);
		return 0 ;
    }

    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 10000) 
	{
        message_vision(snprintf(msg,255,"老船夫对$N说：好！既然这位%s如此看得起我，那我也拼上这条破船，舍命陪君子便了！" , query_respect(who)),who);
        who->delete_temp("出海" );
        message_vision("老船夫一招手，叫来几个年轻船夫。", who);
        message_vision("年轻船夫和$N上了船，一声「起锚」船就开走了，但老船夫却没上船......", who);
		tell_object(who, "大船终于停在了一个小岛边。你走下船来。" ) ;
		who->move (load_room("桃花岛") );
		destruct(ob);
        //who->move(load_room("dahai"));//桃花岛大海
        //tell_room(who->environment(),snprintf(msg,255,"老船夫看船走了，掂着手里的金子笑了：去桃花岛？送死的事情我可不干。只可惜我那几个听话的船夫，要被那帮人给吃掉了。嘿嘿，哈哈！"),who) ;
        //tell_object(who,  "你在海上航行了很久很久......."  ) ;
        //call_out(goto_taohua,10, who->object_id() ) ;
       	return 1;
	}
    else  
		message_vision("老船夫皱眉对$N说：您给的也太少了吧？", who);
	return 0;
}

/*
static void goto_taohua (CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)(ob->environment())->Present(param1);

	if(! me) return;

	tell_object(me, "大船终于停在了一个小岛边。你走下船来。" ) ;
	me->Move (load_room("/d/taohua/haitan") );//没有该场景
}
*/

NPC_END;