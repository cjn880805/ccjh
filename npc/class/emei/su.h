//su.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_su);

virtual void create()
{
	set_name("苏梦俏", "su mengqiao");
	set("long", "她是峨嵋派的第四代俗家弟子。");
	set("gender", "女性");
	set("age", 22);
	set("icon", girl2);
	
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");
		set("foolid",12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3000);
	
	set("mp", 1500);
	set("max_mp", 1500);
	
	set("combat_exp", 150000);
	set("score", 1000);
	set_skill("throwing", 40);
	set_skill("persuading", 40);
	set_skill("force", 60);
	set_skill("dodge", 80);
	set_skill("finger", 70);
	set_skill("parry", 70);
	set_skill("strike", 70);
	set_skill("sword", 80);
	set_skill("jinding_zhang", 70);
	set_skill("tiangang_zhi", 70);
	set_skill("huifeng_jian", 80);
	set_skill("zhutian_bu", 80);
	set_skill("linji_zhuang", 70);
	
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("parry","huifeng_jian");
	create_family("峨嵋派", 4, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

   if (me->query("repute") < 100)
   {
		say("我峨嵋乃是堂堂名门正派，对弟子要求极严。", me);
		say(snprintf(msg, 255, "在德行方面，%s是否还做得不够？", query_respect(me)), me);
		SendMenu(me);
		return;
   }

   if (me->query_combat_exp() > 10000) 
   {
        say("我峨嵋注重清修，对弟子要求能忍受寂寞。", me);
        say(snprintf(msg, 255, "在江湖阅历方面，%s经历丰富，是否能在峨嵋修道？", query_respect(me)), me);
		SendMenu(me);
        return;
   }

   say("好吧，我就收下你了。");
   command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}

NPC_END;
