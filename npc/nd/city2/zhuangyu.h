// zhuangyu.h
//zhangdongni 2001-07-18

NPC_BEGIN(CNcity2_zhuangyu);

virtual void create()
{
	set_name("庄应城", "zhuangyingcheng");
	set("gender", "男性");
	set("age", 40);
	set("icon",young_man3);
	set("ser", 15);
	set("int", 25);
	set("dex", 15);
	set("con", 20);
	set("shen_type", 1);
	set("long", "这是个饱读诗书，却手无搏鸡之力的书生。因编辑‘明史辑略’，被吴之荣告发，全家逮入京中。" );
	set("attitude", "peaceful");
	set_skill("literate", 100);
//	set("noget", "庄允城叹道：我不行了，你走吧。唉，我担心我家里人啊。\n");
	set("chat_chance", 2);
        set_inquiry("鳌拜" , "鳌拜的书房里有宝贝。");
	set_inquiry("书房" , "书房里那幅画儿有学问.");
}
	
virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(6))
	{
	case 0:
		return 	"庄应城说道：只怪我当初好心，在书中夹了金叶送与他，";
	case 1:
	        return  "谁想这狼心狗肺的家伙竟然就去告发了我。唉...";
	case 2:
	        return  "庄应城说道：谁要把吴之荣抓到庄府就好了。";
	case 3:
	        return  "庄应城突然说道: 江湖威望很重要，威望高大有好处啊。";
	case 4:
		return  "庄应城叹了口气，说道：我知道鳌拜书房的秘密，只可惜我出不去啊。";
	case 5:
		return  "庄应城说道：谁要救了我，我一定把我知道的都告诉他。";
	}
	return 0;
}

//{
//	set_inquiry("画" , "移动那幅画时可是有方向的。");
//		"画卷" :  "移动那幅画时可是有方向的。",
//		"方向" :  "先左移一下，后右移一下就行了。",
//		"暗门" :  "那可不能随便进，画里可是有学问的。",
//		"吴之荣" :  "把他送到庄府去有好处。",
//                "威望" :  (: ask_weiwang :),
//                "江湖威望" : (: ask_weiwang :),

//}
/*
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n庄允城说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("庄允城又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}

void init()
{
	object ob; 
	int i;
	ob = this_player();
        if(!userp(ob)) return;
	if(interactive(ob) && !is_fighting() ) 
	say( "庄允城哈哈笑道：终于有人来救我了！\n这位" + RANK_D->query_respect(ob)
				+ "，鳌府的宝贝可不少啊，你要有什么不明白的，尽管问我吧。\n");
	i=(int)this_player()->query("weiwang");
        if(i<20) 
	{
	i=i+10;
        this_player()->set("weiwang",i);
	message_vision(HIC "\n$N的江湖威望提高了！\n" NOR,this_player());
	}
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(i));
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("name") == "明史辑略") 
	{
	 write(HIC "\n庄允城笑到：书里有金叶子，难道你不知道吗？\n" NOR);
	 write(HIC "庄允城说：替我把吴之荣这厮抓到庄府去吧，我不行了。\n" NOR);		
	 write("庄允城喘了口气，又说：庄府在京城东北边。\n");
	}		
        return 1;
        
        carry_object("cloth")->wear();
}

*/
NPC_END;