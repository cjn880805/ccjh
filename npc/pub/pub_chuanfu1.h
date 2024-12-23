// pub_chuanfu1.c 船夫
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_chuanfu1);

virtual void create()
{
	set_name("船夫1","chuan fu1");

	set("icon", cateran);
	set("gender", "男性");
	set("age", 36);
	set("long", "这是一个松花江上的船夫。饱经风霜的脸上透出东北人的豪爽。");
	
	set("combat_exp", 10000);
	set("shen_type", 1);
	
	set("eff_hp",800);
	set("hp",800);
	set("max_mp", 100);
	set("mp", 100);
	set("mp_factor", 10);
	
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 10000)
    {
        message_vision(snprintf(msg,255,"船夫对$N说：好！既然这位%s要过江，那我就送你上这条船吧！" ,query_respect(who)), who);
        message_vision("船夫和$N上了船，一声「起锚」船就张帆离岸了......", who);
        //who->Move (load_room("关外松花江"));//没有该场景
		tell_object(who , "船很快停靠彼岸。你抬脚跨出船来。" ) ;
		who->move(load_room("关外船厂"));//关外船厂
		destruct(ob);
        
       	return 1;
    }
    else  
    {
		message_vision("船夫皱眉对$N说：就这点？你另找高明吧！说完掉头就走了。", who);
        destruct(this);
		return 0;
    }
}

NPC_END;