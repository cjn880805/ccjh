//xian.h
//Lanwood 2000-01-05

EMEIBONZE_BEGIN(CNemei_xian);

virtual void create()
{
	set_name("宁闲师太", "ningxian shitai");
	set("long", "她是一位中年出家道姑，身穿道袍，正端坐在蒲团上，眉目之间有一股祥和之气。");
	set("gender", "女性");
	set("age", 45);
	set("icon", taoistess);
	
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	set_inquiry("剃度", ask_for_join );
	set_inquiry("还俗", "峨嵋弟子，不能还俗。你找掌门师太吧。");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);
		set("foolid",20);
	set("max_hp", 3000);
	set("mp", 1500);
	set("max_mp", 1500);
	
	set("combat_exp", 150000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 70);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("finger", 60);
	set_skill("parry", 70);
	set_skill("strike", 65);
	set_skill("blade", 60);
	set_skill("mahayana", 60);
	set_skill("literate", 60);
	set_skill("jinding_zhang", 60);
	set_skill("tiangang_zhi", 60);
	set_skill("yanxing_dao", 60);
	set_skill("zhutian_bu", 70);
	set_skill("linji_zhuang", 70);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("blade","yanxing_dao");
	map_skill("parry","yanxing_dao");
	
	create_family("峨嵋派", 4, "弟子");
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

   if( DIFFERSTR(me->querystr("class"), "bonze") )
   {
      say("阿弥陀佛！贫尼不收俗家弟子。施主若想学艺可去找我俗家师妹。", me);
	  SendMenu(me);
      return;
   }

   if( DIFFERSTR(me->querystr("gender"), "女性") )
   {
      say("阿弥陀佛！贫尼不收男弟子。施主若想学艺可去找我俗家师妹。", me);
	  SendMenu(me);
      return;
   }

   if (me->query("repute") < 100)
   {
      say(snprintf(msg, 255, "%s你行侠仗义之事还做的不够。", query_respect(me)), me);
	  SendMenu(me);
      return;
   }

   say("阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   say("希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}

EMEIBONZE_END;
