//wutianliang.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_wutianliang);

virtual void create()
{
	set_name("吴天良","wutianliang");

	set("icon", general);
	set("title", "成都提督");

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long","吴天良大人原来只是一个参将，自从给冲郎变成小白脸后，居然官运亨通，不但提为总兵，还能出督全川之兵。");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	carry_object("dadao2")->wield();
	carry_object("jjunfu")->wear();
	carry_object("parry_book")->wear();
	add_money(1000);
	set("no_huan",1);

};

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成");
	
	if ( EQUALSTR(ob->querystr("id"), "gongting mifang") && EQUALSTR(ob->querystr("name"), "宫廷秘方") )
	{
		if(me->query("zhang/renwu5")==2 && me->query_temp("zhang/renwu5_210") 
			&& !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_21"))
		{
			tell_object(me,"\n$HIC吴天良泣首道：张大人对犬子有再生之德，在下岂敢再弹劾张大人，您请回吧！\n");
			if(!me->query_temp("zhang/renwu5_21"))
				me->set_temp("zhang/renwu5_21",1);
			destruct(ob);
			me->delete_temp("zhang/renwu5_210");
			if(me->query_temp("zhang/renwu5_21") && me->query_temp("zhang/renwu5_22")
				&& me->query_temp("zhang/renwu5_23") && me->query_temp("zhang/renwu5_24"))
			{
				me->set("zhang/renwu5_ok",2);
				me->delete_temp("zhang/renwu5_21");
				me->delete_temp("zhang/renwu5_22");
				me->delete_temp("zhang/renwu5_23");
				me->delete_temp("zhang/renwu5_24");
			}
			return 1;
		}
	}
	return 0;
}
NPC_END;
