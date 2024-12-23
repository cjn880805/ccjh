// jiaowenqi.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_jiaowenqi);

virtual void create()
{
        set_name("焦纹奇", "jiao wenqi");
        set("long", "他是关外六魔中的三魔焦纹奇。背上一把铁琵琶，是武林中少见的奇门兵器。");
        set("nickname", "关外三魔");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 50);
        set("int", 20);
        set("con", 30);
        set("dex", 20);
	set("icon",young_man3);	
        set("max_hp", 1200);
        set("hp", 1200);
        set("mp", 1200);
        set("max_mp", 1200);
        set("mp_factor", 100);
        set("combat_exp", 170000);
        set("score", 20000);

        set_skill("force", 80);
        set_skill("xiaowuxiang", 50);
        set_skill("dodge", 50);
        set_skill("shenkong_xing", 60);
        set_skill("unarmed", 90);
        set_skill("yujiamu_quan", 40);
        set_skill("parry", 60);
        set_skill("hammer", 100);
        set_skill("riyue_lun", 100);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "riyue_lun");
        map_skill("hammer", "riyue_lun");

        carry_object("cloth")->wear();
        carry_object("tiepipa")->wield();
//	add_money("silver",40);
}

NPC_END;