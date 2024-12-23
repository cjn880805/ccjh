//bencan.h
//code by zwb
//12-16
//inherit F_MASTER;

DALIBEN_BEGIN(CNDaLi_bencan);

virtual void create()
{
	set_name("本残","ben can");

	set("gender", "男性" );
	set("long", "他身材魁伟，却少了一根手指，为本阴方丈的师兄。" );
	set("title", "天龙寺第十七代僧人");
	set("class", "bonze");
	set("age", 49);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_monk);

	set("hp", 2500);
	set("max_hp", 7500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 180);
	set_skill("dodge", 220);
	set_skill("parry", 180);
	set_skill("finger", 185);
	set_skill("sword", 180);
	set_skill("tianlong_shengong", 180);
	set_skill("tiannan_step", 220);
	set_skill("kurong_changong", 200);
	set_skill("duanjia_sword", 180);
	set_skill("liumai_shenjian", 220);
	set_skill("sun_finger", 200);
	set_skill("buddhism", 160);
	set_skill("literate", 120);
	set_skill("lm_zhongchong", 150);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("parry", "liumai_shenjian");
	map_skill("finger", "liumai_shenjian");
	map_skill("sword", "duanjia_sword");
	prepare_skill("finger","liumai_shenjian");

	create_family("大理段家",17,"高僧");

	carry_object("b_jiasha")->wear();
};



virtual void attempt_apprentice(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "男性") )
	{
		say("阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。", me);
	}else if( DIFFERSTR(me->querystr("class"), "bonze") )
	{
		say("阿弥陀佛！贫僧不收『俗家弟子』。", me);
	}else if (me->query_skill("kurong_changong", 1) < 100)
	{
        say("你内功修为还不到火候，进天龙寺也是徒劳。", me);
    }else
	{
		say("阿弥陀佛，善哉！善哉！", me);
		recruit_apprentice(me);
	}

	SendMenu(me);
}

DALIBEN_END;
