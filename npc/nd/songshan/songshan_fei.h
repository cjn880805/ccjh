//songshan_fei.h 费彬
//by sound 2001-07-10

NPC_BEGIN(CNsongshan_fei);

virtual void create()
{
	
	set_name("费林", "fei bin");
	
	set("long","左冷禅的第四师弟费林、一套大嵩阳手武林中赫赫有名。");	

        set("nickname", "大嵩阳手");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",old_man1);

        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_factor", 30);
        set("hp",2000);
        set("max_hp",2000);
        set("combat_exp", 600000);
        set("shen_type", -1);

        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("songshan_sword", 100);
        set_skill("lingxu_bu", 100);

        map_skill("sword", "songshan_sword");
        map_skill("parry", "songshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("嵩山派", 13, "弟子");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;