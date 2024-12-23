//heimuya_zhang1.h 张乘风
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_zhang1);

virtual void create()
{
	set_name("张剩风", "zhang chengfeng");
	set("nickname", "金猴神魔");
	set("title", "日月神教长老");
	set("gender", "男性");
	set("age", 42);
	set("shen_type", -1);
	set("long", "他是日月神教长老。");
	set("attitude", "peaceful");

	set("per", 21);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man5);

	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 300);

	set("combat_exp", 1500000);
	set("shen_type", -1);
    
	set("chat_chance", 5);

	set_inquiry("黑木崖", "本教弟子或持教主令牌方能上崖！");
	set_inquiry("日月神教", "本教弟子或持教主令牌方能上崖！");
	set_inquiry("黑木令", "那是本教教主令牌，见牌如见教主亲临！");
//	set_inquiry("上崖" :   (: shang_ya :),);

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
	map_skill("club", "weituo_gun");
	map_skill("parry", "weituo_gun");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu_bu");

	create_family("日月神教", 2, "长老");

	carry_object("shutonggun")->wield();
	carry_object("cloth")->wear();
}

/*
int shang_ya()
{
    object ob, myenv ;
    ob = this_player ( ) ;
    if (ob->query("family/family_name") == "日月神教")
    {
        message_vision("张乘风一招手，崖上落下一个大吊篮。\n",ob);
        message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......\n", ob);
        myenv = environment (ob) ;
        ob->move ("/d/heimuya/basket");
	call_out("goto_heimuya", 10, ob) ;
       	return 1;
    }
    else  
    message_vision("张乘风上上下下打量了$N一下：什么！上崖？你的黑木令呢？！\n",ob);
    return 1;
}

int accept_object(object who, object ob)
{
    object myenv ;
    if (ob->query("id") == "heimu ling")
    {
        message_vision("张乘风对$N说：好！这位" + RANK_D->query_respect(who) + "不错，那就请吧！\n" , who);
        message_vision("张乘风一招手，崖上落下一个大吊篮。\n", who);
        message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......\n", who);
        myenv = environment (who) ;
        who->move ("/d/heimuya/basket");
	call_out("goto_heimuya",10,who) ;
       	return 1;
    }
    else  
    {
	message_vision("张乘风对$N说：你敢耍我？！\n", who);
        this_object()->kill_ob(who);
    }
    return 0;
}

void goto_heimuya (object ob)
{
    tell_object(ob , "你眼前一亮，一幢幢白色建筑屹立眼前，霎是辉煌。\n");
    ob->move ("/d/heimuya/chengdedian") ;
}
*/
NPC_END;