//xieyan.h
//code by zwb
//12-15

NPC_BEGIN(CNBaiTuo_xieyan);

virtual void create()
{
		set_name("谢酒客","xieyan");

        set("long", "他就是摩天崖的主人。看年纪大约五十多岁，年轻时好武成兴，无比骄傲，自认为天下第一。");
        set("gender", "男性");
        set("age", 50);
        set("shen_type",1);
        set("attitude", "peaceful");
 	set("icon",old_man2);

        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);

        set("hp", 3000);
        set("max_hp", 1000);
        set("mp", 1500);
        set("max_mp", 1500);
        set("mp_factor", 50);

        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 170);
        set_skill("unarmed", 100);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("hand",170);
        set_skill("staff", 170);

        set_skill("hamagong", 200);
        set_skill("chanchu_bufa", 150);
        set_skill("shexing_diaoshou", 100);
        set_skill("lingshe_zhangfa", 150);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu_bufa");
        map_skill("unarmed", "shexing_diaoshou");
        map_skill("hand", "shexing_diaoshou");
        map_skill("parry", "lingshe_zhangfa");
        map_skill("staff", "lingshe_zhangfa");

        carry_object("gangzhang")->wield();
        add_money(2000);
};



NPC_END;
