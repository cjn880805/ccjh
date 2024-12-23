// shaolin_zhang1.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_zhang1);

virtual void create()
{
    set_name("张凌波", "zhang chengfeng");
    set("nickname",  "金牛神魔"  );
    set("title", "日月神教长老");
    set("gender", "男性");
    set("age", 42);
    set("shen_type", -1);
    set("long","他是日月神教长老。");
    set("attitude", "peaceful");
    set("icon",old_man1);
	
    set("per", 21);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
	
    set("hp", 3000);
    set("max_hp", 9000);
    set("mp", 3000);
    set("max_mp", 3000);
    set("mp_factor", 300);
	
    set("combat_exp", 1500000);
    
	
    set_skill("force", 150);
    set_skill("kuihua_xinfa", 150);
    set_skill("unarmed", 150);
    set_skill("changquan", 150);
    set_skill("dodge", 150);
    set_skill("lingxu_bu", 150);
    set_skill("parry", 150);
    set_skill("club", 150);
    set_skill("weituo_gun", 150);
	
    map_skill("force", "kuihua_xinfa");
    map_skill("club", "wweituo_gun");
    map_skill("parry", "wweituo_gun");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "lingxu_bu");
	
    create_family("日月神教", 2, "长老");
    
    carry_object("shutonggun")->wield();
    carry_object("cloth")->wear();

	set_inquiry("黑木崖", "本教弟子或持教主令牌方能上崖！");
	set_inquiry("黑木令","那是本教教主令牌，见牌如见教主亲临！");
	set_inquiry("上崖",shang_ya);
	set("no_huan",1);
}

static char * shang_ya(CNpc *who,CChar *me)
{
    if ( EQUALSTR(me->querystr("family/family_name"), "日月神教"))
    {
        message_vision("张乘风一招手，崖上落下一个大吊篮。",me);
        message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......", me);

		goto_heimuya(me);

		/*
        me->Move (load_room("/d/heimuya/basket") );//没有该场景
		who->call_out(goto_heimuya, 10, me->object_id() ) ;
		*/

       	return 0;
    }
     
	return "张乘风上上下下打量了你一下：什么！上崖？你的黑木令呢？！";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
    if (EQUALSTR(ob->querystr("id"), "heimu ling"))
    {
        message_vision(snprintf(msg,255,"张乘风对$N说：好！这位%s 不错，那就请吧！" ,query_respect(who) ), who);
        message_vision("张乘风一招手，崖上落下一个大吊篮。", who);
        message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......", who);
        goto_heimuya(who);
       	return 1;
    }
    else  
    {
		message_vision("张乘风对$N说：你敢耍我？！", who);
        kill_ob(who);
    }
    return 0;
}

static void goto_heimuya (CChar * me)
{
	tell_object(me , "你眼前一亮，一幢幢白色建筑屹立眼前，霎是辉煌。");
    me->move (load_room("黑木崖成德殿")); //黑木崖成德殿
}

NPC_END;