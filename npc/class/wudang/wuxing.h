//wuxing.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNwudang_wuxing);

virtual void create()
{
		set_name("���е���","wuxing dizi");
        set("age", 23);
        set("gender", "����");
        set("long","���佣������з�λ���ӡ�");
	set("foolid",128);        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);
	set("icon",taoist_with_sword);	

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 30);
        set("chat_chance",2);

        create_family("�䵱��", 3, "����");
        carry_object("changjian");
        carry_object("wuxingfu")->wear();
}

virtual char * char_msg()
{
	return "���е�������ߺ�ȣ����佣�����µ�һ��";
}
NPC_END;