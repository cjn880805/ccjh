// pub_zhangfang.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhangfang);

virtual void create()
{
	set_name("账房老夫子","lao fuzi" );

	set("icon", drugstore_boss);
	set("gender", "男性");
	set("age", 56);
	set("long","这是一个见钱眼开的老账房。饱经风霜的脸上透出一丝狡猾。");
	
	set("combat_exp", 10000);
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
 	carry_object("cloth")->wear();

	set_inquiry ("学费"  , "先交五百金！");
	set("no_huan",1);
	
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
/*    if (who->query("combat_exp")>= 10000)	//原来3500太少。lanwood 2001-02-24
    {
        say("你的武功应该历练江湖才能再长进，不能埋没在这里了。", who);
		SendMenu(who);
		return 0;
    }
*/
    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 500)
    {
        who->set_temp("marks/jinniu_paied",1);
        say(snprintf(msg,255,"好！既然这位%s如此上进，那就找师傅学吧！" ,query_respect(who) ), who);
		SendMenu(who);
		destruct(ob);
       	return 1;
    }
    
    say("您给的也太少了点儿吧？", who);
	SendMenu(who);
	return 0;
}

NPC_END;