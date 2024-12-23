//tanglong.h
//code by zwb
//12-14

VENDOR_BEGIN(CNPub_tanglong);

virtual void create()
{
	set_name("唐龙","tanglong");
	
	set("icon", smith_boss);
	set("title", "兵器铺老板");
	

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long","据说唐龙是四川唐家的后代。");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("throwing", 30);
	set_skill("hanxing_bada", 30);
	map_skill("throwing","hanxing_bada");
	map_skill("parry","hanxing_bada");
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");

	carry_good("feihuangshi",20);
	carry_good("flower_leaf",20);
	carry_good("tea_leaf",20);
	carry_good("tielianzi",20);
        carry_good("jili",20);
        carry_good("zimuzhen",20);
        carry_good("tiedan",20);
        carry_good("zhuyebiao",20);
        carry_good("arrow",20);
        carry_good("gangbiao",20);
        carry_good("kuihuazhen",20);
        carry_good("feihuangshi",20);
        
        carry_object("jili")->wield();
	carry_object("cloth")->wear();

};


VENDOR_END;
