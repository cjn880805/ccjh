//pub_mowentian.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_mowentian);

virtual void create()
{    
    set_name("莫问天", "mo wen tian");
    set("long","为人狂放，亦正亦邪...");	
    set("gender", "男性"); 
    set("title","问天客");

    set("age", 43);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 30);
    set("icon", young_man1);

    set("max_hp", 20000);
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 100); 
    set("combat_exp", 3000000); 

    set_skill("force", 300);
    set_skill("beiming_shengong", 300);
    set_skill("dodge", 300);
    set_skill("guimei_shenfa", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("club", 300);
    set_skill("zhanjiang_jue", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "guimei_shenfa");
    map_skill("unarmed", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "zhanjiang_jue");
    map_skill("club", "zhanjiang_jue");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 280);
    set("apply/damage", 200);
    carry_object("qimeigun")->wield();
	set("no_kill",1);//不被列入万劫谷的任务中
}

virtual void die()
{
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}
NPC_END;




