//lj_xiaoyulaoren.h	笑语老人
//秦波 2002、6、1

NPC_BEGIN(CNlj_xiaoyulaoren);

void create()
{
	set_name("笑语老人","xiaoyu laoren");
	set("title", "一梦苍生");
	set("gender", "男性");
	set("age", 53);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 39);
	set("str", 40);
	set("int", 45);
	set("con", 50);
	set("dex", 60);
	
	set("max_hp", 30000);
	set("mp", 20000+random(20000));
	set("max_mp", 20000+random(20000));
	set("mp_factor", 160+random(200));

	set("combat_exp", 6500000);
	set_skill("force", 400+random(400));
	set_skill("dodge", 400+random(400));
	set_skill("parry", 400+random(400));
	set_skill("sword",400+random(400));
	set_skill("hand",400+random(400));

	set_skill("beiming_shengong",400+random(400));
	set_skill("yunlong_shou",400+random(400));
	set_skill("doggiesteps", 400+random(400));
    set_skill("ice_sword", 400+random(400));
  
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "doggiesteps");
	map_skill("parry", "ice_sword");
	map_skill("sword", "ice_sword");
	map_skill("hand", "yunlong_shou");

	prepare_skill("hand", "yunlong_shou");
	carry_object("icesword")->wield();
	set("no_huan",1);
	
};

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("lj/renwu4"))	return 0;
	if(!ob->query("xiaoyuelaoren")) return 0;
	destruct(ob);
	tell_object(who, "笑语老人接过了你递上的书信，撕开封口，慢慢的看了起来。");
	tell_object(who, "长久之后，不禁一声轻叹：痴人。。。");
	tell_object(who, "转过头来，对你说道：有劳你了，麻烦你回去告诉他一下，过往云烟的旧事，就不要再作牵挂了。");
	who->set("lj/renwu4_hueifu",1);
	return 1;
}

NPC_END;




