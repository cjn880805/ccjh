//bagua.h
//code by zwb
//1-15

NPC_BEGIN(CNwudang_bagua);

virtual void create()
{
		set_name("���Ե���", "bagua dizi");
        set("age", 23);
        set("gender", "����");
        set("long","���佣����Է�λ���ӡ�");
        set("attitude", "peaceful");
	set("icon",taoist);	
	set("foolid",135);
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 80000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("sword", 80);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 80);

        set("chat_chance", 5);

        create_family("�䵱��", 3, "����");

        carry_object("changjian");
        carry_object("baguafu")->wear();
}

virtual char * chat_msg()
{
	return "���Ե�������ߺ�ȣ����佣�����µ�һ��";
}

NPC_END;