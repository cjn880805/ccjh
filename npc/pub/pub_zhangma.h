// pub_zhangma.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhangma);

virtual void create()
{
	set_name("张妈", "zhang ma" );

	set("icon", old_woman);
	set("gender", "女性" );
	set("age", 50);
	set("long", "一个历经沧桑的老婆婆。");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",10);
	set_inquiry("金花" , inquiry_hua );
	set_temp("shoe",1);
	carry_object("cloth")->wear();
}

virtual char *chat_msg()
{
	switch (random(3))
	{
	case 0:
		return  "张妈念叨着：我苦命的『金花』哟，你现在在那里哟￣";
	case 1:
		return  "张妈暗暗抹了把眼泪。";
	case 2:
		return  "张妈独自说道：我的『金花』呀，你怎能撇下我自个儿走了￣";
	}
	return "";
}

static char * inquiry_hua(CNpc *ob,CChar *me)
{
	CContainer *obn;
	char msg[255];
	
	ob->say(snprintf(msg,255,"这位%s，『金花』是我的亲闺女，甭提多孝顺了！可惜去年上山割草就一去不会，也不知是死是活。唉￣",query_respect(me) ), me );
	
	if(ob->query_temp("shoe")==0)
	{  
		ob->say(snprintf(msg,255,"这位%s，我已经托人去寻找了，也不知道怎么样了。",query_respect(me) ),me);
		ob->SendMenu(me);
		return "";
	}

	ob->say(snprintf(msg,255,"这位%s，我这里有她落在草丛里的一只「绣花鞋」，你要是找到『金花』，就把鞋交给她，她会明白的。我女儿『金花』的命运，就托给你了。" ,query_respect(me) ), me);
	obn=load_item("shoe");//绣花鞋
	obn->move(me);
	ob->set_temp("shoe", 0l);
	ob->SendMenu(me);
	return "";
}
NPC_END;