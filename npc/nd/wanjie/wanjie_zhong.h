// zhong.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_zhong);

virtual void create()
{
        set_name("中千恨", "zhong wanchou");
        set("gender", "男性" );
        set("age", 52);
        set("str", 13);
        set("con", 13);
        set("dex", 13);
        set("per", 13);
        set("int", 13);
        set("icon",old_man1);
        set("long",
		"中千恨张着好长的一张马脸，眼睛生的甚高，\n"
		"一个圆圆的大鼻子却和嘴巴挤在一块，以致眼\n"
		"睛与鼻子之间，留下了一大块一无所有的空白\n"
		"地，丑陋异常。\n");

        set("attitude", "friendly");

        set("max_mp", 500);
        set("mp", 500);
        set("mp_factor", 20);
        set("combat_exp", 35000);

        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 90);
        set_skill("sword", 100);
        set_skill("force", 90);

        carry_object("cloth")->wear();
//	carry_object("bu-shoes")->wear();
}
/*
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("钟万仇对$N说道：想要救木婉清？你去死吧！\n",ob);
                kill_ob(ob);
        }
}
*/
NPC_END;