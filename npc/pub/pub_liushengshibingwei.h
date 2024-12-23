//pub_liushengshibingwei.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_liushengshibingwei);

virtual void create()
{    
    set_name("柳生十兵卫", "liu sheng wei");
    set("long","东洋首席刀客。仰慕中国武术而来。。。");	
    set("gender", "男性"); 
    set("title","东洋第一刀");
    set("age", 43);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 20);
    set("icon", young_man6);

    set("max_hp", 26000);
    set("mp", 12000);
    set("max_mp", 12000);
    set("mp_factor", 100); 
    set("combat_exp", 3000000); 
    set("score", 200000);

    set_skill("force", 300);
    set_skill("beiming_shengong", 300);
    set_skill("dodge", 300);
    set_skill("guimei_shenfa", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 350);
    set_skill("dongyangdaofa", 350);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "guimei_shenfa");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "dongyangdaofa");
    map_skill("blade", "dongyangdaofa");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 280);
    set("apply/damage", 300);
    carry_object("gangdao")->wield();

}

NPC_END;




