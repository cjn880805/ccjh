// zhuoma.c

//code by sound
//date:2001-07-11

NPC_BEGIN(CNxuedao_zhuoma);

virtual void create()
{
        set_name("׿��", "zhuoma");
        set("long", "����һλ����Ůͬ����");
        set("gender", "Ů��");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "bonze");
		set("icon",young_woman9);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_hp", 300);
        set("hp", 300);
        set("mp", 300);
        set("max_mp", 300);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        setup();
}
/*
void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

        say ("׿���ʲΪ��˵��������٢��"+RANK_D->query_respect(ob) + "��ƶ�����������ˡ�\n");
        return;
}
*/
NPC_END;