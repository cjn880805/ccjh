// lilishi.H李力世
//zhangdongni 2001-07-18


NPC_BEGIN(CNcity2_lilishi);

virtual void create()
{
	set_name("李加世", "lijiashi");
	set("title", "天地会青木堂会众");
	set("gender", "男性");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("long", "这是一个身材矮小，满连胡须的中年人，身上的衣服又脏又破，脸上满是皱纹，看上去饱经风霜。\n");
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("icon", young_man2);
	
	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("wuhuduanmendao", 90);
	set_skill("yunlong_shenfa", 60);
	map_skill("blade", "wuhuduanmendao");
	map_skill("dodge", "yunlong_shenfa");
	
    set("mp", 150); 
	set("max_mp", 150);
	set("mp_foctor", 10);
	set("chat_chance", 2);
	
	set_inquiry("陈近南", "想见总舵主可不容易啊.");
	set_inquiry("天地会", "只要是英雄好汉，都可以入我天地会(join tiandihui)。");
	set_inquiry("入会", "只要入了我天地会，可以向会中各位好手学武艺。");
	set_inquiry("反清复明", "去棺材店和回春堂仔细瞧瞧吧！");
	set_inquiry("暗号", "敲三下！");
	set_inquiry("切口", "敲三下！");
/*	set_inquiry("进宫" ,: ask_zhu :),
                "花雕芙苓猪" : (: ask_zhu :),
                "燕窝人参猪" : (: ask_zhu :),
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :)

        carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
*/
}

virtual char * chat_msg(CChar * player)
{
	switch(random(5))
	{
	case 0:
		return 	"李加世说：呆会儿我还得把猪送到宫里去。";
	case 1:
		return  "李加世突然吆喝道: 花雕芙苓猪啊，只卖黄金一两，谁买谁买啊？";
	case 2:
		return  "李加世突然吆喝道: 燕窝人参猪啊，只卖黄金一两，谁买谁买啊？";
        case 3:
		return  "李加世搔了搔头，说道：这么好的猪肉怎么没人要啊。";
        case 4:
		return  "李加世突然说：初进洪门结义兄，对天明誓表真心。";
	
        }
        return 0;       
}
/*
int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 10000) 
	{
		message_vision("\n李力世对$N一揖作礼，说道：这位客官，要什么尽管说。\n",this_player());
		who->set_temp("money_paid",1);
		return 1;
	}
	return 0;
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n李力世说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("李力世说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}


int ask_zhu()
{
if (this_player()->query_temp("money_paid"))
{
this_player()->delete_temp("money_paid");
this_player()->set("huanggong\\canenter",1);
say("李力世说：您老现在可以走啦！\n");
return 1;
}
say("李力世说：干什么也得先交钱啊。\n");
return 1;
} 


void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$N摇了摇头。\n",this_object());
    command("tell "+ob->query("id")+" 不是天地会弟子我不教。\n"); 
    return 0;
    }
	return 1;
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="li" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "天地会" NOR )
	{
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
		return 1;
	}
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本刀法 (blade)                         - 一代宗师  90/    \n"+
"  基本轻功 (dodge)                         - 神乎其技  60/    \n"+
"  基本内功 (force)                         - 神乎其技  60/    \n"+
"  基本招架 (parry)                         - 出类拔萃  50/    \n"+
"  基本拳脚 (unarmed)                       - 出类拔萃  50/    \n"+
"□云龙身法 (yunlong-shenfa)                - 神乎其技  60/    \n"+ 
"□五虎断门刀 (wuhu-duanmendao)             - 一代宗师  90/    \n");
   return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
*/

NPC_END;