// wanyankang.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_wanyankang);

virtual void create()
{
        set_name("阿康", "wanyan kang");
        set("gender", "男性");
        set("title", "大金国小王爷");
        set("age", 24);
        set("class", "fighter");
        set("long",
                "他本名阿康。随母包氏嫁完颜金狗后，成了小王子，\n"
		"贪图富贵，至死不改。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("per", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 26);
	set("icon", young_man1);

        set("chat_chance_combat", 60);

        set("hp", 500);
        set("max_hp", 500);
        set("jing", 400);
        set("max_jing", 400);
        set("mp", 1000);
        set("max_mp", 1000);
        set("mp_factor", 10);

        set("combat_exp", 160000);
        set("score", 100000);

        set_skill("force", 40);
        set_skill("xiantian_qigong", 40);    //先天气功
        set_skill("sword", 40);
        set_skill("quanzhen_jian",40);  //全真剑
        set_skill("dodge", 40);
        set_skill("jinyan_gong", 40);   //金雁功
        set_skill("parry", 40);
        set_skill("strike",40);
        set_skill("unarmed",40);
        set_skill("haotian_zhang", 40);    //昊天掌
        set_skill("claw",40);
        set_skill("jiuyin_baiguzhao", 40);    //昊天掌
        set_skill("literate",40);
        set_skill("taoism",40);

        map_skill("force", "xiantian_qigong");
        map_skill("sword", "quanzhen_jian");
        map_skill("dodge", "jinyan_gong");
        map_skill("parry", "quanzhen_jian");
        map_skill("strike", "haotian_zhang");
        map_skill("claw", "jiuyin_baiguzhao");
        prepare_skill("claw", "jiuyin_baiguzhao");

        create_family("全真教", 3, "弟子");
/*
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );
*/
        carry_object("changjian")->wield();
//	carry_object("male1-cloth")->wear();

}

virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(3))
	{
	case 0:
		perform_action("strike zhua", 1);
		break;
	case 1:
		perform_action("sword ding", 1);
		break;
	case 2:
		perform_action("force recover", 0);	//自动吸气
		break;
	}	
	return 0;
}

NPC_END;