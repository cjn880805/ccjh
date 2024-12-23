//renyingying.h	任盈盈
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_renyingying);

virtual void create()
{
	set_name("盈盈","ren yingying");

	set("title",  "日月圣姑" );
	set("long", "她身材丰腴，体态优雅，虽看上去不好接近，但无论怎样都不失为一可人的妙人。");
	set("gender", "女性");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);	//设置声望的正负
	set("str", 16);
	set("per", 27);
	set("int", 27);
	set("con", 17);
	set("dex", 18);
 	set("icon",young_woman2);
	
	set("hp", 2000);
	set("max_hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	set("combat_exp", 1000000);
	set("score", 100000);

	set_skill("literate", 200);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("unarmed", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("changquan", 120);
	set_skill("xingxiu_duzhang", 120);
	set_skill("lingxu_bu", 120);
	set_skill("damo_jian", 120);
	set_skill("taiji_jian", 120);
	set_skill("huifeng_jian", 120);
	set_skill("taishan_sword", 120);
	set_skill("hengshan_jian", 120);
	set_skill("hengshan_sword", 120);
	set_skill("huashan_sword", 120);
	set_skill("songshan_sword", 120);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "xingxiu_duzhang");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");
	
	set("chat_chance", 10);

	set_inquiry("冲郎", "你看见我的冲哥了么，帮我带一封信给他好么？");
	set_inquiry("紫凤凰", "她是五毒教的教主，我的好朋友。");
	set_inquiry("任无月", "我爹爹他一定没死，我一定要找到他。");
	set_inquiry("东方爱莲", "东方叔叔对我很好，最近一直没看见他。");
	set_inquiry("笑傲江湖曲", "那是一首很动人的曲子，要是冲郎在这里就可以和他琴箫合奏了。");
//	set_inquiry("送信", ask_songxin);
//	set_inquiry("曲谱", ask_qupu);

	carry_object("changjian")->wield();
//	carry_object("letter")->wield();

	create_family("日月神教",2,"弟子");
	set("no_huan",1);
}

virtual char * chat_msg()		//NPC自动聊天
{
	switch(random(3))
	{
	case 0:
		return 	"盈盈眉头直皱，叹道：不知冲郎他，怎恙了,是否又和那小贱人在一起......";
	case 1:
		return 	"盈盈满怀希望的看着你道：你若能把这封信稍给他，可太谢谢你了.............";
	case 2:
		return 	"盈盈焦急的走来走去没，道：也不知紫凤凰见没见到他，可真急死我了.......";
	}

	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu2_1") && !me->query_temp("ry/renwu2_2"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("关于黑木涯真正入口的问题","rukou",me);
		}
		else if(!strcmp(ask, "rukou") )
		{
			say("盈盈道：“我现在整日挂念的就是冲郎，哪里有心思回答你的问题。我这里有一块手娟，不如你帮我交给冲郎？”",me);
			CContainer * obj = load_item("baozi");
			obj->set_name("手娟", "shou juan");
			obj->set_weight(500);
			obj->set("long", "这是一块女子用的手娟。");
			obj->set("owner1",me->id(1));
			obj->set("ry/shoujuan",1);
			obj->move(me);
			me->set_temp("ry/renwu2_2",1);//接受送手帕给冲郎的任务
			tell_object(me,"\n$HIC你得到数量1的手娟。\n");
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if(me->query_temp("ry/renwu2_3") && !me->query_temp("ry/renwu3_1"))
	{
		if (obj->query("ry/xin") &&  EQUALSTR(obj->querystr("owner1"), me->id(1)))
		{
			say( "盈盈高兴的说道:“冲郎信中说一有时间就会来看我，真是太好了！对了，你刚才询问黑木顶的事情么？我想起来了，此事现在由上官风负责，你把黑木令给他就可以上去了！”", me);
			me->set_temp("ry/renwu3_1",1);//完成送信给盈盈的任务
			destruct(obj);
			SendMenu(me);
			return 1;
		}
	}
	return 0;
}
/*
string inquiry_linghuchong()
{
	object me=this_player();
	object obn;
	
	message_vision("去年上华山一去就再无音信,他不会忘记我吧......\n"
		, me );
	if(query_temp("letter")==0)
	{  message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我已经派
	蓝凤凰去寻找了，也不知道怎么样了。\n",me);
	return "";
	}
	message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我这里有
		信, 你要是找到『阿冲』，就把信交给她，她会明白的。\n" , me);
		obn=new("/d/heimuya/npc/obj/letter");
	obn->move(me);
	set_temp("letter",0);
	
	return ("这封信凡你交给令狐冲。\n");
}
*/
NPC_END;