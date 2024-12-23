// guofu.c
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_guofu);

virtual void create()
{
    set_name("芙儿", "guo fu");
    set("gender", "女性");
    set("age", 19);
    set("long", "她是郭靖黄蓉的大女儿，黄老怪的大外孙女，长得如花似玉。");

    set("attitude", "peaceful");
       
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);
    set("icon", girl2);

    set("hp", 1000);
    set("max_hp", 1000);
    set("hp", 1000);
    set("mp", 1000);
    set("max_mp", 500);
    set("mp_factor", 0l);
       
    set("combat_exp", 50000);
    set("score", 0l);
       
    set_skill("force", 60);
    set_skill("bibo_shengong", 60);
    set_skill("unarmed", 60);
    set_skill("luoying_shenzhang", 60);
    set_skill("dodge", 80);
    set_skill("anying_fuxiang", 60);
    set_skill("parry", 60);
    set_skill("sword", 60);
    set_skill("luoying_shenjian", 60);
    set_skill("qimen_wuxing", 60);
       
    map_skill("force"  , "bibo_shengong");
    map_skill("unarmed", "luoying_shenzhang");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("sword"  , "luoying_shenjian") ;

    carry_object("ruanwei")->wear();
    carry_object("shudai")->wear();

}

NPC_END;
