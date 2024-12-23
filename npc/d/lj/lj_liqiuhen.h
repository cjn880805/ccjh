//lj_liqiuhen.h
//wuqing 2002-2-10

NPC_BEGIN(CNlj_liqiuhen);

virtual void create()
{    
    set_name("李秋痕", "li qiou hen");
    set("long","她、曾经是江湖上的美女，尽管因为年华老去，但风姿不减。。。。");	
    set("gender", "女性"); 
    set("title","碧波仙子");
    set("age", 75);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 40);
    set("icon",young_woman4);

    set("max_hp", 18500);
    set("mp", 10000);
    set("max_mp", 10000);
    set("combat_exp", 7000000); 
    set("score", 200000);

    set_skill("force", 200);
    set_skill("beiming_shengong", 200);
    set_skill("dodge", 200);
    set_skill("lingboweibu", 200);
    set_skill("unarmed", 200);
    set_skill("liuyang_zhang", 200);
    set_skill("parry", 200);
    set_skill("blade", 200);
    set_skill("xiaoyao_dao", 200);
    set_skill("zhemei_shou", 200);
    set_skill("hand", 200);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 100);
    set("apply/damage", 50);
    carry_object("gangdao")->wield();

	call_out(do_die, 300);
	set("no_kill",1);

}


static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

virtual void die()
{
	tell_room(environment(), "李秋痕恨然道：“师姐，妹妹我还会来找你的！”");
	destruct(this);
}

NPC_END;

 



