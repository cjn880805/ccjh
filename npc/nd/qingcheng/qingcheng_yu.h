// yu.c ���˺�
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_yu);

virtual void create()
{
	set("icon",young_man5);
	set_name("���˺�", "yu renhao");
	set("gender", "����");
	set("age", 25);
	set("long", "�����ǡ�Ӣ�ۺ��ܣ�������㡹֮һ���书ҲԶ��ͬ�š�");

	set("combat_exp", 80000);
	set("shen_type", -1);

	set_skill("sword", 80);
	set_skill("pixie_sword", 80);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	map_skill("parry", "pixie_sword");
	map_skill("sword", "pixie_sword");
	create_family("�����", 6, "����");

	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
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
        say ("���˺���һ�������Ӿ������˺���\n");
        return;
}
*/
NPC_END;