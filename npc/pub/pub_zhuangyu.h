// pub_zhuangyu.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_zhuangyu);

virtual void create()
{
	set_name("庄允城", "zhuang yuncheng" );

	set("icon", young_man2);
	set("gender", "男性" );
	set("age", 40);
	set("int", 28);
	set("long","这是个饱读诗书，却手无搏鸡之力的书生。因编辑‘明史辑略’，被吴秋荣告发，全家逮入京中。" );
	
	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("no_get", "庄允城叹道：我不行了，你走吧。唉，我担心我家里人啊。");
	set("chat_chance", 5);

	set_inquiry("鳌拜","鳌拜实在太可恶了。");
	set_inquiry("书房","书房里那幅画儿很漂亮吧？");
	set_inquiry("画卷","我很喜欢上面画的那个女孩。");
	set_inquiry("旺财","如果他在就好了，一定会把我救出取得。");
	set_inquiry("银铃","那个叫银铃的女孩子好像一直在找旺财。");
	set_inquiry("旺财的剑", "据说那把剑削铁如泥 ");
	set_inquiry("江湖威望", ask_weiwang);

	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(5) )
	{
	case 0:
		return "庄允城说道：只怪我当初好心，在书中夹了金叶送与他，谁想这狼心狗肺的家伙竟然就去告发了我。唉...";
	case 1:
		return "庄允城说道：谁要把吴秋荣抓到我老婆那里就好了就好了。";
	case 2:
		return "庄允城叹道: 多情自古空余恨，此恨绵绵无绝期。";
	case 3:
		return "庄允城叹了口气，说道：我知道鳌拜谋反的秘密，只可惜……。";
	case 4:
		return "庄允城说道：谁要救了我，我一定把我的女朋友送给他。";
	}
	return "";
}

static char * ask_weiwang(CNpc *ob,CChar *me)
{
	char msg[255];
	tell_object(me,snprintf(msg,255," 你现在的江湖威望是%ld " , me->query("weiwang") ));
	ob->say("如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。", me);
	ob->say("而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。", me);
	ob->say("杀某些坏人或救某些好人可以提高江湖威望。", me);
	ob->SendMenu(me);
	return "";
}

virtual void init(CChar *me)
{
	char msg[255];
	if(!userp(me)) return;
	if(userp(me) && !is_fighting() ) 
		say( snprintf(msg,255,"庄允城哈哈笑道：终于有人来救我了！这位%s，鳌府的宝贝可不少啊，你要有什么不明白的，尽管问我吧。",query_respect(me) ));

	if(me->query("weiwang")<20) 
	{
        me->add("weiwang",10);
		message_vision(  "$N的江湖威望提高了！"  ,me);
	}

	command(snprintf(msg,255,"tell %ld 你现在的江湖威望是%ld ",me->object_id(),me->query("weiwang") ));
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if ( !(ob) ) return 0; 
//	if ( !present(ob,me) return notify_fail("你没有这件东西。");
	if (  EQUALSTR( ob->querystr("name"), "明史辑略") )
	{
		say("书里有金叶子，难道你不知道吗？", me);
		say("替我把吴秋荣这厮抓到庄府去吧，我不行了。", me);		
		say("庄允城喘了口气，又说：庄府在京城东北边。", me);
		SendMenu(me);
	}		

	return 1;
}

NPC_END;