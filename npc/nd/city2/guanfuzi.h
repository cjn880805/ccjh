// guanfuzi.h 关安基
//zhangdn 2001-07-18 



NPC_BEGIN(CNcity2_guanfuzi);

virtual void create()
{
	set_name("关安地", "guan anan");
	set("title", "天地会青木堂会众");
//	set("title", "茶馆老板");
	set("nickname", "关夫子");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long","只见他长长的胡子飘在胸前，模样甚是威严。因此人称关夫子。");
	set("icon",young_man2);

	set_skill("unarmed", 60);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("force", 70);
	set_skill("zixia_shengong", 50);
	set_skill("huashan_sword", 70);
	set_skill("huashan_shenfa",60);
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "huashan_sword");
	map_skill("sword", "huashan_sword");
	map_skill("force", "zixia_shengong");

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 1);
	
	set_inquiry("陈近南", "想见总舵主可不容易啊。");
	set_inquiry("天地会", "只要是英雄好汉，都可以入我天地会(join tiandihui)。");
	set_inquiry("入会", "只要入了我天地会，可以向会中各位好手学武艺。");
        set_inquiry("反清复明",  "去屠宰场和棺材店仔细瞧瞧吧！");
 //       set_inquiry("威望"  (: ask_weiwang :),
 //               "江湖威望" : (: ask_weiwang :),
}

virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(2))
	{
	case 0:
		return 	"关安地忽然说：本堂的香主谁来当，还轮不到我说话。";
	case 1:
	        return  "关安地忽然说：唉，我的脾气不大好，大家可要小心了。";
	}
	return 0;
}

/*
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

void init()
{
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="guan" )
     return 0;
   if(wizardp(ob))   return 0;
  if (ob->query("weiwang")<50)
  {
   message_vision("$N摇了摇头。\n",this_object());
   command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 出神入化  70/    \n"+
"  基本内功 (force)                         - 出神入化  70/    \n"+ 
"□华山剑法 (huashan-jianfa)                - 神乎其技  70/    \n"+
"□华山身法 (huashan-shenfa)                - 神乎其技  60/    \n"+
"  基本招架 (parry)                         - 出神入化  70/    \n"+
"  基本剑法 (sword)                         - 登峰造极  80/    \n"+
"  基本拳脚 (unarmed)                       - 神乎其技  60/    \n"+
"□紫霞神功 (zixia_shengong)                - 出类拔萃  50/    \n");
   return 1;
}

void die()
{
message_vision("\n$N大怒道：“你敢砍老子！兄弟们会替我报仇的！”说完倒地死了。\n", this_object());
::die();
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n关安基说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("关安基又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
*/

NPC_END;