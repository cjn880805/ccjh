// zhong.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_zhong);

virtual void create()
{
        set_name("��ǧ��", "zhong wanchou");
        set("gender", "����" );
        set("age", 52);
        set("str", 13);
        set("con", 13);
        set("dex", 13);
        set("per", 13);
        set("int", 13);
        set("icon",old_man1);
        set("long",
		"��ǧ�����źó���һ���������۾��������ߣ�\n"
		"һ��ԲԲ�Ĵ����ȴ����ͼ���һ�飬������\n"
		"�������֮�䣬������һ���һ�����еĿհ�\n"
		"�أ���ª�쳣��\n");

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
        message_vision("������$N˵������Ҫ��ľ���壿��ȥ���ɣ�\n",ob);
                kill_ob(ob);
        }
}
*/
NPC_END;