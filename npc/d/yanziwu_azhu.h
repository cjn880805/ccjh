// yanziwu_azhu.c
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNyanziwu_azhu);

virtual void create()
{
	set_name("阿丹", "azhu");
	set("long","这是个身穿红衣的女郎，大约十七八岁，一脸精灵顽皮的神气。 一张鹅蛋脸，眼珠灵动，别有一番动人风韵。 ");
	
	set("gender", "女性");
	set("age", 17);
	set("icon",girl2);
	
	set("shen_type", 1);
	
	set("mp", 200);
	set("max_mp", 200);
	set("max_hp", 480);
	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);
	
	set("combat_exp", 10000);
	
	carry_object("goldring")->wear();
	carry_object("necklace")->wear();
	carry_object("changjian")->wield();
	carry_object("pink_cloth")->wear();
	carry_object("flower_shoe")->wear();
	carry_object("mask");
	
	set_inquiry("曼陀山庄","我才不敢去曼陀山庄，王夫人太霸道了! ");
	set_inquiry("王姑娘","哎，只有她才配得上我们公子，也不知她现在怎么样了! ");
	set_inquiry("阿珊", "那小丫头也不只跑哪儿去了。 ");
	set_inquiry("易容", "想变成别人的样子其实很容易，只要有原料就行了。 ");
	set_inquiry("弹琴" ,inquiry_tanqin);
	set("no_huan",1);
}

static char * inquiry_tanqin(CNpc *who,CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"阿丹说道：这位%s这么有雅兴，那我就为你弹奏一曲〈君莫悲〉！只听琴声繁复清亮，你不由的痴了。 ",query_respect(me) ), me );
    who->say("细细品来，竟是张信哲的<<爱如潮水>>!!!  ",me);
    who->say("阿丹一曲终了，道个万福，说道：现丑了。 ", me );
	who->SendMenu(me);
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("wei/renwu5_4"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问关于易容之术","yirong",me);
		}
		else if(!strcmp(ask, "yirong") )
		{
			me->set_temp("wei/renwu5_5",1);//开始寻找易容材料
			say("想变成别人的样子很容易，只是我这儿没有原料了。",me);
			say("如果你能帮我找五张太湖白鱼的鱼皮来，我就能帮你做人皮面具了。",me);
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "白鱼皮") && ob->Query_Amount() ==5
		&& EQUALSTR(ob->querystr("id"), "bai yu pi")
		&& me->query_temp("wei/renwu5_5") && !me->query_temp("wei/renwu5_6"))
	{
		destruct(ob);
		char msg[255];
		tell_object(me,snprintf(msg,255,"\n$HIC阿丹说道：请%s稍候片刻，我去去就来。\n",query_respect(me)));
		tell_object(me,"阿丹转身走了出去。\n");
		me->set_temp("wei/renwu5_6",1);//给阿丹5张白鱼皮
		call_out(do_jiagong, 30);
		set("owner",me->id(1));
		move(load_room("temp_azhu"));
		return 1;
	}
	return 0;
}

static void do_jiagong(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		npc->move(load_room("燕子坞翠霞堂"));
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			char msg[255];
			tell_object(me,"\n阿丹从屋外走了出来。");
			tell_object(me,snprintf(msg,255,"$HIC阿丹说道：让%s你久侯了，这张人皮面具就请%s收好。\n",query_respect((CChar *)me),query_respect((CChar *)me)));
			me->set_temp("wei/renwu5_7",1);//拿到人皮面具
			load_item("killermask1")->move(me);
		}
		npc->del("owner");
	}
}
NPC_END;