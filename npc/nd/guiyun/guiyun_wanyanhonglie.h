// wanyanhonglie.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_wanyanhonglie);

virtual void create()
{
        set_name("完颜金狗", "wanyan honglie");
        set("gender", "男性");
        set("title", "大金国赵王爷");
        set("age", 48);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 26);
        set("per", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 26);
	set("icon", young_man4);

        set("hp", 300);
        set("max_hp", 300);
        set("mp", 300);
        set("max_mp", 300);
        set("mp_factor", 10);

        set("combat_exp", 30000);
        set("score", 10000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("unarmed",40);
        set_skill("changquan",40);

        map_skill("unarmed", "changquan");
        map_skill("parry", "changquan");

//	carry_object("male1-cloth")->wear();
}

NPC_END;