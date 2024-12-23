//noname.h  无名居士
//zhangdongni  2001-07-18


NPC_BEGIN(CNcity_noname);

virtual void create()
{

        set_name("无名居士", "noname" );
        set("title","一代宗师");
	set("long",  "他就是无名居士，没有人知道他的来历。\n");
//              "如果你想收集神书，你可以问问他(book)和(shi).\n"
//              "如果中秋节你没拿过月饼，你可以问他月饼(月饼).\n");
        set("age", 57);
        set("gender", "男性");
        set("icon", old_man1);
        set("class", "beggar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 44);
	set("int", 20);
	set("con", 20);
	set("dex", 44);
	set("no_kill",1);
	set("max_hp", 8000);
	set("max_hp", 8000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_foctor", 500);
	set("combat_exp", 2500000);
	set("score", 50000);                
        set_skill("strike",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 210);
	set_skill("literate", 200);
/*
set("inquiry", ([
            "book": "神书共有四十二本，你可以用help tasks获得有关方面知识！",
            "shi": "只有靠"HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR+CYN"才能找到神书，灵石二十两一块！",
	     "mengzhu": (: ask_me :),
	     "月饼":(: ask_bing :),
	    // "gift":(: ask_gift :),
            ]) );
       	setup();
}
int accept_object(object me, object ob)
{
object shi; 
if( ob->query("money_id") && ob->value() >= 2000)
{	
	 if (!present("xdshi", me))
	{
	shi = new("/clone/misc/findbook");	command("say 好吧,"+me->query("name")+"既然给了钱，我就给你一块！\n");
	shi->move(me);
	message_vision("$N将一块"HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR"交给了$n。\n" , this_object(), me );
	} else 
	command("say 你不是有了一块嘛，还想要？钱我没收！\n");
return 1;
}
command("say 谢谢！");
return 1;
}
int ask_me()
{
if(this_player()->query("combat_exp")<1500000)  tell_object(this_player(),"无名居士说道：你经验太低，想要做盟主，必死无疑！\n");
else {
tell_object(this_player(),"无名居士说道： 好吧，里面危险重重，千万别乱来，否则有生命危险。自己小心吧！\n");
this_player()->move("/d/biwu/hole");
}
return 1;
}
int ask_bing()
{
object me,bing;
me = this_player();
if(!me->query("marks/nabing"))
{
message_vision("无名居士道：好吧，就当做是$N的中秋节礼物吧。无名居士给了$N一只中秋节月饼。\n",me);
bing = new("/clone/misc/yuebing");
bing->move(me);
me->set("marks/nabing",1);
}
else tell_object(me,"你已经拿过一次月饼了，还想拿？\n");
return 1;
}
int ask_gift()
{
object me,gift;
me = this_player();
if(!me->query("marks/nagift"))
{
message_vision("无名居士道：好吧，就当做是$N的国庆节礼物吧。无名居士给了$N一只国庆节红包。\n",me);
gift = new("/clone/misc/guogift");
gift->move(me);
me->set("marks/nagift",1);
}
else tell_object(me,"你已经拿过一次红包了，还想拿？\n");
return 1;
}
*/
}
NPC_END;