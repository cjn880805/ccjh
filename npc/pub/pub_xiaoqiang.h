//pub_xiaoqiang.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_xiaoqiang);

virtual void create()
{    
    set_name("小强", "xiao qiang");
    set("long","它是一种人见人爱的虫虫，奇强无比，天神们见了它也怕怕");	
    set("gender", "无性"); 
    set("title","天神怕怕");
    set("age", 1);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 40);
    set("icon",boy1);

    set("max_hp", 50000);
    set("mp", 8000);
    set("max_mp", 8000);
    set("mp_factor", 100); 
    set("combat_exp", 3800000); 
    set("score", 200000);

    set_skill("force", 300);
    set_skill("beiming_shengong", 300);
    set_skill("dodge", 300);
    set_skill("guimei_shenfa", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("club", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
	set_skill("zhanjiang_jue", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "guimei_shenfa");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "zhanjiang_jue");
    map_skill("club", "zhanjiang_jue");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 280);
    set("apply/damage", 300);
    carry_object("qimeigun")->wield();

}

NPC_END;




