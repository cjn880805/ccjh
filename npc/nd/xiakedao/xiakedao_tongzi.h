// tongzi.c ͯ��

//code by sound
//2001-07-12

NPC_BEGIN(CNxiakedao_tongzi);

virtual void create()
{
        set_name("ͯ��", "tong zi");
	set("icon", boy1);
        set("long", "����һ��ʮ����������꣬ü��Ŀ�㣬������������õ���ϲ����");
        set("gender", "����");
        set("age", 15);
        set("shen_type",100);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("max_mp", 200);
        set("max_hp", 200);
        set("hp", 200);
        set("mp", 200);
        set("max_mp", 200);
        set("mp_factor", 10);

        set("combat_exp", 3000);
        set("score", 10);
        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("hand", 40);
        set_skill("staff", 40);

        create_family("���͵�", 3, "����");
}

NPC_END;