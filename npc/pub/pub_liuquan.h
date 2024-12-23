//pub_liuquan.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_liuquan);

virtual void create()
{    
    set_name("刘权", "liu quan");
    set("long","手拿大刀，一副吃人模样。");	
    set("gender", "男性"); 
    set("title","刀霸");
    set("age", 33);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 20);
    set("icon", young_man2);

    set("max_hp", 20000);
    set("mp", 3000);
    set("max_mp", 10000);
    set("mp_factor", 80); 
    set("combat_exp", 2000000); 
    set("score", 200000);

    set_skill("force", 200);
    set_skill("beiming_shengong", 200);
    set_skill("dodge", 200);
    set_skill("guimei_shenfa", 200);
    set_skill("unarmed", 200);
    set_skill("liuyang_zhang", 200);
    set_skill("parry", 200);
    set_skill("blade", 200);
    set_skill("xiaoyao_dao", 200);
    set_skill("zhemei_shou", 200);
    set_skill("hand", 200);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "guimei_shenfa");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 280);
    set("apply/damage", 80);
    carry_object("gangdao")->wield();
	set("no_kill",1);//不被列入万劫谷的任务中

}
virtual void die()
{
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}
NPC_END;




