// taohuadao_mei.c
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNtaohuadao_mei);

virtual void create()
{
	set_name( "梅如花" ,  "mei chaofeng" );
	set("nickname", "铁尸");
	set("gender", "女性");
	set("age", 39);
        set("icon",young_woman1);

	set("long", "梅如花是黄老怪唯一的女弟子，本来极受黄老怪疼爱，可惜她与师兄陈流水  暗生情愫，他们偷了《九阴真经下卷》私奔。 她已年近中年，但从她脸上仍能依稀看到她早年的风采。 ");
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 32);
	set("con", 35);
	set("max_hp",2500);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	set("repute",-50000);
	
	set("combat_exp", 1000000);
	
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 40);
	set_skill("sword", 80);
	set_skill("literate", 20);
	set_skill("jiuyin_zhua", 90);
	set_skill("luoying_shenjian",90);
	set_skill("bibo_shengong", 90);
	set_skill("anying_fuxiang", 90);
	
	map_skill("force", "bibo_shengong");
	map_skill("parry", "luoying_shenjian");
	map_skill("sword", "luoying_shenjian");
	map_skill("dodge", "anying_fuxiang");
	map_skill("unarmed", "jiuyin_zhua");
	
	create_family("桃花岛", 2, "被逐弟子");
	
	set_inquiry("桃花岛","这儿就是，你都来了还会不知道？");
	set_inquiry("铁尸","江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。");
	set_inquiry("东邪","那是我师父的绰号。");	
	set_inquiry("蓉儿","她是我师父的独女，最是刁蛮任性，阴险毒辣。");
	set_inquiry("九阴白骨爪","练习九阴白骨爪一定要用大量尸体。");
	set_inquiry("靖哥哥","哼，就是这个小子暗算了我师哥，我绝不会放过他！");
	set_inquiry("康弟","康儿是我的徒弟，你见过他么？");
	set_inquiry("梅如花","不就是我么？你是白痴啊？");
	set_inquiry("陈流水","他是我的师哥，也是我的夫君，可惜被靖哥哥那家伙暗算了。");
	
	
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "corpse"  ))
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "冷月牌", "lengyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}




NPC_END;