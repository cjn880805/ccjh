// pub_qiaofu.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_qiaofu);

virtual void create()
{
	set_name("樵夫","qiao fu");

	set("icon", old_man1);
	set("gender", "男性" );
	set("age", 50);
	set("long", "一个一辈子以砍材为生的老樵夫，由于饱受风霜，显出与年龄不相称的衰老。");
	set("shen_type",1);
	set("combat_exp", 10000);
	set("str", 17);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	set_inquiry("柴刀",inquiry_dao);
 	set_temp("buyed", 0l);
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	command("smile");
	say("谢谢好心的大爷，好人有好报。", who);
	if( EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 3000  )
		who->set_temp("buyed", 1);

	SendMenu(who);
	destruct(ob);
	return 1;
}

static char * inquiry_dao(CNpc *who,CChar *me)
{
	CContainer *obj;
	if (me->PresentName("chaidao",IS_ITEM))
		return "你就别寻老头子开心了，你身上不是也有一把吗?";
	
	if( me->query_temp("buyed")==0 )
		return "这位大爷，实在不是我舍不得这刀，小人一家就全靠它过日子了，给了你，叫我怎么过活啊！";

	if( me->query_temp("buyed")==1 )
	{
		who->say("既然好心人想要，就给你吧，本来史婆婆要我好好保管的，你可千万别瞎送给别人，否则她会生气的。", me);
		obj = load_item("chaidao");//柴刀
		obj->move(me);
		message_vision("樵夫递给$N一把柴刀！", me);
		me->set_temp("buyed", 0l);

		who->SendMenu(me);
	}

	return "";
}

NPC_END;