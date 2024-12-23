//ouyangke.h
//code by zwb
//12-16


NPC_BEGIN(CNBaiTuo_ouyangke);

virtual void create()
{
		set_name("白少庄主","ouyang ke");

        set("long", "他手摇折扇，风流儒雅，却有些忧伤，目光茫然地看着来往的女孩们。");
        set("title", "白驼山少庄主");
        set("gender", "男性");
        set("age", 27);
 	set("icon",young_man1);

        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 50);

        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_hp", 2400);
        set("mp", 800);
        set("max_mp", 800);
        set("mp_factor", 20);
        set("combat_exp", 50000);
        set("score", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);
};




NPC_END;
